.PHONY: all
IMPL=TM.cpp
LIBS=$(addprefix lib,$(IMPL:.cpp=.so))
CFLAGS= -std=c++11 -fPIC
OBJECTS=libTM.so libParser.so libValidator.so libTM_Definition.so libTransition.so libTM_Facade.so libTransition_Processor.so libInput_Strings.so libTape.so
CC= g++
LDFLAGS= -L. -lm -lTM -lParser -lValidator -lTM_Definition -lTransition -lTM_Facade -lTransition_Processor -lInput_Strings -lTape
all: TM main.o $(OBJECTS)
TM.o: TM.cpp TM.hpp
	${CC} $(CFLAGS) -c $<
libTM.so: TM.o
		$(CC) --shared -o $@ $<
Parser.o: Parser.cpp Parser.hpp
	${CC} $(CFLAGS) -c $<
libParser.so: Parser.o
		$(CC) --shared -o $@ $<
Validator.o: Validator.cpp Validator.hpp
	${CC} $(CFLAGS) -c $<
libValidator.so: Validator.o
		$(CC) --shared -o $@ $<
TM_Definition.o: TM_Definition.cpp TM_Definition.hpp
	${CC} $(CFLAGS) -c $<
libTM_Definition.so: TM_Definition.o
		$(CC) --shared -o $@ $<
Transition.o: Transition.cpp Transition.hpp
	${CC} $(CFLAGS) -c $<
libTransition.so: Transition.o
		$(CC) --shared -o $@ $<
TM_Facade.o: TM_Facade.cpp TM_Facade.hpp Input_Strings.hpp
	${CC} $(CFLAGS) -c $<
libTM_Facade.so: TM_Facade.o
		$(CC) --shared -o $@ $<
Transition_Processor.o: Transition_Processor.cpp Transition_Processor.hpp
	${CC} $(CFLAGS) -c $<
libTransition_Processor.so: Transition_Processor.o
		$(CC) --shared -o $@ $<
Tape.o: Tape.cpp Tape.hpp
	${CC} $(CFLAGS) -c $<
libTape.so: Tape.o
		$(CC) --shared -o $@ $<
Input_Strings.o: Input_Strings.cpp Input_Strings.hpp
		${CC} $(CFLAGS) -c $<
libInput_Strings.so: Input_Strings.o
	$(CC) --shared -o $@ $<
main.o: main.cpp TM.hpp
	${CC} $(CFLAGS) -c $<
TM: main.o $(OBJECTS)
	$(CC) -o TM main.o $(OBJECTS)  $(LDFLAGS)
clean:
	-rm TM
	-rm *.o
	-rm *.so
