// main 헤더파일 입니다

#define _CRT_SECURE_NO_WARNINGS

//헤더파일 포함
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <conio.h>


//함수 선언(파일별 구분)
//main.c
int main();

//story.c
void story();

//internal_functions.c
void gotoxy(int x, int y);
void ColorSet(int color_number);
void texts(char text[]);
void read_file();
int get_random_word(int* wordLength);
void screen_s(int* story_y);
int input_menu();
int get_levelInput();

//screen_print.c
void first();
void screen();
void print_letter(char* s);
void show_level_select();
void emoticon();
void print_help();
void print_star();
void English();

//game_run.c
int game_run();
double get_input_check(int *score, int *check);

//void check_answer(int check, int *score, int *heart);
//life_bar.c
void life_bar(int heart); 
//event_word.c

//combo.c

//choice_level.c

//ask_quit.c



//기호상수 선언
#define COLS 120
#define LINES 45
#define COLS_BOX 115
#define LINES_BOX 12
#define WORDNUM 1000 //단어개수
#define WORDLEN 15 //단어글자수

//전역 변수(배열) 선언
char wordBase[WORDNUM][WORDLEN]; //2차원 배열을 생성 
int arrayNum; //랜덤 뽑은 배열의 행
int totalScore; //총 점수


