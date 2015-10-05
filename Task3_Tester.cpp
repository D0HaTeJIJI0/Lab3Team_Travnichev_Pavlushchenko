#include <iostream>	
#include <fstream>
#include <cstring>

using namespace std; 

double *summa(double polynom1[], double polynom2[], int power1, int power2)       // функция суммы 2ух многочленов. параметры: массивы коэффициентов многочленов и максимальные степени этих многочленов 
{                                                                                 // функция возвращает указатель на массив суммы
	double *summ;
	if (power1 >= power2)
	{
		summ = new double[power1 + 1];
		for (int i = 0; i <= power2; i++)
		{
			summ[i] = polynom1[i] + polynom2[i];
		}
		for (int i = power2 + 1; i <= power1; i++)
		{
			summ[i] = polynom1[i];
		}
		cout << "!!!!";
	}
	else
	{
		summ = new double[power2 + 1];
		for (int i = 0; i <= power1; i++)
		{
			summ[i] = polynom1[i] + polynom2[i];
		}
		for (int i = power1 + 1; i <= power2; i++)
		{
			summ[i] = polynom2[i];
		}
	}
	return summ;
}

double *multi(double polynom1[], double polynom2[], int power1, int power2)          // аналогично, как и для суммы
{
	double *mult = new double[power1 + power2 + 1];
	for (int i = 0; i <= power1 + power2; i++)
	{
		mult[i] = 0;
	}
	for (int i = 0; i <= power1; i++)
	{
		for (int j = 0; j <= power2; j++)
		{
			mult[i + j] += polynom1[i] * polynom2[j];
		}
	}
	return mult;
}

inline void Checking();

int main()
{
    Checking();
    return 0;
}

void Checking()
{
    const long MAXN = 100, MAXT = 10;
    ifstream fin;
    fin.open("input.txt");
    int tests, n, m, i;
    double factors1[MAXN], factors2[MAXN];
    double * sum[MAXT];
    fin >> tests;
    for (int k = 0; k < tests; k++)
    {
        fin >> n >> m;
        for (i = 0; i < n; i++)
            fin >> factors1[i];
        for (i = 0; i < m; i++)
            fin >> factors2[i];
        sum[k] = summa(factors1, factors2, n, m);
        cout << "!!!!";
    }
    cout << "!!!!";
    fin.close();
    cout << "!!!!";
    fin.open("answers.txt");
    cout << "!!!!";
    char ans[MAXN*2-1];
    for (int k = 0; k < tests; k++)
    {
        fin >> ans;
        bool flag = true;
        for (i = 0; i < strlen(ans); i++)
            if ((int)(ans[i]) != sum[k][i]) 
            {
                cout << "Wrong answer!\n";
                flag = false;
                break;
            }
        if (flag) cout << "OK!\n";
    }
    fin.close();
}
