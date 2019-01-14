#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int size_of_file = 0;
	int scanned_size = 0;
	int count = 0;
	int i = 0;
	FILE *input_file = NULL;
	FILE *output_file = NULL;
	void *search_string = NULL;
	void *buffer = NULL;
	void *front = NULL;
	void *back = NULL;

	//chekcing number of arguments.
	if (argc > 3 && strlen(argv[2]) > 0) 
	{
		//Opening input_file.
		FILE *input_file = fopen(argv[1],"rb");
		if(input_file == NULL)
		{
			printf("Failed to open the input file.\n");
			return 0;
		}

		//Opening ouput_file.
		FILE *output_file = fopen(argv[3],"wb");

		if(output_file == NULL)
		{
			fclose(input_file);
			printf("Failed to open the ouput file.\n");
			return 0;
		}		

		//allocating a space for search_string
		search_string = malloc(strlen(argv[2]));

		if(search_string == NULL)
		{
			fclose(input_file);
			fclose(output_file);
			printf("Failed to allocate a memory space.\n");
			return 0;
		}
		//setting search_string pointer.
		strcpy(search_string, argv[2]);
		
		//allocating space for a buffer.		
		buffer = malloc (sizeof(char) * strlen(argv[2]) * 2);
		//initially front points to a second half of the buffer.
		front = buffer + strlen(argv[2]);
		back = buffer + strlen(argv[2]);
		
		//a loop that reading an input file to the second half of the buffer.
		while(scanned_size = fread(back, sizeof(char), strlen(argv[2]), input_file))
		{ 
			//updating a file size info.
			size_of_file += scanned_size;
			//a loop to check contents.
			for (i = 0; i < strlen(argv[2]) + 1; i++)
			{
				//copying the second half to the first half of the buffer.
				if (front == back)
				{
					//front points to a first half of the buffer.
					front = buffer;
					memmove(front, back, scanned_size);
					//going back to the while loop.
					break;
				} 
				
				//equivalence check.
				if (memcmp(front, search_string, strlen(argv[2])) == 0)
				{
					count++;
				}
				//updating front pointer to point to next byte.
				front += 1;
			} 
		}
		
		//printing results to the screen.
		printf("Size of the file: %d\n", size_of_file);
		printf("Number of matches found: %d\n", count);

		//printing results to the output file.
		fprintf(output_file, "Size of the file: %d\n", size_of_file);
		fprintf(output_file, "Number of matches found: %d\n", count);
		
		//freeing spaces and closing input_file and output_file.
		free(buffer);
		fclose(input_file);
		fclose(output_file);
		free(search_string);

	} else
	{
		printf("Wrong number of arguments.\n");
	}
	return 0;
}





