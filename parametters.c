#include "main.h"

/**
 * init_params - Initializes all fields of the parameters struct to
 * their default values and clears the buffer.
 * @params: Pointer to the parameters struct.
 * @ap: argument of a pointer
 * Return: Nothing
 */

void init_params(prm_t *params, va_list ap)
{
	(*params).unsign = 0;

	(*params).plus_f = 0;
	(*params).space_f = 0;
	(*params).hashtag_f = 0;
	(*params).zero_f = 0;
	(*params).minus_f = 0;

	(*params).widths = 0;
	(*params).precisions = UINT_MAX;

	(*params).modifier_h = 0;
	(*params).modifier_l = 0;

	(void)ap;
}
