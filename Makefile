SOURCES = $(shell find * -name '*.c')

gen: $(SOURCES)
	gcc $(SOURCES) -o 'build/mesh.out'
	cd build
	build/mesh.out

pipe: $(SOURCES)
	gcc $(SOURCES) -o 'build/mesh.out'
	cd build
	echo "/bin/ls" | 'build/mesh.out'

about:
	echo "MESH - Modern Exquisite SHell"
