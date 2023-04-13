#include<iostream>
#include<iomanip>
#include<random>
#include<windows.h>
#include<fstream>
#include<string>
#include <chrono>
#include"header.h"

using namespace std;

/*Wyœwietla stronê g³ówn¹ oraz menu.*/
int mainMenu()
{
	/*Pokazuje nazwê gry.*/
	system("cls");
	showGameName();

	cout << "		" << "MENU: " << endl;
	cout << endl;
	cout << "		" << "1) Rozpocznij gre.\n";
	cout << "		" << "2) Jak grac?\n";
	cout << "		" << "3) Lista wynikow.\n";
	cout << "		" << "4) Pobierz plansze. \n";
	cout << "		" << "5) Wyjdz z gry.\n";
	cout << endl;

	/*Zmienne niezbêdne w poni¿szym switchu.*/
	int option{}, level{}, number{};
	bool ifFail{};

	/*Tablica przeznaczona do sudoku.*/
	int x{ 10 }, y{ 10 }, tab[10][10]{};

	cout << "		" << "Wybierz opcje: ";
	do
	{
		cin >> option;
		ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
		cin.clear();    //czyœci logi b³êdów
		cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

	} while (ifFail == true);

	switch (option)
	{
	case 1:
		/*Rozpoczêcie gry.*/
		system("cls");

		showGameName();

		/*Wybór poziomu trudnoœci gry.*/
		cout << "		" << "Poziom trudnosci: " << endl;
		cout << "		" << "1) Latwy.\n";
		cout << "		" << "2) Sredni.\n";
		cout << "		" << "3) Trudny.\n";
		cout << "		" << "4) Wlasny.\n";
		cout << "		" << "5) Wroc do menu.\n"; //tutaj trzeba dac jakis inny numer??
		cout << endl;
		cout << "		" << "Wybierz poziom: ";
		do
		{
			cin >> level;
			ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
			cin.clear();    //czyœci logi b³êdów
			cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

		} while (ifFail == true);

		/*Tworzê tablicê, odpowiednio wype³nion¹.*/
		createTable(x, y, tab);
		randomFilling(tab);

		/*Prze³¹cza na odpowiedni poziom trudnoœci.*/
		switch (level)
		{
		case 1:
			/*Poziom ³atwy. 5 podpowiedzi*/
			sudokuTable(tab, 5);
			return 0;
			break;

		case 2:
			/*Poziom œredni. 3 podpowiedzi*/
			sudokuTable(tab, 3);
			return 0;
			break;

		case 3:
			/*Poziom trudny. 2 podpowiedzi*/
			sudokuTable(tab, 2);
			return 0;
			break;

		case 4:
			do
			{
				cout << "		" << "Podaj ilosc wyswietlancyh liczb w linii: ";
				do
				{
					cin >> number;
					ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
					cin.clear();    //czyœci logi b³êdów
					cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

				} while (ifFail == true);

			} while (number < 1 || number >8);
		
			/*Poziom w³asny, tak dla zabawy*/
			sudokuTable(tab, number);
			return 0;
			break;

		default:
			cout << "Podano zla wartosc." << endl;
			return 1;
			break;
		}

		return level;
		break;

	case 2:
		system("cls");

		showGameName();
		/*Pokazuje zasady gry.*/
		showGameRules();

		cout << "\n\n Aby powrocic do menu glownego podaj liczbe: ";
		do
		{
			cin >> option;
			ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
			cin.clear();    //czyœci logi b³êdów
			cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

		} while (ifFail == true);
		return 1;
		break;

	case 3:
		/*Wyœwietla plik z zapisanymi wynikami.*/
		system("cls");
		showGameName();

		showScores();

		return 3;
		break;

	case 4:
		/*Zapis szablonu planszy i rozwi¹zania do pliku.*/
		system("cls");
		showGameName();

		/*Tutaj u¿ytkownik sam mo¿e podaæ sobie poziom trudnoœci.*/
		do
		{
			cout << "		" << "Podaj ilosc wyswietlancyh liczb w linii: ";
			do
			{
				cin >> number;
				ifFail = cin.fail();    //sprawdza czy zosta³ wpisany odpowiedni typ danych
				cin.clear();    //czyœci logi b³êdów
				cin.ignore(1000, '\n');     //ignoruje 1000 znaków do momentu wciœniêcia entera,

			} while (ifFail == true);
			

		} while (number < 1 || number >8);

		
		createTable(x, y, tab);
		randomFilling(tab);

		/*Zapisuje plik i rozwi¹zanie.*/
		saveEmptySudoku(tab, number);

		return 4;
		break;

	case 5:
		/*Koniec gry.*/
		cout << "Koniec gry. " << endl;
		Sleep(2000);
	
		return 0;
		break;

	default:
		cout << "Zly wybor.\n";
		Sleep(2000);
		return 1;

		break;
	}
}

/*Wyœwietla nazwê gry- SUDOKU*/
void showGameName()
{
	cout << endl << endl;
	cout << "		" << static_cast<char>(0xC9) << static_cast<char>(0xCD) << static_cast<char>(0xCD) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0XBB) << static_cast<char>(0xCD) << static_cast<char>(0xBB) << ' ' << static_cast<char>(0xC9) << static_cast<char>(0xCD) << static_cast<char>(0xBB) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xC9) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << endl;
	cout << "		" << static_cast<char>(0xBA) << ' ' << ' ' << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << endl;
	cout << "		" << static_cast<char>(0xC8) << static_cast<char>(0xCD) << static_cast<char>(0xBB) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << endl;
	cout << "		" << ' ' << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xCC) << static_cast<char>(0xCD) << static_cast<char>(0xBC) << ' ' << static_cast<char>(0xBA) << ' ' << static_cast<char>(0xBA) << endl;
	cout << "		" << static_cast<char>(0xCD) << static_cast<char>(0xCD) << static_cast<char>(0xBC) << ' ' << static_cast<char>(0xC8) << static_cast<char>(0xCD) << static_cast<char>(0xC8) << ' ' << static_cast<char>(0XBC) << static_cast<char>(0xCD) << static_cast<char>(0XBC) << ' ' << static_cast<char>(0xC8) << static_cast<char>(0xCD) << static_cast<char>(0xBC) << ' ' << static_cast<char>(0xBC) << ' ' << static_cast<char>(0xC8) << ' ' << static_cast<char>(0xC8) << static_cast<char>(0xCD) << static_cast<char>(0xC8) << endl;
	cout << setfill('_') << setw(68) << ' ' << endl;
	cout << endl << endl;
}

/*Wyœwietla zasady gry oraz sposób dzia³ania w programie.*/
void showGameRules()
{
	cout << "		" << "ZASADY SUDOKU: \n" << endl;
	cout << "		" << "Plansza jest podzielona na dziewiec identycznych kwadratow 3 x 3 -\n		w kazdym z nich znajduje sie dziewiec komorek. " << endl;
	cout << "		" << "Nalezy wypelnic wszystkice komorki planszy cyframi od 1 do 9.\n";
	cout << "		" << "W kazdym wierszu i kazdej kolumnie oraz w kazdym z kwadratow 3 x 3\n		dana cyfra moze wystepowac jedynie raz." << endl;

	cout << endl << endl;
	cout << "		" << "JAK GRAC?\n" << endl;
	cout << "		" << "Po rozpoczeciu gry wyskakuje wybor poziomu trudnosci. \n\n		Poziom latwy:\n		5 podpowiedzi \n\n		Poziom sredni:\n		3 podpowiedzi\n\n		Poziom trudny:\n		1 podpowiedz\n\n		Nastepnie wyswietla sie odpowiednia plansza,\n		po ktorej mozemy przemieszczac sie podajac wspolrzedne wiersza oraz kolumny komorki planszy,\n		do ktorej chcemy sie dostac.\n\n		Na przyklad chcemy sie dostac do pola w wierszu 3 i kolumnie 4,\n ";
	cout << "		" << "wiec w ponizszym poleceniu podamy najpierw numer wiersza nastepnie numer kolumny.\n";
	cout << "		" << "Podaj wspolrzedne punktu, do ktorego chesz sie przemiescic: [3, 4]\n\n		Program wyswietla nam biezaca pozycje na planszy.\n		Nastepnie podajemy wartosc w danej komorce,\n		jesli sie pomylilismy mozemy wstawic 0 wtedy nie zachodzi zadna zmiana." << endl;
	cout << endl;

	cout << "\n		" << "Jesli w trakcie gry chcielibysmy wyjsc lub uzyc dodatkowych opcji w oknie:\n		\"Podaj wspolrzedne punktu, do ktorego chesz sie przemiescic: \" \n		podajemy wspolrzedne [0, 0] i uruchomimy nastepujace menu.\n";
	cout << "\n		" << "MENU: " << endl;

	cout << "		" << "1) Podpowiedz." << endl;
	cout << "		" << "2) Zapisz gre do pliku i zakoncz." << endl;
	cout << "		" << "3) Zakoncz." << endl;
	cout << "		" << "4) Powrot do gry." << endl;
	cout << "\n		" << "Opcja 1:\n		Pozwala na uzycie podpowiedzi ich ilosc jest zalezna od wybranego poziomu.\n\n		Opcja 2:\n		Pozwala na zapisanie gry do pliku.\n\n		Opcja 3:\n		Konczy gre.\n\n		 Opcja 4:\n		Powraca do gry.\n ";
}

