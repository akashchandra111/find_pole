CC := gcc
WARNING := -Wall
FILES := main.cpp src/find_pole.cpp

main : main.cpp 
	$(CC) $(WARNING) $^ -o $@

.PHONY : clean
clean:
	rm -r main
