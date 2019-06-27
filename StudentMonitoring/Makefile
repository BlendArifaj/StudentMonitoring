####################################################################
# Makefile                                                         #
####################################################################

.SUFFIXES:				
.PHONY: clean all dox

####################################################################
# Path Definitions                                                 #
####################################################################
OUT_DIR     = ./output
OBJ_DIR     = $(OUT_DIR)/build
EXE_DIR     = $(OUT_DIR)/exe
DOX_DIR     = $(OUT_DIR)/docu
SRC_DIR     = ./src
INCLUDE_DIR = ./include

####################################################################
# Flag Definitions                                                 #
####################################################################
FLAGS = -Wall -c -ansi -g
INCLUDEPATHS =-I$(INCLUDE_DIR)

####################################################################
# Create build and ouput directory								   #
####################################################################
$(OBJ_DIR):
	mkdir -p $(OUT_DIR)
	mkdir -p $(OBJ_DIR)
	@echo "Created build directory."

$(EXE_DIR):
	mkdir -p $(EXE_DIR)
	@echo "Created executable directory."

####################################################################
# Build instructions			 								   #
####################################################################
all: $(OBJ_DIR) $(EXE_DIR) $(EXE_DIR)/exc 


$(EXE_DIR)/exc: $(OBJ_DIR)/main.o $(OBJ_DIR)/functions.o $(OBJ_DIR)/student.o $(OBJ_DIR)/signal_handler.o $(OBJ_DIR)/interactive_part.o $(OBJ_DIR)/help.o 
	gcc $(OBJ_DIR)/main.o $(OBJ_DIR)/functions.o $(OBJ_DIR)/student.o $(OBJ_DIR)/signal_handler.o $(OBJ_DIR)/interactive_part.o $(OBJ_DIR)/help.o -o $(EXE_DIR)/exc

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/functions.c $(SRC_DIR)/student.c
	gcc $(FLAGS) $(INCLUDEPATHS) -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.c 

$(OBJ_DIR)/functions.o: $(SRC_DIR)/functions.c
	gcc $(FLAGS) $(INCLUDEPATHS) -o $(OBJ_DIR)/functions.o $(SRC_DIR)/functions.c

$(OBJ_DIR)/student.o: $(SRC_DIR)/student.c
	gcc $(FLAGS) $(INCLUDEPATHS) -o $(OBJ_DIR)/student.o $(SRC_DIR)/student.c

$(OBJ_DIR)/signal_handler.o: $(SRC_DIR)/signal_handler.c
	gcc $(FLAGS) $(INCLUDEPATHS) -o $(OBJ_DIR)/signal_handler.o $(SRC_DIR)/signal_handler.c

$(OBJ_DIR)/interactive_part.o: $(SRC_DIR)/interactive_part.c
	gcc $(FLAGS) $(INCLUDEPATHS) -o $(OBJ_DIR)/interactive_part.o $(SRC_DIR)/interactive_part.c

$(OBJ_DIR)/help.o: $(SRC_DIR)/help.c
	gcc $(FLAGS) $(INCLUDEPATHS) -o $(OBJ_DIR)/help.o $(SRC_DIR)/help.c
dox:
	mkdir -p $(DOX_DIR)
	@echo "Created doxygen directory."

	doxygen ./doc/exc.dox

clean:
	rm -rf $(OBJ_DIR) $(DOX_DIR) $(EXE_DIR) $(OUT_DIR) 

