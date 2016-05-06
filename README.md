# C-Hands_of_Poker
This program generate and display of a deck of cards and hands of cards.

The numbers of cards & players are entered via the command-line arguments.
Input will be the number of cards/hand and the number of hands (in this order and separated by one space).  The number of hands are from 1 to 7.
The program will display the original deck, shuffled deck of cards and each of the hands of cards, the sorted and ranked hands and the final winner/s.

To use this program
--------------------
1- On the terminal, navigate to where the files are.

2- Make sure you have all three files (deckOfCards.c, cardFunc.c, ranking.c and cardLib.h) in the same directory.

3- Run "gcc deckOfCards.c cardFunc.c ranking.c -o playcards.out” to compile the program.

4- Then type "./playcards.out” follow by two number separated by one space to execute the program, like so: "./playcards.out 5 7”, where 5 is the number of cards and 7 is the number of hands or players.

5- If the combination of cards & hands exceds the total amount of cards, the program will display a message that state so and it will quit.

6- The result will be displayed on the screen.
