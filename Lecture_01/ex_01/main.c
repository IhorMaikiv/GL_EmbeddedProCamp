/*===========================================================================================================*/
/* Global Logic Embedded ProCamp                                                                             */
/* Lecture #01                                                                                               */ 
/* Homework Ex. #01                                                                                          */ 
/* Write swap16, swap32, swap64 functions that swap, bytes in uint16_t, unit32_t, and uint64_t variables     */
/*===========================================================================================================*/
# include <stdio.h>
# include <stdint.h>

/*-----------------------------------------------------------------------------------------------------------*/
/* Function prototypes declaration
/*-----------------------------------------------------------------------------------------------------------*/
uint16_t swap16 (uint16_t *tmp); // Function swaps two bytes in uint16_t variable                           
uint32_t swap32 (uint32_t *tmp); // Function swaps four bytes in uint32_t variable
uint64_t swap64 (uint64_t *tmp); // Function swaps eight bytes in uint64_t variable

main()
{
	uint16_t a, *aPtr;
	uint32_t b, *bPtr;
	uint64_t c, *cPtr;

	aPtr = &a;
	bPtr = &b;
	cPtr = &c;

	*aPtr = 0x410F;
	*bPtr = 0x23ADF0B5;
	*cPtr = 0x0123456789ABCDEF;

	printf ("Short integer variable takes %u bytes.\n\n", sizeof(uint16_t));
	printf ("Integer type variable %u bytes.\n\n", sizeof(uint32_t));
	printf ("Long long integer variable takes %u bytes.\n\n", sizeof(uint64_t));

	printf ("uint16_t=%04X after swapping\nuint16_t=%04X\n", a, swap16(aPtr));
	printf ("uint32_t=%08X after swapping\nuint32_t=%08X\n", b, swap32(bPtr));
	printf ("uint64_t=%016llX after swapping\nuint64_t=%016llX\n", c, swap64(cPtr));

	printf ("\nExit!\n");
	return 0;	
}
/*-----------------------------------------------------------------------------------------------------------*/
/* Function swaps two bytes in uint16_t variable                                                             */
/*-----------------------------------------------------------------------------------------------------------*/
uint16_t swap16 (uint16_t *tmp )
{
	return ((*tmp & 0x00FF) << 8) | ((*tmp & 0xFF00) >> 8);
}
/*-----------------------------------------------------------------------------------------------------------*/
/* Function swaps four bytes in uint32_t variable                                                            */
/*-----------------------------------------------------------------------------------------------------------*/
uint32_t swap32 (uint32_t *tmp )
{
	return ((*tmp & 0x000000FF) << 24) | ((*tmp & 0x0000FF00) <<  8) |
		   ((*tmp & 0x00FF0000) >>  8) | ((*tmp & 0xFF000000) >> 24);
}
/*-----------------------------------------------------------------------------------------------------------*/
/* Function swaps eight bytes in uint64_t variable                                                           */
/*-----------------------------------------------------------------------------------------------------------*/
uint64_t swap64 (uint64_t *tmp)
{
	return ((*tmp & 0x00000000000000FF) << 56) | ((*tmp & 0x000000000000FF00) << 40) | 
		   ((*tmp & 0x0000000000FF0000) << 24) | ((*tmp & 0x00000000FF000000) <<  8) |
		   ((*tmp & 0x000000FF00000000) >>  8) | ((*tmp & 0x0000FF0000000000) >> 24) |
		   ((*tmp & 0x00FF000000000000) >> 40) | ((*tmp & 0xFF00000000000000) >> 56);
}
/*-----------------------------------------------------------------------------------------------------------*/