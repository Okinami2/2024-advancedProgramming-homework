#pragma once

int menu();
void halt(char in, const char* out);
void initArr(int arr[][9], int row, int col);
void showArr(int arr[9][9], int row, int col, int showDifferent);
int randomInt(int begin, int end);
int removable(int arr[][9], int x, int y, int row, int col);
void scanRowAndCol(int* row, int* col);
void drop(int arr[][9], int row, int col);
void fill(int arr[][9], int row, int col);
int isFinish(int arr[][9], int row, int col);
void results(int arr[][9], int rs[][4], int row, int col);
void showRs(int arr[][9], int row, int col, int rs[][4]);
void theEnd();
void fun1();
void fun2();
void fun3();