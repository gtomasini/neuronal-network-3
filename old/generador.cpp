#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>

using namespace std;
const float radio_=20;

const float x0_(20), y0_(25);
const float pi=3.14159265358979323846433832;
int
main( int argc, char *argv[] ) {
	if (argc <3 ){
		cout<<"escriba "<<argv[0]<<" archivo #muestras"<<endl;
		return -1;
	}
	
	ofstream myfile;
	myfile.open ( argv[1] );

	srand ((unsigned int) time(0) );

	//const float x0(20), y0(25);
	int ang=0;
	
	for (int i=0; i<atoi( argv[2] ); i++){
		float x=(float)rand()/float(RAND_MAX)*100;
		float y=(float)rand()/float(RAND_MAX)*100;

		float xx(x-x0_), yy(y-y0_);

		float d( sqrt(xx*xx+yy*yy));
		bool out(true);

		if ( d>radio_) out=false;

		myfile<<x<<","<<y<<","<<out<<endl;

		cout<<i<<") "<<x<<" "<<y<<" "<<d<<" "<<out<<endl;
		
		//angulo
		float radianes=ang*2*pi/360;
		
		d=radio_-2 +(float)rand()/float(RAND_MAX)*4;
		
		x=d*cos(radianes)+x0_;
		y=d*sin(radianes)+y0_;
		//float xx(x-x0), yy(y-y0);

		//float d( sqrt(xx*xx+yy*yy));
		//cout<<x<<" "<<y<<" "<<d<<endl;
		out=true;

		if ( d>radio_) out=false;

		cout<<"d:"<<d<<" x:"<<x<<" y:"<<y<<", out:"<<out<<endl;
		myfile<<x<<","<<y<<","<<out<<endl;
		ang++;
	}
	myfile.close();
}
