INCLUDE_DIR = ../include/
LIB         = ../libtorus.a
CC          = g++
LFLAGS      = -relocatable
CFLAGS      = -Wall -Wextra -Werror -g -O2 -I $(INCLUDE_DIR)
LINKS       = -lgtest -lm

NAME = test_torus
SRC  = test_main test_stat

SRCS  = $(addsuffix .cpp, $(SRC))
OBJS  = $(addsuffix .o, $(SRC))

OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_PREFIXED): $(SRCS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(OBJS_DIR)

$(NAME): $(OBJS_PREFIXED)
	$(CC) $(CFLAGS) $(OBJS_PREFIXED) $(LIB) -o $(NAME) $(LINKS)

all: $(NAME) 

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all