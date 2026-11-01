/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

public import HtmlModel
public import HtmlRenderer.Escape

@[expose] public section

namespace Html

namespace Attrs

/-- What makes two names the same attribute, as `Attrs.render` compares them. -/
def nameKey (name : String) : String := attrNameKey (sanitizeAttrName name)

/-- `f` in place of the fragment of the same name, or after the others if there is none. -/
def set (attrs : Attrs) (f : AttrFragment) : Attrs :=
  let k := nameKey f.name
  if attrs.any (nameKey ·.name == k) then attrs.map fun g => if nameKey g.name == k then f else g
  else attrs ++ [f]

def remove (attrs : Attrs) (name : String) : Attrs :=
  attrs.filter (nameKey ·.name != nameKey name)

def addStyle (attrs : Attrs) (name value : String) : Attrs :=
  let decl := s!"{name}:{value}"
  match attrs.find? (nameKey ·.name == "style") with
  | some (.value _ s) => set attrs (.value "style" (if s.isEmpty then decl else s ++ ";" ++ decl))
  | _ => set attrs (.value "style" decl)

end Attrs

/-- `Attrs.render` keeps the first occurrence of a name, so each attribute replaces any earlier
one of the same name in place, making the occurrence written last win, as in JSX and the DOM. -/
instance : HtmlModel.HtmlPayload Attrs where
  empty := []
  attr n v a := Attrs.set a (.value n v)
  flag n b a := if b then Attrs.set a (.flag n) else Attrs.remove a n
  style n v a := Attrs.addStyle a n v
  key _ a := a
  append a b := b.foldl Attrs.set a

end Html
