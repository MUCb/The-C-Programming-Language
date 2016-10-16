#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
	printf("CHAR_BIT = %d\n", CHAR_BIT);
	printf("CHAR_MIN = %d\n", CHAR_MIN);
	printf("CHAR_MAX = %d\n", CHAR_MAX);
	printf("UCHAR_MAX = %x\n", UCHAR_MAX);

	printf("SHRT_MIN = %d\n", SHRT_MIN);
	printf("SHRT_MAX = %d\n", SHRT_MAX);	
	printf("USHRT_MAX = %x\n", USHRT_MAX);

	printf("INT_MIN = %d\n", INT_MIN);
	printf("INT_MAX = %d\n", INT_MAX);	
	printf("UINT_MAX = %x\n", UINT_MAX);

	printf("LONG_MIN = %ld\n", LONG_MIN);
	printf("LONG_MAX = %ld\n", LONG_MAX);	
	printf("ULONG_MAX = %lx\n", ULONG_MAX);	

	printf("FLT_MIN = %e\n", FLT_MIN);
	printf("FLT_MAX = %e\n", FLT_MAX);	
	printf("FLT_RADIX = %lx\n", FLT_RADIX);	

	printf("DBL_MIN = %0.2e\n", DBL_MIN);
	printf("DBL_MAX = %0.3e\n", DBL_MAX);	
	printf("DBL_MAX_EXP = %x\n", DBL_MAX_EXP);	


	return 0;
}