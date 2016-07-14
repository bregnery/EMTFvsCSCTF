// VarSet.h
// Load the variables from the ttree into the structs in this class
// The structs are defined in DataFormats.h

#ifndef ADD_VARSET
#define ADD_VARSET

#include "TLorentzVector.h"

class VarSet
{
    public:
        VarSet(){};
        ~VarSet(){};

        float recoPt, trkPt, csctf_trkPt;
	float recoEta, trkEta, csctf_trkEta;
	float trkMode;
};

#endif
