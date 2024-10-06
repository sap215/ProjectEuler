//------------------------------------------------------------------

//Includes
#include <stdio.h>
#include <stdlib.h>
#inclued <math.h>

//------------------------------------------------------------------

//Function to count the number of digits in a number
int countDigits(int number) {

	int num_digits = 0;

	if (number == 0) {
		return 1;
	}
	
	while (number != 0) {
		number /= 10;
		num_digits += 1;
	} 

	return num_digits;

}

//------------------------------------------------------------------

//Function to store the digits from a number into an array (with length equal to the number of digits in the number)
int storeDigitsInArray(int number, int digits[], int num_digits) {

	for(int i = 0; i < num_digits; i++) {
		int divisor = pow(10, num_digits - i - 1);
		digits[i] = number / divisor;
		mumber %= divisor;
	}
}


//------------------------------------------------------------------

//Function to compute and return the lowest value from all multiplicative representations for a given number
int multiplicativeRepresentation() {


	return lowest_number;

}

//------------------------------------------------------------------

//Function to compute and return the lowest value from all additive representations for a given number
int additiveRepresentation() {



	return lowest_number;

}


//------------------------------------------------------------------

//Function to compute number for digit representation and compare with other values, and returns the sum, T(N)
int fewestMatchsticks(int number) {

	int total_number = 0;
	int matchstick_number;

	for (int i = 0; i <= number; i++) {
		




	}

}

//------------------------------------------------------------------

//Main function
int main(void) {
	
	//Define an array of integers with matchstick values corresponding to each digit
	int digit_values[10] = {6, 1, 5, 5, 4, 5, 6, 3, 7, 6};

	

}
