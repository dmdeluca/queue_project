#include "queue.h"
#include <stdio.h>

void print_queue(QUEUE hQUEUE);

/* DRIVER */
int main(int argc, char ** argv)
{

	QUEUE myQueue = qMake( );

	int pop_holder;

	qPush(myQueue, 1);
	qPush(myQueue, 2);
	qPush(myQueue, 3);
	qPush(myQueue, 4);

	print_queue(myQueue);

	printf("sum is %d", qSum(myQueue));


	qPop(myQueue, NULL);
	qPop(myQueue, NULL);
	qPop(myQueue, NULL);

	printf("sum is %d", qSum(myQueue));

	print_queue(myQueue);

	qKill(&myQueue);

	return 0;
}

void print_queue(QUEUE hQUEUE)
{
	for ( int i = 0; i < qLen(hQUEUE); i++ )
	{
		int itemp;
		qReadAt(hQUEUE, i, &itemp);
		printf("%3d",itemp);
	}
	printf("\n");
}