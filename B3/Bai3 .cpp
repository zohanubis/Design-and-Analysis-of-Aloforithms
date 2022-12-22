#include "stdio.h"
#include "conio.h"
#define MAX 20
int W, n;
struct DoVat{
	int ten;
	int trongLuong;
	int giaTri;
	float donGia;
	int soLuong;
	int soLuongLay;
	int soLuongConLai;
};
void docFile(DoVat ds_dv[], char *fileName);
void xuat1DoVat(DoVat dv);
void xuatDanhSach(DoVat ds_dv[]);
void sapXep(DoVat ds_dv[]);
void chonDoVat(DoVat ds_dv[]);
void main(){
	char fileName[MAX] = "Bai3.txt";
	DoVat ds_dv[MAX];
	docFile(ds_dv, fileName);
	printf("\nDanh sach do vat:\n");
	xuatDanhSach(ds_dv);
	sapXep(ds_dv);
	printf("\nDanh sach do vat sau khi sap xep:\n");
	xuatDanhSach(ds_dv);
	chonDoVat(ds_dv);
	getch();
}
void docFile(DoVat ds_dv[], char *fileName){
	FILE *f = fopen(fileName, "rt");
	if (f == NULL){
		printf("\n\tLoi doc file!");
		return;
	}
	fscanf(f, "%d", &W);
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++){
		fscanf(f, "%d", &ds_dv[i].ten);
		fscanf(f, "%d", &ds_dv[i].trongLuong);
		fscanf(f, "%d", &ds_dv[i].giaTri);
		fscanf(f, "%d", &ds_dv[i].soLuong);
		ds_dv[i].donGia = (float)ds_dv[i].giaTri / ds_dv[i].trongLuong;
	}
	fclose(f);
}
void xuat1DoVat(DoVat dv){
	printf("\t%d", dv.ten);
	printf("\t%d", dv.trongLuong);
	printf("\t\t%d", dv.giaTri);
	printf("\t\t%d", dv.soLuong);
	printf("\t\t%.2f", dv.donGia);
}
void xuatDanhSach(DoVat ds_dv[]){
	printf("W = %d", W);
	printf("\n\tTenDV\tTrongLuong\tGiaTri\t\tSoLuong\t\tDonGia\n");
	for (int i = 0; i < n; i++){
		xuat1DoVat(ds_dv[i]);
		printf("\n");
	}
}
void sapXep(DoVat ds_dv[]){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (ds_dv[i].donGia < ds_dv[j].donGia){
				DoVat temp = ds_dv[i];
				ds_dv[i] = ds_dv[j];
				ds_dv[j] = temp;
			}
		}
	}
}
void chonDoVat(DoVat ds_dv[]){
	printf("\nDanh sach so luong do vat lay:\n");
	printf("W = %d", W);
	printf("\n\tTenDV\tTrongLuong\tGiaTri\t\tSoLuong\t\tDonGia\t\tSoLuongLay\tSoLuongConLai\tWconlai\n");
	int sum = 0;
	for (int i = 0; i < n; i++){
		xuat1DoVat(ds_dv[i]);
		ds_dv[i].soLuongLay = ds_dv[i].soLuong;
		while ((ds_dv[i].soLuongLay * ds_dv[i].trongLuong) > W){
			ds_dv[i].soLuongLay--;
		}
		ds_dv[i].soLuongConLai = ds_dv[i].soLuong - ds_dv[i].soLuongLay;
		sum += ds_dv[i].soLuongLay * ds_dv[i].giaTri;
		W = W - ds_dv[i].soLuongLay * ds_dv[i].trongLuong;
		printf("\t\t%d", ds_dv[i].soLuongLay);
		printf("\t\t%d", ds_dv[i].soLuongConLai);
		printf("\t\t%d", W);
		printf("\n");
		if (W <= 0){
			break;
		}
	}
	printf("\nTong gia tri cua balo la: %d", sum);
}