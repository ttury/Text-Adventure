#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 128
extern fpos_t move;

void fprintf_Flush(FILE* savefile, char* adddata) {
    fprintf(savefile, adddata);
    fflush(savefile);
}

void Prologue() {
  printf("\n2020년\n");
  printf("covid-19의 출현과 전 세계적 펜데믹 이후\n");
  printf("5년이 지난 지금\n");
  printf("바이러스는 수많은 변이 끝에\n");
  printf("무시무시한 좀비화 바이러스가 되었다.\n\n");

  printf("바이러스의 위협에도 꿋꿋이 야자로 맞서던 대전고등학교는\n");
  printf("결국 교내 확진자 발생으로 인해 어쩔 수 없이 온라인 학습으로 전환한다.\n\n");
  
  printf("며칠 전 학교에서 핸드폰을 압수당한 당신은\n");
  printf("학교가 비어 있는 상황을 이용해 학교로 잠입한다.\n");
  printf("학교에는 좀비들이 가득하다.\n");
  printf("당신은 바이러스에 감염되지 않고 핸드폰을 되찾아 무사히 학교를 빠져나가야 한다.\n");
}

void Show_Map() {
  printf("\n====================\n");
  printf("<교실 배치도>\n\n");
  printf("1층 : 보건실, 행정실\n");
  printf("2층 : 방송실\n");
  printf("3층 : 도서관\n");
  printf("4층 : 컴퓨터실\n");
  printf("5층 : 급식실, 교무실\n");
  printf("====================\n");
}

int Check_Save(FILE *savefile, char *checkdata) {
  char savetemp[MAX_LENGTH];

  while(fgets(savetemp, MAX_LENGTH, savefile) != NULL) {
    if(!strcmp(savetemp, checkdata)) {
      fsetpos(savefile, &move);
      return 1;
    }
  }
  fsetpos(savefile, &move);
  return 0;
}

void Nurse_Office(FILE *history, FILE *items) {
  int player_choice;

  if(Check_Save(history, "보건실 클리어\n")) {
    printf("보건실에 볼일은 없다.\n");
    return;
  }
  printf("\n물을 마시기 위해 보건실에 들어왔다.\n");
  printf("들어오자 마자 대량의 혈액 팩이 눈에 들어온다.\n");
  printf("확진자의 치료를 위한 헌혈 켐페인 때 들여온 것 같다.\n");
  printf("여차할 때 좀비 유인용으로 사용할 수 있을 것 같지만\n");
  printf("나중에 뒷감당이 걱정된다.\n");
  printf("어떻게 할까?");

  printf("\n====================\n");
  printf("1. 가방 가득 넣는다.\n");
  printf("2. 포기하고 나간다.\n");
  printf("=====================\n");

  scanf("%d", &player_choice);

  switch(player_choice) {
    case 1:
      printf("분명히 쓸 곳이 있을 것이다.\n");
      fprintf_Flush(items, "혈액 팩\n");
      printf("혈액 팩을 가지고 보건실에서 나왔다.\n");
      fprintf_Flush(history, "보건실 클리어\n");
      break;
    case 2:
      printf("벌점으로 끝나진 않을 듯 싶다.\n");
      printf("역시 그만두고 보건실에서 나왔다.\n");
      fprintf(history, "보건실 클리어\n");
      break;
  }
}

void Admin_Office(FILE *history, FILE *items) {

}

void Broadcast_Room(FILE *history, FILE *items) {

}

void Library(FILE *history, FILE *items) {

}

void Computer_Room(FILE *history, FILE *items) {

}

void Cafeteria(FILE *history, FILE *items) {

}

void Teacher_Office(FILE *history, FILE *items) {

}

int Floor_One(FILE *history, FILE *items) {
  int player_choice;
  if(Check_Save(history, "교무실 열쇠 필요 확인\n")) {
    
  }
  else {
    printf("1층으로 무사히 들어왔다.\n");
    printf("어디로 움직일까?\n");

    printf("\n====================\n");
    printf("1. 2층으로 바로 올라간다.\n");
    printf("2. 보건실에 들른다.\n");
    printf("3. 행정실에 들른다.\n");
    printf("=====================\n");

    scanf("%d", &player_choice);
    
    switch(player_choice) {
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
    }
  }
  return 1;
}

int Floor_Two(FILE *history, FILE *items) {
  return 2;
}

int Floor_Three(FILE *history, FILE *items) {
  return 3;
}

int Floor_Four(FILE *history, FILE *items) {
  return 4;
}

int Floor_Five(FILE *history, FILE *items) {
  return 5;
}

void Player_Action(FILE *history, FILE *items) {

  int floor = 1;
  while(1) {
    switch(floor) {
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

int Battle_Zombie_1(FILE *characters, FILE *items) {
  int player_choice;
  printf("\nthere is a zombie!!\n");
  printf("and your choce?\n");
  printf("\n====================\n");
  printf("1. fight\n");
  printf("2. swearing\n");
  printf("====================\n");
  scanf("%d", &player_choice);
  
  switch(player_choice) {
    case 1:
      printf("\nyou fought well, but zombie fought better\n");
      printf("you dead\n");
      return 1;
      break;
    case 2:
      printf("\nzombie is sad in her heart.\n");
      printf("you rubbish\n");
      printf("you win!\n\n");
      fprintf(characters, "zombie1 : sad\n");
      return 0;
      break;
  }
  return 1;
}

int Battle_Zombie_2(FILE *characters, FILE *items) {
  int player_choice;
  char savetemp[100];

  printf("there is a zombie!!\n");
  printf("and your choce?\n");
  printf("\n===================\n");
  printf("1. saying love\n");
  printf("2. swearing\n");
  printf("====================\n");
  scanf("%d", &player_choice);
  
  switch(player_choice) {
    case 1:
      printf("\nHe seems to be shy\n");
      printf("He disappeared somewhere..\n");
      printf("you win!!\n");
      printf("Umm? a sheet of paper is left where he left\n");
      printf("you get his number\n");
      fprintf(items, "zombie\'s number\n");
      return 0;
      break;
    case 2:
      fscanf(characters, "zombie1 : %s", savetemp);
      if(strcmp(savetemp, "sad")) {
        printf("\nHe is a boyfriend of the zombie you hurt\n");
        printf("He picked you up and drive you into the ground\n");
        printf("Oh.. disgusting..\n");
        printf("You dead\n");
        return 1;
      }
      break;
  }
  return 1;
}