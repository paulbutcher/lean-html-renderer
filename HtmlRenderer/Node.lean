/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

public import HtmlModel
public import HtmlRenderer.Escape

@[expose] public section

namespace Html

open HtmlModel

/-- An HTML content-model category, as lean-html-model defines them. -/
abbrev Category := HtmlModel.Html.Cat

/-- A node valid wherever category `cat` is, carrying its attributes as each element's payload.
Its content model was checked by lean-html-model when it was built. -/
abbrev Node (cat : Category) := Web.Node Attrs (.html cat)

/-- A node with its typing erased, as rendering consumes it. -/
abbrev Tree := Web.Tree Attrs

namespace Node

/-- A text node. Text is phrasing content, and reaches flow content by widening. -/
def text (s : String) : Node .phrasing := Web.widen (.text s)

/-- Verbatim, unescaped markup, trusted as-is, usable as content of any category.
Misuse can lead to XSS issues. -/
def unsafeRaw {cat : Category} (s : String) : Node cat := .verbatim s

end Node

end Html
