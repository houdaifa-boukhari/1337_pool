#include <string.h>

int ft_atoi(const char *str)
{
    int i =0;
    int signe = 0;
    int resulte = 0;
    int positif = 0;
    while(str[i] == 32)
    {
        i++;
    }
     while(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '+')
            positif++;
        if(str[i] == '-')
            signe++;
        i++;
    }
    if(signe > 1 || positif > 1 || positif + signe > 1)
        return 0;
    while(str[i] <= '9' && str[i] >= '0')
    {
        resulte = resulte*10 + (str[i] - '0');
        i++;
    }
    if(signe == 1)
        return (-1*resulte);
    
    return resulte;
}
int main (void)
{
    char *str = "  -45645865";
    printf("%d\n",ft_atoi(str));
    printf("%d",atoi(str));
}
