#include<iostream>
#include<iomanip>
#include<random>
#include<windows.h>
#include<fstream>
#include<string>
#include<chrono>
#include"header.h"

using namespace std;


/*Pokazuje tablicê.*/
void showTable(int x, int y, int tab[][10])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			/*Dzieli kolumny, aby ich wyœwietlenie by³o przejrzyste*/
			if (j == 0)
				cout <<"		" << tab[i][j] << " | ";
			else if (j % 3 == 0)
				cout << tab[i][j] << " | ";
			else
				cout << tab[i][j] << " ";
		}

		/*Odznacza poziom¹ lini¹ 9 mniejszych kwadratów*/

		if (i % 3 == 0)
			cout << "\n		  -------------------------" << endl;
		else
			cout << endl;
	}
}

//Tworzy pust¹ tablicê o podanych wymiarach z indeksami
void createTable(int x, int y, int tab[][10])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			/*Numeracja indeksów*/
			if (i == 0)
				tab[i][j] = j;
			else if (j == 0)
				tab[i][j] = i;
		}
	}
}

//Wype³nia tablicê sudoku
void randomFilling(int tab[][10])
{
	/*NARZÊDZIE DO RANDOMOWEGO GENEROWANIA LICZB*/
	//W dalszej czêœci programu posiadam funkcjê, która odpowiada za tworzenie losowych liczb, ale pozostawiam tutaj jako przypominajkê o mo¿liwej zmianie.
	//random_device device;
	//mt19937 generator(device());
	//uniform_int_distribution <int> distribution(1, 9);

	/*TABLICA Z WARTOŒCIAMI, KTÓRYMI WYPE£NIE TABELKÊ SUDOKU*/
	int fill[9] = { 9,2,3,4,5,6,1,8,7 };	
	//Jeœli chcia³abym bardziej urozmaiciæ mogê dodaæ tutaj funkcjê, ¿e tablica fill
	// bêdzie wype³niana w koljenoœci losowej. Dlatego dodane narzêdzie do liczb losowych. 
	

	/*WARTOŒCI ROZPOCZYNAJ¥CE KA¯DY Z WARUNKÓW*/
	int k_0 = 0;
	int k_1 = 1;
	int k_2 = 2;
	int k_3 = 3;
	int k_4 = 4;
	int k_5 = 5;
	int k_6 = 6;
	int k_7 = 7;
	int k_8 = 8;

	//Sposób wype³niania mo¿e nie jest najoptymalniejszy,
	//ale polega na przemieszczaniu siê do kolnych kwadracików 3x3 w odpowiedni¹ komórkê
	//w celu wype³nienia ich koljn¹ wartoœci¹
	//zastosowa³am sposób w jaki tworzy siê sudoku na papierze.
	//Kiedy wystêpuje w okreœlonym miejscu np dolnym prawym rogu kwadracika 3x3 to wypelniam wartoscia poczatkowa
	// i powiekszam ja o jeden

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (i % 3 == 1 && j % 3 == 1)
			{
				tab[i][j] = fill[k_0];
				k_0++;
			}

			else if (i % 3 == 0 && j % 3 == 0)
			{
				if (k_1 > 8)
				{
					tab[i][j] = fill[k_1 - 9];
				}
				else
				{
					tab[i][j] = fill[k_1];
				}
				k_1++;
			}

			else if (i % 3 == 2 && j % 3 == 1)
			{
				if (k_2 > 8)
				{
					tab[i][j] = fill[k_2 - 9];
				}
				else
				{
					tab[i][j] = fill[k_2];
				}
				k_2++;
			}
			else if (i % 3 == 1 && j % 3 == 2)
			{
				if (k_3 > 8)
				{
					tab[i][j] = fill[k_3 - 9];
				}
				else
				{
					tab[i][j] = fill[k_3];
				}
				k_3++;
			}
			else if (i % 3 == 0 && j % 3 == 2)
			{
				if (k_4 > 8)
				{
					tab[i][j] = fill[k_4 - 9];
				}
				else
				{
					tab[i][j] = fill[k_4];
				}

				k_4++;
			}
			else if (i % 3 == 2 && j % 3 == 0)
			{
				if (k_5 > 8)
				{
					tab[i][j] = fill[k_5 - 9];
				}
				else
				{
					tab[i][j] = fill[k_5];
				}
				k_5++;
			}
			else if (i % 3 == 1 && j % 3 == 0)
			{
				if (k_6 > 8)
				{
					tab[i][j] = fill[k_6 - 9];
				}
				else
				{
					tab[i][j] = fill[k_6];
				}
				k_6++;
			}
			else if (i % 3 == 0 && j % 3 == 1)
			{
				if (k_7 > 8)
				{
					tab[i][j] = fill[k_7 - 9];
				}
				else
				{
					tab[i][j] = fill[k_7];
				}
				k_7++;
			}
			else if (i % 3 == 2 && j % 3 == 2)
			{
				if (k_8 > 8)
				{
					tab[i][j] = fill[k_8 - 9];	//ustawione, aby nie wychodzi³o poza zakres tabilcy
				}
				else
				{
					tab[i][j] = fill[k_8];
				}
				k_8++;
			}
		}
	}
}
/*Deklaracja tablicy.*/
void showEnd(std::chrono::duration<float> time, int qfr);

/*TABLICA PRZEDSTAWIJ¥CA TYLKO OKREŒLONE WARTOŒCI*/
void sudokuTable(int tab[][10], int qfr)	//qfr w zale¿noœci od poziomu trudnoœci jest ró¿ne, okreœla ono ile bêdzie wyœwietlonych liczb w ka¿dej z linii
{
	/*Tablica pierwsza ma niewype³nion¹ planszê sudoku. Tablica druga na zapisanie miejsc ju¿ uzupe³nionych elementów tablicy(podanych z góry).*/
	int sudoku[10][10]{ ' ' };
	int tabStalych[10][10]{ ' ' };

	createTable(10, 10, sudoku);
	createTable(10, 10, tabStalych);
	cout << endl;

	for (int i = 1; i < 10; i++)
	{
		for (int k = 0; k < qfr; k++)
		{
			/*Losowe wype³nianie planszy sudoku.*/
			int j = randomNumber(1, 9);
			while (sudoku[i][j] != 0)		//w przypadku gdyby wylosowa³o t¹ sam¹ liczbê
				j = randomNumber(1, 9);
			sudoku[i][j] = tab[i][j];
			tabStalych[i][j] = 1;
			/*tabStalych bêdzie s³u¿yæ jako pewnego rodzaju blokada, abyy u¿ytkownik nie móg³ zmieniæ wartoœci juz podanej przez program.*/
		}
	}

	/*Znak char cont oznacza kontynuacjê programu.*/
	char cont = 't';
	/*Pocz¹tkowe po³o¿enie na planszy sudoku.*/
	int x{ 1 }, y{ 1 };
	std::chrono::time_point<std::chrono::system_clock> start{};
	start = std::chrono::system_clock::now();
	do
	{
		system("cls");
		showTable(10, 10, sudoku);
		cont = fillTheCell(sudoku, tabStalych, tab, x, y, qfr);
		/*Wykonuje wype³nianie planszy do momentu zwroceniu innej wartosci niz t*/
	} while (cont == 't' || cont == 'T');

	/*Jeœli zwróci 'e' oznacza to koniec gry, ale jako wygran¹.*/
	if (cont == 'e')
	{
		system("cls");

		std::chrono::duration<float> duration = std::chrono::system_clock::now() - start;
		/*Wyœwietlenie koñcowej strony.*/
		showEnd(duration, qfr);
		saveScores(duration.count());
		
		
	}
}

/*Sprawdza czy podana wartoœæ na plansze sudoku jest poprawna, czyli zgodna z plansz¹ pierwotn¹*/
bool checkSudoku(int n, int first[][10], int x, int y)
{
	if (n == first[x][y])
		return true;
	else
		return false;
}

/*Sprawdza czy zosta³a wype³niona ca³a plansza sudoku*/
bool checkIfCompleted(int nchange[][10])
{
	for (int i = 1; i < 10; i++)
	{
		for (int k = 1; k < 10; k++)
		{
			/*Jeœli jest równe 0 to oznacza, ¿e nadal jest pole do wype³nienia.*/
			if (nchange[i][k] == 0)	
				return false;
		}
	}
	return true;
}

/*WYPE£NIANIE KOMÓREK
menu [ 0,0 ]
nchange jest tablic¹, która informuje czy dane pole jest sta³e-1 puste-0 wype³nione-2*/
char fillTheCell(int tab[][10], int nchange[][10], int first[][10], int& x, int& y, int& qfr)
{
	int n{}, i{}, j{};
	/*ifFail do podania b³êdnego typu danych.*/
	bool ifFail{};

	/*Sprawdza czy tablica jest ju¿ wype³niona, co powoduje zakoñczenie programu.*/
	if (checkIfCompleted(nchange))
	{
		cout << endl;
		cout << "		Koniec gry." << endl;
		Sleep(2000);
		return 'e';
	}
	else
	{
		/*Pokazuje ostatnie zmienione pole chyba, ¿e to pierwszy ruch wtedy [1,1]*/
		cout << "		Aktualna pozycja: [" << x << ", " << y << "]" << endl;
		do
		{
			/*Prosty sposób przemieszczania siê podaj¹c jako pierwsz¹ wspó³rzêdn¹ numer wiersza a drug¹ numer kolumny.*/
			cout << "		Podaj wspolrzedne punktu, do ktorego chesz sie przemiescic: ";
			

			/*Poni¿sza instrukcja wystêpuje w celu sprawdzenia powpranoœci wpisanych danych.*/
			do
			{
				cin >> i;
				ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
				cin.clear();    //czyœci logi b³êdów
				cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

			} while (ifFail == true);
			
			cout << "		";
			do
			{
				cin >> j;
				ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
				cin.clear();    //czyœci logi b³êdów
				cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

			} while (ifFail == true);
			
		} while ((i > 9 || i < 0) && (j > 9 || j < 0));


		if (i == 0 && j == 0)
		{
			/*Po wpisaniu [0,0] wyœwietla siê menu "podrêczne".*/
			char wybor{};

			cout << "		MENU: " << endl;
			cout << "		";
			cout << setfill('_') << setw(40) << '_' << endl;
			cout << "		1) Podpowiedz." << endl;
			cout << "		2) Zapisz gre do pliku i zakoncz." << endl;
			cout << "		3) Zakoncz." << endl;
			cout << "		4) Powrot do gry." << endl;

			cout << endl;
			cout << "		Wybierz: ";
			cin >> wybor;

			cout << "		";
			cout << setfill('_') << setw(40) << '_' << endl;

			switch (wybor)
			{
			case '1':
				/*qfr oznacza poziom trudnoœci oraz iloœæ podpowiedzi. Sprawdzam czy u¿ytkownik mo¿e skorzystaæ z podpowiedzi.*/
				if (qfr != 0)
				{

					/*Program losowo wybiera komórkê na planszy, któr¹ ujawnia.*/
					do
					{
						i = randomNumber(1, 9);
						j = randomNumber(1, 9);
					} while (nchange[i][j] != 0);

					tab[i][j] = first[i][j];
					nchange[i][j] = 2;
					qfr--;

					cout << "		Pozostale podpowiedzi: " << qfr << endl;
					Sleep(1500);

					/*Zamieniam x i y , aby wyœwietli³o odpowiedni¹ lokalizacjê.*/
					x = i;
					y = j;

				}
				else
				{
					cout << "		Wykorzystano wszystkie podpowiedzi :(" << endl;
					Sleep(1000);
				}
				return 't';

				break;

			case '2':
				/*Zapis obecnego dostêpu do pliku. Na obecn¹ chwilê nie ma mo¿liwoœci pobrania planszy z pliku i rozwi¹zywania dalej, ale uwzglêdniam to w dalszym rozwoju.*/
				saveToFile(tab);
				return 'n';

				break;

			case '3':
				/*Wy³¹czam grê bez jakiegokolwiek zapisu.*/
				return 'n';
				break;

			case '4':
				/*Powracam do gry.*/
				return 't';
				break;

			default:
				cout << "		Podano zla wartosc." << endl;
				return 't';
				break;
			}
		}
		else
		{

			/*Wprowadzenie wartoœci do pola na planszy.*/
			do
			{
				cout << "		Podaj wartosc: ";
				do
				{
					cin >> n;
					ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
					cin.clear();    //czyœci logi b³êdów
					cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

				} while (ifFail == true);
				
			} while (n < 0 || n >9);

			/*Sprawdza czy dana wartoœæ nie jest podana z góry ("sta³¹"). Jeœli tak to nie ma mo¿liwoœci jej zmiany.*/
			if (nchange[i][j] == 1)
			{
				cout << "		Wartosc stala. Brak mozliwosci zmiany." << endl;
				Sleep(1000);
				x = i;
				y = j;
				
				return 't';
			}
			/*Sprawdza czy podana wartoœæ jest poprawna, czyli taka sama jak w tablicy pierwotnej.*/
			else
			{
				if (checkSudoku(n, first, i, j))
				{
					tab[i][j] = n;
					nchange[i][j] = 2;
					//zamieniam wartosci x i y aby wyœwietla³a siê odpowiednia aktualna pozycja
					x = i;
					y = j;

					return 't';

				}
				else
				{
					cout << "		Podano nieprawidlowa wartosc." << endl;

					Sleep(1000);
					x = i;
					y = j;

					return 't';
				}
			}
			
		}
	}
	
}

/*Funkcja do tworzenia losowych liczb.*/
int randomNumber(int a, int b)
{
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution <int> distribution(a, b);

	return distribution(generator);
}


/*Ekran koñcowy po wygranej grze*/
void showEnd(std::chrono::duration<float> time, int qfr)
{

	system("cls");
	showGameName();

	cout << "		Koniec gry. Gratuluje wygranej. Twoj czas to: " << time.count() << " s \n		Nieuzytych podpowiedzi: " << qfr << endl;
	/*Zapis nazwy u¿ytkownika do pliku wraz z wynikiem.*/

	Sleep(4000);
}