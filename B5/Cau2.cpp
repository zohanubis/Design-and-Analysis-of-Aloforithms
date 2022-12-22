#include "stdio.h"
#include "conio.h"
const int MAX =10;
struct Do_vat{
char Ten[20];
int trong_luong;
int gia_tri;
int Phuong_an;
};
typedef Do_vat Danh_sach_vat [MAX]; 
typedef int Bang[10][100] ;

void Tao_Bang (Danh_sach_vat ds_vat, int n, int W, Bang F, Bang X)
{
    int xk, yk, k;
    int FMax, XMax, v;
    /*Lấp đầy hàng đầu tiên của 2 bảng*/
    for (v= 0; v <= W; v++)
    {
        X[1][v] = v/ds_vat[1].trong_luong;
        F[1][v] = X[1] [v] * ds_vat[1].gia_tri;
    }
    /*Lấp đầy các hàng còn lại*/
    for (k = 2; k <= n; k++)
    {
        X[k][0] = 0;
        F[1][0] = 0;
    for ( v=1; v <= W; v++)
    {
        Fmax = F[k-1][v] ;
        XMax = 0;
        yk = v/ds_vat[k].trong_luong;
        for (xk=1; xk <= yk; xk++){
            if ( F[k-1][v-xk * ds_vat[k].trong_luong] + xk * ds_vat[k].gia_tri>FMax)
            {
                FMax=F[k-1][v-k*ds_vat[k].trong_luong] + xk*ds_vat[k].gia_tri;
                XMax= xk;
            }
        F[k][v] = FMax;
        X[k][v] = XMax;
        }
    }
}

void Tra_Bang(Danh_sach_vat ds_vat, int n, int W, Bang F[], Bang X[])
{
    int k, v;
    v = W;
    for (k = n; k >=1; k--)
    if (X[k][v] > 0)
    {
    ds_vat[k].Phuong_an := X[k][v];
    v = v - X[k][ v] * ds_vat[k].trong_luong;
    }
}
int main()
{

}