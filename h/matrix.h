#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

typedef struct vec3 vec3;

typedef struct mat4
{
    float m[16];
} mat4;

mat4 mat4_identity();
//vec4 mat4_mul_vec4(mat4 m, vec4 v);
vec3 mat4_mul_vec3(mat4 m, vec3 v);
float get_fovy(float fov_x, float aspect);
mat4 rotation_matrix(vec3 axis, double angle);
mat4 projection_matrix(float fovy_degrees, float aspect, float z_near, float z_far, bool flip_fov);

#endif
