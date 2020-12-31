#pragma once

#include <stdio.h>
#include <string.h>
#include <direct.h>
#include "ascii-art.h"

#define MAX_LENGTH 256
extern fpos_t move;

void fprintf_Flush(FILE* savefile, char* adddata) {
    fprintf(savefile, adddata);
    fflush(savefile);
}

void Prologue() {
    printf("\n2020��\n");
    printf("covid-19�� ������ �� ������ �浥�� ����\n");
    printf("5���� ���� ����\n");
    printf("���̷����� ������ ���� ����\n");
    printf("���ù����� ����ȭ ���̷����� �Ǿ���.\n\n");

    printf("���̷����� �������� ����� ���ڷ� �¼��� ��������б���\n");
    printf("�ᱹ ���� Ȯ���� �߻����� ���� ��¿ �� ���� �¶��� �н����� ��ȯ�Ѵ�.\n\n");

    printf("��ĥ �� �б����� �ڵ����� �м����� �����\n");
    printf("�б��� ��� �ִ� ��Ȳ�� �̿��� �б��� �����Ѵ�.\n");
    printf("�б����� ������� �����ϴ�.\n");
    printf("����� ���̷����� �������� �ʰ� �����ǿ� �ִ� �ڵ����� ��ã�� ������ �б��� ���������� �Ѵ�.\n");
}

void Show_Map() {
    printf("\n====================\n");
    printf("<�ǹ� ������>\n\n");
    printf("1�� : ���ǽ�, ������\n");
    printf("2�� : ��۽�\n");
    printf("3�� : ������\n");
    printf("4�� : ��ǻ�ͽ�\n");
    printf("5�� : �޽Ľ�, ������\n");
    printf("====================\n");
}

int Check_Save(FILE* savefile, char* checkdata) {
    char savetemp[MAX_LENGTH];
    fsetpos(savefile, &move);

    while (fgets(savetemp, MAX_LENGTH, savefile) != NULL) {
        if (!strcmp(savetemp, checkdata)) {
            fsetpos(savefile, &move);
            return 1;
        }
    }
    fsetpos(savefile, &move);
    return 0;
}

void EscapeSchool(FILE* history, FILE* items) {
    if (Check_Save(items, "�ڵ���\n")) {
        printf("\n�ڵ����� ������ ������ �б��� Ż���ߴ�.\n");
        printf("���� ���� �־��� �����ϰ� ���� ���� �־�����\n");
        printf("�ᱹ �ӹ��� �ϼ��ϴ� �� �����ߴ�.\n\n");
        printf("ũ��, ���� ����.\n");
        fprintf_Flush(history, "���� Ŭ����\n");
    }
    else {
        printf("\n�ڵ����� ������ Ż������ ������ �ǹ̰� ����.\n");
        printf("�ڵ����� ������ ȥ�� ��� ��ο� �����ǿ��� ���� ������ ���⸦ ��ٸ��� �ִ�.\n");
    }
}

void Nurse_Office(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(history, "���ǽ� Ŭ����\n")) {
        printf("\n���ǽǿ� ������ ����.\n");
        return;
    }

    printAsciiArt("nurse_office.txt");
    printf("\n���� ���ñ� ���� ���ǽǿ� ���Դ�.\n");
    printf("������ ���� �뷮�� ���� ���� ���� ���´�.\n");
    printf("Ȯ������ ġ�Ḧ ���� ���� ������ �� �鿩�� �� ����.\n\n");
    printf("������ �� ���� ���ο����� ����� �� ���� �� ������\n");
    printf("���߿� �ް����� �����ȴ�.\n\n");
    printf("��� �ұ�?");

    printf("\n====================\n");
    printf("1. ���� ���� �ִ´�.\n");
    printf("2. �����ϰ� ������.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);

    switch (player_choice) {
    case 1:
        printf("\n�и��� �� ���� ���� ���̴�.\n");
        fprintf_Flush(items, "���� ��\n");
        printf("���� ���� ������ ���ǽǿ��� ���Դ�.\n");
        fprintf_Flush(history, "���ǽ� Ŭ����\n");
        break;
    case 2:
        printf("\n�������� ������ ���� �� �ʹ�.\n");
        printf("���� �׸��ΰ� ���ǽǿ��� ���Դ�.\n");
        break;
    }
}

void Admin_Office(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(items, "������ ����\n")) {
        printf("\n�������� �ڽ��� �ӹ��� ���������� �ϼ��ߴ�.\n");
        printf("�������̳� ����\n");
        return;
    }
    if (Check_Save(history, "������ ���� �ʿ� Ȯ��\n")) {
        printAsciiArt("admin_office.txt");
        printf("\n���� �����ǿ� �����ߴ�.\n");
        printf("�������� ��ġ�� ã�Ҵ�.\n\n");

        printf("��� �ұ�?\n");

        printf("\n====================\n");
        printf("1. ������ ���踦 ��������.\n");
        printf("2. 5�� ������ ���踦 ��������.\n");
        printf("3. �� �ڵ����� ������ �ִ� 5�� ������ ���踦 ��������.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            printf("\n������ ���踦 ������.\n");
            printf("������ �ǵ� ��������.\n");
            fprintf_Flush(items, "������ ����\n");
            printf("�����Ƿ� ���ư���\n");
            break;
        case 2:
            printf("\n������ ���踦 ������.\n");
            printf("������ �ǵ� ��������.\n");
            fprintf_Flush(items, "������ ����\n");
            printf("�����Ƿ� ���ư���\n");
            break;
        case 3:
            printf("\n������ ���踦 ������.\n");
            printf("������ �ǵ� ��������.\n");
            fprintf_Flush(items, "������ ����\n");
            printf("�����Ƿ� ���ư���\n");
            break;
        }
    }
    else {
        printf("\n������ �� �߾������� ���� ��� ���ƴٴϰ� �ִ�.\n");
        printf("����� �ɰ� �����ǿ� �� �ʿ�� ���� �� ����.\n");
    }
}

void Broadcast_Room(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(history, "��۽� �޽� ���\n")) {
        printf("\n��۽ǿ� �� �̻� ������ ����.\n");
        return;
    }

    else if (Check_Save(history, "������ ���� ���� Ȯ��\n")) {
        printf("\n���� ���� ���� ����� ������ �ִٴ� ���� �������.\n\n");
        printf("���� �б��� �ִ� ����� ��κ� ���� �л��̾���.\n");
        printf("�л��� �̻� �޽��� �Ҹ��� �������� ������ ����.\n\n");
        printf("Ư���� �Ҹ��� �ΰ��� ����� �޽��� �Ҹ��� �鸮�ڸ��� �ʻ������� 5������ ������ ���̴�.\n");
        printf("�� ƴ�� �̿��� 1������ �������� �ȴ�.\n\n");
        printf("ũ��, ���� ���������� �Ϻ��ϴ�.\n\n");

        printf("��� �ұ�?\n");

        printf("\n====================\n");
        printf("1. ������� �޽����� �︰��.\n");
        printf("2. �׸��ΰ� ������.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            printf("\n�޽����� ���� �� ��ȴ�.\n");
            printf("��� �ʿ��� ������ �Ҹ��� ���� �����ߴ�.\n");
            printf("�Ҹ��� ���ƴ�.\n");
            printf("CCTV�� Ȯ���� ���� 1���� ��� �ְ� �޽ĽǷ� ���� �̵��� ���� Ȯ���ϴ�.\n\n");
            fprintf_Flush(history, "��۽� �޽� ���\n");

            printf("1�ʶ� ������ �� ����.\n");
            printf("�ִ��� ���� �����ǿ��� ���踦 ��������.\n");
            break;
        case 2:
            printf("\n�ð踦 ���� ���� 5�� ���� �� ����.\n");
            printf("�޽� ������ ��Ű�� ���� �߿��ϴ�.\n");
        }
    }
    else {
        printf("\n���� ��۽��� �� ������ ����.\n");
        printf("���� �ڵ����̳� ì�ܼ� Ż������.\n");
    }
}

void Library(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(history, "������ ���� �ʿ� Ȯ��\n")) {
        printf("\n���� ��� 1������ �ű� �� ������?\n");
        printf("\emp ��ġ�� ��� �����?\n");
        printf("���� ������ å �ӿ� �ִ�.\n");

        printf("\n====================\n");
        printf("1. ������ ���� ����� ���١��� �д´�.\n");
        printf("2. ������ �� EMP���� �д´�.\n");
        printf("====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            if (Check_Save(history, "������ ���� ���� Ȯ��\n")) {
                printf("\n�̹� ���� å�̴�.\n");
                printf("���� ������ ������ ��۽��̳� ������.\n");
                return;
            }
            printf("\n������� �������� ������ �� �ִ� �������ڰ� �� å�̴�.\n");
            printf("���� ���� ���ذ� �þ �� ����.\n\n");

            printf("��̷ο� ������ �߰��ߴ�.\n");
            printf("����� ���� ���� ����� ���������� ������ �ִٰ� �Ѵ�.\n");
            printf("Ư���� �Ҹ��� ���õ� ��￡ ���� �ΰ��ϴٰ� �Ѵ�.\n\n");
            fprintf_Flush(history, "������ ���� ���� Ȯ��\n");

            printf("��, �ƹ����� ��۽ǿ� �����߰ڳ�.\n");
            break;
        case 2:
            if (Check_Save(items, "���� �� EMP\n")) {
                printf("\n�Ȱ��� å�� �� �� ������ �ʿ�� ����.\n");
                printf("���� ������ ������ ��ǻ�ͽ��̳� ������.\n");
                return;
            }
            printf("\n���� ���� �ʵ� ������ ������ ���ڰ��� ������.\n");
            printf("�ʵ��л��� ������ �� ���� ������ ���� ����ִ�.\n\n");

            printf("������ ���� �� �ڸ����� �� �б�� ����� �� ����.\n");
            printf("å�� ������ ��ǻ�ͽǿ� ������\n");
            fprintf_Flush(items, "���� �� EMP\n");
        }
    }
    else {
        printf("\nå�̳� ���� ���� �ð��� ����.\n");
        printf("�Դٰ� ��ü ���̶� å�� �� ������.\n");
    }
}

void Computer_Room(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(history, "������ ���� �ʿ� Ȯ��\n")) {
        if (Check_Save(items, "EMP ��ġ\n")) {
            printf("\n��ǻ�ͽǿ� �� ������ ����.\n");
            return;
        }
        printf("\nȭ����� ������ ������ �� �� ������\n");
        printf("dev c++�� �Ƶ��̳�� �����ϴ�.\n");
        printf("��� �ұ�?\n");
        printf("\n====================\n");
        printf("1. �Ƶ��̳븦 ���α׷����� EMP ��ġ�� �����.\n");
        printf("2. �׳� ������.\n");
        printf("====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            if (Check_Save(items, "���� �� EMP\n")) {
                printf("\n�Ʊ� ���������� ���� ���� �� EMP�� ���´�.");
                printf("�Ƶ��̳� ȸ�θ� �����ϰ� å�� ���� �ҽ��� �ٿ��ֱ� �ߴ�.\n");
                printf("�Ҹ� �� �� ����.\n");
                printf("���������� EMP ��ġ�� �������!\n");
                fprintf_Flush(items, "EMP ��ġ\n");
            }
            else {
                printf("\n�ʵ��б� ����� �ð��� ������� ����� �ǻ�� ������ �õ�������\n");
                printf("���� ������ �� ����.\n");
                printf("���� ������ ������ ������ �� ���⵵ �ϴ�.\n");
            }
            break;
        case 2:
            printf("\nȤ�ó� �ؼ� ��������� �õ��� �������� ���ó� â�� ������ ������.\n");
            printf("����� ���ؼ� ������ ���Դ�.\n");
        }
    }
    else {
        printf("\nȭ����� ������ ������ �� �� ����.\n");
        printf("���� �ǹ̰� ���� ��Ҵ�.\n");
    }
}

void Cafeteria(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(history, "�޽Ľ� �� ���\n")) {
        printf("�޽Ľǿ� ���̻� �ٰ����ٰ� ���� Ư���� �� ���� �ִ�.\n");
        return;
    }

    else if (Check_Save(history, "�޽Ľ� ���� �غ�\n")) {
        if (Check_Save(history, "��۽� �޽� ���\n")) {
            printf("\n������� ������ �ӵ��� �Ǹ� �Ծ�ġ��� �ִ�.\n");
            printf("�̴�ζ�� ���� ������ �� ����.\n");
            printf("�ӹ��� ��ġ�� �� �ʿ��� �ð��� ����� �Ѵ�.\n");
            printf("\n====================\n");
            printf("1. �޽Ľ� ���� ��ٴ�.\n");
            printf("2. õõ�� ������� �Ҹ�������.\n");
            printf("3. �׳� ���д�.\n");
            printf("====================\n");

            scanf("%d", &player_choice);

            switch (player_choice) {
            case 1:
                printf("\n�׻� ������ ��Ȳ�� ����ؾ� �Ѵ�.\n");
                printf("�޽Ľ� ���� �߰����� ������ �ð��� �����̳��� ������ ���̴�. �Ƹ���?\n");
                printf("�޽Ľ� ���� ��ɴ�.\n");
                fprintf_Flush(history, "�޽Ľ� �� ���\n");
                break;
            case 2:
                printf("\n����� ���� ���� ����� ������ �ִٰ� �ߴ�.\n");
                printf("�׷��ٸ� ���� �������� ô �ϴ� ���� ȿ���������� �𸥴�.\n");
                printf("�Ʒ��迡 ���� �� �ְ� �Ҹ��� ������.\n\n");
                printf("�׷��� ���� ������� �ʾҴ�.\n");
                printf("��׷ο� �г��� ������� �޷������.\n");
                fprintf_Flush(history, "���� ����\n");
                break;
            case 3:
                printf("\n�޽� �ٸ����� ���� ������.\n");
                printf("������ �� ����.\n");
                break;
            }
        }
        else {
            printf("\n�޽Ľǿ� ������ ��ġ�Ǿ� �ִ�.\n");
            printf("�ϳ��ϳ� ���ǿ� ����� �������.\n");
        }
    }
    else if (Check_Save(history, "������ ���� �ʿ� Ȯ��\n") && Check_Save(items, "���� ��\n")) {
        printf("\n���� ���� �̿��ϸ� �޽ĽǷ� ���� ������ �� ���� ������?\n");
        printf("\n====================\n");
        printf("1. ���� ���� ��ġ�Ѵ�.\n");
        printf("2. �׸��д�.\n");
        printf("====================\n");
        scanf("%d", &player_choice);
        switch (player_choice) {
        case 1:
            printf("\n���� ���� ���������� ���� ���� ��ѷȴ�..\n");
            fprintf_Flush(history, "�޽Ľ� ���� �غ�\n");
            printf("������ 1���� �ִ� ������� ������� ������ �ð� �ø��� ������.\n");
            printf("���� �����Ϸ��� �߰����� ��ġ�� �ʿ��� �� ����.\n");
            break;
        case 2:
            printf("\n���ǽ� ������ ����ǳ�� ���� �� ����.\n");
            printf("������ ������ �ʿ�� ����.\n");
        }
    }
    else {
        printf("\n�޽� �԰� ���� ���� �ƴϴ�.\n");
        printf("���ʿ� ���� �޽ĵ� ����.\n");
    }
}

void Teacher_Office(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(items, "�ڵ���\n")) {
        printf("�޽Ľ� ���� ���� ��Ƽ�� ���Ѵ�.\n");
        printf("������ �ߴ��� �����濡�� �������� ���� ������ �ƴ� �� ����.\n");
        return;
    }

    else if (Check_Save(history, "�ڹ��� ����\n") && Check_Save(history, "���� ����ȭ\n")) {
        printf("\n����, ������ ���� ���ȴ�.\n");
        printf("�� �ڵ����� å�� ���� ���� �ִ�.\n");
        printf("��� �ұ�?\n");
        printf("\n====================\n");
        printf("1. ���Ӱ� �ӹ��� �ϼ��Ѵ�.\n");
        printf("2. ���� �� �ϸ� �ȵ�.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            printf("\n�λ��� �����ڸ� ��ã�Ҵ�.\n");
            fprintf_Flush(items, "�ڵ���\n");
            printf("��� �������� �������� ���Դ�.\n");
            break;
        case 2:
            printf("\n��� ����!\n");
            printf("\n�λ��� �����ڸ� ��ã�Ҵ�.\n");
            fprintf_Flush(items, "�ڵ���\n");
            printf("��� �������� �������� ���Դ�.\n");
        }

    }

    else if (Check_Save(history, "������ ���� �ʿ� Ȯ��\n")) {
        printf("\n�����ǿ� ���� ���ؼ��� ����� EMP ��ġ�� �ʿ��ϴ�.\n");
        printf("��� �ұ�?\n");

        printf("\n====================\n");
        printf("1. ����� �ڹ��踦 �����Ѵ�.\n");
        printf("2. EMP ��ġ�� ������ �����Ų��.\n");
        printf("3. �׸��д�.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            if (Check_Save(history, "�ڹ��� ����\n")) {
                printf("\n�ڹ���� �̹� ���ŵǾ���.\n");
                return;
            }
            else if (Check_Save(items, "������ ����\n")) {
                printf("\n�� ���´� �� ����� ����.\n");
                printf("�ڹ��谡 ���ŵǾ���.\n");
                fprintf_Flush(history, "�ڹ��� ����\n");
            }
            else {
                printf("\n���谡 ������ �ڹ��踦 ���� ���Ѵٴ� ����� �˰� �Ǿ���.\n");
                printf("�����ǿ��� ���踦 ��������.\n");
            }
            break;
        case 2:
            if (Check_Save(history, "���� ����ȭ\n")) {
                printf("\n������ �̹� ����ȭ�Ǿ���.\n");
                return;
            }
            else if (Check_Save(items, "EMP ��ġ\n")) {
                printf("\n��� ����ũ Ƣ�� �Ҹ��� ������ ������ ������.\n");
                printf("�̰� ��¥ �� ���̾�.\n");
                printf("������ ����ȭ�Ǿ���.\n");
                fprintf_Flush(history, "���� ����ȭ\n");
            }
            else {
                printf("\nEMP ��ġ�� ���ٸ� ������ ��й�ȣ�� ���� ���ۿ� ����.\n");
                printf("����, �װ� ���� �� ����.\n");
                printf("EMP ��ġ�� �����ϴ� ����� ã��.\n");
            }
            break;
        case 3:
            printf("\n������ ��������.\n");
            printf("������ �� ���� �ְھ�.\n");
            break;
        }
    }
    else {
        printf("\n���� �����ǿ� �����ߴ�!\n");
        printf("�׷��� �翬�� ���� ��� �ִٴ� ����� �翬���� ���ϰ� ���� ���ߴ�.\n");
        printf("�ٸ� ������ �� ���� �־��µ�\n");
        printf("���� �������� ������ ����ϴ�.\n\n");

        printf("������ ���� ���캸�� ŭ���� �ڹ��谡 �ɷ� �ִ�.\n");
        printf("�����ǿ� ���� ���谡 ���� �� ����.\n\n");

        printf("�� ���� �Һ��� �����ϴ� ���޵� �۵��ϰ� �ִ� �� ����.\n");
        printf("������ ����ȭ��ų emp��ġ�� �ʿ��ϴ�.\n\n");

        printf("��� â���� ���ٺ��� ���ڱ� 1���� ������� ���������.\n");
        printf("�����ǿ� ���� ���ؼ��� ���� �Űܾ� �Ѵ�.\n\n");

        fprintf_Flush(history, "������ ���� �ʿ� Ȯ��\n");
        printf("��, ���� �� �Ա���\n");
    }
}

int Floor_One(FILE* history, FILE* items) {
    int player_choice;
    if (Check_Save(history, "��۽� �޽� ���\n")) {
        printf("\n���������� ������ 1���� ���� �ִ� ����� ���� �� ����.\n");
        printf("�ð��� ����.\n");
    }
    else if (Check_Save(history, "������ ���� �ʿ� Ȯ��\n")) {
        printf("\n1������ �������⿣ ���� �ʹ� ����.\n");
        printf("�����ǿ� ���� ���ؼ��� ���� ���� �ٸ� ������ �Űܾ� �Ѵ�.\n");
        return 2;
    }
    else {
        printf("\n1������ ������ ���Դ�.\n");
        printf("�ڵ����� 5�� �����ǿ� ���� ���̴�.\n");
        printf("��� �ұ�?\n");
    }

    printf("\n====================\n");
    printf("1. 2������ �ö󰣴�.\n");
    printf("2. ���ǽǿ� �鸥��.\n");
    printf("3. �����ǿ� �鸥��.\n");
    printf("4. ������ ������.\n");
    printf("5. �ǹ� �������� Ȯ���Ѵ�.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);

    switch (player_choice) {
    case 1:
        return 2;
        break;
    case 2:
        Nurse_Office(history, items);
        return 1;
        break;
    case 3:
        Admin_Office(history, items);
        return 1;
        break;
    case 4:
        EscapeSchool(history, items);
        return 1;
    case 5:
        Show_Map();
    }
    return 1;
}

int Floor_Two(FILE* history, FILE* items) {
    int player_choice;

    printf("\n2���̴�.\n");
    printf("��� �ұ�?\n");

    printf("\n====================\n");
    printf("1. 3������ �ö󰣴�.\n");
    printf("2. 1������ ��������.\n");
    printf("3. ��۽ǿ� �鸥��.\n");
    printf("4. �ǹ� �������� Ȯ���Ѵ�.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);

    switch (player_choice) {
    case 1:
        return 3;
        break;
    case 2:
        return 1;
        break;
    case 3:
        Broadcast_Room(history, items);
        return 2;
        break;
    case 4:
        Show_Map();
    }
    return 2;
}

int Floor_Three(FILE* history, FILE* items) {
    int player_choice;

    printf("\n3���̴�.\n");
    printf("��� �ұ�?\n");

    printf("\n====================\n");
    printf("1. 4������ �ö󰣴�.\n");
    printf("2. 2������ ��������.\n");
    printf("3. �������� �鸥��.\n");
    printf("4. �ǹ� �������� Ȯ���Ѵ�.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);

    switch (player_choice) {
    case 1:
        return 4;
        break;
    case 2:
        return 2;
        break;
    case 3:
        Library(history, items);
        return 3;
        break;
    case 4:
        Show_Map();
    }
    return 3;
}

int Floor_Four(FILE* history, FILE* items) {
    int player_choice;

    printf("\n4���̴�.\n");
    printf("��� �ұ�?\n");

    printf("\n====================\n");
    printf("1. 5������ �ö󰣴�.\n");
    printf("2. 3������ ��������.\n");
    printf("3. ��ǻ�ͽǿ� �鸥��.\n");
    printf("4. �ǹ� �������� Ȯ���Ѵ�.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);

    switch (player_choice) {
    case 1:
        return 5;
        break;
    case 2:
        return 3;
        break;
    case 3:
        Computer_Room(history, items);
        return 4;
        break;
    case 4:
        Show_Map();
    }
    return 4;
}

int Floor_Five(FILE* history, FILE* items) {
    int player_choice;

    if (Check_Save(items, "�ڵ���\n")) {
        if (Check_Save(history, "�޽Ľ� �� ���\n")) {
            printf("\n��¦ �����.\n");
            printf("�ݼ� ���� ���� ��ġ�� ������� �޽Ľ� ���� �ε帮�� �ִ�.\n");
            printf("�޽Ľ� ���� ����� �ʾҴٸ� ū�ϳ� �� �ߴ�.\n");
        }
        else {
            printf("\n������ ������ ������ ���� �޽Ľǿ��� ���ĳ��� ����鿡�� �ѷ��ο���.\n");
            printf("�ƹ����� �޽��� �����߳� ����\n");
            printf("�̷�, �޽Ľ� ���̶� ��ɤ��Ѹ礤\n");
            fprintf_Flush(history, "���� ����\n");
            return 5;
        }
    }

    else if (Check_Save(history, "��۽� �޽� ���\n") && !Check_Save(history, "�޽Ľ� ���� �غ�\n")) {
        printf("\n�޽Ľǿ� ���� �� ���� ������� ��û ȭ����.\n");
        printf("�ƹ����� ���� �޽����� ���̴� �� ����.\n");
        printf("�������ľ��Ѥ�\n");
        fprintf_Flush(history, "���� ����\n");
        return 5;
    }

    printf("\n5���̴�.\n");
    printf("��� �ұ�?\n");

    printf("\n====================\n");
    printf("1. 4������ ��������.\n");
    printf("2. �����ǿ� �鸥��.\n");
    printf("3. �޽Ľǿ� �鸥��.\n");
    printf("4. �ǹ� �������� Ȯ���Ѵ�.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);

    switch (player_choice) {
    case 1:
        return 4;
        break;
    case 2:
        Teacher_Office(history, items);
        return 5;
        break;
    case 3:
        Cafeteria(history, items);
        return 5;
        break;
    case 4:
        Show_Map();
    }
    return 5;
}

void Player_Action(FILE* history, FILE* items) {
    int floor = 1;
    while (1) {
        if (Check_Save(history, "���� ����\n")) {
            printf("\nGame Over\n");
            break;
        }
        else if (Check_Save(history, "���� Ŭ����\n")) {
            printf("\nGame Clear\n");
            break;
        }
        switch (floor) {
        case 1:
            floor = Floor_One(history, items);
            break;
        case 2:
            floor = Floor_Two(history, items);
            break;
        case 3:
            floor = Floor_Three(history, items);
            break;
        case 4:
            floor = Floor_Four(history, items);
            break;
        case 5:
            floor = Floor_Five(history, items);
            break;
        }
    }
}