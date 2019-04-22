#below we will generat libmax.so and use that when running.

#compile the test.c:
program: libmax.so
	gcc test.c -L. -lmax -o program

#compile the max.c:
libmax.so: max.c    
	gcc -fPIC -shared -o libmax.so max.c

clean : 
	rm program libmax.so

#run the program
#LD_LIBRARY_PATH=. ./program
#or just "./program"