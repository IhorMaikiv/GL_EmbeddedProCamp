/*===========================================================================================================*/
/* Global Logic Embedded ProCamp                                                                             */
/* Lecture #01                                                                                               */
/* Homework Ex. #02                                                                                          */
/* Write function that converts data from RGB 888 to RGB 565 standard                                        */
/*===========================================================================================================*/
# include <stdio.h>
# include <stdint.h>

/* Data in RGB888 format is presented by uint32_t and occupies 3 bytes:
   RED field - bits[23:16], GREEN field - [15:8], BLUE field - [7:0]                                         */
#define RGB888_MASK       0xFFFFFFFF
  
#define RGB565_RED_MASK   0x001F0000 // new position of RED field (5 bits)
#define RGB565_GREEN_MASK 0x00003F00 // new position of GREEN field (6 bits)
#define RGB565_BLUE_MASK  0x0000001F // new position of BLUE field (5 bits)
/*-----------------------------------------------------------------------------------------------------------*/
/* Function prototypes declaration
/*-----------------------------------------------------------------------------------------------------------*/
uint16_t RGBconvert (uint32_t *tmp); // Function converts data presented in RGB 888 to RGB 565 standard 
/*-----------------------------------------------------------------------------------------------------------*/

main()
{
	uint32_t data_in;              // input data in range from 0-255
	uint32_t RGB888, *RGB888Ptr;   // data in RGB888 format
	uint16_t RGB565, *RGB565Ptr;   // data in RGB565 format
	char response;;                // user response: y - start and continue, q - quit

	RGB888Ptr = &RGB888;
	RGB565Ptr = &RGB565;

	printf ("Program converts data from RGB888 to RGB565 standard\n");
	printf ("Enter 'y' to contionue program or 'q'- quit: ");

	while ((response = getchar()) != 'q')
	{
		if (response == 'y')
		{
			RGB888 &= ~(RGB888_MASK);    // clear RGB888 variable
			printf ("\nEnter RED value in range 0x00-FF:");
			scanf  ("%x", &data_in);
			RGB888 |= (data_in << 16);   // write new value into RED field
			printf ("\nEnter GREEN value in range 0x00-FF:");
			scanf  ("%x", &data_in);
			RGB888 |= (data_in << 8);    // write new value into GREEN field
			
			printf ("\nEnter BLUE value in range 0x00-FF:");
			scanf  ("%x", &data_in);
			RGB888 |= data_in;    // write new value into BLUE field
			
			printf ("\nRGB888= 0x%08X\n\n", RGB888);
			*RGB565Ptr = RGBconvert(RGB888Ptr); // convert data from RGB888 to RGB565 format
			printf ("RGB565= 0x%04X\n", RGB565);
			
			printf ("\nDo you want to continue 'y'/'q' ?");
		}
		else
		{
			printf ("You shout press:\ny - to continue\nq - to exit\n");
		}
		while (getchar() != '\n')
			continue;
	}

	printf ("Exit!\n");

	return 0;	
}
/*-----------------------------------------------------------------------------------------------------------*/
/* Function converts data presented in RGB888 to RGB565 standard                                             */
/*-----------------------------------------------------------------------------------------------------------*/
uint16_t RGBconvert (uint32_t *tmp)
{
	
	// Data in RGB565 format is presented by uint16_t and occupies 2 bytes:
    // RED field   - [15:11],
	// GREEN field - [10:5],
	// BLUE field  - [4:0]

	// Conversion RGB fields:
	// RED fiel - cut 3 LSB, silect 5 bits and place new value of RED field on position RGB565[15:11] 
	uint16_t red   = (((*tmp >> 3) & RGB565_RED_MASK) >> 5);
	// GREEN field - cut 2 LSB, silect 6 bits and place new value of GREEN field on position RGB565[10:5]
	uint16_t green = (((*tmp >> 2) & RGB565_GREEN_MASK) >> 3);
	// BLUE field - cut 3 LSB, silect 5 bits and place new value of BLUE field on position RGB565[4:0]
	uint16_t blue  = (*tmp >> 3) & RGB565_BLUE_MASK;

	// Check new value of RED, GREEN and BLUE fields
	printf ("red   = 0x%04X\n", red);
	printf ("green = 0x%04X\n", green);
	printf ("blue  = 0x%04X\n", blue);

	// Concatenation RED, GREEN and BLUE fields in new variable RGB565
	return (red | green | blue );
}
/*-----------------------------------------------------------------------------------------------------------*/