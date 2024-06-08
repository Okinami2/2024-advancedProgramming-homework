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
void showGraph(int arr[][9], int row, int col, int showBorder);
void showBall(int arr[][9], int row, int col, int showBorder, int showDifferent);
void dropBall(int arr[][9], int row, int col, int hasBorder);
void fillBall(int arr[][9], int row, int col, int hasBorder);
void hint(int arr[][9], int row, int col, int hasBorder);
int positionValid(int arr[][9], int rs[][4], int mX, int mY, int *v1, int *v2);
void theEnd();
void fun1();
void fun2();
void fun3();
void fun4();
void fun5();
void fun6();
void fun7();
void fun8();