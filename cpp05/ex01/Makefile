# /**======================
# *            42sp
# * @file      : Makefile
# * @author    : luizedua
# * @email     : luizedua@student.42sp.org.br
# * @createdOn : 06/02/2024
# *========================**/


NAME=Form
ECHO=echo
YELLOW=\033[1;33m
GREEN=\033[1;32m
RED=\033[0;31m
RESET=\033[0m


SOURCES= src/main.cpp src/Bureaucrat.cpp src/Form.cpp

${NAME}: ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ -g3 -Wall -Wextra -Werror -std=c++98 -I include ${SOURCES} -o $@
	@${ECHO} "${GREEN}Compiled!${RESET}"

fclean:
	@rm -fr ${NAME}
	@${ECHO} "${RED}Files removed!${RESET}"

re: fclean ${NAME}

.PHONY: fclean re