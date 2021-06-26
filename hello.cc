#include <node_api.h>
#include <cassert>
#include <thread>

namespace {
    napi_value hello(napi_env env, napi_callback_info info)
    {
    napi_status status;
    napi_value js_value;
    status = napi_create_string_utf8(env, "Hello, cmake-js!", NAPI_AUTO_LENGTH, &js_value);
    assert(status == napi_ok);
    return js_value;
    }

    void export_func(napi_env env, napi_value exports, const char *name, napi_callback f)
    {
    napi_status status;
    napi_value func;
    status = napi_create_function(env, name, NAPI_AUTO_LENGTH, f, nullptr, &func);
    assert(status == napi_ok);
    napi_set_named_property(env, exports, name, func);
    }

    napi_value Init(napi_env env, napi_value exports)
    {
    export_func(env, exports, "hello", hello);
    return exports;
    }

    NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
}
