#include<stdio.h>
#include<stdlib.h>
#include<termios.h>//mac 전용. 윈도우는 conio.h 쓰세요
//#include<conio.h>
#include<string.h>//strcmp 문자열

int getch(void) //mac 전용
{
int ch;
struct termios old;
struct termios new;
tcgetattr(0, &old);
new = old;
new.c_lflag &= ~(ICANON | ECHO);
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

	system("cls");//원도우 "cls"
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
	int nAge = 0;
	printf("[1] 1학년 [2] 2학년 [3] 3학년 [4] 4학년 \n :");
	scanf("%d", &nAge);

	return nAge;
}

int GetSemester(void)//학기선택
{
	int nSemester = 0;
	printf("[1] 1학기 [2] 2학기\n :");
	scanf("%d", &nSemester);

	return nSemester;

}

int GetSubject(void)
{
	int Sugang = 0, i = 0, j = 0, nsubject=0 ;
	double hak[100][1] = { 0 };
	double hak_sum1 = 0.00;
	double hak_sum2 = 0.00;
	double Grade[100][1] = { 0 };
	double Class[100][1] = { 0 };
	
	
	printf("수강신청 과목수(정수입력) :[ ]\b\b");
	scanf("%d", &Sugang);

	for (i = 0; i < Sugang; i++)
	{
		for (j = 0; j < 1; j++)
		{
			printf("[%d]번째 과목입니다.\n\n", i + 1);

			printf("과목명을 입력하세요(Ex.C언어 / C++ /Java) : ");
			fflush(stdin);
			scanf("%s", Class[i][j + 1]);

			printf("학점을 입력하세요(3학점/2학점/1학점 정수만입력) : ");
			fflush(stdin);
			scanf("%lf", &hak[i][j]);

			hak_sum1 += (hak[i][j]);

			printf("성적을 입력하세요(A+ ~ F): ");
			fflush(stdin);
			scanf("%s", Grade[i][j + 2]);


			/*if (strcmp(Grade[i][j + 2], "f") == 0)
			{
				hak_sum2 += 0;
			}
			else if (strcmp(Grade[i][j + 2], "F") == 0)
			{
				hak_sum2 += 0;
			}
			else
			{
				hak_sum2 += (hak[i][j]);
			}*/

			printf("\n\n");


		}
	}
	return nsubject;
	
}





int main(void)
{
	int nMenu = 0, nAge = 0, nSemester = 0, nsubject=0;

	while ((nMenu = PrintMenu()) != 4)
	{
		switch (nMenu)
		{
		case 1: {
			nAge = GetAge();

			switch (nAge) {
			case 1://1학년
				nSemester = GetSemester();
				nsubject = GetSubject();
				break;

			case 2://2힉년
				nSemester = GetSemester();
				nsubject = GetSubject();
				break;

			case 3:
				nSemester = GetSemester();
				nsubject = GetSubject();

				break;

			case 4:
				nSemester = GetSemester();
				nsubject = GetSubject();
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
