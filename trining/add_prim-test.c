#include <unistd.h>
void short_putnbr(int nb)
{
    char digit;
    if(nb > 9)
    {
        short_putnbr(nb / 10);
        short_putnbr(nb % 10);
    }
    else
    {
        digit = nb + 48;
        write(1,&digit,1);
    }
}
int prime(int nb)
{
    int i;
    i = 2;
    if(nb < 2)
        return 0;
    else
    {
        while(i < nb)
        {
            if (nb % i == 0)
                return 0;
            i++;
        }
        return 1;
    }
}
int short_atoi(char *str)
{
    int i = 0;
    int resulte = 0;
    while(str[i] >= 48 && str[i] <= 57)
    {
        resulte = resulte*10 + (str[i] - 48);
        i++;
    }
    return resulte;
}
int add_prime(int nb)
{
    int i = 2;
    int sum = 0;
    
    if(nb <= 0)
        return 0;
    while(nb >= i)
    {
        if(prime(i))
            sum += i;
        i++;
    }
    return sum;
}
int main(int argc , char **argv)
{
	if(argc == 2)
    	short_putnbr(add_prime(short_atoi(argv[1])));
	else
		write(1,"0",1);
	write(1,"\n",1);
}
