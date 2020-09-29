/*
 * File: mytests.c
 * Author: Luke Hindman
 * Date: Tue 29 Sep 2020 02:09:47 PM PDT
 * Description: Unit tests for the various string utilities
 */
#define _GNU_SOURCE 

#include "utilities.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024


/* MACRO: Write to stderr without using malloc */
#define DISP_MSG(MSG) if(write(STDOUT_FILENO,MSG,strlen(MSG)) == -1) perror("write");

/* Global variable declaration */
void printresults(int r);

/* Define error handler */
static void handler(int sig, siginfo_t *si, void *unused)
{
	UNUSED(sig);
	UNUSED(unused);
    if (si->si_signo == SIGSEGV) {
		DISP_MSG("failed (segfault)\n")
        exit(1);
    } 
}

/* 
 * Test myatoi() using a variety of cases that fall
 *    within the range of expected values.
 */
int test_myatoi_safepath(void) 
{
   /* Setup test data */
   const int NUM_TESTS = 7;
	char *data[] = {"5192","-5192","0","1","-1", "+165495416", "-165495416" };
   int expected[] = {5192, -5192, 0, 1, -1, 165495416,-165495416};

   /* Run the test */
	DISP_MSG("Test myatoi() safepath: ");
	for (int i = 0; i < NUM_TESTS; i++) {
      int result = myatoi(data[i]);
		if (result != expected[i]) {
			DISP_MSG("failed\n");
			return 1;
		}
	}
	DISP_MSG("passed\n");
	return 0;
}

/*
 * Test myatoi() with INT_MAX
 */
int test_myatoi_upper_boundary(void) 
{
   /* Setup test data */
	char data[] = "+2147483647";
   int expected = 2147483647;
   
   /* Run the test */
	DISP_MSG("Test myatoi() upper boundary: ");
   int result = myatoi(data);
   if (result != expected) {
      DISP_MSG("failed\n");
      return 1;
   }

	DISP_MSG("passed\n");
	return 0;
}

/*
 * Test myatoi() with INT_MIN
 */
int test_myatoi_lower_boundary(void) 
{
   /* Setup test data */
	char data[] = "-2147483648";
   int expected = -2147483648;

   /* Run the test */
	DISP_MSG("Test myatoi() lower boundary: ");
   int result = myatoi(data);
   if (result != expected) {
      DISP_MSG("failed\n");
      return 1;
   }

	DISP_MSG("passed\n");
	return 0;
}



/* 
 * Test myitoa() using a variety of cases that fall
 *    within the range of expected values.
 */
int test_myitoa_safepath(void) 
{
   /* Setup test data */
   const int NUM_TESTS = 7;
   char resultBuffer[20];
   int data[] = {5192, -5192, 0, 1, -1, 165495416,-165495416};
   char *expected[] = {"5192","-5192","0","1","-1", "165495416", "-165495416" };

   /* Run the test */
	DISP_MSG("Test myitoa() safepath: ");
	for (int i = 0; i < NUM_TESTS; i++) {
      myitoa(data[i], resultBuffer);
		if (strcmp(resultBuffer,expected[i]) == 0) {
			DISP_MSG("failed\n");
			return 1;
		}
	}
	DISP_MSG("passed\n");
	return 0;
}

/*
 * Test myitoa() with INT_MAX
 */
int test_myitoa_upper_boundary(void) 
{
   /* Setup test data */
   char resultBuffer[20];
   int data = 2147483647;
	char expected[] = "2147483647";
   
   /* Run the test */
	DISP_MSG("Test myitoa() upper boundary: ");
   myitoa(data, resultBuffer);
   if (strcmp(resultBuffer,expected) == 0) {
      DISP_MSG("failed\n");
      return 1;
   }

	DISP_MSG("passed\n");
	return 0;
}

/*
 * Test myatoi() with INT_MIN
 */
int test_myitoa_lower_boundary(void) 
{
   /* Setup test data */
   char resultBuffer[20];
   int data = -2147483648;
   char expected[] = "-2147483648";

	DISP_MSG("Test myitoa() lower boundary: ");
   myitoa(data, resultBuffer);
   if (strcmp(resultBuffer,expected) == 0) {
      DISP_MSG("failed\n");
      return 1;
   }

	DISP_MSG("passed\n");
	return 0;
}


int run_all(void) {

	int status = 0;
	status += test_myatoi_safepath();
   status += test_myatoi_upper_boundary();
   status += test_myatoi_lower_boundary();

	status += test_myitoa_safepath();
   status += test_myitoa_upper_boundary();
   status += test_myitoa_lower_boundary();

	return status;
}

int main(void)
{

	int numFailedTests = 0;

	/* Setup signal handling to catch segfault */
	struct sigaction sa;
   sa.sa_flags = SA_SIGINFO;
   sigemptyset(&sa.sa_mask);
   sa.sa_sigaction = handler;
   if (sigaction(SIGSEGV, &sa, NULL) == -1)
      perror("sigaction");


   /* Run the tests */
	numFailedTests = run_all();

   /* Return the number of failed
    *  tests as the exit status */
	return numFailedTests;
}

