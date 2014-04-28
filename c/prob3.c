#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

/*
 * Project Euler Problem 3: Prime Factorization
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 
 *
 * After a little bit of research, it looks like there isn't any "good" 
 * algorithm for this. The best I could really do would be to do a trial 
 * division, where you just divide a number n by each integer up to sqrt(n).
 * This one is a little different though, because as soon as I find a factor, I
 * divide the number I'm testing by that factor so that I don't accidently find
 * that factor again.
 *
 */

int factors(unsigned long);

 int main(int argc, char* argv[])
 {
 	// The commented stuff was just for test values.  I don't really care
 	// about the test values anymore.
 	// if (argc != 2)
 	// {
 	// 	printf("Usage: sol3 <int> where <int> is an integer to find the prime");
 	// 	printf(" factorization of.\n");
 	// 	return 0;
 	// }
 	//long arg = atoi(argv[1]);
 	printf("========== Problem 3 ==========\n");
 	printf("Greatest Prime Factor: %d\n", factors(600851475143));
	printf("===============================\n");
 	return 0;
 }

 int factors(unsigned long num)
 {
 	long numm =  num; //for negatives
 	assert(numm > 2); //or else it's pretty pointless
 	int greatestfactor = 1;
 	int x;
 	int STOP = floor(sqrt(numm));
 	for(x = 2; x < STOP; x++)
 	{
 		while(numm % x == 0) 	//this x is a factor
 		{
 			greatestfactor = x;
 			numm /= x; 		//to find duplicates of this factor
 		}
 	}
 	if (greatestfactor == 1) greatestfactor = numm; //if already prime
 	return greatestfactor;
 }
