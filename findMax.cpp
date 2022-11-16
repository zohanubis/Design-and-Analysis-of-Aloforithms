#include "stdio.h"
int findMax(int arr[], int low, int high);
int main(){
	int arr[10],n;
	printf("Input n: ");scanf("%d",&n);
	for(int i = 0; i < n; i++){
		printf("arr[%d] = ",i);scanf("%d",&arr[i]);
	}
	printf("Max is: %d",findMax(arr,0,n-1));
	return 0;
}
int findMax(int arr[], int low, int high){
	int max;
	if(low < high){
		int mid = (low+high) / 2;
		int maxLeft = findMax(arr,low,mid);
		int maxRight = findMax(arr,mid+1,high);
		if(arr[maxLeft] > arr[maxRight]){
			max = maxLeft;
		}else{
			max = maxRight;
		}
		return max;
	}
	return low;
}
