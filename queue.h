#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "status.h"
#include <stdlib.h>

typedef void* QUEUE;

/*
pre:	none
post:	returns true if hQUEUE is a valid QUEUE object, false otherwise
*/
Boolean qValid(hQUEUE);

/*
pre:	none
post:	QUEUE object created and returned as opaque object handle, NULL returned if unsuccessful
*/
QUEUE qMake( );

/*
pre:	phQUEUE is a valid pointer to QUEUE object handle
post:	value at address phQUEUE freed
			returns SUCCESS if free was successful
			FAILURE otherwise
*/
Status qKill(QUEUE* phQUEUE);

/*
pre:	hQUEUE is a valid QUEUE object handle
post:	length of hQUEUE returned as integer, or -1 on error
*/
int qLen(QUEUE hQUEUE);

/*
pre:	hQUEUE is a valid QUEUE object handle
post:	item pushed to queue hQUEUE
			returns SUCCESS if push was successful
			FAILURE otherwise
*/
Status qPush(QUEUE hQ, int item);
/*
pre:	hQUEUE is a valid QUEUE object handle
post:	item popped from queue and stored in dest
	returns SUCCESS if pop was successful
	FAILURE otherwise
*/

Status qPop(QUEUE hQ, int * dest);

/*
pre:	hQUEUE is a valid QUEUE object handle
post:	empty status returned (true false)
*/
Boolean qIsEmpty(QUEUE hQ);


/*
pre:	hQUEUE is a valid QUEUE object handle
post:	value at place stored in dest (integer)
			returns SUCCESS if successful
			FAILURE otherwise
*/
Status qReadAt(QUEUE hQUEUE, int place, int * dest);

int qSum(QUEUE hQUEUE);

#endif // !_QUEUE_H_
