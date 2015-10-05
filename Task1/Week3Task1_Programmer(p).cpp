#include <iostream>
#include <math.h>
using namespace std;

long ** multMatrix(long ** arr1, long ** arr2, int len1, int wid1, int len2, int wid2, int & newLen, int & newWid);
<<<<<<< HEAD
void cleaning(long **, int, int);
=======
// Принимает 2 массива и их параметры соответственно, на выходе:
// конечный массив, а также параметры выходного массива через
// переменные newLen, newWid
>>>>>>> origin/master

int main()
{
	return 0;
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
