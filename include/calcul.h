#ifndef _CALCUL_H_
#define _CALCUL_H_

uint32_t add_tow(uint32_t *pu32_val1, uint32_t *pu32_val2);
uint32_t multiply_tow(uint32_t *pu32_val1, uint32_t *pu32_val2);
uint32_t substitute_tow(uint32_t *pu32_val1, uint32_t *pu32_val2);
uint32_t calcul_div(uint32_t u32_val1,uint32_t u32_val2);
uint32_t calcul_mod(uint32_t u32_val1,uint32_t u32_val2);
uint32_t is_prime(uint32_t u32_num);
uint32_t to_base64(uint8_t *pu32_inbuf, uint8_t *pu32_outbuf);

#endif /* _CALCUL_H_ */