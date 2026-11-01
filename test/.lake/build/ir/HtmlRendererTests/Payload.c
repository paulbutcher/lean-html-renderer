// Lean compiler output
// Module: HtmlRendererTests.Payload
// Imports: public import Init public meta import Init import HtmlRenderer.Payload meta import HtmlRenderer.Payload
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
LEAN_EXPORT lean_object* lp_test___private_HtmlRendererTests_Payload_0__HtmlRendererTests_empty;
static lean_object* _init_lp_test___private_HtmlRendererTests_Payload_0__HtmlRendererTests_empty(void){
_start:
{
lean_object* v___x_1_; 
v___x_1_ = lean_box(0);
return v___x_1_;
}
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_html_x2drenderer_HtmlRenderer_Payload(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_runtime_initialized = false;
LEAN_EXPORT lean_object* runtime_initialize_test_HtmlRendererTests_Payload(uint8_t builtin) {
lean_object * res;
if (_G_runtime_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_runtime_initialized = true;
lean_initialize_runtime_module();
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_html_x2drenderer_HtmlRenderer_Payload(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_test___private_HtmlRendererTests_Payload_0__HtmlRendererTests_empty = _init_lp_test___private_HtmlRendererTests_Payload_0__HtmlRendererTests_empty();
lean_mark_persistent(lp_test___private_HtmlRendererTests_Payload_0__HtmlRendererTests_empty);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* runtime_initialize_Init(uint8_t builtin);
lean_object* runtime_initialize_html_x2drenderer_HtmlRenderer_Payload(uint8_t builtin);
static bool _G_meta_initialized = false;
LEAN_EXPORT lean_object* meta_initialize_test_HtmlRendererTests_Payload(uint8_t builtin) {
lean_object * res;
if (_G_meta_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_meta_initialized = true;
res = runtime_initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_html_x2drenderer_HtmlRenderer_Payload(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_html_x2drenderer_HtmlRenderer_Payload(uint8_t builtin);
lean_object* initialize_html_x2drenderer_HtmlRenderer_Payload(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_test_HtmlRendererTests_Payload(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_html_x2drenderer_HtmlRenderer_Payload(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_html_x2drenderer_HtmlRenderer_Payload(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = runtime_initialize_test_HtmlRendererTests_Payload(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = meta_initialize_test_HtmlRendererTests_Payload(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return initialize_test_HtmlRendererTests_Payload(builtin);
}
#ifdef __cplusplus
}
#endif
