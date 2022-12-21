#pragma once
#ifndef DuongDi_h
#define DuongDi_h

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"


const int MAX = 10;
char fileDT[] = "DoThi.txt";
int n, soCanh = 0;
int* chuaXet = new int;

typedef struct DOTHI {
	char ten[MAX];
	int x, y;
}dt;

typedef struct CANH {
	char* u,* v;
	int doDai;
}canh;

struct T {
	char* u, * v;
};


int main();
void process();
void menu();
void docFile(char fileName[], int& n, dt x[]);
void showDoThi(dt x[], int n);
void searchDFS(dt x[], canh c[], T t[], int n, int u, int& soCanh);
void ghiFile(char fileName[], int n, canh c[]);
void tinhDoDai(dt x[], canh c[], int n);
void khoiTaoHamChuaXet(int chuaXet[]);
void xuatCanhChuTrinh(T t[], int n);

#endif