#include <stdio.h>
#include "includes/push_swap.h"
#include "includes/service.h"

#include <time.h>

int		*array_generator(int *len);
void	rotate(int a[20][5]);
int		check(t_dlst *a);

int main()
{
	int len;
	int *a = array_generator(&len);
	t_frame *fr = s_create_frame(a,len, s_min(a, len), s_max(a,len));
	printf("Stack A:\n");
	s_show_list_g(fr->a);
	printf("\n");
	sort_large(fr);
	printf("Stack A:\n");
	s_show_list_g(fr->a);
	printf("\n");
	s_del_frame(fr);
    return 0;
}

int check(t_dlst *a)
{
    t_dlst *t = a;
    while (t->next != a)
    {
        if (t->next->data < t->data)
            return (0);
        t = t->next;
    }
    return  (1);
}
void rotate(int a[20][5])
{
    int t;

    for(int i = 0; i< 20; i++)
    {
        t = a[i][0];
        a[i][0] = a[i][1];
        a[i][1] = t;
    }
}
int		*array_generator(int *len)
{
	int		arr_len;
	int		*array;
	int	i;
	int	top;
	int	tail;

	i = 0;
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