/*Lab 2, C Calculator */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

	char user_first_input;
	char exit = 'q';
	bool operation_validity;
	bool num_validity;
	bool integer_validity;
	char num_of_ints;
	int int_num_of_ints;

	do {

	// Function to determine if operation is a valid option.

		int validOperation(char user_first_input) {
			
			if (user_first_input == '+' || user_first_input == '-' || user_first_input == '*' || user_first_input == '/') {
				operation_validity = true;
				return operation_validity;
				
			} else if (user_first_input == 'q') {
				user_first_input = exit;
				operation_validity = true;
				return operation_validity;

			} else {
				operation_validity = false;
				printf("Please enter a vaild operation\n");
				return operation_validity;
			}
		}

	// Function to ensure number of integers is valid.
	
		int validNumberInts(char num_of_ints) {

			if  (isdigit(num_of_ints) != 0 && num_of_ints != '1' && num_of_ints != '0') {
				num_validity = true;
				return num_validity;

			} else {
				num_validity = false;
				printf("Please enter an integer greater than 1\n");
				return num_validity;
			}
		}

	// Function to ensure the entered integer is valid.
	
		int validInteger(char currentIntVal) {
		
			if (isdigit(currentIntVal) != 0) {
				integer_validity = true;
				return integer_validity;
			} else {
				integer_validity = false;
				printf("Please enter an integer\n");
				return integer_validity;
			}
		}

	// Ask user for input, and continue asking until valid input.

		do {
			operation_validity = false;
			int ch;
			user_first_input = '/';

			printf("Enter operation: ");
			scanf(" %c", &user_first_input);	

			validOperation(user_first_input);	

		} while (operation_validity != true);


	// Ask the user for a number of integers, and continue asking until valid input.
		
		if (user_first_input != exit) {
			do {
				num_validity = false;

				printf("Enter number of integers: ");
				scanf(" %c", &num_of_ints);

				int_num_of_ints = num_of_ints - '0';

				validNumberInts(num_of_ints);

			} while (num_validity != true);


	// Create array to store integers, then ask for each of the integers.
	
			char enteredIntegerChars[int_num_of_ints-1]; // Array for characters
			int enteredIntegersConverted[int_num_of_ints-1]; // Array for ints
			int i;

			for (i = 1; i <= int_num_of_ints; ++i) {
				do {
					integer_validity = false;

					printf("%s %d%s", "Enter integer", i, ": ");
					scanf(" %c", &enteredIntegerChars[i-1]);

					char currentIntVal = enteredIntegerChars[i-1];

					int intCurrentIntVal = currentIntVal - '0';
					enteredIntegersConverted[i-1] = intCurrentIntVal;

					validInteger(currentIntVal);

				} while (integer_validity != true);
			}

	// Compute result.
			int computation = enteredIntegersConverted[0];

			printf("\n%s %d ", "Computing:", enteredIntegersConverted[0]);

			switch(user_first_input) {
				
				case '/' :
					for (i = 1; i < int_num_of_ints; ++i) {
						printf("%c %d ", '/', enteredIntegersConverted[i]); 
						computation /= enteredIntegersConverted[i];
					} break;
				
				case '*' :
					for (i = 1; i < int_num_of_ints; ++i) {
						printf("%c %d ", '*', enteredIntegersConverted[i]);
						computation *= enteredIntegersConverted[i];
					} break;

				case '+' :
					for (i = 1; i < int_num_of_ints; ++i) {
						printf("%c %d ", '+', enteredIntegersConverted[i]);
						computation += enteredIntegersConverted[i];
					} break;
					
				case '-' :
					for (i = 1; i < int_num_of_ints; ++i) {
						printf("%c %d ", '-', enteredIntegersConverted[i]);
						computation -= enteredIntegersConverted[i];
					} break;
			}	

			printf("%c %d", '=', computation);
			printf("\n\n");
	
	// Print entire computing expression to user.



		}

	// Quit the program when q is entered

	} while (user_first_input != exit);
	
	return 0;
}
