#include <stdio.h>
#include <string.h>

int get_input(int data[1000][2]);

int main(void) {

}

int get_input(int data[1000][2]) // Returns an int of how many rounds there are, but mostly changes data to the actual input
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

    // Split the input_string into one round, then that into each player's moves
    int rounds_num = 0; // Number of rounds

    char *round = strtok(input_string, "\n");
    while (round != NULL)
    {
        data[rounds_num][0] = round[0];
		data[rounds_num][1] = round[3];
        rounds_num++;

        round = strtok(NULL, "\n");
    }
}

void to_number(int data[1000][2], int data_length) {

	int score = 0;

	for (int i = 0; i < data_length; i++)
		for (int x = 0; x < 1; x++)
			switch (data[i][x])
			{
			case 'A': case 'X':
				data[i][x] = 1;
				break;
			case 'B': case 'Y':
				data[i][x] = 2;
				break;
			case 'C': case 'Z':
				data[i][x] = 3;
				break;
	
			default:
				data[i][x] = 0;
				break;
			}
}