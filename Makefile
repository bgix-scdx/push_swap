.SILENT:
AR = ar 
AR_PARAMS = rc

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=19
LEAKFLAGS = -fsanitize=address -g3 -fno-omit-frame-pointer

FILE_COUNTER = .file_count
BFILE_COUNTER = .bfile_count

OBJFOLDER = obj
BOBJFOLDER = bonus_obj

SOURCES =	printf/utils/ft_printf_undec.c\
			printf/utils/ft_printf_base.c\
			printf/utils/ft_printf_void.c\
			printf/utils/ft_printf_char.c\
			printf/utils/ft_printf_str.c\
			printf/utils/ft_printf_dec.c\
			push_rotate_swap/psr_call.c\
			sorting_algo/greedy_utils.c\
			push_rotate_swap/mini_p.c\
			push_rotate_swap/mini_r.c\
			sorting_algo/sort_utils.c\
			push_rotate_swap/mini_s.c\
			sorting_algo/minisort.c\
			sorting_algo/customs.c\
			sorting_algo/radix.c\
 			bench/bench_utils.c\
			bench/utils_bench.c\
			utils/normaliser.c\
			utils/visualizer.c\
			printf/ft_printf.c\
			utils/disorder.c\
			bench/screen.c\
			utils/utils.c\
			bench/bench.c\
			utils/math.c\
			utils/pars.c\
			push_swap.c\
			init.c\

RNG_SOURCE =	number_generator.c\
				utils/utils.c\
				utils/math.c\

B_SOURCES =	printf/ft_printf.c\
			printf/utils/ft_printf_undec.c\
			printf/utils/ft_printf_base.c\
			printf/utils/ft_printf_void.c\
			printf/utils/ft_printf_char.c\
			printf/utils/ft_printf_str.c\
			printf/utils/ft_printf_dec.c\
			bonus/fcts_de_base_bonus.c \
			bonus/fct_lauch_bonus.c \
			bonus/checker_bonus.c \
			bonus/utils_bonus.c

OBJECTS = $(SOURCES:%.c=$(OBJFOLDER)/%.o)
RNG_OBJECT = $(RNG_SOURCE:%.c=%.o)
B_OBJECTS = $(B_SOURCES:%.c=$(BOBJFOLDER)/%.o)

ARG = 100
TEMPLIST = .tmp
LISTNAME = numbers

NAME = push_swap
BNAME = checker
###############################
#   ___ _       _           _ #
#  / _ \ | ___ | |__   __ _| |#
# / /_\/ |/ _ \| '_ \ / _` | |#
#/ /_\\| | (_) | |_) | (_| | |#
#\____/|_|\___/|_.__/ \__,_|_|#
###############################

all: $(NAME) bonus
	if [ -f $(FILE_COUNTER) ]; then \
		echo "\033[1;34m ✅ $$(wc -l < $(FILE_COUNTER) | xargs) \033[1;36mFiles compiled\033[0m"; \
	else \
		echo "\033[1;34m ⛔️ No modifications found.\033[0m"; \
	fi; \
	rm -f $(FILE_COUNTER)

help:
	echo "\033[1;36m 🦈 bgix.\033[0m"
	echo "\033[0;36m 👉 Some functions can be used with \"_bonus\" to execute the bonus if they are present.\033[0m\n"
	echo "\033[1;36mTargets:\033[0m"
	echo "	\033[0;33mall\033		[0;36mBuild project\033[0m"
	echo "	\033[0;33mclean\033		[0;36mRemove obj folder\033[0m"
	echo "	\033[0;33mfclean\033		[0;36mRemove obj folder and $(NAME)\033[0m"
	echo "	\033[0;33mre\033		[0;36mRebuild project\033[0m"
	echo "	\033[0;33mexec\033		[0;36mBuild and execute project\033[0m"
	echo "	\033[0;33msanitize\033	[0;36mBuild, execute and check for memory leaks\033[0m"
	echo "	\033[0;33mcheckfunc\033	[0;36mShow all used functions\033[0m"
	echo "	\033[0;33mcdebug\033		[0;36mLaunch lldb\033[0m"
	echo "	\033[0;33mnorm\033		[0;36mCheck the norminette with all params\033[0m\n"
	echo "\033[1;36mGit :\033[0m"
	echo "	\033[0;33mgstatus\033		[0;36mShow git's status\033[0m"
	echo "	\033[0;33mgadd\033		[0;36mAdd files to \033[0m"
	echo "	\033[0;33mgcommit\033		[0;36mCommit git with a the requested message\033[0m"
	echo "	\033[0;33mgpush\033		[0;36mPush the git\033[0m"
	echo "	\033[0;33mginit\033		[0;36mInitate git with requested message\033[0m"
	echo "	\033[0;33mgall\033		[0;36mDo it all baby ! add, commit and push the project\033[0m\n"
	echo "\033[1;36mMisc :\033[0m"
	echo "	\033[0;33mbgix\033		[0;36mbgix\033[0m"

clean:
	echo "\033[1;32m 💣 Objects removed.\033[0m"; \
	rm -rf $(OBJFOLDER)
	rm -rf $(BOBJFOLDER)
	rm -rf $(FILE_COUNTER)
	rm -rf $(TEMPLIST)
	rm -rf $(LISTNAME)

fclean:	clean
	echo "\033[1;32m 🧨 $(NAME) removed.\033[0m"; \
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f numgen

re: fclean all

debug:
	echo "\033[1;32m 👉 Debugging \033[0m"
	echo "\033[0;32m	| br set -n [function] : set break point at function \033[0m"
	echo "\033[0;32m	| r : run the function \033[0m"
	echo "\033[0;32m	| n : next line\033[0m"
	echo "\033[0;32m	| s : step in function\033[0m"
	echo "\033[0;32m	| exit : leave lldb\033[0m"
	$(CC) $(CFLAGS) $(NAME)
	lldb ./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

checkfunc:
	if [ -f $(NAME) ]; then \
		echo "\033[1;32mHere is the list of functions used :\033[0m";\
		nm -u $(NAME);\
		echo "\n";\
	else \
		echo "\033[1;31m ⛔️ $(NAME) not found, compilations is needed.\033[0m"; \
	fi; \

norm:
	echo "\n\033[1;32m 🔍 Checking the norminette \033[0m\n"
	norminette -R SourceSearchHeader -R CheckDefine
	echo "\n"

###########################
# _ __ ___   __ _(_)_ __  #
#| '_ ` _ \ / _` | | '_ \ #
#| | | | | | (_| | | | | |#
#|_| |_| |_|\__,_|_|_| |_|#
###########################

$(OBJFOLDER)/%.o: %.c
	echo 1 >> $(FILE_COUNTER) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(MAIN_OBJECT)
	$(CC) $(params) $(OBJECTS) -o $(NAME)

sanitize: all
	echo "\033[1;32m 👉 Executing\033[0m"
	echo "\033[0;32m 💧 Memory leak will show up if present\033[0m"
	$(CC) $(CFLAGS) $(LEAKFLAGS) $(NAME)
	./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

valgrind: re
	echo "\033[1;32m 👉 Executing with valgrind\033[0m"
	$(CC) $(CFLAGS) $(NAME)
	valgrind --leak-check=full ./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

exec: re
	echo "\033[1;32m 👉 Executing \033[0m"
	$(CC) $(CFLAGS) $(NAME)
	./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

###############################
#   ___                       #
#  / __\ ___  _ __  _   _ ___ #
# /__\/// _ \| '_ \| | | / __|#
#/ \/  \ (_) | | | | |_| \__ \#
#\_____/\___/|_| |_|\__,_|___/#
###############################

$(BOBJFOLDER)/%.o: %.c
	echo 1 >> $(BFILE_COUNTER) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BNAME): $(B_OBJECTS)
	$(CC) $(params) $(B_OBJECTS) -o  $(BNAME)

bonus: $(BNAME)
	if [ -f $(BFILE_COUNTER) ]; then \
		echo "\033[1;34m ✅ $$(wc -l < $(BFILE_COUNTER) | xargs) \033[1;36mFiles compiled ⭐️\033[0m"; \
	else \
		echo "\033[1;34m ⛔️ No modifications found. ⭐️\033[0m"; \
	fi; \
	rm -f $(BFILE_COUNTER)

exec_bonus: re_bonus
	echo "\033[1;32m 👉 Executing ⭐️\033[0m"
	$(CC) $(CFLAGS) $(NAME)
	valgrind --leak-check=full ./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

sanitize_bonus: re_bonus
	echo "\033[1;32m 👉 Executing ⭐️\033[0m"
	echo "\033[0;32m 💧 Memory leak will show up if present\033[0m"
	$(CC) $(CFLAGS) $(LEAKFLAGS) $(NAME)
	./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

valgrind_bonus: re_bonus
	echo "\033[1;32m 👉 Executing with valgrind\033[0m"
	$(CC) $(CFLAGS) $(NAME)
	valgrind --leak-check=full ./a.out
	rm -f a.out
	echo "\n\033[1;32mEnded >\033[0m"

re_bonus: fclean all_bonus

#######################
#   ___  _____  _____ #
#  / _ \ \_   \/__   \#
# / /_\/  / /\/  / /\/#
#/ /_\\/\/ /_   / /   #
#\____/\____/   \/    #
#######################

gstatus:
	git status

gadd:
	git add .

gcommit:
	read -p " 📡 Commit message : " msg; \
	git commit -m "$$msg"

gpush:
	git push

ginit:
	git init
	git add .
	read -p " 📡 Commit message : " msg; \
	git commit -m "$$msg"
	echo "\033[0;32mCreated new git with message : \033[1;34m$$msg\033[0m"

gall: gadd gcommit gpush

                                      
#########################################
# ▄████▄ ▄▄▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄▄ ▄▄▄▄   ▄▄▄▄ #
# ██  ██   ██   ██▄██ ██▄▄  ██▄█▄ ███▄▄ #
# ▀████▀   ██   ██ ██ ██▄▄▄ ██ ██ ▄▄██▀ #
#########################################      

rng: fclean all
	echo "\033[1;32m 👉 Executing using a list of size $(ARG) \033[0m"
	for i in $$(seq 1 $(ARG)); do\
		echo $$i >> $(TEMPLIST); \
	done
	shuf $(TEMPLIST) >> $(LISTNAME)
	rm -f $(TEMPLIST)
	./$(NAME) --test --bench $$(cat $(LISTNAME))

rng2:
	cc $(RNG_SOURCE) $(CFLAGS) -o numgen

valgrind_check: fclean all bonus rng2
	valgrind ./$(NAME) --simple 2 5 4 6 3 1
	valgrind ./$(NAME) --bench 5 4 8 6 2 3
	valgrind ./$(NAME) --bench 5 4 4
	./$(NAME) --simple 2 5 4 6 3 1 | valgrind ./checker 2 5 4 6 3 1
	valgrind ./numgen 10 25

bgix:
	bgix

.PHONY: all bonus clean fclean re exec