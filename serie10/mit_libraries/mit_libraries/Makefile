CC=g++

output: out/serie10.o classes
	$(CC) out/*.o -o serie10

out/serie10.o: serie10.cpp
	$(CC) -c serie10.cpp -o out/serie10.o

classes: headers/*.h classes/*.cpp
	$(CC) -c classes/*.cpp
	mv *.o out/

clean:
	rm out/*.o out/serie10
