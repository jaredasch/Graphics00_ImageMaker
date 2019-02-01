#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
  char header[20] = "P3 1000 1000 255 ";
  int pixel[3];
  char line[20];

  int fd = open("image.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  write(fd, header, strlen(header));
  for(int i = 0; i < 1000; i++){
    for(int j = 0; j < 1000; j++){
      pixel[0] = (j % (i + 1)) % 256;
      pixel[1] = (i % (j + 1)) % 256;
      pixel[2] = 256 / ((i+1) * (j+1));
      snprintf(line, 20, "%d %d %d ", pixel[0], pixel[1], pixel[2]);
      write(fd, line, strlen(line));
    }
  }
  close(fd);

  return 0;
}
