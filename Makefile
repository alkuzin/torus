CC     = g++
CFLAGS = -Wall -Wextra -Werror -g 
NAME   = libtorus.a

SRC  = statistics plot
SRCS = $(addsuffix .cpp, $(SRC))
OBJS = $(addsuffix .o, 	 $(SRC))
SRCS_PREFIXED = $(addprefix src/, $(SRCS))

OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_PREFIXED): $(SRCS_PREFIXED)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $(SRCS_PREFIXED)
	mv *.o $(OBJS_DIR)

$(NAME): $(OBJS_PREFIXED)
	ar rcs $(NAME) $(OBJS_PREFIXED)

all: $(NAME) 

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all
