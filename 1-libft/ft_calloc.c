/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:25:07 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/11 14:29:09 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long size_t;

void *ft_calloc(size_t nmemb, size_t size){
	size_t memsize;
	void* pMem;

	if (nmemb == 0 || size == 0)
		return 0;
	memsize = nmemb * size;
	pMem = malloc(memsize);
	ft_bzero(pMem, memsize);

	return pMem;
}

int main(){
	size_t nmemb = 2;
	size_t size = 3;
	ft_calloc(nmemb, size);
	
	return 0;
}