CPPFLAGS= -ID:\dev\libs\SFML-2.0\include -I./include

LDFLAGS= -LD:\dev\libs\SFML-2.0\lib  -lsfml-system -lsfml-window -lsfml-graphics

CXXFLAGS= -g -Wall -Wextra -std=c++0x

OBJS=src\BallsNBricks.o src\game\Game.o src\game\Ball.o src\game\LevelLoader.o src\game\Paddle.o src\game\Critter.o
NAME=BallsNBricks.exe

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	del $(NAME) $(OBJS)
