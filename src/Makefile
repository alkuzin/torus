NAME = libtorus.a

TORUS_STAT_DIR  = stat/
TORUS_PLOT_DIR  = plot/
TORUS_UTILS_DIR = utils/

OBJS = $(TORUS_STAT_DIR)torus_stat.o $(TORUS_PLOT_DIR)torus_plot.o \
	   $(TORUS_UTILS_DIR)torus_utils.o

$(OBJS):
	$(MAKE) -C $(TORUS_STAT_DIR) all
	$(MAKE) -C $(TORUS_PLOT_DIR) all
	$(MAKE) -C $(TORUS_UTILS_DIR) all

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME) 

clean:
	$(MAKE) -C $(TORUS_STAT_DIR) fclean
	$(MAKE) -C $(TORUS_PLOT_DIR) fclean
	$(MAKE) -C $(TORUS_UTILS_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: clean all