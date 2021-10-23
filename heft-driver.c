/*
	Driver code to get HEFT started.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char **argv)
{
	// Command line args

	int input_arr[argc - 1];

	for(int i = 1; i < argc; i++)
	{
		for(int j = 0; j < strlen(argv[i]); j++)
			if(!isdigit(argv[i][j]))
			{
				printf("Please enter only numbers!\n");
				return -1;
			}

		input_arr[i - 1] = atoi(argv[i]);
	}

	// First get number of tasks and processors to check if the number of args is right

	int num_tasks = input_arr[0];
	int num_procs = input_arr[1];

	if(((num_tasks * num_procs) + (num_tasks * num_tasks) + 3) != argc)
	{
		printf("Incorrect number of arguments entered. Check and try again!\n");
		return -1;
	}

	int exec_times[num_procs][num_tasks];

	int a_DAG[num_tasks][num_tasks];

	// Setting up exec_times
	for(int i = 0; i < num_procs; i++)
		for(int j = 0; j < num_tasks; j++)
			exec_times[i][j] = input_arr[2 + (i * num_tasks) + j];

	// Setting up a_DAG
	for(int i = 0; i < num_tasks; i++)
		for(int j = 0; j < num_tasks; j++)
			a_DAG[i][j] = input_arr[2 + (num_procs * num_tasks) + (i * num_tasks) + j];

	// End of command line args setup

	// Printing to test assignment
	
	for(int i = 0; i < num_procs; i++)
	{
		for(int j = 0; j < num_tasks; j++)
			printf("%d ", exec_times[i][j]);

		printf("\n");
	}

	printf("\n\n");

	for(int i = 0; i < num_tasks; i++)
	{
		for(int j = 0; j < num_tasks; j++)
			printf("%d ", a_DAG[i][j]);

		printf("\n");
	}

	return 0;
}