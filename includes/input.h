#ifndef PUSH_SWAP_INPUT_H
#define PUSH_SWAP_INPUT_H

#include "service.h"

long	l_atoi(const char *nptr);
int		ch_digit_cheker(char **my_av, int i);
int		find_double(int *arr, int ac);
void	free_and_exit(void *arr, t_dlst *a, t_dlst *b, int flag);

int	*ch_parser(int ac, char **av, int i, int *len);
int	*one_ac_stack(char **av, int *len);
int	*checker_collector(int ac, char **av, int *len);

#endif //PUSH_SWAP_INPUT_H
