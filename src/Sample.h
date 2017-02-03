// Sample.h

#ifndef ADD_SAMPLE
#define ADD_SAMPLE

#include "TMath.h"
#include "TH1F.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLeaf.h"
#include "TEntryList.h"
#include "TROOT.h"

#include "VarSet.h"
#include "DataFormats.h"
//#include "TreeClasses/L1UpgradeTree.h"
//#include "TreeClasses/Muon2RecoTree.h"

class Sample
{
    public:
        Sample();
        Sample(TString infilename, TString iname, TString insampleType);
        ~Sample();

        TString name;
        TString filename;
        TString treename;
	TFile* file;
	TTree* L1UpgradeTree;
	TTree* Muon2RecoTree;
	int nEvents;

	TBranch* b_Muon_eta;
	TBranch* b_Muon_phi;
	TBranch* b_Muon_pt;
	TBranch* b_L1Upgrade_muonEta;
	TBranch* b_L1Upgrade_muonPhi;

	//L1UpgradeTree* EMTF;
	//Muon2RecoTree* RecoMuon;

        TString sampleType;    // "data", "signal", "background"

        float lumi;            // the luminosity of the data or effective luminosity of MC

        VarSet vars;           // all of the variables from the ttree

        int getEntry(int i);                    // load the ith event from the ttree into vars

	void setEMTFBranchAddresses();
	void setCSCTFBranchAddresses();
	void setRecoBranchAddresses();
	
	void setAdditionalVariables();

    protected:
        //TFile* file;           // the file with the ttree
	//TFile* outFile;        // the output file that will contain new variables

};

#endif
