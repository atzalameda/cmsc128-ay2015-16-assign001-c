/**************************************************
	Zalameda, Angelica T.
	2013-54721
	CMSC 128 AB-2L
	Assign 001: Programming a Number Library 
**************************************************/

#include<stdio.h>
#include"ZalamedaAssign01.h"

int main(){
	int choice;
	
	while(choice != 5){
		printf("\n\t   NUMBER LIBRARY\n\n");
		printf("\t[1] Number to Words\n\t[2] Words to Number\n\t[3] Words to Currency\n\t[4] Number Delimited\n\t[5] Exit\n");
		printf("\tChoice: ");
		scanf("%d", &choice);
	
		switch(choice){
			case 1: printf("\n\t NUMBER TO WORDS\n");
					NumToWords();
				break;
				
			case 2: printf("\n\t WORDS TO NUMBER\n");
					WordsToNum();
				break;
				
			case 3: printf("\n\t WORDS TO CURRENCY\n");
				break;
				
			case 4: printf("\n\t NUMBER DELIMITED\n");
					NumberDelimiter();
				break;
				
			case 5: printf("\n\t\tGOODBYE!\n\n");
				break;
				
			default: printf("\n\t   INVALID INPUT!\n");
				break;
		}
	}
	
}
