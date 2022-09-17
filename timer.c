#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int s = 0;
int m = 0;
int h = 0;
int stop = 0;

void main(){
  while(stop != 1){
    printf("Press s to stop the timer\n");
    printf("%.2i:%.2i:%.2i", h, m, s);
    s++;
    if(s == 60){
      s = 0;
      m++;
    }
    if(m == 60){
      m = 0;
      h++;
    }
    if(h == 24){
      stop = 1;
    }
    if(_kbhit()){
      char key = _getch();
      if(key == 's'){
        break;
      }
    }
    Sleep(1000);
    system("cls");
  }
}
