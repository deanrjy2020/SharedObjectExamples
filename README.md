# SharedObjectExamples

https://www.cnblogs.com/jiqingwu/p/linux_dynamic_lib_create.html

test.c: Dynamic Linking. 编译的时候链接动态库, 在编译的时候必须提供so文件. loader可以在程序启动的时候，来map所有的动态链接映射到内存中


test2.c: Dynamic Loading. 运行的时候加载动态库, 通过dlopen和dlclose的方式加载动态链接库，动态将动态链接库加载到内存中。


总结:
如果test2.c里面直接call so里面的函数了, 那么compile的时候就要提供那个so文件, 要不然编译器不知道被call函数的意思/定义. 即动态链接.

如果.c里面是把so里面的函数通过string/name的形式映射成另外的函数, 那么compile时候不用提供so文件, 因为也没有call so里面的函数. 即动态加载.
// 返回函数地址. 如果查找函数失败则返回NULL.
   fn = dlsym(lib_handle, "max");
见egl_no_config_context_x11.


经验:
eglGetProcAddress和dlsym什么关系?
1, eglGetProcAddress也是一个函数, 也要通过dlsym得到的(一般都是第一个得到).
2, 相当于另外一层封装. 得到了后再通过eglGetProcAddress得到其他函数的addr,
3, eglGetProcAddress是要求EGL initialized, 才能工作, 即在EGL的环境下.