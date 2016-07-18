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
   std::vector<bool> temp;
   unsigned d = 0;

   sample->getEntry(i);

   // Check if the number of tracks is the same
   if(sample->vars.trkPt->size() != sample->vars.csctf_trkPt->size()){
	std::cout << "Event " << i << " does not have the same number of tracks!" << std::endl;
        temp.push_back(false);   
   }

   else{
      // Loop over tracks in the event and see if they match 
      for(std::vector<float>::const_iterator j = sample->vars.trkPt->begin(); j != sample->vars.trkPt->end(); j++)
      {
           DeltaR(d);
           if(deltaR <= 0.2){
                temp.push_back(true);
           }
           else{
                temp.push_back(false);   
           }
	   d++;
      }
   }  
   isMatched.push_back(temp); 
}

///////////////////////////////////////////////////////////////
//-----------------------------------------------------------//
///////////////////////////////////////////////////////////////

void Cuts::DeltaR(unsigned j)
{
// Calculates Delta R

   float deltaPhi = sample->vars.csctf_trkPhi->at(j) - sample->vars.trkPhi->at(j);
   float deltaEta = sample->vars.csctf_trkEta->at(j) -  sample->vars.trkEta->at(j); 
   deltaR = TMath::Sqrt(deltaPhi*deltaPhi + deltaEta*deltaEta);
}
