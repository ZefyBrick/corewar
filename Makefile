# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 19:28:25 by jormond-          #+#    #+#              #
#    Updated: 2020/02/13 22:55:57 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
CR = corewar

ASMINC = assembler/inc/op.h assembler/inc/asm.h
VMINC = vm/inc/op.h

VMLIB = vm/ft_printf/libftprintf.a
ASMLIB = assembler/ft_printf/libftprintf.a

NCURS = -lncurses

FLAGS = -Wall -Wextra -Werror

CRFILES = corewar.c errors.c input_players.c validation.c create.c disasm.c \
validation_2.c arena.c operations.c operations_code_1.c operations_code_2.c \
operations_code_3.c operations_code_4.c tools.c lets_go_war.c tools2.c op.c \
tools3.c ft_show.c ft_show2.c

ASMFILES = asm.c arg_reader.c s_compiler.c fill_magic_header.c tools.c \
read_and_write.c parse.c add_node.c champ_code.c add_token.c write_args.c \
ft_join_char_free.c compare_val.c error_out.c bad_line.c op.c who_is_who.c \
write_anything.c second_part_parse.c process_instr.c ft_strtrim_free.c \
tools2.c tools3.c right_arg.c right_arg2.c


CRSRC = $(addprefix vm/src/,$(CRFILES))
ASMSRC = $(addprefix assembler/src/,$(ASMFILES))

CROBJ = $(addprefix vm/obj/,$(CRFILES:.c=.o))
ASMOBJ = $(addprefix assembler/obj/,$(ASMFILES:.c=.o))

all : $(ASM) $(CR)

$(CR) : $(CROBJ)
	@make -C vm/ft_printf/
	@gcc -o $(CR) $(CROBJ) $(VMLIB) $(NCURS)

$(ASM) : $(ASMOBJ)
	@make -C assembler/ft_printf/
	@gcc -o $(ASM) $(ASMOBJ) $(ASMLIB)

vm/obj/%.o: vm/src/%.c $(INC)
	@mkdir -p vm/obj/
	@gcc $(FLAGS) -Ivm/inc -o $@ -c $<

assembler/obj/%.o: assembler/src/%.c $(ASMINC)
	@mkdir -p assembler/obj/
	@gcc $(FLAGS) -Iassembler/inc -o $@ -c $<

clean :
	@make clean -C vm/ft_printf
	@rm -rf vm/obj/
	@make clean -C assembler/ft_printf/
	@rm -rf assembler/obj/

fclean : clean
	@make fclean -C vm/ft_printf
	@rm -f $(CR)
	@make fclean -C assembler/ft_printf
	@rm -f $(ASM)

re : fclean all

