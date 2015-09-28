#include <iostream>
#include <math.h>
using namespace std;

long ** multMatrix(long ** arr1, long ** arr2, int len1, int wid1, int len2, int wid2, int & newLen, int & newWid);

void cleaning(long **, int, int);

// Принимает 2 массива и их параметры соответственно, на выходе:
// конечный массив, а также параметры выходного массива через
// переменные newLen, newWid

long min(long a, long b)
{
	if (a <= b)
		return a;
	else return b;
}
void cleaning(long ** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete(arr[i]);
		arr[i] = 0;
	}
}

long ** multMatrix(long ** arr1, long ** arr2, int len1, int wid1, int len2, int wid2, int & newLen, int & newWid)
{
	if (wid1 != len2) 
	{
		cout << "Error!";
		return 0;
	}
	newWid = min(len1, wid1);
	long ** ans = new long * [len1];
	for (int i = 0; i < len1; i++)
	{
		ans[i] = new long [newWid];
		for (int j = 0; j < newWid; j++) ans[i][j] = 0;
	    for (int j = 0; j < newWid; j++)
	        for (int k = 0; k < wid1; k++)
	        {
	       		ans[i][j] += arr1[i][k] * arr2[k][j];
	       		cout << i << " " << j << "\t" << ans[i][j] << endl;
	       	}
	}
	cleaning(arr1, len1, wid1);
	cleaning(arr2, len2, wid2);
	newLen = len1; 
	return ans;
}
void assert(long** matrix1, long** matrix2, int len1, int wid1, int len2, int wid2, long** resmatrix)
{
	int newWid, newLen;
	long** firstmatrix = multMatrix(matrix1, matrix2, len1, wid1, len2, wid2, newWid, newLen);
	bool isTrue = true;
	for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < wid1; j++)
		{
 			if (firstmatrix[i][j] != resmatrix[i][j])
 				isTrue = false;
 		}
 	}
 	if (isTrue)
 		cout << "OK" << endl;
 	else
 		cout << "False" << endl;
 }

int main()
{
	long** matrix1 = new long*[4];
	for (int i = 0; i < 4; i++)
		matrix1[i] = new long[2];
	matrix1[0][0] = 6;
	matrix1[0][1] = 7;
	matrix1[1][0] = 5;
	matrix1[1][1] = 0;
	matrix1[2][0] = -1;
	matrix1[2][1] = 2;
	matrix1[3][0] = 6;
	matrix1[3][1] = 3;
	long** matrix2 = new long*[2];
	for (int i = 0; i < 2; i++)
		matrix2[i] = new long[3];
	matrix2[0][0] = 5;
	matrix2[0][1] = 4;
	matrix2[0][2] = 3;
	matrix2[1][0] = 2;
	matrix2[1][1] = 3;
	matrix2[1][2] = 6;
	long** resmatrix1 = new long*[4];
	for (int i = 0; i < 4; i++)
		resmatrix1[i] = new long[3];
	resmatrix1[0][0] = 44;
	resmatrix1[0][1] = 45;
	resmatrix1[0][2] = 60;
	resmatrix1[1][0] = 25;
	resmatrix1[1][1] = 20;
	resmatrix1[1][2] = 15;
	resmatrix1[2][0] = -1;
	resmatrix1[2][1] = 2;
	resmatrix1[2][2] = 9;
	resmatrix1[3][0] = 36;
	resmatrix1[3][1] = 33;
	resmatrix1[3][2] = 36;
	assert(matrix1, matrix2, 4, 3, 3, 2, resmatrix1);
	long** matrix3 = new long*[2];
	for (int i = 0; i < 3; i++)
		matrix3[i] = new long[3];
	matrix3[0][0] = 5;
	matrix3[0][1] = 8;
	matrix3[0][2] = -3;
	matrix3[1][0] = 6;
	matrix3[1][1] = -2;
	matrix3[1][2] = 0;
	long** matrix4 = new long*[3];
	for (int i = 0; i < 3; i++)
		matrix4[i] = new long[2];
	matrix4[0][0] = 7;
	matrix4[0][1] = 1;
	matrix4[1][0] = -4;
	matrix4[1][1] = 6;
	matrix4[2][0] = 5;
	matrix4[2][1] = 6;
	long** resmatrix2 = new long*[2];
	for (int i = 0; i < 2; i++)
		resmatrix2[i] = new long[2];
	resmatrix2[0][0] = -12;
	resmatrix2[0][1] = 35;
	resmatrix2[1][0] = 50;
	resmatrix2[1][1] = -6;
	assert(matrix3, matrix4, 2, 2, 2, 3, resmatrix2);
	long** matrix5 = new long*[3];
	for (int i = 0; i < 3; i++)
		matrix5[i] = new long[3];
	matrix5[0][0] = 5;
	matrix5[0][1] = 1;
	matrix5[0][2] = 5;
	matrix5[1][0] = 1;
	matrix5[1][1] = 5;
	matrix5[1][2] = 1;
	matrix5[2][0] = 5;
	matrix5[2][1] = 1;
	matrix5[2][2] = 5;
	long** matrix6 = new long*[3];
	for (int i = 0; i < 3; i++)
		matrix6[i] = new long[3];
	matrix6[0][0] = 3;
	matrix6[0][1] = 2;
	matrix6[0][2] = 3;
	matrix6[1][0] = 2;
	matrix6[1][1] = 3;
	matrix6[1][2] = 2;
	matrix6[2][0] = 3;
	matrix6[2][1] = 2;
	matrix6[2][2] = 3;
	long** resmatrix3 = new long*[3];
	for (int i = 0; i < 3; i++)
		resmatrix3[i] = new long[3];
	resmatrix3[0][0] = 32;
	resmatrix3[0][1] = 23;
	resmatrix3[0][2] = 32;
	resmatrix3[1][0] = 16;
	resmatrix3[1][1] = 19;
	resmatrix3[1][2] = 16;
	resmatrix3[2][0] = 32;
	resmatrix3[2][1] = 23;
	resmatrix3[2][2] = 32;
	assert(matrix5, matrix6, 3, 3, 3, 3, resmatrix3);
}