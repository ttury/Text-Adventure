#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "ascii-art.h"
#include "event.h"

fpos_t move = 0;

int main() {
	FILE* history;
	FILE* items;
	int player_choice;

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	printf("test\n");
	printAsciiArt("title.txt");
	printf("\n������ ����Ʈ���� ���Ƹ� C#�� Text Adventure ���ӿ� ���� ���� ȯ���մϴ�.\n\n");
	printf("=======================\n");
	printf("1. �̾��ϱ�\n");
	printf("2. ���� �����ϱ�\n");
	printf("3. �����ϱ�\n");
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
		printf("\n������ �����մϴ�.\n");
		return 0;
		break;
	case -1:
		Debug_Mod();
		return 0;
		break;
	}

	fclose(history);
	fclose(items);

	getch();
	return 0;
}