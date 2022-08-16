#include "sort.h"

/**
 * radix_sort - sorts an array in ascending order: Radix sort
 * @array: bigger than 0, numbers to be sorted
 * @size: size of array
 * Return: is void
 */
void radix_sort(int *array, size_t size)
{
	int maximum, digits = 0, power = 1, *new_array, count[10], num, i;
	unsigned int j, k;

	if (array == NULL || size < 2)
		return;
	new_array = malloc(sizeof(int) * (int)size);/* initialize new_array */
	if (new_array == NULL)
		return;
	for (k = 1 ; k < size ; k++)/* find biggest number */
	{
		if (maximum < array[k])
			maximum = array[k];
	}
	for (; maximum > 0 ; digits++)/* count the digits of the max munber*/
		maximum /= 10;
	for (i = 0 ; i < digits ; i++)/* arrange numbers */
	{
		for (j = 0 ; j < 10 ; j++)/* init count array*/
			count[j] = 0;
		for (j = 0 ; j < size ; j++)/* calc freq of digits */
		{
			num = (array[j] / power) % 10;
			count[num]++;
		}
		for (j = 1 ; j < 10 ; j++)/* cumulative freq of count aray*/
			count[j] += count[j - 1];
		for (j = size - 1 ; ((int)j >= 0) ; j--)/* new positions in the new array*/
		{
			num = (array[j] / power) % 10;
			new_array[count[num] - 1] = array[j];
			count[num]--;
		}
		for (j = 0 ; j < size ; j++)/* updating the original array with new_array */
			array[j] = new_array[j];
		print_array(array, size);/* print as per directions */
		power *= 10;/* update digit for next iteration */
	}
	free(new_array);/* free new_array */
}
