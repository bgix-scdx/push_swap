#include <unistd.h>

// int main(void)
// {
//     write(1, "\033[?1049h\033[2J\033[H", 15);

//     write(1, "HELLO ALT SCREEN", 16);
//     //sleep(1);

//     write(1, "\033[?1049l", 8);
// }

int main(void)
{
	write(1, "\033[H\033[J", 6);
	write (1, "test\n", 5);
}