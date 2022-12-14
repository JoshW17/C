#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *secret_word = "     ";
char guess_array[10][6];
int num_lines = 0;
char line[16];
FILE *fp;

void banner(){
  printf("\033[32m ********** **     ** *******   *******   ******** **                       _,.---.---.---.--.._  \033[0m\n");
  printf("\033[32m/////**/// /**    /**/**////** /**////** /**///// /**                   _.-' `--.`---.`---'-. _,`--.._ \033[0m\n");
  printf("\033[32m    /**    /**    /**/**   /** /**    /**/**      /**                  /`--._ .'.     `.     `,`-.`-._\\ \033[0m\n");
  printf("\033[32m    /**    /**    /**/*******  /**    /**/******* /**                 ||   \\  `.`---.__`__..-`. ,'`-._/ \033[0m\n");
  printf("\033[32m    /**    /**    /**/**///**  /**    /**/**////  /**            _  ,`\\ `-._\\   \\    `.    `_.-`-._,``-. \033[0m\n");
  printf("\033[32m    /**    /**    /**/**  //** /**    ** /**      /**         ,`   `-_ \\/ `-.`--.\\    _\\_.-'\\__.-`-.`-._`. \033[0m\n");
  printf("\033[32m    /**    //******* /**   //**/*******  /********/********  (_.o> ,--. `._/'--.-`,--`  \\_.-'       \\`-._ \\ \033[0m\n");
  printf("\033[32m    //      ///////  //     // ///////   //////// ////////    `---'    `._ `---._/__,----`           `-. `-\\ \033[0m\n");
  printf("\033[32m                                                                        /_, ,  _..-'                    `-._\\ \033[0m\n");
  printf("\033[32m                                                                        \\_, \\/ ._( \033[0m\n");
  printf("\033[32m                                                                         \\_, \\/ ._\\ \033[0m\n");
  printf("\033[32m                                                                          `._,\\/ ._\\ \033[0m\n");
  printf("\033[32m                                                                            `._// ./`-._ \033[0m\n");
  printf("\033[32m                                                                              `-._-_-_.-' \033[0m\n");
}

char *get_input(){
  static char guess[100];
  printf("\nEnter a guess: ");
  gets(guess);
  return guess;
}

void board_logic(char* guess, int num_guess, int executed){
  strcpy(guess_array[num_guess], guess);
  for(int i = 0; i < 5; i++){
    int found = 0;
    printf("|    ");
    if(secret_word[i] == guess_array[executed][i]){
      printf("\033[32m%c\033[0m", guess_array[executed][i]);
    } else {
      for(int b = 0; b < 5; b++){
        if(secret_word[b] == guess_array[executed][i]){
          printf("\033[33m%c\033[0m", guess_array[executed][i]);
          found = 1;
          break;
        } else if(found != 1 && b == 4){
          if(guess_array[executed][i] == '\0'){
            printf(" ");
          } else{
              printf("\033[31m%c\033[0m", guess_array[executed][i]);
          }
        }
      }
    }
    printf("   |");
  }
}

void update_board(char* guess, int num_guess){
  int executed = 0;
  for(int i = 0; i < 5; i++){
    printf("\n");
    for(int i = 0; i < 5; i++){
      printf(" ________ ");
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
      printf("|        |");
    }
    printf("\n");
    if(executed < num_guess + 1){
      board_logic(guess, num_guess, executed);
      executed++;
    } else{
      for(int i = 0; i < 5; i++){
        printf("|        |");
      }
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
      printf("|        |");
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
      printf("|________|");
    }
  }
}

int main(){

  fp = fopen("words.txt", "r");
  if(!fp){
    printf("\33[31mERROR: no words.txt file detected\033[0m\n");
    return 1;
  }
  srand(time(0));
  int random = rand() % 2315;
  while(fgets(line, 16, fp) != NULL && num_lines != random){
    num_lines++;
    secret_word = line;
  }
  fclose(fp);
  int num_guess = 0;
  int gameover = 0;
  banner();
  while(gameover != 1){
    char *user_guess = get_input();
    while(strlen(user_guess) != strlen(secret_word) - 1){
      printf("Your input should be five characters long");
      char *user_guess = get_input();
    }
    update_board(user_guess, num_guess);
    num_guess++;
    if(num_guess == 5 || strncmp(user_guess, secret_word, 5) == 0){
      gameover = 1;
      if(num_guess == 5 && strncmp(user_guess, secret_word, 5) != 0){
        printf("\n< GAME OVER >");
        printf("\nThe secret word was: %s", secret_word);
      } else{
        printf("\n< YOU WON! >");
      }
    } else{
      printf("\nYou have %d guesses left\n", 5 - num_guess);
    }
  }
}
