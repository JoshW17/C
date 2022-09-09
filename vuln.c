#include <stdio.h>
int main(){
  char BUFFER[128];
  int BOOL = 0;
  char flag[32];
  FILE *fp;
  printf("Welcome to my super secure program!\nWhat's your name? ");
  gets(BUFFER);
  if(BOOL != 0){
    fp = fopen("flag.txt","r");
    if(!fp){
      return 1;
    }
    while(fgets(flag, 32, fp) != NULL){
      printf("%s\n", flag);
    }
    fclose(fp);
  }
  printf("Your name is %s", BUFFER);
  return 0;
}
