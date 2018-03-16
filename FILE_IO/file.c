#include <stdio.h>

int main() {
  
  FILE* fd = fopen("filename", "w+");
  fprintf(fd, "random words..\n");
  fclose(fd);
  
  printf("successfully wrote to file.\n");
  fd = fopen("filename", "r");
  if (fd < 0){
      printf("Could not open file 'filename'\n");
  }
  char buffer[50];
  
  //while(fscanf(fd, "%s", buffer) != EOF){
  fgets(buffer, sizeof(buffer), fd);
  printf("%s\n", buffer);
  //}
  return 0;
}
