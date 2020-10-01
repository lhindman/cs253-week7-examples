/*
 * Author: Luke Hindman
 * Date: Tue 29 Sep 2020 01:17:59 PM PDT
 * Description: A collection of utility functions from K&R to 
 *    demonstrate how functions behave and how related function
 *    can be organized 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Global declarations */
const int MAXLINE = 80;

/* Function declarations */
int myatoi(const char s[]);
void myitoa(int n, char s[]);
void reverse(char s[]);

int main(void) {

	/* Smoke test of myatoi() */
	printf("Testing myatoi()\n");
	char number[] = "4192";
	printf("\t\"%s\" -> %d\n",number,myatoi(number));
	
	/* Smoke test of reverse() */
	printf("Testing reverse()\n");
	char word[] = "spoons";
	reverse(word);
	printf("\t\"spoons\" -> %s\n", word);

	/* Smoke test of myitoa() */
	printf("Testing myitoa()\n");
	char buffer[MAXLINE];
	int value = 172931;
	myitoa(value,buffer);
	printf("\t%d -> \"%s\"\n",value, buffer);

	return 0;
}


/* 
 * Implementation of atoi() from K&R 3.5
 * 
 *   s - a null terminated string containing characters to be converted
 *   return - equivilant int value of number in string
 */
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

/*
 * Implementation of itoa() from K&R 3.6
 *   n - int value to convert to string
 *   s - character array of sufficient size to hold MAX_INT + '\0' (ie >11 chars)
 */ 
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
/*
 * Implementation of reverse() example from K&R 3.5
 *    s - null terminated string to be reversed
 */
void reverse(char s[]) {
    char c;
	int i, j;

	for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
      /* Swap characters at positions i,j */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}


}
