#include "sort.h"

/**
 * swap - swap a and b
 * @a: an int
 * @b: an int
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - Lomuto partition scheme
 * @arr: array to partition
 * @left: starting index
 * @right: ending index
 * @size: the size of array
 *
 * Return: index of the pivot after partitioning
 */
static int partition(int arr[], int left, int right, int size)
{
	int pivot = arr[right];
	int i = left;
	int j;

	for (j = left; j < right; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[right]);
	if (i != right)
		print_array(arr, size);
	return (i);
}

/**
 * quicksort - Quick Sort using Lomuto partitioning
 * @arr: array to sort
 * @left: starting index
 * @right: ending index
 * @size: number of elements
 */
void quicksort(int arr[], int left, int right, int size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = partition(arr, left, right, size);
		quicksort(arr, left, pivot_index - 1, size);
		quicksort(arr, pivot_index + 1, right, size);
	}
}

/**
 * quick_sort - sort array using quick sort
 * @array: an array of int
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	quicksort(array, 0, size - 1, size);
}

