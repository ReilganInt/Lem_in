/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:50:51 by cormund           #+#    #+#             */
/*   Updated: 2019/12/11 16:47:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

t_step	*next_step(t_vis *vis, t_lem_in *li, t_step *step)
{
	if (step && step->next && !step->fin)
		return (step->next);
	else if (step && !step->next && !step->fin)
		step = collection_steps(vis, li, step);
	return (step);
}
