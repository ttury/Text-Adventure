#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256
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
  printf("당신은 바이러스에 감염되지 않고 교무실에 있는 핸드폰을 되찾아 무사히 학교를 빠져나가야 한다.\n");
}

void Show_Map() {
  printf("\n====================\n");
  printf("<건물 구조도>\n\n");
  printf("1층 : 보건실, 행정실\n");
  printf("2층 : 방송실\n");
  printf("3층 : 도서관\n");
  printf("4층 : 컴퓨터실\n");
  printf("5층 : 급식실, 교무실\n");
  printf("====================\n");
}

int Check_Save(FILE *savefile, char *checkdata) {
  char savetemp[MAX_LENGTH];
  fsetpos(savefile, &move);

  while(fgets(savetemp, MAX_LENGTH, savefile) != NULL) {
    if(!strcmp(savetemp, checkdata)) {
      fsetpos(savefile, &move);
      return 1;
    }
  }
  fsetpos(savefile, &move);
  return 0;
}

void Escape(FILE* history, FILE* items) {
    if (Check_Save(items, "핸드폰\n")) {
        printf("\n핸드폰을 가지고 무사히 학교를 탈출했다.\n");
        printf("힘든 때도 있었고 포기하고 싶은 때도 있었지만\n");
        printf("결국 임무를 완수하는 데 성공했다.\n\n");
        printf("크으, 역시 나다.\n");
        fprintf_Flush(history, "게임 클리어\n");
    }
    else {
        printf("\n핸드폰을 가지고 탈출하지 않으면 의미가 없다.\n");
        printf("핸드폰은 아직도 혼자 춥고 어두운 교무실에서 내가 데리러 오기를 기다리고 있다.\n");
    }
}

void Nurse_Office(FILE *history, FILE *items) {
  int player_choice;

  if(Check_Save(history, "보건실 클리어\n")) {
    printf("\n보건실에 볼일은 없다.\n");
    return;
  }
  printf("\n물을 마시기 위해 보건실에 들어왔다.\n");
  printf("들어오자 마자 대량의 혈액 팩이 눈에 들어온다.\n");
  printf("확진자의 치료를 위한 헌혈 켐페인 때 들여온 것 같다.\n\n");
  printf("여차할 때 좀비 유인용으로 사용할 수 있을 것 같지만\n");
  printf("나중에 뒷감당이 걱정된다.\n\n");
  printf("어떻게 할까?");

  printf("\n====================\n");
  printf("1. 가방 가득 넣는다.\n");
  printf("2. 포기하고 나간다.\n");
  printf("=====================\n");

  scanf("%d", &player_choice);

  switch(player_choice) {
    case 1:
      printf("\n분명히 쓸 곳이 있을 것이다.\n");
      fprintf_Flush(items, "혈액 팩\n");
      printf("혈액 팩을 가지고 보건실에서 나왔다.\n");
      fprintf_Flush(history, "보건실 클리어\n");
      break;
    case 2:
      printf("\n벌점으로 끝나진 않을 듯 싶다.\n");
      printf("역시 그만두고 보건실에서 나왔다.\n");
      break;
  }
}

void Admin_Office(FILE *history, FILE *items) {
    int player_choice;
    if (Check_Save(items, "교무실 열쇠\n")) {
        printf("\n행정실은 자신의 임무를 성공적으로 완수했다.\n");
        printf("교무실이나 가자\n");
        return;
    }
    if (Check_Save(history, "교무실 열쇠 필요 확인\n")) {
        printf("\n드디어 행정실에 도착했다.\n");
        printf("열쇠함의 위치도 찾았다.\n\n");

        printf("어떻게 할까?\n");

        printf("\n====================\n");
        printf("1. 교무실 열쇠를 가져간다.\n");
        printf("2. 5층 교무실 열쇠를 가져간다.\n");
        printf("3. 내 핸드폰이 숨겨져 있는 5층 교무실 열쇠를 가져간다.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            printf("\n교무실 열쇠를 집었다.\n");
            printf("빌리는 건데 괜찮겠지.\n");
            fprintf_Flush(items, "교무실 열쇠\n");
            printf("교무실로 돌아가자\n");
            break;
        case 2:
            printf("\n교무실 열쇠를 집었다.\n");
            printf("빌리는 건데 괜찮겠지.\n");
            fprintf_Flush(items, "교무실 열쇠\n");
            printf("교무실로 돌아가자\n");
            break;
        case 3:
            printf("\n교무실 열쇠를 집었다.\n");
            printf("빌리는 건데 괜찮겠지.\n");
            fprintf_Flush(items, "교무실 열쇠\n");
            printf("교무실로 돌아가자\n");
            break;
        }
    }
    else {
        printf("\n행정실 쪽 중앙현관에 좀비가 몇명 돌아다니고 있다.\n");
        printf("목숨을 걸고서 행정실에 갈 필요는 없을 것 같다.\n");
    }
}

void Broadcast_Room(FILE *history, FILE *items) {
    int player_choice;

    if (Check_Save(history, "방송실 급식 방송\n")) {
        printf("\n방송실에 더 이상 볼일은 없다.\n");
        return;
    }

    else if (Check_Save(history, "도서관 좀비 정보 확인\n")) {
        printf("\n좀비가 감염 전의 기억을 가지고 있다는 것을 고려하자.\n\n");
        printf("지금 학교에 있는 좀비는 대부분 원래 학생이었다.\n");
        printf("학생인 이상 급식종 소리에 반응하지 않을리 없다.\n\n");
        printf("특히나 소리에 민감한 좀비는 급식종 소리가 들리자마자 필사적으로 5층으로 몰려갈 것이다.\n");
        printf("그 틈을 이용해 1층으로 내려가면 된다.\n\n");
        printf("크으, 내가 생각했지만 완벽하다.\n\n");

        printf("어떻게 할까?\n");

        printf("\n====================\n");
        printf("1. 방송으로 급식종을 울린다.\n");
        printf("2. 그만두고 나간다.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            printf("\n급식종을 여러 번 울렸다.\n");
            printf("계단 쪽에서 굉장한 소리가 나기 시작했다.\n");
            printf("소리가 그쳤다.\n");
            printf("CCTV를 확인해 보니 1층은 비어 있고 급식실로 좀비가 이동한 것이 확실하다.\n\n");
            fprintf_Flush(history, "방송실 급식 방송\n");

            printf("1초라도 낭비할 수 없다.\n");
            printf("최대한 빨리 행정실에서 열쇠를 가져오자.\n");
            break;
        case 2:
            printf("\n시계를 보니 아직 5분 남은 것 같다.\n");
            printf("급식 순서를 지키는 것은 중요하다.\n");
        }
    }
    else {
        printf("\n지금 방송실을 갈 이유는 없다.\n");
        printf("빨리 핸드폰이나 챙겨서 탈출하자.\n");
    }
}

void Library(FILE *history, FILE *items) {
    int player_choice;

    if (Check_Save(history, "교무실 열쇠 필요 확인\n")) {
        printf("\n좀비를 어떻게 1층에서 옮길 수 있을까?\n");
        printf("\emp 장치를 어떻게 만들까?\n");
        printf("답은 언제나 책 속에 있다.\n");

        printf("\n====================\n");
        printf("1. 「세상에 나쁜 좀비는 없다」를 읽는다.\n");
        printf("2. 「점프 투 EMP」를 읽는다.\n");
        printf("====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            if (Check_Save(history, "도서관 좀비 정보 확인\n")) {
                printf("\n이미 읽은 책이다.\n");
                printf("좋은 생각이 났으니 방송실이나 가보자.\n");
                return;
            }
            printf("\n좀비와의 교감으로 유명한 명성 있는 좀비학자가 쓴 책이다.\n");
            printf("좀비에 대한 이해가 늘어난 것 같다.\n\n");

            printf("흥미로운 내용을 발견했다.\n");
            printf("좀비는 감염 전의 기억을 본능적으로 가지고 있다고 한다.\n");
            printf("특히나 소리에 관련된 기억에 아주 민감하다고 한다.\n\n");
            fprintf_Flush(history, "도서관 좀비 정보 확인\n");

            printf("음, 아무래도 방송실에 가봐야겠네.\n");
            break;
        case 2:
            if (Check_Save(items, "점프 투 EMP\n")) {
                printf("\n똑같은 책을 두 권 가져갈 필요는 없다.\n");
                printf("좋은 생각이 났으니 컴퓨터실이나 가보자.\n");
                return;
            }
            printf("\n정보 교과 필독 도서로 지정된 전자공학 도서다.\n");
            printf("초등학생도 이해할 수 있을 정도로 쉽고 재미있다.\n\n");

            printf("내용이 많아 이 자리에서 다 읽기는 어려울 것 같다.\n");
            printf("책을 가지고 컴퓨터실에 가보자\n");
            fprintf_Flush(items, "점프 투 EMP\n");
        }
    }
    else {
        printf("\n책이나 보고 있을 시간은 없다.\n");
        printf("게다가 연체 중이라 책을 못 빌린다.\n");
    }
}

void Computer_Room(FILE *history, FILE *items) {
    int player_choice;

    if (Check_Save(history, "교무실 열쇠 필요 확인\n")) {
        if (Check_Save(items, "EMP 장치\n")) {
            printf("\n컴퓨터실에 더 볼일은 없다.\n");
            return;
        }
        printf("\n화면잠금 때문에 게임은 할 수 없지만\n");
        printf("dev c++와 아두이노는 가능하다.\n");
        printf("어떻게 할까?\n");
        printf("\n====================\n");
        printf("1. 아두이노를 프로그래밍해 EMP 장치를 만든다.\n");
        printf("2. 그냥 나간다.\n");
        printf("====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            if (Check_Save(items, "점프 투 EMP\n")) {
                printf("\n아까 도서관에서 빌린 점프 투 EMP를 꺼냈다.");
                printf("아두이노 회로를 구성하고 책에 나온 소스를 붙여넣기 했다.\n");
                printf("할만 한 것 같다.\n");
                printf("성공적으로 EMP 장치를 만들었다!\n");
                fprintf_Flush(items, "EMP 장치\n");
            }
            else {
                printf("\n초등학교 방과후 시간에 만들었던 기억을 되살려 열심히 시도했지만\n");
                printf("역시 무리인 것 같다.\n");
                printf("관련 서적이 있으면 가능할 것 같기도 하다.\n");
            }
            break;
        case 2:
            printf("\n혹시나 해서 공룡게임을 시도해 보았지만 역시나 창이 강제로 꺼졌다.\n");
            printf("기분이 상해서 밖으로 나왔다.\n");
        }
    }
    else {
        printf("\n화면잠금 때문에 게임을 할 수 없다.\n");
        printf("존재 의미가 없는 장소다.\n");
    }
}

void Cafeteria(FILE *history, FILE *items) {
    int player_choice;
    
    if (Check_Save(history, "급식실 문 잠금\n")) {
        printf("급식실에 더이상 다가가다간 내가 특식이 될 수도 있다.\n");
        return;
    }

    else if (Check_Save(history, "급식실 혈액 준비\n")) {
        if (Check_Save(history, "방송실 급식 방송\n")) {
            printf("\n좀비들이 무서운 속도로 피를 먹어치우고 있다.\n");
            printf("이대로라면 조금 위험할 것 같다.\n");
            printf("임무를 마치는 데 필요한 시간을 벌어야 한다.\n");
            printf("\n====================\n");
            printf("1. 급식실 문을 잠근다.\n");
            printf("2. 천천히 먹으라고 소리지른다.\n");
            printf("3. 그냥 냅둔다.\n");
            printf("====================\n");

            scanf("%d", &player_choice);

            switch (player_choice) {
            case 1:
                printf("\n항상 만약의 상황을 대비해야 한다.\n");
                printf("급식실 문이 견고하진 않지만 시간을 조금이나마 벌어줄 것이다. 아마도?\n");
                printf("급식실 문을 잠궜다.\n");
                fprintf_Flush(history, "급식실 문 잠금\n");
                break;
            case 2:
                printf("\n좀비는 감염 전의 기억을 가지고 있다고 했다.\n");
                printf("그렇다면 학주 선생님인 척 하는 것이 효과적일지도 모른다.\n");
                printf("아랫배에 힘을 꽉 주고 소리를 질렀다.\n\n");
                printf("그러나 전혀 비슷하지 않았다.\n");
                printf("어그로에 분노한 좀비들이 달려들었다.\n");
                fprintf_Flush(history, "게임 오버\n");
                break;
            case 3:
                printf("\n급식 다먹으면 매점 가겠지.\n");
                printf("괜찮을 것 같다.\n");
                break;
            }
        }
        else {
            printf("\n급식실에 혈액이 배치되어 있다.\n");
            printf("하나하나 식판에 담느라 힘들었다.\n");
        }
    }
    else if (Check_Save(history, "교무실 열쇠 필요 확인\n") && Check_Save(items, "혈액 팩\n")) {
        printf("\n혈액 팩을 이용하면 급식실로 좀비를 유인할 수 있지 않을까?\n");
        printf("\n====================\n");
        printf("1. 혈액 팩을 배치한다.\n");
        printf("2. 그만둔다.\n");
        printf("====================\n");
        scanf("%d", &player_choice);
        switch (player_choice) {
        case 1:
            printf("\n식판 위에 정성스럽게 혈액 팩을 흩뿌렸다..\n");
            fprintf_Flush(history, "급식실 혈액 준비\n");
            printf("하지만 1층에 있는 좀비들이 여기까지 냄새를 맡고 올리가 없겠지.\n");
            printf("좀비를 유인하려면 추가적인 조치가 필요할 것 같다.\n");
            break;
        case 2:
            printf("\n보건실 때보다 후폭풍이 심할 것 같다.\n");
            printf("위험을 감수할 필요는 없지.\n");
        }
    }
    else {
        printf("\n급식 먹고 있을 때가 아니다.\n");
        printf("애초에 먹을 급식도 없다.\n");
    }
}

void Teacher_Office(FILE *history, FILE *items) {
    int player_choice;
    
    if (Check_Save(items, "핸드폰\n")) {
        printf("급식실 문은 오래 버티지 못한다.\n");
        printf("생사의 중대한 갈림길에서 교무실은 좋은 선택이 아닌 것 같다.\n");
        return;
    }

    else if (Check_Save(history, "자물쇠 제거\n") && Check_Save(history, "세콤 무력화\n")) {
        printf("\n세상에, 교무실 문이 열렸다.\n");
        printf("내 핸드폰이 책상 위에 놓여 있다.\n");
        printf("어떻게 할까?\n");
        printf("\n====================\n");
        printf("1. 명예롭게 임무를 완수한다.\n");
        printf("2. 나쁜 짓 하면 안돼.\n");
        printf("=====================\n");

        scanf("%d", &player_choice);

        switch (player_choice) {
        case 1:
            printf("\n인생의 동반자를 되찾았다.\n");
            fprintf_Flush(items, "핸드폰\n");
            printf("기쁜 마음으로 교무실을 나왔다.\n");
            break;
        case 2:
            printf("\n어림도 없지!\n");
            printf("\n인생의 동반자를 되찾았다.\n");
            fprintf_Flush(items, "핸드폰\n");
            printf("기쁜 마음으로 교무실을 나왔다.\n");
        }

    }

    else if (Check_Save(history, "교무실 열쇠 필요 확인\n")) {
        printf("\n교무실에 들어가기 위해서는 열쇠와 EMP 장치가 필요하다.\n");
        printf("어떻게 할까?\n");

        printf("\n====================\n");
        printf("1. 열쇠로 자물쇠를 제거한다.\n");
        printf("2. EMP 장치로 세콤을 마비시킨다.\n");
        printf("3. 그만둔다.\n");
        printf("=====================\n");
        
        scanf("%d", &player_choice);
        
        switch (player_choice) {
        case 1:
            if (Check_Save(history, "자물쇠 제거\n")) {
                printf("\n자물쇠는 이미 제거되었다.\n");
                return;
            }
            else if (Check_Save(items, "교무실 열쇠\n")) {
                printf("\n딱 들어맞는 게 기분이 좋다.\n");
                printf("자물쇠가 제거되었다.\n");
                fprintf_Flush(history, "자물쇠 제거\n");
            }
            else {
                printf("\n열쇠가 없으면 자물쇠를 열지 못한다는 사실을 알게 되었다.\n");
                printf("행정실에서 열쇠를 가져오자.\n");
            }
            break;
        case 2:
            if (Check_Save(history, "세콤 무력화\n")) {
                printf("\n세콤은 이미 무력화되었다.\n");
                return;
            }
            else if (Check_Save(items, "EMP 장치\n")) {
                printf("\n잠깐 스파크 튀는 소리가 나더니 세콤이 꺼졌다.\n");
                printf("이게 진짜 될 줄이야.\n");
                printf("세콤이 무력화되었다.\n");
                fprintf_Flush(history, "세콤 무력화\n");
            }
            else {
                printf("\nEMP 장치가 없다면 관리자 비밀번호를 찍어보는 수밖에 없다.\n");
                printf("에이, 그건 말도 안 되지.\n");
                printf("EMP 장치를 조립하는 방법을 찾자.\n");
            }
            break;
        case 3:
            printf("\n후일을 도모하자.\n");
            printf("언젠간 꼭 열어 주겠어.\n");
            break;
        }
    }
    else {
        printf("\n드디어 교무실에 도착했다!\n");
        printf("그러나 당연히 문이 잠겨 있다는 사실을 당연하지 못하게 알지 못했다.\n");
        printf("다른 교실은 다 열려 있었는데\n");
        printf("역시 교무실의 보안은 삼엄하다.\n\n");

        printf("교무실 문을 살펴보니 큼직한 자물쇠가 걸려 있다.\n");
        printf("행정실에 여분 열쇠가 있을 것 같다.\n\n");

        printf("문 옆의 불빛을 보아하니 세콤도 작동하고 있는 것 같다.\n");
        printf("세콤을 무력화시킬 emp장치가 필요하다.\n\n");

        printf("잠깐 창밖을 내다보니 갑자기 1층에 좀비들이 몰려들었다.\n");
        printf("행정실에 가기 위해서는 좀비를 옮겨야 한다.\n\n");

        fprintf_Flush(history, "교무실 열쇠 필요 확인\n");
        printf("뭐, 식은 죽 먹기지\n");
    }
}

int Floor_One(FILE *history, FILE *items) {
    int player_choice;
    if (Check_Save(history, "방송실 급식 방송\n")) {
        printf("\n걱정했지만 다행히 1층에 남아 있는 좀비는 없는 것 같다.\n");
        printf("시간이 없다.\n");
    }
    else if(Check_Save(history, "교무실 열쇠 필요 확인\n")) {
        printf("\n1층으로 내려가기엔 좀비가 너무 많다.\n");
        printf("행정실에 가기 위해서는 먼저 좀비를 다른 곳으로 옮겨야 한다.\n");
        return 2;
    }
    else {
        printf("\n1층으로 무사히 들어왔다.\n");
        printf("핸드폰은 5층 교무실에 있을 것이다.\n");
        printf("어떻게 할까?\n");
    }

    printf("\n====================\n");
    printf("1. 2층으로 올라간다.\n");
    printf("2. 보건실에 들른다.\n");
    printf("3. 행정실에 들른다.\n");
    printf("4. 밖으로 나간다.\n");
    printf("5. 건물 구조도를 확인한다.\n");
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
        Escape(history, items);
        return 1;
    case 5:
        Show_Map();
    }
  return 1;
}

int Floor_Two(FILE *history, FILE *items) {
    int player_choice;

    printf("\n2층이다.\n");
    printf("어떻게 할까?\n");

    printf("\n====================\n");
    printf("1. 3층으로 올라간다.\n");
    printf("2. 1층으로 내려간다.\n");
    printf("3. 방송실에 들른다.\n");
    printf("4. 건물 구조도를 확인한다.\n");
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

int Floor_Three(FILE *history, FILE *items) {
    int player_choice;

    printf("\n3층이다.\n");
    printf("어떻게 할까?\n");

    printf("\n====================\n");
    printf("1. 4층으로 올라간다.\n");
    printf("2. 2층으로 내려간다.\n");
    printf("3. 도서관에 들른다.\n");
    printf("4. 건물 구조도를 확인한다.\n");
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

int Floor_Four(FILE *history, FILE *items) {
    int player_choice;

    printf("\n4층이다.\n");
    printf("어떻게 할까?\n");

    printf("\n====================\n");
    printf("1. 5층으로 올라간다.\n");
    printf("2. 3층으로 내려간다.\n");
    printf("3. 컴퓨터실에 들른다.\n");
    printf("4. 건물 구조도를 확인한다.\n");
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

int Floor_Five(FILE *history, FILE *items) {
    int player_choice;

    if (Check_Save(items, "핸드폰\n")) {
        if (Check_Save(history, "급식실 문 잠금\n")) {
            printf("\n깜짝 놀랐다.\n");
            printf("금세 혈액 팩을 해치운 좀비들이 급식실 문을 두드리고 있다.\n");
            printf("급식실 문을 잠그지 않았다면 큰일날 뻔 했다.\n");
        }
        else {
            printf("\n교무실 밖으로 나오는 순간 급식실에서 뛰쳐나온 좀비들에게 둘러싸였다.\n");
            printf("아무래도 급식이 부족했나 보다\n");
            printf("이런, 급식실 문이라도 잠궜ㅇㅡ며ㄴ\n");
            fprintf_Flush(history, "게임 오버\n");
            return 5;
        }
    }

    else if (Check_Save(history, "방송실 급식 방송\n") && !Check_Save(history, "급식실 혈액 준비\n")) {
        printf("\n급식실에 먹을 게 없자 좀비들이 엄청 화났다.\n");
        printf("아무래도 내가 급식으로 보이는 것 같다.\n");
        printf("도망ㅊ쳐야한ㄷ\n");
        fprintf_Flush(history, "게임 오버\n");
        return 5;
    }

    printf("\n5층이다.\n");
    printf("어떻게 할까?\n");

    printf("\n====================\n");
    printf("1. 4층으로 내려간다.\n");
    printf("2. 교무실에 들른다.\n");
    printf("3. 급식실에 들른다.\n");
    printf("4. 건물 구조도를 확인한다.\n");
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

void Player_Action(FILE *history, FILE *items) {
    int floor = 1;
    while(1) {
        if (Check_Save(history, "게임 오버\n")) {
            printf("\nGame Over\n");
            break;
        }
        else if (Check_Save(history, "게임 클리어\n")) {
            printf("\nGame Clear\n");
            break;
        }
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