/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:24:27 by araveala          #+#    #+#             */
/*   Updated: 2024/01/11 19:44:21 by araveala         ###   ########.fr       */
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

void    *ft_calloc(int count, int size)
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
}

int  ft_strlen(char *s) //char const
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

char  ft_strlcpy(char *dst, char *src, int dstsize)//src const
{
    int  i;
    int  len;
	
	printf("WEE");
    len = ft_strlen(src); //buffer doesnt have 0
    i = 0;
    if (dstsize == 0)
        return (len);//return (len);
    while (*src != '\0' && i < (dstsize))
    {
        *dst++ = *src++;
		i++;
    }
    *dst = '\0';
    return (len); //(len)
}

char    *ft_strdup(char *s1)
{
    char    *new;

    new = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
    if (new == NULL)
        return (NULL);
    ft_strlcpy(new, s1, ft_strlen(s1) + 1);
    return (&*new);
}

char    *ft_strjoin(char  *s1, char  *s2)// both const //, int len)
{
    char    *new;
    int     total_len;
    int     i;

    i = 0;
	printf("STRJOIN\n");
	printf("s2 = %s\n", s2);
    if (!s1 || !s2)
        return (NULL);
    total_len = ft_strlen(s1) + ft_strlen(s2);
	printf("total len in strjoin = %d\n", total_len); //why we get 10???
    new = ft_calloc(total_len + 1, sizeof(char)); //sizeof(char) not fixing it
    if (!new)
        return (NULL);
	//ft_strlcpy(&new[i], s1, ft_strlen(s1));
    while (s1[i]) //s1[i] != '\0')//s1[i] != '\0')
    {
		printf("join loop i %d\n", i);
        new[i] = s1[i];
        i++;
		printf("end\n");
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

 //my calloc has been checked in test.call

char *get_line(char *buffer, int x)
{
	//static char *cache;
	char *lineb;
	char *line;

	printf("START\n");

	
	if (buffer)//((find_it('\n', buffer, BUFFER_SIZE)) == 0)
	{
		printf("buffer found\n");
//		if (x == 1)
//		{
//			printf("line empty\n");
//			line = malloc(1 * BUFFER_SIZE + 1);// do i need plus 1 here??? //len + 1); //BUFFER_SIZE + 1);
//			printf("plo\n");
//			if (!line)
//				return (NULL);
//			printf("plo\n");
//			strlcpy(line, buffer, BUFFER_SIZE + 1); //buffer size might not be the right answer
//			printf("first line fill = %s\n", line);
//			return (line);
//		}
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
	static char *cache;
	char buffer[BUFFER_SIZE + 1];
	int read_len;
	char *final_line;
	char *line2;
	int x;
	int i;
	int r;

	r = 0;
	i = 0;
	x = 0;
	//line2 = malloc(1 * 1);
	//while (read_len != -1)
	line2 = NULL;
	cache = NULL;
	//if (!line2)
	//line2  = ft_calloc(1, 1);
	while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0) //did send to buffer of size
	{
		buffer[BUFFER_SIZE] = '\0';
		//if ((find_it('\n', buffer, BUFFER_SIZE)) > 0)
			//final_line = get_line(buffer, x); //ft_strjoin((line2, get_line(buffer, x))?
		//this will be last, need strjoin here .
		//also check read-len?

		if (cache == NULL)
		{
			printf("cache empty\n");
			printf("read len = %d\n", read_len);
			//cache = ft_calloc(ft_strlen(buffer) + 1, sizeof(char)); //sttrdup?
			/*while (ft_strlen(buffer) != r)
			{
				printf("in while\n");
				cache[r] = buffer[r];
				printf("r = %d\n", r);
				r++;
			}
			*cache++ = '\0';*/
			printf("cache = %s\n", cache);
			cache = strdup(buffer);
			//ft_strlcpy(cache, buffer, read_len + 1); //this will cover if file is tiny and buffer is big
			printf("cache = %s\n", cache);
		}
		else //if ((find_it('\n', buffer, BUFFER_SIZE)) == 0) //was buffer
		{
			// x = number of rounds , round 1 is first round.
			printf("x = %d\n", x);
			x++;
			printf("cache before join = %s", cache);
			//free(line2);
			line2 = ft_strjoin(cache, buffer);//get_line(buffer, x);
			printf("cache = %s\n", cache);
			free(cache);
			cache = line2;
			
			
			printf("line2 = %s\n", line2);

		}
		if ((i = find_it('\n', cache, ft_strlen(cache))) > 0)
		{
			final_line = ft_calloc(i + 1, sizeof(char));
			strlcpy(final_line, cache, i);
			
		}
	}
	return (final_line);
}

int main()
{
    int fd;
    char *test;

    fd = open("testies.txt", O_RDONLY);
    if ((test = get_next_line(fd)) != 0) //(read(fd, santi.buff, BUFFER_SIZE)
    {
        printf("%s\n", test); //get_next_line(fd));
        //if (-1)
        //break;
	}
    free(test);
    close(fd);
}
