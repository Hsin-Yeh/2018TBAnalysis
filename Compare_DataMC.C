int Color(int c)
{
  if(c == 0){ return 633;}
  else if(c == 1){ return 600;}
  else if(c == 2){ return 800;}
  else if(c == 3){ return 419;}
  else if(c == 4){ return 880;}
  else if(c == 5){ return 803;}
  else{ return 0; }
}

void Compare_DataMC(){

  int MAXMODULE = 94;
  int NCHIP = 4;
  int NCHANNEL = 64;
  int imodule = 79;
  int NLAYER = 28;
  
  char title[200];
  char plot_title[200];

  TCanvas* c1 = new TCanvas();
  gStyle->SetOptStat(0);

  sprintf(title,"root_plot/ntuple_sim_config22_pdgID11_beamMomentum20_listFTFP_BERT_EMM_result.root");
  TFile f_MC(title);
  sprintf(title,"root_plot/Run436_20GeV_Ele_result.root");
  TFile f_Data(title);
  
  TH1D *h_E1devE7[2][NLAYER]; 
  TH1D *h_E7devE19[2][NLAYER];
  TH1D *h_totalCEE[2];

  sprintf(title,"h_totalCEE");
  h_totalCEE[0] = (TH1D *)f_MC.Get(title);
  h_totalCEE[0]->SetLineColor(Color(0));
  h_totalCEE[0]->SetLineWidth(2);
  h_totalCEE[1] = (TH1D *)f_Data.Get(title);
  h_totalCEE[1]->SetLineColor(1);
  h_totalCEE[1]->SetLineWidth(2);

  
  for(int iL = 0; iL < NLAYER ; ++iL){
    sprintf(title,"layer%i_E1devE7",iL);
    h_E1devE7[0][iL] = (TH1D *)f_MC.Get(title);
    h_E1devE7[0][iL]->SetLineColor(Color(0));
    h_E1devE7[0][iL]->SetLineWidth(2.0);
    h_E1devE7[1][iL] = (TH1D *)f_Data.Get(title);
    h_E1devE7[1][iL]->SetLineColor(1);
    h_E1devE7[1][iL]->SetLineWidth(2);

  
    sprintf(title,"layer%i_E7devE19",iL);
    h_E7devE19[0][iL] = (TH1D *)f_MC.Get(title);
    h_E7devE19[0][iL]->SetLineColor(Color(0));
    h_E7devE19[0][iL]->SetLineWidth(2.0);
    h_E7devE19[1][iL] = (TH1D *)f_Data.Get(title);
    h_E7devE19[1][iL]->SetLineColor(1);
    h_E7devE19[1][iL]->SetLineWidth(2);

  }

  TLegend* legend = new TLegend(0.1,0.75,0.3,0.9);

  sprintf(title,"Total Energy CEE, %GeV");
  h_totalCEE[0]->SetTitle("Total Energy CEE");
  h_totalCEE[0]->Draw("HIST");
  h_totalCEE[1]->Draw("Same");
  legend->AddEntry(h_totalCEE[0],"XTalk","L");
  legend->AddEntry(h_totalCEE[3],"Data","LP");
  legend->SetTextSize(0.035);
  legend->Draw();
  c1->Update();
  //  gPad->WaitPrimitive();
  sprintf(title,"plots/Total Energy CEE.pdf");
  c1->SaveAs(title);

  for(int iL = 0; iL < NLAYER ; ++iL){
    h_E1devE7[0][iL]->Draw("HIST");
    h_E1devE7[1][iL]->Draw("Same");
    legend->Draw();
    c1->Update();
    //gPad->WaitPrimitive();
    sprintf(title,"plots/layer%d_E1devE7.pdf",iL);
    c1->SaveAs(title);
    h_E7devE19[0][iL]->Draw("HIST");
    h_E7devE19[1][iL]->Draw("Same");
    legend->Draw();
    c1->Update();
    //    gPad->WaitPrimitive();
    sprintf(title,"plots/layer%d_E7devE19.pdf",iL);
    c1->SaveAs(title);
  }
}
