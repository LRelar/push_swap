#include <stdio.h>
#include "includes/push_swap.h"
#include "includes/service.h"
#include "includes/dc_lists.h"

#include <time.h>

int		*array_generator(int *len)
{
	int		arr_len;
	int		*array;
	int	i;
	int	top;
	int	tail;

	i = -1;
	tail = -10;
	top = 100;
	printf("Количество элементов в массиве:\n");
	scanf("%d", &arr_len);
	*len = arr_len;
	if ((arr_len > 0 && arr_len < INT_MAX) && \
				(tail > INT_MIN && tail < INT_MAX) && \
				(top > INT_MIN && top < INT_MAX) && (top > tail))
	{
		array = (int *)malloc(sizeof(int) * arr_len);
		arr_len++;
		srand(time(0));
		while (arr_len--)
			array[++i] = rand() % (top - tail + 1) + tail;

		while (i--)
			printf(" %d |", array[i]);

		return (array);
	}
	else
		printf("Чет ты шляпу написал, попробуй еще раз :C\n");
	exit(0);
}

int main()
{
	int len1, len2;

	int *arr = array_generator(&len1);
	int *arr2 = array_generator(&len2) ;
	t_dlst *test1 = cr_lists(arr,len1 -1);
	t_dlst *test2 = cr_lists(arr2, len2 - 1);
	printf("\n***\n");
	show_list(test1);
	printf("***\n");
	show_list(test2);

	printf("---sa\n");
	s_rep_sa(&test1 , 2);
	show_list(test1);

	printf("---sb\n");
	s_rep_sb(&test2,2);
	show_list(test2);

	printf("---ss\n");
	s_rep_ss(&test1, &test2, 2);
	show_list(test1);
	printf("***\n");
	show_list(test2);

	printf("---ra\n");
	s_rep_ra(&test1,2);
	show_list(test1);

	printf("---rb\n");
	s_rep_rb(&test2,2);
	show_list(test2);

	printf("---rr\n");
	s_rep_rr(&test1, &test2, 2);
	show_list(test1);
	printf("***\n");
	show_list(test2);

	printf("---rra\n");
	s_rep_rra(&test1,2);
	show_list(test1);

	printf("---rrb\n");
	s_rep_rrb(&test2,2);
	show_list(test2);

	printf("---rrr\n");
	s_rep_rrr(&test1, &test2, 2);
	show_list(test1);
	printf("***\n");
	show_list(test2);

	printf("---pa\n");
	s_rep_pa(&test1, &test2, 2);
	show_list(test1);
	printf("***\n");
	show_list(test2);

	printf("---pb\n");
	s_rep_pb(&test1, &test2, 2);
	show_list(test1);
	printf("***\n");
	show_list(test2);
	printf("\n");
    return 0;
}