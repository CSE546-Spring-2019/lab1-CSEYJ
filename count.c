#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(void *front, void *search_string, int length);
void shift(void *front, void *back, int length);

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
		FILE *output_file = fopen(argv[3],"wb");
		search_string = malloc(strlen(argv[2]));
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
					shift(front, back, strlen(argv[2]));
					break;
				} 
				count += compare(front, search_string, strlen(argv[2]));
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


int compare(void *front, void *search_string, int length) 
{
	void *current = front;
	void *s_string = search_string;
	if(length > 0)
	{
		while (length > 0)
		{
			if (*(char *) current != *(char *) s_string) 
			{
				return 0;
			}
			current += 1;
			s_string += 1;
			length--;
		}
		return 1;
	} else 
	{
		return 0;
	}
}

void shift(void *front, void *back, int length)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		if(back != NULL)
		{
			*((char *) front + i) = *((char *) back + i);
		} else 
		{
			break;
		}
	}
}

