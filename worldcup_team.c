#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "worldcup_team.h"

// create a structure of teams where each team has a code, name, group seeding, kit colour, and a next node
struct Team{

    int code;
    char name[25];
    char groupSeeding[3];
    char colour[2];
    struct Team *next;

};

int tmpCode;  // temporary variable storing code
char tmpName[25]; // temporary variable storing name
char tmpGS[3];  // temporary variable storing group seeding
char tmpColour[2]; // temporary variable storing kit colour

// Method to check if a letter in groupseeding is valid, return boolean variable
bool letterCheck(char ch){

    char possibleCh[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // array of possible characters

    for(int i = 0; i < 8; i++){

        // if the input character is in the list
        if(ch == possibleCh[i]){
            return true; //return true
        }   
    }

    return false; //return false if it is not in the list
}

// method to check if the kit colour is a valid colour
bool colourCheck(char ch){

    // list of valid colour code
    char colourLst[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V', 'r', 'o', 'y', 'g', 'b', 'i', 'v'};

    for(int i = 0; i < 14; i++){

        // if the input character is in the list
        if(ch == colourLst[i]){

            return true; // return true
        }
    }

    return false; // if it is not return false
}

// Method to print the word representation of a colour
char *colourGen(char ch){

    if(ch == 'r' || ch == 'R'){

        return "Red";
    }

    else if(ch == 'o' || ch == 'O'){

        return "Orange";
    }

    else if(ch == 'y' || ch == 'Y'){

        return "Yellow";
    }

    else if(ch == 'g' || ch == 'G'){

        return "Green";
    }

    else if(ch == 'b' || ch == 'B'){

        return "Blue";
    }

    else if(ch == 'i' || ch == 'I'){

        return "Indigo";
    }

    else if(ch == 'v' || ch == 'V'){

        return "Violet";
    }
}

// an insert method to add a team to the list
struct Team *insertTeam(struct Team *list){

    struct Team *newTeam; // a node that will store the new team

    // check if there is still space in memory
    newTeam = malloc(sizeof(struct Team));

    if (newTeam == NULL){

        printf("Data Base is Full!");
        exit(EXIT_FAILURE);
    }

    // prompt the user to enter a team code, and store it in its temporary variable
    printf("\t Enter team code: ");
    scanf("%d", &tmpCode);

    // check if the code is a valid code
    if(tmpCode < 0){

        printf("Invalid team code! \n");
        return list;
    }

    struct Team *p = list;  // create a temprary node pointing at the head

    // loop through the linked list, to check if the code exists already
    while(p != NULL && p->code != tmpCode){
        p = p->next;
    }

    // if it does, return
    if(p != NULL){

        printf("Team code exists already! \n");
        return list;
    }

    // prompt the user to enter a team name, and store it in its temporary variable
    printf("\t Enter team name: ");
    scanf("%24s", &tmpName);

    p = list;  // make the temorary node point back to the head of the list

    // loop through the linked list, to check if the name exists already
    while(p != NULL && strcmp(p ->name, tmpName) != 0){
        p = p->next;
    }

    // if it does, return
    if(p != NULL){

        printf("Team name exists already! \n");
        return list;
    }

    // prompt the user to enter a team code, and store it in its temporary variable
    printf("\t Enter  group seeding: ");
    scanf("%s", &tmpGS);

    // check if the groupseeding letter is invalid
    if(letterCheck(tmpGS[0]) == false){

        printf("Invalid letter input! Letter must be between A-H! \n"); // if so print invalid letter input
        return list; // and break
    }

    int num = tmpGS[1] - '0';  // switch the second char into an int

    // if it is not between 1 and 4
    if(num < 1 || num > 4){

        printf("Invalid number input! Number must be between 1-4! \n"); // print invalid number
        return list;  // and break
    }

    p = list; // make the temorary node point back to the head of the list

    // loop through the linked list, to check if the group seeding exists already
    while(p != NULL && strcmp(p ->groupSeeding, tmpGS) != 0){
        p = p->next;
    }

    // if it does, return
    if(p != NULL){

        printf("Team group seeding exists already! \n");
        return list;
    }

    // prompt the user to enter a team kit colour, and store it in its temporary variable
    printf("\t Enter the kit colour: ");
    scanf("%s", &tmpColour);
    
    // check if the colour is invalid
    if(colourCheck(tmpColour[0]) == false){

        printf("Invalid kit colour! \n"); // if it is, print invalid kit colour
        return list;  // and break
    }

    // store the given value into the new node
    newTeam->code = tmpCode;
    strncpy(newTeam->name, tmpName, 24);
    strncpy(newTeam->groupSeeding, tmpGS, 2);
    strncpy(newTeam->colour, tmpColour, 1);

    newTeam->next = list; // make the new node point to the head of the list
    return newTeam;  // return the new node
}

// a search method that print the team's information if it is in the list
struct Team *searchTeam(struct Team *list){

    // prompt the user to enter a team code, and store it in its temporary variable
    printf("\t Enter team code: ");
    scanf("%d", &tmpCode);

    struct Team *p = list;  // create a temprary node pointing at the head

    // loop through the linked list, to check if the code exists 
    while (p != NULL && p->code != tmpCode){
        p = p->next;
    }

    return p; // return the node p points to
    
}

// a print method to print all the teams in the list
void printTeam(struct Team *list){

    printf("Team Code \t Team Name \t Group Seeding \t Primary Kit Colour \n"); // print the header info

    struct Team *p = list;  // create a temprary node pointing at the head

    // for every node, print the information
    while (p != NULL){
        printf("%-6d \t\t %-8s \t %-6s \t\t %s \n", p->code, p->name, p->groupSeeding, colourGen(p->colour[0]));
        p = p->next;
    }
    
}

// an update method to update a players information
void updateTeam(struct Team *list){

    struct Team *p = list; // create a temprary node pointing at the head
    struct Team *tmp = list; // create another temprary node pointing at the head

    // prompt the user to enter a team name, and store it in its temporary variable
    printf("\t Enter team code: ");
    scanf("%d", &tmpCode);

    // loop through the linked list, to check if the code exists 
    while(p != NULL && p->code != tmpCode){
        p = p->next;
    }

    // if the code does not exist, return
    if(p == NULL){

        printf("Team does not exist! \n");
        return;
    }

    // prompt the user to enter a team name, and store it in its temporary variable
    printf("\t Enter team name: ");
    scanf("%24s", &tmpName);

    // loop through the linked list, to check if the name exists 
    while(tmp != NULL && strcmp(tmp->name, tmpName)){
        tmp = tmp->next;
    }

    // if it exists
    if(tmp != NULL){

        // check if it is not the same as the original name, if not then return, if it is, continue
        if(strcmp(p->name, tmpName) != 0){
            printf("Team name exists already!");
            return;
        }
    }

    tmp = list; // make the temorary node point back to the head of the list

    // prompt the user to enter a team code, and store it in its temporary variable
    printf("\t Enter  group seeding: ");
    scanf("%s", &tmpGS);

    // check if the groupseeding letter is invalid
    if(letterCheck(tmpGS[0]) == false){

        printf("Invalid letter input! Letter must be between A-H! \n"); // if so print invalid letter input
        return; // and break
    }

    int num = tmpGS[1] - '0';  // switch the second char into an int

    // if it is not between 1 and 4
    if(num < 1 || num > 4){

        printf("Invalid number input! Number must be between 1-4! \n"); // print invalid number
        return;  // and break
    }

    tmp = list; // make the temorary node point back to the head of the list

    // loop through the linked list, to check if the group seeding exists 
    while(tmp != NULL && strcmp(tmp ->groupSeeding, tmpGS) != 0){
        tmp = tmp->next;
    }

    // if it exists
    if(tmp != NULL){

        // check if it is not the same as the original group seeding, if not then return, if it is, continue
        if(strcmp(p->groupSeeding, tmpGS) != 0){;
            printf("Team group seeding exists already! \n");
            return;
        }

    }

    // prompt the user to enter a team kit colour, and store it in its temporary variable
    printf("\t Enter the kit colour: ");
    scanf("%s", &tmpColour);
    
    // check if the colour is invalid
    if(colourCheck(tmpColour[0]) == false){

        printf("Invalid kit colour! \n"); // if it is, print invalid kit colour
        return;  // and break
    }

    // store the given value into the node
    strncpy(p->name, tmpName, 24);
    strncpy(p->groupSeeding, tmpGS, 2);
    strncpy(p->colour, tmpColour, 1);
}

// a delet method to delet a team from the list
struct Team *deletTeam(struct Team *list){

    struct Team *curr = list; // create a temprary node pointing at the head
    struct Team *prev = NULL; // create a temprary node pointing to null, which is before the head

    // prompt the user to enter a team name, and store it in its temporary variable
    printf("\t Enter team code: ");
    scanf("%d", &tmpCode);

    // loop through the linked list, to check if the code exists 
    while(curr != NULL && curr->code != tmpCode){
        prev = curr;
        curr = curr->next;
    }

    // if the code is not in the list, return
    if(curr == NULL){

        printf("Team does not exist! \n");
        return list;
    }
    
    // if the node to be removed is the head, make the head point to the second node
    if(prev == NULL){
        list = list->next;
    }
   
    // else set previous next to current node's next
    else{
        prev->next = curr->next;
    }

    free(curr); // delet curr node from the memory
    return list; // return the list

}

// a method to run the file from another file
void runTeam(){

    struct Team *first = NULL; // a first node which is the head

    char opeCode; // character storing the operation code

    struct Team *p = NULL; // a temporary node

    for(;;){

        // prompt user to enter an operation code, and store it in its varaible
        printf("Enter team operation code: ");
        scanf(" %c", &opeCode);

        switch(opeCode){

            // if the user inputs i
            case 'i':

            first = insertTeam(first); // insert into the node, and make first points to the node the method returns

            break;  // break out of the switch case

            // if the user inputs s
            case 's':

            p = searchTeam(first); // store what search returns into the temporary variable

            // if it is a null node, this means the code does not exist
            if(p == NULL){
                printf("Team does not exist! \n");
            }

            else{
                // print the identifying information, and then print the team info
                printf("Team Code \t Team Name \t Group Seeding \t Primary Kit Colour \n");
                printf("%-6d \t\t %-8s \t %-6s \t\t %s \n", p->code, p->name, p->groupSeeding, colourGen(p->colour[0]));
            }
            break; // break out of the switch case

            // if the user inputs p
            case 'p':
            printTeam(first); // call the method print
            break; // break out of the switch case

            // if the user inputs u
            case 'u':
            updateTeam(first); // call the method update
            break; // break out of the switch case

            // if the user inputs d
            case 'd':
            first = deletTeam(first); // call the method delet, and store the node it returns into the first node
            break; // break out of the switch case

            // if the user inputs q
            case 'q':
            return; // quit the program

            // if the user inputs an invalid input
            default:
            printf("Invalid operation code!\n"); // print a message
            break;  // break out of the switch case

          }
    }
}
