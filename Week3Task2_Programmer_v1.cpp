// Only for counting the most composition!!!!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool compare(int i, int j) { return (i > j); }

long max(int a, int b)
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
	int i,val;
	vector<long> sequence;
	sequence.reserve(n);
	vector<long>::iterator cur;
	cur = sequence.begin();
	for (i = 0; i < n; i++)
	{
	    cin >> *cur;
	    cur++;
	    
    }
	sort(sequence.begin(),sequence.begin()+n,compare);
	cout << "The maximum composition is:\t" << max(sequence[1]*sequence[2]*sequence[0],sequence[0]*sequence[n-2]*sequence[n-1]);
	return 0;
}
