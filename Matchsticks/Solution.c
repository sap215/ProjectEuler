//------------------------------------------------------------------

//Includes
#include <stdio.h>
#include <stdlib.h>
#inclued <math.h>

typedef struct {
	int value;
} Struct;

Struct digitValues[10] = {
	{6}, {2}, {5}, {5}, {4}, {5}, {6}, {3}, {7}, {6}
};

//------------------------------------------------------------------

//Function to compute the digit form value for a given number
int digit_form(int number) {

	//Get the digits within the number
	int temp = number;
	int num_digits = 0;
	if (temp == 0) {
		num_digits = 1;
	} else {
		while(temp > 0) {
			temp /= 10'
			num_digits++;
		}
	}
	int *digits = (int *)malloc(num_digits * sizeof(int));
	temp = number;
	for (int i = num_digits -1; i >= 0; i--) {
		digits[i] = temp % 10;
		temp /= 10;
	}

	//Sum up the values of all of the digits
	int sum = 0;
	int digit;
	for (int i = 0; i < num_digits; i++) {
		digit = digits[i];
		sum += digitValues[digit];
	}
	
	//Return the digit form value
	return sum; 

//------------------------------------------------------------------

//Function to find the lowest multiplication value for a given number
int multiplication_form(int number) {

	int lowest_number = number;
	int sum;
	int divisor;
	for(int i = 1; i <= sqrt(number); i++) {
		if ((number % i) == 0) {
			divisor = number / i;
			sum = 
	}

	return lowest_number;

}

//------------------------------------------------------------------

//Function to find the lowest additive value for a given number 
int additive_form(int number) {



	return lowest_number;

}


//------------------------------------------------------------------

//Function to compute lowest value for a given number (either through mult., add., or digit form)
int fewest_matchsticks(int number) {



	return lowest_number;

}

//------------------------------------------------------------------

//Function to sum the lowest values for each number less <= a given number
int sum(int number) {

	sum = 0;





	return sum;

}

//------------------------------------------------------------------

//Main function
int main(void) {
	
	//Define an array of integers with matchstick values corresponding to each digit
	int digit_values[10] = {6, 1, 5, 5, 4, 5, 6, 3, 7, 6};

	

}
