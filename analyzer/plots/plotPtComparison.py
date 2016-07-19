#!/usr/bin/env python

import glob
import ROOT as root
from src.helpers import *

root.gROOT.SetBatch(True)

f = root.TFile("../Data_Comparison_Hist.root")

canvas = root.TCanvas()

hist = f.Get("PtComparisonHist")

xMin = 0
xMax = 300
yMin = 0
yMax = 300

axisHist = root.TH2F("axisHist","CSCTF vs. EMTF P_{T}",1,xMin,xMax,1,yMin,yMax)
axisHist.GetXaxis().SetTitle("EMTF P_{T} [GeV/c]")
axisHist.GetYaxis().SetTitle("CSCTF P_{T} [GeV/c]")
axisHist.Draw()

hist.Draw("COL same")

canvas.SaveAs("Hist_PtComparison.png")
