/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:09:30 by selbouka          #+#    #+#             */
/*   Updated: 2024/12/16 21:26:34 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include <sys/fcntl.h>
#include <libc.h>
#include "get_next_line.h"



void leeek(void)
{
	system("leaks a.out");
}

int main()
{
	int fd = open ("test.txt",O_RDWR);

	// int i = 0;
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	// while (i <= 3)
	// {
	// 	printf("%s",get_next_line(fd));
	// 	i++;
	// }
	

}

// int main(int argc, char **argv)
// {
// 	(void)argv;
// 	(void)argc;
// 	int i;
// 	i = 5;

// 	char string[i];
// 	string[0] = 'a';
// 	string[1] = 'b';
// 	string[2] = 'c';
// 	string[3] = 'd';
// 	printf("%s\n", string);
// 	i = 2;
// 	printf("%c", string[3]);
// }





// char *outline(char *saveline) 
// { char *str = NULL; 
// int i = 0; int j = 0;
//  while (saveline[i] != '\n' && saveline[i] != '\0') 
//  { i++; } 
//  str = malloc(sizeof(char) * (i + 2)); 
//  if (!str) { return NULL; } 
//  while (j <= i) 
//  { str[j] = saveline[j]; j++; }
//   str[j] = '\0'; return


// char *outline(char *saveline) 
// { 
// 	char *str = NULL; 
//  	int i = 0; 
//   	int j = 0;
//     while (saveline[i] != '\n' && saveline[i] != '\0')
//     { i++; } 
// 	str = malloc(sizeof(char) * (i + 2)); 
// 	if (!str) { return NULL; } 
// 	while (j <= i) { str[j] = saveline[j]; j++; }
// 	str[j] = '\0';
//     return str;
// }
