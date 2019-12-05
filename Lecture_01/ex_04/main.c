/*===========================================================================================================*/
/* Global Logic Embedded ProCamp                                                                             */
/* Lecture #01                                                                                               */ 
/* Homework Ex. #04                                                                                          */ 
/* Program computes the perimeter and area of a circle                                                       */
/*===========================================================================================================*/
# include <stdio.h>

main ()
{
	float radius;
	const float pi = 3.14;

	printf ("Enter the radius of circle in metters R=" );
	scanf ("%f", &radius);

	printf ("\nSquare of circle is S=%.3f square meters.\n", (pi * radius * radius));
	printf ("\nLength of circle is L=%.3f meters.\n", (2 * pi* radius));
	printf ("\nExit!\n");
	return 0;
}