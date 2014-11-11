#include "rb_import_utils.h"

long rb_import_get_file_size(FILE *f) {
  /* preserve the current position */
  long current_position = ftell(f);

  fseek(f, 0, SEEK_END);
  long file_size = ftell(f);

  /* restore the previous position */
  fseek(f, 0, current_position);

  return file_size;
}

char *rb_import_read_file(FILE *f) {
  long file_size      = rb_import_get_file_size(f);
  char * file_content = malloc(file_size + 1);
  int res             = fread(file_content, file_size, 1, f);

  fclose(f);
  file_content[file_size] = 0;

  if(res <= 0) {
    free(file_content);
    file_content = 0;
  }

  return file_content;
}

char *rb_import_load_file_in_str(const char *in) {
  FILE *f = fopen(in, "r");

  return f ? rb_import_read_file(f) : 0;
}
