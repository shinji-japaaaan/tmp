# コンパイラとフラグの定義
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ターゲット名
NAME = push_swap

# ソースファイルとオブジェクトファイルの定義
SRCS = main.c operations.c utils.c sort.c
OBJS = $(SRCS:.c=.o)

# 依存関係の生成
DEPS = push_swap.h

# デフォルトのターゲット
all: $(NAME)

# ターゲットのリンク
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# オブジェクトファイルの生成
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップターゲット
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# リビルドターゲット
re: fclean all

# .PHONYターゲットの定義
.PHONY: all clean fclean re
