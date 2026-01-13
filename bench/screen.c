#include "../header/push_swap.h"

void	screen_fill(t_screen *screen, char c)
{
	int j;
	int i;

	i = 0;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
			screen->mat[i][j++] = c;
		screen->mat[i][j] = '\n';
		i++;
	}
}

t_screen	*screen_init(t_screen *screen, int w, int h, char bg)
{
	screen = malloc(sizeof(screen));
	screen->width = w;
	screen->height = h;
	screen->background = bg;
	screen->mat = malloc(screen->height * sizeof(char *));
	for (int i = 0; i < screen->height; i++)
		screen->mat[i] = malloc(screen->width + 1);
	screen_fill(screen, screen->background);
	contour(screen, 100, 20);
	return (screen);
}

void	screen_display(t_screen *screen)
{
	int i;

	write(1, "\033[?1049h\033[2J\033[H", 15);
	write(1, "\033[2J", 4);

	i = 0;
	while (i < screen->height)
	{
		write(1, screen->mat[i++], screen->width + 1);
	}
}

void	put_pos(t_screen *screen, int x, int y, char c)
{
        if (x >= screen->width || y > screen->height)
                printf("coordonees %d,%d trop grandes\n", x, y);
        else
                screen->mat[y][x] = c;
}

void	putstr_screen(t_screen *screen, int x, int y, char *str)
{
        int i = 0;

        while (*str)
            put_pos(screen, x + i++, y, *str++);
}

