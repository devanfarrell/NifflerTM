.PHONY: all
IMPL=TM.cpp
LIBS=$(addprefix lib,$(IMPL:.cpp=.so))
CFLAGS=-g -std=c++11 -fPIC -DTIMES=4
CC=g++
LDFLAGS=-lm
debug:
	echo $(IMPL:.cpp=.so)
	echo ${LIBS}
all: TM $(LIBS)
tm.o: TM.cpp
	${CC} $(CFLAGS) -c $<
libtm.so: tm.o
		$(CC) --shared -o $@ $<
parser.o: Parser.cpp
	${CC} $(CFLAGS) -c $<
libparser.so: parser.o
		$(CC) --shared -o $@ $<
validator.o: Validator.cpp
	${CC} $(CFLAGS) -c $<
libvalidator.so: validator.o
		$(CC) --shared -o $@ $<
tmdefinition.o: TM_Definition.cpp
	${CC} $(CFLAGS) -c $<
libtmdefinition.so: tmdefinition.o
		$(CC) --shared -o $@ $<
transition.o: Transition.cpp
	${CC} $(CFLAGS) -c $<
libtransition.so: transition.o
		$(CC) --shared -o $@ $<
tmfacade.o: TM_Facade.cpp
	${CC} $(CFLAGS) -c $<
libtmfacade.so: tmfacade.o
		$(CC) --shared -o $@ $<
transitionprocessor.o: Transition_Processor.cpp
	${CC} $(CFLAGS) -c $<
libtransitionprocessor.so: transitionprocessor.o
		$(CC) --shared -o $@ $<
tape.o: Tape.cpp
	${CC} $(CFLAGS) -c $<
libtape.so: tape.o
		$(CC) --shared -o $@ $<
main.o: main.cpp
	${CC} $(CFLAGS) -c $<
TM: main.o libtm.so libparser.so libvalidator.so libtmdefinition.so libtransition.so libtmfacade.so libtransitionprocessor.so libtape.so
	$(CC) -o TM libtm.so libparser.so libvalidator.so libtmdefinition.so libtransition.so libtmfacade.so libtransitionprocessor.so libtape.so main.o -L. -lpuz $(LDFLAGS)
clean:
	-rm TM
	-rm *.o
	-rm *.so
