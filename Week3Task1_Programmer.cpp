#include <iostream>
using namespace std;
const int MAXS = 1000;

long arr1[MAXS][MAXS],arr2[MAXS][MAXS],i,j,ans[MAXS][MAXS];

inline void InputData(int &, int &, bool);
inline void multiplicationMatrix(int, int &);
inline void init(int, int);
inline int min(int, int);

int main()
{
	cout << "Enter the first one:\n";
	int n1,m1;
	InputData(n1,m1,true);
	cout << "\n\nEnter the second one:\n";
	int n2,m2;
	InputData(n2,m2,false);
	if (m1 != n2) cout << "Error!";
	else 
	{
		multiplicationMatrix(n1,m1);
		cout << "\n\nThe result is:\n";
	    for (i = 0; i < n1; i++)
	    {
	        for (j = 0; j < m1; j++)
	            cout << ans[i][j] << " ";
	        cout << endl;
        }
	}
	return 0;
}

inline void InputData(int & n, int & m, bool flag)
{
	cout << "\nEnter parametres:\t";
	cin >> n >> m;
	cout << "\nEnter an matrix:\n";
	if (flag)
	   for (int i = 0; i < n; i++)
	       for (int j = 0; j < m; j++)
                cin >> arr1[i][j];
    else
       for (int i = 0; i < n; i++)
	       for (int j = 0; j < m; j++)
               cin >> arr2[i][j];
}

void init(int n, int m)
{
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < m; j++)
	         ans[i][j] = 0;
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

void multiplicationMatrix(int n, int & m)
{
	int i,j,k,newM = min(n, m);
	init(n, m);
	for (i = 0; i < n; i++)
	    for (j = 0; j < newM; j++)
	        for (k = 0; k < m; k++)
	            ans[i][j] += arr1[i][k]*arr2[k][j];
	m = newM;
}
