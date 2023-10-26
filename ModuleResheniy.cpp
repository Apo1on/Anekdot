// author Evgeniy Afanasev


#include <math.h>
#include <ctime>
#include <random>
#include <string>				// модуль строк
#include <iostream>
#include <fstream>				// модуль файла
#include <cassert>
using namespace std;
// создает случайное число в диапозионе от -100 до 100
// интервал задается в ручную
double RandomNumber(int min,int max)
{
	return 1.0 * rand() / RAND_MAX * max + min;
}

// заполняет массив случайными числами
void ZapolnenieMas(double *mas, const int& n, const int& min, const int& max)
{
	for (int i = 0; i< n; i++)
	{
		mas[i] = RandomNumber(min,max);
	}
}


// вычисляет по заданной формуле
//double Reshenie (double n) 
//{
//	return ();
//}

// считает сумму всех элементов
double Summ(const double *mas, const int& n)
{
	double summa =0.0;
	// идет по массиву складывая значения		
	for (int i = 0; i < n; i++)
	{
		summa = summa + pow(sqrt(abs(mas[i])) - mas[i], 2);
			
	};
	return summa;
}

void SaveInFile(const double* mas, int n, const std::string& way)
{
	ofstream File;
	File.open(way);

	for(int i = 0; i<n; i++)
	{
		File << mas[i] << endl;
	};
	File.close();
}

int FSC(const string& way) {
	string s;
	int count = 0;
	ifstream f(way, ios::in);

	assert(f.is_open() == true);

	if (f.is_open()) {
		while (!f.eof()) {
			count++;//пока файл не закончился читаем строки и увеличиваем счетчик
			getline(f, s);
		}
	}
	return count;
}

void OpenFromFile(double* &mas, int &n, const std::string& way)
{
	ifstream Flic;
	n = 0;
	int i = 0;
	string s;
	Flic.open(way);


	

	if (Flic.is_open())
	{
		for (unsigned i = 0; i < FSC(way)-1; i++)
		{
			Flic >> mas[i];
		}
	};
	n = FSC(way) - 1;
}

