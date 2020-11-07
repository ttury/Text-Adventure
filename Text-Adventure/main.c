#include <stdio.h>
#include "event.h"

int count = 0;

int main() {
  FILE *history;
  FILE *items;
  char savetemp[MAX_LENGTH];

  history = fopen("history.txt", "r+");
  items = fopen("items.txt", "r+");
  
  Prologue();
  Show_Map();
  Player_Action(history, items);
  
  fclose(history);
  fclose(items);
  return 0;
}