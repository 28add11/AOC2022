#include <stdio.h>
#include <string.h>

int get_input(int data[3000][3]);
int to_number(int data[3000][3], int data_length);

int main(void) {

	int data[3000][3];

	int data_len = get_input(data);

	int score = to_number(data, data_len);

	printf("%i\n", score);

	return 0;

}

int get_input(int data[3000][3]) // Returns an int of how many rounds there are, but mostly changes data to the actual input
{
    char input_string[100000]; // Array to store the input string

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
  	while ((c = fgetc(fp)) != EOF) {
    	input_string[i++] = c;
  	}

    // Split the input_string into one round, then that into each player's moves
    int rounds_num = 0; // Number of rounds

    char *round = strtok(input_string, "\n");
    while (round != NULL)
    {
        data[rounds_num][0] = round[0];
		data[rounds_num][1] = round[2];
        rounds_num++;

        round = strtok(NULL, "\n");
    }
	fclose(fp);
	return rounds_num;
}

int to_number(int data[3000][3], int data_length) {

	int score = 0;

	for (int i = 0; i < data_length; i++){
		switch (data[i][1])
		{
		case 'X':

			score += 1;

			if (data[i][0] == 'A') {
				score += 3;
			} 
			else if (data[i][0] == 'C') {
				score += 6;
			}
			break;
		case 'Y':

			score += 2;

			if (data[i][0] == 'B') {
				score += 3;
			} 
			else if (data[i][0] == 'A') {
				score += 6;
			}
			
			break;
		case 'Z':

			score += 3;
				
			if (data[i][0] == 'C') {
				score += 3;
			} 
			else if (data[i][0] == 'B') {
				score += 6;
			}

			break;
	
		default:
			break;
		}
	}
	return score;
}