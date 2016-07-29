// SampleHistos.h

#ifndef HISTOS
#define HISTOS

#include <vector>
#include <iostream>

#include "Sample.h"
#include "../selection/Cuts.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TString.h"

class SampleHistos
{
   public:
	SampleHistos();
	SampleHistos(Sample* sample, Cuts* cut, TString cutName);

	Sample* sample;
	std::vector<std::vector<TH1F*> > histo1D;
	std::vector<TH2F*> histo2D;

	void setHistTitles(TH1F* hist, TString xtitle, TString ytitle);
	void closeFile();
	float getTrackNumDiff(std::size_t emTracks, std::size_t cscTracks);
	float getEMPtResolution(unsigned j, unsigned k);
	float getCSCPtResolution(unsigned j, unsigned k);

   protected:
	TFile* file;  // output file with histograms

};

#endif
