#include "stdio.h"
#define MAXSIZE 10
void input(float arr[], int& n);
void output(float arr[], int n);
void mergeSort(float arr[], float temp[], int left, int right);
void merge(float arr[], float temp[], int left, int mid, int right);
int main() {
	float arr[MAXSIZE], temp[MAXSIZE]; 
	int n;
	input(arr, n);
	printf("arr: ");
	output(arr, n);
	mergeSort(arr, temp, 0, n - 1);
	printf("\narr after sort: ");
	output(arr, n);
	return 0;
}
void input(float arr[], int& n) {
	printf("Input size array: "); scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("arr[%d] = ", i);
		scanf("%f", &arr[i]);
	}
}
void output(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.2f ", arr[i]);
	}
}
void mergeSort(float arr[], float temp[], int left, int right) {
	int mid;
	if (right > left) {
		mid = (left + right) / 2;
		mergeSort(arr, temp, left, mid);
		mergeSort(arr, temp, mid + 1, right);
		merge(arr, temp, left, mid + 1, right);
	}
}
void merge(float arr[], float temp[], int left, int mid, int right) {
	int left_end = mid - 1;
	int temp_pos = left;
	int size = right - left + 1;
	while ((left <= left_end) && (mid <= right)) {
		if (arr[left] < 0) {
			temp[temp_pos] = arr[left];
			temp_pos++;
			left++;
		}
		else{
			temp[temp_pos] = arr[mid];
			temp_pos++;
			mid++;
		}
	}
	while (left <= left_end) {
		temp[temp_pos] = arr[left];
		temp_pos++;
		left++;
	}
	while (mid <= right) {
		temp[temp_pos] = arr[mid];
		temp_pos++;
		mid++;
	}
	for (int i = 0; i <= size; i++) {
		arr[right] = temp[right];
		right--;
	}
}