// Dùng chia để trị để giải quyết bài toán :
// float a
// iput : 692345.84523
// output : 965432.23458
// Mảng a tăng b giảm
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "algorithm"
void soThanhXau(double a, char so[], char a1[], char a2[]);
void quicksort(char a[], int l, int r, int(*compare)(char a ,char b));
int compareless(char a, char b);
int comparemore(char a, char b);
void swapchar(char &a,char &b){
    char temp = a ;
    a =  b;
    b = temp;
}
int main(){
    double a;
    char so[20];
    char a1[15],a2[15],a3;

    printf("\nNhap so : "); scanf("%lf",&a);
    sprintf(so,"%lf\n",a);
    soThanhXau(a,so,a1,a2);
    printf("\n%s\n%s",a1,a2);

    int l1 = 0 , l2 = 0;
    int r1 = strlen(a1) - 1 , r2 = strlen(a2) - 1;
    quicksort(a1,l1,r1,compareless);
    quicksort(a2,l2,r2,comparemore);
    printf("\n%s.%s", a1,a2);
}
void soThanhXau(double a, char so[], char a1[], char a2[])
{
    int i = 0, j = 0;
	while (so[i] !='.')
	{
		a1[i] = so[i];
		++i;
	}
    //12345.544254
	char temp = so[i];
	a1[i] = '\0';
	++i;
	while (so[i] != '\0') {
		a2[j] = so[i];
		++i;
		++j;
	}
	a2[j-1] = so[i];
}
void quicksort(char a[], int l, int r,int(*compare)(char,char)) {
	if (l >= r)return;
	char p = a[(l + r) / 2];
	int i = l, j = r;
	do
	{

	
		while (compare(a[i], p)<0) {
			i++;
		}
		while (compare( a[j] , p)>0) {
			j--;
		}
		if (i <= j) {
			if(i!=j)
				swapchar(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	quicksort(a, l, j,compare);
		quicksort(a, i, r,compare);
		
}
int comparemore(char a, char b) {
	if (a == b)return 0;
	if (a > b)return 1;
	if (a < b)return -1;
}
int compareless(char a, char b) {
	if (a == b)return 0;
	if (a > b)return -1;
	if (a < b)return 1;
}