#include <stdlib.h>
#include <stdio.h>

char square[10] ={'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int checkForWin();
void printBoard();
void markBoard(char mark);


int main()
{
    int gameStatus;

    char mark;

    player = 1;

    do
    {
        printBoard();
        // if player mod 2 is 1 then set player to 1; if player mod 2 is 0 set player to 2
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        //ternary operator the ? represents if the value is true the : represents if the value is false
        //so in this case if player == 1 then mark = X if player != 1 mark = O
        mark = (player == 1) ? 'X' : 'O';  

        markBoard(mark);

        gameStatus = checkForWin();

        if (gameStatus == 1){
            printf("Player %i wins!\n", player);
        }
        else if (gameStatus == 0){
            printf("Its a draw!\n");
        }

        player++;
    }
    while (gameStatus == -1);

    return 0;
}

int checkForWin(){
    int returnValue = -1;
    
    if (square[1] == square[2] && square[2] == square[3]){
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6]){
        returnValue = 1;
    }
    else if (square[7] == square[8] && square[8] == square[9]){
        returnValue = 1;
    }
    else if (square[1] == square[4] && square[4] == square[7]){
        returnValue = 1;
    }
    else if (square[2] == square[5] && square[5] == square[8]){
        returnValue = 1;
    }
    else if (square[3] == square[6] && square[6] == square[9]){
        returnValue = 1;
    }
    else if (square[1] == square[5] && square[5] == square[9]){
        returnValue = 1;
    }
    else if (square[3] == square[5] && square[5] == square[7]){
        returnValue = 1;
    }
    else if( square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
        returnValue = 0;
    }

    return returnValue;
}

void printBoard(){

system("clear");

printf("   +-----+-----+-----+\n");
printf(" 3 |  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);
printf("   +-----+-----+-----+\n");
printf(" 2 |  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);
printf("   +-----+-----+-----+\n");
printf(" 1 |  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);
printf("   +-----+-----+-----+\n");
printf("      1     2     3\n");

    return;
}

void markBoard(char mark){

    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else {
        printf("Invalid move ");
        player --;
        
    }
}