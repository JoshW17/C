#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int s = 0;
int m = 0;
int h = 0;
char key;
int stop = 0;
char flag[64];
FILE *fp;

void getflag(){
  fp = fopen("flag.txt", "r");
  while(fgets(flag, 64, fp) != NULL){
    printf("\n          %s", flag);
  }
  fclose(fp);
}

int main(){
  while(stop != 1){
    system("cls");
    char BUFFER[16] = "goofy";
    if(kbhit()){
      key = getch();
      if(key == 'q'){
        printf("QUIT AT   %.2i:%.2i:%.2i", h, m, s);
        break;
      } else if(key == 'p'){
        while(strcmp(BUFFER, "resume") != 0){
          system("cls");
          key = 'j';
          printf("PAUSED AT %.2i:%.2i:%.2i\n", h, m, s);
          printf("Enter resume or quit: ");
          gets(BUFFER);
          if(strcmp(BUFFER, "quit") == 0){
            stop = 1;
            system("cls");
            printf("QUIT AT   %.2i:%.2i:%.2i", h, m, s);
            return 0;
          }
          system("cls");
        }
      }
    }
      printf("Press q to quit or p to pause the timer\n");
      printf("          %.2i:%.2i:%.2i", h, m, s);
    if(h == 24){
      getflag();
      break;
    }
    s++;
    if(s == 60){
      s = 0;
      m++;
    }
    if(m == 60){
      m = 0;
      h++;
    }
    Sleep(1000);
  }
}
