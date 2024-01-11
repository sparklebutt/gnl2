#include <stdio.h>
#include <stdlib.h>

//this code works , first is simple test
//also now works with harder test , strlcpy and strjoin. no read. 
void    *ft_calloc(int count, int size)
{
    void    *storage_ptr;
    int i;

    i = 0;
    storage_ptr = malloc(count * size);
    if (storage_ptr == NULL)
        return (NULL);
    while (--size > 0)
    {
        storage_ptr = 0;
        storage_ptr++;
    }
    return (storage_ptr);
}

 int  ft_strlen(char *s)
{
    int counter;
    printf("STRLEN\n");
    counter = 0;
    while (*s != '\0')
    {
        counter++;
        s++;
    }
    return (counter);
}


/*char *test(char *str)
{
	char *str_test;
	int x;
	int i;

	i = 0;
	str_test = NULL;
	x = ft_strlen(str);
	printf("str inside test = %s\n", str);
	printf("x inside test  = %x\n", x);
	printf("i in test = %d", i);
	str_test = ft_calloc(x + 1, sizeof(char));
	printf("haloo\n");
	while (i <= x)
	{
		printf("i in loop = %d\n", i);
		str_test[i] = str[i];
		i++;
	}
	printf("i = %d", i);
	return (str_test);
	}*/
 /***/
int  ft_strlcpy(char *dst, char *src, int dstsize)//src const
{
    int  i;
    int  len;

    len = ft_strlen(src); //buffer doesnt have 0
    i = 0;
    if (dstsize == 0)
        return (len);
    while (*src != '\0' && i < (dstsize))
    {
//        i++;
        *dst++ = *src++;
		i++;
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
    new = ft_calloc(total_len + 1, sizeof(char)); //malloc(1 * total_len + 1); //sizeof(char) not fixing it
    if (!new)
        return (NULL);
	printf("not null\n");
    while (s1[i]) // && s1[i] != '\0')
    {
		printf("i in loop = %d\n", i);

		printf("in while loop \n");
        printf("s1 i = %c\n", s1[i]);
		new[i] = s1[i];
        i++;
    }
//	printf("new now = %s\n", new);
    ft_strlcpy(&new[i], s2, ft_strlen(s2));
	//  printf("new = %s\n", new);
    return (new);
}
/***/
int main()
{
	char *str;
	char *str2;
	char *str3;
	char *store;
	static char *empty;
	int x;
//	int r = 0;

	store = NULL;
	str = "test";
	str2 = "me";
	str3 = "weee";
	printf("str = %s\n", str);
	x = 0;
	x = ft_strlen(str);
	printf("x = %d\n", x);
	printf("empty = %s\n", empty);
//**	empty = test(str);
//	empty = ft_strjoin(str, str2);
	//while (r == 3)
	//{
		store = ft_strjoin(str, str2);
		empty = store;
		store = ft_strjoin(empty, str3);
		empty = store;
	//r++;
		
		//}
	printf("len of empty %d", ft_strlen(empty));
	printf("empty = %s x = %d\n", empty, x);
	

	free(empty);
	return (0);
}
