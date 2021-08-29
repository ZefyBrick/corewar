/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:27:06 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/10 14:11:51 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			compare_val(t_cw *corewar, t_parse *parser, char *line, int *i)
{
	t_ls	*tmp;

	tmp = add_node(corewar);
	if (!ft_strcmp(".comment", line))
	{
		parser->comment++;
		tmp->label = COMMAND_COMMENT;
		ft_strcpy(tmp->token, line);
		command_val(corewar, tmp, parser, i);
	}
	else if (!ft_strcmp(".name", line))
	{
		parser->name++;
		tmp->label = COMMAND_NAME;
		ft_strcpy(tmp->token, line);
		command_val(corewar, tmp, parser, i);
	}
	else
		errors_out(corewar, LEXICAL);
}

void			command_val(t_cw *corewar, t_ls *tmp, t_parse *parser, int *i)
{
	t_ls		*val;
	char		*str;

	val = add_node(corewar);
	str = ft_strnew(1);
	while (corewar->line[(*i)])
	{
		if (corewar->line[(*i)] == '\n' && parser->quotes == 0)
			errors_out(corewar, END_LINE_ERROR);
		if (corewar->line[(*i)] == '"' && parser->quotes == 0)
			parser->quotes = 1;
		else if (corewar->line[(*i)] == '"' && parser->quotes == 1)
			break ;
		else if (parser->quotes == 1)
			ft_join_char_free(&str, corewar->line[(*i)]);
		corewar->esym++;
		(*i)++;
	}
	ft_strcpy(val->token, str);
	free(str);
	parser->quotes = 0;
	if (tmp->label == COMMAND_COMMENT)
		check_comment(val);
	else
		check_name(val);
}

void			circle_closure(t_cw *corewar)
{
	t_ls		*head;
	t_ls		*tail;

	head = corewar->tokens;
	tail = corewar->tokens;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->prev = tail;
}
