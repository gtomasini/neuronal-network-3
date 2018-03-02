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
	string icsv("input.csv");

	if (argc>1){
		icsv=argv[1];//nombre de archivo csv
		in=atoi(argv[2]);//numero de entradas
		on=atoi(argv[3]);//numero de salidas
	}
	else{
		cout<<"escriba "<<argv[0]<<" archivo.csv #entradas #salidas"<<endl;
		return 0;
	}
	
	//create data set reader and load data file
	dataReader d;
	d.loadDataFile( icsv.c_str(), in, on);
	d.setCreationApproach( STATIC, 10 );	

	//create neural network
	neuralNetwork nn( in, 10, on);
	nn.loadWeights( "weights.csv" );
	
	//get validation set accuracy and MSE
	double validationSetAccuracy_ = nn.getSetAccuracy( d.getAllDataEntries() );
	double validationSetMSE_ = nn.getSetMSE( d.getAllDataEntries() );

	cout << "Validation Set Accuracy: " << validationSetAccuracy_ << " Validation Set MSE: " << validationSetMSE_ << endl;
			
	cout << endl << endl << "-- END OF PROGRAM --" << endl;
	//char c; cin >> c;
}
