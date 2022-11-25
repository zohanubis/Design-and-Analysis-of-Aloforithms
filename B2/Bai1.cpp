#include "stdio.h"
#include "conio.h"
#define MAXSIZE 50
void nhapMaTran(int a[MAXSIZE][MAXSIZE], int &n);
void xuatMaTran(int a[MAXSIZE][MAXSIZE], int n);
void nhan2MaTran(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int c[MAXSIZE][MAXSIZE], int n);
void main(){
	int a[MAXSIZE][MAXSIZE],b[MAXSIZE][MAXSIZE],c[MAXSIZE][MAXSIZE], n;
	printf("\tNhap ma tran a: ");
	printf("\nNhap cap cua ma tran: "); scanf("%d", &n);
	nhapMaTran(a, n);
	printf("Ma tran a:\n");
	xuatMaTran(a, n);
	printf("\tNhap ma tran b:\n");
	nhapMaTran(b, n);
	printf("Ma tran b:\n");
	xuatMaTran(b, n);
	nhan2MaTran(a, b, c, n);
	printf("Ma tran c:\n");
	xuatMaTran(c, n);
	getch();
}
void nhapMaTran(int a[MAXSIZE][MAXSIZE], int &n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("arr[%d][%d] = ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
}
void xuatMaTran(int a[MAXSIZE][MAXSIZE], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void congMaTran(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int kq[MAXSIZE][MAXSIZE], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			kq[i][j] = a[i][j] + b[i][j];
		}
	}
}
void truMaTran(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int kq[MAXSIZE][MAXSIZE], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			kq[i][j] = a[i][j] - b[i][j];
		}
	}
}
void nhan2MaTran(int a[MAXSIZE][MAXSIZE], int b[MAXSIZE][MAXSIZE], int c[MAXSIZE][MAXSIZE], int n){
	if (n == 1){
		c[0][0] = a[0][0] * b[0][0];
		return;
	}
	else{
		int a11[MAXSIZE][MAXSIZE], a12[MAXSIZE][MAXSIZE], a21[MAXSIZE][MAXSIZE], a22[MAXSIZE][MAXSIZE];
		int b11[MAXSIZE][MAXSIZE], b12[MAXSIZE][MAXSIZE], b21[MAXSIZE][MAXSIZE], b22[MAXSIZE][MAXSIZE];
		int c11[MAXSIZE][MAXSIZE], c12[MAXSIZE][MAXSIZE], c21[MAXSIZE][MAXSIZE], c22[MAXSIZE][MAXSIZE];
		int P1[MAXSIZE][MAXSIZE], P2[MAXSIZE][MAXSIZE], P3[MAXSIZE][MAXSIZE], P4[MAXSIZE][MAXSIZE],P5[MAXSIZE][MAXSIZE], P6[MAXSIZE][MAXSIZE], P7[MAXSIZE][MAXSIZE];
		int akq[MAXSIZE][MAXSIZE], bkq[MAXSIZE][MAXSIZE];
		int sub_n = n / 2;
		for (int i = 0; i < sub_n; i++){
			for (int j = 0; j < sub_n; j++){
				a11[i][j] = a[i][j];
				a12[i][j] = a[i][j + sub_n];
				a21[i][j] = a[i + sub_n][j];
				a22[i][j] = a[i + sub_n][j + sub_n];
				b11[i][j] = b[i][j];
				b12[i][j] = b[i][j + sub_n];
				b21[i][j] = b[i + sub_n][j];
				b22[i][j] = b[i + sub_n][j + sub_n];
			}
		}
		congMaTran(a11, a22, akq, sub_n);
		congMaTran(b11, b22, bkq, sub_n);
		nhan2MaTran(akq, bkq, P1, sub_n);

		congMaTran(a21, a22, akq, sub_n);
		nhan2MaTran(akq, b11, P2, sub_n);

		truMaTran(b12, b22, bkq, sub_n);
		nhan2MaTran(a11, bkq, P3, sub_n);

		truMaTran(b21, b11, bkq, sub_n);
		nhan2MaTran(a22, bkq, P4, sub_n);

		congMaTran(a11, a12, akq, sub_n);
		nhan2MaTran(akq, b22, P5, sub_n);

		truMaTran(a21, a11, akq, sub_n);
		congMaTran(b11, b12, bkq, sub_n);
		nhan2MaTran(akq, bkq, P6, sub_n);

		truMaTran(a12, a22, akq, sub_n);
		congMaTran(b21, b22, bkq, sub_n);
		nhan2MaTran(akq, bkq, P7, sub_n);

		congMaTran(P3, P5, c12, sub_n);
		congMaTran(P2, P4, c21, sub_n);

		congMaTran(P1, P4, akq, sub_n);
		congMaTran(akq, P7, bkq, sub_n);
		truMaTran(bkq, P5, c11, sub_n);

		congMaTran(P1, P3, akq, sub_n);
		congMaTran(akq, P6, bkq, sub_n);
		truMaTran(bkq, P2, c22, sub_n);
		for (int i = 0; i < sub_n; i++){
			for (int j = 0; j < sub_n; j++){
				c[i][j] = c11[i][j];
				c[i][j + sub_n] = c12[i][j];
				c[i + sub_n][j] = c21[i][j];
				c[i + sub_n][j + sub_n] = c22[i][j];
			}
		}
	}
}