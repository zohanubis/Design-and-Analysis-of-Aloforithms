#include "stdio.h"
#include "conio.h"
#define MAXSIZE 50
void inputArray(int a[], int &n);
void outputArray(int a[], int n);
int findIndexMax(int a[], int left, int right);
int main(){
	int a[MAXSIZE], n;
	inputArray(a, n);
	printf("\n\tArray: ");
	outputArray(a, n);
	printf("\n\tIndex max is: %d", findIndexMax(a, 0, n - 1));
	getch();
}
void inputArray(int a[], int &n){
	printf("Input n: "); scanf("%d", &n);
	for (int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void outputArray(int a[], int n){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}
int findIndexMax(int a[], int left, int right){
	if (left == right){
		return left;
	}
	else{
		int mid = (left + right) / 2;
		int maxLeft = findIndexMax(a, left, mid);
		int maxRight = findIndexMax(a, mid + 1, right);
		if (a[maxLeft] > a[maxRight]){
			return maxLeft;
		}
		return maxRight;
	}
}