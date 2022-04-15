
#include <iostream>
#include <fstream>
#include <conio.h>
#include <tchar.h>

using namespace std;

struct s          //структура, описывающая данныесвязанные с определенным преподавателем
{
	char date[10], pred[30], time[30], vid[30], kab[4], fio[50];

};
void raspisanie();
void zanyatiya(struct s* prepods, int);
void obem(struct s* prepods, int);
void lekc(struct s* prepods, int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	raspisanie();

	_getch();
	return 0;
}



void raspisanie()
{
	ifstream F; // открыли файл для чтения
	F.open("prepod.txt"); //открываем файл с информацие
	if (F.is_open()) {
		char* str = new char[1000]; // задаем динамическую строку куда будем записывать строки из файла
		int h = 0; // обнуляем h
		while (!F.eof())//пока файл открыт
		{
			F.getline(str, 1000, '\n'); //считаем сколько строк в файле
			h++;
		}

		F.close(); //закрываем файл
		delete str; //удаляем str т.к она нам больше не пригодаться
		int n = h / 6; // делим на 6 чтобы узнать сколько у нас всего преподавателей т.к для каждого преподавателя отведено 6 строк с информацией(по дате времени кол-ву занятий и т.д)

		s* prepods = new s[n]; //объявление структуры динамическим методом	


		F.open("prepod.txt");// открываем файл для чтения 
		for (int i = 0; i < n; i++)// задаем цикл для записи в структуру
		{
			F.getline(prepods[i].date, 50); // строка с датой
			F.getline(prepods[i].time, 50); //строка с временем занятий
			F.getline(prepods[i].pred, 50);//строка с названием предмета
			F.getline(prepods[i].vid, 50);//строка с видом занятий
			F.getline(prepods[i].kab, 50); //строка с  номером кабинета
			F.getline(prepods[i].fio, 50);//строка с Ф.И.О преподавателя
		}


		zanyatiya(prepods, n);
		obem(prepods, n);
		_getch();
		lekc(prepods, n);
		F.close();
	}
}

void obem(struct s* prepods, int n)
{
	int u = 0; //обнуляем чтобы не было мусора
	cout << "Выберите Преподавателя" << endl;
	for (int i = 0; i < n; i++)
	{

		cout << i << ')' << prepods[i].fio << endl; //выводим преподавателей чтобы выбрать одного для дальнейших действий
	}
	cin >> u;//вводим номер преподавателя в списке
	int j = 0;
	for (int i = 0; i < n; i++)//расчитываем объем часов выбранного преподавателя
	{

		if (!(strcmp(prepods[u].fio, prepods[i].fio)))
		{
			j++;

		}
	}
	cout << "Объем пар в неделю = " << j << endl;


}
void zanyatiya(struct s* prepods, int n)
{
	cout << "Введите дату:" << endl;// выводим список всех занятий на дату 
	cout << "Выберите дату с 11.06.16 по 17.06.16: ";
	char z[30];
	cin >> z;// вводим дату которая нам  нужна
	for (int i = 0; i < n; i++)//выводим информацию на дату
	{

		if (!(strcmp(z, prepods[i].date)))
		{
			cout << "Предмет и Вид занятия : " << prepods[i].pred << "  " << prepods[i].vid << endl;
		}

	}
}
void lekc(struct s* prepods, int n)
{
	int g = 0;
	char d[] = "Лекция";
	for (int i = 0; i < n; i++)// выводим кол-во лекций всего за все время
	{


		if (!(strcmp(d, prepods[i].vid)))
		{
			g++;
		}

	}
	cout << "Количество лекций: " << g;
}
