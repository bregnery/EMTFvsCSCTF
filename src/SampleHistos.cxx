/////////////////////////////////////////////////////////////////////
//                         SampleHistos.cxx                        //
//=================================================================//
//                                                                 //
// Contains functions for producing the analysis's histograms      //
/////////////////////////////////////////////////////////////////////

#include "SampleHistos.h"

///////////////////////////////////////////////////////////////////////
//_________________________Sample Histograms_________________________//
///////////////////////////////////////////////////////////////////////

SampleHistos::SampleHistos(){}

///////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////

SampleHistos::SampleHistos(Sample* sample, Cuts* cut, TString cutName)
{
   using namespace std;

   ///////////////////////////////////////////////////////////////////
   // Output file-----------------------------------------------------
   ///////////////////////////////////////////////////////////////////

   file = new TFile(sample->name + "_" + cutName + "_Hist.root", "RECREATE");
   file->cd();

   ///////////////////////////////////////////////////////////////////
   // Histograms------------------------------------------------------
   ///////////////////////////////////////////////////////////////////

   // Pt for unmatched EMTF tracks
   TH1F* EMTFtrackPtHist = new TH1F("EMTFtrackPtHist","",30,0,350);
   setHistTitles(EMTFtrackPtHist,"P_{T} [GeV/c]","Events");
   EMTFtrackPtHist->Sumw2();

   // Pt for unmatched CSCTF tracks
   TH1F* CSCTFtrackPtHist = new TH1F("CSCTFtrackPtHist","",30,0,350);
   setHistTitles(CSCTFtrackPtHist,"P_{T} [GeV/c]","Events");
   CSCTFtrackPtHist->Sumw2();

   // Eta for unmatched EMTF tracks
   TH1F* EMTFtrackEtaHist = new TH1F("EMTFtrackEtaHist","",20,0,6);
   setHistTitles(EMTFtrackEtaHist,"#eta","Events");
   EMTFtrackEtaHist->Sumw2();

   // Eta for unmatched CSCTF tracks
   TH1F* CSCTFtrackEtaHist = new TH1F("CSCTFtrackEtaHist","",20,0,6);
   setHistTitles(CSCTFtrackEtaHist,"#eta","Events");
   CSCTFtrackEtaHist->Sumw2();

   // Mode for unmatched EMTF tracks
   TH1F* EMTFtrackModeHist = new TH1F("EMTFtrackModeHist","",30,0,30);
   setHistTitles(EMTFtrackModeHist,"Mode","Events");
   EMTFtrackModeHist->Sumw2();

   // Mode for unmatched CSCTF tracks
   TH1F* CSCTFtrackModeHist = new TH1F("CSCTFtrackModeHist","",30,0,30);
   setHistTitles(CSCTFtrackModeHist,"Mode","Events");
   CSCTFtrackModeHist->Sumw2();

   // CSCTF mode vs. EMTF mode for matched tracks
   TH2F* ModeComparisonHist = new TH2F("ModeComparisonHist","",20,0,20,20,0,20); //bins, xmin, xmax, bins, ymin, ymax
   ModeComparisonHist->GetXaxis()->SetTitle("EMTF Mode");
   ModeComparisonHist->GetYaxis()->SetTitle("CSCTF Mode");
   ModeComparisonHist->Sumw2();

   // CSCTF Pt vs. EMTF Pt for mathced tracks
   TH2F* PtComparisonHist = new TH2F("PtComparisonHist","",30,0,300,30,0,300); //bins, xmin, xmax, bins, ymin, ymax
   PtComparisonHist->GetXaxis()->SetTitle("EMTF P_{T} [GeV/c]");
   PtComparisonHist->GetYaxis()->SetTitle("CSCTF P_{T} [GeV/c]");
   PtComparisonHist->Sumw2();

   // The difference in the number of tracks for EMTF and CSCTF
   TH1F* trackNumDiffHist = new TH1F("trackNumDiffHist","",10,0,10);
   setHistTitles(trackNumDiffHist, "Number of Tracks", "Events");
   trackNumDiffHist->Sumw2();

   ////////////////////////////////////////////////////////////////////
   // Fill Histograms--------------------------------------------------
   ////////////////////////////////////////////////////////////////////

   unsigned reportEach = 1000000;

   // Event loop
   for(unsigned i=0; i<sample->nEvents; i++)
   {
	if(i % reportEach == 0) std::cout << "Event: " << i << std::endl;

	// Fill plots that don't depend on matching
	sample->getEntry(i);
	if(getTrackNumDiff(sample->vars.trkPt->size(), sample->vars.csctf_trkPt->size()) < 100) {
	     trackNumDiffHist->Fill(getTrackNumDiff(sample->vars.trkPt->size(), sample->vars.csctf_trkPt->size()));
	}

	// Fill not matched EMTF tracks
	for(unsigned j=0; j<cut->EMisMatched[i].size(); j++)
	{
	   // Test if event is matched
	   if(cut->EMisMatched[i][j] == false)
	   {
	        sample->getEntry(i);
	        // Fill Histograms
	    	EMTFtrackPtHist->Fill(sample->vars.trkPt->at(j));
	    	EMTFtrackEtaHist->Fill(sample->vars.trkEta->at(j));
	    	EMTFtrackModeHist->Fill(sample->vars.trkMode->at(j));
            }
	}

	// Fill not matched CSCTF tracks
	for(unsigned j=0; j<cut->CSCisMatched[i].size(); j++)
	{
	   // Test if event is matched
	   if(cut->CSCisMatched[i][j] == false)
	   {
	        sample->getEntry(i);
	        // Fill Histograms
	    	CSCTFtrackPtHist->Fill(sample->vars.csctf_trkPt->at(j));
	    	CSCTFtrackEtaHist->Fill(sample->vars.csctf_trkEta->at(j));
	    	CSCTFtrackModeHist->Fill(sample->vars.csctf_trkMode->at(j));
            }
	}
	
	// Fill matched Histograms
	for(unsigned j=0; j<cut->EMisMatched[i].size(); j++)
	{
	    // Find matched tracks
	    if(cut->EMisMatched[i][j] == true)
	    {
		sample->getEntry(i);
		
		// Find the corresponding CSC track
		for(unsigned k=0; k < sample->vars.csctf_trkPt->size(); k++)
		{
		     cut->DeltaR(j,k);
		     if(cut->deltaR <= 0.2){
			// Fill Histograms
			ModeComparisonHist->Fill(sample->vars.trkMode->at(j), sample->vars.csctf_trkMode->at(k));
			PtComparisonHist->Fill(sample->vars.trkPt->at(j),sample->vars.csctf_trkPt->at(k)); // xvariable, yvariable
		     }
		}
	     }
	}

   }
  
   /////////////////////////////////////////////////////////////////////
   // Write Histograms--------------------------------------------------
   /////////////////////////////////////////////////////////////////////

   EMTFtrackPtHist->Write();
   CSCTFtrackPtHist->Write();
   EMTFtrackEtaHist->Write();
   CSCTFtrackEtaHist->Write();
   EMTFtrackModeHist->Write();
   CSCTFtrackModeHist->Write();
   ModeComparisonHist->Write();
   PtComparisonHist->Write();
   trackNumDiffHist->Write();
   file->Close();
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

void SampleHistos::setHistTitles(TH1F* hist, TString xtitle, TString ytitle)
{
  hist->GetXaxis()->SetTitle(xtitle);
  hist->GetYaxis()->SetTitle(ytitle);
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

float SampleHistos::getTrackNumDiff(std::size_t emTracks, std::size_t cscTracks)
{
  
	// Calculate the difference in the number of tracks per event between CSCTF and EMTF
	float trackNumDiff = 0;
	trackNumDiff = std::abs(std::abs(emTracks) - std::abs(cscTracks) ); // fabs is an absolute value for floats
	
	// Debugging
	//std::cout << "Difference of Number of tracks: " << trackNumDiff << std::endl;
	//if(trackNumDiff > 100){
	//   std::cout << "EMTF tracks: " << emTracks << " CSCTF tracks: " << cscTracks << std::endl;
	//}
	
	return trackNumDiff;
}

