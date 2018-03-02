/*******************************************************************
* Neural Network Training Example
* ------------------------------------------------------------------
* Bobby Anguelov - takinginitiative.wordpress.com (2008)
* MSN & email: banguelov@cs.up.ac.za
*********************************************************************/

//standard libraries
#include <iostream>
#include <ctime>
#include <stdlib.h>

//custom includes
#include "neuralNetwork.h"
#include "neuralNetworkTrainer.h"

//use standard namespace
using namespace std;

int
main( int argc, char *argv[] ){		
	//seed random number generator
	srand( (unsigned int) time(0) );
	int in=16, on=3;
	int layers(1);
	int hiddenNeurons(5);
	string icsv("input.csv");

	if (argc == 7){
		icsv=argv[1];//nombre de archivo csv
		in=atoi(argv[2]);//numero de entradas
		on=atoi(argv[3]);//numero de salidas
		layers=atoi(argv[4]);//numero de capas
		hiddenNeurons=atoi(argv[6]);
		
	}
	else{
		cout<<"escriba "<<argv[0]
			<<" archivo.csv #entradas #salidas"
			<<" #capas #neuronas-entrada #neuronas-ocultas"<<endl;
		return 0;
	}
	
	//create data set reader and load data file
	dataReader d;
	d.loadDataFile( icsv.c_str(), in, on);
	d.setCreationApproach( STATIC, 10 );	

	//create neural network
	neuralNetwork nn( atoi(argv[5]), hiddenNeurons, on, layers);

	//create neural network trainer
	neuralNetworkTrainer nT( &nn );
	nT.setTrainingParameters( 0.001, 0.9, false);
	nT.setStoppingConditions( 1000, 90);
	nT.enableLogging( "log.csv", 1 );
	
	//train neural network on data sets
	for (int i=0; i < d.getNumTrainingSets(); i++ )
		nT.trainNetwork( d.getTrainingDataSet() );
	
	//save the weights
	nn.saveWeights( "weights.csv" );
		
	cout << endl << endl << "-- END OF PROGRAM --" << endl;
	//char c; cin >> c;
}
