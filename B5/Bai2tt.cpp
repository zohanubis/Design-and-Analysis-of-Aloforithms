#include "stdio.h"
#include "conio.h"
#define MAX 10
struct DoVat{
	int ten;
	int trongLuong;
	int giaTri;
	int soLuong;
	int phuongAn;
};
DoVat dsDV[MAX];
int n_DoVat;
int W;
void docFile(DoVat dsDV[], char *path);
void xuat1DoVat(DoVat dv);
void xuatBaLo(DoVat dsDV[]);
void taoBang(DoVat dsDV[], int F[][MAX], int X[][MAX]);
void xuatBang(int Bang[][MAX]);
void traBang(DoVat dsDV[], int F[][MAX], int X[][MAX]);
void main(){
	docFile(dsDV, "input2.txt");
	xuatBaLo(dsDV);
	int F[MAX][MAX], X[MAX][MAX];
	taoBang(dsDV, F, X);
	printf("\nBang F: ");
	xuatBang(F);
	printf("\nBang X: ");
	xuatBang(X);
	traBang(dsDV, F, X);
	getch();
}
void docFile(DoVat dsDV[], char *path){
	FILE *f = fopen(path, "r");
	if (f == NULL){
		printf("\nKhong mo duoc file!");
	}
	fscanf(f, "%d", &W);
	fscanf(f, "%d", &n_DoVat);
	for (int i = 1; i <= n_DoVat; i++){
		fscanf(f, "%d%d%d%d", &dsDV[i].ten, &dsDV[i].trongLuong, &dsDV[i].giaTri, &dsDV[i].soLuong);
	}
	fclose(f);
}
void xuat1DoVat(DoVat dv){
	printf("\t%d\t%d\t\t%d\t%d", dv.ten, dv.trongLuong, dv.giaTri, dv.soLuong);
}
void xuatBaLo(DoVat dsDV[]){
	printf("\tTen\tTrongLuong\tGiaTri\tSoLuong\n");
	for (int i = 1; i <= n_DoVat; i++){
		xuat1DoVat(dsDV[i]);
		printf("\n");
	}
}
void taoBang(DoVat dsDV[], int F[][MAX], int X[][MAX]){
	int xk, yk, k;
	int FMax, XMax, v;
	for (v = 0; v <= W; v++){
		X[1][v] = v / dsDV[1].trongLuong;
		F[1][v] = X[1][v] * dsDV[1].giaTri;
	}
	for (k = 2; k <= n_DoVat; k++){
		X[k][0] = 0;
		F[k][0] = 0;
		for (v = 1; v <= W; v++){
			FMax = F[k - 1][v];
			XMax = 0;
			yk = v / dsDV[k].trongLuong;
			if (yk > dsDV[k].soLuong){
				yk = dsDV[k].soLuong;
			}
			for (xk = 1; xk <= yk; xk++){
				if ((F[k - 1][v - xk * dsDV[k].trongLuong] + xk*dsDV[k].giaTri) > FMax){
					FMax = F[k - 1][v - xk*dsDV[k].trongLuong] + xk * dsDV[k].giaTri;
					XMax = xk;
				}
			}
			F[k][v] = FMax;
			X[k][v] = XMax;
		}
	}
}
void xuatBang(int Bang[][MAX]){
	for (int i = 1; i <= n_DoVat; i++){
		printf("\n");
		for (int j = 0; j <= W; j++){
			printf("%d ", Bang[i][j]);
		}
	}
}
void traBang(DoVat dsDV[], int F[][MAX], int X[][MAX]){
	int k, v;
	v = W;
	for (k = n_DoVat; k >= 1; k--){
		if (X[k][v] > 0){
			dsDV[k].phuongAn = X[k][v];
			v = v - X[k][v] * dsDV[k].trongLuong;
		}
	}
	int sum = 0;
	printf("\n\tTen\tTrongLuong\tGiaTri\tSoLuong\tPhuongAn\n");
	for (int i = 1; i <= n_DoVat; i++){
		if (dsDV[i].phuongAn != 0){
			sum += dsDV[i].giaTri * dsDV[i].phuongAn;
		}
		xuat1DoVat(dsDV[i]);
		printf("\t%d\n", dsDV[i].phuongAn);
	}
	printf("\n\tTong gia tri: %d", sum);
}