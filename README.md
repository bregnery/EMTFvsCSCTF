# EMTFvCSCTFstudies
This program compares tracks from EMTF and CSCTF using the ntuples created by Andrew.

Installation
============

This program has been tested with CMSSW_8_0_9. To use this program, obtain this CMSSW release and move into the source directory.

    cmsrel CMSSW_8_0_9
    cd CMSSW_8_0_9/
    cd src/
    cmsenv
  
Then, clone this git repository and compile CMSSW

    git clone https://github.com/theurerjohn3/EMTFvCSCTFstudies.git
    scram b
    cmsenv

Instructions
============

First compile the program:

    cd analyzer/
    make

This makes an EMTFvCSCTF executable. Now, run the executable:

    ./EMTFvCSCTF

