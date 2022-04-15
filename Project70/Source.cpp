
#include <iostream>
#include <fstream>
#include <conio.h>
#include <tchar.h>

using namespace std;

struct s          //���������, ����������� ��������������� � ������������ ��������������
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
	ifstream F; // ������� ���� ��� ������
	F.open("prepod.txt"); //��������� ���� � ����������
	if (F.is_open()) {
		char* str = new char[1000]; // ������ ������������ ������ ���� ����� ���������� ������ �� �����
		int h = 0; // �������� h
		while (!F.eof())//���� ���� ������
		{
			F.getline(str, 1000, '\n'); //������� ������� ����� � �����
			h++;
		}

		F.close(); //��������� ����
		delete str; //������� str �.� ��� ��� ������ �� �����������
		int n = h / 6; // ����� �� 6 ����� ������ ������� � ��� ����� �������������� �.� ��� ������� ������������� �������� 6 ����� � �����������(�� ���� ������� ���-�� ������� � �.�)

		s* prepods = new s[n]; //���������� ��������� ������������ �������	


		F.open("prepod.txt");// ��������� ���� ��� ������ 
		for (int i = 0; i < n; i++)// ������ ���� ��� ������ � ���������
		{
			F.getline(prepods[i].date, 50); // ������ � �����
			F.getline(prepods[i].time, 50); //������ � �������� �������
			F.getline(prepods[i].pred, 50);//������ � ��������� ��������
			F.getline(prepods[i].vid, 50);//������ � ����� �������
			F.getline(prepods[i].kab, 50); //������ �  ������� ��������
			F.getline(prepods[i].fio, 50);//������ � �.�.� �������������
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
	int u = 0; //�������� ����� �� ���� ������
	cout << "�������� �������������" << endl;
	for (int i = 0; i < n; i++)
	{

		cout << i << ')' << prepods[i].fio << endl; //������� �������������� ����� ������� ������ ��� ���������� ��������
	}
	cin >> u;//������ ����� ������������� � ������
	int j = 0;
	for (int i = 0; i < n; i++)//����������� ����� ����� ���������� �������������
	{

		if (!(strcmp(prepods[u].fio, prepods[i].fio)))
		{
			j++;

		}
	}
	cout << "����� ��� � ������ = " << j << endl;


}
void zanyatiya(struct s* prepods, int n)
{
	cout << "������� ����:" << endl;// ������� ������ ���� ������� �� ���� 
	cout << "�������� ���� � 11.06.16 �� 17.06.16: ";
	char z[30];
	cin >> z;// ������ ���� ������� ���  �����
	for (int i = 0; i < n; i++)//������� ���������� �� ����
	{

		if (!(strcmp(z, prepods[i].date)))
		{
			cout << "������� � ��� ������� : " << prepods[i].pred << "  " << prepods[i].vid << endl;
		}

	}
}
void lekc(struct s* prepods, int n)
{
	int g = 0;
	char d[] = "������";
	for (int i = 0; i < n; i++)// ������� ���-�� ������ ����� �� ��� �����
	{


		if (!(strcmp(d, prepods[i].vid)))
		{
			g++;
		}

	}
	cout << "���������� ������: " << g;
}
