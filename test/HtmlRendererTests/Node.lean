/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

import HtmlRendererTests.Elems
meta import HtmlRendererTests.Elems

namespace HtmlRendererTests

open Html

-- **Demonstration of `render_wellFormed`:** a tree built without `unsafeRaw` contains no
-- verbatim markup, which `decide` confirms for a concrete tree.
example : WellFormedHtml .html5 (Node.render (div [Node.text "hi", p []])) :=
  Node.render_wellFormed _ (by decide +kernel)

/-- The same theorem at `.xhtml`, where `WellFormedHtml` additionally rules out
an unclosed void tag and a bare attribute: rendering a tree built without
`unsafeRaw` in that dialect yields well-formed XML, void children and boolean
attributes included. -/
example : WellFormedHtml .xhtml (Node.render (div [Node.text "hi", input [.flag "disabled"]]) .xhtml) :=
  Node.render_wellFormed _ (by decide +kernel) .xhtml

-- A tree containing `unsafeRaw` is exactly what the hypothesis rules out.
example : (div [Node.unsafeRaw "<b>"]).hasVerbatim = true := by decide +kernel

/-- **Paired renderer-side invariant for `text`:** a text node renders to exactly
its escaped content, with nothing else spliced in. Combined with `escape_safe`,
a text node can never inject a raw `<`/`>` into its surrounding markup. -/
theorem render_text_safe (s : String) (dialect : Dialect) :
    Node.render (Node.text s) dialect = escape s ∧
      ∀ c ∈ (escape s).toList, c ≠ '<' ∧ c ≠ '>' ∧ c ≠ '"' :=
  ⟨Node.render_text s dialect, escape_safe s⟩

#guard Node.render (div []) = "<div></div>"
#guard Node.render (div [p []]) = "<div><p></p></div>"
#guard Node.render (br) = "<br>"
#guard Node.render (ul [li [], li []]) = "<ul><li></li><li></li></ul>"
#guard Node.render ((span [] : Node .phrasing) : Node .flow) = "<span></span>"

-- Text is escaped when it is rendered, not when it is built.
#guard Node.render (p [Node.text "a < b & c"]) = "<p>a &lt; b &amp; c</p>"
#guard Node.render (title "<script>") = "<title>&lt;script&gt;</title>"

-- `.xhtml` closes void tags and gives every boolean attribute a value, and
-- leaves everything else (including non-void elements) untouched.
#guard Node.render br (dialect := .xhtml) = "<br />"
#guard Node.render (div [hr]) (dialect := .xhtml) = "<div><hr /></div>"
#guard Node.renderPretty br (dialect := .xhtml) = "<br />"
#guard Node.render (input [.value "type" "text", .flag "disabled"])
  = "<input type=\"text\" disabled>"
#guard Node.render (input [.value "type" "text", .flag "disabled"]) (dialect := .xhtml)
  = "<input type=\"text\" disabled=\"disabled\" />"

-- An `iframe` has no children, but isn't a void element, so it still closes.
#guard Node.render (iframe [.value "src" "/x"]) = "<iframe src=\"/x\"></iframe>"

-- Pretty-printing: empty and void elements stay one line.
#guard Node.renderPretty (div []) = "<div></div>"
#guard Node.renderPretty br = "<br>"

-- A lone leaf child (text or `unsafeRaw`) isn't worth exploding onto its
-- own line, whether the element's declared content category is flow or
-- phrasing.
#guard Node.renderPretty (li [Node.text "one"]) = "<li>one</li>"
#guard Node.renderPretty (div [Node.unsafeRaw "<b>x</b>"]) = "<div><b>x</b></div>"

-- A lone *structured* (non-leaf) child, or a void child, does get its own
-- indented line
#guard Node.renderPretty (div [p []]) = "<div>\n  <p></p>\n</div>"
#guard Node.renderPretty (div [hr]) = "<div>\n  <hr>\n</div>"

-- Multiple flow children: one per line, indented one level deeper than the
-- parent, closing tag back at the parent's own indentation.
#guard Node.renderPretty (div [p [], p []]) = "<div>\n  <p></p>\n  <p></p>\n</div>"

-- Nesting increases indentation by one `unit` per level.
#guard Node.renderPretty (div [div [p [], p []]])
  = "<div>\n  <div>\n    <p></p>\n    <p></p>\n  </div>\n</div>"

-- Phrasing children are laid out inline, exactly like compact rendering,
-- regardless of how many there are or how deep the surrounding tree is;
-- whitespace between text/inline runs is visible in rendered output, so
-- the pretty-printer must never inject any.
#guard Node.renderPretty (p [Node.text "Hello, ", strong [Node.text "world"]])
  = "<p>Hello, <strong>world</strong></p>"
#guard Node.renderPretty (div [p [Node.text "Hello, ", strong [Node.text "world"]]])
  = "<div>\n  <p>Hello, <strong>world</strong></p>\n</div>"

-- Adjacent phrasing children among block content share a line.
#guard Node.renderPretty (div [p [], Node.text "a", span [Node.text "b"], p []])
  = "<div>\n  <p></p>\n  a<span>b</span>\n  <p></p>\n</div>"

-- `unit` is configurable (default two spaces).
#guard Node.renderPretty (div [p []]) "    " = "<div>\n    <p></p>\n</div>"

end HtmlRendererTests
