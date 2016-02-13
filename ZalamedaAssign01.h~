void NumToWords(){
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

