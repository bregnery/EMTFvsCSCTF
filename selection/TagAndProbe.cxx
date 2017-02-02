/////////////////////////////////////////////////////////////////////
//                         TagAndProbe.cxx                         //
//=================================================================//
//                                                                 //
// Contains functions for producing the analysis's Tag and Probe   //
// method and efficency histograms                                 //
/////////////////////////////////////////////////////////////////////

#include "TagAndProbe.h"

///////////////////////////////////////////////////////////////////////
//_________________________Tag And Probe_____________________________//
///////////////////////////////////////////////////////////////////////

TagAndProbe::TagAndProbe(){}

///////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////

TagAndProbe::TagAndProbe(Sample* insample, Cuts* cut, TString cutName)
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

   // EMTF Matched Pt
   TH1F* EMTFrecoMatchPtHist = new TH1F("EMTFrecoMatchPtHist", "EMTF Matched Reconstructed Muon P_{T}",30,0,350);
   setHistTitles(EMTFrecoMatchPtHist,"P_{T} [GeV/c]","Events");
   EMTFrecoMatchPtHist->SetStats(1);
   EMTFrecoMatchPtHist->Sumw2();

   // EMTF Not Matched Pt
   TH1F* EMTFrecoNoMatchPtHist = new TH1F("EMTFrecoNoMatchPtHist", "EMTF Unmatched Reconstructed Muon P_{T}",30,0,350);
   setHistTitles(EMTFrecoNoMatchPtHist,"P_{T} [GeV/c]","Events");
   EMTFrecoNoMatchPtHist->SetStats(1);
   EMTFrecoNoMatchPtHist->Sumw2();

   // EMTF Matched + Unmatched Pt
   TH1F* EMTFrecoSumPtHist = new TH1F("EMTFrecoSumPtHist", "EMTF Matched + Unmatched Reconstructed Muon P_{T}",30,0,350);
   setHistTitles(EMTFrecoSumPtHist,"P_{T} [GeV/c]","Events");
   EMTFrecoSumPtHist->SetStats(1);
   EMTFrecoSumPtHist->Sumw2();

   // EMTF Efficiency vs Pt
   TH1F* EMTFrecoEfficiencyPtHist = new TH1F("EMTFrecoEfficiencyPtHist", "EMTF Efficency vs Muon P_{T}",30,0,350);
   setHistTitles(EMTFrecoEfficiencyPtHist,"P_{T} [GeV/c]","Efficency");
   EMTFrecoEfficiencyPtHist->SetStats(1);
   EMTFrecoEfficiencyPtHist->Sumw2();

   ////////////////////////////////////////////////////////////////////
   // Fill Histograms--------------------------------------------------
   ////////////////////////////////////////////////////////////////////

   unsigned reportEach = 1000000;

   // Event loop
   for(unsigned eventNum=0; eventNum<sample->nEvents; eventNum++)
   {
	if(eventNum % reportEach == 0) std::cout << "Event: " << eventNum << std::endl;
	sample->getEntry(eventNum);

	if(sample->RecoMuon->pt.size() >= 2){
	    // Find an event with a matched muon
	    for(unsigned trackNum=0; trackNum < sample->EMTF->muonEta.size(); trackNum++)
            {	
                cut->recoEMDeltaR(trackNum,0);
                if(cut->deltaR <= 0.2){
	           // Tag the Muon and Probe the event for more muons
	           Probe(EMTFrecoMatchPtHist, EMTFrecoNoMatchPtHist, trackNum, cut);
                }
            }
        }  

   }  

   // Add the histograms together
   EMTFrecoSumPtHist->Add(EMTFrecoMatchPtHist, EMTFrecoNoMatchPtHist);
   
   // Divide the matched histogram by the sum
   EMTFrecoEfficiencyPtHist->Divide(EMTFrecoMatchPtHist, EMTFrecoSumPtHist);
 
   /////////////////////////////////////////////////////////////////////
   // Save Class Vectors------------------------------------------------
   /////////////////////////////////////////////////////////////////////

   histo1D.push_back(EMTFrecoMatchPtHist);
   histo1D.push_back(EMTFrecoNoMatchPtHist);
   histo1D.push_back(EMTFrecoSumPtHist);
   histo1D.push_back(EMTFrecoEfficiencyPtHist);

   /////////////////////////////////////////////////////////////////////
   // Write Histograms--------------------------------------------------
   /////////////////////////////////////////////////////////////////////
   
   for(std::vector<TH1F*>::const_iterator itr = histo1D.begin(); itr != histo1D.end(); itr++){
	(*itr)->Write();
   }

   //file->Close();
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

void TagAndProbe::Probe(TH1F* matchHist, TH1F* nomatchHist, int EMTFtag, Cuts* cut)
{
    // Probe to see if there is a match for the second muon
    bool isMatched = false;
    for(unsigned trackNum=0; trackNum < sample->EMTF->muonEta.size(); trackNum++)
    {	
        cut->recoEMDeltaR(trackNum, 1); // Look for a second (indexed as 1) matching reco muon
        if(cut->deltaR <= 0.2 && trackNum != EMTFtag){
	    isMatched = true;
		  
            //Fill Matched Histogram 
            matchHist->Fill(sample->RecoMuon->pt[1]);
        }
    } 
    
    if(isMatched == false){
        //Fill Unmatched Histogram
   	nomatchHist->Fill(sample->RecoMuon->pt[1]);
    }
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

void TagAndProbe::setHistTitles(TH1F* hist, TString xtitle, TString ytitle)
{
  hist->GetXaxis()->SetTitle(xtitle);
  hist->GetYaxis()->SetTitle(ytitle);
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

void TagAndProbe::closeFile()
{
	file->Close();
}
