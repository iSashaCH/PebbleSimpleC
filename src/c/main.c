#include <pebble.h>

// Define the number of values as 10
#define NUM_VALUES 10

// Array of values to be sorted
int input_array[] = { 5, 7, 2, 6, 4, 1, 9, 0, 3, 8 };

void print_array(void);
void selection_sort(void);
void swap(int index, int new_index);

int main(void) {
   // Print the input array
  print_array();

  // Run the algorithm
  selection_sort();

  // Print the new state of the sorted array
  print_array();

  // Wait for the user to press Back
  app_event_loop();

  // Program ran without error
  return 0;
  
}

void print_array(void) {
  // Print all the array values
  for(int i = 0; i < NUM_VALUES; i++) {
    printf("Element %d = %d", i, input_array[i]);
  }

  // Print a blank line for readability
  printf(" ");
}


void selection_sort(void) {
  // Check each value in the array
  for(int i = 0; i < NUM_VALUES; i++) {
    // Find the smallest value's index in the input array
    int min_index = i;

    // Check all values after the current one
    for(int j = i + 1; j < NUM_VALUES; j++) {
      // If the value in this location is less than the location being tested
      if(input_array[j] < input_array[min_index]) {
        // Save the index where the next smallest value can be found
        min_index = j;
      }
    }

    // Swap the current value with the smallest value, if it is not itself
    if(min_index != i) {
      swap(i, min_index);
    }
  }
}

void swap(int index, int new_index) {
  // Make a temportary copy
  int temp = input_array[index];

  // Place the new value in place of the old value
  input_array[index] = input_array[new_index];

  // Place the old value where the new value came from
  input_array[new_index] = temp;
}