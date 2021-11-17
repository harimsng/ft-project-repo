#include <stdio.h>

enum e_initial_entries
{
	zero,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	eleven,
	twelve,
	thirteen,
	fourteen,
	fifteen,
	sixteen,
	seventeen,
	eighteen,
	nineteen,
	twenty,
	thirty = 30,
	forty = 40,
	fifty = 50,
	sixty = 60,
	seventy = 70,
	eighty = 80,
	ninety = 90,
	hundred = 100,
	thousand = 1000,
	million = 1000000,
	billion = 1000000000
};

int	main(void)
{
	int						idx;
	enum e_initial_entries	e_entry;

	idx = 0;
	while (idx < 32)
	{
		printf("%d\n", e_entry++);
		++idx;
	}
	return (0);
}
