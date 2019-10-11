#include <stdio.h>
#include "includes/push_swap.h"
#include "includes/service.h"

#include <time.h>

int		*array_generator(int *len);

int main()
{
	int len1;

	int *ar = array_generator(&len1);

	t_frame *fr = s_create_frame(ar, len1, s_min(ar, len1),s_max(ar,len1));
	free(ar);
	printf("\n----Show a\n");
	s_show_list(fr->a);
	printf("----\n");
	printf("\n----Show b\n");
	s_show_list(fr->b);
	printf("----\n");

	s_split_chunks(fr);
	printf("\n MIN %d\tMAX%d\n", fr->MIN, fr->MAX);
	for (int i = 0; i< 22; i++)
	{
		printf("%d\t", fr->stages[i]);
	}


	s_del_frame(fr);
    return 0;
}


int		*array_generator(int *len)
{
	int		arr_len;
	int		*array;
	int	i;
	int	top;
	int	tail;

	i = -1;
	tail = -500;
	top = 500;
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

		//while (i--)
		//	printf(" %d |", array[i]);

		return (array);
	}
	else
		printf("Чет ты шляпу написал, попробуй еще раз :C\n");
	exit(0);
}