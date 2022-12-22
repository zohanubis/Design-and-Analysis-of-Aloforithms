#include "stdio.h"
#include "conio.h"
#define MAX 50
int n;
struct HoatDong{
	char ten[50];
	int thoiGianBatDau;
	int thoiGianKetThuc;
	int phuongAn = 0;
};
void docFile(HoatDong dshd[]);
void xuat1HD(HoatDong hd);
void xuatDSHD(HoatDong dshd[]);
void sapXep(HoatDong dshd[]);
bool kiemTraHD(HoatDong dshd[], int index);
void luaChonHoatDong(HoatDong dshd[]);
void main(){
	HoatDong dshd[MAX];
	docFile(dshd);
	printf("Danh sach hoat dong:\n");
	xuatDSHD(dshd);
	sapXep(dshd);
	printf("\nDanh sach hoat dong sau khi sap xep theo thoi gian ket thuc:\n");
	xuatDSHD(dshd);
	printf("\nDanh sach hoat dong duoc lua chon:\n");
	printf("\tTen\tTGBD\tTGKT");
	luaChonHoatDong(dshd);
	getch();
}
void docFile(HoatDong dshd[]){
	FILE *f = fopen("Bai1.txt", "r");
	if (f == NULL){
		printf("\nLoi doc file!");
		return;
	}
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++){
		fscanf(f, "%s%d%d", &dshd[i].ten, &dshd[i].thoiGianBatDau, &dshd[i].thoiGianKetThuc);
	}
	fclose(f);
}
void xuat1HD(HoatDong hd){
	printf("\n\t%s\t%d\t%d", hd.ten, hd.thoiGianBatDau, hd.thoiGianKetThuc);
}
void xuatDSHD(HoatDong dshd[]){
	printf("\tTen\tTGBD\tTGKT");
	for (int i = 0; i < n; i++){
		xuat1HD(dshd[i]);
	}
}
void swap(HoatDong &hd1, HoatDong &hd2){
	HoatDong temp = hd1;
	hd1 = hd2;
	hd2 = temp;
}
void sapXep(HoatDong dshd[]){
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n; j++){
			if (dshd[i].thoiGianKetThuc > dshd[j].thoiGianKetThuc){
				swap(dshd[i], dshd[j]);
			}
		}
	}
}
bool kiemTraHD(HoatDong dshd[], int index){
	if (dshd[index].phuongAn == 0){
		dshd[index].phuongAn = 1;
		for (int i = index + 1; i < n; i++){
			if (dshd[index].thoiGianKetThuc > dshd[i].thoiGianBatDau){
				dshd[i].phuongAn = -1;
			}
		}
		return 1;
	}
	return 0;
}
void luaChonHoatDong(HoatDong dshd[]){
	for (int i = 0; i < n; i++){
		if (kiemTraHD(dshd, i)){
			xuat1HD(dshd[i]);
		}
	}
}