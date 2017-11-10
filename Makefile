# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enanrock <marvin42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 11:41:31 by enanrock          #+#    #+#              #
#    Updated: 2017/11/10 23:25:02 by enanrock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
NAME_001 = $(NAME)
NAME_ALL = $(NAME_001)

LIB_DIR = ./libft/
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
HDR_DIR = ./includes/

LIB = $(addsuffix Makefile, $(LIB_DIR))

.PHONY: all leaks clean fclean re new_author norme victory tuto where_is_malloc\
	tuto_map test test_mlp_0

all: $(LIB) author .gitignore
	@make $@ -C dir_of_makefile -f Makefile_lem-in

$(NAME_001): $(LIB)
	@make $(addprefix ../, $@) -C dir_of_makefile -f Makefile_lem-in

leaks:
	clear
	@make $@ -C dir_of_makefile -f Makefile_lem-in

clean: $(LIB)
	@make $@ -C dir_of_makefile -f Makefile_lem-in
ifneq ("$(OBJ_DIR)", "./")
	@echo "\033[1;31m""\c"
	@rm -fdv $(OBJ_DIR)
	@echo "\033[m""\c"
endif

fclean: $(LIB)
	@make $@ -C dir_of_makefile -f Makefile_lem-in
ifneq ("$(OBJ_DIR)", "./")
	@echo "\033[1;31m""\c"
	@rm -fdv $(OBJ_DIR)
	@echo "\033[m""\c"
endif

re: fclean all

where_is_malloc: $(LIB)
	@make $@ -C ./libft/

$(LIB):
	git clone https://github.com/erwan-nanrocki/libft.git ./libft/

author:
	@echo "\033[1;37m""\c"
	echo "enanrock" > author
	@echo "\033[m"

.gitignore:
	@echo "\033[1;37m""\c"
	echo "$(OBJ_DIR)"   > $@
	echo "$(NAME_ALL)" >> $@
	echo "*.swp"       >> $@
	echo "*.o"         >> $@
	echo "*.a"         >> $@
	echo "*_DONE"      >> $@
	@echo "\033[m"
	norme: $(LIB)
	@make norme -C $(LIB_DIR)
	@echo "\033[1;37m""norminette on $(SRC_DIR)""\033[m"
	@norminette $(SRC_DIR)                                   \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[0;32mNorme"`/g''
	@echo "\033[1;37m""norminette on $(HDR_DIR)""\033[m"
	@norminette $(HDR_DIR)                                   \
		| sed ''s/Error/`echo "\033[0;31mError"`/g''     \
		| sed ''s/Warning/`echo "\033[0;33mWarning"`/g'' \
		| sed ''s/Norme/`echo "\033[1;34mNorme"`/g''

victory:
	@echo "\r  ( '_' )           < .                                    \c"
	@sleep 1
	@echo "\r  ( -_- )           < ..                                   \c"
	@sleep 0.2
	@echo "\r  ( '_' )           < ...                                  \c"
	@sleep 1.5
	@echo "\r  ( ^_^ )           < cool, you did it !                   \c"
	@sleep 3
	@echo "\r  /)^3^(\           < So Awesome !                         \c"
	@sleep 3
	@num=1;\
		while [[ $$num -le 50 ]];do\
		echo "\r ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔʕ•̫͡•ʔ*̫͡*ʔ  < The local crowd into a frenzy        \c";\
		sleep 0.1;\
		echo "\r  ʕ•̫͡•ʕ*̫͡*ʕ•͓͡•ʔʕ•̫͡•ʔ*̫͡*ʔ < The local crowd into a frenzy        \c";\
		sleep 0.1;\
		((num = num + 1));\
		done
	@echo "\r ᕦ(ˇò_ó)ᕤ           < You're the best !                    \c"
	@sleep 3
	@num=1;\
		while [[ $$num -le 20 ]];do\
		echo "\r | ( ^.^ ) |        < Dance                                \c";\
		sleep 0.1;\
		echo "\r  /(  ^.^)  /       <        to                            \c";\
		sleep 0.1;\
		echo "\r | ( ^.^ ) |        <           death                      \c";\
		sleep 0.1;\
		echo "\r\  (^.^  )\         <                 !                    \c";\
		sleep 0.1;\
		((num = num + 1));\
		done
	@echo "\r \ (O.O  )\         < oops...                              \c"
	@sleep 1.5
	@echo "\r  ( ╥﹏╥ )          < Time to work now...                  \c"

tuto_map:
	clear
	@echo "options are : -l -p and -m 42"
	@echo ""
	@echo "1->0       ______________"
	@echo "         /                \\"
	@echo "  ______[5]----[3]-----{1} |"
	@echo " /              |      /   |"
	@echo "[6]-----}0{----[4]   /     |"
	@echo " \\   _________/ |  /       |"
	@echo "  \\ /          [2]<______/"
	@echo "  [7]_________/"
	@echo ""

tuto:
	@make tuto_map
	@read
	@echo "R:\033[32m+1+\033[m"
	@echo "R:\033[31m-1-\033[m\033[32m+12+13+\033[m"
	@echo "R:\033[31m-12-\033[m13""\c"
	@echo "\033[32m+124+125+127+\033[m""\033[33m~121~\033[m"
	@echo "R:\033[31m-13-\033[m124 125 127""\c"
	@echo "\033[32m+134+135+\033[m""\033[33m~131~\033[m"
	@echo "R:\033[31m-124-\033[m125 127 134 135""\c"
	@echo "\033[32m+1243+1247+\033[m""\033[33m~1242~\033[m"
	@echo ""
	@echo "S:\033[32m+1240+\033[m"
	@echo "100 ants in 1240 : (score = 102)"
	@read
	@make tuto_map
	@echo "R:\033[31m-125-\033[m127 134 135 1243 1247""\c"
	@echo "\033[32m+1253+1256+\033[m""\033[33m~1252~\033[m"
	@echo "R:\033[31m-127-\033[m134 135 1243 1247 1253 1256""\c"
	@echo "\033[32m+1274+1276+\033[m""\033[33m~1272~\033[m"
	@echo "R:\033[31m-134-\033[m135 1243 1247""\c"
	@echo " 1253 1256 1274 1276""\c"
	@echo "\033[32m+1342 1347+\033[m""\033[33m~1343~\033[m"
	@echo ""
	@echo "S: 1240\033[32m+1340+\033[m"
	@echo "100 ants in 1240 : (score = 102)"
	@echo ""
	@echo "50 ants in 13\033[31m4\033[m0  : (score = 52)"
	@echo "50 ants in 12\033[31m4\033[m0  : (score = 52)"
	@read
	@make tuto_map
	@echo "R:\033[31m-135-\033[m1243 1247 1253 1256""\c"
	@echo " 1274 1276 1342 1347""\c"
	@echo "\033[32m+1352+1356+\033[m""\033[33m~1353~\033[m"
	@echo "R:\033[31m-1243-\033[m1247 1253 1256""\c"
	@echo " 1274 1276 1342 1347 1352 1356""\c"
	@echo "\033[32m+12435+\033[m""\033[33m~12431~12434~\033[m"
	@echo "R:\033[31m-1247-\033[m1253 1256 1274 1276 1342""\c"
	@echo " 1347 1352 1356 12435""\c"
	@echo "\033[32m+12476+\033[m""\033[33m~12472 12474~\033[m"
	@echo "R:\033[31m-1253-\033[m1256 1274 1276 1342""\c"
	@echo " 1347 1352 1356 12435 12476""\c"
	@echo "\033[32m+12534+\033[m""\033[33m~12531~12535~\033[m"
	@echo "R:\033[31m-1256-\033[m1274 1276 1342 1347 1352""\c"
	@echo " 1356 12435 12476 12534""\c"
	@echo "\033[32m+12567+\033[m""\033[33m~12565~\033[m"
	@echo ""
	@echo "S: 1240 1340\033[32m+12560+\033[m"
	@echo "100 ants in 1240 : (score = 102)"
	@echo ""
	@echo "50 ants in 1\033[31m2\033[m560 : (score = 53)"
	@echo "50 ants in 1\033[31m2\033[m34  : (score = 52)"
	@echo "or"
	@echo "50 ants in 1\033[31m2\033[m560 : (score = 53)"
	@echo "50 ants in 1\033[31m2\033[m40  : (score = 52)"
	@read
	@make tuto_map
	@echo "R:\033[31m-1274-\033[m1276 1342 1347 1352 1356""\c"
	@echo " 12435 12476 12534""\c"
	@echo " 12567\033[32m+12743+\033[m""\033[33m~12742~12747~\033[m"
	@echo ""
	@echo "S: 1240 1340 12560\033[32m+12740+\033[m"
	@echo "100 ants in 1240 : (score = 102)"
	@echo ""
	@echo "50 ants in 1\033[31m2\033[m740 : (score = 53)"
	@echo "50 ants in 1\033[31m2\033[m560 : (score = 53)"
	@echo "or"
	@echo "50 ants in 127\033[31m4\033[m0 : (score = 53)"
	@echo "50 ants in 13\033[31m4\033[m0  : (score = 52)"
	@echo "or"
	@echo "50 ants in 1\033[31m2\033[m7\033[31m4\033[m0 : (score = 53)"
	@echo "50 ants in 1\033[31m24\033[m0  : (score = 52)"
	@read
	@make tuto_map
	@echo "R:\033[31m-1276-\033[m1342 1347 1352 1356 12435 12476 12534""\c"
	@echo " 12567 12743""\c"
	@echo "\033[32m+12765+\033[m""\033[33m~12767~\033[m"
	@echo ""
	@echo "S: 1240 1340 12560 12740\033[32m+12760+\033[m"
	@echo "100 ants in 1240 : (score = 102)"
	@echo ""
	@echo "50 ants in 1\033[31m27\033[m60 : (score = 53)"
	@echo "50 ants in 1\033[31m27\033[m40 : (score = 53)"
	@echo "or"
	@echo "50 ants in 1\033[31m2\033[m7\033[31m6\033[m0 : (score = 53)"
	@echo "50 ants in 1\033[31m2\033[m5\033[31m6\033[m0 : (score = 53)"
	@echo "or"
	@echo "50 ants in 12760 : (score = 53)"
	@echo "50 ants in 1340  : (score = 52)"
	@echo "or"
	@echo "50 ants in 1\033[31m2\033[m760 : (score = 53)"
	@echo "50 ants in 1\033[31m2\033[m40  : (score = 52)"

test:
	clear
	cat ./anthill/example_no_room.map
	read
	clear
	./lem-in < ./anthill/example_no_room.map
	read
	clear
	cat ./anthill/example_0_ant.map
	read
	clear
	./lem-in < ./anthill/example_0_ant.map
	read
	clear
	cat ./anthill/example_minus3_ant.map
	read
	clear
	./lem-in < ./anthill/example_minus3_ant.map
	read
	clear
	cat ./anthill/example_no_start.map
	read
	clear
	./lem-in < ./anthill/example_no_start.map
	read
	clear
	cat ./anthill/example_no_end.map
	read
	clear
	./lem-in < ./anthill/example_no_end.map
	read
	clear
	cat ./anthill/example_no_solution_1.map
	read
	clear
	./lem-in < ./anthill/example_no_solution_1.map
	read
	clear
	cat ./anthill/example_no_solution_2.map
	read
	clear
	./lem-in < ./anthill/example_no_solution_2.map
	read
	clear
	cat ./anthill/example1.map
	read
	clear
	./lem-in < ./anthill/example1.map
	read
	clear
	cat ./anthill/example_start_end_are_the_same.map
	read
	clear
	./lem-in < ./anthill/example_start_end_are_the_same.map
	read
	clear
	cat ./anthill/example42.map
	read
	clear
	./lem-in < ./anthill/example42.map
	read
	clear
	cat ./anthill/example2ants.map
	read
	clear
	./lem-in < ./anthill/example2ants.map
	read
	clear
	cat ./anthill/example1000.map
	read
	clear
	./lem-in < ./anthill/example1000.map
	read

test_mlp_0:
	clear
	cat ./anthill/example_no_room.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_no_room.map
	read
	clear
	cat ./anthill/example_0_ant.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_0_ant.map
	read
	clear
	cat ./anthill/example_minus3_ant.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_minus3_ant.map
	read
	clear
	cat ./anthill/example_no_start.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_no_start.map
	read
	clear
	cat ./anthill/example_no_end.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_no_end.map
	read
	clear
	cat ./anthill/example_no_solution_1.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_no_solution_1.map
	read
	clear
	cat ./anthill/example_no_solution_2.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_no_solution_2.map
	read
	clear
	cat ./anthill/example1.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example1.map
	read
	clear
	cat ./anthill/example_start_end_are_the_same.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example_start_end_are_the_same.map
	read
	clear
	cat ./anthill/example42.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example42.map
	read
	clear
	cat ./anthill/example2ants.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example2ants.map
	read
	clear
	cat ./anthill/example1000.map
	read
	clear
	./lem-in -mlp 0 < ./anthill/example1000.map
	read
