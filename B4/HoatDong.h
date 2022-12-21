#pragma once
#ifndef HoatDong_h
#define HoatDong_h

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

const int MAX = 10;
char fileHD[] = "HoatDong.txt";
char fileMH[] = "LapLich.txt";
int n;

typedef struct HoatDong {
	char ten[10];
	int end, start;
}HD;

typedef struct LapLich {
	char* ten;
	int end, start;
}LL;

//Khai bao nguyen ham
int main();
void process();
void menu();
void readFile(char fileName[], HD hd[], int& n);
void displayHoatDong(HD hd[], int n);
void lucChonHoatDong(HD hd[], LL ll[], int n);
void displayLapLich(LL ll[], int n);
void displayMonHoc(HD hd[], int n);
void lucChonMonHoc(HD hd[], LL ll[], int n);
void displayLich(LL ll[], int n);

#endif // !Bai01_HoatDong