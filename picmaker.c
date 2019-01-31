#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
  char header[20] = "P3 500 500 255 ";
  int pixel[3];
  char line[20];
  
  int fd = open("image.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  write(fd, header, strlen(header));
  for(int i = 0; i < 500; i++){
    for(int j = 0; j < 500; j++){
      snprintf(line, 20, "%d %d %d ", i, j, 0);
      write(fd, line, strlen(line));
    }
  }

  return 0;
}
