#include <stdio.h>
#include "includes/push_swap.h"
#include "includes/service.h"

#include <time.h>

int		*array_generator(int *len);
void	rotate(int a[20][5]);
int		check(t_dlst *a);
int check2(t_dlst *a, t_dlst *val);
int main()
{
	int len =6;
	int *ar = array_generator(&len);
	//int ar[]={0,-242,-388,-32,-292,-397};
	t_frame *fr = s_create_frame(ar,len,s_min(ar,len), s_max(ar, len));
	//printf("\nМассив:\n");
	//s_show_list_g(fr->a);
	//printf("\n");
	sort_large(fr);
	//printf("\nМассив:\n");
	//s_show_list_g(fr->a);
	//printf("\n");
	return 0;
}
int check2(t_dlst *a, t_dlst *val)
{
	t_dlst *t = a;
	if (t == val)
		return (0);
	t=t->next;
	while (t!= a)
	{
		if (t == val)
			return (0);
		t = t->next;
	}
	return (1);
}
int check(t_dlst *a)
{
    t_dlst *t = a;
    while (t->next != a)
    {
        if (t->next->data > t->data)
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
	int		arr_len = 10;
	int		*array;
	int	i;
	int	top;
	int	tail;

	i = 0;
	tail = -500;
	top = 500;
	//printf("Количество элементов в массиве:\n");
	//scanf("%d", &arr_len);
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