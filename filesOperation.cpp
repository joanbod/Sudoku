#include<iostream>
#include<iomanip>
#include<random>
#include<windows.h>
#include<fstream>
#include<string>
#include"header.h"

using namespace std;

/*Zapis do pliku w trakcie gry z menu podrêcznego.*/
void saveToFile(int tab[][10])
{
	string fileName{};
	cout << "		Podaj nazwe pliku: ";
	cin >> fileName;

	/*W przypadku, kiedy u¿ytkownik nie poda rozszerzenia program automatycznie je dodaje.*/
	if (fileName.find(".txt") == string::npos)
		fileName += ".txt";

	ofstream plik;
	plik.open(fileName);

	if (plik.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				/*Dzieli kolumny, aby ich zapis by³ przejrzysty.*/

				if (j % 3 == 0)
					plik << tab[i][j] << " | ";
				else
					plik << tab[i][j] << " ";
			}

			/*Wyœwietla 9 mniejszych kwadratów oddzielonych poziom¹ lini¹.*/

			if (i % 3 == 0)
				plik << "\n  -------------------------" << endl;
			else
				plik << endl;
		}
	}
	else
		cout << "Wystapil blad przy otwieraniu pliku." << endl;

	plik.close();
}

/*Zapisuje szablon planszy wraz z rozwi¹zaniem do pliku.*/
void saveEmptySudoku(int tab[][10], int qfr)
{
	int sudoku[10][10]{ ' ' };

	/*Tworzy tablicê, która bêdzie wyœwietla³a tylko okreœlone wartoœci.*/
	createTable(10, 10, sudoku);

	cout << endl;
	/*Wype³niam szablon.*/
	for (int i = 1; i < 10; i++)
	{
		for (int k = 0; k < qfr; k++)
		{
			int j = randomNumber(1, 9);
			while (sudoku[i][j] != 0)		
				j = randomNumber(1, 9);
			sudoku[i][j] = tab[i][j];
		}
	}

	/*Zapisanie do pliku niewype³nionej planszy oraz rozwi¹zania.*/
	string fileName{};
	cout << "		Podaj nazwe pliku: ";
	cin >> fileName;

	if (fileName.find(".txt") == string::npos)
		fileName += ".txt";

	ofstream plik;
	plik.open(fileName, ios::app);

	if (plik.is_open())
	{
		plik << "Szablon: " << endl;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (j % 3 == 0)
					plik << sudoku[i][j] << " | ";
				else
					plik << sudoku[i][j] << " ";
			}

			if (i % 3 == 0)
				plik << "\n  -------------------------" << endl;
			else
				plik << endl;
		}

		plik << endl;

		plik << "Rozwi¹zanie: " << endl;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j % 3 == 0)
					plik << tab[i][j] << " | ";
				else
					plik << tab[i][j] << " ";
			}
			if (i % 3 == 0)
				plik << "\n  -------------------------" << endl;
			else
				plik << endl;
		}
		cout << "		Plik utworzony." << endl;
	}
	else
		cout << "Wystapil blad przy otwieraniu pliku." << endl;

	plik.close();
}

/*Zapis wyników do pliku.*/
void saveScores(float time)
{
	string name{};
	static int lp{1};
	cout << "		Podaj nazwe uzytkownika: " ;
	cin >> name;

	ofstream plik;
	plik.open("listawynikow.txt", ios::app);

	if (plik.is_open())
	{
		plik << '\n' << lp << ") " << name << " czas: " << time << endl;
		lp++;
	}
	else
		cout << "Wystapil blad przy otwieraniu pliku." << endl;

	plik.close();
	/*Mo¿liwoœæ rozwoju ustawienia wed³ug czasu, poziomu trudnoœci w tym pliku.*/
	//Zrobi³abym to na wektorach. ?? 
	//Tablica wektorów pobieram poprzednie wyniki i dodaje nowe. z poziomem trudnoœci i czasem.??
	//zapis do pliku od góry poziomy trudnoœci a nastepnie wed³ug czasu.
}

/*Pokazuje liste z wynikami.*/
void showScores()
{
	bool ifFail{};
	ifstream plik;
	plik.open("listawynikow.txt");
	int c{ 1 };
	do 
	{
		cout << "\n Lista wynikow: \n";
		if (plik.is_open())
		{
			string linia{};

			while (!plik.eof())
			{
				getline(plik, linia);
				cout << linia;
				cout << endl;
			}

			plik.seekg(0, ios::beg);
		}
		else
			cout << "Wystapil blad przy otwieraniu pliku." << endl;

		cout << "\n\nAby powrocic do menu wpisz 0."<< endl;
		do
		{
			cin >> c;
			ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
			cin.clear();    //czyœci logi b³êdów
			cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

		} while (ifFail == true);
	} while (c == 1);

	

	plik.close();
}