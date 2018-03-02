/*******************************************************************
 * Basic Feed Forward Neural Network Class
 * ------------------------------------------------------------------
 * Bobby Anguelov - takinginitiative.wordpress.com (2008)
 * MSN & email: banguelov@cs.up.ac.za
 ********************************************************************/

#ifndef NNetwork
#define NNetwork

#include "dataReader.h"

class neuralNetworkTrainer;

class neuralNetwork {
    //class members
    //--------------------------------------------------------------------------------------------
private:

    //number of neurons
    int nInput_, nHidden_, nOutput_, nHiddenLayers_;

    //neurons
    double *inputNeurons_; //	inputNeurons_[nInput_+1]
    double **hiddenNeurons_; //	hiddenNeurons_[nHiddenLayers_][nHidden_+1]
    double *outputNeurons_; //	output_[nOutput_]

    //weights
    double **wInputHidden_;
    double ***wHiddenHidden_;
    double **wHiddenOutput_;

    //Friends
    //--------------------------------------------------------------------------------------------
    friend class neuralNetworkTrainer;

    //public methods
    //--------------------------------------------------------------------------------------------

public:

    //constructor & destructor
    neuralNetwork(int inputsNum, int hiddenNeuNum, int outputsNum, int nHiddelLayers = 1);
    ~neuralNetwork();

    //weight operations
    bool loadWeights(const char* inputFilename);
    bool saveWeights(const char* outputFilename);
    int* feedForwardPattern(const std::vector<double> &pattern);
    double getSetAccuracy(const std::vector<dataEntry *>& set);
    double getSetMSE(const std::vector<dataEntry *>& set);

    //private methods
    //--------------------------------------------------------------------------------------------

private:
    void initializeWeights();
    inline double activationFunction(double x);
    int clampOutput(double x);
    void feedForward(const std::vector<double> &pattern);
};

#endif
