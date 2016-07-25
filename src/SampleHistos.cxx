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

SampleHistos::SampleHistos(Sample* insample, Cuts* cut, TString cutName)
{
   using namespace std;

   sample = insample;

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
   EMTFtrackPtHist->SetStats(1);
   EMTFtrackPtHist->Sumw2();

   // Pt for matched EMTF tracks
   TH1F* matchEMTFtrackPtHist = new TH1F("matchEMTFtrackPtHist","",30,0,350);
   setHistTitles(matchEMTFtrackPtHist,"P_{T} [GeV/c]","Events");
   matchEMTFtrackPtHist->SetStats(1);
   matchEMTFtrackPtHist->Sumw2();

   // Pt for unmatched CSCTF tracks
   TH1F* CSCTFtrackPtHist = new TH1F("CSCTFtrackPtHist","",30,0,350);
   setHistTitles(CSCTFtrackPtHist,"P_{T} [GeV/c]","Events");
   CSCTFtrackPtHist->SetStats(1);
   CSCTFtrackPtHist->Sumw2();

   // Pt for matched CSCTF tracks
   TH1F* matchCSCTFtrackPtHist = new TH1F("matchCSCTFtrackPtHist","",30,0,350);
   setHistTitles(matchCSCTFtrackPtHist,"P_{T} [GeV/c]","Events");
   matchCSCTFtrackPtHist->SetStats(1);
   matchCSCTFtrackPtHist->Sumw2();

   // Eta for unmatched EMTF tracks
   TH1F* EMTFtrackEtaHist = new TH1F("EMTFtrackEtaHist","",20,0,6);
   setHistTitles(EMTFtrackEtaHist,"#eta","Events");
   EMTFtrackEtaHist->SetStats(1);
   EMTFtrackEtaHist->Sumw2();

   // Eta for matched EMTF tracks
   TH1F* matchEMTFtrackEtaHist = new TH1F("matchEMTFtrackEtaHist","",20,0,6);
   setHistTitles(matchEMTFtrackEtaHist,"#eta","Events");
   matchEMTFtrackEtaHist->SetStats(1);
   matchEMTFtrackEtaHist->Sumw2();

   // Eta for unmatched CSCTF tracks
   TH1F* CSCTFtrackEtaHist = new TH1F("CSCTFtrackEtaHist","",20,0,6);
   setHistTitles(CSCTFtrackEtaHist,"#eta","Events");
   CSCTFtrackEtaHist->SetStats(1);
   CSCTFtrackEtaHist->Sumw2();

   // Eta for matched CSCTF tracks
   TH1F* matchCSCTFtrackEtaHist = new TH1F("matchCSCTFtrackEtaHist","",20,0,6);
   setHistTitles(matchCSCTFtrackEtaHist,"#eta","Events");
   matchCSCTFtrackEtaHist->SetStats(1);
   matchCSCTFtrackEtaHist->Sumw2();

   // Mode for unmatched EMTF tracks
   TH1F* EMTFtrackModeHist = new TH1F("EMTFtrackModeHist","",30,0,30);
   setHistTitles(EMTFtrackModeHist,"Mode","Events");
   EMTFtrackModeHist->SetStats(1);
   EMTFtrackModeHist->Sumw2();

   // Mode for matched EMTF tracks
   TH1F* matchEMTFtrackModeHist = new TH1F("matchEMTFtrackModeHist","",30,0,30);
   setHistTitles(matchEMTFtrackModeHist,"Mode","Events");
   matchEMTFtrackModeHist->SetStats(1);
   matchEMTFtrackModeHist->Sumw2();

   // Mode for unmatched CSCTF tracks
   TH1F* CSCTFtrackModeHist = new TH1F("CSCTFtrackModeHist","",30,0,30);
   setHistTitles(CSCTFtrackModeHist,"Mode","Events");
   CSCTFtrackModeHist->SetStats(1);
   CSCTFtrackModeHist->Sumw2();

   // Mode for matched CSCTF tracks
   TH1F* matchCSCTFtrackModeHist = new TH1F("matchCSCTFtrackModeHist","",30,0,30);
   setHistTitles(matchCSCTFtrackModeHist,"Mode","Events");
   matchCSCTFtrackModeHist->SetStats(1);
   matchCSCTFtrackModeHist->Sumw2();

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
   trackNumDiffHist->SetStats(1);
   trackNumDiffHist->Sumw2();

   // Pt resolution for the EMTF
   TH1F* recoEMresoHist = new TH1F("recoEMresoHist","",40,-20,20);
   setHistTitles(recoEMresoHist, "P_{T} Resolution","Events");
   recoEMresoHist->SetStats(1);
   recoEMresoHist->Sumw2();

   // Pt resolution for the CSCTF
   TH1F* recoCSCresoHist = new TH1F("recoCSCresoHist","",40,-20,20);
   setHistTitles(recoCSCresoHist, "P_{T} Resolution","Events");
   recoCSCresoHist->SetStats(1);
   recoCSCresoHist->Sumw2();

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

	// Fill matched EMTF tracks
	for(unsigned j=0; j<cut->EMisMatched[i].size(); j++)
	{
	   // Test if event is matched
	   if(cut->EMisMatched[i][j] == true)
	   {
	        sample->getEntry(i);
	        // Fill Histograms
	    	matchEMTFtrackPtHist->Fill(sample->vars.trkPt->at(j));
	    	matchEMTFtrackEtaHist->Fill(sample->vars.trkEta->at(j));
	    	matchEMTFtrackModeHist->Fill(sample->vars.trkMode->at(j));
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

	// Fill matched CSCTF tracks
	for(unsigned j=0; j<cut->CSCisMatched[i].size(); j++)
	{
	   // Test if event is matched
	   if(cut->CSCisMatched[i][j] == true)
	   {
	        sample->getEntry(i);
	        // Fill Histograms
	    	matchCSCTFtrackPtHist->Fill(sample->vars.csctf_trkPt->at(j));
	    	matchCSCTFtrackEtaHist->Fill(sample->vars.csctf_trkEta->at(j));
	    	matchCSCTFtrackModeHist->Fill(sample->vars.csctf_trkMode->at(j));
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

	// Fill reco and EMTF matched Histograms
	for(unsigned j=0; j<cut->recoEMisMatched[i].size(); j++)
	{
	    // Find matched tracks
	    if(cut->recoEMisMatched[i][j] == true)
	    {
		sample->getEntry(i);
		
		// Find the corresponding reco track
		for(unsigned k=0; k < sample->vars.recoPt->size(); k++)
		{
		     cut->recoEMDeltaR(j,k);
		     if(cut->deltaR <= 0.2){
			// Fill Histograms
			recoEMresoHist->Fill(getEMPtResolution(j,k) );
		     }
		}
	     }
	}

	// Fill reco and CSCTF matched Histograms
	for(unsigned j=0; j<cut->recoCSCisMatched[i].size(); j++)
	{
	    // Find matched tracks
	    if(cut->recoCSCisMatched[i][j] == true)
	    {
		sample->getEntry(i);
		
		// Find the corresponding reco track
		for(unsigned k=0; k < sample->vars.recoPt->size(); k++)
		{
		     cut->recoCSCDeltaR(j,k);
		     if(cut->deltaR <= 0.2){
			// Fill Histograms
			recoCSCresoHist->Fill(getCSCPtResolution(j,k) );
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

   matchEMTFtrackPtHist->Write();
   matchCSCTFtrackPtHist->Write();
   matchEMTFtrackEtaHist->Write();
   matchCSCTFtrackEtaHist->Write();
   matchEMTFtrackModeHist->Write();
   matchCSCTFtrackModeHist->Write();

   ModeComparisonHist->Write();
   PtComparisonHist->Write();

   trackNumDiffHist->Write();

   recoEMresoHist->Write();
   recoCSCresoHist->Write();

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

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

float SampleHistos::getEMPtResolution(unsigned j, unsigned k)
{
	// Calculate the Pt Resolution 
	float resolutionPt = 0;
	resolutionPt = (1/(sample->vars.trkPt->at(j)) - 1/(sample->vars.recoPt->at(k)) ) / (1/(sample->vars.recoPt->at(k)) );
	return resolutionPt;
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

float SampleHistos::getCSCPtResolution(unsigned j, unsigned k)
{
	// Calculate the Pt Resolution 
	float resolutionPt = 0;
	resolutionPt = (1/(sample->vars.csctf_trkPt->at(j)) - 1/(sample->vars.recoPt->at(k)) ) / (1/(sample->vars.recoPt->at(k)) );
	return resolutionPt;
}
