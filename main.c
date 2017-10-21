#include "libft.h"
#include <stdio.h>
#define BUF_SIZE 1000

int	ft_validtets(char *buf)
{
	int x;
	int y;
	int v;

	x = 0;
	y = 1;
	v = 0;
	while(buf[x] != '\0')
	{
		if(buf[x] == '\n')
		{
			if ((v % 5 == 4) && (buf[x] != '\n'))
			   return (0);
			if ((((v % 5) != 4) && (v % 20) != 0))
				return (0);
			if((v % 5) == 4)
			{
				x++;
				v++;
			}
			if (((v % 20) == 0))
			{
				x++;
				y++;
				v = 0;
			}
		}
		x++;
		v++;
	}
	return (y - 1);
}

char	**ft_tetsplit(char *buf, int tetcount)
{
	int		x;
	int		y;
	int		i;
	char	**ret;

	x = 0;
	y = 0;
	i = -1;
	ret = (char**)malloc(sizeof(char*) * (tetcount + 1));
	while (y < tetcount)
		ret[y++] = (char*)malloc(sizeof(char) * 21);
	y = 0;
	tetcount = 20;
	while(buf[++i] != '\0')
	{
		if (i != tetcount)
			ret[y][x++] = buf[i];
		if (i == tetcount)
		{
			ret[y++][x] = '\0';
			x = 0;
			tetcount = tetcount + 21;
		}
	}
	return (ret);
}


int main (int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char *str;
	int tets;
	char **tetstrings;
	int		**tetconf;

	str = NULL;
	if (argc == 2)
		str = argv[1]; //this takes a file name or path from stdini
	fd = open(str, O_RDONLY); //reads the file and returns the size
	if (fd == -1)
	{
		ft_putstr("error");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); //read returns the size of buf;
	tets = ft_validtets(buf);
	if (tets == 0)
		ft_putstr("error");
	tetstrings = ft_tetsplit(buf, tets);
	tetconf = determinefigures(tetstrings, tets);
	findbesttetris(tetconf, tets);
	if(fd == - 1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
