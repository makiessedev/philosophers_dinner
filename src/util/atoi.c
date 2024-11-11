int ft_atoi(char *s)
{
    int  signal;
    int num;

    num = 0;
    signal = 1;
    while (*s == ' ' || *s == '\t')
        s++;
    if (*s == '+' && *s++)
        ;
    else if (*s == '-' && s++)
        signal = -1;
    while (*s >= '0' && *s <= '9')
    {
        num = (num * 10) + (*s - '0');
        s++;
    }
    return (num * signal);
}