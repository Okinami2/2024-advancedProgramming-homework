#pragma once

int menu();
void halt(char in, const char* out);
void initArr(int arr[][9], int row, int col);
void showArr(int arr[9][9], int row, int col);
int randomInt(int begin, int end);
void scanRowAndCol(int* row, int* col);
void select(int arr[][9], int row, int col);
void fun1();