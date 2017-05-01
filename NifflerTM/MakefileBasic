.PHONY: all
IMPL=TM.cpp
LIBS=$(addprefix lib,$(IMPL:.cpp=.so))
CFLAGS= -std=c++11 -fPIC
OBJECTS=TM.o Parser.o Validator.o Input_Strings.o TM_Definition.o Transition.o TM_Facade.o Transition_Processor.o Tape.o
CC=g++
LDFLAGS=
all: TM
main.o: main.cpp
	${CC} $(CFLAGS) -c $<
TM.o: TM.cpp TM.hpp
	${CC} $(CFLAGS) -c $<
Parser.o: Parser.cpp Parser.hpp
	${CC} $(CFLAGS) -c $<
Validator.o: Validator.cpp Validator.hpp
	${CC} $(CFLAGS) -c $<
TM_Definition.o: TM_Definition.cpp TM_Definition.hpp
	${CC} $(CFLAGS) -c $<
Transition.o: Transition.cpp Transition.hpp
	${CC} $(CFLAGS) -c $<
TM_Facade.o: TM_Facade.cpp TM_Facade.hpp Input_Strings.hpp
	${CC} $(CFLAGS) -c $<
Transition_Processor.o: Transition_Processor.cpp Transition_Processor.hpp
	${CC} $(CFLAGS) -c $<
Input_Strings.o: Input_Strings.cpp Input_Strings.hpp
	${CC} $(CFLAGS) -c $<
Tape.o: Tape.cpp Tape.hpp
	${CC} $(CFLAGS) -c $<
TM: main.o $(OBJECTS)
	$(CC) -o TM main.o $(OBJECTS) $(LDFLAGS)
clean:
	-rm TM
	-rm *.o
	-rm *.so
