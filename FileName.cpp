#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <cstring> // библиотека из с++

void bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		bool if_replaced = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = tmp; 
				if_replaced = true;
			}
		}
		if (!if_replaced) 
			break;
	}
}

void search_sort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minindex = i; // если бы работали с max, то начинали с size - i
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minindex])
			{
				minindex = j;
			}
		}

		if (minindex != i)
		{
			int tmp = arr[i];
			arr[i] = arr[minindex];
			arr[minindex] = tmp;
		}
	}
}

void insertion_sort(int arr[], int size) 
{
	for (int i = 1; i < size; ++i)
	{
		int current_i = arr[i]; 
		int j;
		for (j = i - 1; j >= 0 && arr[j] > current_i; --j)
		{
			arr[j + 1] = arr[j]; 
		}		
		arr[j + 1] = current_i;
	}
}

void array_generating(int arr[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 1000;
	}
}

int main()
{
	int size;
	int* mas;
	int choose_option;
	double time1=0;
	double time2=0;
	double time3=0;
	int* copy; 

	printf("Please write the length of array: ");
	scanf_s("%d", &size);
	mas = (int*)malloc(size * sizeof(int)); // что именно делает здесь *int и почему выделяется память для mas?

	if (mas == NULL) // почему решает проблему с printf?
	{
		printf("Memory allocation failed for mas\n");
		return 1;
	}

	copy = (int*)malloc(size * sizeof(int));

	array_generating(mas, size);

	do
	{
		printf("Please choose the type of sort\n1 - Bubble sort\n2 - Search sort\n3 - Insertion sort\n4 - Show the received data\n");
		scanf_s("%d", &choose_option);

		if (choose_option == 1)
		{
			memcpy(copy, mas, size);
			clock_t start_time = clock();
			bubble_sort(copy, size);
			clock_t end_time = clock();
			time1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;			
		}

		if (choose_option == 2)
		{
			memcpy(copy, mas, size);
			clock_t start_time = clock();
			bubble_sort(copy, size);
			clock_t end_time = clock();
			time2 = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		}

		if (choose_option == 3)
		{
			memcpy(copy, mas, size);
			clock_t start_time = clock();
			bubble_sort(copy, size);
			clock_t end_time = clock();
			time3 = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		}

	} while (choose_option != 4);

	printf("Time of bubble sort %f seconds\n", time1);
	printf("Time of search sort %f seconds\n", time2);
	printf("Time of insertion sort %f seconds\n", time3);
	/*for (int i = 0; i < size; ++i)
	{
		printf("%d ", mas[i]);
	}*/
	free(mas); // надо?
	return 0;
}