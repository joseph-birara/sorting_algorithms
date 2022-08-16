#include "sort.h"

/**
 * swapp - swaps node and prints
 * @current: node being moved right
 * @new: node being moved left
 * @list: pointer to head node
 */
void swapp(listint_t *current, listint_t *new, listint_t **list)
{
	/* - node - current - new - */
	current->next = new->next;
	if (current->next) /* check if node is tail */
		current->next->prev = current;
	new->next = current;
	new->prev = current->prev;
	if (new->prev) /* check if head node */
		new->prev->next = new;
	else /* node is  head */
		*list = new;
	current->prev = new;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: pointer to head node
 */
void cocktail_sort_list(listint_t **list)
{
	int unsorted = 1;
	listint_t *current, *start, *end;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	start = *list, end = NULL;

	while (unsorted) /* doesnt run if list is sorted */
	{
		unsorted = 0; /* considerd sorted */
		while (current->next && current != end)
		{	/* left --> right */
			if (current->n > current->next->n)
			{
				unsorted = 1; /* list is not sorted */
				swapp(current, current->next, list);
			}
			else /* current and next node are sorted */
				current = current->next;
		}
		end = current; /* tail node is greatest value, dont chk again*/

		if (!unsorted) /* if sorted from above loop, then break */
			break;

		unsorted = 0; /* resetting value */
		while (current->prev && current != start)
		{	/* right <--- left */
			if (current->n < current->prev->n)
			{
				unsorted = 1;
				swapp(current->prev, current, list);
			}
			else /* prev node and current are sorted */
				current = current->prev;
		}
		start = current; /* head is smallest value, dont chk again*/
	}
}
