#include "stdio.h"
#include "conio.h"
#define MAX 30
void toHop(int arr[MAX][MAX],int n, int k);
void improveToHop(int arr[MAX],int n, int k);
void main(){
	int k, n;
	int arr[MAX][MAX];
	do{
		printf("\nNhap n va k: ");
		scanf("%d%d", &n, &k);
	} while (n < k);
	toHop(arr,n, k);
	
	getch();
}
void toHop(int arr[][MAX],int n, int k){
	for (int i = 0; i <= n ; i++){
		for (int j = 0; j <= i; j++){
			if (i == j || i == 0){
				arr[i][j] = 1;
			}
			else{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= n ; i++){
		printf("\n");
		for (int j = 0; j <= i; j++){
			printf("%d ", arr[i][j]);
		}
	}
	printf("\n\tC(%d,%d): %d", k, n, arr[n][k]);
}
void improveToHop(int arr[],int n, int k){
	arr[0] = 1;
	arr[1] = 1;
	int p1, p2;
	for (int i = 2; i <= n; i++){
		p1 = arr[0];
		for (int j = 1; j <= i; j++){
			p2 = arr[j];
			arr[j] = p1 + p2;
			p1 = p2;
		}
		arr[i] = 
	}
}