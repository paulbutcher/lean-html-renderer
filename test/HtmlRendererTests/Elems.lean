/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

public import HtmlRenderer

/-! Just enough elements to test rendering, built directly with `Web.elem`. -/

@[expose] public section

namespace HtmlRendererTests

open Html HtmlModel

def div (children : List (Node .flow)) (attrs : Attrs := []) : Node .flow :=
  Web.elem (.html .div) (.html .flow) attrs segs![.many (Nodes.ofList children)]

def p (children : List (Node .phrasing)) (attrs : Attrs := []) : Node .paragraph :=
  Web.elem (.html .p) (.html .paragraph) attrs segs![.many (Nodes.ofList children)]

def span (children : List (Node .phrasing)) (attrs : Attrs := []) : Node .phrasing :=
  Web.elem (.html .span) (.html .phrasing) attrs segs![.many (Nodes.ofList children)]

def strong (children : List (Node .phrasing)) (attrs : Attrs := []) : Node .phrasing :=
  Web.elem (.html .strong) (.html .phrasing) attrs segs![.many (Nodes.ofList children)]

def ul (children : List (Node .listItemOrScript)) (attrs : Attrs := []) : Node .flow :=
  Web.elem (.html .ul) (.html .flow) attrs segs![.many (Nodes.ofList children)]

def li (children : List (Node .flow)) (attrs : Attrs := []) : Node .listItem :=
  Web.elem (.html .li) (.html .listItem) attrs segs![.many (Nodes.ofList children)]

def br (attrs : Attrs := []) : Node .phrasing :=
  Web.elem (.html .br) (.html .phrasing) attrs segs![]

def hr (attrs : Attrs := []) : Node .flow :=
  Web.elem (.html .hr) (.html .flow) attrs segs![]

def input (attrs : Attrs := []) : Node .phrasing :=
  Web.elem (.html .input) (.html .phrasing) attrs segs![]

def iframe (attrs : Attrs := []) : Node .phrasing :=
  Web.elem (.html .iframe) (.html .phrasing) attrs segs![]

def meta_ (attrs : Attrs := []) : Node .phrasingMetadata :=
  Web.elem (.html .meta) (.html .phrasingMetadata) attrs segs![]

def title (content : String) (attrs : Attrs := []) : Node .title :=
  Web.elem (.html .title) (.html .title) attrs segs![.one (.text content)]

def head (title : Node .title) (children : List (Node .metadata) := []) (attrs : Attrs := []) :
    Node .head :=
  Web.elem (.html .head) (.html .head) attrs segs![.many (Nodes.ofList children), .one title]

def body (children : List (Node .flow)) (attrs : Attrs := []) : Node .body :=
  Web.elem (.html .body) (.html .body) attrs segs![.many (Nodes.ofList children)]

end HtmlRendererTests
