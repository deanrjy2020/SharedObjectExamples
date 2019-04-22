// the function/struct cannot be static 
// C++编译后得到的"nm libmax.so" 是 iiimaxiii, 要用C的编译方式.
extern "C" int max(int n1, int n2, int n3)
{
    int max_num = n1;
    max_num = max_num < n2? n2: max_num;
    max_num = max_num < n3? n3: max_num;
    return max_num;
}

typedef struct {
 const char *module;
 int  (*max)(int n1, int n2, int n3);
 // can be many functions
} SHARED_STRUCT;

extern "C" const SHARED_STRUCT shared_struct = {
    .module = "hello", //no use
    max,
};