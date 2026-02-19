#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 256

void createFile();
void readFile();
void appendToFile();
void deleteFile();
void searchWord();

int main() {
    int choice;
    while (1) {
        printf("\n--- File Operations Menu ---\n");
        printf("1. Create and Write to File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Search for a word\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: appendToFile(); break;
            case 4: searchWord(); break;
            case 5: deleteFile(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// 1.1 Create and Write
void createFile() {
    FILE *fptr;
    char content[MAX_LIMIT];
    fptr = fopen("data.txt", "w");
    if (fptr == NULL) { printf("Error opening file!\n"); return; }

    printf("Enter text to write to file: ");
    fgets(content, MAX_LIMIT, stdin);
    fprintf(fptr, "%s", content);
    fclose(fptr);
    printf("File created successfully.\n");
}

// 1.2 Read and Display
void readFile() {
    FILE *fptr;
    char ch;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL) { printf("File not found!\n"); return; }

    printf("\n--- File Content ---\n");
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }
    fclose(fptr);
}

// 1.3 Append Data
void appendToFile() {
    FILE *fptr;
    char content[MAX_LIMIT];
    fptr = fopen("data.txt", "a");
    if (fptr == NULL) { printf("Error!\n"); return; }

    printf("Enter text to append: ");
    fgets(content, MAX_LIMIT, stdin);
    fprintf(fptr, "%s", content);
    fclose(fptr);
    printf("Content appended.\n");
}

// 2.1 Search for a word/phrase
void searchWord() {
    FILE *fptr;
    char word[50], temp[50];
    int count = 0;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL) { printf("File not found!\n"); return; }

    printf("Enter word to search: ");
    scanf("%s", word);

    while (fscanf(fptr, "%s", temp) != EOF) {
        if (strcmp(temp, word) == 0) {
            count++;
        }
    }
    fclose(fptr);
    printf("The word '%s' appeared %d times.\n", word, count);
}

// 2.2 Delete File
void deleteFile() {
    if (remove("data.txt") == 0) {
        printf("File 'data.txt' deleted successfully.\n");
    } else {
        printf("Unable to delete the file or file does not exist.\n");
    }
}