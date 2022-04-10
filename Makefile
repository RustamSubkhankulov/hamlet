CC = gcc 

OBJ = obj/hamlet.o obj/logs.o obj/general.o obj/main.o

all: global

global: $(OBJ) 
	$(CC) $(OBJ) -o hamlet -fsanitize=bounds -fsanitize=address

obj/hamlet.o: src/hamlet/hamlet.cpp src/global_conf.h src/hamlet/hamlet.h src/hamlet/hamlet_conf.h
	$(CC) src/hamlet/hamlet.cpp -c -o obj/hamlet.o

obj/logs.o: src/global_conf.h src/logs/errors_and_logs.cpp src/logs/errors_and_logs.h src/logs/errors.h src/logs/log_definitions.h src/include/errors.txt
	$(CC) src/logs/errors_and_logs.cpp -c -o obj/logs.o 

obj/general.o: src/global_conf.h src/general/general.cpp src/general/general.h 
	$(CC) src/general/general.cpp -c -o obj/general.o

obj/main.o: src/main.cpp src/global_conf.h
	$(CC) src/main.cpp -c -o obj/main.o 

.PNONY: cleanup 

cleanup:
	rm obj/*.o 
