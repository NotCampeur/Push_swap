# Push_swap
A 42 school's project. 

> :warning: **Warning**: It is educational project.

> :warning: **Warning**: You can take inspiration from it but don't copy / paste what you don't understand.

# Last changes :
> The visualizer is now split from the mandatory part
> everything is normed
> leaks seems to come from SDL->Xlib
> Parsing take the parameters accordingly to the subject.


# Git status return :
        modifié :         Makefile
        modifié :         includes/checker_includes/checker_engine.h
        modifié :         includes/checker_includes/checker_includes.h
        modifié :         includes/checker_includes/checker_load.h
        supprimé :        includes/checker_includes/checker_operations.h
        modifié :         includes/checker_includes/checker_structure.h
        renommé :         includes/push_swap_includes/push_swap_operations.h -> includes/operations_includes/ps_c_operations.h
        modifié :         includes/push_swap_includes/push_swap_algos.h
        modifié :         includes/push_swap_includes/push_swap_includes.h
        modifié :         includes/push_swap_includes/push_swap_load.h
        modifié :         includes/push_swap_includes/push_swap_peculiar_cases.h
        renommé :         includes/checker_includes/checker_parsing.h -> includes/visualizer_includes/visualizer.h
        nouveau fichier : includes/visualizer_includes/visualizer_engine.h
        nouveau fichier : includes/visualizer_includes/visualizer_includes.h
        renommé :         includes/checker_includes/checker_sdl.h -> includes/visualizer_includes/visualizer_sdl.h
        nouveau fichier : includes/visualizer_includes/visualizer_structure.h
        renommé :         includes/checker_includes/checker_visualizer.h -> includes/visualizer_includes/visualizer_system.h
        modifié :         libft/Makefile
        modifié :         libft/libft.a
        modifié :         libft/objs/ft_add_to_tab.o
        modifié :         libft/objs/ft_atoi.o
        modifié :         libft/objs/ft_error.o
        modifié :         libft/objs/ft_float_abs.o
        modifié :         libft/objs/ft_float_floor.o
        modifié :         libft/objs/ft_float_roof.o
        modifié :         libft/objs/ft_float_round.o
        modifié :         libft/objs/ft_free_tab.o
        modifié :         libft/objs/ft_get_file.o
        modifié :         libft/objs/ft_get_next_line.o
        modifié :         libft/objs/ft_int_abs.o
        modifié :         libft/objs/ft_is_alpha.o
        modifié :         libft/objs/ft_is_alpha_num.o
        modifié :         libft/objs/ft_is_char_in_str.o
        modifié :         libft/objs/ft_is_charset_in_str.o
        modifié :         libft/objs/ft_is_digit.o
        modifié :         libft/objs/ft_is_lower.o
        modifié :         libft/objs/ft_is_only_digits.o
        modifié :         libft/objs/ft_is_upper.o
        modifié :         libft/objs/ft_is_valid_file_path.o
        modifié :         libft/objs/ft_is_white_space.o
        modifié :         libft/objs/ft_itoa.o
        modifié :         libft/objs/ft_itoa_base.o
        modifié :         libft/objs/ft_itoa_hexa.o
        modifié :         libft/objs/ft_itoa_octa.o
        modifié :         libft/objs/ft_list_add_back.o
        modifié :         libft/objs/ft_list_add_front.o
        modifié :         libft/objs/ft_list_clear.o
        modifié :         libft/objs/ft_list_iter.o
        modifié :         libft/objs/ft_list_map.o
        modifié :         libft/objs/ft_list_putstr.o
        modifié :         libft/objs/ft_list_putstr_fd.o
        modifié :         libft/objs/ft_list_putstr_fp.o
        modifié :         libft/objs/ft_list_remove_node.o
        modifié :         libft/objs/ft_list_size.o
        modifié :         libft/objs/ft_malloc_node.o
        modifié :         libft/objs/ft_nbr_len.o
        modifié :         libft/objs/ft_print_int_tab.o
        modifié :         libft/objs/ft_print_int_tab_fd.o
        modifié :         libft/objs/ft_putchar.o
        modifié :         libft/objs/ft_putchar_fd.o
        modifié :         libft/objs/ft_putchar_fp.o
        modifié :         libft/objs/ft_putnbr.o
        modifié :         libft/objs/ft_putnbr_fd.o
        modifié :         libft/objs/ft_putnbr_fp.o
        modifié :         libft/objs/ft_putstr.o
        modifié :         libft/objs/ft_putstr_fd.o
        modifié :         libft/objs/ft_putstr_fp.o
        modifié :         libft/objs/ft_putstr_tab.o
        modifié :         libft/objs/ft_putstr_tab_fd.o
        modifié :         libft/objs/ft_putstr_tab_fp.o
        modifié :         libft/objs/ft_rm_charset.o
        modifié :         libft/objs/ft_split.o
        modifié :         libft/objs/ft_str_add_prefixe.o
        modifié :         libft/objs/ft_str_add_suffix.o
        modifié :         libft/objs/ft_str_count_c.o
        modifié :         libft/objs/ft_strcmp.o
        modifié :         libft/objs/ft_strcpy.o
        modifié :         libft/objs/ft_strdup.o
        modifié :         libft/objs/ft_strdup_c.o
        modifié :         libft/objs/ft_strjoin.o
        modifié :         libft/objs/ft_strlen.o
        modifié :         libft/objs/ft_strnew.o
        modifié :         libft/objs/ft_strnstr.o
        modifié :         libft/objs/ft_strstr.o
        modifié :         libft/objs/ft_strsub.o
        modifié :         libft/objs/ft_swap.o
        modifié :         libft/objs/ft_tab_cpy.o
        modifié :         libft/objs/ft_tab_len.o
        modifié :         libft/objs/ft_tab_new.o
        modifié :         libft/srcs/checks/ft_is_charset_in_str.c
        modifié :         libft/srcs/converts/ft_atoi.c
        modifié :         libft/srcs/file/ft_get_next_line.c
        modifié :         libft/srcs/lists/ft_list_size.c
        modifié :         libft/srcs/strings/ft_str_count_c.c
        supprimé :        log_checker.log
        supprimé :        log_push_swap.log
        modifié :         srcs/checker/checker_apply_operation.c
        modifié :         srcs/checker/checker_engine.c
        nouveau fichier : srcs/checker/checker_instructions.c
        modifié :         srcs/checker/checker_load.c
        modifié :         srcs/checker/checker_main.c
        modifié :         srcs/checker/checker_parsing.c
        renommé :         srcs/checker/visualizer/SDL_Creators/SDL_ColorInit.c -> srcs/checker/visualizer/SDL_Creators/sdl_color_init.c
        renommé :         srcs/checker/visualizer/SDL_Creators/SDL_PointInit.c -> srcs/checker/visualizer/SDL_Creators/sdl_point_init.c
        renommé :         srcs/checker/visualizer/SDL_Creators/SDL_RectInit.c -> srcs/checker/visualizer/SDL_Creators/sdl_rect_init.c
        nouveau fichier : srcs/checker/visualizer/SDL_Render/sdl_render_tools.c
        renommé :         srcs/checker/visualizer/SDL_TextureManagement.c -> srcs/checker/visualizer/SDL_Render/sdl_texture_management.c
        supprimé :        srcs/checker/visualizer/checker_visualizer.c
        nouveau fichier : srcs/checker/visualizer/visualizer_engine.c
        nouveau fichier : srcs/checker/visualizer/visualizer_main.c
        nouveau fichier : srcs/checker/visualizer/visualizer_system.c
        modifié :         srcs/operations/push.c
        modifié :         srcs/operations/reverse_rotate.c
        modifié :         srcs/operations/rotate.c
        modifié :         srcs/operations/swap.c
        modifié :         srcs/push_swap/push_swap_algos.c
        modifié :         srcs/push_swap/push_swap_engine.c
        modifié :         srcs/push_swap/push_swap_load.c
        modifié :         srcs/push_swap/push_swap_main.c
        modifié :         srcs/push_swap/push_swap_parsing.c
        modifié :         srcs/push_swap/push_swap_peculiar_cases.c
        supprimé :        stack.txt
        supprimé :        start.sh

In this repository you will find two programs to find and test a sorting algorithm on a stack of int
