#include <stdio.h>  // Include the standard input/output header file
#include <stdlib.h> // Include the standard library header for exit function

int main() {
    FILE *fptr;  // Declare a file pointer 'fptr' for file operations
    char filename[100];  // Declare an array 'filename' to store the filename
    int num, count = 0;  // Declare an integer 'num' to store each number read from the file, and 'count' to count the number of numbers
    double sum = 0.0;  // Declare a double 'sum' to store the sum of the numbers

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
    if (scanf("%99s", filename) != 1) {
        // If the user input fails, print an error message and exit
        printf("Error reading filename.\n");
        return 1;
    }

    // Open the file in read mode ("r")
    fptr = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fptr == NULL) {
        // If the file pointer is NULL, print an error message and exit the program
        printf("Error: Cannot open file %s\n", filename);
        perror("Reason");  // Print the system-generated error message
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Inform the user that the file is being processed
    printf("Reading numbers from file: %s\n", filename);

    // Read numbers from the file until the end of the file (EOF) is reached
    while (fscanf(fptr, "%d", &num) != EOF) {
        // Print each number read from the file for user confirmation
        printf("Read number: %d\n", num);
        // Add the number to the sum
        sum += num;
        // Increment the count of numbers
        count++;
    }

    // Close the file after reading all numbers
    if (fclose(fptr) != 0) {
        // If fclose fails, print an error message
        printf("Error: Failed to close file %s\n", filename);
        return 1;  // Return a non-zero value to indicate abnormal termination
    }

    // Calculate the average and handle the case where no numbers are found
    if (count == 0) {
        // If no numbers were found, print a message
        printf("No numbers found in the file.\n");
    } else {
        // Calculate and print the average of the numbers
        double average = sum / count;
        printf("Total numbers read: %d\n", count);
        printf("Sum of the numbers: %.2f\n", sum);
        printf("Average of the numbers: %.2f\n", average);
    }

    // Thank the user for using the program
    printf("Thank you for using the Average Calculator.\n");

    return 0;  // Return 0 to indicate successful execution
}
