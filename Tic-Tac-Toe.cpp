#include <iostream>
using namespace std;
bool checkRows(char symbol);
bool checkColums(char symbol);
bool checkDiagonals(char symbol);
bool isWinner(char symbol);
void takeInputPlayer1();
void takeInputPlayer2();
void showBoard();
void clear();
int count = 0;
const int SIZE = 3;
char board[SIZE][SIZE];
int rows, col;
int main()
{
    system("cls");

    takeInputPlayer1();
}
void clear()
{
    system("pause");
    system("cls");
}
void showBoard()
{
    char ch = 'A';
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\t" << i;
    }
    cout << endl;
    cout << "\t";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "--------";
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {

        cout << ch;

        for (int j = 0; j < SIZE; j++)
        {
            cout << "\t|" << board[i][j];
        }
        cout << "\t|";
        cout << "\b";
        cout << endl;
      
        cout << "\t";
        for (int i = 0; i < SIZE; i++)
        {
            cout << "--------";
        }

        cout << endl;
        ch++;
    }
}
void takeInputPlayer1()
{
    showBoard();
    string input;
    cout << "Choose a Position as Player 1 i.e. A0 : ";
    cin >> input;

    if (input[0] == 'A')
    {
        rows = 0;
    }
    else if (input[0] == 'B')
    {
        rows = 1;
    }
    else if (input[0] == 'C')
    {
        rows = 2;
    }
    else
    {
        cout << "Invalid Input.\nTry Again." << endl;
        clear();
        takeInputPlayer1();
    }

    if (input[1] == '0')
    {
        col = 0;
    }
    else if (input[1] == '1')
    {
        col = 1;
    }
    else if (input[1] == '2')
    {
        col = 2;
    }
    else
    {
        cout << "Invalid Input.\nTry Again." << endl;
        clear();
        takeInputPlayer1();
    }
    if (board[rows][col] != '0' && board[rows][col] != 'X')
    {
        board[rows][col] = '0';
    }
    else
    {
        cout << "You cannot overwrite.\nTry Again." << endl;
        clear();
        takeInputPlayer1();
    }
    system("cls");
    if (isWinner('0'))
    {
        showBoard();
        cout << "Player 1 wins ." << endl;
        cout << "Thanks For Palying." << endl;
        clear();
        exit(0);
    }
    else if (count >= 9)
    {
        showBoard();
        cout << "Draw." << endl;
        cout << "Thanks For Playing." << endl;
        clear();
        exit(0);
    }
    takeInputPlayer2();
}
void takeInputPlayer2()
{
    showBoard();
    string input;
    cout << "Choose a Position as Player 2 i.e. A0 : ";
    cin >> input;

    if (input[0] == 'A')
    {
        rows = 0;
    }
    else if (input[0] == 'B')
    {
        rows = 1;
    }
    else if (input[0] == 'C')
    {
        rows = 2;
    }
    else
    {
        cout << "Invalid Input.\nTry Again." << endl;
        clear();
        takeInputPlayer2();
    }

    if (input[1] == '0')
    {
        col = 0;
    }
    else if (input[1] == '1')
    {
        col = 1;
    }
    else if (input[1] == '2')
    {
        col = 2;
    }
    else
    {
        cout << "Invalid Input.\nTry Again." << endl;
        clear();
        takeInputPlayer2();
    }
    if (board[rows][col] != '0' && board[rows][col] != 'X')
    {
        board[rows][col] = 'X';
    }
    else
    {
        cout << "You cannot overwrite.\nTry Again." << endl;
        clear();
        takeInputPlayer2();
    }
    system("cls");
    if (isWinner('X'))
    {
        showBoard();
        cout << "Player 2 wins ." << endl;
        cout << "Thanks For Palying." << endl;
        clear();
        exit(0);
    }
    else if (count >= 9)
    {
        showBoard();
        cout << "Draw." << endl;
        cout << "Thanks For Playing." << endl;
        clear();
        exit(0);
    }
    takeInputPlayer1();
}
bool isWinner(char symbol)
{
    count++;
    if (checkRows(symbol) || checkColums(symbol) || checkDiagonals(symbol))
    {
        return true;
    }
    return false;
}
bool checkRows(char symbol)
{
    for (int i = 0; i < SIZE; i++)
    {
        int count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (symbol == board[i][j])
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
    }
    return false;
}
bool checkColums(char symbol)
{
    for (int i = 0; i < SIZE; i++)
    {
        int count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (symbol == board[j][i])
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
    }
    return false;
}
bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                if (symbol == board[i][j])
                {
                    count++;
                }
            }
        }
    }
    if (count == 3)
    {
        return true;
    }
    count = 0;
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {

            if (i + j == SIZE - 1)
            {
                if (symbol == board[i][j])
                {
                    count++;
                }
            }
        }
    }
    if (count == 3)
    {
        return true;
    }
    return false;
}