#include <iostream>
#include <stdlib.h>
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
    int count1=0;

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
    // HANDLE l =GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(l,1);
    if(count1==0){
    system("Color 01");
    }
    
    else if(count1==9){
    system("Color 03");
    }
    else if(count1==8){
    system("Color 04");
    }
    else if(count1==7){
    system("Color 0D");
    }
    else if(count1==6){
    system("Color 01");
    }
    else if(count1==5){
    system("Color 0B");
    }
    else if(count1==4){
    system("Color 08");
    }
    else if(count1==3){
    system("Color 09");
    }
    else if(count1==2){
    system("Color 0A");
    }else if(count1==1){
    system("Color 0B");
    }else{
            system("Color 01");
            count1=0;

    }
    count1++;
     cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<"\n";
    cout << "*********"<<" "<< "*"<<" "<<"*******"<<" "<<"*********"<<" "<<"********"<<" "<<"*******"<<" "<<"*********"<<" "<<"*********"<<" "<<"*********"<<"\n";
    cout << "    *    "<<" "<< "*"<<" "<<"*      "<<" "<<"    *    "<<" "<<"*      *"<<" "<<"*      "<<" "<<"    *    "<<" "<<"*       *"<<" "<<"*        "<<"\n";
    cout << "    *    "<<" "<< "*"<<" "<<"*      "<<" "<<"    *    "<<" "<<"********"<<" "<<"*      "<<" "<<"    *    "<<" "<<"*       *"<<" "<<"*********"<<"\n";
    cout << "    *    "<<" "<< "*"<<" "<<"*      "<<" "<<"    *    "<<" "<<"*      *"<<" "<<"*      "<<" "<<"    *    "<<" "<<"*       *"<<" "<<"*        "<<"\n";
    cout << "    *    "<<" "<< "*"<<" "<<"*******"<<" "<<"    *    "<<" "<<"*      *"<<" "<<"*******"<<" "<<"    *    "<<" "<<"*********"<<" "<<"*********"<<"\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<"\n";
   
   
    // HANDLE m =GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(l,12);

    cout<< "\n                        0     1     2 "<<"\n";
    cout<< "                     __________________"<<"\n";
    cout<< "                    |      |     |     |"<<"\n";
    cout<< "               A    |  "<<board[0][0]<<"   |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  |"<<"\n";
    cout<< "                    |______|_____|_____|"<<"\n";
    cout<< "                    |      |     |     |"<<"\n";
    cout<< "               B    |  "<<board[1][0]<<"   |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  |"<<"\n";
    cout<< "                    |______|_____|_____|"<<"\n";
    cout<< "                    |      |     |     |"<<"\n";
    cout<< "               C    |  "<<board[2][0]<<"   |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  |"<<"\n";
    cout<< "                    |______|_____|_____|"<<"\n"<<endl;
    
}
void takeInputPlayer1()
{
    showBoard();
    string input;
    cout << "Choose a Position as Player 'O' i.e. A0 : ";
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
    if (board[rows][col] != 'O' && board[rows][col] != 'X')
    {
        board[rows][col] = 'O';
    }
    else
    {
        cout << "You cannot overwrite.\nTry Again." << endl;
        clear();
        takeInputPlayer1();
    }
    system("cls");
    
    if (isWinner('O'))
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
    cout << "Choose a Position as Player 'X' i.e. A0 : ";
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
    if (board[rows][col] != 'O' && board[rows][col] != 'X')
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