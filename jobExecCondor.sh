#!/bin/bash

#
# variables from arguments string in jdl
#


OUTDIR=$1


echo ""
echo "parameter set:"
echo "INPUTFILE:   $INPUTFILE"
echo "OUTPUTFILE:  $OUTPUTFILE"
echo "WEIGHT:     $WEIGHT"


source /cvmfs/cms.cern.ch/cmsset_default.sh

scram p CMSSW CMSSW_7_4_6_patch6
# cmsenv
cd CMSSW_7_4_6_patch6/src
eval `scramv1 runtime -sh`
cd -




#run macro
root -b -q -l TriggerCheck.C+ 

CMSEXIT=$?

if [[ $CMSEXIT -ne 0 ]]; then
  echo "exit code $CMSEXIT, skipping xrdcp"
  return $CMSEXIT
else
#echo "xrdcp output for condor"
  for FILE in *.root
    do
      echo "xrdcp -f ${FILE} ${OUTDIR}/${FILE}"
      xrdcp -f ${FILE} ${OUTDIR}/${FILE}
      rm ${FILE}
    done
fi






