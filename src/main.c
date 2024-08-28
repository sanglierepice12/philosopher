/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:52 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/28 15:27:52 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main()
{
/*

	long sec, final_sec = 0;
	gettimeofday(&tv,&tz);
	printf("tv = %lu\n", tv.tv_sec);
	printf("tv = %lu\n", tv.tv_usec);

	char c[456];
	scanf("%s", c);

	sec = tv.tv_sec;

	gettimeofday(&tv,&tz);
	printf("tv = %lu\n", tv.tv_sec);
	printf("tv = %lu\n", tv.tv_usec);

	final_sec = (tv.tv_sec - sec) * 1000 + tv.tv_usec / 10000;
	printf("%lu\n", final_sec);*/
	set_time();
	return (0);
}
