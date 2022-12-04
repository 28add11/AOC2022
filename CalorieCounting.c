
/*
	AOC 2022 Day 1 Part 1 submission, by Nicholas West. Use as you like idc I spent like 5 minutes writing this.
	Some of the code here is used with respect to the terms from ChatGPT by OpenAI.
    This shit doesnt work.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 2048 // Set the maximum size for each chunk, or area seperated by an empty line

int getElves(int elfArray[1000]);
void split_input(int numbers[1000][100], int group_sizes[1000]);
int compare_int(const void *a, const void *b);

int main(void) {
	int ElfTotalCalories[1000] = {0};

	getElves(ElfTotalCalories);

	qsort(ElfTotalCalories, 1000, sizeof(int), compare_int);

    printf("%d \n", ElfTotalCalories[0]);



	return 0;
}

int getElves(int elfArray[1000]) { /*Gets all the elves calories*/
	int elfSnacks[1000][100] = {0};
	int elfSnacksCount[1000] = {0}; //Stores how many snacks each elf has

	split_input(elfSnacks, elfSnacksCount);
	
	for (int i = 0; i < 1000; i++) {
		for (int x = 0; x < elfSnacksCount[i]; x++) {
			elfArray[i] += elfSnacks[i][x];
		}
	}

}

// Function to split the input into groups of numbers and store them in a two-dimensional array
void split_input(int numbers[1000][100], int group_sizes[1000])
{
    char input_string[100000]; // Array to store the input string

      // Open the file for reading
    FILE *fp = fopen("input.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the input from stdin
    fgets(input_string, sizeof(input_string), fp);

    // Split the input_string into a list of strings, one for each group of numbers
    char *groups[1000]; // Array to store the groups
    int num_groups = 0; // Number of groups

    char *group = strtok(input_string, "\n\n");
    while (group != NULL)
    {
        groups[num_groups] = group;
        num_groups++;

        group = strtok(NULL, "\n\n");
    }

    // Create a list of lists of numbers, where each sub-list represents the numbers in a group
    for (int i = 0; i < num_groups; i++)
    {
        // Split the group into a list of numbers
        char *number = strtok(groups[i], "\n");
        int num_numbers = 0; // Number of numbers in the group

        while (number != NULL)
        {
            numbers[i][num_numbers] = atoi(number);
            num_numbers++;

            number = strtok(NULL, "\n");
        }

		group_sizes[i] = num_numbers;
    }
}

int compare_int(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return *ib - *ia;
}