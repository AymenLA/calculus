#include <stdio.h>
#include <stdint.h>

#define OPTIMIZE_ITERATIONS

uint32_t add_tow(uint32_t *pu32_val1, uint32_t *pu32_val2)
{
	uint32_t u32_retval = 0;

	#ifdef DEBUG_PRINT
		printf("add_tow running\n")
	#endif

	u32_retval = *pu32_val1 + *pu32_val2;
	return u32_retval;
}

uint32_t multiply_tow(uint32_t *pu32_val1, uint32_t *pu32_val2)
{
	uint32_t u32_retval = 0;

	#ifdef DEBUG_PRINT
		printf("multiply_tow running\n")
	#endif

	u32_retval = *pu32_val1 * *pu32_val2;
	return u32_retval;	
}

uint32_t substitute_tow(uint32_t *pu32_val1, uint32_t *pu32_val2)
{
	int32_t i32_retval = 0;

	#ifdef DEBUG_PRINT
		printf("multiply_tow running\n")
	#endif

	i32_retval = *pu32_val1 - *pu32_val2;
	return i32_retval;	
}

uint32_t calcul_div(uint32_t u32_val1,uint32_t u32_val2)
{
	return (u32_val1 / u32_val2);
}

uint32_t calcul_mod(uint32_t u32_val1,uint32_t u32_val2)
{
	return (u32_val1 - (u32_val2 * (u32_val1 / u32_val2)));
}

uint32_t is_prime(uint32_t u32_num)
{
	uint32_t u32_i = 0;
	uint32_t u32_j = 1;
	uint32_t u32_k = 0;
	uint32_t u32_r = 0;
	uint8_t u8_flag = 0;
	do
	{
	#ifdef OPTIMIZE_ITERATIONS
		do
		{
	#else
		for(u32_j = 1; u32_j <= u32_i; u32_j++)
		{
	#endif
		

			u32_k = calcul_div(u32_i,u32_j);
			u32_r = calcul_mod(u32_i,u32_j);
			#if DEBUG_PRINT
			printf("%d / %d = %d (R = %d)\n",
									u32_i, 
									u32_j, 
									u32_k, 
									u32_r
									);
			printf("flag = %d\n", u8_flag);
			#endif /* DEBUG_PRINT */
			if( u32_j != 1 & u32_j != u32_i & u32_r == 0 )
			{
				u8_flag = 1;
				//printf("%d is not prime\n", u32_i);

			}
	#ifdef OPTIMIZE_ITERATIONS
			u32_j++;
		}while(u8_flag != 1 & u32_j < u32_i );
	#else
		}
	#endif
		if(u8_flag == 0)
		{
			printf("%d\n", u32_i);
		}

		u8_flag = 0;
		u32_i++; 
		#ifdef OPTIMIZE_ITERATIONS
			u32_j = 1; 
		#endif
	}while(u32_i < u32_num);

	return 0;
}

uint32_t ret_mod(uint32_t u32_val1, uint32_t u32_val2)
{

}