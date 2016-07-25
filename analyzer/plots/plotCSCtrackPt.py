#!/usr/bin/env python

import glob
import ROOT as root
from src.helpers import *

root.gROOT.SetBatch(True)

# Open root files
data = root.TFile("../Data_Comparison_Hist.root")

# Create TCanvas
canvas = root.TCanvas()

# Access Histograms
Hist = data.Get("CSCTFtrackPtHist")

Hist.SetFillColor(root.kOrange)
Hist.SetLineColor(root.kOrange)
Hist.SetMarkerStyle(0)
Hist.SetFillStyle(1)

# Create a 2D Histogram for more control
xMin = 0
xMax = 350
yMin = 0
yMax = 10000
xTitle = "P_{T} [GeV/c]"

# Log y axis
#canvas.SetLogy(True)

axisHist = root.TH2F("axisHist","Unmatched CSCTF Tracks P_{T}",1,xMin,xMax,1,yMin,yMax)
axisHist.GetXaxis().SetTitle(xTitle)
axisHist.GetYaxis().SetTitle("Events/Bin")
axisHist.GetYaxis().SetTitleOffset(1.7)
axisHist.Draw()

root.gStyle.SetOptStat(1111) # Needed for stats box

Hist.Draw() # Must first just draw to get stats box

canvas.GetPad(0).Update()
stats_data = Hist.GetListOfFunctions().FindObject("stats").Clone("stats_data")

axisHist.Draw()  # to get axis titles back
stats_data.Draw()

Hist.Draw("hist same")
canvas.SaveAs("Hist_CSCTFtrackPt.png")
