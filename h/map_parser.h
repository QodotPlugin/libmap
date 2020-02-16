#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <stdbool.h>

#include "libmap.h"
#include "entity.h"
#include "brush.h"
#include "face.h"

LIBMAP_API bool map_parser_load(const char *map_file);

void token(const char *buf);
void newline();

void commit_face();
void commit_brush();
void commit_entity();

#endif
