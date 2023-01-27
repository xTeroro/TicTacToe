#include <iostream>
#include "Global"

using namespace std;
using namespace Funcs;
using namespace Vars;
using namespace BotF;

void SinglePlayerGame()
{
    SetUp();
    bool R1=true;
    while (true)
    {
        if(Opponent == 'X' && R1 == true)
        {
            R1 = false;
            cout<<"AI Turn! \n";
            BestMove();
            cout << "The Opponent Chose: " << I + 1 << " and " << J + 1 << '\n';
            AvailableSpots--;
        }

        Draw();
        cout << '\n';

        // Player Turn

        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if (Map[ColumnCord][RowCord] == 0)
            {
                Map[ColumnCord][RowCord] = 1;
                DrawMap[ColumnCord][RowCord] = Player;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n\n";
            }
        }
        AvailableSpots--;


        // Check for Win            Draw();
            cout << '\n';
        checkkWinner(Map);
        if(Winner == 1)
        {
            cout<<"Player Won! \n";
            break;
        }else if(Winner == 2)
        {
            cout<<"Computer Won! \n";
            break;
        }else if(AvailableSpots == 0)
        {
            cout<<"Draw! \n";
            break;
        }


        // AI Turn

        cout<<"AI Turn! \n";

        BestMove();
        cout << "The Opponent Chose: " << I + 1 << " and " << J + 1 << '\n';
        AvailableSpots--;


        // Check for Win

        checkkWinner(Map);
        if(Winner == 1)
        {
            cout<<"Player Won! \n";
            break;
        }else if(Winner == 2)
        {
            cout<<"Computer Won! \n";
            break;
        }else if(AvailableSpots == 0)
        {
            cout<<"Draw! \n";
            break;
        }
    }
    if (AskChar('Y', 'N', "Do you want to play again? (Y/N)", "Invalid character, please try again.") == true)
    {
        SinglePlayerGame();
    }
}

void MultiPlayerGame()
{
    SetUp();
    bool R1=true;
    while (true)
    {
        if(Opponent == 'X' && R1 == true)
        {
            R1 = false;
            cout<<"Player 2 Turn! \n";

        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if (Map[ColumnCord][RowCord] == 0)
            {
                Map[ColumnCord][RowCord] = 2;
                DrawMap[ColumnCord][RowCord] = Opponent;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n\n";
            }
        }
        AvailableSpots--;

        cout << "Player 2 Chose: " << ColumnCord << ' ' << RowCord << '\n';
        }
        Draw();
        cout << '\n';
        cout<<"Player 1 Turn! \n";
        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if(Map[ColumnCord][RowCord] == 0)
            {
                Map[ColumnCord][RowCord] = 1;
                DrawMap[ColumnCord][RowCord] = Player;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n\n";
            }
        }
        AvailableSpots--;

        cout << "Player 1 Chose: " << ColumnCord << ' ' << RowCord << '\n';
    
        // Player 2 Turn

        Draw();
        cout << '\n';

        cout<<"Player 2 Turn! \n";

        while (true)
        {
            ColumnCord = CheckCord(3, "Enter the row coordinate (from up to down): ", "Invalid coordinate, please try again.");
            RowCord = CheckCord(3, "Enter the column coordinate (from left to right): ", "Invalid coordinate, please try again.");
            if (Map[ColumnCord][RowCord] == 0)
            {
                Map[ColumnCord][RowCord] = 2;
                DrawMap[ColumnCord][RowCord] = Opponent;
                break;
            }
            else
            {
                cout << "T~his (but a scratch) coordinate is already taken, please try again \n\n";
            }
        }
        AvailableSpots--;

        cout << "Player 2 Chose: " << ColumnCord << ' ' << RowCord << '\n';


        // Check for Win

        checkkWinner(Map);
        if(Winner == 1)
        {
            cout<<"Player 1 Won! \n";
            break;
        }else if(Winner == 2)
        {
            cout<<"PLayer 2 Won! \n";
            break;
        }else if(AvailableSpots == 0)
        {
            cout<<"Draw! \n";
            break;
        }
    }
    if (AskChar('Y', 'N', "Do you want to play again? (Y/N)", "Invalid character, please try again.") == true)
    {
        MultiPlayerGame();
    }
}

int main()
{
    cout << "=======\n|| B ||\n|| Y ||\n||   ||\n|| T ||\n|| E ||\n|| R ||\n|| O ||\n|| R ||\n|| O ||\n======= \n\n\n\n";
    cout << "Welcome to Tic Tac Toe!\n\n";
    if (AskChar('C', 'F', "Do you want to play against the computer or a friend? (C/F)", "Please enter a valid input."))
    {
        cout << "You chose to play against the computer.\n\n";
        SinglePlayerGame();
    }
    else
    {
        cout << "You chose to play against a friend.\n\n";
        MultiPlayerGame();
    }

    // Exit Sequence
    cout << "The Program will automatically exit when the timer reaches 0." << '\n';
    for (int i = 5; i > 0; i--)
    {
        cout << i << '\n';
	char ch = getchar();
        // Sleep(1000);
    }
}
