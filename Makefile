NAME				=		abstractVM

CXX					=		g++

NOW 				:=	$(shell date +"%d %h %g:%R")

DEFAULT				=		"\033[00m"
GREEN				=		"\033[0;32m"
HIGHLIGHTED			=		"\033[2;102m"
HIGHLIGHTED_R			=		"\033[2;101m"
DELETION 			=		"\033[2;103m"
TEAL				=		"\033[1;34m"
RED					=		"\033[1;31m"
ECHO				=		/bin/echo -e

SRC_PATH	= ./src/
SRC		=	$(SRC_PATH)main.cpp \
			$(SRC_PATH)Exception.cpp \
			$(SRC_PATH)Factory.cpp \
			$(SRC_PATH)types/Float.cpp \
			$(SRC_PATH)types/Int8.cpp \
			$(SRC_PATH)types/Int16.cpp \
			$(SRC_PATH)types/Int32.cpp \
			$(SRC_PATH)types/Double.cpp \
			$(SRC_PATH)types/BigDecimal.cpp \
			$(SRC_PATH)Operand.cpp \
			$(SRC_PATH)VirtualMachine.cpp 

OBJ					=		$(SRC:.cpp=.o)

CXXFLAGS			+= 	-Wall -Wextra -std=c++11 -g -fpic

INCLUDE				=	-I./include

LIB = -lpthread

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CXX) $(OBJ) -o $(NAME) $(LIB)
		@$(ECHO) $(HIGHLIGHTED)"COMPILATION SUCCEEDED ON "$(NOW)$(DEFAULT)"\n"
		@$(fclean)
clean:
		@$(RM) $(OBJ) $(PROC_OBJ) $(BONUS_OBJ)
		@$(ECHO) $(DELETION)"OBJs PROPERLY DELETED"$(DEFAULT)

fclean:		clean
		@$(RM) $(NAME) $(PROC_NAME)
		@$(ECHO) $(DELETION)"BINARY PROPERLY DELETED"$(DEFAULT)

re:		fclean all

.PHONY:		all clean fclean re

.cpp.o:
		@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@  && \
		$(ECHO) $(GREEN) " [OK] " $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) " [XX] " $(TEAL) $< $(DEFAULT)