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

   sample->getEntry(i);

   // Check if the number of tracks is the same
   //if(sample->vars.trkPt->size() != sample->vars.csctf_trkPt->size()){
	//std::cout << "Event " << i << " does not have the same number of tracks!" << std::endl;
        //temp.push_back(false);   
   //}

   // Loop over EMTF tracks in the event and see if they match 
   for(unsigned j=0; j < sample->vars.trkPt->size(); j++)
   {
	// Sets the j entry equal to false
	// But changes it to true if there is csc track such that deltaR <= 0.2
        EMtemp.push_back(false);   
	for(unsigned k=0; k < sample->vars.csctf_trkPt->size(); k++)
        {
             DeltaR(j,k);
             if(deltaR <= 0.2){
                 EMtemp[j]=true;
		 break;
             }
        }
	// Debugging
	//if(EMtemp[j]==false){
	//     std::cout << "Event: " << i << " has an unmatched EMTF track." << std::endl;
        //}
    
   }  
   EMisMatched.push_back(EMtemp);

   // Debugging
   //std::cout << "Event: " << i << " has " << sample->vars.csctf_trkPt->size() << " tracks" << std::endl;

   // Loop over CSCTF tracks in the event and see if they match 
   for(unsigned j=0; j < sample->vars.csctf_trkPt->size(); j++)
   {
	// Sets the j entry equal to false
	// But changes it to true if there is csc track such that deltaR <= 0.2
        CSCtemp.push_back(false);   
	for(unsigned k=0; k < sample->vars.trkPt->size(); k++)
        {
             DeltaR(k,j); //important to make j and k are switched here
             if(deltaR <= 0.2){
                 CSCtemp[j]=true;
		 break;
             }
        }
	
	// Debugging
	//if(CSCtemp[j]==false){
	     //std::cout << "Event: " << i << " has an unmatched CSC track." << std::endl;
        //}
    
   }  
   CSCisMatched.push_back(CSCtemp);

}

///////////////////////////////////////////////////////////////
//-----------------------------------------------------------//
///////////////////////////////////////////////////////////////

void Cuts::DeltaR(unsigned j, unsigned k)
{
// Calculates Delta R

   float deltaPhi = sample->vars.csctf_trkPhi->at(k) - sample->vars.trkPhi->at(j);
   float deltaEta = sample->vars.csctf_trkEta->at(k) -  sample->vars.trkEta->at(j); 
   deltaR = TMath::Sqrt(deltaPhi*deltaPhi + deltaEta*deltaEta);
}
