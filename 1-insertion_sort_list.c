#include "sort.h"

/**
 * insertion_sort_list - sorts list with insertion sort
 * @list: input list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *pn, *nxt;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;
		pn = temp->prev;
		nxt = temp->next;

		while (temp)
		{
			if (temp->n < pn->n)
			{
				swap_list(pn, temp, nxt, list);
			}
			temp = nxt;
			if (temp)
			{
				nxt = temp->next;
				pn = temp->prev;
			}
		}
	}
}

/**
 * swap_list - swaps the position of two nodes in a linked list
 * @pn: previous node
 * @temp: temp
 * @nxt: next node
 * @h: head of list
 */
void swap_list(listint_t *pn, listint_t *temp, listint_t *nxt, listint_t **h)
{

	while (pn && temp->n < pn->n)
	{
		if (nxt)
			nxt->prev = pn;
		temp->next = pn;
		temp->prev = pn->prev;
		if (pn->prev)
			(pn->prev)->next = temp;
		pn->prev = temp;
		pn->next = nxt;
		nxt = pn;
		pn = temp->prev;
		if ((*h)->prev)
			*h = (*h)->prev;
		print_list(*h);
	}
}
