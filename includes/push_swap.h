/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:58:24 by ivanderw          #+#    #+#             */
/*   Updated: 2023/05/30 19:11:57 by ivanderw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cur_target_index;
	int				cost;
	char			format;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	ft_putchar(char c);
long	ft_atoi(const char *str);
int		ft_strlen(const char *s);
char	*ft_strdup(char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_printbr(void);
void	ft_error(void);
int		ft_is_digit(char c);
int		ft_is_numeric(char *str);
int		ft_duplicate_check(int tmp, char **argv, int i);
void	ft_check_inputs(char **argv);

int		ft_printf_printchar_length(char n);
int		ft_printf_printstr_length(char *str);
int		ft_printf_printdecimal_length(int n);
int		ft_printf_printunsigned_length(unsigned int n);
int		hex_length(unsigned int n);
void	print_hex(unsigned int n, const char mychar);
int		ft_printf_printhex_length(unsigned int n, const char mychar);
int		ft_address_length(unsigned long n);
void	ft_printaddress(unsigned long n);
int		ft_printf_printadd_length(unsigned long long my_ptr);
int		get_output_length(va_list args, const char mychar);
int		ft_printf(const char *inputstr, ...);

void	ft_lstadd_back(t_list **lst, t_list *_new);
void	ft_lstadd_front(t_list **lst, t_list *_new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstnew_plus_index(int content, int index);
int		ft_lstsize(t_list *lst);
void	ft_lstremove_front(t_list **lst);
void	ft_lstremove_back(t_list **lst);
int		ft_is_duplicatecheck(t_list **stack_a);
int		ft_is_sorted(t_list *stack_a);
int		ft_get_mindex(t_list **stack_a);
int		ft_get_maxdex(t_list **stack_a);
int		ft_get_middex(t_list **stack_x);
int		ft_sa(t_list *stack_a);
int		ft_sa_no_print(t_list *stack_a);
int		ft_sb(t_list *stack_b);
int		ft_sb_no_print(t_list *stack_b);
int		ft_ss(t_list *stack_a, t_list *stack_b);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pa_no_print(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_pb_no_print(t_list **stack_a, t_list **stack_b);
int		ft_ra(t_list **stack_a);
int		ft_ra_no_print(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rb_no_print(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rra(t_list **stack_a);
int		ft_rra_no_print(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrb_no_print(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);
void	printer1(t_list *current_node);
void	ft_print_status(t_list *stack_a, t_list *stack_b, char *title);
void	ft_r_stack_a(t_list **stack_a, int rotations, int *steps);
void	ft_r_stack_b(t_list **stack_b, int rotations, int *steps);
void	ft_rr_stacks(t_list **stack_a, t_list **stack_b, int rot, int *st);
void	ft_rr_stack_a(t_list **stack_a, int rotations, int *steps);
void	ft_rr_stack_b(t_list **stack_b, int rotations, int *steps);
void	ft_rrr_stacks(t_list **stack_a, t_list **stack_b, int rot, int *st);
t_list	*ft_get_cheapest_node(t_list **stack_b);
void	ft_cheapest_move(t_list **stack_a, t_list **stack_b, int *steps);
void	ft_short_sort(t_list **stack_a, int *steps);
void	sel_sort(t_list **stack_a, t_list **stack_b, int *steps);
void	cost_sort(t_list **stack_a, t_list **stack_b, int *steps);
void	ft_refresh_current_targets(t_list **stack_a, t_list **stack_b);
void	ft_refresh_current_costs(t_list **stack_a, t_list **stack_b);
int		ft_get_steps_to_top(t_list **stack_x, int m_index);
void	ft_set_standard_costs(t_list **stack_a, t_list **stack_b, t_list *s_b);

#endif
