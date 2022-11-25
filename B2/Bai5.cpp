#include "stdio.h"
#include "conio.h"
#include "math.h"
#define MAXSIZE 50
void inputArray(int a[], int &n);
void outputArray(int a[], int n);
float averageArray(int a[], int left, int right, int n);
int averageElementsInArray(int a[], float average, int left, int right);
void main(){
	int a[MAXSIZE], n;
	inputArray(a, n);
	printf("\n\tArray: ");
	outputArray(a, n);
	printf("\n\tAverage of array is: %.2f",averageArray(a,0,n-1,n));
	float average = averageArray(a, 0, n - 1, n);
	printf("\n\tAverage Elements in Array is: %d", averageElementsInArray(a,average , 0, n - 1));
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
float averageArray(int a[], int left, int right, int n){
	if (left == right){
		return (float) a[left] / n;
	}
	else{
		int mid = (left + right) / 2;
		float averageLeft = averageArray(a, left, mid,n);
		float averageRight = averageArray(a, mid + 1, right,n);
		return averageLeft + averageRight;
	}
}
int averageElementsInArray(int a[], float average, int left, int right){
	if (left == right){
		return a[left];
	}
	else{
		int mid = (left + right) / 2;
		int averageLeft = averageElementsInArray(a,average, left, mid);
		int averageRight = averageElementsInArray(a,average, mid + 1, right);
		if ((float)abs(averageLeft - average) < (float)abs(averageRight - average)){
			return averageLeft;
		}
		return averageRight;
	}
}