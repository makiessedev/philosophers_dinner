int ft_strlen(char *s)
{
    int i;

    i = -1;
    while (s[++i])
        ;
    return (i);
}