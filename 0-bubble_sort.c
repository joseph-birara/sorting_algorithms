#include "sort.h"
/**
 *bubble_sort - sorts array of integers using bubble_sort
 * @array: arry to be sorted
 * @size : number of elements
 */


void bubble_sort(int *array, size_t size)
{
size_t c, j;
int temp;
for (c = 0; c < size; c++)
{
for (j = 0; j < size - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
}
}


