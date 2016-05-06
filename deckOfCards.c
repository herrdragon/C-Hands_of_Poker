//deckOfCards.c
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>  /* for atoi() & rand()*/
#include <time.h>    /* for time() */
#include "cardLib.h" /* definition for types and function prototype */
/******************************************************************************/
/* DOCUMENTATION */

/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #4.   DUE Thursday 3/10 */

/* DESCRIPTION: This program generate and display of a deck of cards and of 
hands of cards. The numbers of cards & players are entered via the command-line 
arguments. Input will be the number of cards/hand and the number of hands 
(in this order and separated by one space).  The number of hands are from 1 
to 7. The program will display the original deck, shuffled deck of cards and 
each of the hands of cards, the sorted and ranked hands and the final 
winner/s. */

/* SPECIFICATIONS: Write algorithms and programs to generate a display of a deck 
of cards and of hands of cards. */

/* INPUT: Accept input via the command-line arguments. Validate command-line 
input. Input will be the number of cards/hand and the number of hands (players).
*/

/* COMPILATION: gcc deckOfCards.c cardFunc.c ranking.c -o playcards.out */

/* EXECUTE: ./playcards.out number1 number2 */

/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/

/* START PSEUDO CODE
int main(int argc, char *argv[]) {
	if (inputsIsValid(argc > 2)){
	convert strings argv[1] to integers
	convert strings argv[2] to integers

	if (inputsAreValid(argv[1], argv[2])){

		struct arrayOfCards;
		struct arrayOfHands;
		
		makeDeck(arrayOfCards);
		printDeck(arrayOfCards,"New Deck");
		
		shuffleDeck(arrayOfCards);
		printDeck(arrayOfCards,"Shuffled Deck");

		dealHand(argv[1], argv[2], deck, arrayOfHands);
		printHand(argv[1], argv[2], arrayOfCards, arrayOfHands,"Dealt Hands");

		sortHands(argv[1], argv[2], arrayOfHands);
		printHand(argv[1], argv[2], arrayOfCards, arrayOfHands,”Sorted Hands");

		rankedHands(argv[2], arrayOfHands,”Ranked Hands");
		printWinners();
	} 
   return 0;
}
 END PSEUDO CODE */
/******************************************************************************/
int main(int argc, char *argv[]) {
	if (!verifyParam(argc)) { /* verify the number of parameters */
   		printf("%s\n", "You must especify both, the number of cards & players");
		return FALSE;
	}
	// declare constants
	const int numCards = atoi(argv[1]);    /* convert strings to integers */
	const int numPlayers = atoi(argv[2]);

	if (verifyGame(numCards, numPlayers)){ /* validate user input */
		time_t ranTime;					   /* make a new seed */
   		srand((unsigned) time(&ranTime));  /* for shuffle function */

		struct card deck[CARDSINDECK];     /* create array of cards */

		//create a 2D array of players by cards
		struct card hands[numPlayers][STUDCARDS];
		
		makeDeck(deck);
		printDeck(deck, "New Deck");
		
		shuffleDeck(deck);
		printDeck(deck, "Shuffled Deck");
		
		dealHand(STUDCARDS, numPlayers, deck, hands);
		printHand(STUDCARDS, numPlayers, hands, "Dealt Hands");

		sortHand(STUDCARDS, numPlayers, hands);
		printHand(STUDCARDS, numPlayers, hands, "Sorted Hands");

		/* TEST HANDS ARRAY SUITS: 0-3, FACE: 1-14 */
		// struct card test[9][5] = {
		// 	{{7,0},{8,0},{9,0},{10,0},{11,0}},
		// 	{{6,0},{6,2},{6,3},{6,1},{11,0}},
		// 	{{5,1},{5,2},{13,0},{13,1},{13,3}},
		// 	{{3,0},{5,0},{6,0},{9,0},{13,0}},
		// 	{{2,1},{3,0},{4,3},{5,2},{14,0}},
		// 	{{14,0},{14,2},{14,1},{4,2},{5,3}},
		// 	{{1,0},{1,1},{3,2},{3,3},{5,2}},
		// 	{{1,0},{2,1},{5,2},{10,2},{10,3}},
		// 	{{3,0},{4,1},{5,2},{9,3},{13,0}},
		// };
		// printHand(STUDCARDS, numPlayers, test, "Sorted Hands");
		// rankHands(numPlayers, test, "Ranked Hands");
		
		rankHands(numPlayers, hands, "Ranked Hands");
		printWinner();
		
		/* FUTURE USE: LAST DELT CARD */
		int lastCard = STUDCARDS * numPlayers;
		// printf("%s", "Last dealt card of the shuffled deck ");
		// printf("%s%d%s\n", "was the ", lastCard, "th card");
	} 
	else {
		; // future use
	}
   	return NOERRORS;
}
