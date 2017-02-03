//////////////////////////////////////////////////////////////
//                         Cuts.cxx                         //
//==========================================================//
//                                                          //
// Contains functions for the analysis's various versions   //
// Selection Criteria                                       //
//////////////////////////////////////////////////////////////

#include "Cuts.h"

//////////////////////////////////////////////////////////////
//______________________Cuts________________________________//
//////////////////////////////////////////////////////////////

Cuts::Cuts(){}

//////////////////////////////////////////////////////////////
//----------------------------------------------------------//
//////////////////////////////////////////////////////////////

Cuts::Cuts(Sample* insample)
{
// For loop that runs over all the events to create boolean flags

   unsigned reportEach = 1000000;

   sample = insample;

   for(unsigned i=0; i<sample->nEvents; i++)
   {
	if(i % reportEach == 0) std::cout << "Event: " << i << std::endl;
	Matched(i);
   }
}

///////////////////////////////////////////////////////////////
//-----------------------------------------------------------//
///////////////////////////////////////////////////////////////

void Cuts::Matched(int i)
{
// Determines if CSCTF and EMTF tracks are matched

   // Create a temp vector to pass to the real vector
   std::vector<bool> EMtemp;
   std::vector<bool> CSCtemp;
   std::vector<bool> recoEMtemp;
   std::vector<bool> recoCSCtemp;

   sample->getEntry(i);

   // Loop over EMTF tracks in the event and see if they match reco tracks
   for(unsigned j=0; j < sample->vars.trkEta.size(); j++)
   {
	// Sets the j entry equal to false
	// But changes it to true if there is reco track such that deltaR <= 0.2
        recoEMtemp.push_back(false);   
	for(unsigned k=0; k < sample->vars.recoPt.size(); k++)
        {
             recoEMDeltaR(j,k); //important to note that j and k are switched here
             if(deltaR <= 0.2){
                 recoEMtemp[j]=true;
		 break;
             }
        }

	//Debugging
	//if(recoEMtemp[j] == false){
	   //std::cout << "Event: " << i << " has an unmatched reco Track." << std::endl;
	//}
	
   }  
   recoEMisMatched.push_back(recoEMtemp);

}

///////////////////////////////////////////////////////////////
//-----------------------------------------------------------//
///////////////////////////////////////////////////////////////

void Cuts::DeltaR(unsigned j, unsigned k)
{
// Calculates Delta R

   float deltaPhi = sample->vars.csctf_trkPhi[k] - sample->vars.trkPhi[j];
   float deltaEta = sample->vars.csctf_trkEta[k] -  sample->vars.trkEta[j]; 
   deltaR = TMath::Sqrt(deltaPhi*deltaPhi + deltaEta*deltaEta);
}

///////////////////////////////////////////////////////////////
//-----------------------------------------------------------//
///////////////////////////////////////////////////////////////

void Cuts::recoEMDeltaR(unsigned j, unsigned k)
{
// Calculates Delta R

   float deltaPhi = sample->vars.recoPhi[k] - sample->vars.trkPhi[j];
   float deltaEta = sample->vars.recoEta[k] - sample->vars.trkEta[j]; 
   deltaR = TMath::Sqrt(deltaPhi*deltaPhi + deltaEta*deltaEta);
}

///////////////////////////////////////////////////////////////
//-----------------------------------------------------------//
///////////////////////////////////////////////////////////////

void Cuts::recoCSCDeltaR(unsigned j, unsigned k)
{
// Calculates Delta R

   float deltaPhi = sample->vars.csctf_trkPhi[j] - sample->vars.recoPhi[k];
   float deltaEta = sample->vars.csctf_trkEta[j] -  sample->vars.recoEta[k]; 
   deltaR = TMath::Sqrt(deltaPhi*deltaPhi + deltaEta*deltaEta);
}
