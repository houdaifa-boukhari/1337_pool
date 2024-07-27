#include<unistd.h>

void putnbr(int nb)
{
	char digite;
	if(nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
	{
		digite = nb + 48;
		write(1,&digite,1);
	}

}

int main()
{
	int i = 1;
	//char digite;

	while(i <=100)
	{
		if(i % 5 == 0 && i % 3 == 0)
		write(1,"fizzbuzz",8);
		else if(i % 5 == 0)
		{
			write(1,"buzz",4);
		}
		else if(i % 3 == 0)
		{
			write(1,"fizzz",4);
		}
		else{
			putnbr(i);
		}
		write(1,"\n",1);
		i++;
	}
}
