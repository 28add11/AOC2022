#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_input(char data[5000][1000]);
void parse_input(char data[5000][1000], int priorities[5000], int rucksacks);
int get_priority(char c);
int sum_array(int array[5000], int itemcount);

int main(void) {
	char data[5000][1000];
	int priorites[5000] = {0};

	int rucksacks = get_input(data);
	parse_input(data, priorites, rucksacks);
	int result = sum_array(priorites, rucksacks);
	printf("%i\n", result);
	return 0;
}

int get_input(char data[5000][1000]) {
    // Open the file for reading
    FILE *fp = fopen("input.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the input from input.txt
    char c;
    int i = 0;
    int pos = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            data[i][pos] = '\0';
            i++;
            pos = 0;
        } else {
            data[i][pos++] = c;
        }
    }

    // Close the file
    fclose(fp);

    // Return the number of rucksacks
    return i;
}

void parse_input(char data[5000][1000], int priorities[5000], int rucksacks) {
    int i;
    int length;
    int x;
    int y;
    for (i = 0; i <= rucksacks; i++) {

        // Make a copy of the rucksack strings
        char *rucksack = strdup(data[i]);
		char *rucksack1 = strdup(data[++i]);
		char *rucksack2 = strdup(data[++i]);

        // Determine the length of the rucksack string
        length = strlen(rucksack);

		// Initialize c to NULL
		char *c = NULL;
		
		for (x = 0; x < length; x++) {
			// Find the duplicate character in the second half of the string
			c = strchr(rucksack1, rucksack[x]);
			// Check if the character was found
			if (c != NULL) {
				if (strchr(rucksack2, *c) != NULL) {
					priorities[i] = get_priority(*c);
					
					break;
				}
		    	
			}
			
		}
		free(rucksack);
	}
}

int get_priority(char c) {
	//If c is greater than or equal to 'a' (since 'a' is greater than 'A' in ascii) then do the math to generate score
	return (c >= 'a') ? ((c - 'a') + 1) : ((c - 'A') + 27);
}

int sum_array(int array[5000], int itemcount) {
	int i;
	int sum = 0;
	for (i = 0; i <= itemcount; i++) {
		sum += array[i];
	}
	return sum;
}