#!/usr/bin/octave

%{
Project Euler Problem 4: Largest Palindrome Product

A palindromic number reads the same both ways. The largest palindrome made from 
the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.

The naive solution is simple: count down from 999 to find the largest palindrome
as a brute-force technique.

The faster solution is to first compute highest palindromes and them work down 
from there, as there are fewer palindromes than there are factors.  Once the 
palindrome is found, possible factors are explored.
%}

% Setup info so we run as a script and not a function definiution
printf('Largest Palindrome Product\n')
printf('==========================\n')


%{
Checks whether the given number is a palindrome.
I did the work-towards-the-middle method instead of making a copy, reversing it, 
and then doing the checking.  This way is more complicated but a little faster,
I think.
%}
function pal = ispal(number)
	number = abs(number);  	% no negatives
	if(number < 10)			% if 0 or 1 digits 
		pal = true;
		return;
	endif
	str = num2str(number);
	len = size(str, 2);		% 2 is the second dimension, length of the string
	l = 1;
	k = len;
	while ((str(l) == str(k)) && (l < k))
		l++;
		k--;
	endwhile
	if (l >= k) 			% have checked all possible letters and they passed
		pal = true;
		return;
	else 					% it failed somewhere
		pal = false;
		return;
	endif
endfunction




%{
Computes palindromic numbers using a brute-force technique.
%}
function[drome, f1, f2] = naive_palindrome()
	drome = 0;
	f1 = 0;
	f2 = 0;
	for x = 500:999
		for y = 500:999
			val = x*y;
			if (ispal(val) && val > drome)	%if new highest palindrome found 
				drome = val;
				f1 = x;
				f2 = y;
			endif
		endfor
	endfor
endfunction

%{
Uses mathematical properties to calculate the palindromes first, and then find
three digit factors that are acceptabe.
%}
function[drome, f1, f2] = math_palindrome()
	drome = 0;
	f1 = 0;
	f2 = 0;
	% The digits a, b, and c discussed in the paper
	for a = 9:-1:0
		for b = 9:-1:0
			for c = 9:-1:0
				pal = 9091*a + 910*b + 100*c;
				for x = 90:-1:10 	%stop at ten or we'll find wrong answers
					if ((mod(pal, x) == 0) && (pal/x < 999))
						drome = pal * 11; 	% restore the factored out 11
						f1 = x * 11;		% multiply over the 11
						f2 = pal/x;
						return;
					endif
				endfor
			endfor
		endfor
	endfor
endfunction

% Now on to the fun part of the script
t1 = cputime();
[d, n1, n2] = palindrome();
t2 = cputime();
[r, m1, m2] = math_palindrome();
t3 = cputime();
if((d == r) && (n1 == m1) && (n2 == m2))
	printf('Largest palindrome from 3-digit factors: %d.\n', d);
	printf('Factors were %d and %d.\n', n1, n2);
	printf('"naive_palindrome()" took %f seconds.\n', t2 - t1);
	printf('"math_palindrome()"" took %f seconds.\n', t3 - t2);
else
	printf('The two methods did not agree on a result.\n');
endif