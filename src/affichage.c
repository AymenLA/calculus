#include <stdio.h>
#include <stdint.h>

uint32_t print_data(uint32_t u32_val1)
{

	#ifdef DEBUG_PRINT
		printf("print_data running\n");
	#endif

	if(printf("print data : %d\n",u32_val1) != 0)
	{
		return 1;
	}

	return 0;
}

uint32_t print_hex(uint8_t *pu8_data,uint32_t u32_len)
{
	uint32_t u32_i = 0;

	for(u32_i = 1; u32_i < u32_len + 1; u32_i++)
	{
		printf("0x%0.2x ",*(pu8_data + u32_i - 1));

		if( (u32_i - ((u32_i / 8) * 8)) == 0)
		{
			printf("\n");
		}

		else if( (u32_i - ((u32_i / 4) * 4)) == 0)
		{
			printf("\t");
		}

	}
	printf("\n");

	return 0;	
}
uint32_t print_(uint8_t *u8p_text,uint8_t u8_type, uint8_t u8_color)
{
	return 0;
}