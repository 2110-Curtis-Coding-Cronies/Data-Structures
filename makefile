CC = g++
CFLAGS = -I/src
target = HashTables
objects = src/HashTables/main.o src/HashTables/HashTable.o

# build executable
HashTableMake: $(objects)
	$(CC) -o $(target) $(objects)

# delete object files and target executable
.PHONY: clean
clean:
	rm $(target) $(objects)