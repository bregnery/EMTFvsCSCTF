Accessing Data Files on EOS at CERN
===================================

EOS is used to store large files. Here is how to list files in an EOS directory and then download them to a local (afs) directory using a CERN lxplus maching.

    eos ls /<directory>/
    xrdcp root://eoscms.cern.ch//<directory>/<filename> <filename>

