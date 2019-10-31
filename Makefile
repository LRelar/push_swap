CHECKER	=	./make_check
PUSH	=	./make_push


.PHONY: all clean fclean re make_check make_push

all: build

build: $(CHECKER) $(PUSH)

$(CHECKER):
	@$(MAKE) -f $(CHECKER)

$(PUSH):
	@$(MAKE) -f $(PUSH)

clean:
	@$(MAKE) -f $(CHECKER) clean
	@$(MAKE) -f $(PUSH) clean

fclean: 
	@$(MAKE) -f $(CHECKER) fclean
	@$(MAKE) -f $(PUSH) fclean

re: fclean all
