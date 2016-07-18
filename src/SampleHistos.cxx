/////////////////////////////////////////////////////////////////////
//                         SampleHistos.cxx                        //
//=================================================================//
//                                                                 //
// Contains functions for producing th analysis's histograms       //
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
   TH1F* EMTFtrackPtHist = new TH1F("EMTFtrackPtHist","",100,0,800);
   setHistTitles(EMTFtrackPtHist,"P_{T} [GeV/c]","Events");
   EMTFtrackPtHist->Sumw2();

   // Pt for unmatched CSCTF tracks
   TH1F* CSCTFtrackPtHist = new TH1F("CSCTFtrackPtHist","",100,0,800);
   setHistTitles(CSCTFtrackPtHist,"P_{T} [GeV/c]","Events");
   CSCTFtrackPtHist->Sumw2();

   // Eta for unmatched EMTF tracks
   TH1F* EMTFtrackEtaHist = new TH1F("EMTFtrackEtaHist","",100,0,6);
   setHistTitles(EMTFtrackEtaHist,"#eta","Events");
   EMTFtrackEtaHist->Sumw2();

   // Eta for unmatched CSCTF tracks
   TH1F* CSCTFtrackEtaHist = new TH1F("CSCTFtrackEtaHist","",100,0,6);
   setHistTitles(CSCTFtrackEtaHist,"#eta","Events");
   CSCTFtrackEtaHist->Sumw2();

   // Mode for unmatched EMTF tracks
   TH1F* EMTFtrackModeHist = new TH1F("EMTFtrackModeHist","",100,0,30);
   setHistTitles(EMTFtrackModeHist,"Mode","Events");
   EMTFtrackModeHist->Sumw2();

   // Mode for unmatched CSCTF tracks
   //TH1F* CSCTFtrackModeHist = new TH1F("CSCTFtrackModeHist","",100,0,30);
   //setHistTitles(CSCTFtrackModeHist,"Mode","Events");
   //CSCTFtrackModeHist->Sumw2();

   ////////////////////////////////////////////////////////////////////
   // Fill Histograms--------------------------------------------------
   ////////////////////////////////////////////////////////////////////

   unsigned reportEach = 1000000;

   // Event loop
   for(unsigned i=0; i<sample->nEvents; i++)
   {
	if(i % reportEach == 0) std::cout << "Event: " << i << std::endl;

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
	    	//CSCTFtrackModeHist->Fill();
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
   //CSCTFtrackModeHist->Write();
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
