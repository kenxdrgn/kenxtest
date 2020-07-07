/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:15 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 03:15:40 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "time.h"
#include "ctype.h"
#include "string.h"
#include "limits.h"
#include "../includes/libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
    {
		printf("-----------------------\n");
		printf(" int ft_isascii(int c)\n");
		printf("-----------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run --print\n");
        printf("usage [manual]:\n1. a <int c>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		long cnt = 0;
		long failed = 0;

		printf("Running small test(s): ft_isascii\n");
		for (int i = 0; i <= 127; i++)
		{
			cnt++;
			if (isascii(i) != ft_isascii(i))
			{
				failed++;
				printf("FAILED case: %d , st: %d, ft: %d\n", i, isascii(i), ft_isascii(i));
			}
			if (argc == 3 && !strcmp(argv[2], "--print"))
				printf("%ld: test case: %c , st: %d, ft: %d\n", cnt, i, isascii(i), ft_isascii(i));
		}
		double rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);

		printf("Running full test(s): ft_isascii\n");
		cnt = 0;
		failed = 0;
		for (long i = INT_MIN; i <= INT_MAX; i++)
		{
			cnt++;
			if (isascii(i) != ft_isascii(i))
			{
				failed++;
				printf("FAILED case: %ld , st: %d, ft: %d\n", i, isascii(i), ft_isascii(i));
			}
		}
		rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);
	}
	else
	{
		printf("st: %i\n", isascii(atoi(argv[1])));
		printf("ft: %i\n", ft_isascii(atoi(argv[1])));
	}
}