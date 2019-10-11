#include <stdio.h>
#include "includes/push_swap.h"
#include "includes/service.h"

#include <time.h>

int		*array_generator(int *len);
int 	min(int *arr, int len1);

int main()
{
	int len1, len2;


	int *ar = array_generator(&len1);
	t_frame *fr = s_create_frame(ar, len1, min(ar, len1));
	free(ar);
	printf("\n----Show a\n");
	s_show_list(fr->a);
	printf("----\n");
	printf("\n----Show b\n");

	s_rep_pb(&(fr->a),&(fr->b), 3);
	printf("\n--Test update--\n");
	s_update_fr(fr);
	printf("\n----Show a\n");
	s_show_list(fr->a);
	printf("----\n");
	printf("\n----Show b\n");
	s_show_list(fr->b);
	printf("----\n");

	s_del_frame(fr);
    return 0;
}

int 	min(int *arr, int len1)
{
	int i = 0;
	int min = arr[0];
	while(++i < len1)
		if (arr[i] < min)
			min = arr[i];
	return (min);
}
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