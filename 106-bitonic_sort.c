#include "sort.h"
void bitonic_deep_up(int *array_init, int *array, size_t size_init, size_t size, int *flag);
void compare_swap_down(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	int n;
	size_t i;
	(void)array_init;	
	if (flag[0] == 0)
	{
		for (i = 0; i < size/2 ; i++)
		{
			if (array[0] < array[size - 1])
			{
				n = array[0];
				array[0] = array[size - 1];
				array[size - 1] = n;
				printf("Result [%lu/%lu] (DOWN):\n", size, size_init);
				print_array(array, size);
			}
		}
	}
}
void compare_swap_up(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	int n;
	size_t i;
	(void)array_init;	
	if (flag[0] == 0)
	{
		for (i = 0; i < size/2 ; i++)
		{
		if (array[0] > array[size - 1])
		{
			n = array[0];
			array[0] = array[size - 1];
			array[size - 1] = n;
			printf("Result [%lu/%lu] (UP):\n", size, size_init);
			print_array(array, size);
		}
		}
	}
}
void bitonic_deep_down(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	(void)array;	
	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	printf("Merging [%lu/%lu] (DOWN):\n", size, size_init);
	print_array(array, size);
	bitonic_deep_up(array_init, array, size_init, size / 2, flag);
	compare_swap_up(array_init, array, size_init, size, flag);	
	bitonic_deep_down(array_init, array + (size/2), size_init, size / 2, flag);	
	compare_swap_down(array_init, array, size_init, size, flag);	
}
void bitonic_deep_up(int *array_init, int *array, size_t size_init, size_t size, int *flag)
{
	(void)array;	
	if (size < 2)
	{
		flag[0] = 0;
		return;
	}	
	printf("Merging [%lu/%lu] (UP):\n", size, size_init);
	print_array(array, size);
	bitonic_deep_up(array_init, array, size_init, size / 2, flag);
	compare_swap_up(array_init, array, size_init, size, flag);
	bitonic_deep_down(array_init, array + (size/2), size_init, size / 2, flag);
	compare_swap_down(array_init, array, size_init, size, flag);
}
/**
 * bitonic_sort - sorts
 * @array: input
 *@size: size of input
 *
 **/
void bitonic_sort(int *array, size_t size)
{
	size_t size_init = size;
	int *array_init = array;
	int *flag;
	int aux = {0};

	flag = &aux;
	if (array)
	{
		bitonic_deep_up(array_init, array, size_init, size, flag);
	}	
}