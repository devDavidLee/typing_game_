//�̴ٹ� �׽�Ʈ ����3
#include "main.h"
#define SIZE 6

int game_run()
{

	int a; //���� ���� ���� ����
	int check; //���ڿ� ���� �� ��� ����
	int score = 0; //���� ����
	int heart = 5; //���� ��� ����
	clock_t start, end;
	double result; //�ð����� �����ϱ� ���� ����
	int wordLength;

	char ch;
	int s_time, j = 0;

	//system("mode con cols=120 lines=45"); //�ܼ�â ũ��
	system("title �Ǵ��̸� ��ƶ�!"); //�ܼ�â ����
	system("cls"); // �ܼ�â �ʱ�ȭ
	//srand(time(NULL));
	gotoxy(110, 0);
	printf("������\n"); //ü�¹� �׽�Ʈ

	srand(time(0));
	s_time = time(0);
	a = get_random_word(&wordLength);
	gotoxy(COLS / 2 - 5, 3);
	printf("%s\n", wordBase[a]);

	while (1)
	{
		char* inputArray = (int*)malloc(sizeof(char) * wordLength);
		//char input[wordLength]; //�Է¹��� �ܾ� �迭
		
		//a = get_random_word(); //�迭���� �ܾ� �����ϱ� ���� ���� �ε��� ��
		//gotoxy(COLS / 2 - 5, 3);
		//printf("%s\n", wordBase[a]); //�迭���� ���� ����� �ܾ� ���

		if (time(0) == s_time + 5)
		{
			system("cls");
			heart = heart - 1;
			life_bar(heart);

			gotoxy(5, 5);
			printf("%d", score);
			a = get_random_word(&wordLength);
			gotoxy(COLS / 2 - 5, 3);
			printf("%s\n", wordBase[a]);
			s_time = time(0);
			j = 0;
			free(inputArray);
		}
		if (_kbhit())
		{
			//gotoxy(COLS / 2 - 5, 5);
			ch = _getch();
			if (ch == 27)
			{
				break;
			}
			//printf("%c", ch);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);
				inputArray[j] = ch;
				j++;
			}
		}
		if (j >= wordLength)
		{
			//printf("%s\n", input);
			inputArray[wordLength] = 0;
			for (int i = 0; wordBase[a][i] != 0; i++)  //�迭�� �������� �پ��ִ� \n ����
			{
				if (wordBase[a][i] == '\n')
				{
					wordBase[a][i] = 0;
					break;
				}
			}
			check = strcmp(inputArray, wordBase[a]); //���ڿ� ��
			//printf("%d", check);
			
			system("cls");
			switch (check)  // ���ڿ� �񱳰��� ���� ���
			{
			case 0:
				gotoxy(COLS / 2 - 5, 10);
				printf("�¾ҽ��ϴ�!\n");
				score = score + 10;
				break;
			case 1:
				gotoxy(COLS / 2 - 5, 10);
				printf("Ʋ�Ƚ��ϴ�!\n");
				heart = heart - 1;
				break;
			case -1:
				gotoxy(COLS / 2 - 5, 10);
				printf("Ʋ�Ƚ��ϴ�!\n");
				heart = heart - 1;
				break;
			}
			life_bar(heart);


			gotoxy(5, 5);
			printf("%d", score);
			a = get_random_word(&wordLength);
			gotoxy(COLS / 2 - 5, 3);
			printf("%s\n", wordBase[a]);
			s_time = time(0);
			j = 0;
			free(inputArray);
		}

		if (score >= 50) // ������ ���� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("1�ܰ踦 Ŭ���� �ϼ̽��ϴ�!");
			Sleep(2000); //2�� ������
			return 1;
			break;
		}
		else if (heart == 0) //����� 0�� �Ǿ������� ����
		{
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("�Ǵ��̰� Ż���ߴ�!�Ф�\n");
			Sleep(1000);
			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("����� ����: %d", score);
			Sleep(1000); //1�� ������

			system("cls"); // �ܼ�â �ʱ�ȭ
			gotoxy(COLS / 2 - 10, LINES / 2);
			printf("���ӿ���");
			Sleep(1000); //1�� ������
			return 0;
			break;
		}
	}
}