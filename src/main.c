/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:30:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 02:29:02 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "mb_core.h"
#include "mb_real_float.h"

#define HEIGHT 40
#define WIDTH 80
#define MAX_ITERATION_COUNT 4242

static size_t	get_iteration_count(
	t_mb *context,
	size_t y,
	size_t x,
	size_t *out
)
{
	t_mb_real	*r;
	t_mb_real	*i;
	t_mb_err	result;

	r = mb_real_float_new((float)x * 4 / ((float)WIDTH - 1) - 3);
	if (!r)
		return (true);
	i = mb_real_float_new((float)y * 4 / ((float)HEIGHT - 1) - 2);
	if (!i)
	{
		mb_real_float_delete(r);
		return (true);
	}
	result = mb(context, r, i, out);
	mb_real_float_delete(r);
	mb_real_float_delete(i);
	return (result);
}

int	main(void)
{
	size_t	i;
	size_t	j;
	size_t	iteration_count;
	bool	is_space;
	t_mb	*context;

	if (mb_new(mb_real_float(), 2, MAX_ITERATION_COUNT, &context))
		exit(EXIT_FAILURE);
	i = (size_t)-1;
	while (++i < HEIGHT)
	{
		j = (size_t)(-1);
		while (++j < WIDTH)
		{
			if (get_iteration_count(context, i, j, &iteration_count))
				exit(EXIT_FAILURE);
			is_space = iteration_count == MAX_ITERATION_COUNT;
			if (is_space)
				putchar(' ');
			else
				putchar('x');
		}
		putchar('\n');
	}
}
