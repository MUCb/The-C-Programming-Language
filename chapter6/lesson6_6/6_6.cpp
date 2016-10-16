#include <stdio.h>

int main(){
	union vla{
		int ival;
		float fval;
		char *cval;
	} u;
	u.fval = 4;

		//printf("%f\n", u);
	printf("%15.2f.\n",100000.123456789 );
	printf("%-15.5f.\n",100000.123456789 );
	// printf("%.10s.\n","hello, world" );
	// printf("%-10s.\n","hello, world" );
	// printf("%.15s.\n","hello, world" );
	// printf("%-15s.\n","hello, world" );
	// printf("%15.10s.\n","hello, world" );
	// printf("%-15.10s.\n","hello, world" );
	// printf("%s.\n","hello, world" );
	// printf("%s.\n","hello, world" );

	return 0;
}