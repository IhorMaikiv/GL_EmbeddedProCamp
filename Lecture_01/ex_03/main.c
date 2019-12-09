/*===========================================================================================================*/
/* Global Logic Embedded ProCamp                                                                             */
/* Lecture #01                                                                                               */ 
/* Homework Ex. #03                                                                                          */ 
/* Program gets height and width of rectangle (in meters) and calculate perimeter and area (in inches)       */
/*===========================================================================================================*/
# include <stdio.h>

main ()
{
	float width_m;     // width of rectangle in meters
	float width_inch;  // width of rectangle in inches
	float height_m;    // height of rectangle in meters
	float height_inch; // height of rectangle in inches

	const float inch = 0.0254; // length of inche in meter

	printf ("Enter the height of rectangle in metters L=" );
	scanf ("%f", &height_m);
	printf ("\nEnter the width of rectangle in metters W=" );
	scanf ("%f", &width_m);
	height_inch = height_m / inch;
	width_inch = width_m / inch;

	printf ( "\nSquare of rectangle is S=%.3f square inches.\n", height_inch * width_inch  );
	printf ( "\nPerimeter of rectangle is P=%.3f inches.\n", 2 * (height_inch + width_inch) );
	printf ( "\nExit!\n" );
	return 0;
}