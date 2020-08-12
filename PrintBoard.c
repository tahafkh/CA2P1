#include"PrintBoard.h"
#include<stdio.h>
void PrintBoard(char Table[8][8],int *Whites,int *Blacks) {
	int i = 0, j = 0;
	(*Whites) = 0;
	(*Blacks) = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (Table[i][j] == 'w') {
				(*Whites)++;
			}
			if (Table[i][j] == 'b') {
				(*Blacks)++;
			}
		}
	}
	printf("    1  2  3  4  5  6  7  8[b=%d w=%d]\n", *Blacks, *Whites);
	for (i = 0; i < 8; i++) {
		printf("%d0  ", i+1 );
		for (j = 0; j < 8; j++) {
			printf("%c  ", Table[i][j]);
		}
		printf("\n");
	}
}