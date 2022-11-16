#include "stdio.h"
int findSum(int arr[], int low, int high);
int main(){
	int arr[10],n;
	printf("Input n: ");scanf("%d",&n);
	for(int i = 0; i < n; i++){
		printf("arr[%d] = ",i);scanf("%d",&arr[i]);
	}
	printf("Sum is: %d",findSum(arr,0,n-1));
	return 0;
}
int findSum(int arr[], int low, int high){
	if(low < high){
		int mid = (low+high) / 2;
		int sumLeft = findSum(arr,low,mid);
		int sumRight = findSum(arr,mid+1,high);
		return sumLeft + sumRight;
	}
	return arr[low] % 2 == 0 ? arr[low] : 0;
}
