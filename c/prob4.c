#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>

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
		exit(1);
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
	t1 = secs + ((double) usecs/1000000);		//first timing
	secs = end.tv_sec - middle.tv_sec;
	usecs = end.tv_usec - middle.tv_usec;
	t2 = secs + ((double) usecs/1000000);		//second timing

	//all answers must agree
	if(ans1[0] == ans2[0])
	{
		printf("Largest palindrome from two 3-digit factors: %d.\n", ans1[0]);
		//printf("naive_solution factors were %d and %d.\n", ans1[1], ans1[2]);
		//printf("math_solution factors were %d and %d.\n", ans2[1], ans2[2]);
		printf("\"naive_palindrome()\" took %f seconds.\n", t1);
		printf("\"math_palindrome()\" took %f seconds.\n", t2);
	}
	else
	{
		printf("The two methods did not agree in a result.\n");
		printf("naive_palindrome gave %d and math_palindrome gave %d.\n", \
			ans1[0], ans2[0]);
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

	int len = (int)((ceil(log10(number)))); //number of digits
	char str[(len + 1) * sizeof(char)];						//have extra space for null terminator
	sprintf(str,"%d", number);
	int i = 0, j = len-1;
	while ((str[i] == str[j]) && (i < j))
	{
		i++;
		j--;
	}
	if (i >= j)	return true;			//checked all possible letters
	else return false;					//if failed somewhere and finished early
	}

/*
 * Computes palindromic numbers using a brute-force technique.\
 */
int* naive_palindrome()
{
	int *answers = (int *)malloc(3 * sizeof(int));
	if(answers == NULL)
	{
		printf("Memory error. Stop.\n");
		exit(1);
	}
	answers[0] = 0;//where the palindrome is stored
	answers[1] = 0;//the first factor
	answers[2] = 0;//the second factor
	int x, y, val;
	for (x = 500; x < 1000; x++)
	{
		for (y = 500; y < 1000; y++)
		{
			val = x * y;
			if( ispal(val) && (val > answers[0]))
			{
				answers[0] = val;
				answers[1] = x;
				answers[2] = y;
			}
		}
	}
	return answers;
}

/*
 * Uses mathematical properties to calculate the palindromes first, and then 
 * find three digit factors that are acceptabe.
 */
int *math_palindrome()
{
    int *answers = (int *)malloc(3 * sizeof(int));
	if(answers == NULL)
	{
		printf("Memory error. Stop.\n");
		exit(1);
	}
	answers[0] = 0;//where the palindrome is stored
	answers[1] = 0;//the first factor
	answers[2] = 0;//the second factor
	int a, b, c, x, pal;	//if you need to know what they are, read the paper
	for(a = 9; a >= 0; a--)
	{
		for(b = 9; b >= 0; b--)
		{
			for(c = 9; c >= 0; c--)
			{
				pal = 9091*a + 910*b + 100*c;
				for(x = 90; x >= 10; x--)
				{
					if((pal % x == 0) && (pal / x < 1000))
					{
						answers[0] = pal * 11; //multiply over the 11
						answers[1] = x * 11;   //multiply over the 11 (again)
						answers[2] = pal / x;
						/* We don't have to do any more checking to see if we 
						 * found the highest palindrome, because it is, due to
						 * the way we set up the for loops.
						 */
						return answers;
					}
				}
			}
		}
	}
	return answers;	
}