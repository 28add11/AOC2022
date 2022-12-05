#include <stdio.h>
#include <string.h>

int get_input(char data[5000][1000]);
void parse_input(char data[5000][1000], int priorities[5000], int rucksacks);
int get_priority(char c);
int sum_array(int array[5000], int itemcount);

int main(void) {
	char data[5000][1000];
	int priorites[5000];

	int rucksacks = get_input(data);
	parse_input(data, priorites, rucksacks);
	printf("%i\n", sum_array(priorites, rucksacks));
}

int get_input(char data[5000][1000]) {
	
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

	int rucksack_count = 0; // how many rucksacks there are
	int item_index; //The item's index in rucksack

	char *rucksack = strtok(input_string, "\n");
    while (rucksack != NULL)
    {
		
		for (item_index = 0; item_index < sizeof(rucksack); item_index++) { //since rucksack is a char pointer, 
			data[rucksack_count][item_index] = rucksack[item_index];
		}
		data[rucksack_count][item_index] = '\0'; //Set the n+1 item in the rucksack to a null
        rucksack_count++;

        rucksack = strtok(NULL, "\n");
    }
	fclose(fp);
	return rucksack_count;
}

void parse_input(char data[5000][1000], int priorities[5000], int rucksacks) {
	int i;
	int charindex;
	int x;
	int y;
	for (i = 0; i < rucksacks; i++) {
		charindex = 0;
		while (data[i][charindex] != '\0') { //find the size of that data element
			charindex++;
		}
		int middle = (--charindex/2); //Split the data element in two (not literally, just finding the middle)

		//Find the duplicate letter
		for (x = 0; x < middle; x++) {
			for (y = 0; (y + middle) < charindex; y++){
				if (data[i][x] == data[i][y])
				{
					priorities[i] = get_priority(data[i][x]);
				}		
			}
		}
	}
}

int get_priority(char c) {
	//If c is greater than or equal to 'a' (since 'a' is greater than 'A' in ascii) then do the math to generate score
	return (c >= 'a') ? ((c - 'a') + 1) : ((c - 'A') + 27);
}

int sum_array(int array[5000], int itemcount) {
	int i;
	int sum;
	for (i = 0; i < itemcount; i++) {
		sum += array[i];
	}
	return sum;
}