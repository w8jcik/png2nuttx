#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define RGB565(r, g, b) (unsigned short)((r << 11) + (g << 5) + b)
#include "lodepng.h"

int decodeOneStep(const char* filename)
{
  unsigned error;
  unsigned char* image;
  unsigned width, height;
  
  int16_t *pixels;
  char cut_filename[64];
  char derived_filename[64];

  int i;
  FILE *write_ptr;

  error = lodepng_decode24_file(&image, &width, &height, filename);
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

  error = lodepng_decode24_file(&image, &width, &height, filename);
  if(error) printf("decoder error %u: %s\n", error, lodepng_error_text(error));
        
  if (NULL == (pixels = malloc(width * height * sizeof(int)))) {
    printf("malloc failed\n");
    return(-1);
  }
  
  for (i = 0; i < width * height; i += 1) {
    pixels[i] = RGB565(image[i*3]/8, image[i*3+1]/4, image[i*3+2]/8);
  }
  
  strncpy(cut_filename, filename, strlen(filename)-4);
  
  // sometimes \0 is missing, contrary to the specification 
  
  cut_filename[strlen(filename)-4] = '\0';
  
  sprintf(derived_filename, "%s-%dx%d.rgb", cut_filename, width, height);
  
  printf("Saving as %s\n", derived_filename);
  
  write_ptr = fopen(derived_filename, "wb");

  fwrite(pixels, sizeof(pixels), (width * height)/2, write_ptr);

  free(pixels);

  free(image);
  
  return 0;
}

int main(int argc, char *argv[])
{
  const char* filename = argc > 1 ? argv[1] : "rainbow.png";

  decodeOneStep(filename);
  
  return 0;
}
