#include <stdio.h>  // Include the standard input/output header file

int main() {        // The main function where program execution begins
    int n, i;       // Declare two integer variables 'n' for the number of elements and 'i' for the loop counter
    int arr[100];   // Declare an array 'arr' of size 100 to store the integers

    // Prompt the user to enter the number of elements
    printf("Enter number of elements: ");
    // Read the input from the user and store it in variable 'n'
    scanf("%d", &n);

    // Check if the number of elements is within the valid range
    if (n < 1 || n > 100) {
        // If the number of elements is invalid, print an error message and exit the program
        printf("Error: Number of elements should be between 1 and 100.\n");
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Prompt the user to enter the integers
    printf("Enter %d integers: ", n);
    // Loop to read 'n' integers from the user
    for(i = 0; i < n; i++) {
        // Read each integer and store it in the 'arr' array
        scanf("%d", &arr[i]);
    }

    // Print the entered integers
    printf("You entered: ");
    // Loop to print each integer stored in the 'arr' array
    for(i = 0; i < n; i++) {
        // Print each integer followed by a space
        printf("%d ", arr[i]);
    }
    // Print a newline character at the end for better formatting
    printf("\n");

    return 0;  // Return 0 to indicate successful execution
}
