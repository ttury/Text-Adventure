#include <stdio.h>
#include <strings.h>
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
  if(Check_Save(history, "zombie was moved\n")) printf("ok\n");
  
  fclose(history);
  fclose(items);
  return 0;
}