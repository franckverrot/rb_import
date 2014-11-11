#ifndef RB_IMPORT_UTILS_H
#define RB_IMPORT_UTILS_H
#include <ruby.h>

long rb_import_get_file_size(FILE *);
char *rb_import_read_file(FILE *);
char *rb_import_load_file_in_str(const char *);

#endif
