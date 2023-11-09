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
	
	int min, max;
	cout << "Введите минимальное и максимальное значение: ";
	cin >> min >> max;

	// в зависимости от введенного параметра вернет проверку или нет
	double* mas = new double[n];
	// тестовый массив для ассерта
	double* testMas = new double[3];
		testMas[0] = 4;
		testMas[1] = 9;
		testMas[2] = 16;
		// работа ассерта
		// проверка единственной функции где есть вычисления
		assert(Summ(testMas, n) == 184);
	
	
	cout << Summ(mas, n) << endl;

	string stroka;
	cout << "Введите название файла в который сохранится (без .txt): ";
	cin >> stroka;
	stroka = stroka + ".txt";
	cout << stroka << endl;

	// сохранение в файл
	SaveInFile(mas, n, stroka);
	
	cout << "Введите название файла из которого вернется (без  .txt): ";
	cin >> stroka;
	stroka = stroka + ".txt";

	// вывод из файла
	int flag;
	flag = OpenFromFile(mas, n, stroka);

	// вывод массива из файла
	if (flag == 0)
	{
		for (size_t i = 0; i < n; i++)
		{
			cout << mas[i] << endl;
		}
	}
	else {
		cout << " Ошибка имени файла!!";
	}
}