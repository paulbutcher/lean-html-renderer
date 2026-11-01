/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

public import HtmlRenderer.Dialect
public import HtmlRenderer.Escape
public import HtmlRenderer.Node
public import HtmlRenderer.Render
public import HtmlRenderer.Document
public import HtmlRenderer.Payload

/-!
# `HtmlRenderer`: rendering lean-html-model trees

Renders a lean-html-model tree whose payload is an `Attrs` value
(`HtmlRenderer/Escape.lean`) to HTML or XHTML. `Attrs.render` is the single
place attribute names are sanitized and values escaped; the tree holds text
raw, and rendering (`HtmlRenderer/Render.lean`) escapes it and lays it out,
from the tree erased to `Tree`. The `HtmlPayload Attrs` instance
(`HtmlRenderer/Payload.lean`) is what a markup macro builds elements with.

## Dialects

`Dialect` chooses the serialization, and is an argument to `Node.render`,
`Node.renderPretty`, and `document`, so one tree can be emitted either way.
`.html5`, the default, is the usual HTML syntax. `.xhtml` is XML: every
element either closes or self-closes (`<br />`), every boolean attribute
carries a value (`disabled="disabled"`), and `document` declares the XHTML
namespace on `<html>`.

## Well-formedness

`Node.render_wellFormed` shows that, given no `unsafeRaw` use,
`Node.render` always produces, with or without `lineBreaks`, well-formed
markup: balanced tags, no unescaped `<`/`>` outside tag delimiters, and
every attribute run of the shape its dialect admits, with no name repeated
(`Attrs.render_wellFormed`).
`WellFormedHtml` is indexed by the dialect, and at `.xhtml` has neither an
unclosed void tag nor a bare attribute, so the theorem there says the output
is well-formed XML. Its hypothesis, that the node contains no verbatim markup,
is `Node.hasVerbatim`, which is decidable. `escape_safe`,
`sanitizeAttrName_safe`, and `Attrs.render_safe`, the escaping-safety facts
that proof rests on, are public too. The theorem covers `Node.render`; it
says nothing about `Node.renderPretty`, whose interposed indentation would
need a side-condition that `unit` contains no `<`/`>`.

## The escape hatch

`Node.unsafeRaw : String → Node cat` is verbatim, unescaped markup, trusted
as-is, valid in any category. Misuse can create XSS vulnerabilities, and
it's exactly what `Node.render_wellFormed`'s hypothesis rules out.
-/
