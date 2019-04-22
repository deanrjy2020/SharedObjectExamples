#include <stdio.h>
#include <dlfcn.h>
#include "max.h"

// the same as the one in max.c
typedef struct {
 const char *module;
 int  (*max)(int n1, int n2, int n3);
 // can be many functions
} SHARED_STRUCT;

typedef int (*FN)(int n1, int n2, int n3); 

int main(int argc, char **argv) {
    void *lib_handle;
    FN fn = NULL;
    SHARED_STRUCT* st = NULL;
    char *error;

    // 加载动态库,如果加载失败返回NULL. 
    lib_handle = dlopen("libmax.so", RTLD_LAZY); //use the so if run this line
    if (!lib_handle) {
      fprintf(stderr, "%s\n", dlerror());
      return 1;
    }

    // 返回函数地址. 如果查找函数失败则返回NULL.
    fn = (FN) dlsym(lib_handle, "max");
    if ((error = dlerror()) != NULL) {
      fprintf(stderr, "%s\n", error);
      return 1;
    }

    st = (SHARED_STRUCT*) dlsym(lib_handle, "shared_struct");
    if ((error = dlerror()) != NULL) {
      fprintf(stderr, "SHARED_STRUCT dlsym error, %s\n", error);
      return 1;
    }

    int a = 10, b = -2, c = 100;
    printf("test2 max function: max among 10, -2 and 100 is %d.\n", fn(a, b, c));

    if (st && st->max) {
        printf("test2 st struct: max among 10, -2 and 100 is %d.\n", st->max(a, b, c));
    }
    /*
    和微软的动态加载dll技术对比如下:
    ::LoadLibrary() - dlopen()
    ::GetProcAddress() - dlsym()
    ::FreeLibrary() - dlclose()
    */
    dlclose(lib_handle);

    return 0;
}