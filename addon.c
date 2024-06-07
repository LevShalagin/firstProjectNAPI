#include <assert.h>
#include <node_api.h>
#include <stdio.h>
#include <string.h>

static napi_value getDate(napi_env env, napi_callback_info info) {
  
  size_t argc = 1;
  napi_value args[1];
  napi_get_cb_info(env, info, &argc, args, NULL, NULL);

  // Получаем строку из JavaScript
  size_t str_len;
  char* str = (char*) malloc((str_len + 1) * sizeof(char));
  napi_get_value_string_utf8(env, args[0], str, str_len + 1, &str_len);

  // Используем строку в C
  printf("Полученная строка: %s\n", str);

  napi_value *result;
  napi_create_string_utf8(env, str, NAPI_AUTO_LENGTH, &result);

  free(str);

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
