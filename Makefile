#https://stackoverflow.com/questions/20308661/linking-sdl-image-in-make-file
OBJS = main.cpp TextureManager.cpp Game.cpp ObjectBehaviour.cpp Player.cpp Enemy.cpp InputHandler.cpp

CC = g++

LIBS = /usr/include/SDL_image 

COMPILER_FLAGS = -w 

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = main

all : $(OBJ_NAME)

$(OBJ_NAME) : $(OBJS)
		$(CC) $(OBJS) -L $(LIBS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

