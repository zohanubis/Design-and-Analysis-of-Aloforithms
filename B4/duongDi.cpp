#include "DuongDi.h"

//Ham thuc thi
int main() {
	process();
	getch();
}

void process() {
	dt x[MAX];
	canh c[MAX];
	T t[MAX];
	int chon = -1;
	int u = 1, soCanh = 0;
	while (chon != 0) {
		menu();
		printf("\nChon cau de thuc thi: ");
		scanf("%d", &chon);
		switch (chon) {
		case 1:
			docFile(fileDT, n, x);
			break;
		case 2:
			tinhDoDai(x, c, n);
			break;
		case 3:
			khoiTaoHamChuaXet(chuaXet);
			searchDFS(x, c, t, n, u, soCanh);
			break;
		default:
			break;
		}
	}
}

void menu() {
    printf("1. Doc File");
    printf("2. Tinh do dai");
    printf("3. DFS");
}

void docFile(char fileName[], int& n, dt x[]) {
	FILE* f = fopen(fileName, "r");
	if (f == NULL) return;
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(f, "%s %d %d", x[i].ten, &x[i].x, &x[i].y);
	}
	showDoThi(x, n);
	fclose(f);
}

void showDoThi(dt x[], int n) {
	printf("\n\nHien thi do thi cua duong di");
	printf("\n%-10s %-10s %-10s", "Dinh", "Hoanh do", "Tung do");
	for (int i = 1; i <= n; i++) {
		printf("\n%-10s %-10d %-10d", x[i].ten, x[i].x, x[i].y);
	}
}

void searchDFS(dt x[], canh c[], T t[], int n, int u, int& soCanh) {
	chuaXet[u] = 1;
	for (int v = 1; v <= n; v++) {
		if (c[v].v != 0 && c[u].u != 0 && chuaXet[v] == 0) {
			soCanh++;
			t[soCanh].u = x[u].ten;
			t[soCanh].v = x[v].ten;
			if (soCanh == n - 1) {
				xuatCanhChuTrinh(t, soCanh);
				/*ghiFile(fileDT, n, c);*/
				return;
			}
			else {
				searchDFS(x, c, t, n, v, soCanh);
			}
		}
	}
}

void tinhDoDai(dt x[], canh c[], int n) {
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			c[i].doDai = sqrt(pow(x[i].x - x[1].x, 2) + pow(x[i].y + x[1].y, 2));
			c[i].u = x[i].ten;
			c[i].v = x[1].ten;
		}
		else {
			c[i].doDai = sqrt(pow(x[i].x - x[i + 1].x, 2) + pow(x[i].y - x[i + 1].y, 2));
			c[i].u = x[i].ten;
			c[i].v = x[i + 1].ten;
		}
	}
	printf("\n\nHien thi do dai cac canh cua duong di");
	printf("\n%-10s %-10s %-10s", "Dinh U", "Dinh V", "Do dai");
	for (int i = 1; i <= n; i++) {
		printf("\n%-10s %-10s %-10d", c[i].u, c[i].v, c[i].doDai);
	}
}

void khoiTaoHamChuaXet(int chuaXet[]) {
	for (int i = 1; i <= n; i++) {
		chuaXet[i] = 0;
	}
}

void ghiFile(char fileName[], int n, canh c[]) {

}

void xuatCanhChuTrinh(T t[], int n) {
	for (int i = 1; i <= n; i++) {
		printf("\n %s %s ", t[i].u, t[i].v);
	}
}