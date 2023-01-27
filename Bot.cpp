#include "Global"
#include <climits>
#include <iostream>

using namespace Vars;
using namespace Funcs;
using namespace std;
using namespace BotF;

// Vars for MiniMax and BestMove

int BotF::I,BotF::J;



int MiniMax(int Board[3][3], int depth, bool isMaximizing)
{
    //Check if anybody won
    checkkWinner(Board);
    if (Winner == 1)
    {
        Winner = -1;
        return -10;
    }
    else if (Winner == 2)
    {
        Winner = -1;
        return 10;
    }
    else if (AvailableSpots == 0)
    {
        Winner = -1;
        return 0;
    }
    if (isMaximizing == true)
    {
        int bestScore = INT_MIN;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(Board[i][j] == 0)
                {
                    Board[i][j] = 2;
                    AvailableSpots--;
                    int score = MiniMax(Board, depth + 1, false);
                    AvailableSpots++;
                    Board[i][j] = 0;
                    bestScore = max(score,bestScore);
                }
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = INT_MAX;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(Board[i][j] == 0)
                {
                    Board[i][j] = 1;
                    AvailableSpots--;
                    int score = MiniMax(Board, depth + 1, true);
                    AvailableSpots++;
                    Board[i][j] = 0;
                    bestScore = min(score,bestScore);
                }
            }
        }
        return bestScore;
    }
}

void BotF::BestMove()
{
    int bestScore = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Map[i][j] == 0)
            {
                Map[i][j] = 2;
                AvailableSpots--;
                int score = MiniMax(Map, 0, false);
                AvailableSpots++;
                Map[i][j] = 0;
                if (score > bestScore)
                {
                    bestScore = score;
                    I = i;
                    J = j;
                }
            }
        }
    }
    Map[I][J] = 2;
    DrawMap[I][J] = Opponent;
    Winner = -1;
}
