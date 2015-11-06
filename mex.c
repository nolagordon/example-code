// Returns the minimum excluded integer in a list
// (c) Nola J. Gordon

#include <stdio.h>
#include <stdlib.h>

int mex (int*, int);
int main (int argc, char **argv) {
  // Initialize array
  int length = 10;
  int *values = (int *)malloc(length * sizeof(int));
  int counter, i;

  // Read in each integer and add it to an array
  for (counter = 0; EOF != (fscanf(stdin, "%d", &i)); counter++) {
   
    // If the number of integers is higher than the length of the array,
    // increase array size
    if (counter+1 > length) {
      length *= 2;
      values = realloc(values, length * sizeof(int));
    }

    // Add integer to the array
    values[counter] = i;
  }

  // Call mex to find smallest missing integer and print it out
  fprintf ( stdout, "%d",  mex(values, counter) );
  free(values);
  return 0;
}

// Given an integer array, returns the minimum exlcuded integer in the set of values
int mex (int *vptr, int size) {
  int i;
  char *data = (char *)malloc(size * sizeof(char));

  // Initialize each value in data to 0
  for (i = 0; i < size; i++) {
    data[i] = 0;
  }

  // Sort array of integers into a boolean array
  // If the index stores a 1, that index number appears in the int array
  for (i = 0; i < size; i++) {
    int current = vptr[i];
    if (current >= 0 && current < size) {
      data[current] = 1;
    }
  }

  // Index of the first 0 is the smallest missing int
  for (i = 0; i < size; i++) {
    if (data[i] == 0) {
      free(data);
      return i;
    }   
  }

  // If there are no false values in the boolean array, return the number
  // after the highest number in the integer array
  free(data);
  return i;
}
