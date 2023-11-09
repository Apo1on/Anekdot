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
// заполняет массив случайными числами
void ZapolnenieMas(double *mas, const int& n, const int& min, const int& max)
{
	for (int i = 0; i< n; i++)
	{
		
		mas[i] = 1.0 * rand() / RAND_MAX * max + min;
	}
}

// считает сумму всех элементов
double Summ(const double *mas, const int& n)
{
	double summa =0.0;
	// идет по массиву складывая значения		
	for (int i = 0; i < n; i++)
	{
		// сумма вычисляется по формуле 
		// сумма = (модуль числа - само число это все в квадрате) + сумма предыдущих действий
		summa = summa + pow(sqrt(abs(mas[i])) - mas[i], 2);
			
	};
	return summa;
}

// сохранение в файл
// не важно какое название оно в любом случае сгенерируется
void SaveInFile(const double* mas, int n, const std::string& way)
{
	ofstream File;
	File.open(way);
	// вывод в файл
	for(int i = 0; i<n; i++)
	{
		File << mas[i] << endl;
	};
	// сохранение файла
	File.close();
}

// Find String - Count очередной строка - счетчик
// считается количество строк и возвращает их количество
int FSC(const string& way) {
	string s;
	int count = 0;
	ifstream f(way, ios::in);
	// открывает матрицу

	if (f.is_open()) {
		while (!f.eof()) {
			count++;//пока файл не закончился читаем строки и увеличиваем счетчик
			getline(f, s);
		}
	}
	return count;
}


// выгружает из файла данные
int OpenFromFile(double* &mas, int &n, const std::string& way)
{
	ifstream Flic;
	n = 0;
	int i = 0;
	string s;
	Flic.open(way);

	// проверяет существует ли файл или нет
	if (Flic.is_open())
	{
		// выгружает значения строк в массив
		for (unsigned i = 0; i < FSC(way) - 1; i++)
		{
			Flic >> mas[i];
		}
		n = FSC(way) - 1;
		return 0;
	} 
	// в случае если нет, выводит ошибку что файла нет
	else
	{
		return -1;
	};

}

