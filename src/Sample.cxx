///////////////////////////////////////////////////////////////////////////
//                             Sample.cxx                                //
//=======================================================================//
//                                                                       //
//        Keeps track of the sample information. TTree, xsec, etc.       //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
// _______________________Includes_______________________________________//
///////////////////////////////////////////////////////////////////////////

#include "Sample.h"

///////////////////////////////////////////////////////////////////////////
// _______________________Constructor/Destructor_________________________//
///////////////////////////////////////////////////////////////////////////

Sample::Sample() 
{
    lumi = -999;
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

Sample::Sample(TString infilename, TString iname, TString insampleType)
{
    //gROOT->LoadMacro(L1UpgradeTree.C);
    //*EMTF = new L1UpgradeTree;
    //gROOT->LoadMacro(Muon2RecoTree.C);
    //*RecoMuon = new Muon2RecoTree;

    filename = infilename;
    name = iname;
    sampleType = insampleType;
    file = new TFile(infilename);

    L1UpgradeTree = (TTree*)file->Get("l1UpgradeTree/L1UpgradeTree");
    nEvents = L1UpgradeTree->GetEntries();
    setEMTFBranchAddresses();

    Muon2RecoTree = (TTree*)file->Get("l1MuonRecoTree/Muon2RecoTree");
    setRecoBranchAddresses();
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

Sample::~Sample() {
  // free pointed to memory!
  if (L1UpgradeTree != 0) {
    delete L1UpgradeTree;
  }
  if (Muon2RecoTree != 0) {
    delete Muon2RecoTree;
  }
  if (file !=0) {
    delete file;
  }
}

///////////////////////////////////////////////////////////////////////////
// _______________________Other Functions________________________________//
///////////////////////////////////////////////////////////////////////////

void Sample::setEMTFBranchAddresses()
{
    L1UpgradeTree->SetMakeClass(1);

    L1UpgradeTree->SetBranchAddress("muonEta", &vars.trkEta, &b_L1Upgrade_muonEta);
    L1UpgradeTree->SetBranchAddress("muonPhi", &vars.trkPhi, &b_L1Upgrade_muonPhi);
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

void Sample::setRecoBranchAddresses()
{
    Muon2RecoTree->SetMakeClass(1);

    Muon2RecoTree->SetBranchAddress("eta", &vars.recoEta, &b_Muon_eta);
    Muon2RecoTree->SetBranchAddress("phi", &vars.recoPhi, &b_Muon_eta);
    Muon2RecoTree->SetBranchAddress("pt", &vars.recoPt, &b_Muon_eta);
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

void Sample::setCSCTFBranchAddresses()
{
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

void Sample::setAdditionalVariables()
{
    for(unsigned i=0; i<nEvents; i++){
	getEntry(i);
    }
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

int Sample::getEntry(int i)
{
    int j = i;
    L1UpgradeTree->LoadTree(i);
    L1UpgradeTree->GetEntry(i);
    Muon2RecoTree->LoadTree(j);
    Muon2RecoTree->GetEntry(j);
    return i;
}

