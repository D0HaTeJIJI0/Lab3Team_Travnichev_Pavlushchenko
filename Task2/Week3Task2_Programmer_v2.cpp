#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAXN = 100;
struct array
{
	long val, pos;
};

array sequence[MAXN];

void QSort(int, int); 
inline void maxMult(array [], long, long &, long & ,long &);

void test()
{
	int amount;
	array seq[MAXN];
	cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		cin >> seq[i].val;
		seq[i].pos = i;
	}
	long res1, res2, res3;
	cin >> res1 >> res2 >> res3;
	long a1, a2, a3;
	maxMult(seq, amount, a1, a2, a3);
	if ((a1 == res1) && (a2 == res2) && (a3 == res3))
	{
		cout << "OK" << endl;
	}
	else cout << "Failed" << endl;
	
}

void maxMult(array seq[], long amount, long & ind1, long & ind2, long & ind3)
{
    for (int i = 0; i < amount; i++) sequence[i] = seq[i];
    QSort(0, amount-1);
    long composition1 = sequence[0].val*sequence[1].val*sequence[2].val;
	long composition2 = sequence[0].val*sequence[amount-1].val*sequence[amount-2].val;
	ind1 = sequence[0].pos;
	if (composition1 > composition2) 
	{
		ind2 = sequence[1].pos;
		ind3 = sequence[2].pos;
	}
	else 
	{
		ind2 = sequence[amount-2].pos;
		ind3 = sequence[amount-1].pos;
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
void main()
{
	freopen("Input.txt", "r", stdin);
	test();
	test();
	test();
	test();
	test();
}

