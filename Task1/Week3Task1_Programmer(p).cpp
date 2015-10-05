#include <iostream>
#include <math.h>
using namespace std;

long ** multMatrix(long ** arr1, long ** arr2, int len1, int wid1, int len2, int wid2, int & newLen, int & newWid);

int main()
{
	return 0;
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
	    for (int j = 0; j < newWid; j++)
	        for (int k = 0; k < wid1; k++)
	        	ans[i][j] += arr1[i][k] + arr2[k][j];
	}
	newLen = len1; 
	return ans;
}
