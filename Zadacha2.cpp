// author Evgeniy Afanasev
#include <string>				// библеотека строк
#include "ModuleResheniy.h"		// модуль с действиями
using namespace std;			// пространоство имен 

//https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

// главная часть
int main() {
	int n;
	setlocale(LC_ALL, "Russian"); // меняет язык на русский

	cout << "Введите размер массива:";
	cin >> n;
	cout << endl;

	double* mas = new double[n];

	ZapolnenieMas(mas, n);


	cout << Summ(mas, n) << endl;

	string stroka;


	cout << "Введите название файла в который сохранится (без .txt): ";
	cin >> stroka;
	stroka = stroka + ".txt";
	cout << stroka << endl;

	SaveInFile(mas, n, stroka);

	cout << "Введите название файла из которого вернется (без  .txt): ";
	cin >> stroka;
	stroka = stroka + ".txt";
	cout << stroka << endl;
	OpenFromFile(mas, n, stroka);

	for (int i = 0; i < n; i++)
	{
		cout << stroka << endl;
	}
}