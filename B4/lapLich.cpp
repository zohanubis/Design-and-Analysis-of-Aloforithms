//Khai bao thu vien
#include "HoatDong.h"

int main() {
	process();
	getch();
}

void menu() {
	printf("\nCau 1 :Lua chon hoat dong.  ");

}

void process() {
	HD hd[MAX];
	LL ll[MAX];
	int nhap = -1;
	while (nhap != 0) {
		menu();
		printf("\nLua chon cua ban: ");
		scanf("%d", &nhap);
		switch (nhap) {
		case 1:

			readFile(fileMH, hd, n);
			lucChonMonHoc(hd, ll, n);
			break;
		case 2:
			break;
		default:
			break;
		}
	}
}

void readFile(char fileName[], HD hd[], int& n) {
	FILE* f = fopen(fileName, "r");
	if (f == NULL) return;
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f, "%s %d %d", hd[i].ten, &hd[i].start, &hd[i].end);
	}
	displayMonHoc(hd, n);
	fclose(f);
}

void displayMonHoc(HD hd[], int n) {
	printf("\n\nXuat cac mon hoc");
	printf("\n%-5s | %-10s | %-10s", "Ten", "StartTime", "EndTime");
	for (int i = 0; i < n; i++) {
		printf("\n%-5s | %-10d | %d", hd[i].ten, hd[i].start, hd[i].end);
	}
}

void lucChonMonHoc(HD hd[], LL ll[], int n) {
	int min = hd[0].end, dem = 0;
	for (int i = 0; i < n; i++) {
		if (hd[i].end < min) {
			min = hd[i].end;
			ll[0].end = hd[i].end;
			ll[0].ten = hd[i].ten;
			ll[0].start = hd[i].start;
		}
	}

	int max = ll[0].end;
	for (int i = 0; i < n; i++) {
		if (max < hd[i].start) {
			ll[dem + 1].ten = hd[i].ten;
			ll[dem + 1].start = hd[i].start;
			ll[dem + 1].end = hd[i].end;
			max = hd[i].end;
			dem++;
		}
	}
	displayLich(ll, n);
}

void displayLich(LL ll[], int n) {
	printf("\n\nXuat danh sach lich cac mon hoc duoc chon");
	printf("\n%-5s | %-10s | %-10s", "Ten", "StartTime", "EndTime");
	for (int i = 0; i < n + 1; i++) {
		printf("\n%-5s | %-10d | %d", ll[i].ten, ll[i].start, ll[i].end);
	}
}