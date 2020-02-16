#ifndef MAP_DATA_H
#define MAP_DATA_H

#include "libmap.h"
#include "entity.h"
#include "entity_geometry.h"

typedef struct texture_data
{
    char *name;
    int width;
    int height;
} texture_data;

int entity_count;
entity *entities;
entity_geometry *entity_geo;

int texture_count;
texture_data *textures;

void map_data_reset();

int map_data_register_texture(const char *name);
extern LIBMAP_API void map_data_set_texture_size(const char *name, int width, int height);

extern LIBMAP_API int map_data_get_texture_count();
extern LIBMAP_API texture_data *map_data_get_textures();
int map_data_find_texture(const char *texture_name);
texture_data *map_data_get_texture(int texture_idx);

extern LIBMAP_API void map_data_set_spawn_type_by_classname(const char *key, int spawn_type);

extern LIBMAP_API void map_data_print_entities();
extern LIBMAP_API int map_data_get_entity_count();
extern LIBMAP_API const entity *map_data_get_entities();
const char *map_data_get_entity_property(int entity_idx, const char *key);

#endif
