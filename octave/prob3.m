#!/usr/bin/octave

%{
Project Euler Problem 3: Prime Factorization

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 

After a little bit of research, it looks like there isn't any "good" 
algorithm for this. The best I could really do would be to do a trial 
division, where you just divide a number n by each integer up to sqrt(n).
This one is a little different though, because as soon as I find a factor, I
divide the number I'm testing by that factor so that I don't accidently find
that factor again.
%}

% Start with non-function declaration so that this is run as a script
printf('Greatest prime factor: ');

function[retval] = factors(number)
	number = abs(number);
	greatestfactor = 1;
	x = 0;
	STOP = floor(sqrt(number));
	for x = 2:STOP
		while(mod(number, x) == 0) 	%this x is a factor
 			greatestfactor = x;
 			number = number / x; 	%to find duplicates of this factor
 		endwhile
	endfor
	if (greatestfactor == 1)		%if a prime number
		greatestfactor = number;
	endif
	retval = greatestfactor
endfunction

%finish the script
t1 = cputime();
printf('%d\n', factors(600851475143));
t2 = cputime();
printf('Time: %f\n', t2-t1);