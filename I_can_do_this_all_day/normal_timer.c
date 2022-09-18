#include <stdio.h>
#include <stdlib.h>
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

void main(){
  while(stop != 1){
    system("cls");
    if(kbhit()){
      key = getch();
      if(key == 'q'){
        printf("q: quit   p: pause   s: start\n");
        printf("QUIT AT   %.2i:%.2i:%.2i", h, m, s);
        break;
      } else if(key == 'p'){
        while(key != 's'){
          system("cls");
          printf("q: quit   p: pause   s: start\n");
          printf("PAUSED AT %.2i:%.2i:%.2i\n", h, m, s);
          Sleep(1000);
          if(kbhit()){
            key = getch();
          }
          if(key == 'q'){
            stop = 1;
            system("cls");
            break;
          }
          system("cls");
        }
      }
    }
    if(stop == 1){
      printf("q: quit   p: pause   s: start\n");
      printf("QUIT AT   %.2i:%.2i:%.2i", h, m, s);
    } else{
      printf("q: quit   p: pause   s: start\n");
      printf("          %.2i:%.2i:%.2i", h, m, s);

    }
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
