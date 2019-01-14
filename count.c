#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{

	FILE *input_file = NULL;
	FILE *output_file = NULL;
	void *search_string = NULL;
	void *buffer = NULL;
	void *front = NULL;
	void *back = NULL;
	int size_of_file = 0;
	int scanned_size = 0;
	int count = 0;
	int i = 0;

	if (argc > 3 && strlen(argv[2]) > 0) 
	{
		FILE *input_file = fopen(argv[1],"rb");

		if(input_file == NULL)
		{
			printf("Failed to open the input file.\n");
			return 0;
		}

		FILE *output_file = fopen(argv[3],"wb");

		if(output_file == NULL)
		{
			fclose(input_file);
			printf("Failed to open the ouput file.\n");
			return 0;
		}		

		search_string = malloc(strlen(argv[2]));

		if(search_string == NULL)
		{
			fclose(input_file);
			fclose(output_file);
			printf("Failed to allocate a memory space.\n");
			return 0;
		}

		strcpy(search_string, argv[2]);
		
		buffer = malloc (sizeof(char) * strlen(argv[2]) * 2);
		front = buffer + strlen(argv[2]);
		back = buffer + strlen(argv[2]);

		while(scanned_size = fread(back, sizeof(char), strlen(argv[2]), input_file))
		{ 
			size_of_file += scanned_size;
			for (i = 0; i < strlen(argv[2]) + 1; i++)
			{
				if (front == back)
				{
					front = buffer;
					memmove(front, back, scanned_size);
					break;
				} 
				
				if (memcmp(front, search_string, strlen(argv[2])) == 0)
				{
					count++;
				}
				front += 1;
			} 
		}
		
		printf("Size of the file: %d\n", size_of_file);
		printf("Number of matches found: %d\n", count);

		fprintf(output_file, "Size of the file: %d\n", size_of_file);
		fprintf(output_file, "Number of matches found: %d\n", count);
		
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





