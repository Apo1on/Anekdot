// author Evgeniy Afanasev

#include <iostream>				// модуль вывода
#include <clocale>				// модуль перевода
#include <cmath>				// математический модуль
#include <string>				// модуль строк
#include <fstream>				// модуль файла
#include <math.h>
#include <time.h>
#include <random>
#include <fstream>				// модуль файла

// Заносит значение в массив
double Reshenie (double n); 
// считает массив
double Summ(const double *mas, const int& n);
// заполняет массив
void ZapolnenieMas(double *mas, const int& n, const int& min, const int& max);
// сохраняет массив в файл
void SaveInFile(const double* mas, int n, const std::string& way);
// считывает данные с массива
int OpenFromFile(double* &mas, int &n, const std::string& way);
// узнает количество элементов с файле
int FSC(const std::string& way);
