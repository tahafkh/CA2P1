#include<stdio.h>
#include "Possibility.h"
#include "PlayGame.h"
#include "PrintBoard.h"
#include "Initialize.h"
int main() {/*Initializing variables*/
	char Table[8][8], TableFake[8][8], EndGame = 'c',TrashInput;
	int Turn = 1, Possible = 1,Blacks=0,Whites=0;
	while (EndGame != 'e') {
		Initialize(Table, &Turn, TableFake, &Possible);/*Initializing the game*/
		PrintBoard(Table, &Whites, &Blacks);/*Printing the first board*/
		while (Possible) {
			PlayGame(Table, Turn, TableFake);/*Play the game in each turn*/
			PrintBoard(Table, &Whites, &Blacks);/*Update the board and printting it*/
			Turn++;/*Change the turn*/
			Possible = Possibility(Table, Turn);/*Chaeck whether there is a possible cell for next player*/
		}
		printf("There is no more choice in the game!\n");
		if (Blacks > Whites)/*Winning or draw states*/
			printf("BLACK has won the game!\n");
		else if (Whites > Blacks)
			printf("WHITE has won the game!\n");
		else
			printf("There is a draw in the game\n");
		printf("WHITES = %d\nBLACKS = %d\n", Whites, Blacks);
		printf("If You Want To Start A New Game,Press c.Else,Press e\n");/*Continue or end the game*/
		scanf("%c%c", &EndGame,&TrashInput);
	}
	return 0;
}