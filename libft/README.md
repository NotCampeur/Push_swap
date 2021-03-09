# libft
Basic library in C language.

# Change log

- A new header file has been created (libft_error.h) to organize the defines
	and the function relative to the error management

- Almost every function has been changed to return
	an error message in the appropriate case.

	Updated files :

		new file :         includes/libft_error.h

		deleted  :         debug
		
		modified :         Makefile
		modified :         includes/libft_defines.h
		modified :         includes/libft_includes.h
		modified :         includes/libft_io.h
		modified :         srcs/checks/ft_is_char_in_str.c
		modified :         srcs/checks/ft_is_charset_in_str.c
		modified :         srcs/checks/ft_is_only_digits.c
		modified :         srcs/checks/ft_strcmp.c
		modified :         srcs/converts/ft_atoi.c
		modified :         srcs/converts/ft_itoa_base.c
		modified :         srcs/converts/ft_itoa_octa.c
		modified :         srcs/file/ft_get_file.c
		modified :         srcs/file/ft_get_next_line.c
		modified :         srcs/io/ft_error.c
		modified :         srcs/io/ft_print_int_tab.c
		modified :         srcs/io/ft_print_int_tab_fd.c
		modified :         srcs/io/ft_print_str_tab.c
		modified :         srcs/io/ft_print_str_tab_fd.c
		modified :         srcs/io/ft_print_str_tab_fp.c
		modified :         srcs/io/ft_putchar_fd.c
		modified :         srcs/io/ft_putchar_fp.c
		modified :         srcs/io/ft_putnbr_fd.c
		modified :         srcs/io/ft_putnbr_fp.c
		modified :         srcs/io/ft_putstr.c
		modified :         srcs/io/ft_putstr_fd.c
		modified :         srcs/io/ft_putstr_fp.c
		modified :         srcs/lists/ft_list_add_back.c
		modified :         srcs/lists/ft_list_add_front.c
		modified :         srcs/lists/ft_list_clear.c
		modified :         srcs/lists/ft_list_iter.c
		modified :         srcs/lists/ft_list_map.c
		modified :         srcs/lists/ft_list_remove_node.c
		modified :         srcs/lists/ft_list_size.c
		modified :         srcs/lists/ft_malloc_node.c
		modified :         srcs/main.c
		modified :         srcs/math/ft_swap.c
		modified :         srcs/strings/ft_rm_charset.c
		modified :         srcs/strings/ft_split.c
		modified :         srcs/strings/ft_str_add_prefixe.c
		modified :         srcs/strings/ft_str_add_suffix.c
		modified :         srcs/strings/ft_str_count_c.c
		modified :         srcs/strings/ft_strcpy.c
		modified :         srcs/strings/ft_strdup.c
		modified :         srcs/strings/ft_strdup_c.c
		modified :         srcs/strings/ft_strjoin.c
		modified :         srcs/strings/ft_strlen.c
		modified :         srcs/strings/ft_strnew.c
		modified :         srcs/strings/ft_strnstr.c
		modified :         srcs/strings/ft_strstr.c
		modified :         srcs/strings/ft_strsub.c
		modified :         srcs/tabs/ft_add_to_tab.c
		modified :         srcs/tabs/ft_free_tab.c
		modified :         srcs/tabs/ft_tab_cpy.c
		modified :         srcs/tabs/ft_tab_len.c
		modified :         srcs/tabs/ft_tab_new.c
