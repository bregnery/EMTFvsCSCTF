#! /usr/bin/env python

import sys
import math
import numpy
from ROOT import *

## in_filename = '/afs/cern.ch/work/a/abrinke1/public/EMTF/Emulator/files/EMTF_NTuple_ZMu_274198_10k_B.root'
EMTF_in_filename = '../NTupleMaker/EMTF_NTuple_ZMu_274198_10k.root'
EMTF_in_file = TFile.Open(in_filename)
EMTF_tree = in_file.Get("ntuple/tree")



#the top half needs to refrence the right file, but it is the files for EMTF

## in_filename = '/afs/cern.ch/work/a/abrinke1/public/CSCTF/Emulator/files/CSCTF_NTuple_ZMu_274198_10k_B.root'
CSCTF_in_filename = '../NTupleMaker/CSCTF_NTuple_ZMu_274198_10k.root'
CSCTF_in_file = TFile.Open(in_filename)
CSCTF_tree = in_file.Get("ntuple/tree")




out_file = TFile('plots/EMTF_CSCTF_matched_pT.root', 'recreate')





pt_bins = [100, 0, 100]


#TH1F(name, title, x bins, xlow, xhigh), I think this is the declaration that was used


h_EMTF_pt_mu = TH1F('h_EMTF_pt', 'EMTF Unmatched Muon pt', pt_bins[0], pt_bins[1], pt_bins[2]) 

h_CSCTF_pt_mu = TH1F('h_CSCTF_pt', 'CSCTF Unmatched Muon pt', pt_bins[0], pt_bins[1], pt_bins[2])


#TH2F(name, title, x bins, xlow, xhigh, ybins, ylow, yhigh ), I think this is the declaration I should use


h_matched_pt_mu = TH2F('h_matched_pt', ' Matched Muon pt ', pt_bins[0], pt_bins[1], pt_bins[2],pt_bins[0], pt_bins[1], pt_bins[2])

Unused_CSCTF = CSCTF_tree.GetEntries()*[True]





for iEvt in range(EMTF_tree.GetEntries()):
    EMTF_has_pair = False
    for j in range(CSCTF_tree.GetEntries()):

        if( abs (EMTF_tree.(however you get R) - CSCTF_tree.(however you get R) ) < .2) #not sure how to get these varibles
             h_matched_pt_mu.Fill( EMTF_tree.recoPt(iEvt) , CSCTF_tree.recoPt(j) )
             EMTF_has_pair=true
             Unused_CSCTF[j]=False;

    if(!EMTF_has_pair)
        h_EMTF_pt_mu.Fill( EMTF_tree.recoPt(iEvt) ) 

for i in range( CSCTF_tree.GetEntries() ):
    if(Unused_CSCTF[i])
         h_CSCTF_pt_mu.Fill( CSCTF_tree.recoPt(i) )

    
out_file.cd()

h_EMTF_pt_mu.Write()
h_CSCTF_pt_mu.Write()
h_matched_pt_mu.Write()

out_file.Close()
EMTF_in_file.Close()
CSCTF_in_file.Close()
