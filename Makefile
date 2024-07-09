LIB      = libtorus.a
SRC_DIR  = src/
TEST_DIR = test/

all:
	$(MAKE) -C $(SRC_DIR) all
	mv $(SRC_DIR)$(LIB) .

clean:
	$(MAKE) -C $(SRC_DIR) clean

fclean: clean
	$(MAKE) -C $(SRC_DIR) fclean
	rm -f $(LIB)

re: clean all

tests:
	$(MAKE) -C $(TEST_DIR) all

clean_tests:
	$(MAKE) -C $(TEST_DIR) fclean