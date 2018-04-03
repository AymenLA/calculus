#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "calcul.h"
#include "affichage.h"

uint32_t main(uint32_t argc, uint32_t *argv)
{
	#if (defined(DEBUG_L1) && (DEBUG_L1==0))
		printf("debug message :\n");
	#endif /* DEBUG_L1 */
	uint32_t *pu32_val1, *pu32_val2;

	pu32_val1 = NULL;
	pu32_val2 = NULL;

	pu32_val1 = malloc(sizeof(uint32_t));
	if(pu32_val1 == NULL)
	{
		printf("error on allocating memory\n");
	}

	pu32_val2 = malloc(sizeof(uint32_t));
	if(pu32_val2 == NULL)
	{
		printf("error on allocating memory\n");
	}

	*pu32_val1 = 25;
	*pu32_val2 = 27;

	print_data(*pu32_val1);
	print_data(*pu32_val2);
	print_data(add_tow(pu32_val1,pu32_val2));
	print_data(multiply_tow(pu32_val1,pu32_val2));
	print_data(substitute_tow(pu32_val1,pu32_val2));
	is_prime(25);

	free(pu32_val1);
	free(pu32_val2);
	return 0;
}