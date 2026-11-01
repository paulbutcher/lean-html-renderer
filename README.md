# html-renderer

A Lean 4 library that renders [lean-html-model](https://github.com/paulbutcher/lean-html-model) trees, whose payload is an attribute list, to HTML or XHTML strings. Text is escaped and attribute names sanitized when the tree is rendered, and `Node.render_wellFormed` proves the output well-formed.

The code was moved out of [lean-html](https://github.com/paulbutcher/lean-html), so that a package building trees some other way, such as lean-html-syntax's `html!`, can render them without lean-html's tag functions. Declarations keep their names in namespace `Html`.

## Installation

Add it to your `lakefile.toml`:

```toml
[[require]]
name = "html-renderer"
git = "https://github.com/paulbutcher/lean-html-renderer"
rev = "v0.1.0"
```

## Usage

```lean
import HtmlRenderer

open Html HtmlModel

def greeting : Node .paragraph :=
  Web.elem (.html .p) (.html .paragraph) [.value "class" "hi"]
    segs![.many (Nodes.ofList [Html.Node.text "a < b"])]

#eval greeting.render   -- "<p class=\"hi\">a &lt; b</p>"
```

- `Node cat` is a lean-html-model node of HTML category `cat` carrying an `Attrs` payload, a list of `AttrFragment`s: `.value name value` or a bare `.flag name`. `Tree` is the same with its typing erased.
- `Node.render` renders compactly; `(lineBreaks := true)` puts each child that isn't phrasing content on a line of its own, as cmark does. `Node.renderPretty` indents, `unit` (two spaces by default) per level, breaking lines only beside children that aren't phrasing content.
- `Node.text` is a text node, escaped when rendered. Where an attribute name repeats, compared after sanitizing and ignoring ASCII case, `Attrs.render` keeps the first.
- `document head body` prepends `<!DOCTYPE html>` and wraps a `Node .head` and a `Node .body` in `<html>`, taking `lang`, `pretty`, `unit`, and `dialect`.

## Dialects

Pass `(dialect := .xhtml)` to `Node.render`, `Node.renderPretty`, or `document` for XML instead of HTML5, the default: every element closes or self-closes (`<br />`), every boolean attribute carries a value (`disabled="disabled"`), and `document` declares the XHTML namespace on `<html>`, with `lang` given as `xml:lang` too.

## Well-formedness

- `Node.render_wellFormed`: rendering produces balanced tags, no unescaped `<` or `>` outside a tag's own delimiters, and attribute runs with no name repeated, with or without `lineBreaks`. At `.xhtml` it says the output is well-formed XML.
- Its hypothesis is `n.hasVerbatim = false`: the node contains no `Node.unsafeRaw`. `decide +kernel` proves it for a concrete tree.
- It covers `Node.render`, not `Node.renderPretty`, whose indentation would need a side condition on `unit`.
- `escape_safe`, `sanitizeAttrName_safe`, `sanitizeAttrName_start`, `Attrs.render_safe`, and `Attrs.render_wellFormed` are the escaping and attribute facts it rests on.

## `unsafeRaw`

`Node.unsafeRaw : String → Node cat` inserts markup verbatim, unescaped, in any category. It is trusted as-is, so misuse can introduce XSS vulnerabilities, and it is exactly what `Node.render_wellFormed`'s hypothesis rules out.

## The payload instance

`HtmlModel.HtmlPayload Attrs` is what a markup macro such as lean-html-syntax's `html!` builds elements with:

- Where an attribute name repeats, the occurrence written last wins, as in JSX and the DOM, in the position of the first. Names compare as `Attrs.render` compares them, after sanitizing and ignoring ASCII case.
- A flag is a bare attribute when true and absent when false, removing any earlier occurrence.
- Styles join into one `style` attribute, `color:red;margin-left:4px`, after any style written as text.
- `key` is dropped, and spliced attributes override those before them.
- There is no `EventAttr` instance, so a markup macro reports that this payload has no event support.

## License

This library is released under the Apache 2.0 license. See the LICENSE file for the complete license text.
