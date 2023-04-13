#pragma once

/*Wype�nia plansz� sudoku.*/
void randomFilling(int tab[][10]);

/*Pokazuje plansz�.*/
void showTable(int x, int y, int tab[][10]);

/*Towrzy pust� tablic� na sudoku.*/
void createTable(int x, int y, int tab[][10]);

/*Tu nast�puje rozwi�zywanie tablicy sudoku.*/
void sudokuTable(int tab[][10], int qfr);

/*Wype�nia, sprawdza i podpowiada plansze sudoku.*/
char fillTheCell(int tab[][10], int nchange[][10], int first[][10], int& x, int& y, int& qfr);
bool checkSudoku(int n, int first[][10], int x, int y);
bool checkIfCompleted(int nchange[][10]);

/*Losowa liczba.*/
int randomNumber(int a, int b);


/*Zapisuje pust� plansz� do pliku.*/
void saveEmptySudoku(int tab[][10], int qfr);
void saveToFile(int tab[][10]);
/*Zapisuje wyniki wraz z nazw� u�ytkownika do pliku.*/
void saveScores(float time);
/*Pokazuje wyniki.*/
void showScores();

/*Wy�wietla napis sudoku.*/
void showGameName();
/*Wy�wietla zasady gry.*/
void showGameRules();


/*Funkcja odpowiedzialna za poruszanie si� po programie.*/
int mainMenu();