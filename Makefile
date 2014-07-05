binary:
	gcc -I lib -o png2nuttx png2nuttx.c lib/lodepng.c 

convert:
	./png2nuttx examples/suka.png

dump:
	hexdump examples/suka.png.bin

test:
	make clean
	make binary
	make convert
	make dump

clean:
	-rm examples/*.bin
	-rm png2nuttx
