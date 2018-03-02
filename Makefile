all: nn3 generador testnn2

INCLUDE=/usr/local/include/opencv
LIBS=

dataReader.o:	dataReader.cpp
	g++ -c dataReader.cpp

main.o: main.cpp
	g++ -c main.cpp
	
test.o: test.cpp
	g++ -c test.cpp
		
neuralNetwork.o:	neuralNetwork.cpp
	g++ -c neuralNetwork.cpp
	
neuralNetworkTrainer.o: 	neuralNetworkTrainer.cpp
	g++ -c neuralNetworkTrainer.cpp
	
nn3: dataReader.o main.o neuralNetwork.o neuralNetworkTrainer.o
	g++ -o nn3 dataReader.o main.o neuralNetwork.o neuralNetworkTrainer.o

testnn2: dataReader.o test.o neuralNetwork.o 
	g++ -o testnn2 dataReader.o test.o neuralNetwork.o

generador: generador.cpp
	g++ generador.cpp -o generador