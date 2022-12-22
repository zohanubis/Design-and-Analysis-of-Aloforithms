#include "stdio.h"
#include "conio.h"
#define MAXSIZE 50
int vt, vt1, vt2;
void inputArray(int a[], int& n);
void outputArray(int a[], int n);
int maxLeft(int a[], int i, int j);
int maxRight(int a[], int i, int j);
int subSequenceMax(int a[], int left, int right);
void main() {
	int a[MAXSIZE],b[MAXSIZE], n;
	inputArray(a, n);
	printf("\n\tArray: ");
	outputArray(a, n);
	int sum = subSequenceMax(a, 0, n - 1);
	printf("\n\tTong day con lon nhat: %d", sum);
	printf("\n\tDay con co tong lon nhat la: ");
	int j = 0;
	for (int i = vt; i >= 0; i--) {
		if (sum > 0) {
			b[j] = a[i];
			j++;
			sum -= a[i];
		}
	}
	for (int i = j-1; i >= 0; i--) {
		printf("%d ", b[i]);
	}
	getch();
}
void inputArray(int a[], int& n) {
	printf("Input n: "); scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void outputArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
int maxLeft(int a[], int i, int j) {
	int maxSum = 0;
	int sum = 0;
	for (int k = j; k >= i; k--) {
		sum += a[k];
		if (sum > maxSum) {
			maxSum = sum;
			vt1 = k;
		}
	}
	return maxSum;
}
int maxRight(int a[], int i, int j) {
	int maxSum = 0;
	int sum = 0;
	for (int k = i; k <= j; k++) {
		sum += a[k];
		if (sum > maxSum) {
			maxSum = sum;
			vt2 = k;
		}
	}
	return maxSum;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int subSequenceMax(int a[], int left, int right) {
	if (left == right) {
		return a[left];
	}
	int mid = (left + right) / 2;
	int sumLeft = subSequenceMax(a, left, mid);
	int sumRight = subSequenceMax(a, mid + 1, right);
	int sum = maxLeft(a, left, mid) + maxRight(a, mid + 1, right);
	if (sumLeft > sumRight) {
		vt = vt1;
	}
	else {
		vt = vt2;
	}
	return max(max(sumLeft, sumRight), sum);
}