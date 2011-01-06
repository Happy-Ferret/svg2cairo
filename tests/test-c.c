/*
Copyright (c) 2010 Andreas Krinke

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*
This file shows how to use C source code generated by cairoxml2cairo.lua
with C.
*/

#include <stdlib.h>
#include <cairo.h>

#include "path to C source file"

int main(int argc, char *argv[]) {
	cairo_surface_t *surface = NULL;
	cairo_t *cr = NULL;
	
	int width =  cairo_code_<name of the file>_get_width();
	int height = cairo_code_<name of the file>_get_height();
	
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);
	
	cairo_code_<name of the file>_render(cr);
	
	cairo_surface_write_to_png(surface, "test-c.png");
	
	return 0;
}