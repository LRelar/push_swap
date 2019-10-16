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
    int len1 = 10;
    int score = 0;
    //int *ar = array_generator(&len1);
    int b[]={-100, -200, -300, -400, -500, -600};
    int a[21][10] = {
            {1,2,3,4,5,6,7,8,9,10},
            {1,2,3,4,5,6,7-150,9,10},
            {1,2,3,4,5,6,7-250,9,10},
            {1,2,3,4,5,6,7-350,9,10},
            {1,2,3,4,5,6,7-450,9,10},
            {1,2,3,4,5,6,7-550,9,10},
            {1,2,3,4,5,6,7-650,9,10},
            {1,2,3,4,5,6,7,8,9,10},
            {1,2,3,4,-150,6,7,8,9,10},
            {1,2,3,4,-250,6,7,8,9,10},
            {1,2,3,4,-350,6,7,8,9,10},
            {1,2,3,4,-450,6,7,8,9,10},
            {1,2,3,4,-550,6,7,8,9,10},
            {1,2,3,4,-650,6,7,8,9,10},
            {1,2,3,4,5,6,7,8,9,10},
            {1,2,3,-150,5,6,7,8,9,10},
            {1,2,3,-250,5,6,7,8,9,10},
            {1,2,3,-350,5,6,7,8,9,10},
            {1,2,3,-450,5,6,7,8,9,10},
            {1,2,3,-550,5,6,7,8,9,10},
            {1,2,3,-650,5,6,7,8,9,10},
    };
    t_frame *fr;
    for(int i = 0; i < 21; i++)
    {
        fr = s_create_frame(a[i],len1, s_min(a[i], len1),s_max(a[i],len1));
        fr->b = s_create_lists(b, 6);
		printf("\nCтэки:");
		printf("\nA: ");
		s_show_list_g(fr->a);
		printf("\nB: ");
		s_show_list_g(fr->b);
        s_update_fr(fr);
        if (i <7)
        {
            fr->sec = fr->a->prev->prev->prev;
            fr->depth2 = 2;
        }
        else
        {
            if (i<14)
            {
                fr->sec = fr->a->next->next->next->next;
                fr->depth2 = 5;
            }
            else
            {
				fr->sec = fr->a->next->next->next;
				fr->depth2 = 6;
            }
        }
        calc_com2(fr);
		printf("\nКарта:\n");
		for(int i =0; i<3; i++)
		{
			for(int j=0; j<2;j++)
				printf("%d ", fr->com2[i][j]);
			printf("\n");
		}
		printf("Скрол: %d\n", fr->scroll2);
		printf("\nВыполнение команд:");
		printf("\nA: ");
		s_show_list_g(fr->a);
		printf("\nB: ");
		s_show_list_g(fr->b);
		printf("\n----------\n");
		do_com(&(fr->a), &(fr->b),fr->scroll2, fr->com2);
		printf("\nCтэки:");
		printf("\nA: ");
		s_show_list_g(fr->a);
		printf("\nB: ");
		s_show_list_g(fr->b);
		if (check(fr->b) == 0)
			printf("\n**********************************************************************[KO] B i = %d", i);
		else
		{
			if (check2(fr->a,fr->sec) == 0)
				printf("\n**********************************************************************[KO] A i = %d", i);
			else
				{
					printf("\n**************************************[OK] i = %d", i);
					score++;
				}
	}
		s_del_frame(fr);
	}
	printf("\nИтого: %d/21\n", score);
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
	int		arr_len = 100;
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