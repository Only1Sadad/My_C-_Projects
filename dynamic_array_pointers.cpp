#include <iostream>
using namespace std;
// Programmer:Sadad Yusuf
// Create a function that takes an integer (size) as input and returns a
// dynamically allocated array of integers of that size with all values set to
// 0.
int* dynamic_array(int size);
// Create a function that sets the value of an array of integers to its index
// using pointers (not using square brackets)*
void set_array_values(int* arr);
// Create a function that prints an array of integers using pointers (not using
// square brackets)*
void print_array(int* arr, int size);
// Create a function that prints an array of integers in reverse using pointers
// (not using square brackets)*
void reverse_print(int* arr1, int size1);

int main() {
  int size;
  cout << "\nEnter size of array: ";
  cin >> size;

  // Call the function to create the array
  int* test = dynamic_array(size);

  // Print the values of the array
  for (int i = 0; i < size; i++) {
                     // Access the value
    cout << test[i] << " ";  // Print each value
  }
  cout << " " << endl;
  delete[] test;  // Deallocate memory to prevent memory leak.

  set_array_values(
      &size);  // Call the function to set the values of the array using Ptr's

  // testing the print array function to print values in an array using *ptr
  int scores[] = {10, 20, 30, 40, 50};
  int size2 = sizeof(scores) / sizeof(scores[0]);
  print_array(
      scores,
      size2);  // Call the function to print the values of the array using *ptr

  // testing using ptr to reverse values in the array
  int test_case[] = {1,2,3,4,5,6,7,8,9,10};
  int size3= sizeof(test_case)/sizeof(test_case[0]);
  reverse_print(test_case,size3);  // Call the function to print the values of the
                                 // array in reverse using *ptr
  return 0;
}
int* dynamic_array(int size) {
  int* ptr = new int[size];  // Allocate memory for the array
  for (int i = 0; i < size; i++) {
    ptr[i] = 0;  // Initialize each element to 0
  }
  return ptr;  // Return the pointer to the array
}
void set_array_values(int* arr) {
  int size = 5;  // Set the pointer to the beginning of the array
  for (int i = 0; i < size; i++) {
    arr[i] = *arr;  // Set the value of each element to its index the array at
                    // the current index to the index value
  }
  cout << "\nafter setting Array values using *ptr's: ";  // Print the values
                                                          // after setting
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";  // Print each value>>
  }
  cout << endl;
}
void print_array(int* arr, int size) {
  // Set the pointer to the beginning of the array
  cout << "\n printing Array values using *ptr: ";  // Print the array values
                                                    // using *ptr
  for (int i = 0; i < size; i++) {
    cout << *(arr + i) << " ";
  }
  cout << endl;
}
void reverse_print(int* arr1, int size1) {
  for (int i = size1 - 1; i >= 0; i--) {
    cout << *(arr1+i) << " ";  // Print each value in reverse order>>>>
  }
  cout << endl;
}
