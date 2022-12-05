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
		data[rounds_num][1] = round[2]; //index of the 2nd collum
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
		case 'X': //since X means we need to lose, if they play rock you play scissors, etc etc

			score += 0;

			if (data[i][0] == 'A') { 
				score += 3;
			} 
			else if (data[i][0] == 'B') {
				score += 1;
			}
			else if (data[i][0] == 'C') {
				score += 2;
			}
			break;

		case 'Y': //Since Y means we need to tie, if rock is played we need to play rock, etc etc

			score += 3;

			if (data[i][0] == 'A') {
				score += 1;
			} 
			else if (data[i][0] == 'B') {
				score += 2;
			}
			else if (data[i][0] == 'C') {
				score += 3;
			}
			
			break;

		case 'Z': //Since Z means we need to win, if rock is played, we play paper

			score += 6;
				
			if (data[i][0] == 'A') {
				score += 2;
			} 
			else if (data[i][0] == 'B') {
				score += 3;
			}
			else if (data[i][0] == 'C') {
				score += 1;
			}

			break;
	
		default:
			break;
		}
	}
	return score;
}