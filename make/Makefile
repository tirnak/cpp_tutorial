yes:
	yes it runs

echo_compiler:
	echo $(CXX)
	echo $(LD)

cat.o: cat.cpp
	$(CXX) cat.cpp -o cat.o

preprocess: cat.cpp
	$(CXX) -E cat.cpp|less

to_asm: cat.cpp
	$(CXX) -S cat.cpp
	less cat.s
	rm cat.s

ls.o: ls.cpp
	$(CXX) -std=c++11 ls.cpp -o ls.o -lboost_system -lboost_filesystem

ls-static.o: ls.cpp
	$(CXX) -std=c++11 ls.cpp -o ls-static.o -lboost_system -lboost_filesystem -static

run_ls_wd: ls_wd.o
	LD_LIBRARY_PATH=. ./ls_wd.o

ls_wd.o: ls_frontend.o libls.so
	$(LD) --sysroot=/ --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -\
dynamic-linker /lib64/ld-linux-x86-64.so.2 -z relro \
-o ls_wd.o \
/usr/lib/gcc/x86_64-linux-gnu/4.8/../../../x86_64-linux-gnu/crt1.o /usr/lib/gcc/x86_64-linux-gnu/4.8/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/4.8/crtbegin.o \
-L. -L/usr/lib/gcc/x86_64-linux-gnu/4.8 -L/usr/lib/gcc/x86_64-linux-gnu/4.8/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/4.8/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/4.8/../../.. \
ls_frontend.o \
-lls -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-linux-gnu/4.8/crtend.o /usr/lib/gcc/x86_64-linux-gnu/4.8/../../../x86_64-linux-gnu/crtn.o

ls_frontend.o: ls_frontend.cpp 
	$(CXX) -std=c++11 -c ls_frontend.cpp -o ls_frontend.o

libls.so: libls.cpp libls.hpp
	$(CXX) -std=c++11 -shared -fPIC -o libls.so libls.cpp -lboost_system -lboost_filesystem

clean:
	rm *.o *.so
