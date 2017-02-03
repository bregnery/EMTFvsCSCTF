//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 30 20:07:19 2017 by ROOT version 6.06/01
// from TTree Muon2RecoTree/Muon2RecoTree
// found on file: L1Ntuple_165.root
//////////////////////////////////////////////////////////

#ifndef Muon2RecoTree_h
#define Muon2RecoTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "L1Trigger/L1TNtuples/interface/L1AnalysisRecoMuon2DataFormat.h"

class Muon2RecoTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //L1Analysis::L1AnalysisRecoMuon2DataFormat *Muon;
   UShort_t        nMuons;
   vector<float>   e;
   vector<float>   et;
   vector<float>   pt;
   vector<float>   eta;
   vector<float>   phi;
   vector<bool>    isLooseMuon;
   vector<bool>    isMediumMuon;
   L1Analysis::L1AnalysisRecoMuon2DataFormat isTightMuon;
   vector<float>   iso;
   vector<short>   hlt_isomu;
   vector<short>   hlt_mu;
   vector<float>   hlt_isoDeltaR;
   vector<float>   hlt_deltaR;
   L1Analysis::L1AnalysisRecoMuon2DataFormat passesSingleMuon;
   L1Analysis::L1AnalysisRecoMuon2DataFormat charge;
   L1Analysis::L1AnalysisRecoMuon2DataFormat met;
   L1Analysis::L1AnalysisRecoMuon2DataFormat mt;
   L1Analysis::L1AnalysisRecoMuon2DataFormat etaSt1;
   L1Analysis::L1AnalysisRecoMuon2DataFormat phiSt1;
   L1Analysis::L1AnalysisRecoMuon2DataFormat etaSt2;
   L1Analysis::L1AnalysisRecoMuon2DataFormat phiSt2;

   // List of branches
   TBranch        *b_Muon_nMuons;   //!
   TBranch        *b_Muon_e;   //!
   TBranch        *b_Muon_et;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_isLooseMuon;   //!
   TBranch        *b_Muon_isMediumMuon;   //!
   TBranch        *b_Muon_isTightMuon;   //!
   TBranch        *b_Muon_iso;   //!
   TBranch        *b_Muon_hlt_isomu;   //!
   TBranch        *b_Muon_hlt_mu;   //!
   TBranch        *b_Muon_hlt_isoDeltaR;   //!
   TBranch        *b_Muon_hlt_deltaR;   //!
   TBranch        *b_Muon_passesSingleMuon;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_met;   //!
   TBranch        *b_Muon_mt;   //!
   TBranch        *b_Muon_etaSt1;   //!
   TBranch        *b_Muon_phiSt1;   //!
   TBranch        *b_Muon_etaSt2;   //!
   TBranch        *b_Muon_phiSt2;   //!

   Muon2RecoTree(TTree *tree=0);
   virtual ~Muon2RecoTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Muon2RecoTree_cxx
Muon2RecoTree::Muon2RecoTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("L1Ntuple_165.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("L1Ntuple_165.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("L1Ntuple_165.root:/l1MuonRecoTree");
      dir->GetObject("Muon2RecoTree",tree);

   }
   Init(tree);
}

Muon2RecoTree::~Muon2RecoTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Muon2RecoTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Muon2RecoTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Muon2RecoTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nMuons", &nMuons, &b_Muon_nMuons);
   fChain->SetBranchAddress("e", &e, &b_Muon_e);
   fChain->SetBranchAddress("et", &et, &b_Muon_et);
   fChain->SetBranchAddress("pt", &pt, &b_Muon_pt);
   fChain->SetBranchAddress("eta", &eta, &b_Muon_eta);
   fChain->SetBranchAddress("phi", &phi, &b_Muon_phi);
   fChain->SetBranchAddress("isLooseMuon", &isLooseMuon, &b_Muon_isLooseMuon);
   fChain->SetBranchAddress("isMediumMuon", &isMediumMuon, &b_Muon_isMediumMuon);
   fChain->SetBranchAddress("isTightMuon", &isTightMuon, &b_Muon_isTightMuon);
   fChain->SetBranchAddress("iso", &iso, &b_Muon_iso);
   fChain->SetBranchAddress("hlt_isomu", &hlt_isomu, &b_Muon_hlt_isomu);
   fChain->SetBranchAddress("hlt_mu", &hlt_mu, &b_Muon_hlt_mu);
   fChain->SetBranchAddress("hlt_isoDeltaR", &hlt_isoDeltaR, &b_Muon_hlt_isoDeltaR);
   fChain->SetBranchAddress("hlt_deltaR", &hlt_deltaR, &b_Muon_hlt_deltaR);
   fChain->SetBranchAddress("passesSingleMuon", &passesSingleMuon, &b_Muon_passesSingleMuon);
   fChain->SetBranchAddress("charge", &charge, &b_Muon_charge);
   fChain->SetBranchAddress("met", &met, &b_Muon_met);
   fChain->SetBranchAddress("mt", &mt, &b_Muon_mt);
   fChain->SetBranchAddress("etaSt1", &etaSt1, &b_Muon_etaSt1);
   fChain->SetBranchAddress("phiSt1", &phiSt1, &b_Muon_phiSt1);
   fChain->SetBranchAddress("etaSt2", &etaSt2, &b_Muon_etaSt2);
   fChain->SetBranchAddress("phiSt2", &phiSt2, &b_Muon_phiSt2);
   Notify();
}

Bool_t Muon2RecoTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Muon2RecoTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Muon2RecoTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Muon2RecoTree_cxx
