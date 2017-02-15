#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include "ReadTree.cc"
//#include "SetStyle.C"
//#include "StackPlot.C"
//#include "ComputeBin.C"
#include <stdio.h>
#include "TLegend.h"
#include "TGraph.h"
#include "TPad.h"
#include "TPaveText.h"
#include "THStack.h"
#include "TGaxis.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TEfficiency.h"



using namespace std;
void TriggerCheck(){//main programme
     //Set Canvas Style
   //  TStyle *gStyle = new TStyle("gStyle","Style for P-TDR");
    // SetStyle st;
    // st.SetPars(gStyle);
     //finished setting canvas style
    // DataMC plot;

     //Important
     //In kevins v3 production due to a bug puWeight is divided to all standard MC weights ...this should be removed 
     //from the code if you are using it for version otherthan V3
     TString InputFilePathV5="root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV6/";   
 


     //reading the GJets MC



    TChain* tData = new TChain("tree");
    // tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_JetHT_2016B.root");
     //tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJet_CleanVars/tree_JetHT_2016C.root");
     //tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJet_CleanVars/tree_JetHT_2016D.root");   

  

   tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016B.root");


   tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016C.root");

tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016D.root");

tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016E.root");

tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016F.root");

tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016G.root");

//tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV11/tree_GJet_CleanVars/tree_SingleElectron_2016B.root");









     ReadTree Data(tData);



     TFile *f=new TFile("TriggerHistosHTcross_SingleEle_Pt_V11.root","RECREATE");



     double Lumi=813.37;

     int nBinsHT=13;
     int nBinsMHT=20;
     int nBinsPt=29;
     int nBinsPtEE=22;
     int nBinsNJ=6;
     int nBinsS=25;
     double HTbins[14]={500.,600.,700,800,900,1000.,1100,1200.,1300,1400,1500,1700,2000,3000};
     double MHTbins[21]={150.,160,170,180,190,200,210,225,240,255,270,285,300,325,350,375,400,450,500.,600,750};
     double Ptbins[30]={100,110,120,130,140,150,160,170,180,190,200.,210,220,230,240,250,260,275,290,300,350,400,450,500,550,600.,700,800,900,1000};
     double PtbinsEE[23]={100,110,120,130,140,150,160,170,180,200.,220,250,300,350,400,450,500,550,600.,700,800,900,1000};


     double NJetsbins[7]={4,5,6,7,8,9,12};
     /////////Three MHT Bins
     double MHTbin1Min=200;
     double MHTbin1Max=350;
     double MHTbin2Min=350;
     double MHTbin2Max=500;
     double MHTbin3Min=500;
     double MHTbin3Max=1500;


    ///////////Three MHT Bins

     

     int nBinAN=18;
     double nBinANmax=18.5;

     /////////////////////////////////////////////////////////////////////////////All user input changes above 
     TH1F *hMHT_TrPass=new TH1F("hMHT_TrPass","hMHT_TrPass",nBinsMHT,MHTbins);
     TH1F *hMHT_TrTotal=new TH1F("hMHT_TrTotal","hMHT_TrTotal",nBinsMHT,MHTbins);

     TH1F *hPt_TrPass=new TH1F("hPt_TrPass","hPt_TrPass",nBinsPt,Ptbins);
     TH1F *hPt_TrTotal=new TH1F("hPt_TrTotal","hPt_TrTotal",nBinsPt,Ptbins);


     TH1F *hMHT_TrPassEB=new TH1F("hMHT_TrPassEB","hMHT_TrPassEB",nBinsMHT,MHTbins);
     TH1F *hMHT_TrTotalEB=new TH1F("hMHT_TrTotalEB","hMHT_TrTotalEB",nBinsMHT,MHTbins);

     TH1F *hMHT_TrPassEE=new TH1F("hMHT_TrPassEE","hMHT_TrPassEE",nBinsMHT,MHTbins);
     TH1F *hMHT_TrTotalEE=new TH1F("hMHT_TrTotalEE","hMHT_TrTotalEE",nBinsMHT,MHTbins);

     TH1F *hPt_TrPassEB=new TH1F("hPt_TrPassEB","hPt_TrPassEB",nBinsPt,Ptbins);
     TH1F *hPt_TrTotalEB=new TH1F("hPt_TrTotalEB","hPt_TrTotalEB",nBinsPt,Ptbins);

     TH1F *hPt_TrPassEE=new TH1F("hPt_TrPassEE","hPt_TrPassEE",nBinsPtEE,PtbinsEE);
     TH1F *hPt_TrTotalEE=new TH1F("hPt_TrTotalEE","hPt_TrTotalEE",nBinsPtEE,PtbinsEE);




     int maxEvents_Data=tData->GetEntries();
     for(int iEv=0;iEv<maxEvents_Data;iEv++){//Data
     tData->GetEntry(iEv);
     if(iEv % 10000==0){cout<<"Event no Data : "<<iEv<<endl;}

     //int binNumber_Data = computeBin( Data.MHT, Data.HT, Data.NJets, k13TeV);
     int index=Data.Photons->size();


      if( index >0 ){//Filling Yield(N_Obsereved) in Data
            bool PassTriggerCross=false;
            bool PassTrigger=false;

         for(unsigned int itr=0;itr<Data.TriggerNames->size();itr++){//loop on trigger

          ///  cout<<"Trigger Names: "<<Data.TriggerNames->at(itr)<<endl;
                 //HLT_PFHT800_v2
                 // HLT_Photon165_HE10_v3
             if(Data.TriggerNames->at(itr).find("HLT_PFHT800_v") !=string::npos && Data.TriggerPass->at(itr)==1){//cross trigger
             PassTriggerCross=true;
             //  cout<<"photon cross"<<endl;
               }//cross trigger


              if(Data.TriggerNames->at(itr).find("HLT_Photon175_v") !=string::npos && Data.TriggerPass->at(itr)==1){// trigger
                PassTrigger=true;
                //cout<<"photon trigger"<<endl;

               }// trigger



              }//loop on triggers




         if(PassTriggerCross==true ){//cross trigger pass

          //hMHT_TrTotal->Fill(Data.MHT);
          hPt_TrTotal->Fill(Data.Photons->at(0).Pt());     
         
           if(fabs(Data.Photons->at(0).Eta()) <1.444){
               // hMHT_TrTotalEB->Fill(Data.MHT);
                hPt_TrTotalEB->Fill(Data.Photons->at(0).Pt());
          
                 }
           if(fabs(Data.Photons->at(0).Eta())> 1.566 && fabs(Data.Photons->at(0).Eta())< 2.5){

                 //hMHT_TrTotalEE->Fill(Data.MHT);
                 hPt_TrTotalEE->Fill(Data.Photons->at(0).Pt());
              }     






          if(PassTrigger==true){// trigger pass

        hPt_TrPass->Fill(Data.Photons->at(0).Pt());
        //hMHT_TrPass->Fill(Data.MHT); 

       if(fabs(Data.Photons->at(0).Eta()) <1.444){
                //hMHT_TrPassEB->Fill(Data.MHT);
                hPt_TrPassEB->Fill(Data.Photons->at(0).Pt());
                 }
           if(fabs(Data.Photons->at(0).Eta())> 1.566 && fabs(Data.Photons->at(0).Eta())< 2.5){

                // hMHT_TrPassEE->Fill(Data.MHT);
                 hPt_TrPassEE->Fill(Data.Photons->at(0).Pt());
              }






       }//trigger pass




     }// cross trigger pass 

         }//Filling Yield(N_Obsereved) in Data





     }//Data 

     

     f->Write();

     /*

      TPaveText *tpav1 = new TPaveText(0.2506522,0.3247818,0.759097,0.6970332,"brNDC");

    tpav1->SetBorderSize(0);
    tpav1->SetFillStyle(0);
    tpav1->SetTextAlign(11);
    tpav1->SetTextFont(42);
    tpav1->SetTextSize(0.04);
    tpav1->AddText("HT >250");
    //tpav1->AddText("#gamma p_{T} > 100 ");
    tpav1->AddText("NJets #geq 2");
    //tpav1->AddText("MHT>200");
    tpav1->AddText("Btags=0");
    tpav1->AddText("#epsilon = (Photon175 and Photon165)/Photon165");
   

    TPaveText *pCMS1 = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");

    pCMS1->SetBorderSize(0);
    pCMS1->SetFillStyle(0);
    pCMS1->SetTextAlign(11);
    pCMS1->SetTextFont(42);
    pCMS1->SetTextSize(0.04);
    pCMS1->AddText("CMS #it{Preliminary}                      813 pb^{-1}, #sqrt{s}= 13 TeV");







      TCanvas *c_tr=new TCanvas("c_tr","c_tr");
      TCanvas *c_trEB=new TCanvas("c_trEB","c_trEB");
      TCanvas *c_trEE=new TCanvas("c_trEE","c_trEE");



      TEfficiency *pEff = new TEfficiency(*hMHT_TrPass,*hMHT_TrTotal);
      pEff->SetTitle("#epsilon vs MHT ; MHT ; #epsilon_{trigger}");  
      pEff->SetLineColor(2);
      pEff->SetMarkerColor(2);
      pEff->SetLineWidth(2);


      TLine *line =new TLine(100,0.98,750,0.98);
      line->SetLineColor(kBlue);
      line->SetLineWidth(2);


      TLine *line1 =new TLine(250,0.,250,0.98);
      line1->SetLineColor(kBlue);
      line1->SetLineWidth(2);



      TEfficiency *pEffEB = new TEfficiency(*hMHT_TrPassEB,*hMHT_TrTotalEB);
      pEffEB->SetTitle("#epsilon vs MHT ; MHT ; #epsilon_{trigger}^{Barrel}");
      pEffEB->SetLineColor(2);
      pEffEB->SetMarkerColor(2);
      pEffEB->SetLineWidth(2);

      TEfficiency *pEffEE = new TEfficiency(*hMHT_TrPassEE,*hMHT_TrTotalEE);
      pEffEE->SetTitle("#epsilon vs MHT ; MHT ; #epsilon_{trigger}^{Endcap}");
      pEffEE->SetLineColor(2);
      pEffEE->SetMarkerColor(2);
      pEffEE->SetLineWidth(2);





     c_tr->cd();
     pEff->Draw();
     line->Draw("same");
     tpav1->Draw("same");
     pCMS1->Draw("same");
     c_tr->SaveAs("TriggerEff.png");
     c_tr->SaveAs("TriggerEff.gif");
     c_tr->Close();


     c_trEB->cd();
     pEffEB->Draw();
     line->Draw("same");
     tpav1->Draw("same");
     pCMS1->Draw("same");
     line1->Draw("same");
     c_trEB->SaveAs("TriggerEffEB.png");
     c_trEB->SaveAs("TriggerEffEB.gif");
     //c_trEB->Close();


     c_trEE->cd();
     pEffEE->Draw();
     line->Draw("same");
     tpav1->Draw("same");
     pCMS1->Draw("same");
     c_trEE->SaveAs("TriggerEffEE.png");
     c_trEE->SaveAs("TriggerEffEE.gif");
     c_trEE->Close();

     */













}//main programme
