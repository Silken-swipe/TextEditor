#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLEN 50

void WorkWithFile(char file_name[]) {
    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int c = 0;
    while ((c = getchar()) != '\n') {
        fputc(c, file);
    }
    fclose(file);
}

int main(int argc, char **argv) {
    char file_name[MAXLEN];

    printf("Enter the file name: ");
    scanf("%49s", file_name);

    if (access(file_name, F_OK) == 0) {
        printf("File already exists!\n");
        return 0;
    } else {
        printf("New file was created!\n");
    }

    WorkWithFile(file_name);

    return 0;
}