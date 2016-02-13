#include<string.h>
#include<stdio.h>

void NumToWords(){ // function for converting number to words
	int num, quotient, temp;
	int skip = 0;
	char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
	char *twos[] = { "", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char *tens[] = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *two_digits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" }; 
	
	printf("Enter a number (0 - 1,000,000 without commas): "); // asks for input from the user
	scanf("%d", &num);
	
	if(num == 0){ // if the input is 0 then it will just print zero
		printf("OUTPUT: zero");
	} else if(num > 1000000){ // if the input exceeds 1,000,000 the it is invalid
		printf("\n  INVALID INPUT! EXCEEDED MAX NUMBER! \n");
	} else{
		printf("OUTPUT: ");
		while(num != 0){ // loops until the input is greater than 0
			if((num / 1000000) > 0){ // prints the MILLION place. 
				quotient = num / 1000000;
				printf("%s million ", ones[quotient]);
				break;
			} 
			
			if((num / 100000) > 0){ // prints the HUNDRED THOUSAND place
				quotient = num / 100000; 
				num = num % 100000;
				if(num == 0) printf("%s hundred thousand ", ones[quotient]);
				else if ((num/10000) == 0 && ((num%10000)/1000) == 0) printf("%s hundred thousand ", ones[quotient]);
				else printf("%s hundrend ", ones[quotient]);
			}
			
			if((num / 10000) > 0){ // prints the TEN THOUSAND place
				quotient = num / 10000;
				num = num % 10000;
				if(num == 0) printf("%s thousand ", tens[quotient]);
				else if (quotient == 1 && num > 1000){
					temp = num / 1000;
					num = num % 1000;
					printf("%s thousand ", twos[temp+1]);
					skip = 1;
				} else printf("%s ", tens[quotient]);
			}
			
			if((num / 1000) > 0){ // prints the THOUSAND place
				if(skip == 0){
					quotient = num / 1000;
					num = num % 1000;
					printf("%s thousand ", ones[quotient]);
				}
			}
			
			if((num / 100) > 0){ // prints the HUNDRED place
				quotient = num / 100;
				num = num % 100;
				printf("%s hundred ", ones[quotient]);
			}
			
			if((num / 10) > 0){ // prints the TENS place
				quotient = num / 10;
				num = num % 10;
				if(quotient == 1){
					printf("%s ", two_digits[num]);
					break;
				} else printf("%s ", tens[quotient]);
			}
			
			if((num / 1) > 0){ // prints the ONES place
				quotient = num / 1;
				num = num % 1;
				printf("%s ", ones[quotient]);
			}
		}
	}
	printf("\n\n");	
}

void WordsToNum(){ // function for converting number in word form to number
	char number[100];
	char *str, *temp;
	int num = 0, total = 0;
	int i = 0, tmp = 0;
	int flag = 0, hundreds;
	
	getchar();
	printf("Enter a number in word form (zero to one million in LOWERCASE): "); // asks for input from the user
	fgets(number, 100, stdin);
	
	temp = strtok(number, "\n"); // removes the newline at the end of the string
	
	str = strtok(temp, " "); // splits the string by spaces
	while(str != NULL){ // loop until str is not NULL
		// for ones place
		if(strcmp(str, "zero") == 0) num = 0;
		else if(strcmp(str, "one") == 0) num = 1;
		else if(strcmp(str, "two") == 0) num = 2;
		else if(strcmp(str, "three") == 0) num = 3;
		else if(strcmp(str, "four") == 0) num = 4;
		else if(strcmp(str, "five") == 0) num = 5;
		else if(strcmp(str, "six") == 0) num = 6;
		else if(strcmp(str, "seven") == 0) num = 7;
		else if(strcmp(str, "eight") == 0) num = 8;
		else if(strcmp(str, "nine") == 0) num = 9;
		// for -teens place
		else if(strcmp(str, "ten") == 0) num = 10;
		else if(strcmp(str, "eleven") == 0) num = 11;
		else if(strcmp(str, "twelve") == 0) num = 12;
		else if(strcmp(str, "thirteen") == 0) num = 13;
		else if(strcmp(str, "fourteen") == 0) num = 14;
		else if(strcmp(str, "fifteen") == 0) num = 15;
		else if(strcmp(str, "sixteen") == 0) num = 16;
		else if(strcmp(str, "seventeen") == 0) num = 17;
		else if(strcmp(str, "eighteen") == 0) num = 18;
		else if(strcmp(str, "nineteen") == 0) num = 19;
		// for tens place
		else if(strcmp(str, "twenty") == 0) num = 20;
		else if(strcmp(str, "thirty") == 0) num = 30;
		else if(strcmp(str, "forty") == 0) num = 40;
		else if(strcmp(str, "fifty") == 0) num = 50;
		else if(strcmp(str, "sixty") == 0) num = 60;
		else if(strcmp(str, "seventy") == 0) num = 70;
		else if(strcmp(str, "eighty") == 0) num = 80;
		else if(strcmp(str, "ninety") == 0) num = 90;
		// for hundreds
		else if(strcmp(str, "hundred") == 0){
			tmp = total; // copies the value of total
			tmp = tmp - (tmp % 10); // removes the added ones
			hundreds = (total % 10) * 100; // stores the multiplied hundreds
			num = hundreds + tmp; // adds tmp(with no added one) and the hundred place
			total = 0; // resets total
		} else if(strcmp(str, "thousand") == 0){
			tmp = total;
			num = tmp * 1000;
			total = 0;
		} else if(strcmp(str, "million") == 0){
			tmp = total;
			num = tmp * 1000000 - total;
			total = 0;
		}
		
		total += num;
		
		str = strtok(NULL, " ");
	}
	printf("OUTPUT: %d\n", total);
}

void NumberDelimiter(){ // function for adding a single character delimiter to the  
	char num[10], temp[10];
	char delimiter, str;
	int position;
	int i, j, k, sizeNum;

	printf("Enter a number (0 - 1,000,000 without commas): "); // asks for input from the user
	scanf("%s", num);
	getchar();
	printf("Enter a single-character delimiter: "); // asks for the delimiter to be added to the string
	scanf("%c", &delimiter);
	printf("Enter the number of places for the delimiter: "); // asks the number of places to put the delimiter
	scanf("%d", &position);
	
	sizeNum = strlen(num); // to store the size of the string
	position = sizeNum - position;
	k = position + 1; // holds the index of the array next to the place of the delimiter

	strcpy(temp, num); // copies the string to another string
	
	for(i=position; i<sizeNum+1; i++){ // loop that starts with the position to be replaced
		str = temp[i]; // temporarily copies the character
		if(i == position){
			num[i] = delimiter; // replaces the stored string with the delimiter
		}
		num[k] = str; // stores the character removed to the next position in the array
		k++; // increments the index
	}
	
	printf("OUTPUT: %s\n", num);
	getchar();

}

