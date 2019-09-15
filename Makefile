all:
	g++ --std=c++11 -o main ./main.cpp ./notification.cpp -I ./ -lpthread
clean:
	rm -rf ./main

