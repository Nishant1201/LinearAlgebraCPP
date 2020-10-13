Vector.o : Vector.cpp Vector.hpp
	g++ -Wall -c Vector.cpp

Matrix.o : Matrix.cpp Matrix.hpp Vector.hpp
	g++ -Wall -c Matrix.cpp

LinearSystem.o : LinearSystem.cpp LinearSystem.hpp Matrix.hpp Vector.hpp
	g++ -Wall -c LinearSystem.cpp

LinearSystemTest.o : LinearSystemTest.cpp Matrix.hpp Vector.hpp
	g++ -Wall -c LinearSystemTest.cpp

exec : LinearSystemTest.o LinearSystem.o Matrix.o Vector.o
	g++ -o exec -O3 LinearSystemTest.o LinearSystem.o Matrix.o Vector.o

#main.o : main.cpp Matrix.hpp Vector.hpp
#	g++ -Wall -c main.cpp
#
#exec : main.o Matrix.o Vector.o
#	g++ -o exec -O3 main.o Matrix.o Vector.o
