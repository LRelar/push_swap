#include <stdio.h>
#include "includes/push_swap.h"
#include "includes/service.h"
#include "includes/input.h"

#include <time.h>

void	rotate(int a[20][5]);
int		check(t_dlst *a);
int		check2(t_dlst *a);
int        *array_generator(int len)
{
	int        arr_len = len;
	int        *array;
	int    i;
//	int    top;
	//int    tail;

	i = 0;
	//printf("\nКоличество элементов в массиве:\n");
	// scanf("%d", &arr_len);
	//len = &arr_len;
	// printf("Нижняя граница:\n");
	// scanf("%zd", &tail);
	// printf("Верхняя граница:\n");
	// scanf("%zd", &top);
	//tail = INT_MIN +1;
	//top = INT_MAX - 100;
	/*if ((arr_len > 0 && arr_len < INT_MAX) && \
        (tail > INT_MIN && tail < INT_MAX) && \
        (top > INT_MIN && top < INT_MAX) && (top > tail))
	{*/
		array = (int *)malloc(sizeof(int) * arr_len);
		srand(time(0));
		while (arr_len--)
			array[i++] = rand() % 32767 - (32767 /2);
		//while (i--)
		//	printf("%d ", array[i]);
		return (array);
	//}
	//else
		printf("Чет ты шляпу написал, попробуй еще раз :C\n");
	exit(0);
}
int total = 0;

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
//	s_show_both_list(fr->a, fr->b);
	//printf("\n");
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
	//s_show_both_list(fr->a, fr->b);
	printf("\n%d", check2(fr->a));
	s_del_frame(fr);
	return 0;
}
int check2(t_dlst *a)
{
	t_dlst *t = a;

	while (t->next != a)
	{
		if (t->data > t->next->data)
			return (0);
		t = t->next;
	}
	return (1);
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
