#include <iostream>
#include <ctime>
#include "tictactoe.h"
using namespace std;

char space[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
char computer = 'O';

void start()
{
    bool game = true;

    gui();

    while(game)
    {
        pMove();
        gui();

        if(checkWin())
        {
            game = false;
            break;
        }else if(checkTie())
        {
            game = false;
            break;
        }

        cMove();
        gui();

        if(checkWin())
        {
            game = false;
            break;
        }else if(checkTie())
        {
            game = false;
            break;
        }
    }
}

void gui()
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << space[0] << "  |  " << space[1] << "  |  " << space[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << space[3] << "  |  " << space[4] << "  |  " << space[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << space[6] << "  |  " << space[7] << "  |  " << space[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void pMove()
{
    int i;

    cout << "Pick free space(1-9): ";
    cin >> i;
    i--;

    do
    {
        if(space[i] == '1' || space[i] == '2' || space[i] == '3' || space[i] == '4' || space[i] == '5' || space[i] == '6' || space[i] == '7' || space[i] == '8' || space[i] == '9'){
            space[i] = player;
            break;
        }
    }while(!i > 0 || !i < 8);
}

void cMove()
{
    int i;

    srand(time(0));

    while(true)
    {
        i = rand() % 9;
        if(space[i] == '1' || space[i] == '2' || space[i] == '3' || space[i] == '4' || space[i] == '5' || space[i] == '6' || space[i] == '7' || space[i] == '8' || space[i] == '9'){
            space[i] = computer;
            break;
        }
    }
}

bool checkWin()
{
    if((space[0] != '1' || space[0] != '2' || space[0] != '3' || space[0] != '4' || space[0] != '5' || space[0] != '6' || space[0] != '7' || space[0] != '8' || space[0] != '9') && (space[0] == space[1]) && (space[1] == space[2]))
    {
        space[0] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if(( space[3] != '1' ||  space[3] != '2' ||  space[3] != '3' ||  space[3] != '4' ||  space[3] != '5' ||  space[3] != '6' ||  space[3] != '7' ||  space[3] != '8' ||  space[3] != '9') && (space[3] == space[4]) && (space[4] == space[5]))
    {
        space[3] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if(( space[6] != '1' ||  space[6] != '2' ||  space[6] != '3' ||  space[6] != '4' ||  space[6] != '5' ||  space[6] != '6' ||  space[6] != '7' ||  space[6] != '8' ||  space[6] != '9') && (space[6] == space[7]) && (space[7] == space[8]))
    {
        space[6] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if((space[0] != '1' || space[0] != '2' || space[0] != '3' || space[0] != '4' || space[0] != '5' || space[0] != '6' || space[0] != '7' || space[0] != '8' || space[0] != '9') && (space[0] == space[3]) && (space[3] == space[6]))
    {
        space[0] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if(( space[1] != '1' ||  space[1] != '2' ||  space[1] != '3' ||  space[1] != '4' ||  space[1] != '5' ||  space[1] != '6' ||  space[1] != '7' ||  space[1] != '8' ||  space[1] != '9') && (space[1] == space[4]) && (space[4] == space[7]))
    {
        space[1] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if(( space[2] != '1' ||  space[2] != '2' ||  space[2] != '3' ||  space[2] != '4' ||  space[2] != '5' ||  space[2] != '6' ||  space[2] != '7' ||  space[2] != '8' ||  space[2] != '9') && (space[2] == space[5]) && (space[5] == space[8]))
    {
        space[2] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if((space[0] != '1' || space[0] != '2' || space[0] != '3' || space[0] != '4' || space[0] != '5' || space[0] != '6' || space[0] != '7' || space[0] != '8' || space[0] != '9') && (space[0] == space[4]) && (space[4] == space[8]))
    {
        space[0] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else if(( space[2] != '1' ||  space[2] != '2' ||  space[2] != '3' ||  space[2] != '4' ||  space[2] != '5' ||  space[2] != '6' ||  space[2] != '7' ||  space[2] != '8' ||  space[2] != '9') && (space[2] == space[4]) && (space[4] == space[6]))
    {
        space[2] == player ? cout << "YOU WIN!" << endl : cout << "YOU LOSE!" << endl;
    }
    else{
        return false;
    }

    return true;
}

bool checkTie()
{
    for(int i = 0; i < 9; i++)
    {
        if(space[i] == '1' || space[i] == '2' || space[i] == '3' || space[i] == '4' || space[i] == '5' || space[i] == '6' || space[i] == '7' || space[i] == '8' || space[i] == '9')
        {
            return false;
        }
    }

    std::cout << "IT'S A TIE!" << endl;

    return true;
}
