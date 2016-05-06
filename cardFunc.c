// cardFunc.c
/******************************************************************************/
/* PROGRAMMER:  Miguel Herrnsdorf  */
/*DESCRIPTION: functions to most common manipulation of a deck of cards.
* create a deck, display a deck, shuffle a deck, deal a specific number of cards
* to specific number of players, and display hands. It also validate the user 
* input of cards and players. 
*/
/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>  /* for atoi(), rand() & qsort() */
#include "cardLib.h" /* definition for types and function prototype */
/******************************************************************************/

//Constants assignment
/* Used for card's suit symbols */
const char suitType[SUITINDECK][SUITINDECK] = {{0xe2, 0x99, 0xa2, 0},
 {0xe2, 0x99, 0xa1, 0}, {0xe2, 0x99, 0xa4, 0}, {0xe2, 0x99, 0xa7, 0}};

/* Used to replace highest values on a card */
const char highCards[] = "JQKA";

/* Used to unset delt cards from deck */
const int NOCARDS = -1;
// End Constant assignment

/******************************************************************************/

/*
* Function: verifyParam
* ---------------------
* Verify that the inputs are within the range.
*
* argc: int that check the number of parameters for the game.
* return: False if argc and NUMPARAM are not equals.  Returns TRUE otherwise.
* side sffects: none.
*/
int verifyParam(int argc) {
    return (argc < NUMPARAM)? FALSE: TRUE;
}

/******************************************************************************/

/*
* Function: verifyGame
* ---------------------
* Verify that the inputs are within the range.
*
* numCards: int that sets the number of cards to be used in the game.
* numPlayers: int that sets the number of players in the game.
* return: False numPlayers are not between 1 & 7 or if numCards * numPlayers 
* is grater than 52.  Returns TRUE otherwise.
* side sffects: none.
*/
int verifyGame(int numCards, int numPlayers) {
    // if (numPlayers < MINHAND || numPlayers > 10) { // testing mode
    if (numPlayers < MINHAND || numPlayers > MAXPLAYERS) { 
        printf("%s", "The number of players must be between ");
        printf("%d %s %d\n", MINHAND, "&", MAXPLAYERS);
        return FALSE;
    } else if (STUDCARDS * numPlayers > CARDSINDECK) {
        printf("%s", "Your combination of cards & players exceeded");
        printf("%s\n", " the number of cards available");
        return FALSE;
    } else {
        return TRUE;
    }
}

/******************************************************************************/

/*
* Function: makeDeck
* -------------------
* Initialize the structure array of 52 cards.  Each card is a structure of two
* members value and suit.
* 
* deck: the array of 52 structures of type card.
* return: void
* side effects: This function modifies the array being passed by initializing 
* the members of the structure.
*/
void makeDeck(struct card deck[]) {
    int i = 0, j = 1, deckIndex = 0;

    for (i = 0; i < SUITINDECK; i++){
        for (j = 1; j <= CARDSINSUIT; j++){
            deck[deckIndex].value = j;
            deck[deckIndex].suit = i;
            deckIndex++;
        }
    }
    i = 0, j = 0;
    for (; i < SUITINDECK; i++, j += CARDSINSUIT)
        deck[j].value += CARDSINSUIT;
}

/******************************************************************************/

/*
* Function: shuffleDeck
* ----------------------
* Traversing the array of cards swapping the card at each position by another 
* card at a random position. 
*
* deck:  array of structures of type card.
* return: void
* side effects: This method modifies the array being passed.
*/
void shuffleDeck(struct card deck[]) {
    int i = 0, random = 0;
    struct card temp;

    for(i = 0; i < CARDSINDECK; i++)
    {
        random = rand() % CARDSINDECK;
        temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

/******************************************************************************/

/*
* Function: printDeck
* --------------------
* Displays the deck of cards. It replaces the actual numeric value of the high 
* value cards (11, 12, 13) by their game symbol (J, Q, K) respectively.
*
* deck: an array of structures of type card.
* message: string to be print before displaying the deck.
* return: void 
* side effects: none
*/
void printDeck(struct card deck[], char message[]) {
    char *pos = message;
    while (*pos != '\0') {
        printf("%c", *(pos++));
    }
    printf("\n");

    int i = 0, j = 0, cardValue = CARDSINSUIT;
    for (; i < SUITINDECK; i++) {
        for (; j < cardValue; j++) {
            if (deck[j].value >= JACK)
                // for the three highest values, print the symbol
                printf("%2c",highCards[deck[j].value - JACK]);
            else if (deck[j].value == ACE) {
                // for the ACE value, print the symbol
                printf("%2c",highCards[SUITINDECK - deck[j].value]);
            }
            else
                printf("%2d",deck[j].value);
            // print the suit symbol from suitType array
            printf("%s ", suitType[deck[j].suit]);
        }
    cardValue += CARDSINSUIT;
    printf("\n");
    }
}

/******************************************************************************/

/*
* Function: dealHand
* -------------------
* Distribute the cards of the deck to the players determined numCards, 
* numPlayers.  The cards are being saved to a 2D array. At the same time the 
* dealt cards are being set to '-1' in the deck to represent the card is not 
* in the deck anymore.
* 
* numCards: int that sets the number of cards to be used in the game.
* numPlayers: int that sets the number of players in the game.
* deck: an array of structures of type card.
* hands: 2D array to save the dealt cards.
* return: void
* side effects: It modifies the 2D array passed as parameter.
*/
void dealHand(int numCards, int numPlayers, struct card deck[], 
              struct card hands[][numCards]) {
    int i = 0, j = 0, r = 0;
    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < numCards; j++) {
            hands[i][j] = deck[r];
            deck[r].value = NOCARDS; // set dealt card to -1
            deck[r].suit = NOCARDS;
            r++;
        }
    }
}

/******************************************************************************/

/*
* Function: printHand
* --------------------
* This function displays the cards of each player. It replaces the  
* actual numeric value of the faces 1, 11, 12, and 13 but their symbol
* A, J, Q, and K respectively. This is done for display purposes only. 
* 
* numCards: int that sets the number of cards to be used in the game.
* numPlayers: int that sets the number of players in the game.
* hands: 2D array to display the dealt cards.
* message: string to be print before displaying the hands.
* return: void 
* side effects: None
*/
void printHand(int numCards, int numPlayers, 
               struct card hands[][numCards], char message[]) {
    int i = 0, j = 0;
    char *pos = message;
    while (*pos != '\0') {
       printf("%c", *(pos++));
    }
    printf("\n");

    for (i = 0; i < numPlayers; i++) {
        printf("%s%d\t", "Player-",i+1);
        for (j = 0; j < numCards; j++) {
            if (hands[i][j].value >= JACK) {
            // for the three highest values, print the symbol
            printf("%2c",highCards[hands[i][j].value - JACK]);
        }
        else if (hands[i][j].value == ACE) {
            // for the ACE value, print the symbol
            printf("%2c",highCards[SUITINDECK - hands[i][j].value]);
        }
        else {
            printf("%2d",hands[i][j].value);
        }
        // print the suit symbol from suitType array
        printf("%s ", suitType[hands[i][j].suit]);
    }
    printf("\n");
    }
}

/******************************************************************************/

/*
* Function: sortHand
* -------------------
* Reorder the cards of each hand by value in ascending order.
* 
* numCards: int that sets the number of cards to be used in the game.
* numPlayers: int that sets the number of players in the game.
* hands: 2D array to save the dealt cards.
* return: void
* side effects: It modifies the 2D array passed as parameter.
*/
void sortHand(int numCards, int numPlayers, struct card hands[][numCards]) {
    int i = 0;
    for (i = 0; i < numPlayers; i++) {
        qsort((void *) hands[i], numCards, sizeof (struct card), 
              (compfn) cmpFace);
    }
}

/******************************************************************************/

/*
* Function: cmpFace
* ------------------
* Helper function that compares two structures by value and return the highest 
* one.
* 
* card1: the structure to compare to.
* card2: the structure to be compare with.
* deck: an array of structures of type card.
* hands: 2D array to save the dealt cards.
* return: the value of the highest card.
* side effects: none
*/

int cmpFace(struct card *card1, struct card *card2) {
    if (card1->value < card2->value)
        return -1;
    else if (card1->value > card2->value)
        return 1;
    else
        return 0;
}

/******************************************************************************/
