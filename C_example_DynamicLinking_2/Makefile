#formally, use the libxxs.so.1

#compile the test.c:
program: libmax.so
	gcc test.c -L. -lmax -o program

#"-Wl,-soname,libmax.so.1" tell the program to search libmax.so.1 when *RUNNING*.
#"-o libmax.so.0.1" file generated name, suppose the ".0.1" is the version.
libmax.so: max.c    
	gcc -fPIC -shared -Wl,-soname,libmax.so.1 -o libmax.so.0.1 max.c
	#no matter what the file generated name is, at the linking time, it is always looking for libmax.so as we are using "-lmax".
	ln -sf libmax.so.0.1 libmax.so #for compiling
	ln -sf libmax.so.0.1 libmax.so.1 #for running
    
clean : 
	rm program libmax.so libmax.so.1 libmax.so.0.1

#will look for the libmax.so.1 when running.
#run the program
#LD_LIBRARY_PATH=. ./program
#or just "./program"