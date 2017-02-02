// Plots.h

#ifndef ADD_PLOTS
#define ADD_PLOTS

#include <vector>
#include <iostream>

#include "Sample.h"
#include "SampleHistos.h"
#include "../selection/Cuts.h"
#include "../selection/TagAndProbe.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TString.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TFrame.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TROOT.h"

class Plots
{
   public:
	Plots();
	Plots(Sample* insample, Cuts* cut, TagAndProbe* inhistos, TString cutName);

	Sample* sample;
	TagAndProbe* histos;
	std::vector<TCanvas*> canvas;

	void saveCanvas();
};

#endif
