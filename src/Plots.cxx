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

Plots::Plots(Sample* insample, Cuts* cut, TagAndProbe* inhistos, TString cutName)
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

   gStyle->SetPadLeftMargin(0.15);
   //gROOT->SetBatch();

   /////////////////////////////////////////////////////////////////////
   // Create Plots------------------------------------------------------
   /////////////////////////////////////////////////////////////////////

   for(std::vector<TH1F*>::const_iterator j = histos->histo1D.begin(); j != histos->histo1D.end(); j++){

	    TString histoVarName((*j)->GetName());

	    // Create Canvas
  	    TCanvas* canvasTemp = new TCanvas("c" + histoVarName, "c" + histoVarName, width, height);
	    
	    // Set Histogram filling parameters
	    (*j)->SetFillColor(kOrange);
	    (*j)->SetLineColor(kOrange+7);
	    (*j)->SetMarkerStyle(0);
	    (*j)->SetFillStyle(1);
	    (*j)->GetYaxis()->SetTitleOffset(2.0);
	    (*j)->Draw("hist same");
	
	    canvasTemp->SaveAs("Hist_" + histoVarName + ".png");
	
	    // Save Canvas Vector
	    canvas.push_back(canvasTemp);

	    index++;
   }

   gStyle->SetPadRightMargin(0.17);

/*
   for(std::vector<TH2F*>::const_iterator j = histos->histo2D.begin(); j != histos->histo2D.end(); j++){

	    TString histoVarName((*j)->GetName());

	    // Create Canvas
  	    TCanvas* canvasTemp = new TCanvas("c" + histoVarName, "c" + histoVarName, width, height);
	    
	    // Set Histogram filling parameters
	    (*j)->SetFillColor(kOrange);
	    (*j)->SetLineColor(kOrange+7);
	    (*j)->SetMarkerStyle(0);
	    (*j)->SetFillStyle(1);
	    (*j)->GetYaxis()->SetTitleOffset(2.0);
	    (*j)->SetStats(0);
	    (*j)->Draw("colz text");
	
	    canvasTemp->SaveAs("Hist_" + histoVarName + ".png");
	
	    // Save Canvas Vector
	    canvas.push_back(canvasTemp);

	    index++;
   }
*/

}

////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////
