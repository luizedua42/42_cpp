# ==============================================
# ?                    ABOUT
#  @file        : Makefile
#  @author      : luizedua
#  @email       : luizedua@student.42sp.org.br
#  @createdOn   : 05/02/2024
# =============================================**/

NAME=ZombieHorde
ECHO=echo
YELLOW=\033[1;33m
GREEN=\033[1;32m
RED=\033[0;31m
RESET=\033[0m

SOURCES= src/Zombie.cpp src/zombieHorde.cpp src/main.cpp

${NAME}: ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ -Wall -Wextra -Werror -std=c++98 -I include ${SOURCES} -o $@
	@${ECHO} "${GREEN}Compiled!${RESET}"

fclean:
	@rm -fr ${NAME}
	@${ECHO} "${RED}Files removed!${RESET}"

re: fclean ${NAME}

.PHONY: fclean re