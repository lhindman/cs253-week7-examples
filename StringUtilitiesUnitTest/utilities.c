/*
 * File: utilities.c
 * Author: Luke Hindman
 * Date: Tue 29 Sep 2020 02:04:01 PM PDT
 * Description: Collection of useful string utility functions
 */
#include <string.h>
#include <ctype.h>
#include "utilities.h"

int myatoi(const char s[]){
	int i,n,sign;

	for (i = 0; isspace(s[i]); i++); /* skip white space */

	sign = (s[i] == '-')? -1 : 1;

	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;

	for (n = 0; isdigit(s[i]); i++) {
		n = 10 * n + (s[i] - '0');
	}

	return sign * n;
}

void myitoa(int n, char s[]) {

	int i, sign;

	if ((sign = n) < 0) {  /* record sign */
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';  /* get next digit */
	} while ((n /= 10) > 0);	/* delete it */

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);



}

void reverse(char s[]) {
   char c;
	size_t i, j;

	for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
      /* Swap characters at positions i,j */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}


}