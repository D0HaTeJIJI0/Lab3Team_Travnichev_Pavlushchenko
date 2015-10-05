#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int MAXN = 100;

inline void outputSum(double fact1[], double fact2[], long n, long m)
{
    const int newLen = max(n, m);
    cout.precision(3);
    cout.setf(ios::fixed, ios::floatfield);
    for (int i = 0; i < newLen-1; i++)
        cout << fact1[i]+fact2[i] << " ";
    cout << fact1[newLen-1]+fact2[newLen-1] << endl;
}

inline void outputMult(double fact1[], double fact2[], long n, long m)
{
    double answer[MAXN];
    for (int i = 0; i < n+m; i++)
    {
        answer[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            answer[j+i] += fact1[i]*fact2[j];
    }
    for (int i = 0; i < n+m-2; i++) cout << answer[i] << " ";
    cout << answer[n+m-2] << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("answers.txt", "w", stdout);
    int tests, n, m, i;
    double factors1[MAXN], factors2[MAXN]; 
    cin >> tests;
    for (int k = 0; k < tests; k++)
    {
        cin >> n >> m;
        int len = max(n, m);
        for (i = 0; i < len; i++) 
		{
			factors1[i] = 0;
			factors2[i] = 0;
		}
        for (i = 0; i < n; i++)
            cin >> factors1[i];
        for (i = 0; i < m; i++)
            cin >> factors2[i];
        outputSum(factors1, factors2, n, m);
        outputMult(factors1, factors2, n, m);
    }
    return 0;
}
