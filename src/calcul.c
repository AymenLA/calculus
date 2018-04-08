#include <stdio.h>
#include <stdint.h>

#define OPTIMIZE_ITERATIONS

#define BINARY_PATERN "%c%c%c%c%c%c%c%c"
#define BINARY(byte_data)  \
  (byte_data & 0x80 ? '1' : '0'), \
  (byte_data & 0x40 ? '1' : '0'), \
  (byte_data & 0x20 ? '1' : '0'), \
  (byte_data & 0x10 ? '1' : '0'), \
  (byte_data & 0x08 ? '1' : '0'), \
  (byte_data & 0x04 ? '1' : '0'), \
  (byte_data & 0x02 ? '1' : '0'), \
  (byte_data & 0x01 ? '1' : '0') 

#define FIRST_6_BITS(byte_data) \
  ((byte_data >> 2) & 0x3f)
#define LAST_2_BITS(byte_data)  \
  ((byte_data  & 0x3f)

#define FIRST_4_BITS(byte_data)
#define LAST_4_BITS(byte_data)

#define FIRST_2_BITS(byte_data)
#define LAST_6_BITS(byte_data)  


#if DEBUG_PRINT
  	#define PRINT_BINARY_TAB(data) \
    printf("value = 0b"BINARY_PATERN" , ",BINARY(data))
  	#define PRINT_CARRY_TYPE(data) \
    printf("old_u8_carry_type = %d   , ", data)
    #define PRINT_CARRY_VALUE(data) \
    printf("old_u8_carry = 0b"BINARY_PATERN" , ",BINARY(data))
#endif

uint32_t add_tow(uint32_t *pu32_val1, uint32_t *pu32_val2)
{
	uint32_t u32_retval = 0;

	#ifdef DEBUG_PRINT
		printf("add_tow running\n");
	#endif

	u32_retval = *pu32_val1 + *pu32_val2;
	return u32_retval;
}

uint32_t multiply_tow(uint32_t *pu32_val1, uint32_t *pu32_val2)
{
	uint32_t u32_retval = 0;

	#ifdef DEBUG_PRINT
		printf("multiply_tow running\n");
	#endif

	u32_retval = *pu32_val1 * *pu32_val2;
	return u32_retval;	
}

uint32_t substitute_tow(uint32_t *pu32_val1, uint32_t *pu32_val2)
{
	int32_t i32_retval = 0;

	#ifdef DEBUG_PRINT
		printf("multiply_tow running\n");
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

uint32_t to_base64(uint8_t *pu32_inbuf, uint8_t *pu32_outbuf)
{
	uint8_t u8_scan = 0;
	uint32_t u32_i, u32_size;
	uint8_t u8_temp_var = 0, u8_carry = 0, u8_carry_type = 0;
	// u8_carry_type : 0 if none, else 2 or 4 
	uint8_t u8_test_tab[] = {
		'a', 'b', 'x', 'y',
		'A', 'B', 'X', 'Y',
		'1', '9', '.', '@',
		'e', '&', 't', 'g',
		':', ';', 'M', '5',
		's', 'B', 'p', ' ',
		'G', 'z', '#', ')',
	};
	// TBD : source wikipedia : visit https://fr.wikipedia.org/wiki/Base64
/*

	    Valeur Codage         Valeur Codage         Valeur Codage         Valeur Codage
      0 000000 A           17 010001 R           34 100010 i           51 110011 z
      1 000001 B           18 010010 S           35 100011 j           52 110100 0
      2 000010 C           19 010011 T           36 100100 k           53 110101 1
      3 000011 D           20 010100 U           37 100101 l           54 110110 2
      4 000100 E           21 010101 V           38 100110 m           55 110111 3
      5 000101 F           22 010110 W           39 100111 n           56 111000 4
      6 000110 G           23 010111 X           40 101000 o           57 111001 5
      7 000111 H           24 011000 Y           41 101001 p           58 111010 6
      8 001000 I           25 011001 Z           42 101010 q           59 111011 7
      9 001001 J           26 011010 a           43 101011 r           60 111100 8
     10 001010 K           27 011011 b           44 101100 s           61 111101 9
     11 001011 L           28 011100 c           45 101101 t           62 111110 +
     12 001100 M           29 011101 d           46 101110 u           63 111111 /
     13 001101 N           30 011110 e           47 101111 v
     14 001110 O           31 011111 f           48 110000 w        (complément) =
     15 001111 P           32 100000 g           49 110001 x
     16 010000 Q           33 100001 h           50 110010 y

*/	

     uint8_t u8_out_index[] = 
     {
     	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',  // 7
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',  // 15
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',  // 23
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',  // 31
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',  // 39
     	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',  // 47
     	'w', 'x', 'y', 'z', '0', '1', '2', '3',  // 55
     	'4', '5', '6', '7', '8', '9', '+', '/',  // 63
     	'=', // 64
     };

     u32_size = sizeof(u8_test_tab);

     printf("size in ASCII: %d\n ",u32_size  );
     printf("size in base64: %d\n ",(u32_size * 8) /6 );
     printf("needed padding : %d\n ",((u32_size * 8) /6) -(((((u32_size * 8) /6)) /4)*4) );

     for (u32_i = 0; u32_i < u32_size; u32_i++)
     {
     	printf("0b"BINARY_PATERN", %c\n",BINARY(u8_test_tab[u32_i]), u8_test_tab[u32_i]);
	 }
	 printf("\n");

     for (u32_i = 0; u32_i <= u32_size; u32_i++)
     {
     	if((u8_carry_type != 0))
     	{
     		if(u8_carry_type == 2)
     		{
     			#if DEBUG_PRINT
     				PRINT_BINARY_TAB(u8_test_tab[u32_i]);
     				PRINT_CARRY_TYPE(u8_carry_type);
     				PRINT_CARRY_VALUE(u8_carry);
     			#endif
     			u8_temp_var = ((u8_test_tab[u32_i] >> 4) & 0x0f) | u8_carry	;

     			u8_carry = ((u8_test_tab[u32_i]) << 2 ) & 0x3c ;
     			u8_carry_type = 4;
     		}

     		else if(u8_carry_type == 4)
     		{
     			#if DEBUG_PRINT
     				PRINT_BINARY_TAB(u8_test_tab[u32_i]);
     				PRINT_CARRY_TYPE(u8_carry_type);
     				PRINT_CARRY_VALUE(u8_carry);
     			#endif

     			u8_temp_var = ((u8_test_tab[u32_i] >> 6) & 0x03) | u8_carry ;

     			u8_carry_type = 6;
     			u8_carry = u8_test_tab[u32_i] & 0x3f;
 				u32_i--;

     		}  	
     		else if(u8_carry_type == 6)
     		{
     			#if DEBUG_PRINT
     				PRINT_BINARY_TAB(u8_test_tab[u32_i]);
     				PRINT_CARRY_TYPE(u8_carry_type);
     				PRINT_CARRY_VALUE(u8_carry);
     			#endif

     			u8_temp_var =  u8_carry & 0x3f;
     			
     			u8_carry_type = 0;
     			u8_carry = 0;   

     		}	
     	}
     	else
     	{
     			#if DEBUG_PRINT
     				PRINT_BINARY_TAB(u8_test_tab[u32_i]);
     				PRINT_CARRY_TYPE(u8_carry_type);
     				PRINT_CARRY_VALUE(u8_carry);
     			#endif

     		u8_temp_var = (u8_test_tab[u32_i] >> 2) & 0x3f;
     		u8_carry_type = 2;
     		u8_carry = (u8_test_tab[u32_i] << 4 ) & 0x30;
     	}

     	#if DEBUG_PRINT
     	printf("0b"BINARY_PATERN", ",BINARY(u8_temp_var));
     	printf("0x%0.2x : %d, " ,u8_temp_var, u32_i);
     	#endif

     	if(u8_temp_var <= 63)
     	{
     		printf("%c\n" ,u8_out_index [u8_temp_var]);
     	}
     	else
     	{
     		printf("%c\n", u8_out_index[64]);
     	}
     	
     }
}