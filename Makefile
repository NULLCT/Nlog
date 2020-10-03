PATH=

main:
	clang++ -std=c++17 main.cpp -o ${PATH}main

run:
	./bin/main

clean:
	rm bin/*
