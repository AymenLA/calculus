#include <stdio.h>
#include <stdint.h>

uint32_t print_data(uint32_t u32_val1)
{

	#ifdef DEBUG_PRINT
		printf("print_data running\n")
	#endif

	if(printf("print data : %d\n",u32_val1) != 0)
	{
		return 1;
	}

	return 0;
}

uint32_t print_text(uint8_t *u8p_text,uint8_t u8_type, uint8_t u8_color)
{
	return 0;
}