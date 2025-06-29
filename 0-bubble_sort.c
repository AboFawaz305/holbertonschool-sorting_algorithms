#include "sort.h"

/**
 * swap - swap elements i and j
 * @array: an array
 * @i: the first element
 * @j: the second element
 * @size: the size of array
 */
void swap(int *array, int i, int j, int size)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * bubble_sort - sort array using bubble sort
 * @array: an array of numbers to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j;
	char is_sorted;

	if (array == NULL)
		return;
	for (i = size, is_sorted = 0; i >= 1 && !is_sorted; i--)
	{
		is_sorted = 1;
		for (j = 1; j < i; j++)
			if (array[j - 1] > array[j])
			{
				swap(array, j - 1, j, size);
				is_sorted = 0;
			}
	}
}

