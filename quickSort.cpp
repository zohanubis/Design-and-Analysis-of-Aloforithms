#include "stdio.h"
void partition(float a[], int left, int right);
void printArray(float a[], int n);
int main(){
	float a[50];
	int n;
	printf("Nhap so luong phan tu: ");scanf("%d",&n);
	for(int i = 0; i < n; i++){
		printf("a[%d] = ",i);
		scanf("%f",&a[i]);
	}
	printf("Mang la: ");
	printArray(a,n);
	partition(a,0,n-1);
	printf("\nMang sau khi sort: ");
	printArray(a,n);
	return 0;
}
void printArray(float a[], int n){
	for(int i = 0; i < n; i++){
		printf("%.2f ",a[i]);
	}
}
void swap(float &a, float &b){
	float temp = a;
	a = b;
	b = temp;
}
void partition(float a[], int left, int right){
	int k = (left+right) / 2;
	float x = a[k];
	int l = left;
	int r = right;
	do{
		while(a[l] < x) l++;
		while(a[r] > x) r--;
		if(l <= r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}while( l < r);
	if(left < r) partition(a,left,r);
	if(right > l) partition(a,l,right);
}
