void root_logon(){

  cout << endl << "Welcome to the ATLAS rootlogon.C" << endl;

  //
  // based on a style file from BaBar
  //

  //..BABAR style from RooLogon.C in workdir
  TStyle *atlasStyle= new TStyle("ATLAS","Atlas style");

  // use plain black on white colors
  Int_t icol=0;
  atlasStyle->SetFrameBorderMode(icol);
  atlasStyle->SetCanvasBorderMode(icol);
  atlasStyle->SetPadBorderMode(icol);
  atlasStyle->SetPadColor(icol);
  atlasStyle->SetCanvasColor(icol);
  atlasStyle->SetStatColor(icol);
  //atlasStyle->SetFillColor(icol);

  // set the paper & margin sizes
  atlasStyle->SetPaperSize(20,26);
  atlasStyle->SetPadTopMargin(0.05);
  atlasStyle->SetPadTopMargin(0.11);
  atlasStyle->SetPadRightMargin(0.05);
  atlasStyle->SetPadBottomMargin(0.1);
  atlasStyle->SetPadLeftMargin(0.12);

  // use large fonts
  //Int_t font=72;
  Int_t font=42;
  Double_t tsize=0.045;
  atlasStyle->SetTextFont(font);



  atlasStyle->SetTextSize(tsize);
  atlasStyle->SetLabelFont(font,"x");
  atlasStyle->SetTitleFont(font,"x");
  atlasStyle->SetLabelFont(font,"y");
  atlasStyle->SetTitleFont(font,"y");
  atlasStyle->SetLabelFont(font,"z");
  atlasStyle->SetTitleFont(font,"z");

  atlasStyle->SetLabelSize(tsize,"x");
  atlasStyle->SetTitleSize(tsize,"x");
  atlasStyle->SetLabelSize(tsize,"y");
  atlasStyle->SetTitleSize(tsize,"y");
  atlasStyle->SetLabelSize(tsize,"z");
  atlasStyle->SetTitleSize(tsize,"z");

  atlasStyle->SetLabelOffset(tsize/4,"x");
  atlasStyle->SetLabelOffset(tsize/4,"y");
  


  //use bold lines and markers
  atlasStyle->SetMarkerStyle(20);
  atlasStyle->SetMarkerSize(0.5);
  atlasStyle->SetHistLineWidth(2.);
  atlasStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  //
  atlasStyle->SetLegendFillColor(0);
  atlasStyle->SetLegendFont(62);
  //atlasStyle->SetLegendTextSize(0.03);

  //get rid of X error bars and y error bar caps
  //atlasStyle->SetErrorX(0.001);

  //do not display any of the standard histogram decorations
  //  atlasStyle->SetOptTitle(0);
  //atlasStyle->SetOptStat(1111);
  atlasStyle->SetOptStat(0);
  //atlasStyle->SetOptFit(1111);
  atlasStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  atlasStyle->SetPadTickX(1);
  atlasStyle->SetPadTickY(1);

  //  gROOT->SetStyle("Plain");

  //gStyle->SetPadTickX(1);
  //gStyle->SetPadTickY(1);

  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
}

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
  int Energy;
  
  char title[200];
  char plot_title[200];

  TCanvas* c1 = new TCanvas();
  TCanvas *c2 = new TCanvas("c2","c2",6400,3600);
  TCanvas *c3 = new TCanvas("c3","c3",6400,3600);
  c2->Divide(7,4);
  c3->Divide(7,4);
  //  gStyle->SetOptStat(0);
  //  gROOT->SetBatch(kTRUE);
  TImage *img = TImage::Create();
  
  root_logon();

  string filename;
  ifstream infile("data_input.txt");
  infile >> filename;
  int start = filename.find_last_of("/");
  int end = filename.find(".root");
  string f_substr = filename.substr(start+1,end-start-1);

  start = filename.find("sim_");
  end = filename.find("GeV");
  Energy = std::stoi(filename.substr(start+4,end-start-4));

  cout << "Energy = " << Energy << " GeV " << endl;

  sprintf(title,"%s",filename.c_str());
  TFile f_MC(title);
  sprintf(title,"root_plot/plot_data_%dGeV_Ele.root",Energy);
  TFile f_Data(title);
  sprintf(title,"root_plot/plot_ntuple_sim_config22_pdgID11_beamMomentum%d_listFTFP_BERT_EMM.root",Energy);
  TFile f_MC_original(title);

  sprintf(title,"output.root");
  TFile f_output(title,"recreate");

  TH1D *h_E1devE7[3][28];
  TH1D *h_E7devE19[3][28];
  TH1D *h_totalCEE[3];

  sprintf(title,"h_totalCEE");
  h_totalCEE[0] = (TH1D *)f_MC.Get(title);
  h_totalCEE[0]->SetLineColor(Color(0));
  h_totalCEE[0]->SetLineWidth(2);
  h_totalCEE[1] = (TH1D *)f_MC_original.Get(title);
  h_totalCEE[1]->SetLineColor(4);
  h_totalCEE[1]->SetLineWidth(2);
  h_totalCEE[2] = (TH1D *)f_Data.Get(title);
  h_totalCEE[2]->SetLineColor(1);
  h_totalCEE[2]->SetLineWidth(2);

  
  for(int iL = 0; iL < NLAYER ; ++iL){
    sprintf(title,"layer%i_E1devE7",iL);
    h_E1devE7[0][iL] = (TH1D *)f_MC.Get(title);
    h_E1devE7[0][iL]->SetLineColor(Color(0));
    h_E1devE7[0][iL]->SetLineWidth(2.0);
    h_E1devE7[1][iL] = (TH1D *)f_MC_original.Get(title);
    h_E1devE7[1][iL]->SetLineColor(4);
    h_E1devE7[1][iL]->SetLineWidth(2);
    h_E1devE7[2][iL] = (TH1D *)f_Data.Get(title);
    h_E1devE7[2][iL]->SetLineColor(1);
    h_E1devE7[2][iL]->SetLineWidth(2);
    

  
    sprintf(title,"layer%i_E7devE19",iL);
    h_E7devE19[0][iL] = (TH1D *)f_MC.Get(title);
    h_E7devE19[0][iL]->SetLineColor(Color(0));
    h_E7devE19[0][iL]->SetLineWidth(2.0);
    h_E7devE19[1][iL] = (TH1D *)f_MC_original.Get(title);
    h_E7devE19[1][iL]->SetLineColor(4);
    h_E7devE19[1][iL]->SetLineWidth(2);
    h_E7devE19[2][iL] = (TH1D *)f_Data.Get(title);
    h_E7devE19[2][iL]->SetLineColor(1);
    h_E7devE19[2][iL]->SetLineWidth(2);

  }
  
  TLegend* legend = new TLegend(0.1,0.75,0.3,0.9);
  c1->cd();
  
  sprintf(title,"Total Energy CEE ");
  h_totalCEE[0]->SetTitle("Total Energy CEE");
  h_totalCEE[0]->Draw("HIST");
  h_totalCEE[1]->Draw("HISTSame");
  h_totalCEE[2]->Draw("Same");
  legend->AddEntry(h_totalCEE[0],"Simulation","L");
  //legend->AddEntry(h_totalCEE[1],"Without XTalk","L");
  legend->AddEntry(h_totalCEE[2],"Data","LP");
  //  sprintf(title,"beamE=%dGeV",Energy);
  //  legend->SetHeader(title);
  legend->SetTextSize(0.035);
  legend->Draw();
  c1->Update();
  //gPad->WaitPrimitive();
  sprintf(title,"plots/%dGeV/Total Energy CEE.png",Energy);
  //  c1->SaveAs(title);
  img->FromPad(c1);
  img->WriteImage(title);



  for(int iL = 0; iL < NLAYER ; ++iL){

	//c2->cd(iL+1);
	sprintf(title,"E1devE7_layer%02d_%dGeV", iL+1, Energy);
	//h_E1devE7[0][iL]->GetYaxis()->SetRangeUser(0,0.06);
	//h_E1devE7[1][iL]->GetYaxis()->SetRangeUser(0,0.06);
	//h_E1devE7[2][iL]->GetYaxis()->SetRangeUser(0,0.06);
	h_E1devE7[0][iL]->SetTitle(title);
    h_E1devE7[0][iL]->Draw("HIST");
    //h_E1devE7[1][iL]->Draw("HISTSame");
    h_E1devE7[2][iL]->Draw("Same");
    legend->Draw();
	c1->Update();
    //c2->Update();
	//c2->Write();
	//gPad->WaitPrimitive();
    sprintf(title,"plots/%s/E1devE7_layer%02d.png", f_substr, Energy, iL+1);
    img->FromPad(c1);
    img->WriteImage(title);
	//c1->SaveAs(title);

	//c3->cd(iL+1);
	sprintf(title,"E7devE19_layer%02d_%dGeV", iL+1, Energy);
	h_E7devE19[0][iL]->SetTitle(title);
	//h_E7devE19[0][iL]->GetYaxis()->SetRangeUser(0,0.09);
	//h_E7devE19[1][iL]->GetYaxis()->SetRangeUser(0,0.09);
	//h_E7devE19[2][iL]->GetYaxis()->SetRangeUser(0,0.09);
    h_E7devE19[0][iL]->Draw("HIST");
    //h_E7devE19[1][iL]->Draw("HISTSame");
    h_E7devE19[2][iL]->Draw("Same");
    legend->Draw();
    sprintf(title,"Beam Energy = %dGeV",Energy);
	c1->Update();
    //c3->Update();
	//c1->Write();
    //gPad->WaitPrimitive();
    sprintf(title,"plots/%s/E7devE19_layer%02d.png", f_substr, Energy, iL+1);
    img->FromPad(c1);
    img->WriteImage(title);
    //c1->SaveAs(title);
  }
  //c2->Write();
  //c3->Write();

  f_output.Write();
  f_output.Close();
  
  delete c1;

}
