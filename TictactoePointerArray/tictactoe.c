#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Michael, Run the code and type in row 1 column one and then type in the same 1 and 1 again.  This will for whatever reason show -1- -200 in the row and column selection
//Second problem: I have no idea how to check for a winner when using pointers because I dont know how to increment or decrement the pointer address inside of an if/else if statement (see checkforWinner method at bottom)

//Function definitions
void printBoard(char (*ticTacToe)[3]);
bool isSlotFilled(char (*ticTacToe)[3], int selectionX, int selectionY);
bool turnSwitcher(bool XTurn);
void play(char player, char (*pticTacToe)[3]);
void updateBoard(char (*ticTacToe)[3], int selectionX, int selectionY, char player);
bool checkForWinner(char (*pticTacToe)[3], char XorO);

int main()
{
    //create 2d array
    char ticTacToe[3][3] = {{"---"}, {"---"}, {"---"}};
    //create array of pointers
    char (*pticTacToe)[3] = &ticTacToe[0];
    bool XTurn = true;
    char X = 'X';
    char O = 'O';
    bool gameOver = false;

    printf("Welcome to TicTacToe\n");
    //print the starting board
    printBoard(pticTacToe);
    //Total of 9 turns; if no one wins by turn 9 result is a draw
    for (int i = 1; i <= 9; i++){
        if (XTurn == true){
            printf("Its X's turn");
            //plays X's turn
            play(X, pticTacToe);
            //checks if X won
            gameOver = checkForWinner(pticTacToe, X);
            //if game is over print winner and return
            if (gameOver == true){
                printBoard(pticTacToe);
                printf("X wins!");
                return 0;
            }
        }
        else{
            printf("Its O's turn");
            play(O, pticTacToe);
            //checks if 0 won
           gameOver = checkForWinner(pticTacToe, O);
           if (gameOver == true){
            printBoard(pticTacToe);
            printf("O wins!");
            return 0; 
           }

        }
        //switch turns
        XTurn = turnSwitcher(XTurn);
        //print the board updated from the previous move
        printBoard(pticTacToe);
    }
    //if no one wins print statement and end
    printf("\nGame Over, it's a draw!\n");
    return 0;
}

//main game play functionality 
void play(char player, char (*pticTacToe)[3]){
    int row;
    int column;
    bool validSelection = false;
    bool rowValid;
    bool columnValid;

    //repeats until the user selects a valid number between one and three that is not already taken
    while(validSelection == false){
        //takes in user row selection and checks to see if its a valid number between 1 and 3
        rowValid = false;
        columnValid = false;
        while(rowValid == false){
             printf("\nEnter the row you would like to select: ");
             scanf("%i", &row);
             if(row >= 1 && row <= 3)
             {
                 rowValid = true;
             }
             else{
                 printf("\n Invalid Row Selection, select a number between 1 and 3");
             }
        }
        while(columnValid == false){
            printf("\nEnter the column you would like to select: ");
            scanf("%i", &column);
            if(column >= 1 && column <= 3)
            {
                columnValid = true;
            }
            else{
                printf("\n Invalid Column Selection, select a number between 1 and 3");
            }
        }
        //decrement row and column by one to match the actual column and row array numbers
        --column;
        --row;
        //finally check to see if the slot chosen by the user has already been taken or not
        validSelection = isSlotFilled(pticTacToe, column, row);
    }
    //after validation update the game board
    updateBoard(pticTacToe, column, row, player);

    return;

}

//switches the player
bool turnSwitcher(bool XTurn){
    if (XTurn == true){
        XTurn = false;
    }
    else{
        XTurn = true;
    }
return XTurn;
}

//checks to see if the slot chosen was already filled by another player
bool isSlotFilled(char (*ticTacToe)[3], int selectionX, int selectionY){
    //increment the tictactoe address by the row number selected by the user
    ticTacToe += selectionY;

    //debugging stuff to test inputs
    // printf("\n%c\n", (*ticTacToe)[selectionX]);
    // printf("\n%i\n", selectionY);
    // printf("\n%i\n", selectionX);
    
    if ((*ticTacToe)[selectionX] != '-'){
        printf("\nThis column is taken. Please select a different square\n");
         //decrements the pointer because it doesnt work without this, I dont know michael, I really dont.
        ticTacToe -= selectionY;
        return false;
    }
    else{
         //decrements the pointer because it doesnt work without this, I dont know michael, I really dont.
        ticTacToe -= selectionY;
        return true;
    }


}

void updateBoard(char (*pticTacToe)[3], int selectionX, int selectionY, char player){
    //incremente the pointer by the row selected
    pticTacToe += selectionY;
    //choose the array at location of the column
    (*pticTacToe)[selectionX] = player;
    //decrements the pointer because it doesnt work without this, I dont know michael, I really dont.
    pticTacToe -= selectionY;
    return;
}

//prints the current board using a pointer array to tictactoe
void printBoard(char (*ticTacToe)[3]){
    printf("\n        TIC TAC TOE     \n");
    printf("    +-----+-----+-----+\n");
    printf("R 3 |  %c  |  %c  |  %c  |\n", (*ticTacToe + 6)[0], (*ticTacToe + 6)[1], (*ticTacToe + 6)[2]);
    printf("    +-----+-----+-----+\n");
    printf("O 2 |  %c  |  %c  |  %c  |\n", (*ticTacToe + 3)[0], (*ticTacToe + 3)[1], (*ticTacToe + 3)[2]);
    printf("    +-----+-----+-----+\n");
    printf("W 1 |  %c  |  %c  |  %c  |\n", (*ticTacToe)[0], (*ticTacToe)[1], (*ticTacToe)[2]);
    printf("    +-----+-----+-----+\n");
    printf("       1     2     3\n");
    printf("        C O L U M N     \n\n");
    //printf("%p %p", (ticTacToe + 1)[2], (ticTacToe + 2)[1]);

    return;
}
//checks to see if a player won the game after their turn
bool checkForWinner(char (*pticTacToe)[3], char XorO) {

    //Incomplete because I have no idea how to increment or decrement the pointer inside of an if statement
    //printf("%c %c %c",(*pticTacToe + 3)[0], (*pticTacToe + 3)[1], (*pticTacToe + 3)[2]);
    //---
    if((*pticTacToe)[0] == XorO && (*pticTacToe)[1] == XorO && (*pticTacToe)[2] == XorO){
        return true;
    }
    else if((*pticTacToe + 3)[0] == XorO && (*pticTacToe + 3)[1] == XorO && (*pticTacToe + 3)[2] == XorO){
        return true;
    }
    else if((*pticTacToe + 6)[0] == XorO && (*pticTacToe + 6)[1] == XorO && (*pticTacToe + 6)[2] == XorO){
        return true;
    }
    // |
    else if((*pticTacToe)[0] == XorO && (*pticTacToe + 3)[0] == XorO && (*pticTacToe + 6)[0] == XorO){
        return true;
    }
    else if((*pticTacToe)[1] == XorO && (*pticTacToe + 3)[1] == XorO && (*pticTacToe + 6)[1] == XorO){
        return true;
    }
    else if((*pticTacToe)[2] == XorO && (*pticTacToe + 3)[2] == XorO && (*pticTacToe + 6)[2] == XorO){
        return true;
    }
    // "/"
    else if((*pticTacToe)[0] == XorO && (*pticTacToe + 3)[1] == XorO && (*pticTacToe + 6)[2] == XorO){
        return true;
    }
    // "\"
    else if((*pticTacToe + 6)[0] == XorO && (*pticTacToe + 3)[1] == XorO && (*pticTacToe)[2] == XorO){
        return true;
    }
    else{
        return false;
    }

}
