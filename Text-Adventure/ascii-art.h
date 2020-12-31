#pragma once

#include <stdio.h>
#include <stdlib.h>

void printAsciiArt(char* nameOfAsciiArt) {
	char print_temp[256] = { 0x00, };
	FILE* rfp;
	char pathOfAsciiArt[100];
	sprintf(pathOfAsciiArt, ".\\Ascii-Art\\%s", nameOfAsciiArt);
	rfp = fopen(pathOfAsciiArt, "r+");

	if (rfp == NULL) {
		printf("%s 파일을 열지 못했습니다..\n", nameOfAsciiArt);
		return;
	}

	while (fgets(print_temp, 255, rfp) != NULL) {
		printf(print_temp);
	}
	puts("");

	fclose(rfp);

	return;
}