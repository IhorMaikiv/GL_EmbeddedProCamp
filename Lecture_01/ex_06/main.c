/*===========================================================================================================*/
/* Global Logic Embedded ProCamp                                                                             */
/* Lecture #01                                                                                               */ 
/* Homework Ex. #06                                                                                          */ 
/* Program prints all numbers between 1 to 500 which divided by a number specified by user                   */
/*===========================================================================================================*/
# include <stdio.h>

main()
{
	int i;        // cycle counter
	int digit;    // input variable
	int reminder; // reminder of division
	
	printf ("Enter the number N=" );
	scanf  ("%d", &digit);

	printf ("\nList all numbers between 1 to 500 that can be divided on %d is printed below:\n", digit);

	while ( digit > 0)
	{
		for ( i=1; i<=500; i++ )
		{
			reminder = i % digit;
			if ( reminder == 0 )
			printf ("%d\n", i);
		}
		printf ("\nEnter new value or '0' if you want to exit N=");
		scanf  ("%d", &digit) ;
	}

	printf ("\nExit!\n");

	return 0;
}