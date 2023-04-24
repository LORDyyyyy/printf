#include "main.h"

/**
 * init_params - a function that give the 'parameters' struct
 * members its initial value
 * @params: the struct pointer
 *
 * Return: void
 */
void init_params(params_t *params)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;
}
