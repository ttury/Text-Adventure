 #include <stdio.h>
 #include "event.h"

void Battle_Zombie_First(FILE *characters, FILE *items) {
  int player_choice;
  printf("\nthere is a zombie!!\n");
  printf("and your choce?\n");
  printf("===================\n");
  printf("1. fight\n");
  printf("2. swearing\n");
  printf("====================\n");
  scanf("%d", &player_choice);
  
  switch(player_choice) {
    case 1:
      printf("you fought well, but zombie fought better\n");
      printf("you dead\n");
      return;
      break;
    case 2:
      printf("zombie is sad in her heart.\n");
      printf("you rubbish\n");
      printf("you win!\n\n");
      fprintf(characters, "zombie1 : sad");
      break;
  }
}