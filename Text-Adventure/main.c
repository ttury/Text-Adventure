#include <stdio.h>
#include "event.h"

fpos_t move = 0;

int main() {
  FILE *history;
  FILE *items;
  char savetemp[MAX_LENGTH];


  int player_choice;

  printf("\n������ ����Ʈ���� ���Ƹ� C#�� Text Adventure ���ӿ� ���� ���� ȯ���մϴ�.\n\n");
  printf("=======================\n");
  printf("1. �̾��ϱ�\n");
  printf("2. ���� �����ϱ�\n");
  printf("=======================\n");
  scanf("%d", &player_choice);

  switch (player_choice) {
  case 1:
	  history = fopen("history.txt", "a+");
	  items = fopen("items.txt", "a+");
	  Player_Action(history, items);
	  break;
  case 2:
	  remove("history.txt");
	  remove("items.txt");
	  history = fopen("history.txt", "a+");
	  items = fopen("items.txt", "a+");
	  Prologue();
	  Show_Map();
	  Player_Action(history, items);
  }

  fclose(history);
  fclose(items);
  return 0;
}