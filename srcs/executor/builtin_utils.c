/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:34:20 by serma             #+#    #+#             */
/*   Updated: 2021/04/15 18:58:40 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "programm_utils.h"

char	*cut_var(char *str)
{
	char	*ret;
	char	*eqv_sign;

	ret = ft_strdup(str);
	if (!ret)
		error_exit_message("", errno);
	eqv_sign = ft_strchr(ret, '=');
	if (!eqv_sign)
		return (ret);
	*eqv_sign = '\0';
	return (ret);
}

char	*create_str(char *env_str)
{
	char	*ret;
	char	*var;
	char	*arg;
	char	*eq_sign;

	ret = ft_strdup("declare -x ");
	if (!ret)
		error_exit_message("", errno);
	eq_sign = ft_strchr(env_str, '=');
	if (!eq_sign)
		return (ft_strjoin_free(ret, env_str));
	var = cut_var(env_str);
	arg = quotes_take(eq_sign + 1);
	ret = ft_strjoin_free(ret, var);
	ret = ft_strjoin_free(ret, "=");
	ret = ft_strjoin_free(ret, arg);
	free(arg);
	free(var);
	return (ret);
}
