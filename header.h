#pragma once

/*Wype³nia planszê sudoku.*/
void randomFilling(int tab[][10]);

/*Pokazuje planszê.*/
void showTable(int x, int y, int tab[][10]);

/*Towrzy pust¹ tablicê na sudoku.*/
void createTable(int x, int y, int tab[][10]);

/*Tu nastêpuje rozwi¹zywanie tablicy sudoku.*/
void sudokuTable(int tab[][10], int qfr);

/*Wype³nia, sprawdza i podpowiada plansze sudoku.*/
char fillTheCell(int tab[][10], int nchange[][10], int first[][10], int& x, int& y, int& qfr);
bool checkSudoku(int n, int first[][10], int x, int y);
bool checkIfCompleted(int nchange[][10]);

/*Losowa liczba.*/
int randomNumber(int a, int b);


/*Zapisuje pust¹ planszê do pliku.*/
void saveEmptySudoku(int tab[][10], int qfr);
void saveToFile(int tab[][10]);
/*Zapisuje wyniki wraz z nazw¹ u¿ytkownika do pliku.*/
void saveScores(float time);
/*Pokazuje wyniki.*/
void showScores();

/*Wyœwietla napis sudoku.*/
void showGameName();
/*Wyœwietla zasady gry.*/
void showGameRules();


/*Funkcja odpowiedzialna za poruszanie siê po programie.*/
int mainMenu();