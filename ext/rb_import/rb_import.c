#include <ruby.h>

char *load_file_in_str(const char *in) {
  FILE *f = fopen(in, "r");

  if(!f) {
    return 0;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char * out = malloc(fsize + 1);
  int res = fread(out, fsize, 1, f);

  if(res <= 0) {
    return 0;
  }
  fclose(f);

  out[fsize] = 0;
  return out;
}

VALUE rb_import(VALUE self, VALUE file_name) {
  /* try finding the file the same way Ruby's `load`
   * or `require` would do */
  VALUE file_location = rb_find_file(file_name);

  if(RTEST(file_location)) {
    char *file_path     = RSTRING_PTR(file_location);
    char *file_content  = load_file_in_str(file_path);
    int result;

    VALUE obj = rb_eval_string_protect(file_content, &result);
    if (result) {
      rb_raise(rb_eLoadError, "can't eval imported file %s", RSTRING_PTR(file_location));
    } else {
      return obj;
    }
  } else {
    rb_raise(rb_eLoadError, "can't import file %s", RSTRING_PTR(file_name));
  }
}

void Init_rb_import() {
  /* make `import` available in the `Kernel` module */
  rb_define_method(rb_mKernel, "import", rb_import, 1);
}
