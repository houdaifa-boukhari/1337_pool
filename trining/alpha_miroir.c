#include <unistd.h>
int alpha(char c)
{
	int i;
	
	if(c >= 'a' && c <= 'z')
	{
		i = c - 'a';
		return i;
	}
	else if(c >= 'A' && c <= 'Z')
	{
		i = c - 'A';
		return i;
	}
	else
		return 1;
}
int main(int argc , char **argv)
{
	if(argc == 2)
	{
		int i = 0;
		while(argv[1][i])
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z'){
			argv[1][i] = 'z' - alpha(argv[1][i]); 
			write(1,&argv[1][i],1);
			}
			else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				argv[1][i] = 'Z' - alpha(argv[1][i]);
				write(1,&argv[1][i],1);
			}
			else
				write(1,&argv[1][i],1);
			i++;
		}	
	}
	write(1,"\n",1);
}
