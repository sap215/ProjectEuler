//--------------------------------------------------

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//--------------------------------------------------

//Function to add all factors (from 1 to sqrt(given_number)) to an array (a 0 will be added if a given number isn't a factor)
void find_factors(long long int given_number, int sqrt_given_number, int Factors[]) {	

	int Number;

	//Add all of the factors from 1 up to sqrt of given_number to an array
	for (Number = 1; Number < (sqrt_given_number + 1); Number++) {
		if ((given_number % Number) == 0) {
			Factors[Number-1] = Number;
		} else {
			Factors[Number-1] = 0;
		}
	}

}

//--------------------------------------------------

//Function to find the greatest common divisor between two numbers (using the Euclidean Algorithm)
int greatest_common_divisor(int a, int b) {

	while (b != 0) {
		int c = b;
		b = a % b;
		a = c;
	}
	
	return(a);

}

//--------------------------------------------------

//Function to determine if a number is prime (given it's gcd with 2 is equal to 1)
int fermats_little_theorem(int p) {
	
	int result = 1;
	int base = 2;
	int b = (p - 1);
	
	while (b > 0) {
		//The case where (p-1) is odd
		if ((b % 2) == 1) {
			result = ((result * base) % p);
		}
		base = (base * base) % p;
		b = b / 2;
	}

	//Safety check for Carmichael numbers
	int check;
	for (check = 2; check * check <= p; check++) {
		if ((p % check) == 0) {
			return(0);
		}
	}
	
	//Returns either 0 or 1, 1 implies prime
	return(result);
}

//--------------------------------------------------

//Function to keep only the prime numbers in our array
void keep_primes(long long int given_number, int sqrt_given_number, int Factors[]) {

	int Index;
	int a;
	int b;
	int gcd;
	int a_is_prime;
	int b_is_prime;
	
	//For each of the factors (from 1 up to sqrt of given_number), check if that number (or its multiple) is a prime
	//If one of the two is a prime, keep it. If neither are prime, change the array element to a 0. If both are prime, keep the larger prime
	for (Index = 0; Index < (sqrt_given_number - 1); Index++) {

		//Make sure the number at the array index isn't equal to 2
		if ((Factors[Index] != 2) && (Factors[Index] != 0)) { 

			//From Fermat's Little Theorem (with a = 2) we know a number, p, is prime iff gcd(a,p) = 1 and a^(p-1) is congruent to 1 (mod p)
			a = Factors[Index];
			b = given_number / a;
		
			//Check if a is prime
			gcd = greatest_common_divisor(2, a);
			if (gcd == 1) {
				a_is_prime = fermats_little_theorem(a);
			} else {
				a_is_prime = 0;
			}

			//Check if b is prime
			gcd = greatest_common_divisor(2, b);
			if (gcd == 1) {
                                b_is_prime = fermats_little_theorem(b);
                        } else {
                        	b_is_prime = 0;
			}
			
			if ((a_is_prime == 1) && (b_is_prime == 0)) {
				Factors[Index] = a;
			} else if ((a_is_prime == 0) && (b_is_prime == 1)) {
                                Factors[Index] = b;
                        } else if ((a_is_prime == 1) && (b_is_prime == 1)) {
				if (a > b) {
					Factors[Index] = a;
				} else {
					Factors[Index] = b;
				}
                        } else if ((a_is_prime == 0) && (b_is_prime == 0)) { 
				Factors[Index] = 0;
			}
		}
	}	
}

//--------------------------------------------------

//Function to find the largest prime number in our array
int find_largest_prime(int sqrt_given_number, int Factors[]) {
	
	int max = 0;
	int Index;

	for (Index = 0; Index < (sqrt_given_number - 1); Index++) {
		if (Factors[Index] > max) {
			max = Factors[Index];
		}
	}

	return(max);

}

//--------------------------------------------------

//Main function
int main() {

	//Define variables
	long long int given_number;
	int largest_prime_divisor;
	int sqrt_given_number; //If a number has a factor, then one of the numbers within that factor must be less than the sqrt of the number

	//Promp user for number
	printf("Enter a number: ");
	scanf("%lld", &given_number);

	sqrt_given_number = sqrt(given_number);
	int Factors[sqrt_given_number];
	
	//Call a function to find all possible factors of the sqrt of given_number
	find_factors(given_number, sqrt_given_number, Factors);

	//Call a function to find the prime numbers out of all possible factors of sqrt of given_number
	keep_primes(given_number, sqrt_given_number, Factors);

	//Call a function to find the largest prime factor of GIVEN_NUMBER (this function returns the max)
	largest_prime_divisor = find_largest_prime(sqrt_given_number, Factors);

	printf("Largest Prime Factor: %d\n", largest_prime_divisor);

}

//--------------------------------------------------
