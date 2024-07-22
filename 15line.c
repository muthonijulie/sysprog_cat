#include <stdio.h>  // Include the standard input/output header file
#include <stdlib.h> // Include the standard library header file for exit function

int main() {
    char str[100];  // Declare a character array 'str' to store the input line of text

    // Prompt the user to enter a line of text
    printf("Enter a line of text: ");

    // Use fgets to read a line of text from the standard input (stdin)
    if (fgets(str, sizeof(str), stdin) == NULL) {
        // If fgets fails, print an error message and exit the program
        printf("Error: Failed to read input.\n");
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Print the line of text entered by the user
    printf("You entered: %s", str);

    return 0;  // Return 0 to indicate successful execution
}
