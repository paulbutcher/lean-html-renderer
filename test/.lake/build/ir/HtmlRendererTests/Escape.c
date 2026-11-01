// Lean compiler output
// Module: HtmlRendererTests.Escape
// Imports: public import Init public meta import Init import HtmlRenderer.Escape meta import HtmlRenderer.Escape
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lp_html_x2drenderer_Html_sanitizeAttrName(lean_object*);
lean_object* lp_html_x2drenderer_Html_attrNameKey(lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__HtmlRendererTests_attrKey(lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_Attrs_render_go_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_Attrs_render_go_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__3_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__3_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___redArg(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_optAttr_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_optAttr_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__HtmlRendererTests_attrKey(lean_object* v_f_1_){
_start:
{
lean_object* v___y_3_; lean_object* v_name_6_; 
v_name_6_ = lean_ctor_get(v_f_1_, 0);
lean_inc_ref(v_name_6_);
lean_dec_ref(v_f_1_);
v___y_3_ = v_name_6_;
goto v___jp_2_;
v___jp_2_:
{
lean_object* v___x_4_; lean_object* v___x_5_; 
v___x_4_ = lp_html_x2drenderer_Html_sanitizeAttrName(v___y_3_);
v___x_5_ = lp_html_x2drenderer_Html_attrNameKey(v___x_4_);
return v___x_5_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_Attrs_render_go_match__1_splitter___redArg(lean_object* v_x_7_, lean_object* v_h__1_8_, lean_object* v_h__2_9_){
_start:
{
if (lean_obj_tag(v_x_7_) == 0)
{
lean_object* v___x_10_; lean_object* v___x_11_; 
lean_dec(v_h__2_9_);
v___x_10_ = lean_box(0);
v___x_11_ = lean_apply_1(v_h__1_8_, v___x_10_);
return v___x_11_;
}
else
{
lean_object* v_head_12_; lean_object* v_tail_13_; lean_object* v___x_14_; 
lean_dec(v_h__1_8_);
v_head_12_ = lean_ctor_get(v_x_7_, 0);
lean_inc(v_head_12_);
v_tail_13_ = lean_ctor_get(v_x_7_, 1);
lean_inc(v_tail_13_);
lean_dec_ref_known(v_x_7_, 2);
v___x_14_ = lean_apply_2(v_h__2_9_, v_head_12_, v_tail_13_);
return v___x_14_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_Attrs_render_go_match__1_splitter(lean_object* v_motive_15_, lean_object* v_x_16_, lean_object* v_h__1_17_, lean_object* v_h__2_18_){
_start:
{
if (lean_obj_tag(v_x_16_) == 0)
{
lean_object* v___x_19_; lean_object* v___x_20_; 
lean_dec(v_h__2_18_);
v___x_19_ = lean_box(0);
v___x_20_ = lean_apply_1(v_h__1_17_, v___x_19_);
return v___x_20_;
}
else
{
lean_object* v_head_21_; lean_object* v_tail_22_; lean_object* v___x_23_; 
lean_dec(v_h__1_17_);
v_head_21_ = lean_ctor_get(v_x_16_, 0);
lean_inc(v_head_21_);
v_tail_22_ = lean_ctor_get(v_x_16_, 1);
lean_inc(v_tail_22_);
lean_dec_ref_known(v_x_16_, 2);
v___x_23_ = lean_apply_2(v_h__2_18_, v_head_21_, v_tail_22_);
return v___x_23_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__3_splitter___redArg(lean_object* v_x_24_, lean_object* v_h__1_25_, lean_object* v_h__2_26_){
_start:
{
if (lean_obj_tag(v_x_24_) == 0)
{
lean_object* v_name_27_; lean_object* v_val_28_; lean_object* v___x_29_; 
lean_dec(v_h__2_26_);
v_name_27_ = lean_ctor_get(v_x_24_, 0);
lean_inc_ref(v_name_27_);
v_val_28_ = lean_ctor_get(v_x_24_, 1);
lean_inc_ref(v_val_28_);
lean_dec_ref_known(v_x_24_, 2);
v___x_29_ = lean_apply_2(v_h__1_25_, v_name_27_, v_val_28_);
return v___x_29_;
}
else
{
lean_object* v_name_30_; lean_object* v___x_31_; 
lean_dec(v_h__1_25_);
v_name_30_ = lean_ctor_get(v_x_24_, 0);
lean_inc_ref(v_name_30_);
lean_dec_ref_known(v_x_24_, 1);
v___x_31_ = lean_apply_1(v_h__2_26_, v_name_30_);
return v___x_31_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__3_splitter(lean_object* v_motive_32_, lean_object* v_x_33_, lean_object* v_h__1_34_, lean_object* v_h__2_35_){
_start:
{
if (lean_obj_tag(v_x_33_) == 0)
{
lean_object* v_name_36_; lean_object* v_val_37_; lean_object* v___x_38_; 
lean_dec(v_h__2_35_);
v_name_36_ = lean_ctor_get(v_x_33_, 0);
lean_inc_ref(v_name_36_);
v_val_37_ = lean_ctor_get(v_x_33_, 1);
lean_inc_ref(v_val_37_);
lean_dec_ref_known(v_x_33_, 2);
v___x_38_ = lean_apply_2(v_h__1_34_, v_name_36_, v_val_37_);
return v___x_38_;
}
else
{
lean_object* v_name_39_; lean_object* v___x_40_; 
lean_dec(v_h__1_34_);
v_name_39_ = lean_ctor_get(v_x_33_, 0);
lean_inc_ref(v_name_39_);
lean_dec_ref_known(v_x_33_, 1);
v___x_40_ = lean_apply_1(v_h__2_35_, v_name_39_);
return v___x_40_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___redArg(uint8_t v_dialect_41_, lean_object* v_h__1_42_, lean_object* v_h__2_43_){
_start:
{
if (v_dialect_41_ == 0)
{
lean_object* v___x_44_; lean_object* v___x_45_; 
lean_dec(v_h__2_43_);
v___x_44_ = lean_box(0);
v___x_45_ = lean_apply_1(v_h__1_42_, v___x_44_);
return v___x_45_;
}
else
{
lean_object* v___x_46_; lean_object* v___x_47_; 
lean_dec(v_h__1_42_);
v___x_46_ = lean_box(0);
v___x_47_ = lean_apply_1(v_h__2_43_, v___x_46_);
return v___x_47_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___redArg___boxed(lean_object* v_dialect_48_, lean_object* v_h__1_49_, lean_object* v_h__2_50_){
_start:
{
uint8_t v_dialect_24__boxed_51_; lean_object* v_res_52_; 
v_dialect_24__boxed_51_ = lean_unbox(v_dialect_48_);
v_res_52_ = lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___redArg(v_dialect_24__boxed_51_, v_h__1_49_, v_h__2_50_);
return v_res_52_;
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter(lean_object* v_motive_53_, uint8_t v_dialect_54_, lean_object* v_h__1_55_, lean_object* v_h__2_56_){
_start:
{
if (v_dialect_54_ == 0)
{
lean_object* v___x_57_; lean_object* v___x_58_; 
lean_dec(v_h__2_56_);
v___x_57_ = lean_box(0);
v___x_58_ = lean_apply_1(v_h__1_55_, v___x_57_);
return v___x_58_;
}
else
{
lean_object* v___x_59_; lean_object* v___x_60_; 
lean_dec(v_h__1_55_);
v___x_59_ = lean_box(0);
v___x_60_ = lean_apply_1(v_h__2_56_, v___x_59_);
return v___x_60_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter___boxed(lean_object* v_motive_61_, lean_object* v_dialect_62_, lean_object* v_h__1_63_, lean_object* v_h__2_64_){
_start:
{
uint8_t v_dialect_35__boxed_65_; lean_object* v_res_66_; 
v_dialect_35__boxed_65_ = lean_unbox(v_dialect_62_);
v_res_66_ = lp_test___private_HtmlRendererTests_Escape_0__Html_AttrFragment_render_match__1_splitter(v_motive_61_, v_dialect_35__boxed_65_, v_h__1_63_, v_h__2_64_);
return v_res_66_;
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_optAttr_match__1_splitter___redArg(lean_object* v_x_67_, lean_object* v_h__1_68_, lean_object* v_h__2_69_){
_start:
{
if (lean_obj_tag(v_x_67_) == 0)
{
lean_object* v___x_70_; lean_object* v___x_71_; 
lean_dec(v_h__2_69_);
v___x_70_ = lean_box(0);
v___x_71_ = lean_apply_1(v_h__1_68_, v___x_70_);
return v___x_71_;
}
else
{
lean_object* v_val_72_; lean_object* v___x_73_; 
lean_dec(v_h__1_68_);
v_val_72_ = lean_ctor_get(v_x_67_, 0);
lean_inc(v_val_72_);
lean_dec_ref_known(v_x_67_, 1);
v___x_73_ = lean_apply_1(v_h__2_69_, v_val_72_);
return v___x_73_;
}
}
}
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Escape_0__Html_optAttr_match__1_splitter(lean_object* v_motive_74_, lean_object* v_x_75_, lean_object* v_h__1_76_, lean_object* v_h__2_77_){
_start:
{
if (lean_obj_tag(v_x_75_) == 0)
{
lean_object* v___x_78_; lean_object* v___x_79_; 
lean_dec(v_h__2_77_);
v___x_78_ = lean_box(0);
v___x_79_ = lean_apply_1(v_h__1_76_, v___x_78_);
return v___x_79_;
}
else
{
lean_object* v_val_80_; lean_object* v___x_81_; 
lean_dec(v_h__1_76_);
v_val_80_ = lean_ctor_get(v_x_75_, 0);
lean_inc(v_val_80_);
lean_dec_ref_known(v_x_75_, 1);
v___x_81_ = lean_apply_1(v_h__2_77_, v_val_80_);
return v___x_81_;
}
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_html_x2drenderer_HtmlRenderer_Escape(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_test_HtmlRendererTests_Escape(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
lean_initialize_runtime_module();
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_html_x2drenderer_HtmlRenderer_Escape(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_html_x2drenderer_HtmlRenderer_Escape(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_test_HtmlRendererTests_Escape(uint8_t builtin) {
lean_object * res;
if (_G_meta_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_meta_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_html_x2drenderer_HtmlRenderer_Escape(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_html_x2drenderer_HtmlRenderer_Escape(uint8_t builtin);
lean_object* initialize_html_x2drenderer_HtmlRenderer_Escape(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_test_HtmlRendererTests_Escape(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_html_x2drenderer_HtmlRenderer_Escape(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_html_x2drenderer_HtmlRenderer_Escape(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_test_HtmlRendererTests_Escape(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_test_HtmlRendererTests_Escape(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_test_HtmlRendererTests_Escape(builtin);
}
#ifdef __cplusplus
}
#endif
