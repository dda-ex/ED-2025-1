#include <stdlib.h>
#include <stdio.h>

int main() {
	
	int *iptr;
	
	iptr = (int *)malloc(sizeof(int));
	
	if (iptr == NULL)
		return -1;
	
	*iptr = 5;
	
	printf("%d , %p \n", *iptr, iptr);
	free(iptr);
	return 0;
}