all:
	g++ my_inf_arith.cpp usefulfunctions.cpp main.cpp -o my_inf_arith

libmy_inf_arith:
	g++ my_inf_arith.cpp usefulfunctions.cpp main.cpp -o my_inf_arith.o
	ar rcs libmy_inf_arith.a my_inf_arith.o
	rm my_inf_arith.o

clean:
	rm -f my_inf_arith libmy_inf_arith.a *.o
	
