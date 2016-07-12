// Sample.h

#ifndef ADD_SAMPLE
#define ADD_SAMPLE

#include "TMath.h"
#include "TH1F.h"
#include "TFile.h"
#include "TTree.h"
#include "TEntryList.h"

#include "VarSet.h"

class Sample
{
    public:
        Sample();
        Sample(TString infilename, TString iname, TString insampleType);
        ~Sample();

        TString name;
        TString filename;
        TString treename;
        TTree* tree;
	//TTree* outTree;

        TString dir;           // DAS directory
        TString pileupfile;    // used for pile up reweighting through lumiWeights
        TString sampleType;    // "data", "signal", "background"

        int nOriginal;         // the number of events run over to get this sample
        int nOriginalWeighted; // the number of original events run over to get this sample accounting for genWeights
        int nEvents;           // the number of events in the sample

        float lumi;            // the luminosity of the data or effective luminosity of MC

        VarSet vars;           // all of the variables from the ttree

        int getEntry(int i);                    // load the ith event from the ttree into vars
        int getEntry(int i, TEntryList* list);  // load ith event from the list into vars
                                                // the ith event in the list maps to the jth tree entry

        void setBranchAddresses(); // link the values in the tree to vars
	//void addBranch(float newVar, TString newVarName, TBranch* newVarBranch); // Adds a branch with a leaf containing a floating point variable 
	//void getOutFile();

    protected:
        TFile* file;           // the file with the ttree
	//TFile* outFile;        // the output file that will contain new variables

};

#endif
