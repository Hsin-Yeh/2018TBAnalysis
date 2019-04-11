/////////////////////////////////////////////////////////
// Arthor: Chia-hung Chien  chchien521@gmail.com       
// Just use the same class name as we used to.
// Date : 20-June-2018
/////////////////////////////////////////////////////////

#ifndef ntupleMaker_h
#define ntupleMaker_h

#include "TTree.h"
#include "TROOT.h"
#include "TH2Poly.h"
#include "TApplication.h"
#include "TChain.h"
#include <string>
#include <vector>

using namespace std;
const int NLAYER = 28+12;
const int EE_NLAYER = 28;
const int NCHANNEL = 128;
const int setup_config = 0; //0 For 28EE+ 12FH(7module*9layer + 1module*3layer)
const double ENEPERMIP = 86.5e-06; //(GeV) Based on 150GeV muon for 300um Si

class ntupleMaker{
 public:
  ntupleMaker();
  ntupleMaker( TChain *c1,TChain *c2,TChain *c3,string filename );
  ntupleMaker( TChain *c1,TChain *c2,string filename );
  ntupleMaker( TChain *c1,string filename );
 
  ~ntupleMaker();
  
  void NtupleMaker();
  void Event_Display(int ev); // Event Display
  
  //member
  bool Is_Data;
  int  beamE;
  int  runN; //0 for MC
  int  PID; // 0 for electron, 1 for pion, 2 for muon
  string beam_str; // "Ele","Pi","Mu"

 private:
  // Members
  string fname;
  //TApplication *app;
  
  TFile        *Inputfile;
  TTree        *T_Rechit;
  TTree        *T_DWC;
  TTree        *T_Meta;
  TTree        *T_MC;
  int          nevents;
  bool         TestRun;
  
  // Mainframe functions
  void Init();
  void Init_Runinfo();
  void GetData(int evt);
  void Getinfo(int nhit, int &layer, int &chip, int &channel, double &x, double &y,double &z,double &ene, double &TOT);    
  // Tool functions
  void InitTH2Poly(TH2Poly& poly); //Give frame to TH2Poly
  void InitTH2Poly_flower(TH2Poly& poly); //Give flower frame to TH2Poly
  bool Mask_NoisyChannel(int layer, int chip, int channel, double posx, double posy);
  void root_logon();
  double* Set_X0(double X0_arr[]);
  
  ///////////////////////////////
  // Declaration of leaf types //
  ///////////////////////////////
  /*Data*/
  //For Rechit
   UInt_t          event;
   UInt_t          run;
   Int_t           pdgID;
   Float_t        beamEnergy;
   Float_t        trueBeamEnergy;
   UInt_t           NRechits;
   vector<unsigned int> *rechit_detid;
   vector<unsigned int> *rechit_module;
   vector<unsigned int> *rechit_layer;
   vector<unsigned int> *rechit_chip;
   vector<unsigned int> *rechit_channel;
   vector<unsigned int> *rechit_type;
   vector<float>   *rechit_x;
   vector<float>   *rechit_y;
   vector<float>   *rechit_z;
   vector<int>     *rechit_iu;
   vector<int>     *rechit_iv;
   vector<float>   *rechit_energy;
   vector<float>   *rechit_energy_noHG;
   vector<float>   *rechit_amplitudeHigh;
   vector<float>   *rechit_amplitudeLow;
   vector<bool>     *rechit_hg_goodFit;
   vector<bool>     *rechit_lg_goodFit;
   vector<bool>     *rechit_hg_saturated;
   vector<bool>     *rechit_lg_saturated;
   vector<bool>     *rechit_fully_calibrated;
   vector<float>   *rechit_TS2High;
   vector<float>   *rechit_TS2Low;
   vector<float>   *rechit_TS3High;
   vector<float>   *rechit_TS3Low;
   vector<unsigned short>   *rechit_Tot;
   vector<float>   *rechit_timeMaxHG;
   vector<float>   *rechit_timeMaxLG;
   vector<unsigned short>   *rechit_toaRise;
   vector<unsigned short>   *rechit_toaFall;

   // For ImpactPoints (from Delayed wire chamber)
   Int_t           ntracks;
   // ignore the layers currently
   Double_t        impactX_HGCal_layer_1;
   Double_t        impactY_HGCal_layer_1;
   Double_t        impactX_HGCal_layer_2;
   Double_t        impactY_HGCal_layer_2;
   Double_t        impactX_HGCal_layer_3;
   Double_t        impactY_HGCal_layer_3;
   Double_t        impactX_HGCal_layer_4;
   Double_t        impactY_HGCal_layer_4;
   Double_t        impactX_HGCal_layer_5;
   Double_t        impactY_HGCal_layer_5;
   Double_t        impactX_HGCal_layer_6;
   Double_t        impactY_HGCal_layer_6;
   Double_t        impactX_HGCal_layer_7;
   Double_t        impactY_HGCal_layer_7;
   Double_t        impactX_HGCal_layer_8;
   Double_t        impactY_HGCal_layer_8;
   Double_t        impactX_HGCal_layer_9;
   Double_t        impactY_HGCal_layer_9;
   Double_t        impactX_HGCal_layer_10;
   Double_t        impactY_HGCal_layer_10;
   
   Float_t         trackChi2_X;
   Float_t         trackChi2_Y;
   Int_t           dwcReferenceType;
   Double_t        m_x;
   Double_t        m_y;
   Double_t        b_x;
   Double_t        b_y;

   // TBD

   // For metadata
   Int_t           configuration;
   Float_t         biasCurrentCh0;
   Float_t         biasCurrentCh1;
   Float_t         biasCurrentCh2;
   Float_t         biasCurrentCh3;
   Float_t         humidity_RHDP4;
   Float_t         TCassette07;
   Float_t         tablePositionY;
   Float_t         humidity_air;
   Float_t         temperature_air;
   
};

#endif
