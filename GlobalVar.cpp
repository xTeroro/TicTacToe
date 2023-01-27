#include "Global"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
using namespace Vars;



// Core Variables of the Game
char Vars::Player,Vars::Opponent;
char Vars::DrawMap[3][3];
int Vars::Map[3][3],Vars::AvailableSpots;

// In-Game Variables
int Vars::ColumnCord, Vars::RowCord, Vars::OpponentCord, Vars::Winner;

// Question Functions
bool Funcs::AskChar(char y, char n, string msg, string error)
{
    string input;
    while (true)
    {
        cout << msg << '\n';
        getline(cin, input);
        cout << '\n';
        if ((input[0] == y || input[0] == y + 32) && input[1] == '\0')
        {
            return true;
        }
        else if ((input[0] == n || input[0] == n + 32) && input[1] == '\0')
        {
            return false;
        }
        else
        {
            cout << error << '\n';
        }
    }
}
int Funcs::Ask3Char(char option_1, char option_2, char r, string msg, string error)
{
    string input;
    while (true)
    {
        cout << msg << '\n';
        getline(cin, input);
        if(input == "Creator?")
        {
            cout << "Teroro";
        }
        cout << '\n';
        if ((input[0] == option_1 || input[0] == option_1 + 32) && input[1] == '\0')
        {
            return 1;
        }
        else if ((input[0] == option_2 || input[0] == option_2 + 32) && input[1] == '\0')
        {
            return 2;
        }
        else if ((input[0] == r || input[0] == r + 32) && input[1] == '\0')
        {
            return 3;
        }
        else
        {
            cout << error << '\n';
        }
    }
}
int Funcs::CheckCord(int Max, string msg, string error)
{
    string input;
    while (true)
    {
        cout << msg << '\n';
        getline(cin, input);
        cout << '\n';
        if (input[0] >= '1' && input[0] <= Max + 48 && input[1] == '\0')
        {
            return input[0] - 49;
        }
        else
        {
            cout << error << '\n';
        }
    }
}

// Resetting Maps Funtions
void Funcs::ClearMap()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Map[i][j] = 0;
        }
    }
}
void Funcs::ResetDrawMap()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            DrawMap[i][j] = '-';
        }
    }
}

//Random
int Funcs::Random(int max)
{
    srand(time(NULL));
    return rand() % max;
}

// Win Checking
void Funcs::checkkWinner(int Map[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        if(Map[i][0] == Map[i][1] && Map[i][1] == Map[i][2] && Map[i][2] != 0)
        {
            Winner = Map[i][0];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        if(Map[0][i] == Map[1][i] && Map[1][i] == Map[2][i] && Map[2][i] != 0)
        {
            Winner = Map[0][i];
        }
    }
    if(Map[0][0] == Map[1][1] && Map[1][1] == Map[2][2] && Map[2][2] != 0)
    {
        Winner = Map[0][0];
    }
    if(Map[2][0] == Map[1][1] && Map[1][1] == Map[0][2] && Map[0][2] != 0)
    {
        Winner = Map[2][0];
    }
}

// Game Functions
void Funcs::SetUp()
{
    int id;
    id = Ask3Char('X', '0', 'R', "Select your character X or 0 or R(random) : ", "Invalid character, please try again.");
    if (id == 1)
    {
        Player = 'X';
        Opponent = '0';
    }
    else if (id == 2)
    {
        Player = '0';
        Opponent = 'X';
    }
    else
    {
        id = Random(2) + 1;
        if (id == 1)
        {
            Player = 'X';
            Opponent = '0';
        }
        else
        {
            Player = '0';
            Opponent = 'X';
        }
        cout << "Player character is: " << Player << '\n'
             << "Opponent character is: " << Opponent << "\n\n";
    }
    ClearMap();
    ResetDrawMap();
    AvailableSpots = 9;
    Winner = -1;
}
void Funcs::Draw()
{
    cout << "  " << 1 << " " << 2 << " " << 3 << '\n';
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; j++)
        {
            cout << DrawMap[i][j] << ' ';
        }
        cout << '\n';
    }
}
