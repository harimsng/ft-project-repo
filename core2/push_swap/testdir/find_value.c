#include <stdio.h>

#define KEY1 (g_inst_string[i][0] + 26 * g_inst_string[i][1])
#define KEY2 (g_inst_string[i][0] + 26 * g_inst_string[i][1] + 26 * 26 * g_inst_string[i][2])

static const char		*g_inst_string[11] =
{
	"pa\n",
	"pb\n",
	"sa\n",
	"sb\n",
	"ss\n",
	"ra\n",
	"rb\n",
	"rr\n",
	"rra\n",
	"rrb\n",
	"rrr\n"
};

int	main(void)
{
	for (int i = 0; i < 11; ++i)
	{
		if (g_inst_string[i][2] == '\n')
			printf("%s : %d\n", g_inst_string[i], KEY1 % 31);
		else
			printf("%s : %d\n", g_inst_string[i], KEY2 % 31);
	}
	return (0);
}
