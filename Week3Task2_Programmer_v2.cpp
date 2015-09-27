#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXN = 1000;

int sequence[MAXN];

void QSort(int, int);
inline long max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main()
{
	cout << "Enter an amount of elements:\t";
	int n;
	cin >> n;
	cout << "\nEnter a sequence:\t";
	for (int i = 0; i < n; i++) cin >> sequence[i];
	QSort(0,n-1);
	cout << "The maximum composition is:\t" << max(sequence[1]*sequence[2]*sequence[0],sequence[0]*sequence[n-2]*sequence[n-1]);
	return 0;
}

void QSort(int left, int right)
{
	int key = sequence[left+(rand() % (right-left))];
	int buf,l = left,r = right;
	do
	{
		while (sequence[l] > key) l++;
		while (sequence[r] < key) r--;
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
