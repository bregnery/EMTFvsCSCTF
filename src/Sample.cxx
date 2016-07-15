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
    filename = infilename;
    name = iname;
    sampleType = insampleType;
    treename = TString("ntuple/tree");
    file = new TFile(infilename);
    tree = (TTree*)file->Get(treename);
    //outFile = new TFile(iname + "_StageVar.root", "RECREATE");
    //outFile->cd();
    //outTree = new TTree("outTree","RECREATE");
    //outTree = tree->CloneTree();
    nEvents = tree->GetEntries();

    lumi = -999;
    
    setBranchAddresses();
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

Sample::~Sample() {
  // free pointed to memory!
  if (tree != 0) {
    delete tree;
  }
  if (file !=0) {
    delete file;
  }
}

///////////////////////////////////////////////////////////////////////////
// _______________________Other Functions________________________________//
///////////////////////////////////////////////////////////////////////////

void Sample::setBranchAddresses()
{
    tree->SetBranchAddress("recoPt", &vars.recoPt);
    tree->SetBranchAddress("trkPt", &vars.trkPt);
    tree->SetBranchAddress("csctf_trkPt", &vars.csctf_trkPt);
    tree->SetBranchAddress("recoEta", &vars.recoEta);
    tree->SetBranchAddress("trkEta", &vars.trkEta);
    tree->SetBranchAddress("csctf_trkEta", &vars.csctf_trkEta);
    tree->SetBranchAddress("trkMode", &vars.trkMode);
    tree->SetBranchAddress("trkPhi", &vars.trkPhi);
    tree->SetBranchAddress("csctf_trkPhi", &vars.csctf_trkPhi);
}

/*
///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////
void Sample::addBranch(float newVar, TString newVarName, TBranch* newVarBranch){
// makes a new branch in the output tree
// this branch has a leaf containing a floating point variable
     newVarBranch = outTree->Branch(newVarName, &newVar, newVarName + "/F");
}
*/

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

int Sample::getEntry(int i)
{
    tree->GetEntry(i);
    return i;
}

///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

int Sample::getEntry(int i, TEntryList* list)
{
    int treenum = list->GetEntry(i);
    tree->GetEntry(treenum);
    return treenum;
}


/*
///////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////
void Sample::getOutFile(){
// Creates an output file
// Saves the output tree in this file
      outTree->Write();
      outFile->Close();
}
*/
