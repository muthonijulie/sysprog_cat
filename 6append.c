#include <stdio.h>  // Include the standard input/output header file
#include <stdlib.h> // Include the standard library header file for exit function

int main() {  // The main function where program execution begins
    FILE *fptr;  // Declare a file pointer for file operations
    char filename[100], str[100];  // Declare an array filename to store the filename and another array str to store the input string

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    // Read the input filename from the user and store it in the filename array
    scanf("%s", filename);

    // Open the file in append mode ,a
    fptr = fopen(filename, "a");

    // Check if the file was opened successfully
    if (fptr == NULL) {
        // If the file pointer is NULL, print an error message and exit the program
        printf("Error: Cannot open file %s\n", filename);
        perror("Reason");  // Print the system-generated error message
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Prompt the user to enter a string to append to the file
    printf("Enter a string to append to the file: ");
    // Consume the newline character left in the input buffer by the previous 'scanf'
    //used to read one character at a time from the key board
    getchar();// consume newline left by scanf

    // Read a line of input from the user and store it in the str array
    if (fgets(str, sizeof(str), stdin) == NULL) {
        // If fgets fails, print an error message and close the file
        printf("Error: Failed to read input.\n");
        fclose(fptr);
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Append the string to the file
    if (fprintf(fptr, "%s", str) < 0) {
        // If fprintf fails, print an error message and close the file
        printf("Error: Failed to write to file %s\n", filename);
        fclose(fptr);
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Close the file after appending the content
    if (fclose(fptr) != 0) {
        // If fclose fails, print an error message
        printf("Error: Failed to close file %s\n", filename);
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Inform the user that the content has been appended to the file
    printf("Content appended to the file.\n");

    return 0;  // Return 0 to indicate successful execution
}
