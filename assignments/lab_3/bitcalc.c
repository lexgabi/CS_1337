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
//	char allBinaryNum[total_ints-1][35];
//	char converted_binary[4];
//	char binary_conv[4];
	bool operation_validity;
	bool num_validity;
	bool hex_validity;
	int converted_dec;
	int total_ints;


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
	
	int i;
	int int_check = 1;

	for (i=0; i < strlen(num_of_ints); ++i) {
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
	int i;
	int hex_check = 1;

	for (i=0; i < strlen(current_hex_val); ++i) {
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
	
	// Function to convert
	//
int decToBinary(char hexConvertedDec[]) {
	int i, compare;

	for (i = 31; i >= 0; i--) {
		compare = converted_dec >> i;
		if (compare & 1) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n\n");
}
	
/*		int convertToDec(int converted_dec) {
			int i, compare;
			for (i=31; i>=0; i--) {
				compare = converted_dec >> i;
				if (compare & 1) {
					printf("1");
				} else
					printf("0");
			}
		} */

//		const char* convertToBinary(char current_hex_val[]) {
//			int i;
//			int missing_val = strlen(current_hex_val) % 8;
//			if (missing_val != 0) {
//				for (i=8; i > missing_val; --i) {
//					printf("0000");
//				}
//			}



	// Ask user for input, and continue asking until valid input.
int main() {

	do {
		do {
			operation_validity = false;

			printf("Enter operation: ");
			scanf(" %s", user_first_input);	

			validOperation(user_first_input);	

		} while (operation_validity != true);


	// Ask the user for a number of integers, and continue asking until valid input.
		
		if (operation != 'q') {
			do {
				num_validity = false;

				printf("Enter number of integers: ");
				scanf(" %s", num_of_ints);

				validNumberInts(num_of_ints);

			} while (num_validity != true);
		

	// Create array to store integers, then ask for each of the integers.
	
			total_ints = atoi(num_of_ints);
			char totalHexs[total_ints-1][8];// Array of string hexadecimals
			char current_hex_val[8];// Array to access most recent input string
		
			int hexConvertedDec[total_ints-1]; // Array for converted decimals
//			int binaryNum[32]; // Array for current converted binary
//			int hexConvertedBi[total_ints-1][32]; // Array for all converted binaries

			int i, j, bi_compare;

			for (i = 0; i < total_ints; ++i) {
				do {
					hex_validity = false;

					printf("%s %d%s", "Enter integer", i+1, ": ");
					scanf(" %s", current_hex_val);

					memcpy(totalHexs[i], current_hex_val, sizeof(current_hex_val));

					validHex(current_hex_val);

					converted_dec = (int)strtol(current_hex_val, NULL, 16);

					hexConvertedDec[i] = converted_dec;

//					decToBinary(converted_dec);

/*					for (j = 31; j >= 0; --j) {
						bi_compare = converted_dec >> j;
						if (bi_compare & 1) {
							binaryNum[31-j] = 1;
						} else {
							binaryNum[31-j] = 0;
						}
					}

					memcpy(hexConvertedBi[i], binaryNum, sizeof(binaryNum));
*/
//					convertToBinary(current_hex_val);
//					converted_dec = convertToDec(current_hex_val);
//					hexConvertedDec[i] = converted_dec;


		//			printf("%d\n", converted_dec);
					
		//			char binary_conv[] = "";
		//			printf("%s\n", binary_conv);
		//			memcpy(converted_binary[i], binary_conv, sizeof(binary_conv));


				} while (hex_validity != true);
			}

			

	// Compute result and print hexadecimal operation
			int computation = hexConvertedDec[0];

			printf("\n%s\n\t  %08X", "Hexadecimal operation:", hexConvertedDec[0]);

			switch(operation) {
				
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
			
			printf("\n\t%c %08X", '=', computation);
			printf("\n\n");

		decToBinary(hexConvertedDec[0]);

			
/*
			int compare;
			for (i = 31; i >= 0; i--) {
				compare = hexConvertedDec[0] >> i;
				if (compare & 1) {
					printf("1");
				} else {
					printf("0");
				}
			}

*/
//			printf("%s\n\t  %d", "Binary operation:", convertToDec(hexConvertedDec[0]));
			

	
	// Print binary operation
	



		}

	// Quit the program when q is entered

	} while (operation != 'q');
	
	return 0;
}
