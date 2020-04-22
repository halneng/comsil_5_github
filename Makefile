main :  main.o
	g++ -o main main.o
main.o : main.cpp
	g++ -c -o main.o main.cpp

main : 

.PHONY : clean
clean :
	rm *.o a.out
