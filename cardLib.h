// cardLib.h
/******************************************************************************/
/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #4.   DUE Thursday 3/10
*/
/*DESCRIPTION: header file contains common constants, declarations, prototypes 
* and type declarations that are used by deckOfCards.c, cardFunc.c., ranking.c 
*/
/*
  CERTIFICATION: I hereby certify that this collective work is my own and none
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/
/******************************************************************************/

#define CARDSINDECK 52 //used to check total cards in deck
#define CARDSINSUIT 13 //used to control max # of cards
#define JACK        11 //used to control high cards
#define RANKLENGTH  16 //used to control length of string ranks
#define RANKS       10 //used to control # of ranks
#define ACE			     1 //used to control lowest cards
#define MAXPLAYERS   7 //used to control max # of players
#define STUDCARDS    5 //used to control fixed # of cards
#define MINCARD		   1 //used to control min # of cards
#define MINHAND 	   1 //used to control min # of players
#define NUMPARAM	   3 //used to control min # of parameters
#define SUITINDECK   4 //used to control # of suits used
#define NOERRORS     0 //no errors found
#define FALSE        0 //used to return 0 from functions
#define TRUE         1 //used to return 1 from functions
#define POS0         0 //used to control card position
#define POS1         1 //used to control card position
#define POS2         2 //used to control card position
#define POS3         3 //used to control card position
#define POS4         4 //used to control card position

enum rank_levels {No_Rank, High_Card, One_Pair, Two_Pair, Three_of_a_kind, 
    Straight, Flush, Full_House, Four_of_a_kind, Straight_Flush};

/******************************************************************************/
/* Used for card's suit symbols */
const char suitType[SUITINDECK][SUITINDECK];

/* Used to replace highest values on a card */
const char highCards[4];

/* Used to replace highest values on a card */
const char ranks[RANKS][RANKLENGTH];

/* Used to unset delt cards from deck */
const int NOCARDS;

/******************************************************************************/
// especify the structure a a card
struct card {int value; int suit;};

int verifyParam(int argc);

int verifyGame(int numCards, int numPlayers);

void makeDeck(struct card deck[]);

void shuffleDeck(struct card deck[]);

void printDeck(struct card deck[], char message[]);

void dealHand(int numCards, int numPlayers, struct card deck[], 
              struct card hands[][numCards]);

void sortHand(int numCards, int numPlayers, struct card hands[][numCards]);

typedef int (*compfn)(const void*, const void*);

int cmpFace(struct card *card1, struct card *card2);

void rankHands(int numPlayers, struct card hands[][STUDCARDS], char message[]);

int isStFLush  (int numPlayers, struct card hands[][STUDCARDS]);

int isFour     (int numPlayers, struct card hands[][STUDCARDS]);

int isFullHouse(int numPlayers, struct card hands[][STUDCARDS]);

int isFLush    (int numPlayers, struct card hands[][STUDCARDS]);

int isThree    (int numPlayers, struct card hands[][STUDCARDS]);

int isTowPair  (int numPlayers, struct card hands[][STUDCARDS]);

int isOnePair  (int numPlayers, struct card hands[][STUDCARDS]);

int isHighCard (int numPlayers, struct card hands[][STUDCARDS]);

void printHand(int numCards, int numPlayers, struct card hands[][numCards], 
               char message[]);

void printWinner();

void cleanWinner();
