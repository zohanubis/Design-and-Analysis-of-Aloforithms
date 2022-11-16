#include "stdio.h"
void readFile(int a[][50], int &n);
void printTable(int a[][50], int n);
void deleteColumn(int a[][50], int col, int &n);
void sortTable(int a[][50], int n);
void selectionTable(int a[][50], int &n);
int main(){
	int a[50][50],n;
	readFile(a,n);
	printf("\tTable: ");
	printTable(a,n);
	sortTable(a,n);
	printf("\n\tTable after sort Ei: ");
	printTable(a,n);
	selectionTable(a,n);
	return 0;
}
void readFile(int a[][50], int &n){
	FILE *f = fopen("ActivitySelection.txt","rt");
	if(f == NULL){
		printf("\n\tLoi doc file");
	}
	fscanf(f,"%d\n",&n);
	for(int i = 1; i <= 2; i++){
		for(int j = 0; j < n; j++){
			fscanf(f,"%d",&a[i][j]);
			a[0][j] = j + 1;
		}
	}
}
void printTable(int a[][50], int n){
	for(int i = 0; i < 3; i++){
		if(i == 0){
			printf("\nAi: ");
		}else if(i == 1){
			printf("\nSi: ");
		}else{
			printf("\nEi: ");
		}
		for(int j = 0; j < n; j++){
			printf("%d ",a[i][j]);
		}
	}
}
void sortTable(int a[][50], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(a[2][i] > a[2][j]){
				for(int k = 0; k < 3; k++){
					int temp = a[k][i];
					a[k][i] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}
void deleteColumn(int a[][50], int col, int &n){
	for(int i = 0; i < 3; i++){
		for(int j = col; j < n-1; j++){
			a[i][j] = a[i][j+1];
		}
	}
	n--;
}
void selectionTable(int a[][50], int &n){
	int b[50];
	printf("\nLi\tChon\tXoa");
	for(int i = 0; i < n; i++){
		printf("\n%d\t",i+1);
		b[i] = a[0][i];
		printf("%d\t",b[i]);
		for(int  j = i+1; j < n; j++){
			if(a[1][j] < a[2][i]){
				printf("%d ",a[0][j]);
				deleteColumn(a,j,n);
				j--;
			}
		}
	}
	printf("\nHoat dong duoc chon: ");
	for(int i = 0; i < n; i++){
		printf("%d ",b[i]);
	}
}
