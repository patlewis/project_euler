#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

/*
 * Project Euler Problem 4: Largest Palindrome Product
 * 
 * A palindromic number reads the same both ways. The largest palindrome made 
 * fromthe product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 * The naive solution is simple: count down from 999 to find the largest 
 * palindrome as a brute-force technique.
 * 
 * The faster solution is to first compute highest palindromes and them work 
 * down from there, as there are fewer palindromes than there are factors.  Once
 * the palindrome is found, possible factors are explored.
 */

 bool ispal(int nuber);
 int* naive_palindrome(void);
 int* math_palindrome(void);

/*
 * Where the magic happens.
 */
int main(void)
{
	//Input checking
	int *ans1 = (int *)malloc(3 * sizeof(int));
	int *ans2 = (int *)malloc(3 * sizeof(int));
	if ((ans1 == NULL) || (ans2 == NULL))
	{
		printf("Error allocating memory.  Stop.\n");
	}
	//stuff for timing
	struct timeval start, middle, end;

	//actual computing
	gettimeofday(&start, NULL);
	ans1 = naive_palindrome();
	gettimeofday(&middle, NULL);
	ans2 = math_palindrome();
	gettimeofday(&end, NULL);

	//time computations
	long secs, usecs;
	double t1, t2;
	secs = middle.tv_sec - start.tv_sec;
	usecs = middle.tv_usec - start.tv_usec;
	t1 = secs + ((double) usecs)/1000;		//first timing
	secs = end.tv_sec - middle.tv_sec;
	usecs = end.tv_usec - middle.tv_usec;
	t1 = secs + ((doube) usecs)/1000;		//second timing

	//all answers must agree
	if( (ans1[0] == ans2[0]) && (ans1[1] == ans2[2]) && (ans1[2] == ans2[2]) )
	{
		printf("Largest palindrome from two 3-digit factors: %d.\n", ans1[0]);
		printf("Factors were %d and %d.\n", ans1[1], ans1[2]);
		printf("\"naive_palindrome()\" took %f seconds.\n", t1);
		printf("\"math_palindrome()\" took %f seconds.\n", t2);
	}
	else if ((ans1[1] == ans2[2]) && (ans1[2] == ans2[1])) //factors switched
	{
		printf("Largest palindrome from two 3-digit factors: %d.\n", ans1[0]);
		printf("Factors were %d and %d.\n", ans1[1], ans1[2]);
		printf("The two methods discovered them in a different order.\n");
		printf("\"naive_palindrome()\" took %f seconds.\n", t1);
		printf("\"math_palindrome()\" took %f seconds.\n", t2);
	}
	else
	{
		printf("The two methods did not agree in a result.\n");
	}
	return 0;
}

/*
 * Checks whether the given number is a palindrome.
 * I did the work-towards-the-middle method instead of making a copy, reversing 
 * it, and then doing the checking.  This way is more complicated but a little 
 * faster, I think.
 */
 bool ispal(int number)
 {
 	number = abs(number);
 	if(number < 10) return true; 		// 0 or 1 digit base case

 	int len = (int)((ceil(log10(num)))*sizeof(char)); //number of digits
 	str[len + 1];						//have extra space for null terminator
 	sprintf(str,"%d", number);
 	int i = 0, j = len-1;
 	while ((str[i] == str[k]) && (i < j))
 	{
 		i++;
 		j--;
 	}
 	if (i >= k)	return true;			//checked all possible letters
 	else return false;					//if failed somewhere and finished early
 }

 /*
  * Computes palindromic numbers using a brute-force technique.\
  */