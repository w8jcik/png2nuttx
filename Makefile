BINS := bin/png2nuttx

binary:
	gcc -I lib -o bin/png2nuttx png2nuttx.c lib/lodepng.c 

convert:
	bin/png2nuttx examples/suka.png

dump:
	hexdump examples/suka.rgb

test:
	make clean
	make binary
	make convert
	make dump

install:
	cp bin/png2nuttx /usr/local/bin/
	
uninstall:
	rm /usr/local/bin/png2nuttx -f

clean:
	-rm examples/*.rgb -f
	-rm bin/png2nuttx -f
