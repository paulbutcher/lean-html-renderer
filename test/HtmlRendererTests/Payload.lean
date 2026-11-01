/-
Copyright (c) 2026 Paul Butcher. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
-/
module

import HtmlRenderer.Payload
meta import HtmlRenderer.Payload

namespace HtmlRendererTests

open Html HtmlModel

private def empty : Attrs := HtmlPayload.empty

-- The occurrence written last wins, in the position of the first; names compare ignoring ASCII
-- case.
#guard (HtmlPayload.attr "ID" "b" (HtmlPayload.attr "class" "c" (HtmlPayload.attr "id" "a" empty))).render
  = " ID=\"b\" class=\"c\""

#guard (HtmlPayload.flag "hidden" true empty).render = " hidden"
#guard (HtmlPayload.flag "Hidden" false (HtmlPayload.flag "hidden" true empty)).render = ""
#guard (HtmlPayload.key "k" (HtmlPayload.attr "id" "a" empty)).render = " id=\"a\""
#guard Attrs.render (HtmlPayload.append ([.value "id" "a", .value "class" "c"] : Attrs)
    [.value "ID" "b", .flag "hidden"])
  = " ID=\"b\" class=\"c\" hidden"

#guard (HtmlPayload.style "margin-left" "4px" (HtmlPayload.style "color" "red" empty)).render
  = " style=\"color:red;margin-left:4px\""
#guard (HtmlPayload.style "color" "red" (HtmlPayload.attr "style" "display:none" empty)).render
  = " style=\"display:none;color:red\""

theorem set_set (a : Html.Attrs) {f g : AttrFragment}
    (h : Html.Attrs.nameKey f.name = Html.Attrs.nameKey g.name) :
    Html.Attrs.set (Html.Attrs.set a f) g = Html.Attrs.set a g := by
  unfold Html.Attrs.set
  simp only [h]
  by_cases ha : a.any (Html.Attrs.nameKey ·.name == Html.Attrs.nameKey g.name)
  · obtain ⟨x, hx, hk⟩ := List.any_eq_true.mp ha
    have hany : (a.map fun y => if Html.Attrs.nameKey y.name == Html.Attrs.nameKey g.name then f
        else y).any (Html.Attrs.nameKey ·.name == Html.Attrs.nameKey g.name) := by
      refine List.any_eq_true.mpr ⟨f, List.mem_map.mpr ⟨x, hx, by simp [hk]⟩, by simp [h]⟩
    simp only [ha, ↓reduceIte]
    simp only [hany, ↓reduceIte, List.map_map]
    refine List.map_congr_left fun y _ => ?_
    by_cases hy : Html.Attrs.nameKey y.name = Html.Attrs.nameKey g.name <;> simp [hy, h]
  · have hany : (a ++ [f]).any (Html.Attrs.nameKey ·.name == Html.Attrs.nameKey g.name) := by
      simp [h]
    simp only [ha, Bool.false_eq_true, ↓reduceIte]
    simp only [hany, ↓reduceIte, List.map_append]
    simp only [List.any_eq_true, beq_iff_eq, not_exists, not_and] at ha
    simp only [List.map_cons, List.map_nil, h, beq_self_eq_true, ↓reduceIte]
    congr 1
    exact (List.map_congr_left fun y hy => by simp [ha y hy]).trans (List.map_id' a)

end HtmlRendererTests
