all: nn3 generador testnn2

INCLUDE=/usr/local/include/opencv
LIBS=

dataReader.o:	dataReader.cpp
	g++ -O3 -c dataReader.cpp

main.o: main.cpp
	g++ -O3 -c main.cpp
	
test.o: test.cpp
	g++ -c test.cpp
		
neuralNetwork.o:	neuralNetwork.cpp
	g++ -O3 -c neuralNetwork.cpp
	
neuralNetworkTrainer.o: 	neuralNetworkTrainer.cpp
	g++ -O3 -c neuralNetworkTrainer.cpp
	
nn3: dataReader.o main.o neuralNetwork.o neuralNetworkTrainer.o
	g++ -O3 -o nn3 dataReader.o main.o neuralNetwork.o neuralNetworkTrainer.o

testnn2: dataReader.o test.o neuralNetwork.o 
	g++ -o testnn2 dataReader.o test.o neuralNetwork.o

generador: generador.cpp
	g++ generador.cpp -o generador
