// author Evgeniy Afanasev


#include <math.h>
#include <ctime>
#include <random>
#include <string>				// модуль строк
#include <iostream>
#include <fstream>				// модуль файла
using namespace std;
// создает случайное число в диапозионе от -100 до 100
double RandomChislo()
{
	return 1.0 * rand() / RAND_MAX * 200 - 100;
}

// заполняет массив случайными числами
void ZapolnenieMas(double *mas, int n)
{
	srand(time(NULL));
	for (int i = 0; i< n; i++)
	{
		mas[i] = RandomChislo();
	}
}


// вычисляет по заданной формуле
double Reshenie (double n) 
{
	return (pow(sqrt(abs(n))-n,2));
}

// считает сумму всех элементов
double Summ(double *mas, int n)
{
	double summa;
	// идет по массиву складывая значения		
	for(int i = 0; i < n; i++)
	{
		summa = summa + Reshenie(mas[i]);
	}
	return summa;
}

void SaveInFile(double* mas, int n, const std::string& way)
{
	ofstream File;
	File.open(way);

	for(int i = 0; i<n; i++)
	{
		File << mas[i] << endl;
	};
	File.close();
}

void OpenFromFile(double* mas, int n, const std::string& way)
{
	ifstream File;
	File.open(way);
	if (File.is_open()){
		for(int i = 0; i<n; i++)
			{
				File >> mas[i];
			};
	};
}

