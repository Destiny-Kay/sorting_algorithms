#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursively sorts a partition of the array using Quick Sort
 * @array: The array to be sorted
 * @low: The index of the low element of the partition
 * @high: The index of the high element of the partition
 * @size: The size of the original array
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		_quick_sort(array, low, pivot - 1, size);
		_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme
 * @array: The array to be sorted
 * @low: The index of the low element of the partition
 * @high: The index of the high element of the partition
 * @size: The size of the original array
 * Return: The pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
