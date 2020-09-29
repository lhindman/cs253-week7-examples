/*
 * File: utilities.h
 * Author: Luke Hindman
 * Date: Tue 29 Sep 2020 02:04:01 PM PDT
 * Description: Collection of useful string utility functions
 */


/* 
 * Implementation of atoi() from K&R 3.5
 * 
 *   s - a null terminated string containing characters to be converted
 *   return - equivilant int value of number in string
 */
int myatoi(const char s[]);


/*
 * Implementation of itoa() from K&R 3.6
 *   n - int value to convert to string
 *   s - character array of sufficient size to hold MAX_INT + '\0' (ie >11 chars)
 */ 
void myitoa(int n, char s[]);

/*
 * Implementation of reverse() example from K&R 3.5
 *    s - null terminated string to be reversed
 */
void reverse(char s[]);