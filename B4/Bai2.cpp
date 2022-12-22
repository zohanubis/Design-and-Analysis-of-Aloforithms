#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#define MAX 50
struct ThanhPho{
	char ten;
	int hoanhDo;
	int tungDo;
};
struct Canh{
	char dinhDau;
	char dinhCuoi;
	float doDai;
};
int n_TP,n_Canh, n_ChuTrinh;
char thanhPhoXuatPhat;
void docFile(ThanhPho dsTP[]);
void tinhDoDaiCanh(ThanhPho dsTP[],Canh dsCanh[]);
void xuatDSCanh(Canh dsCanh[], int n);
void sapXep(Canh dsCanh[]);
bool kiemTraBac3(Canh dsChuTrinh[], Canh pCanh);
bool kiemTraChuTrinh(Canh dsChuTrinh[], Canh pCanh);
void luaChonCanh(Canh dsCanh[]);
void ghiFile(Canh dsChuTrinh[]);
void main(){
	ThanhPho dsTP[MAX];
	Canh dsCanh[MAX];
	docFile(dsTP);
	tinhDoDaiCanh(dsTP,dsCanh);
	printf("\nDanh sach canh:\n");
	xuatDSCanh(dsCanh,n_Canh);
	sapXep(dsCanh);
	printf("\nDanh sach canh sau khi sap xep tang theo do dai:\n");
	xuatDSCanh(dsCanh,n_Canh);
	luaChonCanh(dsCanh);
	getch();
}
void docFile(ThanhPho dsTP[]){
	FILE *f = fopen("Bai2.txt", "r");
	if (f == NULL){
		printf("\nLoi doc file!");
		return;
	}
	fscanf(f, "%d\n", &n_TP);
	for (int i = 0; i < n_TP; i++){
		fscanf(f, "%c\n", &dsTP[i].ten);
		fscanf(f, "%d\n", &dsTP[i].hoanhDo);
		fscanf(f, "%d\n", &dsTP[i].tungDo);
	}
	fscanf(f, "%c", &thanhPhoXuatPhat);
	fclose(f);
}
void tinhDoDaiCanh(ThanhPho dsTP[],Canh dsCanh[]){
	int count = 0;
	for (int i = 0; i < n_TP-1; i++){
		for (int j = i + 1; j < n_TP; j++){
			dsCanh[count].dinhDau = dsTP[i].ten;
			dsCanh[count].dinhCuoi = dsTP[j].ten;
			dsCanh[count].doDai = sqrt(pow((float)(dsTP[i].hoanhDo - dsTP[j].hoanhDo), 2) + pow(float(dsTP[i].tungDo - dsTP[j].tungDo), 2));
			count++;
		}
	}
	n_Canh = count;
}
void xuatDSCanh(Canh dsCanh[], int n){
	printf("\tDinhDau\t\tDinhCuoi\tDoDai");
	for (int i = 0; i < n; i++){
		printf("\n\t%c\t\t%c\t\t%.2f", dsCanh[i].dinhDau, dsCanh[i].dinhCuoi, dsCanh[i].doDai);
	}
}
void swap(Canh &c1, Canh &c2){
	Canh temp = c1;
	c1 = c2;
	c2 = temp;
}
void sapXep(Canh dsCanh[]){
	for (int i = 0; i < n_Canh - 1; i++){
		for (int j = i + 1; j < n_Canh; j++){
			if (dsCanh[i].doDai > dsCanh[j].doDai){
				swap(dsCanh[i], dsCanh[j]);
			}
		}
	}
}
bool kiemTraBac3(Canh dsChuTrinh[], Canh pCanh){
	int count1 = 1;
	int count2 = 1;
	for (int i = 0; i < n_ChuTrinh; i++){
		if (pCanh.dinhDau == dsChuTrinh[i].dinhDau || pCanh.dinhDau == dsChuTrinh[i].dinhCuoi){
			count1++;
		}
		if (pCanh.dinhCuoi == dsChuTrinh[i].dinhDau || pCanh.dinhCuoi == dsChuTrinh[i].dinhCuoi) {
			count2++;
		}
		if (count1 == 3){
			return 1;
		}
		if (count2 == 3) {
			return 1;
		}
	}
	return 0;
}
bool kiemTraChuTrinh(Canh dsChuTrinh[], Canh pCanh){
	int count1 = 1;
	int count2 = 1;
	int count3 = 1;
	char dinhTrungGian1 = 'NULL';
	char dinhTrungGian2 = NULL;
	for (int i = 0; i < n_ChuTrinh; i++){
		if (pCanh.dinhDau == dsChuTrinh[i].dinhDau){
			count1++;
			dinhTrungGian1 = dsChuTrinh[i].dinhCuoi;
		}
		if (pCanh.dinhDau == dsChuTrinh[i].dinhCuoi){
			count1++;
			dinhTrungGian1 = dsChuTrinh[i].dinhDau;
		}
		if (pCanh.dinhCuoi == dsChuTrinh[i].dinhDau){
			count2++;
			dinhTrungGian2 = dsChuTrinh[i].dinhCuoi;
		}
		if (pCanh.dinhCuoi == dsChuTrinh[i].dinhCuoi){
			count2++;
			dinhTrungGian2 = dsChuTrinh[i].dinhDau;
		}
		if (dinhTrungGian1 == dinhTrungGian2){
			count3++;
		}
		if (count1 == 2 && count2 == 2 && count3 == 2){
			return 1;
		}
	}
	return 0;
}
void luaChonCanh(Canh dsCanh[]){
	Canh dsChuTrinh[MAX];
	n_ChuTrinh = 0;
	for (int i = 0; i < n_Canh; i++){
		if (kiemTraBac3(dsChuTrinh, dsCanh[i]) == 0 && kiemTraChuTrinh(dsChuTrinh,dsCanh[i]) == 0){
			dsChuTrinh[n_ChuTrinh] = dsCanh[i];
			n_ChuTrinh++;
		}
	}
	printf("\nDanh sach canh lua chon:\n");
	xuatDSCanh(dsChuTrinh, n_ChuTrinh);
	ghiFile(dsChuTrinh);
}
void ghiFile(Canh dsChuTrinh[]) {
	char ketQua[MAX];
	int sum = 0;
	for (int i = 0; i < n_ChuTrinh; i++) {
		sum += dsChuTrinh[i].doDai;
		ketQua[i] = dsChuTrinh[i].dinhDau;
	}
	for (int i = n_ChuTrinh-1; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < n_ChuTrinh; j++) {
			if (dsChuTrinh[i].dinhCuoi == ketQua[j]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			ketQua[i] = dsChuTrinh[i].dinhCuoi;
		}
	}
	for (int i = 0; i < n_ChuTrinh; i++) {
		for (int j = i + 1; j < n_ChuTrinh; j++) {
			if (ketQua[i] > ketQua[j]) {
				char temp = ketQua[i];
				ketQua[i] = ketQua[j];
				ketQua[j] = temp;
			}
		}
	}
	FILE* f = fopen("Bai2Out.txt", "w");
	if (f == NULL) {
		printf("Ghi file khong thanh cong!");
	}
	printf("\nKet qua:\n");
	for (int i = 0; i < n_ChuTrinh; i++) {
		printf("%c-", ketQua[i]);
		fprintf(f, "%c-", ketQua[i]);
	}
	printf("%c", thanhPhoXuatPhat);
	fprintf(f, "%c\n", thanhPhoXuatPhat);
	printf("\n%d", sum);
	fprintf(f, "%d", sum);
	printf("\nGhi file thanh cong!");
}