// author Evgeniy Afanasev
#include <string>				// библеотека строк
#include "ModuleResheniy.h"		// модуль с действиями
#include <cassert>
using namespace std;			// пространоство имен 

//https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

// главная часть
int main(int argc, char* argv[]) {
	int n;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian"); // меняет язык на русский
	if (argc == 2) {
		//argv[0] // имя файла
		n = stoi(argv[1]);
	}
	else {
		// ввод N
		cout << "Введите размер массива:";
		cin >> n;
		cout << endl;
		
	}
	cout << "Проверять ассерт?(0 = да, иные = нет): ";
	int flag; // флаг проверки
	cin >> flag;
	if (flag == 0) {
		n = 3;
	};
	
	int min, max;
	cout << "Введите минимальное и максимальное значение: ";
	cin >> min >> max;

	// в зависимости от введенного параметра вернет проверку или нет
	double* mas = new double[n];
	if (flag == 0)
	{
		mas[0] = 4;
		mas[1] = 9;
		mas[2] = 16;
	}
	else{
		ZapolnenieMas(mas, n,min,max);
	}

	// работа ассерта
	if (flag == 0)
	{
		assert(Summ(mas, n) == 184);
		//assert(Summ(mas, n) == 0);
	};
	
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
	OpenFromFile(mas, n, stroka);

	for (size_t i = 0; i < n; i++)
	{
		cout << mas[i] << endl;
	}
}