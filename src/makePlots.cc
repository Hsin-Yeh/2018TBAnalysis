#include "PlotSetting.h"
#include "makePlots.h"
#include "ntupleMaker.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include "TGaxis.h"
#include "TGraphErrors.h"
#include <utility>


//makePlots
makePlots::makePlots(){}
makePlots::makePlots(TChain *c1, TChain *c2, TChain *c3, string filename):T_Rechit(c1),T_DWC(c2),T_rechit_var(c3)
{
	cout << "Constructor of makePlot ... \n" << endl;
	fname = filename;

}

//Destructor
makePlots::~makePlots()
{
	cout << "\n\n";
	cout << "Destructor of makePlot ... " << endl;
}

void makePlots::Init(){
	// Set object pointer(Data)
	rechit_detid = 0;
	rechit_module = 0;
	rechit_layer = 0;
	rechit_chip = 0;
	rechit_channel = 0;
	rechit_type = 0;
	rechit_x = 0;
	rechit_y = 0;
	rechit_z = 0;
	rechit_iu = 0;
	rechit_iv = 0;
	rechit_energy = 0;
	rechit_energy_noHG = 0;
	rechit_amplitudeHigh = 0;
	rechit_amplitudeLow = 0;
	rechit_hg_goodFit = 0;
	rechit_lg_goodFit = 0;
	rechit_hg_saturated = 0;
	rechit_lg_saturated = 0;
	rechit_fully_calibrated = 0;
	rechit_TS2High = 0;
	rechit_TS2Low = 0;
	rechit_TS3High = 0;
	rechit_TS3Low = 0;
	rechit_Tot = 0;
	rechit_timeMaxHG = 0;
	rechit_timeMaxLG = 0;
	rechit_toaRise = 0;
	rechit_toaFall = 0;

	hit_mip = 0;
	hit_x = 0;
	hit_y = 0;
	hit_z = 0;

	T_Rechit->SetBranchAddress("event", &event);
	T_Rechit->SetBranchAddress("run", &run);
	T_Rechit->SetBranchAddress("pdgID", &pdgID);
	T_Rechit->SetBranchAddress("beamEnergy", &beamEnergy);
	T_Rechit->SetBranchAddress("trueBeamEnergy", &trueBeamEnergy);
	T_Rechit->SetBranchAddress("NRechits", &NRechits);
	T_Rechit->SetBranchAddress("rechit_detid", &rechit_detid);
	T_Rechit->SetBranchAddress("rechit_module", &rechit_module);
	T_Rechit->SetBranchAddress("rechit_layer", &rechit_layer);
	T_Rechit->SetBranchAddress("rechit_chip", &rechit_chip);
	T_Rechit->SetBranchAddress("rechit_channel", &rechit_channel);

	T_Rechit->SetBranchAddress("rechit_x", &rechit_x);
	T_Rechit->SetBranchAddress("rechit_y", &rechit_y);
	T_Rechit->SetBranchAddress("rechit_z", &rechit_z);
	T_Rechit->SetBranchAddress("rechit_iu", &rechit_iu);
	T_Rechit->SetBranchAddress("rechit_iv", &rechit_iv);
	T_Rechit->SetBranchAddress("rechit_energy", &rechit_energy);

	T_Rechit->SetBranchAddress("rechit_amplitudeHigh", &rechit_amplitudeHigh);
	T_Rechit->SetBranchAddress("rechit_amplitudeLow", &rechit_amplitudeLow);
    
	T_Rechit->SetBranchAddress("rechit_Tot", &rechit_Tot);
	T_Rechit->SetBranchAddress("rechit_timeMaxHG", &rechit_timeMaxHG);
	T_Rechit->SetBranchAddress("rechit_timeMaxLG", &rechit_timeMaxLG);
	T_Rechit->SetBranchAddress("rechit_toaRise", &rechit_toaRise);
	T_Rechit->SetBranchAddress("rechit_toaFall", &rechit_toaFall);

	T_DWC->SetBranchAddress("trackChi2_X", &trackChi2_X, &b_trackChi2_X);
	T_DWC->SetBranchAddress("trackChi2_Y", &trackChi2_Y, &b_trackChi2_Y);
	T_DWC->SetBranchAddress("dwcReferenceType", &dwcReferenceType, &b_dwcReferenceType);
	T_DWC->SetBranchAddress("m_x", &m_x, &b_m_x);
	T_DWC->SetBranchAddress("m_y", &m_y, &b_m_y);
	T_DWC->SetBranchAddress("b_x", &b_x, &b_b_x);
	T_DWC->SetBranchAddress("b_y", &b_y, &b_b_y);
	
	T_rechit_var->SetBranchAddress("hit_mip", &hit_mip, &b_hit_mip);
	T_rechit_var->SetBranchAddress("hit_x", &hit_x, &b_hit_x);
	T_rechit_var->SetBranchAddress("hit_y", &hit_y, &b_hit_y);
	T_rechit_var->SetBranchAddress("hit_z", &hit_z, &b_hit_z);
	T_rechit_var->SetBranchAddress("layerNhit", layerNhit, &b_layerNhit);
	T_rechit_var->SetBranchAddress("totalE", &totalE, &b_totalE);
	T_rechit_var->SetBranchAddress("totalE_CEE", &totalE_CEE, &b_totalE_CEE);
	T_rechit_var->SetBranchAddress("totalE_CEH", &totalE_CEH, &b_totalE_CEH);
	T_rechit_var->SetBranchAddress("layerE", layerE, &b_layerE);
	T_rechit_var->SetBranchAddress("layerE1", layerE1, &b_layerE1);
	T_rechit_var->SetBranchAddress("layerE7", layerE7, &b_layerE7);
	T_rechit_var->SetBranchAddress("layerE19", layerE19, &b_layerE19);
	T_rechit_var->SetBranchAddress("layerE37", layerE37, &b_layerE37);
	T_rechit_var->SetBranchAddress("impactX", impactX, &b_impactX);
	T_rechit_var->SetBranchAddress("impactY", impactY, &b_impactY);

	Init_Runinfo();
	nevents = T_Rechit->GetEntries();

	PlotSetting *P = nullptr;
	P->root_logon();
}

void makePlots::Init_Runinfo(){
	T_Rechit->GetEntry(0);
	beamE = beamEnergy;
	if( pdgID == 11 ){
		beam_str = "Ele";
		PID = 0;}
	else if( pdgID == 13){
		beam_str = "Mu";
		PID = 2;}
	else if( pdgID == 211){
		beam_str = "Pi";
		PID = 1;}
	else{
		cout << "unknown PDGID QQ" << endl;
		beam_str = "??";
		PID = -1;}

	cout << beam_str.c_str()  << " , "<< beamE << "GeV\n" << endl;
}

void makePlots::GetData(int evt){
	T_Rechit      -> GetEntry(evt);
	T_DWC         -> GetEntry(evt);
	T_rechit_var  -> GetEntry(evt);
}

void makePlots::Getinfo(int ihit,int &layer, int &chip, int &channel, double &x, double &y,double &z,double &ene){
	layer   = rechit_layer  ->at(ihit);
	chip    = rechit_chip   ->at(ihit);
	channel = rechit_channel->at(ihit);
	x       = rechit_x      ->at(ihit);
	y       = rechit_y      ->at(ihit);
	z       = rechit_z      ->at(ihit);
	ene     = rechit_energy ->at(ihit);
}

void makePlots::Loop(){

	Init();
  
	double X0_arr[EE_NLAYER];
	double *X0_layer = Set_X0(X0_arr);
	double Passed_events = 0;
	double efficiency;
	int layer, chip, channel;
	double posx, posy, posz, energy;

	// Declare Draw Options
	TCanvas *c1 = new TCanvas("c1","c1",6400,3600);
	c1->Divide(7,4);
	//gROOT->SetBatch(kTRUE);
	
	// Declare output filename
	char title[200];
	int start = fname.find_last_of("/");
	int end = fname.find(".root");
	string f_substr = fname.substr(start+1,end-start-1);
	sprintf(title,"root_plot/plot_%s.root",f_substr.c_str());
	cout << "output name : " << title << endl;
	TFile outf(title,"recreate");

	// Declare histograms
	TH1D *h_E1devE7[EE_NLAYER]; 
	TH1D *h_E7devE19[EE_NLAYER];
	TH1D *h_totalE = new TH1D("h_totalE","",100,0,300);
	TH1D *h_totalCEE = new TH1D("h_totalCEE","",100,0,3000);
	TH1D *h_E1_no_XTalk = new TH1D("h_E1_no_XTalk","E1/E7==1, E1 Energy",100,0,300);
	h_E1_no_XTalk->GetXaxis()->SetTitle("[MIP]");
	TH1D *h_E1_SecondRing_no_XTalk = new TH1D("h_E1_SecondRing_no_XTalk","E7/E19==1, E1 Energy",100,0,300);
	h_E1_SecondRing_no_XTalk->GetXaxis()->SetTitle("[MIP]");
	TH1D *h_E1devE7_SecondRing_no_XTalk = new TH1D("h_E1deve7_SecondRing_no_XTalk","",101,0,1.01);
	TH1D *h_SHD_Elayer = new TH1D("h_SHD_Elayer","",50,0,25);
    
	for(int iL = 0; iL < EE_NLAYER ; ++iL){
		sprintf(title,"layer%i_E1devE7",iL);
		h_E1devE7[iL] = new TH1D(title,title,101,0,1.01);
		sprintf(title,"layer%i_E7devE19",iL);
		h_E7devE19[iL] = new TH1D(title,title,101,0,1.01);
	}

	TH2Poly *poly = new TH2Poly();
	InitTH2Poly(*poly);

	TH2Poly *latShower_energy[EE_NLAYER];
	for(int iL = 0; iL < EE_NLAYER ; ++iL){
		latShower_energy[iL] = new TH2Poly();
		InitTH2Poly(*latShower_energy[iL]);
		sprintf(title,"Layer_%i",iL+1);
		latShower_energy[iL]->SetTitle(title);
		latShower_energy[iL]->SetName(title);
	}
	

	// -------------------- Loop Over Events -------------------- //
	
	for(int ev = 0; ev < nevents; ++ev){
		if(ev %10000 == 0) cout << "Processing event: "<< ev << endl;
		GetData(ev);

		// Event Selection
		if ( dwcReferenceType != 15) continue;
		double impact_R = sqrt ( (impactX[0] * impactX[0]) + (impactY[0] * impactY[0]) );
		if ( impact_R > 0.5 ) continue;
		cout << impact_R << endl;
		int Nhits = NRechits;
		//if ( Nhits < 200 ) continue;
		Passed_events++;

		
		for(int iL = 0; iL < EE_NLAYER ; ++iL){
			//Fill shower shape histogram
			if( layerE1[iL] != 0) {
				double E1devE7  = layerE1[iL]/layerE7[iL];
				double E7devE19 = layerE7[iL]/layerE19[iL];
				h_E1devE7 [iL]->Fill(E1devE7);
				h_E7devE19[iL]->Fill(E7devE19);

				if ( iL == 5 && E1devE7 == 1 ) {  h_E1_no_XTalk->Fill(layerE1[iL]);  }
				if ( iL == 5 && E7devE19 == 1) {
					h_E1_SecondRing_no_XTalk->Fill(layerE1[iL]);
					h_E1devE7_SecondRing_no_XTalk->Fill(E1devE7);
				}
			}
		}

		// Fill PolyHistograms
		for(int ihit = 0; ihit < NRechits ; ++ihit){
			Getinfo ( ihit, layer, chip, channel, posx, posy, posz, energy );
			if ( layer > EE_NLAYER ) continue;
			//if ( chip != 1 ) continue;
			//if ( channel != 34 ) continue;
			latShower_energy[layer-1] -> Fill( impactX[layer-1], impactY[layer-1], 1);
			cout << "Layer = " << layer << ", Chip = " << chip << ", channel = " << channel << ", posx = " << posx << ", posy = " << posy << ", energy = " << energy << endl;
		}

		
		h_totalE->Fill(totalE);
		h_totalCEE->Fill(totalE_CEE);


		// Calculate the shower depth
		double SHD_Elayer = 0;
    
		for(int iL = 0 ; iL < EE_NLAYER ; ++iL){
			SHD_Elayer += X0_layer[iL]*layerE[iL];
		}
		SHD_Elayer /= totalE;
		h_SHD_Elayer->Fill(SHD_Elayer);
	}

	//Efficiency
	efficiency = Passed_events / nevents;
	cout << "\n\n";
	cout << "Total Events = " << nevents << ", Passed Events = " << Passed_events  << endl;
	cout << "Efficiency = " << efficiency << "\n" << endl;
  
	// Normalize Histograms
	Double_t scale = 1/h_totalE->Integral();
	h_totalE->Scale(scale);
	scale = 1/h_totalCEE->Integral();
	h_totalCEE->Scale(scale);
	scale = 1/h_SHD_Elayer->Integral();
	h_SHD_Elayer->Scale(scale);

	for (int iL = 0; iL < EE_NLAYER; ++iL){
		scale = 1/h_E1devE7 [iL]->Integral();
		h_E1devE7 [iL]->Scale(scale);
		scale = 1/h_E7devE19[iL]->Integral();
		h_E7devE19[iL]->Scale(scale);
	}

	for ( int iL = 0; iL < EE_NLAYER; iL++){
		c1->cd(iL+1);
		latShower_energy[iL] -> Draw("colz");
	}
	c1->Update();
	gPad->WaitPrimitive();

	c1->Write();
	delete c1;
	outf.Write();
	outf.Close();
}



void makePlots::Event_Display(){

	Init();
	gStyle->SetPalette(54);
	gStyle->SetOptStat(0);
	gROOT->SetBatch(kTRUE);
	//TCanvas *c1 = new TCanvas("c1","c1",1200,600);
	TCanvas *c1 = new TCanvas("c1","c1",6400,3600);
	c1->Divide(7,4);
	char title[50];

	int Nlayer = 28;
	TH2Poly *latShower_energy[Nlayer];

	for(int iL = 0; iL < Nlayer ; ++iL){
		latShower_energy[iL] = new TH2Poly();
		InitTH2Poly(*latShower_energy[iL]);
		sprintf(title,"Layer_%i",iL+1);
		latShower_energy[iL]->SetTitle(title);
	}

	TH2Poly *firstL = new TH2Poly();
	InitTH2Poly(*firstL);
	int counts = 0;
	for(int ev = 0; ev < nevents; ++ev){
		if(ev %10000 == 0) cout << "Processing event: "<< ev << endl;
    
		GetData(ev);
		int Nhits;
		Nhits = NRechits;
		//cout << Nhits << endl;
		int layer, chip, channel;
		double posx,posy,posz,energy;
		double ENEPERMIP = 52.8e-03;
    
		double totalE = 0;
		for(int ihit = 0; ihit < Nhits ; ++ihit){
			Getinfo ( ihit, layer, chip, channel, posx, posy, posz, energy );
			totalE += energy/ENEPERMIP;
		}
		if(totalE >= 140000 && ev < 10000){
			counts++;
			for(int ihit = 0; ihit < Nhits ; ++ihit){
				Getinfo ( ihit, layer, chip, channel, posx, posy, posz, energy );
				//cout << "layer = " << layer << " , x = " << posx << ", y = " << posy << ", nmip = " << energy/ENEPERMIP <<endl;
				latShower_energy[layer-1]->Fill(posx,posy,energy/ENEPERMIP);
				if(layer == 1)
					firstL->Fill(posx,posy,energy/ENEPERMIP);

			}
		}
	}
	for(int iL = 0; iL < EE_NLAYER ; ++iL){
		c1->cd(iL);
		latShower_energy[iL]->Draw("colz");
	}
	//c1->Update();
	sprintf(title,"plots/evt_dis/evt_display_%ievts_avg.png",counts);
	//getchar();
	//c1->Update();

	c1->SaveAs(title);
  
	TCanvas *c2 = new TCanvas();
	firstL->Draw("samecolz");
	c2->Update();
	sprintf(title,"plots/evt_dis/evt_display_1st.png");
	c2->SaveAs(title);

	//getchar();
  
}


/*
  void makePlots::PlotProducer(bool ignore_EE, bool hitmap){
  
  //-------------------- Call Parameters and Initialize --------------------//
  Init();
  //gStyle->SetPalette(53);
  gStyle->SetOptStat(0);
  gROOT->SetBatch(kTRUE);
  TGAxis::SetMaxDigits(3);

  TCanvas *c1 = new TCanvas("c1","c1",6400,3600);
  if(!ignore_EE)
  c1->Divide(8,5);
  else
  c1->Divide(4,3);
  char title[50];
  TCanvas* c2 = new TCanvas("c2","c2",6400,3600);
  c2->Divide(4,2);
  TCanvas* c3 = new TCanvas("c3","c3",6400,3600);
  c3->Divide(4,2);
  TCanvas* c4 = new TCanvas("c4","c4",6400,3600);
  c4->Divide(8,5);
  TCanvas* c5 = new TCanvas();


  TH2Poly *latShower_energy[NLAYER];
  for(int iL = 0; iL < NLAYER ; ++iL){
  latShower_energy[iL] = new TH2Poly();
  if(setup_config == 0){
  if(iL < EE_NLAYER)
  InitTH2Poly(*latShower_energy[iL]);
  else
  //	InitTH2Poly_flower(*latShower_energy[iL]);
  InitTH2Poly(*latShower_energy[iL]);
  }
  sprintf(title,"Layer_%i",iL+1);
  latShower_energy[iL]->SetTitle(title);
  }


  TH1D* h_TotalEnergy = new TH1D("h_TotalEnergy","",200,0,20000);
  TH1D* h_EE_Energy = new TH1D("h_EE_Energy","",100,0,20000);
  TH1D* h_FH_Energy = new TH1D("h_FH_Energy","",100,0,50000);
  TH1D* h_TotalEnergy_TOT = new TH1D("h_TotalEnergy_TOT","",100,0,50000);
  TH1D* h_TotalEnergy_HG = new TH1D("h_TotalEnergy_HG","",100,0,1000000);
  TH1D* h_TotalEnergy_LG = new TH1D("h_TotalEnergy_LG","",100,0,100000);
  TH1D* h_TotalEnergy_Layer[NLAYER];
  TH1D* h_Longitudinal_Shower_Profile = new TH1D("h_Longitudinal_Shower_Profile","",100,0,10000);
  TH1D* h_CoG = new TH1D("h_CoG","",100,0,200);
  TH2D* h_CoG_TotalE = new TH2D("h_CoG_TotalE","",50,50,0,200,0,50000);
  TH2D* h_CoG_NHits = new TH2D("h_CoG_NHits","",50,50,0,200,0,50000);

  TH1D* h_TotalEnergy_Mask = new TH1D("h_TotalEnergy_Mask","",200,0,20000);
  TH1D* h_EE_Energy_Mask = new TH1D("h_EE_Energy_Mask","",100,0,20000);
  TH1D* h_FH_Energy_Mask = new TH1D("h_FH_Energy_Mask","",100,0,50000);
  TH1D* h_TotalEnergy_TOT_Mask = new TH1D("h_TotalEnergy_TOT_Mask","",100,0,50000);
  TH1D* h_TotalEnergy_HG_Mask = new TH1D("h_TotalEnergy_HG_Mask","",100,0,100000);
  TH1D* h_TotalEnergy_LG_Mask = new TH1D("h_TotalEnergy_LG_Mask","",100,0,100000);
  TH1D* h_Longitudinal_Shower_Profile_Mask = new TH1D("h_Longitudinal_Shower_Profile_Mask","",100,0,10000);
  TH2D* h_CoG_TotalE_Mask = new TH2D("h_CoG_TotalE_Mask","",50,50,0,200,0,50000);
  TH2D* h_CoG_NHits_Mask = new TH2D("h_CoG_NHits_Mask","",50,50,0,200,0,50000);

  TF1* fit_TotalEnergy_Layer_gaussian[NLAYER];
  TGraphErrors* g_TotalEnergy_Layer;

  for(int ilayer = 0; ilayer < NLAYER; ilayer++){
  char histname[50], fitname[50];    
  sprintf(histname,"h_TotalEnergy_Layer_%d",ilayer);
  h_TotalEnergy_Layer[ilayer] = new TH1D(histname,"",100,0,2000);

  sprintf(fitname,"fit_TotalEnergy_Layer_gaussian%d",ilayer);
  fit_TotalEnergy_Layer_gaussian[ilayer] = new TF1(fitname,"gaus",80,1500);
  }
  

  //-------------------- Loop over events --------------------//

  int counts = 0;
  for(int ev = 0; ev < nevents; ++ev){
  if(ev %10000 == 0) cout << "Processing event: "<< ev << endl;    
  GetData(ev);
  int Nhits;
  Nhits = NRechits;
  //cout << Nhits << endl;
  //    int layer, chip, channel;
  //double posx, posy, posz, energy, E_TOT, E_HG, E_LG;
   
    
  double totalE = 0, CoG = 0, CoG_NHits = 0, EE_energy = 0, FH_energy = 0, totalE_TOT=0, totalE_HG=0, totalE_LG=0;
  double totalE_Mask = 0, CoG_Mask = 0, CoG_NHits_Mask = 0, EE_energy_Mask = 0, FH_energy_Mask = 0, totalE_TOT_Mask=0, totalE_HG_Mask = 0, totalE_LG_Mask = 0, NHits_Mask = 0;
  double totalE_layer[NLAYER];
  for(int ilayer = 0; ilayer < NLAYER; ilayer++){
  totalE_layer[ilayer] = 0;
  }
    
  for(int ihit = 0; ihit < Nhits ; ++ihit){
  //Getinfo(h, layer, chip, channel, posx, posy, posz, energy, TOT, E_HG, E_LG);
      
  totalE += rechit_energy->at(ihit);
  CoG += rechit_energy->at(ihit) * rechit_z->at(ihit);
  totalE_TOT += rechit_Tot->at(ihit);
  totalE_HG += rechit_amplitudeHigh->at(ihit);
  totalE_LG += rechit_amplitudeLow->at(ihit);
  CoG_NHits += rechit_z->at(ihit) * 1;
  if(rechit_layer->at(ihit) <= EE_NLAYER) { EE_energy += rechit_energy->at(ihit); }
  else { FH_energy += rechit_energy->at(ihit); }


  if( !Mask_NoisyChannel( rechit_layer->at(ihit), rechit_chip->at(ihit), rechit_channel->at(ihit), rechit_x->at(ihit), rechit_y->at(ihit) ) ) {
  totalE_Mask += rechit_energy->at(ihit);
  CoG_Mask += rechit_energy->at(ihit) * rechit_z->at(ihit);
  totalE_TOT_Mask += rechit_Tot->at(ihit);
  totalE_HG_Mask += rechit_amplitudeHigh->at(ihit);
  totalE_LG_Mask += rechit_amplitudeLow->at(ihit);
  CoG_NHits_Mask += rechit_z->at(ihit) * 1;
  NHits_Mask++;
  totalE_layer[rechit_layer->at(ihit)-1] += rechit_energy->at(ihit);
  if(rechit_layer->at(ihit) <= EE_NLAYER) { EE_energy_Mask += rechit_energy->at(ihit); }
  else { FH_energy_Mask += rechit_energy->at(ihit); }
  }
  }
  counts++;

  // Fill Histograms
    
  for(int ilayer=0; ilayer < NLAYER; ilayer++){
  if(totalE_layer[ilayer] > 25){
  h_TotalEnergy_Layer[ilayer]->Fill(totalE_layer[ilayer]);
  }
  }
    
  h_TotalEnergy_Mask->Fill(totalE_Mask);
  h_CoG_TotalE_Mask->Fill(CoG_Mask/totalE_Mask, totalE_Mask);
  h_EE_Energy_Mask->Fill(EE_energy_Mask);
  h_FH_Energy_Mask->Fill(FH_energy_Mask);
  h_TotalEnergy_HG_Mask->Fill(totalE_HG_Mask);
  h_TotalEnergy_LG_Mask->Fill(totalE_LG_Mask);
  h_TotalEnergy_TOT_Mask->Fill(totalE_TOT_Mask);
  h_CoG_NHits_Mask->Fill(CoG_NHits_Mask/NHits_Mask, NHits_Mask);
        
  h_TotalEnergy->Fill(totalE);
  h_CoG_TotalE->Fill(CoG/totalE, totalE);
  h_CoG->Fill(CoG/totalE);
  h_EE_Energy->Fill(EE_energy);
  h_FH_Energy->Fill(FH_energy);
  h_TotalEnergy_HG->Fill(totalE_HG);
  h_TotalEnergy_LG->Fill(totalE_LG);
  h_TotalEnergy_TOT->Fill(totalE_TOT);
  h_CoG_NHits->Fill(CoG/totalE, Nhits);

    
  // Fill Hexagon Energy Display 
    
  for(int ihit = 0; ihit < Nhits ; ++ihit){
  //Getinfo(h, layer, chip, channel, posx, posy, posz, energy, TOT, E_HG, E_LG);
  if( !Mask_NoisyChannel(rechit_layer->at(ihit), rechit_chip->at(ihit), rechit_channel->at(ihit), rechit_x->at(ihit), rechit_y->at(ihit)) ) {
  if( hitmap ) {
  latShower_energy[rechit_layer->at(ihit) - 1]->Fill(rechit_x->at(ihit), rechit_y->at(ihit), 1);
  }
  else {
  latShower_energy[ rechit_layer->at(ihit)-1]->Fill(rechit_x->at(ihit), rechit_y->at(ihit), rechit_energy->at(ihit));}	
  }
  }
  }
  
  //-------------------- End Loop over events --------------------//



  
  //-------------------- Fit & Plots --------------------//

  //Layer_Energy_Sum
  double Layer_Energy_Mean[NLAYER], Layer_Energy_Sigma[NLAYER], Layer_Number[NLAYER];
  
  for(int ilayer = 0; ilayer < NLAYER; ilayer++){
  c4->cd(ilayer+1);
  sprintf(title,"Layer%i",ilayer+1);
  h_TotalEnergy_Layer[ilayer]->SetTitle(title);
  h_TotalEnergy_Layer[ilayer]->GetXaxis()->SetTitle("Energy");
  h_TotalEnergy_Layer[ilayer]->SetLineWidth(5);
  h_TotalEnergy_Layer[ilayer]->Fit(fit_TotalEnergy_Layer_gaussian[ilayer]);
    
  if(fit_TotalEnergy_Layer_gaussian[ilayer]->GetParameter(1)<0){
  Layer_Energy_Mean[ilayer] = 0;
  Layer_Energy_Sigma[ilayer] = 0;
  }
  else {
  Layer_Energy_Mean[ilayer] = fit_TotalEnergy_Layer_gaussian[ilayer]->GetParameter(1);
  Layer_Energy_Sigma[ilayer] = fit_TotalEnergy_Layer_gaussian[ilayer]->GetParameter(2);
  }
    
  Layer_Number[ilayer] = ilayer + 1;
  }
  
  c4->Update();
  sprintf(title,"layer_Energy_Sum%i.png",runN);
  c4->SaveAs(title);

  c5->cd();
  g_TotalEnergy_Layer = new TGraphErrors(NLAYER,Layer_Number,Layer_Energy_Mean,0,Layer_Energy_Sigma);
  g_TotalEnergy_Layer->Draw("AP");
  c5->Update();
  sprintf(title,"LayerEnergy_MeanValue%i.png",runN);
  c5->SaveAs(title);

  //Energy_display

  for(int iL = 0; iL < NLAYER ; ++iL){
  //    latShower_energy[iL]->SetMaximum(10000000);
  if(!ignore_EE){
  c1->cd(iL+1);
  latShower_energy[iL]->Draw("colz");
  }

  else{
  int tmpL = iL+1 - 28 ;
  if(tmpL > 0){
  c1->cd(tmpL);
  latShower_energy[iL]->Draw("colz");
  }
  }
  }
  c1->Update();
  sprintf(title,"energy_display_Run%i.png",runN);
  c1->SaveAs(title);

  // Histograms
  
  c2->cd(1);
  h_TotalEnergy->SetTitle("Total_energy");
  h_TotalEnergy->SetTitleOffset(0.8);
  h_TotalEnergy->SetLineWidth(5);
  h_TotalEnergy->Draw();
  c2->Update();

  c2->cd(2);
  h_CoG_TotalE->SetTitle("CoG_TotalE");
  h_CoG_TotalE->SetTitleOffset(0.8);
  h_CoG_TotalE->GetXaxis()->SetTitle("CoG");
  h_CoG_TotalE->GetYaxis()->SetTitle("TotalE");
  h_CoG_TotalE->Draw("colz");
  c2->Update();


  c2->cd(3);
  h_CoG_TotalE->SetTitle("CoG_NHits");
  h_CoG_NHits->SetTitleOffset(0.8);
  h_CoG_NHits->GetXaxis()->SetTitle("CoG");
  h_CoG_NHits->GetYaxis()->SetTitle("NHits");
  h_CoG_NHits->Draw("colz");
  c2->Update();


  c2->cd(3);
  h_CoG->SetTitle("CoGZ");
  h_CoG->SetTitleOffset(0.8);
  h_CoG->GetXaxis()->SetTitle("CoGZ[cm]");
  h_CoG->Draw();
  c2->Update();
  
  c2->cd(4);
  h_EE_Energy->SetTitle("EE_Energy");
  h_EE_Energy->SetTitleOffset(0.8);
  h_EE_Energy->SetLineWidth(5);
  h_EE_Energy->Draw();
  c2->Update();

  c2->cd(5);
  h_FH_Energy->SetTitle("FH_Energy");
  h_FH_Energy->SetTitleOffset(0.8);
  h_FH_Energy->SetLineWidth(5);
  h_FH_Energy->Draw();
  c2->Update();

  c2->cd(6);
  h_TotalEnergy_TOT->SetTitle("TotalE_TOT");
  h_TotalEnergy_TOT->SetTitleOffset(0.8);
  h_TotalEnergy_TOT->SetLineWidth(5);
  h_TotalEnergy_TOT->Draw();
  c2->Update();

  c2->cd(7);
  h_TotalEnergy_HG->SetTitle("TotalE_HG");
  h_TotalEnergy_HG->SetTitleOffset(0.8);
  h_TotalEnergy_HG->SetLineWidth(5);
  h_TotalEnergy_HG->Draw();
  c2->Update();

  c2->cd(8);
  h_TotalEnergy_LG->SetTitle("TotalE_LG");
  h_TotalEnergy_LG->SetTitleOffset(0.8);
  h_TotalEnergy_LG->SetLineWidth(5);
  h_TotalEnergy_LG->Draw();
  c2->Update();
  
  sprintf(title,"Histograms%i.png",runN);
  c2->SaveAs(title);


  // Mask_NoisyChannel Histograms
  
  c3->cd(1);
  h_TotalEnergy_Mask->SetTitle("Total_energy_Mask");
  h_TotalEnergy_Mask->SetTitleOffset(0.8);
  h_TotalEnergy_Mask->SetLineWidth(5);
  h_TotalEnergy_Mask->Draw();
  c3->Update();

  c3->cd(2);
  h_CoG_TotalE_Mask->SetTitle("CoG_TotalE_Mask");
  h_CoG_TotalE_Mask->SetTitleOffset(0.8);
  h_CoG_TotalE_Mask->GetXaxis()->SetTitle("CoG");
  h_CoG_TotalE_Mask->GetYaxis()->SetTitle("TotalE");
  h_CoG_TotalE_Mask->Draw("colz");
  c3->Update();

  c3->cd(3);
  h_CoG_NHits_Mask->SetTitle("CoG_NHits_Mask");
  h_CoG_NHits_Mask->SetTitleOffset(0.8);
  h_CoG_NHits_Mask->GetXaxis()->SetTitle("CoG");
  h_CoG_NHits_Mask->GetYaxis()->SetTitle("NHits");
  h_CoG_NHits_Mask->Draw("colz");
  c3->Update();

  c3->cd(4);
  h_EE_Energy_Mask->SetTitle("EE_Energy_Mask");
  h_EE_Energy_Mask->SetTitleOffset(0.8);
  h_EE_Energy_Mask->SetLineWidth(5);
  h_EE_Energy_Mask->Draw();
  c3->Update();

  c3->cd(5);
  h_FH_Energy_Mask->SetTitle("FH_Energy_Mask");
  h_FH_Energy_Mask->SetTitleOffset(0.8);
  h_FH_Energy_Mask->SetLineWidth(5);
  h_FH_Energy_Mask->Draw();
  c3->Update();

  c3->cd(6);
  h_TotalEnergy_TOT_Mask->SetTitle("TotalE_TOT_Mask");
  h_TotalEnergy_TOT_Mask->SetTitleOffset(0.8);
  h_TotalEnergy_TOT_Mask->SetLineWidth(5);
  h_TotalEnergy_TOT_Mask->Draw();
  c3->Update();

  c3->cd(7);
  h_TotalEnergy_HG_Mask->SetTitle("TotalE_HG_Mask");
  h_TotalEnergy_HG_Mask->SetTitleOffset(0.8);
  h_TotalEnergy_HG_Mask->SetLineWidth(5);
  h_TotalEnergy_HG_Mask->Draw();
  c3->Update();

  c3->cd(8);
  h_TotalEnergy_LG_Mask->SetTitle("TotalE_LG_Mask");
  h_TotalEnergy_LG_Mask->SetTitleOffset(0.8);
  h_TotalEnergy_LG_Mask->SetLineWidth(5);
  h_TotalEnergy_LG_Mask->Draw();
  c3->Update();
  
  sprintf(title,"Histograms_MaskNoisyChannel%i.png",runN);
  c3->SaveAs(title);

  delete c1;
  delete c2;
  delete c3;

  }
  //============================== End of PlotProducer ==============================//
  */


void makePlots::InitTH2Poly(TH2Poly& poly)
{
	int MAXVERTICES = 6;
	double HexX[MAXVERTICES];
	double HexY[MAXVERTICES];
	int iu,iv,CellXYsize;
	ifstream file("src_txtfile/poly_frame.txt");
	string line;
  
	for(int header = 0; header < 4; ++header )     getline(file,line);
  
	while(true){
		getline(file,line);
		if( file.eof() ) break;
		file >> iu >> iv >> CellXYsize;    
		for(int i = 0; i < CellXYsize ; ++i){
			getline(file,line);
			file >> HexX[i] >> HexY[i];
		}
    
		poly.AddBin(CellXYsize, HexX, HexY);
	}
	file.close();
}

void makePlots::InitTH2Poly_flower(TH2Poly& poly){
	int MAXVERTICES = 6;
	double HexX[MAXVERTICES];
	double HexY[MAXVERTICES];
	double positionX, positionY, centerX, centerY;
	int iu,iv,CellXYsize,Daisy_N;
	ifstream file("src_txtfile/poly_frame.txt");
	string line;
	ifstream daisyfile("src_txtfile/daisy_frame_center_position.txt");

	for(int header = 0; header < 4; ++header )     getline(file,line);
	daisyfile >> Daisy_N;
  
	for(int j = 0; j < Daisy_N ; j++){
		daisyfile >> centerX >> centerY;
		if( file.eof() ) {
			file.clear();
			file.seekg(0, ios::beg);
			for(int header = 0; header < 4; ++header )     getline(file,line);
		} 
		while(!file.eof()){
			file >> iu >> iv >> CellXYsize;
			for(int i = 0; i < CellXYsize ; ++i){
				file >> positionX >> positionY;
				HexX[i] = centerX + positionX;
				HexY[i] = centerY + positionY;
			}
			poly.AddBin(CellXYsize, HexX, HexY);
		}
	}
	file.close();
	daisyfile.close();
}



/*
  void makePlots::InitTH2Poly_flower(TH2Poly& poly)
  {
  //For module Geometry
  double a = 0.6496345; // HGCAL_TB_CELL::FULL_CELL_SIDE,  Size in terms of 1 unit of x/y co-ordinates of a cell side which is 0.064 cm
  double A = 11*a; // One side of a full sensor(neglecting the cut at the MB)
  double x_a = sqrt(3) / 2; // cosine pi/6
  //double y_a = 1 / 2.; // sine pi/6
  double vy_a = 3. / 2;
  double  X0 = 2 * x_a * A; //Translation in Cartesian x for 1 unit of Sensor_iu
  double VX0 = x_a * A; // Cartesian x component of translation for 1 unit of Sensor_iv
  double VY0 = vy_a * A; // Cartesian y component of translation for 1 unit of Sensor_iv
  vector< pair<int,int> > sensor_iu_iv;
  sensor_iu_iv.push_back( make_pair(0,0) );
  sensor_iu_iv.push_back( make_pair(-1,0) );
  sensor_iu_iv.push_back( make_pair(1,0) );
  sensor_iu_iv.push_back( make_pair(0,-1) );
  sensor_iu_iv.push_back( make_pair(0,1) );
  sensor_iu_iv.push_back( make_pair(1,-1) );
  sensor_iu_iv.push_back( make_pair(-1,1) );

  
  double PI = 3.14159265;
  //  double TB_rotate = -PI/2;
  double TB_rotate = -PI/6;
  

    
  //For channel Geometry
  int MAXVERTICES = 6;
  double HexX[MAXVERTICES];
  double HexY[MAXVERTICES];
  int iu,iv,CellXYsize;
  string line;

  double module_centerx = 0;
  double module_centery = 0;
  double rotate_module_centerx = 0;
  double rotate_module_centery = 0;

  for(int moduleID = 0; moduleID < (int)sensor_iu_iv.size(); ++moduleID){
  ifstream file("src_txtfile/poly_frame.txt");
  
  for(int header = 0; header < 4; ++header )     getline(file,line);
  module_centerx = sensor_iu_iv[moduleID].first*X0 + sensor_iu_iv[moduleID].second*VX0;
  module_centery = sensor_iu_iv[moduleID].second*VY0;

  rotate_module_centerx =
  module_centerx * cos(TB_rotate) - module_centery * sin(TB_rotate);
    
  rotate_module_centery =
  module_centerx * sin(TB_rotate) + module_centery * cos(TB_rotate);

  while(true){
  getline(file,line);
  if( file.eof() ) break;
  file >> iu >> iv >> CellXYsize;    
  for(int i = 0; i < CellXYsize ; ++i){
  getline(file,line);
  file >> HexX[i] >> HexY[i];
  HexX[i] += rotate_module_centerx;
  HexY[i] += rotate_module_centery;
  }
    
  poly.AddBin(CellXYsize, HexX, HexY);
  }
  file.close();
  }
  
  }
*/

double* makePlots::Set_X0(double X0_arr[]){

	// len["Cu"] = 1.436; //cm                                  
	// len["W"] = 0.35; //cm                                  
	// len["Lead"] = 0.56; //cm                               
	// len["Pb"] = 0.56; //cm                                 
	// len["CuW"] = 0.43; //cm                                
	// len["Al"] = 8.897; //cm

	// 4-July-2018
	// In all the checks done, Pb is 4.9 mm (~0.875 X0) and 
	// Cu is 6 mm (~0.42 X0)  

	// 10-July-2018
	// Odd layers have this config: 
	// Fe(0.3)-Pb(4.9)-Fe(0.3)-Air (4.6) - PCB - Si
	// Even layers have this config: 
	// Kapton(0.01)-CuW(1.2)-Cu(6)-CuW-Kapton-Si

	// 17-July-2018
	// Fe-Pb-Fe-Air-PCB-Si 
	// Kap-CuW-Cu-CuW-Si

	/*
	// 17-July-2018
	1 0.933   2 0.976   3 0.909   4 0.976   5 0.909
	6 0.976   7 0.909   8 0.976   9 0.909   10 0.976
	11 0.909  12 0.976  13 0.909  14 0.976  15 0.909
	16 1.143  17 0.909  18 0.976  19 0.909  20 1.43
	21 0.909  22 0.976  23 0.909  24 0.976  25 0.909
	26 0.976  27 0.909  28 0.976
	*/
	double single_layer_X0[28];
	for( int i = 0 ; i < 28 ; ++i){
		if ( i % 2 == 0) single_layer_X0[i] = 0.909;
		else single_layer_X0[i] = 0.976;
	}
	single_layer_X0[0]  = 0.933;
	single_layer_X0[15] = 1.143;
	single_layer_X0[19] = 1.43;

	double X0_sum = 0.;
	for(int iL = 0 ; iL < 28 ; ++iL){
		X0_sum += single_layer_X0[iL];
		X0_arr[iL] = X0_sum;
	}
  
	return X0_arr;
}
