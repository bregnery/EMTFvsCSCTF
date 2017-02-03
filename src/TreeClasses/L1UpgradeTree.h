//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jan 30 19:45:39 2017 by ROOT version 6.06/01
// from TTree L1UpgradeTree/L1UpgradeTree
// found on file: L1Ntuple_165.root
//////////////////////////////////////////////////////////

#ifndef L1UpgradeTree_h
#define L1UpgradeTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "L1Trigger/L1TNtuples/interface/L1AnalysisL1UpgradeDataFormat.h"

class L1UpgradeTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //L1Analysis::L1AnalysisL1UpgradeDataFormat *L1Upgrade;
   UShort_t        nEGs;
   vector<float>   egEt;
   vector<float>   egEta;
   vector<float>   egPhi;
   vector<short>   egIEt;
   vector<short>   egIEta;
   vector<short>   egIPhi;
   vector<short>   egIso;
   vector<short>   egBx;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egTowerIPhi;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egTowerIEta;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egRawEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egIsoEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egFootprintEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egNTT;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egShape;
   L1Analysis::L1AnalysisL1UpgradeDataFormat egTowerHoE;
   UShort_t        nTaus;
   vector<float>   tauEt;
   vector<float>   tauEta;
   vector<float>   tauPhi;
   vector<short>   tauIEt;
   vector<short>   tauIEta;
   vector<short>   tauIPhi;
   vector<short>   tauIso;
   vector<short>   tauBx;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauTowerIPhi;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauTowerIEta;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauRawEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauIsoEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauNTT;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauHasEM;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauIsMerged;
   L1Analysis::L1AnalysisL1UpgradeDataFormat tauHwQual;
   UShort_t        nJets;
   vector<float>   jetEt;
   vector<float>   jetEta;
   vector<float>   jetPhi;
   vector<short>   jetIEt;
   vector<short>   jetIEta;
   vector<short>   jetIPhi;
   vector<short>   jetBx;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetTowerIPhi;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetTowerIEta;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetRawEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetSeedEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetPUEt;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetPUDonutEt0;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetPUDonutEt1;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetPUDonutEt2;
   L1Analysis::L1AnalysisL1UpgradeDataFormat jetPUDonutEt3;
   UShort_t        nMuons;
   vector<float>   muonEt;
   vector<float>   muonEta;
   vector<float>   muonPhi;
   L1Analysis::L1AnalysisL1UpgradeDataFormat muonEtaAtVtx;
   L1Analysis::L1AnalysisL1UpgradeDataFormat muonPhiAtVtx;
   vector<short>   muonIEt;
   vector<short>   muonIEta;
   vector<short>   muonIPhi;
   L1Analysis::L1AnalysisL1UpgradeDataFormat muonIDEta;
   L1Analysis::L1AnalysisL1UpgradeDataFormat muonIDPhi;
   vector<short>   muonChg;
   vector<unsigned short> muonIso;
   vector<unsigned short> muonQual;
   vector<unsigned short> muonTfMuonIdx;
   vector<short>   muonBx;
   UShort_t        nSums;
   vector<short>   sumType;
   vector<float>   sumEt;
   vector<float>   sumPhi;
   vector<short>   sumIEt;
   vector<short>   sumIPhi;
   vector<float>   sumBx;

   // List of branches
   TBranch        *b_L1Upgrade_nEGs;   //!
   TBranch        *b_L1Upgrade_egEt;   //!
   TBranch        *b_L1Upgrade_egEta;   //!
   TBranch        *b_L1Upgrade_egPhi;   //!
   TBranch        *b_L1Upgrade_egIEt;   //!
   TBranch        *b_L1Upgrade_egIEta;   //!
   TBranch        *b_L1Upgrade_egIPhi;   //!
   TBranch        *b_L1Upgrade_egIso;   //!
   TBranch        *b_L1Upgrade_egBx;   //!
   TBranch        *b_L1Upgrade_egTowerIPhi;   //!
   TBranch        *b_L1Upgrade_egTowerIEta;   //!
   TBranch        *b_L1Upgrade_egRawEt;   //!
   TBranch        *b_L1Upgrade_egIsoEt;   //!
   TBranch        *b_L1Upgrade_egFootprintEt;   //!
   TBranch        *b_L1Upgrade_egNTT;   //!
   TBranch        *b_L1Upgrade_egShape;   //!
   TBranch        *b_L1Upgrade_egTowerHoE;   //!
   TBranch        *b_L1Upgrade_nTaus;   //!
   TBranch        *b_L1Upgrade_tauEt;   //!
   TBranch        *b_L1Upgrade_tauEta;   //!
   TBranch        *b_L1Upgrade_tauPhi;   //!
   TBranch        *b_L1Upgrade_tauIEt;   //!
   TBranch        *b_L1Upgrade_tauIEta;   //!
   TBranch        *b_L1Upgrade_tauIPhi;   //!
   TBranch        *b_L1Upgrade_tauIso;   //!
   TBranch        *b_L1Upgrade_tauBx;   //!
   TBranch        *b_L1Upgrade_tauTowerIPhi;   //!
   TBranch        *b_L1Upgrade_tauTowerIEta;   //!
   TBranch        *b_L1Upgrade_tauRawEt;   //!
   TBranch        *b_L1Upgrade_tauIsoEt;   //!
   TBranch        *b_L1Upgrade_tauNTT;   //!
   TBranch        *b_L1Upgrade_tauHasEM;   //!
   TBranch        *b_L1Upgrade_tauIsMerged;   //!
   TBranch        *b_L1Upgrade_tauHwQual;   //!
   TBranch        *b_L1Upgrade_nJets;   //!
   TBranch        *b_L1Upgrade_jetEt;   //!
   TBranch        *b_L1Upgrade_jetEta;   //!
   TBranch        *b_L1Upgrade_jetPhi;   //!
   TBranch        *b_L1Upgrade_jetIEt;   //!
   TBranch        *b_L1Upgrade_jetIEta;   //!
   TBranch        *b_L1Upgrade_jetIPhi;   //!
   TBranch        *b_L1Upgrade_jetBx;   //!
   TBranch        *b_L1Upgrade_jetTowerIPhi;   //!
   TBranch        *b_L1Upgrade_jetTowerIEta;   //!
   TBranch        *b_L1Upgrade_jetRawEt;   //!
   TBranch        *b_L1Upgrade_jetSeedEt;   //!
   TBranch        *b_L1Upgrade_jetPUEt;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt0;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt1;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt2;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt3;   //!
   TBranch        *b_L1Upgrade_nMuons;   //!
   TBranch        *b_L1Upgrade_muonEt;   //!
   TBranch        *b_L1Upgrade_muonEta;   //!
   TBranch        *b_L1Upgrade_muonPhi;   //!
   TBranch        *b_L1Upgrade_muonEtaAtVtx;   //!
   TBranch        *b_L1Upgrade_muonPhiAtVtx;   //!
   TBranch        *b_L1Upgrade_muonIEt;   //!
   TBranch        *b_L1Upgrade_muonIEta;   //!
   TBranch        *b_L1Upgrade_muonIPhi;   //!
   TBranch        *b_L1Upgrade_muonIDEta;   //!
   TBranch        *b_L1Upgrade_muonIDPhi;   //!
   TBranch        *b_L1Upgrade_muonChg;   //!
   TBranch        *b_L1Upgrade_muonIso;   //!
   TBranch        *b_L1Upgrade_muonQual;   //!
   TBranch        *b_L1Upgrade_muonTfMuonIdx;   //!
   TBranch        *b_L1Upgrade_muonBx;   //!
   TBranch        *b_L1Upgrade_nSums;   //!
   TBranch        *b_L1Upgrade_sumType;   //!
   TBranch        *b_L1Upgrade_sumEt;   //!
   TBranch        *b_L1Upgrade_sumPhi;   //!
   TBranch        *b_L1Upgrade_sumIEt;   //!
   TBranch        *b_L1Upgrade_sumIPhi;   //!
   TBranch        *b_L1Upgrade_sumBx;   //!

   L1UpgradeTree(TTree *tree=0);
   virtual ~L1UpgradeTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef L1UpgradeTree_cxx
L1UpgradeTree::L1UpgradeTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("L1Ntuple_165.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("L1Ntuple_165.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("L1Ntuple_165.root:/l1UpgradeTree");
      dir->GetObject("L1UpgradeTree",tree);

   }
   Init(tree);
}

L1UpgradeTree::~L1UpgradeTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t L1UpgradeTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t L1UpgradeTree::LoadTree(Long64_t entry)
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

void L1UpgradeTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("nEGs", &nEGs, &b_L1Upgrade_nEGs);
   fChain->SetBranchAddress("egEt", &egEt, &b_L1Upgrade_egEt);
   fChain->SetBranchAddress("egEta", &egEta, &b_L1Upgrade_egEta);
   fChain->SetBranchAddress("egPhi", &egPhi, &b_L1Upgrade_egPhi);
   fChain->SetBranchAddress("egIEt", &egIEt, &b_L1Upgrade_egIEt);
   fChain->SetBranchAddress("egIEta", &egIEta, &b_L1Upgrade_egIEta);
   fChain->SetBranchAddress("egIPhi", &egIPhi, &b_L1Upgrade_egIPhi);
   fChain->SetBranchAddress("egIso", &egIso, &b_L1Upgrade_egIso);
   fChain->SetBranchAddress("egBx", &egBx, &b_L1Upgrade_egBx);
   fChain->SetBranchAddress("egTowerIPhi", &egTowerIPhi, &b_L1Upgrade_egTowerIPhi);
   fChain->SetBranchAddress("egTowerIEta", &egTowerIEta, &b_L1Upgrade_egTowerIEta);
   fChain->SetBranchAddress("egRawEt", &egRawEt, &b_L1Upgrade_egRawEt);
   fChain->SetBranchAddress("egIsoEt", &egIsoEt, &b_L1Upgrade_egIsoEt);
   fChain->SetBranchAddress("egFootprintEt", &egFootprintEt, &b_L1Upgrade_egFootprintEt);
   fChain->SetBranchAddress("egNTT", &egNTT, &b_L1Upgrade_egNTT);
   fChain->SetBranchAddress("egShape", &egShape, &b_L1Upgrade_egShape);
   fChain->SetBranchAddress("egTowerHoE", &egTowerHoE, &b_L1Upgrade_egTowerHoE);
   fChain->SetBranchAddress("nTaus", &nTaus, &b_L1Upgrade_nTaus);
   fChain->SetBranchAddress("tauEt", &tauEt, &b_L1Upgrade_tauEt);
   fChain->SetBranchAddress("tauEta", &tauEta, &b_L1Upgrade_tauEta);
   fChain->SetBranchAddress("tauPhi", &tauPhi, &b_L1Upgrade_tauPhi);
   fChain->SetBranchAddress("tauIEt", &tauIEt, &b_L1Upgrade_tauIEt);
   fChain->SetBranchAddress("tauIEta", &tauIEta, &b_L1Upgrade_tauIEta);
   fChain->SetBranchAddress("tauIPhi", &tauIPhi, &b_L1Upgrade_tauIPhi);
   fChain->SetBranchAddress("tauIso", &tauIso, &b_L1Upgrade_tauIso);
   fChain->SetBranchAddress("tauBx", &tauBx, &b_L1Upgrade_tauBx);
   fChain->SetBranchAddress("tauTowerIPhi", &tauTowerIPhi, &b_L1Upgrade_tauTowerIPhi);
   fChain->SetBranchAddress("tauTowerIEta", &tauTowerIEta, &b_L1Upgrade_tauTowerIEta);
   fChain->SetBranchAddress("tauRawEt", &tauRawEt, &b_L1Upgrade_tauRawEt);
   fChain->SetBranchAddress("tauIsoEt", &tauIsoEt, &b_L1Upgrade_tauIsoEt);
   fChain->SetBranchAddress("tauNTT", &tauNTT, &b_L1Upgrade_tauNTT);
   fChain->SetBranchAddress("tauHasEM", &tauHasEM, &b_L1Upgrade_tauHasEM);
   fChain->SetBranchAddress("tauIsMerged", &tauIsMerged, &b_L1Upgrade_tauIsMerged);
   fChain->SetBranchAddress("tauHwQual", &tauHwQual, &b_L1Upgrade_tauHwQual);
   fChain->SetBranchAddress("nJets", &nJets, &b_L1Upgrade_nJets);
   fChain->SetBranchAddress("jetEt", &jetEt, &b_L1Upgrade_jetEt);
   fChain->SetBranchAddress("jetEta", &jetEta, &b_L1Upgrade_jetEta);
   fChain->SetBranchAddress("jetPhi", &jetPhi, &b_L1Upgrade_jetPhi);
   fChain->SetBranchAddress("jetIEt", &jetIEt, &b_L1Upgrade_jetIEt);
   fChain->SetBranchAddress("jetIEta", &jetIEta, &b_L1Upgrade_jetIEta);
   fChain->SetBranchAddress("jetIPhi", &jetIPhi, &b_L1Upgrade_jetIPhi);
   fChain->SetBranchAddress("jetBx", &jetBx, &b_L1Upgrade_jetBx);
   fChain->SetBranchAddress("jetTowerIPhi", &jetTowerIPhi, &b_L1Upgrade_jetTowerIPhi);
   fChain->SetBranchAddress("jetTowerIEta", &jetTowerIEta, &b_L1Upgrade_jetTowerIEta);
   fChain->SetBranchAddress("jetRawEt", &jetRawEt, &b_L1Upgrade_jetRawEt);
   fChain->SetBranchAddress("jetSeedEt", &jetSeedEt, &b_L1Upgrade_jetSeedEt);
   fChain->SetBranchAddress("jetPUEt", &jetPUEt, &b_L1Upgrade_jetPUEt);
   fChain->SetBranchAddress("jetPUDonutEt0", &jetPUDonutEt0, &b_L1Upgrade_jetPUDonutEt0);
   fChain->SetBranchAddress("jetPUDonutEt1", &jetPUDonutEt1, &b_L1Upgrade_jetPUDonutEt1);
   fChain->SetBranchAddress("jetPUDonutEt2", &jetPUDonutEt2, &b_L1Upgrade_jetPUDonutEt2);
   fChain->SetBranchAddress("jetPUDonutEt3", &jetPUDonutEt3, &b_L1Upgrade_jetPUDonutEt3);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_L1Upgrade_nMuons);
   fChain->SetBranchAddress("muonEt", &muonEt, &b_L1Upgrade_muonEt);
   fChain->SetBranchAddress("muonEta", &muonEta, &b_L1Upgrade_muonEta);
   fChain->SetBranchAddress("muonPhi", &muonPhi, &b_L1Upgrade_muonPhi);
   fChain->SetBranchAddress("muonEtaAtVtx", &muonEtaAtVtx, &b_L1Upgrade_muonEtaAtVtx);
   fChain->SetBranchAddress("muonPhiAtVtx", &muonPhiAtVtx, &b_L1Upgrade_muonPhiAtVtx);
   fChain->SetBranchAddress("muonIEt", &muonIEt, &b_L1Upgrade_muonIEt);
   fChain->SetBranchAddress("muonIEta", &muonIEta, &b_L1Upgrade_muonIEta);
   fChain->SetBranchAddress("muonIPhi", &muonIPhi, &b_L1Upgrade_muonIPhi);
   fChain->SetBranchAddress("muonIDEta", &muonIDEta, &b_L1Upgrade_muonIDEta);
   fChain->SetBranchAddress("muonIDPhi", &muonIDPhi, &b_L1Upgrade_muonIDPhi);
   fChain->SetBranchAddress("muonChg", &muonChg, &b_L1Upgrade_muonChg);
   fChain->SetBranchAddress("muonIso", &muonIso, &b_L1Upgrade_muonIso);
   fChain->SetBranchAddress("muonQual", &muonQual, &b_L1Upgrade_muonQual);
   fChain->SetBranchAddress("muonTfMuonIdx", &muonTfMuonIdx, &b_L1Upgrade_muonTfMuonIdx);
   fChain->SetBranchAddress("muonBx", &muonBx, &b_L1Upgrade_muonBx);
   fChain->SetBranchAddress("nSums", &nSums, &b_L1Upgrade_nSums);
   fChain->SetBranchAddress("sumType", &sumType, &b_L1Upgrade_sumType);
   fChain->SetBranchAddress("sumEt", &sumEt, &b_L1Upgrade_sumEt);
   fChain->SetBranchAddress("sumPhi", &sumPhi, &b_L1Upgrade_sumPhi);
   fChain->SetBranchAddress("sumIEt", &sumIEt, &b_L1Upgrade_sumIEt);
   fChain->SetBranchAddress("sumIPhi", &sumIPhi, &b_L1Upgrade_sumIPhi);
   fChain->SetBranchAddress("sumBx", &sumBx, &b_L1Upgrade_sumBx);
   Notify();
}

Bool_t L1UpgradeTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void L1UpgradeTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t L1UpgradeTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef L1UpgradeTree_cxx
