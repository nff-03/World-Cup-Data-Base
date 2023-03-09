#include <stdio.h>
#include "worldcup_team.h"
#include "worldcup_player.h"
#include "worldCupDB.h"

void main(){

    char opeCode; // character storing the operation code

    for(;;){

        // prompt user to enter an operation code, and store it in its varaible
        printf("Enter operation code: ");
        scanf(" %c", &opeCode);

        switch(opeCode){

            // if the user inputs h
            case 'h':

            // prints a message clarifying the purpose of the program
            printf("This program is designed to help you update the Teams database, or players database \n");
            printf("To update the Teams database type 't', to update the players database type 'p', and type 'q' to quit \n");

            break; // break out of the switch case

            // if the user inputs t
            case 't':
            runTeam(); // call the method that runs the teams file
            break; // break out of the switch case

            // if the user inputs p
            case 'p':
            runPlayer();  // call the method that runs the players file
            break;  // break out of the switch case

            // if the user inputs q
            case 'q':
            return;  // quit the program

            // if the user inputs an invalid input
            default:
            printf("Invalid operation code!\n");  // print a message
            break; // break out of the switch case

        }
    }
}
