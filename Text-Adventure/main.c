#include <stdio.h>
#include <conio.h>
#include "event.h"

fpos_t move = 0;

int main() {
	FILE *history;
	FILE *items;
	char savetemp[MAX_LENGTH];


	int player_choice;

	printf("\n대전고 소프트웨어 동아리 C#의 Text Adventure 게임에 오신 것을 환영합니다.\n\n");
	printf("=======================\n");
	printf("1. 이어하기\n");
	printf("2. 새로 시작하기\n");
	printf("3. 종료하기\n");
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
		break;
	case 3:
		printf("\n게임을 종료합니다.\n");
		break;
  }

  fclose(history);
  fclose(items);

  getch();
  return 0;
}