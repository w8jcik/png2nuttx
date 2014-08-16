png2nuttx
---------

Utility extracts pixels from *.png* images, allowing to use them
in NuttX OS.

Usage example
-------------

    $ ./png2nuttx image.png
    $ ls
    image.png image.png.bin ...

Dependencies
------------

Utility makes use of LodePNG library from http://lodev.org/lodepng.
Sources are included in the */lib* folder. Don't need to do anything
about that.

Details
-------

Pixels are being extracted from *.png* and saved into the file with
the same name but with .bin added at the end. Format is absolutely raw,
every 16 bits describes color of one pixel. No metadata at all.

Formats that can be exported using GIMP are all too complicated
and BMP is a total mess. PNG is nice but the only interesting library
I have found, called LodePNG, works with NuttX but doesn't support
reading row by row. Without it, the limited amount of memory in
microcontroller doesn't allow to process images larger than just
a few rows.

If we have to convert from civilized format raw data is perfect.
