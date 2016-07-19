#!/usr/bin/env python

import glob
import ROOT as root
from src.helpers import *

root.gROOT.SetBatch(True)

f = root.TFile("../Data_Comparison_Hist.root")

canvas = root.TCanvas()

hist = f.Get("ModeComparisonHist")

xMin = 0
xMax = 20
yMin = 0
yMax = 20

axisHist = root.TH2F("axisHist","CSCTF vs. EMTF Mode",1,xMin,xMax,1,yMin,yMax)
axisHist.GetXaxis().SetTitle("EMTF Mode")
axisHist.GetYaxis().SetTitle("CSCTF Mode")
axisHist.Draw()

hist.Draw("COL same")

canvas.SaveAs("Hist_ModeComparison.png")
