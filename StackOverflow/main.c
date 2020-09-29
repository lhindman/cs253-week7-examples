/*
 * Author:  Luke Hindman
 * Date: Tue 29 Sep 2020 12:06:49 PM PDT
 * Description:  Explore the limitations of allocating
 *    memory within the stack. */
#include <stdio.h>

/* Function definitions */
int recursiveDepthFinder(int level);

int main(void) {

   /* On Linux systems, the size of the stack segment is limited to 8MB
    *    for a single-threaded process.  For a multi-threaded prcocess,
    *    all threads exist within the same virtual address space and share
    *    the code, data and head segments, but each execution thread is 
    *    allocated its own unique 8MB stack segment.
    * 
    * The default stack size on Linux is 8MB and you can view the current
    *    stack size using the following command:
    * 
    *    ulimit -a
    * 
    * On Windows based systems, the default stack size is 1MB
    */

   /* Allocate 7MB array of chars */
   char bigArray[7 * 1024 * 1024];
   printf("The size of bigArray: %ld\n", sizeof(bigArray));

   /* Fill the array with 7MB of zeros, just for grins */
   // for (int i = 0; i < 1024 * 1024; i++) {
   //    bigArray[i] = 0;
   // }

   /* Allocate 1MB array of chars */
   // char smallerArray[ 1024 * 1024];
   // printf("The size of smallerArray: %ld\n", sizeof(smallerArray));

   /* Let's try writing a single byte into the second array */
   // smallerArray[0] = 0;


   /* Every function that is called allocates a stack frame which consumes
    *    space within the stack.  The stack frame is destropyed when the
    *    function returns and the stack space is reclaimed.
    * This can be problematic when we have functions that operate using 
    *    recursion or when functions have a deep, nested call tree.
    */
   // recursiveDepthFinder(1);


   return 0;
}

int recursiveDepthFinder(int level) {
   /* Allocate 10KB of space to make this example more interesting */
   char data[10 * 1024];

   /* Initialize the data, just to have something in memory */
   for (int i = 0; i < 10 * 1024; i++) {
      data[i] = i % level;
   }

   /* Display the current level */
   printf("Finished processing level %d: %ldKB\n", level, (sizeof(data) * level )/1024);

   /* Make the recursive call */
   return recursiveDepthFinder(level + 1);
}
