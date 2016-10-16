#include <stdio.h>
#include <ctype.h>
#include <math.h>
double atof (char s[]);

int main(){
	printf("%e\n",-123.0 );
	char s[]="-1.12e+012";
	printf("res= %f\n", atof(s));
	return 0;
}

double atof (char s[])
{
	double val, val1, power, res;
	res =0.0;
	int i, sign , sign1;
	for (i = 0; isspace (s[i]); i++)
		; 
	printf("d=%d\n",i );
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit (s[i]); i++)
		val = 10.0 * val + (s[i] - '0'); 
	if (s[i] =='.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val1=0.0;

	if (s[i] == 'e') {
		i++;
		//printf("eee\n");
		if (s[i] == '+' || s[i] == '-')
			sign1 = (s[i] == '-') ? -1 : 1;
		i++;
		for (val1=0.0; isdigit (s[i]); i++)
			val1 = 10.0 * val1 + (s[i] - '0'); 
	}
	printf("%f\n", val1);
	res = sign * val / power * pow(10,val1);
	return res;
}