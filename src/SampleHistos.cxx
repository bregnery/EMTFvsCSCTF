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

   // The track type
   std::vector<TString> trackType;
   trackType.push_back("EMTFtrack");
   trackType.push_back("matchEMTFtrack");
   trackType.push_back("CSCTFtrack");
   trackType.push_back("matchCSCTFtrack");

   std::vector<TString> trackTypeTitle;
   trackTypeTitle.push_back("Unmatched EMTF track ");
   trackTypeTitle.push_back("Matched EMTF track ");
   trackTypeTitle.push_back("Unmatched CSCTF track ");
   trackTypeTitle.push_back("Matched CSCTF track ");

   // The resolution type 
   std::vector<TString> resolutionType;
   resolutionType.push_back("recoEM");
   resolutionType.push_back("recoCSC");

   std::vector<TString> resolutionTitle;
   resolutionTitle.push_back(" Resolution for EMTF");
   resolutionTitle.push_back(" Resolution for CSCTF");

   // Eta comparison
   std::vector<TString> etaCompType;
   etaCompType.push_back("CSC15notEMTF");
   etaCompType.push_back("EMTF15notCSC");

   std::vector<TString> etaCompTitle;
   etaCompTitle.push_back("for CSCTF Mode = 15 and EMTF Mode != 15");
   etaCompTitle.push_back("for EMTF Mode = 15 and CSCTF Mode != 15");

   // The plots with number of tracks
   std::vector<TString> numType;
   numType.push_back("Diff");

   std::vector<TString> numTitle;
   numTitle.push_back("Difference in ");

   // Histogram vectors
   std::vector<TH1F*> histoPtVec;
   std::vector<TH1F*> histoEtaVec;
   std::vector<TH1F*> histoModeVec;
   std::vector<TH1F*> histoResoVec;
   std::vector<TH1F*> histoNumVec;
   std::vector<TH1F*> histoEtaCompVec;

   // Set Histogram Parameters
   int index = 0;
   for(std::vector<TString>::const_iterator itr = trackType.begin(); itr != trackType.end(); itr++){

	// track Pt
   	histoPtVec.push_back(new TH1F(*itr + "PtHist",trackTypeTitle[index] + "P_{T}",30,0,350) );
   	setHistTitles(histoPtVec[index],"P_{T} [GeV/c]","Events");
   	histoPtVec[index]->SetStats(1);
   	histoPtVec[index]->Sumw2();

	// track Eta
	histoEtaVec.push_back(new TH1F(*itr + "EtaHist",trackTypeTitle[index] + "#eta",20,0,6) );
   	setHistTitles(histoEtaVec[index],"#eta","Events");
   	histoEtaVec[index]->SetStats(1);
   	histoEtaVec[index]->Sumw2();

	// track Mode
   	histoModeVec.push_back(new TH1F(*itr + "ModeHist",trackTypeTitle[index] + "Mode",30,0,30) );
   	setHistTitles(histoModeVec[index],"Mode","Events");
   	histoModeVec[index]->SetStats(1);
   	histoModeVec[index]->Sumw2();

	index++;
   }

   index = 0;
   for(std::vector<TString>::const_iterator itr = etaCompType.begin(); itr != etaCompType.end(); itr++){

	// eta
	histoEtaCompVec.push_back(new TH1F(*itr + "Eta","#eta for " + etaCompTitle[index],9,-5,5));
	setHistTitles(histoEtaCompVec[index],"#eta","Events");
	histoEtaCompVec[index]->SetStats(1);
	histoEtaCompVec[index]->Sumw2();
	
	index++;
   }
	

   index = 0;
   int histoIndex = 0;
   int numResoHist = 0;

   for(std::vector<TString>::const_iterator itr = resolutionType.begin(); itr != resolutionType.end(); itr++){

	// Find starting index for CSC resolution
	if( (*itr) == "recoCSC"){
		numResoHist = histoIndex;
	}	

	// Pt Resolution
	histoResoVec.push_back(new TH1F(*itr + "resoHist","P_{T}" + resolutionTitle[index],13,-2,10) );
   	setHistTitles(histoResoVec[index], "P_{T} Resolution","Events");
   	histoResoVec[histoIndex]->SetStats(1);
   	histoResoVec[histoIndex]->Sumw2();

	histoIndex++;

	// Loop over mode values
	for(int mode = 1; mode < 16; mode++){

		// Create string from mode
		TString modeStr = std::to_string(mode);

		histoResoVec.push_back(new TH1F(*itr + modeStr + "Pt10resoHist", "Mode = " + modeStr + " P_{T}" + resolutionTitle[index] +" with P_{T} < 10", 13,-2,10) );
   		histoResoVec[histoIndex]->SetStats(1);
   		histoResoVec[histoIndex]->Sumw2();

		histoIndex++;

		histoResoVec.push_back(new TH1F(*itr + modeStr + "Pt10_30resoHist", "Mode = " + modeStr + " P_{T}" + resolutionTitle[index] +" with 10 < P_{T} < 30", 13,-2,10) );
   		histoResoVec[histoIndex]->SetStats(1);
   		histoResoVec[histoIndex]->Sumw2();

		histoIndex++;
				
		histoResoVec.push_back(new TH1F(*itr + modeStr + "Pt30_100resoHist", "Mode = " + modeStr + " P_{T}" + resolutionTitle[index] +" with 30 < P_{T} < 1000", 13,-2,10) );
   		histoResoVec[histoIndex]->SetStats(1);
   		histoResoVec[histoIndex]->Sumw2();

		histoIndex++;

		histoResoVec.push_back(new TH1F(*itr + modeStr + "Pt100resoHist", "Mode = " + modeStr + " P_{T}" + resolutionTitle[index] +" with P_{T} > 100", 13,-2,10) );
   		histoResoVec[histoIndex]->SetStats(1);
   		histoResoVec[histoIndex]->Sumw2();

		histoIndex++;
	}
	index++;
   }

   index = 0;

   for(std::vector<TString>::const_iterator itr = numType.begin(); itr != numType.end(); itr++){

	// number of tracks
	histoNumVec.push_back(new TH1F(*itr + "NumTrackHist",numTitle[index] + "the Number of Tracks",10,0,10) );
   	setHistTitles(histoNumVec[index], "Number of Tracks", "Events");
   	histoNumVec[index]->SetStats(1);
   	histoNumVec[index]->Sumw2();
	
	index++;
   }

   // CSCTF mode vs. EMTF mode for matched tracks
   TH2F* ModeComparisonHist = new TH2F("ModeComparisonHist","CSCTF vs. EMTF Mode",20,0,20,20,0,20); //bins, xmin, xmax, bins, ymin, ymax
   ModeComparisonHist->GetXaxis()->SetTitle("EMTF Mode");
   ModeComparisonHist->GetYaxis()->SetTitle("CSCTF Mode");
   ModeComparisonHist->Sumw2();

   // CSCTF Pt vs. EMTF Pt for mathced tracks
   TH2F* PtComparisonHist = new TH2F("PtComparisonHist","CSCTF vs. EMTF P_{T}",30,0,300,30,0,300); //bins, xmin, xmax, bins, ymin, ymax
   PtComparisonHist->GetXaxis()->SetTitle("EMTF P_{T} [GeV/c]");
   PtComparisonHist->GetYaxis()->SetTitle("CSCTF P_{T} [GeV/c]");
   PtComparisonHist->Sumw2();

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
	     histoNumVec[0]->Fill(getTrackNumDiff(sample->vars.trkPt->size(), sample->vars.csctf_trkPt->size()));
	}

	// Fill not matched EMTF tracks
	for(unsigned j=0; j<cut->EMisMatched[i].size(); j++)
	{
	   // Test if event is matched
	   if(cut->EMisMatched[i][j] == false)
	   {
	        sample->getEntry(i);
	        // Fill Histograms
	    	histoPtVec[0]->Fill(sample->vars.trkPt->at(j));
	    	histoEtaVec[0]->Fill(sample->vars.trkEta->at(j));
	    	histoModeVec[0]->Fill(sample->vars.trkMode->at(j));
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
	    	histoPtVec[1]->Fill(sample->vars.trkPt->at(j));
	    	histoEtaVec[1]->Fill(sample->vars.trkEta->at(j));
	    	histoModeVec[1]->Fill(sample->vars.trkMode->at(j));
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
	    	histoPtVec[2]->Fill(sample->vars.csctf_trkPt->at(j));
	    	histoEtaVec[2]->Fill(sample->vars.csctf_trkEta->at(j));
	    	histoModeVec[2]->Fill(sample->vars.csctf_trkMode->at(j));
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
	    	histoPtVec[3]->Fill(sample->vars.csctf_trkPt->at(j));
	    	histoEtaVec[3]->Fill(sample->vars.csctf_trkEta->at(j));
	    	histoModeVec[3]->Fill(sample->vars.csctf_trkMode->at(j));
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

			if(sample->vars.trkMode->at(j) != 15 && sample->vars.csctf_trkMode->at(k) == 15){
			   histoEtaCompVec[0]->Fill(sample->vars.csctf_trkEta->at(k) );
			}
			
			if(sample->vars.trkMode->at(j) == 15 && sample->vars.csctf_trkMode->at(k) != 15){
			   histoEtaCompVec[1]->Fill(sample->vars.trkEta->at(j) );
			}
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

			histoIndex = 0; //Incredibly important index, often could cause seg faults			

			histoResoVec[histoIndex]->Fill(getEMPtResolution(j,k) );

			histoIndex++;

			for(int mode = 1; mode < 16; mode++){
			     if(sample->vars.trkMode->at(j) == mode && sample->vars.trkPt->at(j) < 10){
				 histoResoVec[histoIndex]->Fill(getEMPtResolution(j,k));
			     }
			     histoIndex++;

			     if(sample->vars.trkMode->at(j) == mode && sample->vars.trkPt->at(j) < 30 && sample->vars.trkPt->at(j) > 10){
				 histoResoVec[histoIndex]->Fill(getEMPtResolution(j,k));
			     }
			     histoIndex++;

			     if(sample->vars.trkMode->at(j) == mode && sample->vars.trkPt->at(j) < 100 && sample->vars.trkPt->at(j) > 30){
				 histoResoVec[histoIndex]->Fill(getEMPtResolution(j,k));
			     }
			     histoIndex++;

			     if(sample->vars.trkMode->at(j) == mode && sample->vars.trkPt->at(j) > 100){
				 histoResoVec[histoIndex]->Fill(getEMPtResolution(j,k));
			     }
			     histoIndex++;
			}
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
			histoIndex = numResoHist; // incredibly important number to get right

			histoResoVec[histoIndex]->Fill(getCSCPtResolution(j,k) );

			histoIndex++;

			for(int mode = 1; mode < 16; mode++){
			     if(sample->vars.csctf_trkMode->at(j) == mode && sample->vars.csctf_trkPt->at(j) < 10){
				 histoResoVec[histoIndex]->Fill(getCSCPtResolution(j,k));
			     }
			     histoIndex++;

			     if(sample->vars.csctf_trkMode->at(j) == mode && sample->vars.csctf_trkPt->at(j) < 30 && sample->vars.csctf_trkPt->at(j) > 10){
				 histoResoVec[histoIndex]->Fill(getCSCPtResolution(j,k));
			     }
			     histoIndex++;

			     if(sample->vars.csctf_trkMode->at(j) == mode && sample->vars.csctf_trkPt->at(j) < 100 && sample->vars.csctf_trkPt->at(j) > 30){
				 histoResoVec[histoIndex]->Fill(getCSCPtResolution(j,k));
			     }
			     histoIndex++;

			     if(sample->vars.csctf_trkMode->at(j) == mode && sample->vars.csctf_trkPt->at(j) > 100){
				 histoResoVec[histoIndex]->Fill(getCSCPtResolution(j,k));
			     }
			     histoIndex++;
			}
		     }
		}
	     }
	}


   }
 
   /////////////////////////////////////////////////////////////////////
   // Save Class Vectors------------------------------------------------
   /////////////////////////////////////////////////////////////////////

   histo1D.push_back(histoPtVec);
   histo1D.push_back(histoEtaVec);
   histo1D.push_back(histoModeVec);
   histo1D.push_back(histoNumVec);
   histo1D.push_back(histoResoVec);
   histo1D.push_back(histoEtaCompVec);

   histo2D.push_back(ModeComparisonHist);
   histo2D.push_back(PtComparisonHist);
 
   /////////////////////////////////////////////////////////////////////
   // Write Histograms--------------------------------------------------
   /////////////////////////////////////////////////////////////////////
   
   for(std::vector<std::vector<TH1F*> >::const_iterator itr = histo1D.begin(); itr != histo1D.end(); itr++){
	for(std::vector<TH1F*>::const_iterator j = (*itr).begin(); j != (*itr).end(); j++){
	    (*j)->Write();
	}
   }

   for(std::vector<TH2F*>::const_iterator itr = histo2D.begin(); itr != histo2D.end(); itr++){
	(*itr)->Write();
   }

   //file->Close();
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

	// Debugging
	//std::cout << "Pt Resolution: "
		//<< (1/(sample->vars.trkPt->at(j)) - 1/(sample->vars.recoPt->at(k)) ) / (1/(sample->vars.recoPt->at(k)) ) << std::endl;

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

//////////////////////////////////////////////////////////////////
//--------------------------------------------------------------//
//////////////////////////////////////////////////////////////////

void SampleHistos::closeFile()
{
	file->Close();
}
