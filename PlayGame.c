#include"PlayGame.h"
#include "ValidInput.h"
#include"Rotate.h"
#include<stdio.h>
void PlayGame(char Table[8][8], int Turn,char TableFake[8][8]) {
	char Row, Column, TrashInput;
	int TrashNumber = 0, Wrong = 0, i = 0, j = 0, k=0, l=0, Counter = 0, Row1[2] = { 0,0 }, Column1[2] = { 0,0 }, Diameter1[4] = { 0,0,0,0 };
	if (Turn % 2 == 1)
		printf("BLACK Player's Turn.Please Enter a valid number:\n");
	else
		printf("WHITE Player's Turn.Please Enter a valid number:\n");
	scanf("%c%c", &Row, &Column);/*Check the truth of input*/
	if (Column == '\n') {
		Wrong = 1;
	}
	else
	{
		scanf("%c", &TrashInput);
		while (TrashInput != '\n') {
			if (TrashInput != ' ' && TrashInput != '\n') 
				TrashNumber++;
			scanf("%c", &TrashInput);
		}
	}
	if (TrashNumber > 0) 
		Wrong = 1;
	TrashNumber = 0;
	if (Wrong == 0)
		Wrong = ValidInput(Row, Column, Table, Turn, Row1, Column1, Diameter1);
	while (Wrong) {/*Get a valid input*/
		Wrong = 0;
		printf("INVALID INPUT!Please enter a valid input according to the Table\n");
		scanf("%c%c", &Row, &Column);
		if (Column == '\n')
			Wrong = 1;
		else
			{
			scanf("%c", &TrashInput);
			while (TrashInput != '\n') {
				if (TrashInput != ' ' && TrashInput != '\n')
					TrashNumber++;
				scanf("%c", &TrashInput);
				}
			}
		if (TrashNumber > 0)
			Wrong = 1;
		TrashNumber = 0;
		if (Wrong == 0)
			Wrong = ValidInput(Row, Column, Table, Turn, Row1, Column1, Diameter1);
		}
	Rotate(Row, Column, Table, Turn, Row1, Column1, Diameter1,TableFake);/*Change the colours in each move*/
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++){
			TableFake[i][j]=Table[i][j];
		}
	}
}
