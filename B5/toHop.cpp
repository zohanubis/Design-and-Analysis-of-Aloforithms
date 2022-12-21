#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int c[20][20];

int main();
int toHop(int n, int k, int mang[20][20]);
int dq(int a, int b) {
	if (a == 0 || a == b) {
		return 1;
	}
	return(dq(a - 1, b - 1) + dq(a - 1, b));
}
//Ham thuc thi
int main() {
	/*printf("\nKet qua: %d", toHop(4, 3, c));
	printf("\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%5d", c[i][j]);
		}
		printf("\n");*/
	int a = 4, b = 3;
	printf("%d", dq(a, b));

}

void process() {

}

int toHop(int n, int k, int mang[20][20]) {
	//if (k == 0 || k == n) {
	//	c[k][k] = 1;
	//	return 1;
	//}
	//
	///*if (i == i && j == 0) return 1;
	//if (i == i && j == i) return 1;*/
	//return toHop(n - 1, k - 1) + toHop(n - 1, k)  ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) mang[i][j] = 1;
			else if (j == 0) mang[i][j] = 1;
			else if (i > 0 && i <= n) mang[i][i] = 1;
			else {
				return(toHop(n - 1, k - 1, mang) + toHop(i - 1, k, mang));
			}
		}
	}

}
