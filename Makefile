CHECKER	=	./make_check
PUSH	=	./make_push


.PHONY: all clean fclean re

all: build

build:
	@$(MAKE) -f $(CHECKER)
	@$(MAKE) -f $(PUSH)

clean:
	@$(MAKE) -f $(CHECKER) clean
	@$(MAKE) -f $(PUSH) clean

fclean: 
	@$(MAKE) -f $(CHECKER) fclean
	@$(MAKE) -f $(PUSH) fclean

re: fclean all
