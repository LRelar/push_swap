#include "../includes/push_swap.h"
#include "../includes/service.h"
#include "../includes/input.h"
#include "../includes/visual.h"

int main(int argc, char *argv[])
{
	int *arr;
	int len;

	if (argc == 1)
		return (0);
	arr = checker_collector(argc, argv, &len);
	if (len == 1 || s_check(arr, len))
		return (0);
	t_frame *fr = s_create_frame(arr,len,s_min(arr,len), s_max(arr, len));
	printf("%c[?25l", 27);
	visualizer(fr);
	free(arr);
	if (len == 2)
		sort_2(fr);
	if (len == 3)
		sort_3(fr);
	if (len == 4)
		sort_4(fr);
	if (len == 5)
		sort_5(fr);
	if (len > 5)
		sort_large(fr);
	visualizer(fr);
	printf("%c[?25h", 27);
	s_del_frame(fr);
	return 0;
}