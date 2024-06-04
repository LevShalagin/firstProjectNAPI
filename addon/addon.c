#include <assert.h>
#include <node_api.h>
#include <stdio.h>
#include <string.h>

static napi_value getDate(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 2;
  napi_value args[2];
  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  assert(status == napi_ok);

  if (argc < 2) {
    napi_throw_type_error(env, NULL, "Wrong number of arguments");
    return NULL;
  }

  napi_valuetype valuetype0;
  status = napi_typeof(env, args[0], &valuetype0);
  assert(status == napi_ok);

  napi_valuetype valuetype1;
  status = napi_typeof(env, args[1], &valuetype1);
  assert(status == napi_ok);

  if (valuetype0 != napi_string || valuetype1 != napi_string) {
    napi_throw_type_error(env, NULL, "Wrong arguments");
    return NULL;
  }

  char16_t buffer;

  char *value0;
  status = napi_get_value_string_utf16(env, args[0], buffer, 1000, &value0);
  assert(status == napi_ok);

  char *value1;
  status = napi_get_value_string_utf16(env, args[1], buffer, 1000, &value1);
  assert(status == napi_ok);

  char *resultC;

  sprintf(resultC, "<tr><td id=\"data\">%s</td><td id=\"event\">%s</td></tr>", value0, value1);

  napi_value result;
  status = napi_create_string_utf16(env, resultC, strlen(resultC), &result);
  assert(status == napi_ok);

  return result;
}

#define DECLARE_NAPI_METHOD(name, func) \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

static napi_value Init(napi_env env, napi_value exports) {
  napi_status status;

  napi_property_descriptor desc = DECLARE_NAPI_METHOD("get_date", getDate);
  
  status = napi_define_properties(env, exports, 1, &desc);
  assert(status == napi_ok);
  
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
