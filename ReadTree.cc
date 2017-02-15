#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
using namespace std;

class ReadTree {

public :

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
  // Declaration of leaf types
   UInt_t          RunNum;
   UInt_t          LumiBlockNum;
   ULong64_t       EvtNum;
   Int_t           BTags;
   Int_t           BTagsclean;
   Int_t           NJets;
   Int_t           NJetsclean;
   Double_t        CrossSection;
   Int_t           CSCTightHaloFilter;
   Double_t        DeltaPhi1;
   Double_t        DeltaPhi1clean;
   Double_t        DeltaPhi2;
   Double_t        DeltaPhi2clean;
   Double_t        DeltaPhi3;
   Double_t        DeltaPhi3clean;
   Double_t        DeltaPhi4;
   Double_t        DeltaPhi4clean;
   Int_t           EcalDeadCellTriggerPrimitiveFilter;
   Int_t           eeBadScFilter;
   Int_t           HBHEIsoNoiseFilter;
   Int_t           HBHENoiseFilter;
   Double_t        HT;
   Double_t        HTclean; 
   Double_t        MET;
   Double_t        METclean;
   Double_t        MHT;
   Double_t        MHTclean;
   vector<bool>    *photon_fullID;
   vector<double>  *photon_genMatched;
   vector<double>  *photon_hadTowOverEM;
   vector<double>  *photon_hasPixelSeed;
   vector<double>  *photon_isEB;
   vector<bool>    *photon_nonPrompt;
   vector<double>  *photon_passElectronVeto;
   vector<double>  *photon_pfChargedIso;
   vector<double>  *photon_pfChargedIsoRhoCorr;
   vector<double>  *photon_pfGammaIso;
   vector<double>  *photon_pfGammaIsoRhoCorr;
   vector<double>  *photon_pfNeutralIso;
   vector<double>  *photon_pfNeutralIsoRhoCorr;
   vector<double>  *photon_sigmaIetaIeta;
   vector<TLorentzVector> *Photons;
   vector<string>  *TriggerNames;
   vector<int>     *TriggerPass;
   vector<int>     *TriggerPrescales;
   Double_t        Weight;
  
   // List of branches
   TBranch        *b_RunNum;   //!
   TBranch        *b_LumiBlockNum;   //!
   TBranch        *b_EvtNum;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_BTagsclean;   //!
   TBranch        *b_CrossSection;   //!
   TBranch        *b_CSCTightHaloFilter;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi1clean;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi2clean;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_DeltaPhi3clean;   //!
   TBranch        *b_DeltaPhi4;   //!
   TBranch        *b_DeltaPhi4clean;   //!
   
   TBranch        *b_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_eeBadScFilter;   //!
   
   TBranch        *b_HBHEIsoNoiseFilter;   //!
   TBranch        *b_HBHENoiseFilter;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HTclean;   //!
   
   TBranch        *b_MET;   //!
   TBranch        *b_METclean;   //!
   
   TBranch        *b_MHT;   //!
   TBranch        *b_MHTclean;   //!
   
   TBranch        *b_NJets;   //!
   TBranch        *b_NJetsclean;   //!
  
   TBranch        *b_photon_fullID;   //!
   TBranch        *b_photon_genMatched;   //!
   TBranch        *b_photon_hadTowOverEM;   //!
   TBranch        *b_photon_hasPixelSeed;   //!
   TBranch        *b_photon_isEB;   //!
   TBranch        *b_photon_nonPrompt;   //!
   TBranch        *b_photon_passElectronVeto;   //!
   TBranch        *b_photon_pfChargedIso;   //!
   TBranch        *b_photon_pfChargedIsoRhoCorr;   //!
   TBranch        *b_photon_pfGammaIso;   //!
   TBranch        *b_photon_pfGammaIsoRhoCorr;   //!
   TBranch        *b_photon_pfNeutralIso;   //!
   TBranch        *b_photon_pfNeutralIsoRhoCorr;   //!
   TBranch        *b_photon_sigmaIetaIeta;   //!
   TBranch        *b_Photons;   //!
   
   TBranch        *b_TriggerNames;   //!
   TBranch        *b_TriggerPass;   //!
   TBranch        *b_TriggerPrescales;   //!
   TBranch        *b_Weight;   //!
   

  ReadTree(TTree *tree);

   virtual ~ReadTree();

   int photonIndex();




};

ReadTree::~ReadTree()

{

   if (!fChain) return;

   delete fChain->GetCurrentFile();

}

 ReadTree::ReadTree(TTree *tree)

{


fChain=tree;
   
   photon_fullID = 0;
   photon_genMatched = 0;
   photon_hadTowOverEM = 0;
   photon_hasPixelSeed = 0;
   photon_isEB = 0;
   photon_nonPrompt = 0;
   photon_passElectronVeto = 0;
   photon_pfChargedIso = 0;
   photon_pfChargedIsoRhoCorr = 0;
   photon_pfGammaIso = 0;
   photon_pfGammaIsoRhoCorr = 0;
   photon_pfNeutralIso = 0;
   photon_pfNeutralIsoRhoCorr = 0;
   photon_sigmaIetaIeta = 0;
   Photons = 0;
   TriggerNames = 0;
   TriggerPass = 0;
   TriggerPrescales = 0;
  

   fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
   fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("BTagsclean", &BTagsclean, &b_BTagsclean);
   
   fChain->SetBranchAddress("CrossSection", &CrossSection, &b_CrossSection);
   fChain->SetBranchAddress("CSCTightHaloFilter", &CSCTightHaloFilter, &b_CSCTightHaloFilter);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi2clean", &DeltaPhi2clean, &b_DeltaPhi2clean);
   
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("DeltaPhi3clean", &DeltaPhi3clean, &b_DeltaPhi3clean);
   
   fChain->SetBranchAddress("DeltaPhi4", &DeltaPhi4, &b_DeltaPhi4);
   fChain->SetBranchAddress("DeltaPhi4clean", &DeltaPhi4clean, &b_DeltaPhi4clean);
   
   fChain->SetBranchAddress("EcalDeadCellTriggerPrimitiveFilter", &EcalDeadCellTriggerPrimitiveFilter, &b_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("eeBadScFilter", &eeBadScFilter, &b_eeBadScFilter);
   
   fChain->SetBranchAddress("HBHEIsoNoiseFilter", &HBHEIsoNoiseFilter, &b_HBHEIsoNoiseFilter);
   fChain->SetBranchAddress("HBHENoiseFilter", &HBHENoiseFilter, &b_HBHENoiseFilter);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HTclean", &HTclean, &b_HTclean);
   
   
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METclean", &METclean, &b_METclean);
  
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MHTclean", &MHTclean, &b_MHTclean);
  
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("NJetsclean", &NJetsclean, &b_NJetsclean);
   
   fChain->SetBranchAddress("photon_fullID", &photon_fullID, &b_photon_fullID);
   fChain->SetBranchAddress("photon_genMatched", &photon_genMatched, &b_photon_genMatched);
   fChain->SetBranchAddress("photon_hadTowOverEM", &photon_hadTowOverEM, &b_photon_hadTowOverEM);
   fChain->SetBranchAddress("photon_hasPixelSeed", &photon_hasPixelSeed, &b_photon_hasPixelSeed);
   fChain->SetBranchAddress("photon_isEB", &photon_isEB, &b_photon_isEB);
   fChain->SetBranchAddress("photon_nonPrompt", &photon_nonPrompt, &b_photon_nonPrompt);
   fChain->SetBranchAddress("photon_passElectronVeto", &photon_passElectronVeto, &b_photon_passElectronVeto);
   fChain->SetBranchAddress("photon_pfChargedIso", &photon_pfChargedIso, &b_photon_pfChargedIso);
   fChain->SetBranchAddress("photon_pfChargedIsoRhoCorr", &photon_pfChargedIsoRhoCorr, &b_photon_pfChargedIsoRhoCorr);
   fChain->SetBranchAddress("photon_pfGammaIso", &photon_pfGammaIso, &b_photon_pfGammaIso);
   fChain->SetBranchAddress("photon_pfGammaIsoRhoCorr", &photon_pfGammaIsoRhoCorr, &b_photon_pfGammaIsoRhoCorr);
   fChain->SetBranchAddress("photon_pfNeutralIso", &photon_pfNeutralIso, &b_photon_pfNeutralIso);
   fChain->SetBranchAddress("photon_pfNeutralIsoRhoCorr", &photon_pfNeutralIsoRhoCorr, &b_photon_pfNeutralIsoRhoCorr);
   fChain->SetBranchAddress("photon_sigmaIetaIeta", &photon_sigmaIetaIeta, &b_photon_sigmaIetaIeta);
   fChain->SetBranchAddress("Photons", &Photons, &b_Photons);
   
   fChain->SetBranchAddress("TriggerNames", &TriggerNames, &b_TriggerNames);
   fChain->SetBranchAddress("TriggerPass", &TriggerPass, &b_TriggerPass);
   fChain->SetBranchAddress("TriggerPrescales", &TriggerPrescales, &b_TriggerPrescales);
  
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   


}








