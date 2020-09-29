/*
 * Author: Luke Hindman
 * Date: Tue 29 Sep 2020 01:17:59 PM PDT
 * Description: A collection of utility functions from K&R to 
 *    demonstrate how functions behave and how related function
 *    can be organized 
 */
#include <stdio.h>
#include "utilities.h"


/* Global declarations */
const int MAXLINE = 80;

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

