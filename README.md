3. Read and Print an Array of Integers
Question: Write a C program that reads an array of integers from the user and prints the array.
#include <stdio.h>

int main() {
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("You entered: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

4. Read a File and Print Its Content
Question: Write a C program that reads a text file and prints its content to the screen.
#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], c;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    return 0;
}

6. Append to a File
Question: Write a C program that appends user input to an existing file.
#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], str[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "a");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    printf("Enter a string to append to the file: ");
    getchar(); // consume newline left by scanf
    fgets(str, 100, stdin);

    fprintf(fptr, "%s", str);
    fclose(fptr);

    printf("Content appended to the file.\n");

    return 0;
}

9. Calculate Average of Numbers
Question: Write a C program that reads a list of numbers from a file and calculates their average.
#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100];
    int num, count = 0;
    double sum = 0.0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    while (fscanf(fptr, "%d", &num) != EOF) {
        sum += num;
        count++;
    }

    fclose(fptr);

    if (count == 0) {
        printf("No numbers found in the file.\n");
    } else {
        printf("Average: %.2f\n", sum / count);
    }

    return 0;
}

Question 15
Write a program to read a line of text from the user and print it.
#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s", str);
    return 0;
}
