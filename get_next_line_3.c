/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:24:27 by araveala          #+#    #+#             */
/*   Updated: 2024/01/11 12:01:09 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

size_t  ft_strlen(char *s) //char const
{
    int counter;
	printf("STRLEN");
    counter = 0;
    while (*s != '\0')
    {
        counter++;
        s++;
    }
    return (counter);
}

size_t  ft_strlcpy(char *dst, char *src, size_t dstsize)//src const
{
    size_t  i;
    size_t  len;

    len = ft_strlen(src); //buffer doesnt have 0
    i = 0;
    if (dstsize == 0)
        return (len);
    while (*src != '\0' && i < (dstsize - 1))
    {
        i++;
        *dst++ = *src++;
    }
    *dst = '\0';
    return (len);
}

char    *ft_strjoin(char  *s1, char  *s2)// both const //, int len)
{
    char    *new;
    int     total_len;
    int     i;

    i = 0;
	printf("STRJOIN\n");
    if (!s1 || !s2)
        return (NULL);
    total_len = ft_strlen(s1) + ft_strlen(s2);
	printf("total len in strjoin = %d\n", total_len); //why we get 10???
    new = malloc(1 * total_len + 1); //sizeof(char) not fixing it
    if (!new)
        return (NULL);
    while (s1[i])
    {
        new[i] = s1[i];
        i++;
    }
    ft_strlcpy(&new[i], s2, ft_strlen(s2));
	printf("new = %s\n", new);
    return (new);
}

int find_it(char c, char *str, int length)
{
    int i;

    i = 0;
    while (i != BUFFER_SIZE + 1)
    {
        if (*str == c)
        {
            printf("switched\n");
            return (i);
        }
        printf("str loc = %c i = %d\n", *str, i);
		i++;
        str++;
    }
	printf("END OF FIND IT\n");
    return (0);
}

/*char    *ft_substr(char *s, unsigned int start, size_t len)
{
    char            *sub_str;
    size_t          i;
    unsigned int    str_len;

    i = 0;
    if (!s)
        return (NULL);
    str_len = ft_strlen(s);
    if (str_len - start < len)
        len = str_len - start;
    if (start + len > str_len)
        len = 0;
    sub_str = calloc(len + 1, sizeof(char));//sizeof(char)); //FIX CALLOC
    if (sub_str == NULL)
        return (NULL);
    if (start < str_len)
    {
        while (i < len && s[start] != '\0')
            sub_str[i++] = s[start++];
    }
    sub_str[i] = '\0';
    return (sub_str);
	}*/

/* void    *ft_calloc(size_t count, size_t size)
{
    void    *storage_ptr;
	int i;

	i = 0;
    storage_ptr = malloc(count * size);
    if (storage_ptr == NULL)
        return (NULL);
    while (size-- > 0)
	{
		storage_ptr = 0;
		storage_ptr++;
	}
    return (storage_ptr);
}*/

char *get_line(char *buffer, int x)
{
	static char *left_overs;
	char *lineb;
	char *line;

	printf("START\n");

	//if (x == 1)
	//lineb = NULL;
	//printf("lineb start = %s\n", lineb);//causes new  segfault 
	if (buffer)//((find_it('\n', buffer, BUFFER_SIZE)) == 0)
	{
		printf("buffer found\n");
		if (x == 1)
		{
			printf("line empty\n");
			line = malloc(1 * BUFFER_SIZE + 1);// do i need plus 1 here??? //len + 1); //BUFFER_SIZE + 1);
			printf("plo\n");
			if (!line)
				return (NULL);
			printf("plo\n");
			strlcpy(line, buffer, BUFFER_SIZE + 1); //buffer size might not be the right answer
			printf("first line fill = %s\n", line);
			return (line);
		}
		if (x > 1)
		{
//problem is here
			printf("line not empty \n");
//			if (x == 1)
//				lineb = "x";
			printf("line = %s\n", line);
			lineb = ft_strjoin(line, buffer);
			printf("lineb = %s\n", lineb);
		}
	}
	printf("check\n");
	return (lineb);
}

char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int read_len;
	char *final_line;
	char *line2;
	int x;

	x = 0;
//	final_line = malloc(1, 1);
	while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		if ((find_it('\n', buffer, BUFFER_SIZE)) > 0)
			final_line = get_line(buffer, x); //ft_strjoin((line2, get_line(buffer, x))?
		//this will be last, need strjoin here .
		//also check read-len?
		if ((find_it('\n', buffer, BUFFER_SIZE)) == 0)
		{
			// x = number of rounds , round 1 is first round.
			printf("x = %d\n", x);
			x++;
			line2 = get_line(buffer, x);
			printf("line2 = %s\n", line2);

		}
	}
	return (final_line);
}

int main()
{
    int fd;
    char *test;

    fd = open("testies.txt", O_RDONLY);
    if ((test = get_next_line(fd)) != NULL) //(read(fd, santi.buff, BUFFER_SIZE)
    {
        printf("%s\n", test); //get_next_line(fd));
        //if (-1)
        //break;
    }
    free(test);
    close(fd);
}
