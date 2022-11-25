
void NhapMT(double A[][SIZE], int N)
{
	int i, j;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			scanf("%lf", &A[i][j]);
		}
	}
}


void XuatMT(double A[][SIZE], int N)
{
	int i, j;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			printf("%0.1lf \t", A[i][j]);
		}
		printf("\n");
	}
}

/*cong 2 ma tran*/
void Cong(double A[][SIZE], double B[][SIZE], double kq[][SIZE], int N)
{
	int i, j;

	for (i = 0; i< N; i++)
	{
		for (j = 0; j<N; j++)
		{
			kq[i][j] = A[i][j] + B[i][j];
		}
	}

}

/*tru 2 ma tran*/
void TruMT(double A[][SIZE], double B[][SIZE], double kq[][SIZE], int N)
{
	int i, j;

	for (i = 0; i< N; i++)
	{
		for (j = 0; j<N; j++)
		{
			kq[i][j] = A[i][j] - B[i][j];
		}
	}
}


/*thuat toan.  */
void ThuatToanStrassen(double A[][SIZE], double B[][SIZE], double C[][SIZE], int N)
{
	// toi gian nho nhat
	if (N == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
		return;
	}

	// nhung truong hop con lai
	else
	{
		int sub_N = (int)(N / 2);// giam kich thuot ma tran chia 4 

		double A11[SIZE][SIZE], A12[SIZE][SIZE], A21[SIZE][SIZE], A22[SIZE][SIZE];
		double B11[SIZE][SIZE], B12[SIZE][SIZE], B21[SIZE][SIZE], B22[SIZE][SIZE];
		double C11[SIZE][SIZE], C12[SIZE][SIZE], C21[SIZE][SIZE], C22[SIZE][SIZE];
		double P1[SIZE][SIZE], P2[SIZE][SIZE], P3[SIZE][SIZE], P4[SIZE][SIZE], P5[SIZE][SIZE], P6[SIZE][SIZE], P7[SIZE][SIZE];
		double Akq[SIZE][SIZE], Bkq[SIZE][SIZE];

		int i, j;

		//chia ma trận thành 4 ma trận con:
		for (i = 0; i < sub_N; i++)
		{
			for (j = 0; j < sub_N; j++)
			{
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + sub_N];
				A21[i][j] = A[i + sub_N][j];
				A22[i][j] = A[i + sub_N][j + sub_N];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + sub_N];
				B21[i][j] = B[i + sub_N][j];
				B22[i][j] = B[i + sub_N][j + sub_N];
			}
		}
		/*XuatMT(A11, sub_N);
		printf("\n");
		XuatMT(A12, sub_N);
		printf("\n");
		XuatMT(A21, sub_N);
		printf("\n");
		XuatMT(A22, sub_N);
		printf("\n");
		getch();*/
		// tinh p1 to p7:
		/*chi tiet*/

		Cong(A11, A22, Akq, sub_N);   // a11 + a22
		Cong(B11, B22, Bkq, sub_N);   // b11 + b22
		ThuatToanStrassen(Akq, Bkq, P1, sub_N);  // p1 = (a11+a22) * (b11+b22)

		Cong(A21, A22, Akq, sub_N);   // a21 + a22
		ThuatToanStrassen(Akq, B11, P2, sub_N); // p2 = (a21+a22) * (b11)

		TruMT(B12, B22, Bkq, sub_N); // b12 - b22
		ThuatToanStrassen(A11, Bkq, P3, sub_N); // p3 = (a11) * (b12 - b22)

		TruMT(B21, B11, Bkq, sub_N); // b21 - b11
		ThuatToanStrassen(A22, Bkq, P4, sub_N); // p4 = (a22) * (b21 - b11)

		Cong(A11, A12, Akq, sub_N); // a11 + a12
		ThuatToanStrassen(Akq, B22, P5, sub_N); // p5 = (a11+a12) * (b22)

		TruMT(A21, A11, Akq, sub_N); // a21 - a11
		Cong(B11, B12, Bkq, sub_N); // b11 + b12
		ThuatToanStrassen(Akq, Bkq, P6, sub_N); // p6 = (a21-a11) * (b11+b12)

		TruMT(A12, A22, Akq, sub_N); // a12 - a22
		Cong(B21, B22, Bkq, sub_N); // b21 + b22
		ThuatToanStrassen(Akq, Bkq, P7, sub_N); // p7 = (a12-a22) * (b21+b22)

		// calculating c21, c21, c11 e c22:

		Cong(P3, P5, C12, sub_N); // c12 = p3 + p5
		Cong(P2, P4, C21, sub_N); // c21 = p2 + p4

		Cong(P1, P4, Akq, sub_N); // p1 + p4
		Cong(Akq, P7, Bkq, sub_N); // p1 + p4 + p7
		TruMT(Bkq, P5, C11, sub_N); // c11 = p1 + p4 - p5 + p7

		Cong(P1, P3, Akq, sub_N); // p1 + p3
		Cong(Akq, P6, Bkq, sub_N); // p1 + p3 + p6
		TruMT(Bkq, P2, C22, sub_N); // c22 = p1 + p3 - p2 + p6


		// Gop

		for (i = 0; i < sub_N; i++)
		{
			for (j = 0; j < sub_N; j++)
			{
				C[i][j] = C11[i][j];
				C[i][j + sub_N] = C12[i][j];
				C[i + sub_N][j] = C21[i][j];
				C[i + sub_N][j + sub_N] = C22[i][j];
			}
		}

	}

}