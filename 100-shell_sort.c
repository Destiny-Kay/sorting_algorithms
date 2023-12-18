#include "sort.h"
/**
 * shell_sort - implementation of the shell sort algorithm
 * using the knuth sequence
 * @array:  an array of integers to be sorted
 * @size: The size of the array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (i >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
