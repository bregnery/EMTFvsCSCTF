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

   // CSCTF Matched Pt
   TH1F* CSCTFrecoMatchPtHist = new TH1F("CSCTFrecoMatchPtHist", "CSCTF Matched Reconstructed Muon P_{T}",30,0,350);
   setHistTitles(CSCTFrecoMatchPtHist,"P_{T} [GeV/c]","Events");
   CSCTFrecoMatchPtHist->SetStats(1);
   CSCTFrecoMatchPtHist->Sumw2();

   // CSCTF Not Matched Pt
   TH1F* CSCTFrecoNoMatchPtHist = new TH1F("CSCTFrecoNoMatchPtHist", "CSCTF Unmatched Reconstructed Muon P_{T}",30,0,350);
   setHistTitles(CSCTFrecoNoMatchPtHist,"P_{T} [GeV/c]","Events");
   CSCTFrecoNoMatchPtHist->SetStats(1);
   CSCTFrecoNoMatchPtHist->Sumw2();

   // CSCTF Matched + Unmatched Pt
   TH1F* CSCTFrecoSumPtHist = new TH1F("CSCTFrecoSumPtHist", "CSCTF Matched + Unmatched Reconstructed Muon P_{T}",30,0,350);
   setHistTitles(CSCTFrecoSumPtHist,"P_{T} [GeV/c]","Events");
   CSCTFrecoSumPtHist->SetStats(1);
   CSCTFrecoSumPtHist->Sumw2();

   // CSCTF Efficiency vs Pt
   TH1F* CSCTFrecoEfficiencyPtHist = new TH1F("CSCTFrecoEfficiencyPtHist", "CSCTF Efficency vs Muon P_{T}",30,0,350);
   setHistTitles(CSCTFrecoEfficiencyPtHist,"P_{T} [GeV/c]","Efficency");
   CSCTFrecoEfficiencyPtHist->SetStats(1);
   CSCTFrecoEfficiencyPtHist->Sumw2();

   ////////////////////////////////////////////////////////////////////
   // Fill Histograms--------------------------------------------------
   ////////////////////////////////////////////////////////////////////

   unsigned reportEach = 1000000;

   // Event loop
   for(unsigned eventNum=0; eventNum<sample->nEvents; eventNum++)
   {
	if(eventNum % reportEach == 0) std::cout << "Event: " << eventNum << std::endl;
	sample->getEntry(eventNum);

	if(sample->vars.recoPt.size() >= 2){
	    // Find an event with a EMTF matched muon
	    for(unsigned trackNum=0; trackNum < sample->vars.trkEta.size(); trackNum++)
            {	
                cut->recoEMDeltaR(trackNum,0);
                if(cut->deltaR <= 0.2){
	           // Tag the Muon and Probe the event for more muons
	           Probe(EMTFrecoMatchPtHist, EMTFrecoNoMatchPtHist, trackNum, cut);
                }
            }
	    // Find an event with a CSCTF matched muon
	    for(unsigned trackNum=0; trackNum < sample->vars.csctf_trkEta.size(); trackNum++)
            {	
                cut->recoCSCDeltaR(trackNum,0);
                if(cut->deltaR <= 0.2){
	           // Tag the Muon and Probe the event for more muons
	           CSCProbe(CSCTFrecoMatchPtHist, CSCTFrecoNoMatchPtHist, trackNum, cut);
                }
            }
        }  

   }  

   // Add the histograms together
   EMTFrecoSumPtHist->Add(EMTFrecoMatchPtHist, EMTFrecoNoMatchPtHist);
   CSCTFrecoSumPtHist->Add(CSCTFrecoMatchPtHist, CSCTFrecoNoMatchPtHist);
   
   // Divide the matched histogram by the sum
   EMTFrecoEfficiencyPtHist->Divide(EMTFrecoMatchPtHist, EMTFrecoSumPtHist);
   CSCTFrecoEfficiencyPtHist->Divide(CSCTFrecoMatchPtHist, CSCTFrecoSumPtHist);
 
   /////////////////////////////////////////////////////////////////////
   // Save Class Vectors------------------------------------------------
   /////////////////////////////////////////////////////////////////////

   histo1D.push_back(EMTFrecoMatchPtHist);
   histo1D.push_back(EMTFrecoNoMatchPtHist);
   histo1D.push_back(EMTFrecoSumPtHist);
   histo1D.push_back(EMTFrecoEfficiencyPtHist);
   histo1D.push_back(CSCTFrecoMatchPtHist);
   histo1D.push_back(CSCTFrecoNoMatchPtHist);
   histo1D.push_back(CSCTFrecoSumPtHist);
   histo1D.push_back(CSCTFrecoEfficiencyPtHist);

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
    for(unsigned trackNum=0; trackNum < sample->vars.trkEta.size(); trackNum++)
    {	
        cut->recoEMDeltaR(trackNum, 1); // Look for a second (indexed as 1) matching reco muon
        if(cut->deltaR <= 0.2 && trackNum != EMTFtag && 1.25 < TMath::Abs(sample->vars.recoEta[1]) < 2.5){
	    isMatched = true;
		  
            //Fill Matched Histogram 
            matchHist->Fill(sample->vars.recoPt[1]);
        }
    } 
    
    if(isMatched == false && 1.25 < TMath::Abs(sample->vars.recoEta[1]) < 2.5){
        //Fill Unmatched Histogram
   	nomatchHist->Fill(sample->vars.recoPt[1]);
    }
}

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

void TagAndProbe::CSCProbe(TH1F* matchHist, TH1F* nomatchHist, int EMTFtag, Cuts* cut)
{
    // Probe to see if there is a match for the second muon
    bool isMatched = false;
    for(unsigned trackNum=0; trackNum < sample->vars.csctf_trkEta.size(); trackNum++)
    {	
        cut->recoCSCDeltaR(trackNum, 1); // Look for a second (indexed as 1) matching reco muon
        if(cut->deltaR <= 0.2 && trackNum != EMTFtag && 1.25 < TMath::Abs(sample->vars.recoEta[1]) < 2.5){
	    isMatched = true;
		  
            //Fill Matched Histogram 
            matchHist->Fill(sample->vars.recoPt[1]);
        }
    } 
    
    if(isMatched == false && 1.25 < TMath::Abs(sample->vars.recoEta[1]) < 2.5){
        //Fill Unmatched Histogram
   	nomatchHist->Fill(sample->vars.recoPt[1]);
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
