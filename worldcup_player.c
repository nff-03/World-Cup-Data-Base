#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "worldcup_player.h"

// create a structure of players where each player has a code, name, age, clubname, and a next node
struct Player{

    int code;
    char name[50];
    int age;
    char clubName[50];
    struct Player *next;

};

// temporary variable to store the input values
int tmpCode2;
char tmpName2[50];
int tmpAge2;
char tmpClub2[50];

// a helper method read line to read the user input with space in it
int read_line(char str[], int n) {

  int ch, i = 0;

  while (isspace(ch = getchar()));
  while (ch != '\n' && ch != EOF) {

    if (i < n) {
      str[i++] = ch;
    }
    ch = getchar();
  }

  str[i] = '\0';
  return i;
}

// an insert method to add a player to the list
struct Player *insert(struct Player *list){

    struct Player *newPlayer;  // a node that will store the new player

    // check if there is still space in memory
    newPlayer = malloc(sizeof(struct Player));

    if(newPlayer == NULL){

        printf("Data Base is Full!");
        exit(EXIT_FAILURE);
    }

    // prompt the user to enter a pleaye code, and store it in its temporary variable
    printf("\t Enter player code: ");
    scanf("%d", &tmpCode2);

    // check if the code is a valid code
    if(tmpCode2 < 0){

        printf("Invalid player code! \n");
        return list;
    }

    struct Player *p = list;  // create a temprary node pointing at the head

    // loop through the linked list, to check if the code exists already
    while(p != NULL && p->code != tmpCode2){
        p = p->next;
    }

    // if it does, return
    if(p != NULL){

        printf("Player code exists already! \n");
        return list;
    }

    // prompt the user to enter a player name, and store it in its temporary variable
    printf("\t Enter player name: ");
    read_line(tmpName2, 49);

    // prompt the user to enter a player age and store it in its temporary variable
    printf("\t Enter player age: ");
    scanf("%d", &tmpAge2);

    // check if the given age is a valid age
    if(tmpAge2 < 17 || tmpAge2 > 99){

        printf("Invalid age input! Age must be between 17 - 99! \n");
        return list;
    }

    // prompt the user to enter a player club name and store it in its temporary variable
    printf("\t Enter player club name: ");
    read_line(tmpClub2, 49);

    // store the given value into the new node
    newPlayer->code = tmpCode2;
    strncpy(newPlayer->name, tmpName2, 49);
    newPlayer->age = tmpAge2;
    strncpy(newPlayer->clubName, tmpClub2, 49);

    newPlayer->next = list; // make the new node point to the head of the list
    return newPlayer;  // return the new node

}

// a search method that print the player's information if it is in the list
struct Player *search(struct Player *list){

    // prompt the user to enter a team code, and store it in its temporary variable
    printf("\t Enter player code: ");
    scanf("%d", &tmpCode2);

    struct Player *p = list; // create a temprary node pointing at the head

    // loop through the linked list, to check if the code exists 
    while (p != NULL && p->code != tmpCode2){
        p = p->next;
    }

    return p; // return the node p points to

}

// a print method to print all the players in the list
void print(struct Player *list){

    printf("Player Code \t Player Name \t Player Age \t Player Club \n");  // print the header info

    struct Player *p = list;  // create a temprary node pointing at the head

    // for every node, print their information
    while(p != NULL){
        printf("%-6d \t\t %-8s \t %d \t\t %s \n", p->code, p->name, p->age, p->clubName);
        p = p->next;
    }

}

// an update method to update a players information
void update(struct Player *list){

    struct Player *p = list; // create a temprary node pointing at the head

    // prompt the user to enter a team name, and store it in its temporary variable
    printf("\t Enter player code: ");
    scanf("%d", &tmpCode2);

    // loop through the linked list, to check if the code exists 
    while(p != NULL && p->code != tmpCode2){
        p = p->next;
    }

    // if the code does not exist, return
    if(p == NULL){

        printf("Player does not exist! \n");
        return;
    }

    // prompt the user to enter a player name, and store it in its temporary variable
    printf("\t Enter player name: ");
    read_line(tmpName2, 49);

    // prompt the user to enter a player age and store it in its temporary variable
    printf("\t Enter player age: ");
    scanf("%d", &tmpAge2);

    // check if the given age is a valid age
    if(tmpAge2 < 17 || tmpAge2 > 99){

        printf("Invalid age input! Age must be between 17 - 99! \n");
        return;
    }

    // prompt the user to enter a player club name and store it in its temporary variable
    printf("\t Enter player club name: ");
    read_line(tmpClub2, 49);

    // copy the information into the node
    strncpy(p->name, tmpName2, 49);
    p->age = tmpAge2;
    strncpy(p->clubName, tmpClub2, 49);
}

// a delet method to delet a player from the list
struct Player *delet(struct Player *list){

    struct Player *curr = list; // create a temprary node pointing at the head
    struct Player *prev = NULL; // create a temprary node pointing to null, which is before the head

    // prompt the user to enter a team name, and store it in its temporary variable
    printf("\t Enter player code: ");
    scanf("%d", &tmpCode2);

    // loop through the linked list, to check if the code exists 
    while(curr != NULL && curr->code != tmpCode2){
        prev = curr; // set previous to current, and current to its next
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

    free(curr);  // delet curr node from the memory
    return list;  // return the list
}

// a method to run the file from another file
void runPlayer(){

    struct Player *first = NULL;  // a first node which is the head

    char opeCode; // character storing the operation code

    struct Player *p = NULL; // a temporary node

    for(;;){

        // prompt user to enter an operation code, and store it in its varaible
        printf("Enter player operation code: ");
        scanf(" %c", &opeCode);

        switch(opeCode){

            // if the user inputs i
            case 'i':

            first = insert(first);  // insert into the node, and make first points to the node the method returns

            break;  // break out of the switch case

            // if the user inputs s
            case 's':

            p = search(first);  // store what search returns into the temporary variable
            
            // if it is a null node, this means the code does not exist
            if(p == NULL){
                printf("Player does not exist! \n");
            }
            
            else{
                // print the identifying information, and then print the player info
                printf("Player Code \t Player Name \t Player Age \t Player Club \n");
                printf("%-6d \t\t %-8s \t %d \t\t %s \n", p->code, p->name, p->age, p->clubName);
            }
            break; // break out of the switch case

            // if the user inputs p
            case 'p':
            print(first); // call the method print
            break; // break out of the switch case

            // if the user inputs u
            case 'u':
            update(first);  // call the method update
            break; // break out of the switch case

            // if the user inputs d
            case 'd':
            first = delet(first);  // call the method delet, and store the node it returns into the first node
            break; // break out of the switch case

            // if the user inputs q
            case 'q':
            return;  // quit the program

            // if the user inputs an invalid input
            default:
            printf("Invalid operation code!\n");  // print a message
            break;  // break out of the switch case

          }
    }

}
