#include "Task3.hpp"
#include <iostream>	
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std; 

inline void Checking();
//inline void OutputAns(double [], double [], int);

int main()
{
    Checking();
    return 0;
}

/*void OutputAns(double yourAns[], double myAns[], int n)
{
	cout.precision(3);
    cout.setf(ios::fixed, ios::floatfield);
	cout << "\nYour answer:\t";
	for (int i = 0; i < n; i++)
		cout << yourAns[i] << " ";
	cout << "\nMy answer:\t";
	for (int i = 0; i < n; i++)
		cout << myAns[i] << " ";
	cout << endl;
}*/

void Checking()
{
    const long MAXN = 100, MAXT = 10;
    ifstream fin;
    fin.open("input.txt");
    int tests, n, m, i;
    double factors1[MAXN], factors2[MAXN];
    double * sum[MAXT], * mult[MAXT];
    int amount_sum[MAXT], amount_mult[MAXT];
    fin >> tests;
    for (int k = 0; k < tests; k++)
    {
        fin >> n >> m;
        for (i = 0; i < n; i++)
            fin >> factors1[i];
        for (i = 0; i < m; i++)
            fin >> factors2[i];
        sum[k] = summa(factors1, factors2, n, m);
        mult[k] = multi(factors1, factors2, n, m);
        amount_sum[k] = max(n, m);
        amount_mult[k] = n+m-1;
    }
    fin.close();
    freopen("answers.txt", "r", stdin);
    freopen("results.txt", "w", stdout);
    double ans;
   // for (i = 0; i < n+m-1; i++)
    //    cout << mult[tests-1][i] << " ";
    //for (i = 0; i < MAXN; i++) ans[i] = 0;
    for (int k = 0; k < tests; k++)
    {
        bool flag = true;
        cout << "Test " << k+1 << ":";
        for (i = 0; i < amount_sum[k]; i++)
        {
            cin >> ans;
            //ans = floor(ans*1000+.5)/1000;
            sum[k][i] = floor(sum[k][i]*1000+.5)/1000;
            if (ans != sum[k][i]) 
            {
                cout << "\tWrong answer in sum!\n";
                cout << i  << " " << ans << " " << sum[k][i];
                //OutputAns(sum[k], ans, amount_sum[k]);
                flag = false;
                break;
            }
        }
        //for (i = 0; i < amount_sum[k]; i++) ans[i] = 0;
        if (flag) cout << "\tOK!\n";
        flag = true;
        for (i = 0; i < amount_mult[k]; i++)
        {
            cin >> ans;
            ans = floor(ans*1000+.5)/1000;
            mult[k][i] = floor(mult[k][i]*1000+.5)/1000;
            if (ans != mult[k][i]) 
            {
                cout << "\tWrong answer in multi!\n";
                //OutputAns(sum[k], ans, amount_mult[k]);
                flag = false;
                break;
            }
        } 
        if (flag) cout << "\tOK!\n";
        //for (i = 0; i < amount_mult[k]; i++) ans[i] = 0;
    }
}
