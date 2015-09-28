#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXN = 1000;

struct array
{
	long val, pos;
};

int n;
array sequence[MAXN];

void test(int*, int*);
void QSort(int, int);
inline void outputData(int &, int &, int &); 

int main()
{
	cout << "Enter an amount of elements:\t";
	cin >> n;
	cout << "\nEnter a sequence:\t";
	for (int i = 0; i < n; i++) 
	{
		cin >> sequence[i].val;
		sequence[i].pos = i;	
	}
	QSort(0,n-1);
	int n1, n2, n3;
	outputData(n1, n2, n3);
	cout << "\nThe numbers, which give the most composition are:\t" << n1 << " " << n2 << " " << n3;
	int* result;

	return 0;
}

void outputData(int & n1, int & n2, int & n3)
{
	long composition1 = sequence[0].val*sequence[1].val*sequence[2].val;
	long composition2 = sequence[0].val*sequence[n-1].val*sequence[n-2].val;
	n1 = sequence[0].pos;
	if (composition1 > composition2) 
	{
		n2 = sequence[1].pos;
		n3 = sequence[2].pos;
	}
	else 
	{
		n2 = sequence[n-2].pos;
		n3 = sequence[n-1].pos;
	}
}

void QSort(int left, int right)
{
	int key = sequence[left+(rand() % (right-left))].val;
	int l = left,r = right;
	array buf;
	do
	{
		while (sequence[l].val > key) l++;
		while (sequence[r].val < key) r--;
		if (l <= r)
		{
			buf = sequence[l];
			sequence[l] = sequence[r];
			sequence[r] = buf;
			l++; r--;
		}
	}
	while (l <= r);
	if (l < right) QSort(l,right);
	if (r > left) QSort(left,r);
}
