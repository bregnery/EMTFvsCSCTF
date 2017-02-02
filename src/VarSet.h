// VarSet.h
// Load the variables from the ttree into the structs in this class
// The structs are defined in DataFormats.h

#ifndef ADD_VARSET
#define ADD_VARSET

#include <vector>
#include <iostream>
#include "TLeaf.h"
#include "TLorentzVector.h"

class VarSet
{
    public:
        VarSet(){};
        ~VarSet(){};

        std::vector<float> nRecoMuons, ntrkMuons, csctf_ntrkMuons;
        std::vector<float> recoPt, trkPt, csctf_trkPt;
	std::vector<float> recoEta, trkEta, csctf_trkEta;
	std::vector<float> trkMode, csctf_trkMode;
	std::vector<float> trkPhi, csctf_trkPhi, recoPhi;
};

#endif
