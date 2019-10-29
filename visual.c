#include "./includes/visual.h"

//TODO на основе этого сделать полноценный модуль визуализации
int			visualizer(t_frame *fr)
{
	t_dlst *temp1;
	t_dlst *temp2;

	if (fr->a == NULL && fr->b == NULL)
		return  (0);
	sleep(1);
	printf("%c[2J%c[H", 27, 27);
	printf("________________________\nStack A:\tStack B:\n________________________\n");
	if (fr->b == NULL)
	{
		if (fr->a != NULL)
		{
			printf("%d\n", fr->a->data);
			temp1 = fr->a->next;
			while (temp1 != fr->a)
			{
				printf("%c[41m%d%c[0m\n",27, temp1->data, 27);
				temp1 = temp1->next;
			}
		}
	}
	if (fr->a == NULL)
	{
		if (fr->b != NULL)
		{
			printf("%22d\n", fr->b->data);
			temp1 = fr->b->next;
			while (temp1 != fr->b)
			{
				printf("%22d\n", temp1->data);
				temp1 = temp1->next;
			}
		}
	}
	if (fr->a != NULL && fr->b != NULL)
	{
		printf("%-11d%11d\n", fr->a->data, fr->b->data);
		temp1 = fr->a->next;
		temp2 = fr->b->next;
		while (temp1 != fr->a || temp2 != fr->b )
		{
			if (temp1 != fr->a && temp2 != fr->b)
			{
				printf("%-11d%11d\n", temp1->data, temp2->data);
				temp1 = temp1->next;
				temp2 = temp2->next;
				continue;
			}
			if (temp1 == fr->a && temp2 != fr->b)
			{
				printf("%22d\n",temp2->data);
				temp2 = temp2->next;;
				continue;
			}
			if (temp1 != fr->a && temp2 == fr->b)
			{
				printf("%-11d\n", temp1->data);
				temp1 = temp1->next;
				continue;
			}
		}
	}
	return (printf("________________________\n"));
}