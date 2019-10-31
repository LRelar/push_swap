#ifndef CHEKER_H
#define CHEKER_H

#include "input.h"

void	exec_command(char *buf, t_dlst **stack_a, t_dlst **stack_b);
void	grab_stdout(t_dlst **stack_a, t_dlst **stack_b, int *i);
int		*ch_parser(int ac, char **av, int i);
int		finish_check(t_dlst *stack_a, t_dlst *stack_b);
t_dlst	*ch_one_ac_stack(char **av);
int		ch_checker_collector(int ac, char **av);
int		main(int ac, char **av);

#endif
