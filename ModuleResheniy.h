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
double Summ(double *mas, int n);
// рандомит число
double RandomChislo();
// заполняет массив
void ZapolnenieMas(double *mas, int n);
// сохраняет массив в файл
void SaveInFile(double* mas, int n, const std::string& way);
// считывает данные с массива
void OpenFromFile(double* &mas, int &n, const std::string& way);
