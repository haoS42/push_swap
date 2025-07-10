/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yossasak <yossasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:14:47 by yossasak          #+#    #+#             */
/*   Updated: 2024/12/01 21:02:02 by yossasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// #include <stdio.h>

// int main(void)
// {
//     // テストデータ
//     char *content = "Hello, world!";

//     // 新しいリスト要素を作成
//     t_list *new_node = ft_lstnew(content);

//     // 結果をチェック
//     if (new_node == NULL)
//     {
//         printf("Error: ft_lstnew returned NULL.\n");
//         return (1);
//     }

//     // リスト要素の内容を表示
//     printf("Content of the new node: %s\n", (char *)new_node->content);

//     // 次の要素がNULLであることを確認
//     if (new_node->next == NULL)
//     {
//         printf("Next pointer is correctly NULL.\n");
//     }
//     else
//     {
//         printf("Error: Next pointer is not NULL.\n");
//     }

//     // メモリ解放
//     free(new_node);

//     return (0);
// }
