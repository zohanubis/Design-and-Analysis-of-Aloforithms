#include "stdio.h"
#include "math.h"
int average(int a[], float aver, int left, int right);
float findIndexMax(int a[], int left, int right, int n);
int main()
{
    int a[50], n, temp [50], b[50];
    printf("Input n : "); scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i); scanf("%d",&a[i]);
    }
    printf("\nArray : ");
    for(int i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
    printf("\nAverage array is: %.2f",findIndexMax(a,0,n-1,n));
	printf("\nAverage in array is: %d",average(a,findIndexMax(a,0,n-1,n),0,n-1));
	return 0;
}
float findIndexMax(int a[], int left, int right, int n)
{
    if(left == right){
        return (float) a[left] / n;
    }
    else{
        int mid = (left + right) / 2;
        float l = findIndexMax(a,left,mid,n);
        float r = findIndexMax(a,mid + 1, right, n);
        return l + r;
    }
}
int average(int a[], float aver, int left, int right){
    if(left == right){
        return a[left];
    }
    else{
        int mid = (left + right) / 2;
        int l = average(a,aver, left,mid);
        int r = average(a,aver, mid + 1, right);
        return abs(l-aver)< abs(r-aver) ? l : r;
    }
}