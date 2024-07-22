#include <stdio.h>  // Include the standard input/output header file

int main() {  // The main function where program execution begins
    FILE *fptr;  // Declare a file pointer 'fptr' for file operations
    char filename[100], c;  // Declare an array 'filename' to store the filename and a character variable 'c' for reading characters from the file

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    // Read the input filename from the user and store it in the 'filename' array
    scanf("%s", filename);

    // Open the file in read mode ("r")
    fptr = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fptr == NULL) {
        // If the file pointer is NULL, print an error message and exit the program
        printf("Cannot open file %s\n", filename);
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Read characters from the file one by one until the end of the file (EOF) is reached
    c = fgetc(fptr);
    while (c != EOF) {
        // Print the character read from the file
        printf("%c", c);
        // Read the next character from the file
        c = fgetc(fptr);
    }

    // Close the file after reading is complete
    fclose(fptr);
    return 0;  // Return 0 to indicate successful execution
}
