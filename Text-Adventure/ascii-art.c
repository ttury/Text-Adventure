#include <stdlib.h>
#include <Windows.h>

void printAsciiArt(char *nameOfAsciiArt) {
	char print_temp[256];
	FILE* rfp;
	char pathOfAsciiArt[100];
	sprintf(pathOfAsciiArt, ".\\Ascii-Art\\%s", nameOfAsciiArt);
	rfp = fopen(pathOfAsciiArt, "r");

	system("mode con cols=130");

	if (rfp == NULL) {
		printf("%s � �ҷ� � �ϴ�.\n", nameOfAsciiArt);
		return;
	}

	while (fgets(print_temp, 255, rfp) != NULL) {
		printf(print_temp);
	}
	puts("");

	fclose(rfp);

	return;
}

int main() {
	printAsciiArt("thinkingface.txt");
	return 0;
}