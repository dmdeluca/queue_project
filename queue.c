#include "queue.h"

typedef struct node
{
	struct node * next;
	int data;
} Node;

typedef struct queue
{
	Node * head;
	Node * tail;
	int length;
} Queue;

typedef Queue* pQueue;
typedef Node* pNode;

/*
pre:	none
post:	QUEUE object created and returned as opaque object handle, NULL returned if unsuccessful
*/
QUEUE qMake( )
{
	pQueue temp = ( pQueue ) malloc(sizeof(Queue));
	if ( temp )
	{
		temp->head = NULL;
		temp->tail = NULL;
		temp->length = 0;
		return ( QUEUE ) temp;
	}
	return NULL;
}

/*
pre:	phQ is a valid pointer to QUEUE object handle
post:	value at address phQ freed
*/
Status qKill(QUEUE* phQUEUE)
{
	if ( qValid(*phQUEUE) )
	{
		QUEUE* temp = phQUEUE;
		while ( !qIsEmpty(*phQUEUE) )
		{
			int itemp;
			qPop(*phQUEUE, &itemp);
		}
		free(*temp);
		*phQUEUE = NULL;
		return SUCCESS;
	}
	return FAILURE;
}

/*
pre:	none
post:	returns true if hQUEUE is a valid QUEUE object, false otherwise
*/
Boolean qValid(hQUEUE)
{
	if ( ( pQueue ) hQUEUE )
	{
		return TRUE;
	}
	return FALSE;
}


/*
pre:	hQUEUE is a valid QUEUE object handle
post:	length of hQUEUE returned as integer, or -1 on error
*/
int qLen(QUEUE hQUEUE)
{
	if ( qValid(hQUEUE) )
	{
		return ( ( pQueue ) hQUEUE )->length;
	}
	return -1;
}

/*
pre:	hQUEUE is a valid QUEUE object handle
post:	item pushed to queue hQUEUE
returns SUCCESS if push was successful
FAILURE otherwise
*/
Status qPush(QUEUE hQUEUE, int item)
{
	if ( qValid(hQUEUE) )
	{
		/* Make queue object transparent. */
		pQueue temp = ( pQueue ) hQUEUE;

		/* Create new node and fill with data. */
		pNode temp_node = ( pNode ) malloc(sizeof(Node));
		temp_node->data = item;
		temp_node->next = NULL;
		temp->length++;

		/* Store old tail. Update tail. */
		pNode oldtail = temp->tail;
		temp->tail = temp_node;

		/* Place the node in the queue. */
		if ( qIsEmpty(hQUEUE) )
		{
			temp->head = temp_node;
			return SUCCESS;
		}

		/* The queue was not empty. Need to place new item at end of queue. */
		oldtail->next = temp_node;
		return SUCCESS;

	}
	return FAILURE;
}
/*
pre:	hQUEUE is a valid QUEUE object handle
post:	item popped from queue and stored in dest
returns SUCCESS if pop was successful
FAILURE otherwise
*/



Status qPop(QUEUE hQUEUE, int * dest)
{
	if ( qValid(hQUEUE) )
	{
		if ( !qIsEmpty(hQUEUE) )
		{
			/* Make queue transparent and store address of first item */
			pQueue temp = ( pQueue ) hQUEUE;
			pNode temp_node = temp->head;
			/* Move head to "second" item. */
			temp->head = temp_node->next;
			/* Free the old head after storing the popped data. */
			if (dest )
				*dest = temp_node->data;
			free(temp_node);
			temp->length--;
			return SUCCESS;
		}
	}

	return FAILURE;
}

/*
pre:	hQUEUE is a valid QUEUE object handle
post:	empty status returned (true false)
*/
Boolean qIsEmpty(QUEUE hQUEUE)
{
	if ( qValid(hQUEUE) )
	{
		pQueue myQ = ( pQueue ) hQUEUE;
		if ( myQ->head )
			return FALSE;
		return TRUE;
	}
	return TRUE;
}

Status qReadAt(QUEUE hQUEUE, int place, int * dest)
{
	if ( qValid(hQUEUE) )
	{
		int len = qLen(hQUEUE);
		if ( place < len && dest && place >= 0 )
		{
			pQueue temp = ( pQueue ) hQUEUE;
			pNode temp_node = temp->head;
			for ( int i = 0; i < place; temp_node = temp_node->next, i++ );
			*dest = temp_node->data;
			return SUCCESS;
		}
	}
	return FAILURE;
}

int qSum(QUEUE hQUEUE)
{
	if ( qValid(hQUEUE) )
	{
		pQueue temp = ( pQueue ) hQUEUE;
		int sum = 0;
		pNode temp_node = temp->head;
		while ( temp_node )
		{
			sum += temp_node->data;
			temp_node = temp_node->next;
		}
		return sum;
	}
	return 0;
}