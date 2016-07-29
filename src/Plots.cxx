/////////////////////////////////////////////////////////////////////
//                         Plots.cxx                               //
//=================================================================//
//                                                                 //
// Contains functions for producing the analysis's Plots           //
/////////////////////////////////////////////////////////////////////

#include "Plots.h"

///////////////////////////////////////////////////////////////////////
//_________________________Sample Histograms_________________________//
///////////////////////////////////////////////////////////////////////

Plots::Plots(){}

///////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////

Plots::Plots(Sample* insample, Cuts* cut, SampleHistos* inhistos, TString cutName)
{
   /////////////////////////////////////////////////////////////////////
   // Save Class Variables----------------------------------------------
   /////////////////////////////////////////////////////////////////////

   sample = insample;
   histos = inhistos;

   /////////////////////////////////////////////////////////////////////
   // Create necessary canvas variables and set root parameters---------
   /////////////////////////////////////////////////////////////////////

   int index = 0;
   double width = 1000;
   double height = 1000;

   gROOT->SetBatch();

   /////////////////////////////////////////////////////////////////////
   // Create Plots------------------------------------------------------
   /////////////////////////////////////////////////////////////////////

   for(std::vector<std::vector<TH1F*> >::const_iterator itr = histos->histo1D.begin(); itr != histos->histo1D.end(); itr++){
      	for(std::vector<TH1F*>::const_iterator j = (*itr).begin(); j != (*itr).end(); j++){

	    TString histoVarName((*j)->GetName());

	    // Create Canvas
  	    TCanvas* canvasTemp = new TCanvas("c" + histoVarName, "c" + histoVarName, width, height);
	    
	    // Set Histogram filling parameters
	    (*j)->SetFillColor(kOrange);
	    (*j)->SetLineColor(kOrange);
	    (*j)->SetMarkerStyle(0);
	    (*j)->SetFillStyle(1);
	    (*j)->GetYaxis()->SetTitleOffset(1.7);
	    (*j)->Draw("hist same");
	
	    canvasTemp->SaveAs("Hist_" + histoVarName + ".png");
	
	    // Save Canvas Vector
	    canvas.push_back(canvasTemp);

	    index++;
     	}
	
   }

}

////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////
