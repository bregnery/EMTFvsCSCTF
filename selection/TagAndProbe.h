// TagAndProbe.h

#ifndef TAGANDPROBE
#define TAGANDPROBE

#include <vector>
#include <iostream>

#include "../src/Sample.h"
#include "Cuts.h"

#include "TH1F.h"
#include "TH1.h"
#include "TH2F.h"
#include "TAxis.h"
#include "TString.h"

class TagAndProbe
{
   public:
	TagAndProbe();
	TagAndProbe(Sample* sample, Cuts* cut, TString cutName);

	Sample* sample;
	std::vector<TH1F*> histo1D;
	std::vector<TH2F*> histo2D;

        void Probe(TH1F* matchHist, TH1F* nomatchHist, int EMTFtag, Cuts* cut);
	void setHistTitles(TH1F* hist, TString xtitle, TString ytitle);
	void closeFile();

   protected:
	TFile* file;  // output file with histograms

};

#endif
