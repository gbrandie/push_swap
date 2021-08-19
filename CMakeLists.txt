cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap push_swap.c libft/ft_strlen.c libft/ft_split.c libft/ft_isdigit.c create_stack_funcs.c helpful_funcs.c bad_and_check_funcs.c)