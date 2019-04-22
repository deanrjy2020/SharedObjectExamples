# dyn loading, 

##因为在test2.c里面没有直接calllibmax.so里面的函数, 所以直接编译下面也是会通过的(当然运行会出问题)
#下面只要libdl.so这个库就可以(dlopen等函数用到) 
program: libmax
	gcc test2.cpp -ldl -o program

#"-o libmax.so.0.1" file generated name, suppose the ".0.1" is the version.
libmax: max.cpp
	gcc -fPIC -shared -o libmax.so.0.1 max.cpp
	#ln -sf libmax.so.0.1 libmax.so #for compiling, don't need this as it is dyn loading.
	ln -sf libmax.so.0.1 libmax.so #for running, as the code use dlopen("libmax.so",..)
    
clean : 
	rm program libmax.so libmax.so.0.1

#will look for the libmax.so.1 when running.
#run the program
#LD_LIBRARY_PATH=. ./program
#or just "./program"