//Cuts.h

#ifndef ADD_CUTS
#define ADD_CUTS

#include "TMath.h"
#include "Sample.h"
#include <vector>
#include <iostream>

class Cuts
{
    public:
	Cuts();
	Cuts(Sample* insample);

	// Save the sample variable
	Sample* sample;

	// Define delta R, the variable which we will cut on
	float deltaR;

	// Boolean variables that state whether an event passes a selection criteria
	std::vector<std::vector<bool> > isMatched;

	// Selection criteria, each void function contains a different set of cuts
	void Matched(int i);
	// Function for calculating delta R
	void DeltaR(int i);
};
#endif
