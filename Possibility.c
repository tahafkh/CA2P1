#include"Possibility.h"
#include"ConvertTrue.h"
#include"ValidInput.h"
int Possibility(char Table[8][8],int Turn) {
	int Possible =0, Column1[2] = { 0,0 }, Row1[2] = { 0,0 }, Diameter1[4] = { 0,0,0,0 };
	char Row = '1', Column = '1';
	for (Row = '1'; Row <= '8'; Row++) {
		for (Column = '1'; Column <= '8'; Column++) {
			if(ValidInput(Row,Column,Table,Turn,Row1,Column1,Diameter1)==0){/*Check Validity for all cells in the table*/
				Possible = 1;
			}
		}
	}
	if (Possible==0)
		return 0;
	return 1;
}