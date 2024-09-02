#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i;
	char *num = argv[0];

	fprintf(stdout, "arg[0] = %s \n", argv[0]);
	
	for (i = 0; i < strlen(argv[0]); i++)
		fprintf(stdout, "num[%d] = %c \n", i, num[i]);

	return 0;
}