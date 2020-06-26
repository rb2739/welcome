#include<stdio.h>
#include<stdlib.h>
#include<termios.h>//mac 전용. 윈도우는 conio.h 쓰세요
#include<string.h>

int getch(void) //mac 전용 
{ int ch; 
    struct termios old; 
    struct termios new; 
    tcgetattr(0, &old); 
    new = old; 
    new.c_lflag &= ~(ICANON|ECHO); 
    new.c_cc[VMIN] = 1; 
    new.c_cc[VTIME] = 0; 
    tcsetattr(0, TCSAFLUSH, &new); 
    ch = getchar(); 
    tcsetattr(0, TCSAFLUSH, &old); 
    return ch; 
}

int PrintMenu(void)//시작화면
{
    int nInput = 0;

    //system("clear");//원도우 "cls"
    //메뉴
    printf("\n \t\t\t\t\t\t\t\t\t\t 성적 관리 시스템");
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(" [1] 성적입력 \n\n\n [2] 성적 평균\n\n\n [3] 지원 가능 회사\n\n\n [4] 프로그램 종료\n\n : ");
    //입력 숫자
    scanf("%d", &nInput);
    return nInput;


}

int GetAge(void)//메뉴 1-1 학년선택
{
    int nAge=0;
    printf("[1] 1학년 [2] 2학년 [3] 3학년 [4] 4학년 \n :");
    scanf("%d", &nAge);

    return nAge;
}

int GetSemester(void)//학기선택
{
    int nSemester=0;
    printf("[1] 1학기 [2] 2학기\n :");
    scanf("%d", &nSemester);

    return nSemester;

}

void GetSubject(char* *szName, int *nGrade, int nSemester)//과목이름 점수저장
{
    int  i;
    double tmp=0;


    FILE *fp = NULL;
    for(i=0; i<6; i++){
        fflush(stdin);

        printf("과목 명을 입력하세요.(6과목) : \n  ");
        char buffer[30];
        scanf("%s", buffer);
        int l = strlen(buffer);
        char* newstrptr = (char*)malloc(sizeof(char) * (l + 1));
        strcpy(newstrptr, buffer);
        szName[i] = newstrptr;
        fflush(stdin);

        printf("점수를 입력하세요.(정수) : \n  ");
        scanf("%d", &nGrade[i]);
    }
    printf("0000");
    for(i=0; i<6; i++){
        tmp=tmp+nGrade[i];
    }
    tmp=tmp/6;
    printf("1111");

    if(nSemester == 11){
        fp = fopen("1학년 1학기.txt","w");
        printf("2222");
        for(i=0; i<6; i++)
            fprintf(fp, "%s\n%d\n%lf", szName[i], nGrade[i], tmp);
        printf("3333");
    }
    else if(nSemester == 12){
        fp = fopen("1학년 2학기.tx","w");
        for(i=0; i<6; i++)
            fprintf(fp, "%s\n%d\n%lf", szName[i], nGrade[i], tmp);
    }
}






int main(void)
{
    int nMenu = 0, nAge=0, nSemester=0;
    int nGrade[6];
    char *szName[6];

    while ((nMenu = PrintMenu()) != 4)
    {
        switch (nMenu)
        {
            case 1:{
                       nAge=GetAge();

                       switch (nAge){
                           case 1:
                               nSemester=GetSemester();
                               GetSubject(szName, nGrade, nAge*10+nSemester);
                               break;

                           case 2:
                               nSemester=GetSemester();
                               break;

                           case 3:
                               nSemester=GetSemester();
                               break;

                           case 4:
                               nSemester=GetSemester();
                               break;

                           default:
                               puts(" 1~4 사이의 숫자를 입력하세요");
                               continue;

                       }
                   }


                   break;

            case 2:
                   puts("성적평점");
                   break;

            case 3:
                   puts("학점별 기업목록");
                   break;

            default: //???
                   puts("\n\n\n   1~4 사이의 수를 입력하세요 ");


        }
        getch();
    }
    return 0;
}


