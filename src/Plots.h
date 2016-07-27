// Plots.h

#ifndef PLOTS
#define PLOTS

#include <vector>
#include <iostream>

#include "Sample.h"
#include "SampleHistos.h"
#include "../selection/Cuts.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TString.h"

class Plots
{
   public:
	Plots();
	Plots(Sample* insample, Cuts* cut, SampleHistos inhistos, TString cutName);

	Sample* sample;
	SampleHistos* histos,

   protected:
	TFile* file;  // output file with histograms

};

#endif
