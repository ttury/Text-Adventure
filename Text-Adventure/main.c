#include <stdio.h>
#include <string.h>
#include "event.h"

int main() {
  
  int player_choice;
  char savetemp[100];
  FILE *characters;
  FILE *items;
  characters = fopen("characters.txt", "r+");
  items = fopen("items.txt", "r+");
  
  Battle_Zombie_1(characters, items);
  
  printf("there is another zombie!!\n");
  printf("and your choce?\n");
  printf("===================\n");
  printf("1. saying love\n");
  printf("2. swearing\n");
  printf("====================\n");
  scanf("%d", &player_choice);
  
  switch(player_choice) {
    case 1:
      printf("He seems to be shy\n");
      printf("He disappeared somewhere..\n");
      printf("you win!!\n");
      printf("Umm? a sheet of paper is left where he left\n");
      printf("you get his number\n");
      fprintf(items, "zombie\'s number\n");
      break;
    case 2:
      fscanf(characters, "zombie1 : %s", savetemp);
      if(strcmp(savetemp, "sad")) {
        printf("He is a boyfriend of the zombie you hurt\n");
        printf("He picked you up and drive you into the ground\n");
        printf("Oh.. disgusting..\n");
        printf("You dead\n");
        return 1;
      }
      break;
  }
  
  fclose(characters);
  fclose(items);
  return 0;
}