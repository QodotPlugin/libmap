#ifndef GODOT_UTIL_H
#define GODOT_UTIL_H

#define GD_REGISTER_METHOD(name, function_name, function)                                \
    godot_instance_method function_name = {NULL, NULL, NULL};                            \
    function_name##.method = &function;                                                  \
                                                                                         \
    nativescript_api->godot_nativescript_register_method(p_handle, name, #function_name, \
                                                         attributes, function_name);

#define GD_USER_DATA() \
    user_data_struct *user_data = (user_data_struct *)p_user_data

#define GD_NEW(type, name, ...) \
    godot_##type name;          \
    api->godot_##type##_new(&name, ##__VA_ARGS__)

#define GD_VARIANT_NEW(type, name, ...) \
    godot_variant name;                 \
    api->godot_variant_new_##type(&##name, ##__VA_ARGS__)

#define GD_CAST_VARIANT(type, variant) \
    api->godot_variant_as_##type##(variant)

#define GD_VARIANT_ARGV(type, name, idx) \
    godot_##type name = GD_CAST_VARIANT(type, p_args[##idx])

#define GD_ARRAY_GET(array, idx) \
    api->godot_array_get(array, idx)

#define GD_POOL_ARRAY_GET(type, array, idx) \
    api->godot_pool_##type##_array_get(array, idx)

#define GD_ARRAY_SIZE(array) \
    api->godot_array_size(array)

#define GD_POOL_ARRAY_SIZE(type, array) \
    api->godot_pool_##type##_array_size(array)

#define GD_STRING_TO_CHAR(dest, src)                                  \
    godot_char_string src##_chars = api->godot_string_utf8(&##src##); \
    dest = api->godot_char_string_get_data(&##src##_chars);

#define GD_VARIANT_STRING_TO_CHAR(dest, src)                       \
    godot_string g_##dest = api->godot_variant_as_string(&##src##); \
    GD_STRING_TO_CHAR(dest, g_##dest##);

#define GD_DESTROY(type, name) \
    api->godot_##type##_destroy(name)

#define GD_RETURN_NULL()           \
    GD_VARIANT_NEW(nil, null_ret); \
    return null_ret

#endif
