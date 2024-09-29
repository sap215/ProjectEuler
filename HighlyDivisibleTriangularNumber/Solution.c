//-----------------------------------------------------

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//-----------------------------------------------------

//Function to find the number of divisors in a given triangular number
int find_divisors(long long int triangle_number) {

	int num_divisors = 0;
	int i;

	//Brute-force method for finding all divisors
	for (i = 1; i <= sqrt(triangle_number); i++) {
		if ((triangle_number % i) == 0) {
			if (triangle_number / i == i) {
				num_divisors += 1;			
			} else {
				num_divisors += 2;
			}
		}
	}

	return (num_divisors);

}

//-----------------------------------------------------

//Main function
int main() {

	long long int triangle_number = 0;
	int divisor_target;
	int max = 0;
	int iterator = 1;

	//Promp user for value
	printf("For what number of divisors would you like to find the first triangle number that has at least that many divisors: ");
	scanf("%d", &divisor_target);

	//Find divisors for each triangle number up until divisor_target is found
	while (max <= divisor_target) {
		triangle_number = ((iterator * (iterator + 1)) / 2);
		max = find_divisors(triangle_number);
		iterator++;
	}

	printf("The triangle number is: %lld\n", triangle_number);

	return (EXIT_SUCCESS);
}

//-----------------------------------------------------
