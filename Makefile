SOURCES = $(shell find * -name '*.c')

gen: $(SOURCES)
	gcc $(SOURCES) -o 'build/mesh.exe'
	cd build
	build/mesh.exe

about:
	echo "MESH - Modern Exquisite SHell"