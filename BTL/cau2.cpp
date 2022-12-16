#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<algorithm>
struct Hoatdong {
	float TGstart;
	float TGend;
	float time;
};
void swap(Hoatdong& a, Hoatdong& b) {
	Hoatdong temp;
	temp = b;
	a = b;
	b = temp;
}
void DocFile(Hoatdong list[]);
int sl;
int main() {

	Hoatdong list[20];
	DocFile(list);

	for (int i = 0; i < sl; i++) {
		printf("Start\tEnd.\n");
		printf("%.2f\t%.2f\n", list[i].TGstart, list[i].TGend);
	}
	int a, b;
	printf("Nhap thoi gian ban dau(Dnh dang 24h va nhap dang H:mm) : "); scanf("%d:%d", &a, &b);
	float c = float(a) + float(60 / b);
	for (int i = 0; i < sl; i++) {
		for (int j = i + 1; j < sl; j++) {
			if (list[i].time > list[j].time) swap(list[i], list[j]);
		}
	}
	float timenow = c;
	for (int i = 0; i < sl; i++) {

		if (list[i].TGstart > timenow && list[i].TGend > timenow) {
			printf(" %.2f - %.2f -> ", list[i].TGstart, list[i].TGend);
			timenow = list[i].TGend;
		}
	}
}
void DocFile(Hoatdong list[]){
	FILE* f;
	f = fopen("Bai2.txt", "r");
	fscanf(f, "%d", &sl);
	for (int i = 0; i < sl; i++) {
		fscanf(f, "%f %f", &list[i].TGstart, &list[i].TGend);
	}
	for (int i = 0; i < sl; i++)
	{
		list[i].time = list[i].TGend - list[i].TGstart;
	}
}