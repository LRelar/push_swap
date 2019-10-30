#include "./includes/visual.h"

void	both_exist(t_frame *fr, t_dlst **temp1, t_dlst **temp2)
{
	while(1)
	{
		if (*temp1 == fr->fst)
			printf("%c[44;1m%-14d%c[0m",27, (*temp1)->data, 27);
		else if (*temp1 == fr->sec)
			printf("%c[7m%-14d%c[0m",27, (*temp1)->data, 27);
		if (*temp1 != fr->fst && *temp1 != fr->sec)
			printf("%-14d", (*temp1)->data);
		if (*temp2 == fr->fst)
			printf("%c[44;1m%14d%c[0m\n",27, (*temp2)->data, 27);
		else if (*temp2 == fr->sec)
			printf("%c[7m%14d%c[0m\n",27, (*temp2)->data, 27);
		if (*temp2 != fr->fst && *temp2 != fr->sec)
			printf("%14d\n", (*temp2)->data);
		*temp1 = (*temp1)->next;
		*temp2 = (*temp2)->next;
		if(!(*temp1 = (*temp1 == fr->a) ? NULL : *temp1) ||
			!(*temp2 = (*temp2 == fr->b) ? NULL : *temp2))
			break;
	}
}

void 	a_exist(t_frame *fr, t_dlst **temp1)
{
	while(1)
	{
		if (*temp1 == fr->fst)
			printf("%c[44;1m%-14d%c[0m\n",27, (*temp1)->data, 27);
		else if (*temp1 == fr->sec)
			printf("%c[7m%-14d%c[0m\n",27, (*temp1)->data, 27);
		if (*temp1 != fr->fst && *temp1 != fr->sec)
			printf("%-14d\n", (*temp1)->data);
		*temp1 = (*temp1)->next;
		if (*temp1 == fr->a)
			break;
	}
}

void 	b_exist(t_frame *fr, t_dlst **temp2)
{
	while(1)
	{

		if (*temp2 == fr->fst)
			printf("%c[44;1m%28d%c[0m\n",27, (*temp2)->data, 27);
		else if (*temp2 == fr->sec)
			printf("%c[7m%28d%c[0m\n",27, (*temp2)->data, 27);
		if (*temp2 != fr->fst && *temp2 != fr->sec)
			printf("%28d\n", (*temp2)->data);
		*temp2 = (*temp2)->next;
		if (*temp2 == fr->b)
			break;
	}
}

void	visualizer(t_frame *fr)
{
	t_dlst *temp1;
	t_dlst *temp2;

	temp1 = fr->a;
	temp2 = fr->b;
	printf("%c[2J%c[H", 27, 27);
	printf("____________________________\nStack A");
	if (fr->b)
		printf(" [%-3d - %3d] ", fr->i , fr->i - 1);
	else
		printf("\t\t    ");
	printf("Stack B\n____________________________\n");
	if (fr->a && fr->b)
		both_exist(fr, &temp1, &temp2);
	if (temp1)
		a_exist(fr, &temp1);
	if (temp2)
		b_exist(fr, &temp2);
	printf("____________________________\n");
	if (!fr->fst && !fr->sec && fr->b)
		printf("Moving to the next range\n");
	sleep(1);
}

