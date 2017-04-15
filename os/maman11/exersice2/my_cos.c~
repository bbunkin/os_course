/*Maman 11 exersice 2
 * my_cos.c
 *
 *  Created on: Mar 12, 2017
 *      Author: borisb
 */
#include <stdio.h>
#include <math.h>

#define ERR_THR 0.000001
#define M_PI 3.14159265358979323846264338327

/* Factorial function - returns factorial of n */
double factorial(double n){
 	double retval = 1;
 	double i;
 	for (i = n; i > 1; --i)
 		retval *= i;
 	return retval;
}

/* Absolute function - returns the absolute */
double abs_f(double x){ 
	return (x > 0)?x:-x;
	}

/* Normalize the x between 0 - 2pi */ 
double two_pi_modulu(double x){
	if (x > 2*M_PI)
	 	return two_pi_modulu(x - 2*M_PI);
	else if (x < 0)
		return 	two_pi_modulu(x + 2*M_PI);
	else
		return x;
	}

/* Function calculates cosine of x by Taylor series */
double my_cos(double x){
	int i=0;
	double sum=0,res;
	x = two_pi_modulu(x);
	do{
		res = (pow(-1,i)*pow(x,2*i))/factorial(2*i);
		i++;
		sum += res;
	}while(abs_f(res) > ERR_THR);
	return sum;
}

int main(void){
	double x;

	printf("Enter x in Radians\nx=");
	scanf("%lf",&x);
	printf("x=%.10f my_cos(X)=%.10f cos(X)=%.10f\n", x, my_cos(x), cos(x));

	return 0;
	}

