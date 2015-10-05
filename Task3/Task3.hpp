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

