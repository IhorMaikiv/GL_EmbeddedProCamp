/*===========================================================================================================*/
/* Global Logic Embedded ProCamp                                                                             */
/* Lecture #01                                                                                               */ 
/* Homework Ex. #05                                                                                          */ 
/* Program computes factorial of 10                                                                          */
/*===========================================================================================================*/
# include <stdio.h>

// Function prototype declaration
long factorial (long);

main ()
{
	int i;

	for ( i=1; i<=10; i++ )
	{
		printf ("Factorial %2d! = %ld\n", i, factorial(i));
	}
	printf ("\nExit!\n");
	return 0;
}
/*-----------------------------------------------------------------------------------------------------------*/
long factorial (long digit )
{
	if ( digit <= 1 )
		return 1;
	else
		return ( digit * factorial(digit-1));
}
/*-----------------------------------------------------------------------------------------------------------*/