/*Lab 3, C Bit Calculator */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


char user_first_input[100];
char operation;
char num_of_ints[100];
char binaryNum[35];
char binary[1];
bool operation_validity, num_validity, hex_validity;	
int total_ints, j, converted_dec;


// Function to determine if operation is a valid option.

int validOperation(char user_first_input[]) {

	if (strlen(user_first_input) == 1) {
		if (strcmp(user_first_input, "q") == 0) {
			operation = 'q';
			operation_validity = true;
			return operation_validity;
		} else if (strcmp(user_first_input, "|") == 0) {
			operation = '|';
			operation_validity = true;
			return operation_validity;
		} else if (strcmp(user_first_input, "&") == 0) {
			operation = '&';
			operation_validity = true;
			return operation_validity;
		} else if (strcmp(user_first_input, "^") == 0) {
			operation = '^';
			operation_validity = true;
			return operation_validity;
		} else
			operation_validity = false;
			printf("Please enter |, &, ^, or q\n");
			return operation_validity;


	} else {
		operation_validity = false;
		printf("Please enter |, &, ^, or q\n");
		return operation_validity;
	}
}

// Function to ensure number of integers is valid.
	
int validNumberInts(char num_of_ints[]) {
	if (strcmp(num_of_ints, "1") == 0 || strcmp(num_of_ints, "0") == 0) {
		num_validity = false;
		printf("Please enter an integer greater than 1\n");
		return num_validity;
	}

	int int_check = 1;

	for (int i=0; i < strlen(num_of_ints); ++i) {
		if (isdigit(num_of_ints[i]) != 0) {
			int_check *= 1;
		} else {
			int_check *= 0;
		}
	}

	if (int_check == 1) {
		num_validity = true;
	} else {
		num_validity = false;
		printf("Please enter an integer greater than 1\n");
	}

	return num_validity;
}

// Function to ensure the entered hexadecimal is valid: must be 8 or less in hex, 0-9 and A-F
	
int validHex(char current_hex_val[]) {
	int hex_check = 1;

	for (int i=0; i < strlen(current_hex_val); ++i) {
		if (isdigit(current_hex_val[i]) != 0) {
			hex_check *= 1;
		} else if (isxdigit(current_hex_val[i]) != 0) {
			hex_check *= 1;
		} else {
			hex_check *= 0;
		}
	}
	if (hex_check ==1 && strlen(current_hex_val) <= 8) {
		hex_validity = true;
	} else {
		hex_validity = false;
		printf("Please enter an 8-digit hexadecimal integer\n");
	}

	return hex_validity;
}


int main() {

	do {
		do {
			operation_validity = false;

			printf("Enter operation: "); // Ask user for operation
			scanf(" %s", user_first_input);	

			validOperation(user_first_input); // Ensure entered operation is valid	

		} while (operation_validity != true); // Continue asking until valid operation

		
		if (operation != 'q') { // If user enters q, skip the rest of the main function
			do {
				num_validity = false;

				printf("Enter number of integers: ");
				scanf(" %s", num_of_ints); // Ask user for number of integers

				validNumberInts(num_of_ints); // Ensure entered number is valid

			} while (num_validity != true); // Continue asking until valid input
		
	
			total_ints = atoi(num_of_ints);

			char totalHexs[total_ints-1][8];// String array of entered hexadecimals
			char current_hex_val[8];// Array to access most recent input string
		
			int hexConvertedDec[total_ints-1]; // Integer array for converted decimals

			int bi_compare;

			for (int i = 0; i < total_ints; ++i) {
				do {
					hex_validity = false;

					printf("%s %d%s", "Enter integer", i+1, ": ");
					scanf(" %s", current_hex_val); // Ask user for each hexadecimal

					memcpy(totalHexs[i], current_hex_val, sizeof(current_hex_val));

					validHex(current_hex_val); // Validate entered hexadecimals

					converted_dec = (int)strtol(current_hex_val, NULL, 16);

					hexConvertedDec[i] = converted_dec; // Store converted decimals


				} while (hex_validity != true); // Ask for input until valid
			}

			
// Using entered values, perform required operations and print results

			int computation = hexConvertedDec[0];
			int i;

			printf("\n%s\n\t  %08X", "Hexadecimal operation:", hexConvertedDec[0]);

			switch(operation) { // Prints Hexadecimal based on operation entered
				
				case '|' :
					for (i = 1; i < total_ints; ++i) {
						printf("\n\t%c %08X", '|', hexConvertedDec[i]); 
						computation = computation | hexConvertedDec[i];
					} break;
				
				case '&' :
					for (i = 1; i < total_ints; ++i) {
						printf("\n\t%c %08X", '&', hexConvertedDec[i]);
						computation = computation & hexConvertedDec[i];
					} break;

				case '^' :
					for (i = 1; i < total_ints; ++i) {
						printf("\n\t%c %08X", '^', hexConvertedDec[i]);
						computation = computation ^ hexConvertedDec[i];
					} break;
					
			}
			
			printf("\n\t%c %08X\n\n", '=', computation);

			printf("%s\n\t ", "Binary operation:");
			
			for (int j = 0; j < total_ints; ++j) { // Converts input to binary and prints
				if (operation == '|' && j != 0) {
					printf("|");
				} else if (operation == '&' && j != 0) {
					printf("&");
				} else if (operation == '^' && j != 0) {
					printf("^");
				}
				for (i = 31; i >= 0; i--) {
					int compare = hexConvertedDec[j] >> i;
					if ((i+1) % 8 == 0) {
						printf(" ");
					}
					if (compare & 1) {
						printf("1");
					} else {
						printf("0");
					}
				}
				printf("\n\t");
			}
			printf("%c", '=');

			for (i = 31; i >= 0; i--) { // Converts computation to binary and prints
				int compare = computation >> i;
				if ((i+1) % 8 == 0) {
					printf(" ");
				}
				if (compare & 1) {
					printf("1");
				} else {
					printf("0");
				}
			}
			printf("\n\n");

		}

	} while (operation != 'q'); // Quits the program when q is entered
	
	return 0;
}
