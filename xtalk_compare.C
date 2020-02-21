void xtalk_compare(int Energy)
{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Tue Oct 15 20:48:04 2019) by ROOT version6.10/04

    char title[200];
    //int Energy = 300;
    
    sprintf(title,"root_plot/plot_sim_%dGeV_EMN.root",Energy);
    TFile f_MC(title);
    sprintf(title,"root_plot/plot_data_%dGeV_Ele.root",Energy);
    TFile f_Data(title);
    sprintf(title,"root_plot/plot_ntuple_sim_config22_pdgID11_beamMomentum%d_listFTFP_BERT_EMN.root",Energy);
    TFile f_MC_original(title);

    int NLAYER = 28;
    double chi_cross_COGx[NLAYER], chi_cross_COGy[NLAYER], chi_cross_E1devE7[NLAYER], chi_cross_E7devE19[NLAYER];
    double chi_original_COGx[NLAYER], chi_original_COGy[NLAYER], chi_original_E1devE7[NLAYER], chi_original_E7devE19[NLAYER];
    double layerID[NLAYER];

    for( int iL = 1; iL <= 28; iL++) {
	
	layerID[iL-1] = iL;
	
	TH1D* E1devE7__1;
	TH1D* E1devE7__2;
	TH1D* E1devE7__3;
	sprintf(title,"histo/layer%d/layer%d_E1devE7",iL,iL);
	E1devE7__1 = (TH1D *)f_MC.Get(title);
	E1devE7__2 = (TH1D *)f_MC_original.Get(title);
	E1devE7__3 = (TH1D *)f_Data.Get(title);

    
	TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",333,105,837,583);
	Canvas_1->Range(-0.127676,-0.01502931,1.140176,0.07874052);
	Canvas_1->SetFillColor(0);
	Canvas_1->SetBorderMode(0);
	Canvas_1->SetBorderSize(2);
	Canvas_1->SetTopMargin(0.08013938);
	Canvas_1->SetBottomMargin(0.1602788);
	Canvas_1->SetFrameBorderMode(0);
	Canvas_1->SetFrameLineWidth(2);
	Canvas_1->SetFrameBorderMode(0);
   
	E1devE7__1->SetStats(0);
	E1devE7__1->SetLineColor(2);
	E1devE7__1->SetLineWidth(2);
	E1devE7__1->SetMarkerColor(2);
	E1devE7__1->SetMarkerStyle(20);
	E1devE7__1->SetMarkerSize(0.5);
	E1devE7__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	E1devE7__1->GetXaxis()->SetLabelFont(42);
	E1devE7__1->GetXaxis()->SetLabelOffset(0.01125);
	E1devE7__1->GetXaxis()->SetLabelSize(0.045);
	E1devE7__1->GetXaxis()->SetTitleSize(0.052);
	E1devE7__1->GetXaxis()->SetTitleOffset(1.1);
	E1devE7__1->GetYaxis()->SetLabelFont(42);
	E1devE7__1->GetYaxis()->SetLabelOffset(0.01125);
	E1devE7__1->GetYaxis()->SetLabelSize(0.045);
	E1devE7__1->GetYaxis()->SetTitleSize(0.045);
	E1devE7__1->GetYaxis()->SetTitleOffset(1.4);
	E1devE7__1->GetYaxis()->SetTitleFont(42);
	E1devE7__1->GetZaxis()->SetLabelFont(42);
	E1devE7__1->GetZaxis()->SetLabelSize(0.045);
	E1devE7__1->GetZaxis()->SetTitleSize(0.045);
	E1devE7__1->GetZaxis()->SetTitleFont(42);
	E1devE7__1->GetYaxis()->SetRangeUser(0,0.064);
	E1devE7__1->Draw("HIST");
   
	TPaveText *pt = new TPaveText(0.2230294,0.9363613,0.3672606,0.995,"blNDC");
	pt->SetName("title");
	pt->SetBorderSize(0);
	pt->SetFillColor(0);
	pt->SetFillStyle(0);

	Int_t ci;      // for color index setting
	TColor *color; // for color definition with alpha
	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	TText *pt_LaTex = pt->AddText("w/  xtalk");
	pt->Draw();
   
	E1devE7__2->SetLineColor(4);
	E1devE7__2->SetLineWidth(2);
	E1devE7__2->SetMarkerColor(4);
	E1devE7__2->SetMarkerStyle(20);
	E1devE7__2->SetMarkerSize(0.5);
	E1devE7__2->Draw("HISTSAME");
    
	E1devE7__3->SetLineWidth(2);
	E1devE7__3->SetMarkerStyle(20);
	E1devE7__3->SetMarkerSize(0.5);
	E1devE7__3->Draw("SAME");

   
	TLegend *leg = new TLegend(0.13,0.7,0.43,0.9,NULL,"brNDC");
	leg->SetBorderSize(1);

	ci = TColor::GetColor("#000000");
	leg->SetTextColor(ci);
	leg->SetTextFont(62);
	

	ci = 1183;
	color = new TColor(ci, 0, 0, 0, " ", 0.011);
	leg->SetLineColor(ci);
	leg->SetLineStyle(1);
	leg->SetLineWidth(1);
	ci = 1180;
	color = new TColor(ci, 1, 1, 1, " ", 0);
	leg->SetFillColor(ci);
	leg->SetFillStyle(1001);
	TLegendEntry *entry=leg->AddEntry("","with xtalk","lpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(2);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(2);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg->AddEntry("","no xtalk","lpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(4);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(4);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg->AddEntry("","data","lpflpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(1);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(1);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	sprintf(title,"TB2018 %dGeV layer%d",Energy, iL);
        leg->SetHeader(title);
	leg->Draw();
	Canvas_1->Update();	

	sprintf(title,"plots/%dGeV/%dGeV_E1devE7_layer%02d.png", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	sprintf(title,"plots/%dGeV/%dGeV_E1devE7_layer%02d.pdf", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	//gPad->WaitPrimitive();

    
	Canvas_1->Modified();
	Canvas_1->cd();
	Canvas_1->SetSelected(Canvas_1);
	
	chi_cross_E1devE7[iL-1]    = E1devE7__3->Chi2Test(E1devE7__1,"UW CHI2/NDF");
	chi_original_E1devE7[iL-1] = E1devE7__3->Chi2Test(E1devE7__2,"UW CHI2/NDF");

	// E7 dev E19
	TH1D* E7devE19__1;
	TH1D* E7devE19__2;
	TH1D* E7devE19__3;
	sprintf(title,"histo/layer%d/layer%d_E7devE19",iL,iL);
	E7devE19__1 = (TH1D *)f_MC.Get(title);
	E7devE19__2 = (TH1D *)f_MC_original.Get(title);
	E7devE19__3 = (TH1D *)f_Data.Get(title);

	E7devE19__1->SetStats(0);
	E7devE19__1->SetLineColor(2);
	E7devE19__1->SetLineWidth(2);
	E7devE19__1->SetMarkerColor(2);
	E7devE19__1->SetMarkerStyle(20);
	E7devE19__1->SetMarkerSize(0.5);
	E7devE19__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	E7devE19__1->GetXaxis()->SetLabelFont(42);
	E7devE19__1->GetXaxis()->SetLabelOffset(0.01125);
	E7devE19__1->GetXaxis()->SetLabelSize(0.045);
	E7devE19__1->GetXaxis()->SetTitleSize(0.052);
	E7devE19__1->GetXaxis()->SetTitleOffset(1.1);
	E7devE19__1->GetYaxis()->SetLabelFont(42);
	E7devE19__1->GetYaxis()->SetLabelOffset(0.01125);
	E7devE19__1->GetYaxis()->SetLabelSize(0.045);
	E7devE19__1->GetYaxis()->SetTitleSize(0.045);
	E7devE19__1->GetYaxis()->SetTitleOffset(1.4);
	E7devE19__1->GetYaxis()->SetTitleFont(42);
	E7devE19__1->GetZaxis()->SetLabelFont(42);
	E7devE19__1->GetZaxis()->SetLabelSize(0.045);
	E7devE19__1->GetZaxis()->SetTitleSize(0.045);
	E7devE19__1->GetZaxis()->SetTitleFont(42);
	//E7devE19__1->GetYaxis()->SetRangeUser(0,0.095);
	E7devE19__1->Draw("HIST");

	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	pt->Draw();
   
	E7devE19__2->SetLineColor(4);
	E7devE19__2->SetLineWidth(2);
	E7devE19__2->SetMarkerColor(4);
	E7devE19__2->SetMarkerStyle(20);
	E7devE19__2->SetMarkerSize(0.5);
	E7devE19__2->Draw("HISTSAME");
    
	E7devE19__3->SetLineWidth(2);
	E7devE19__3->SetMarkerStyle(20);
	E7devE19__3->SetMarkerSize(0.5);
	E7devE19__3->Draw("SAME");

   
	TLegend *leg_E7devE19 = new TLegend(0.13,0.7,0.43,0.9,NULL,"brNDC");
	leg_E7devE19->SetBorderSize(1);

	ci = TColor::GetColor("#000000");
	leg_E7devE19->SetTextColor(ci);
	leg_E7devE19->SetTextFont(62);
	

	ci = 1183;
	color = new TColor(ci, 0, 0, 0, " ", 0.011);
	leg_E7devE19->SetLineColor(ci);
	leg_E7devE19->SetLineStyle(1);
	leg_E7devE19->SetLineWidth(1);
	ci = 1180;
	color = new TColor(ci, 1, 1, 1, " ", 0);
	leg_E7devE19->SetFillColor(ci);
	leg_E7devE19->SetFillStyle(1001);
	entry=leg_E7devE19->AddEntry("","with xtalk","lpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(2);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(2);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg_E7devE19->AddEntry("","no xtalk","lpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(4);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(4);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg_E7devE19->AddEntry("","data","lpflpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(1);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(1);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	sprintf(title,"TB2018 %dGeV layer%d",Energy, iL);
        leg_E7devE19->SetHeader(title);
	leg_E7devE19->Draw();
	Canvas_1->Update();	

	sprintf(title,"plots/%dGeV/%dGeV_E7devE19_layer%02d.png", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	sprintf(title,"plots/%dGeV/%dGeV_E7devE19_layer%02d.pdf", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	//gPad->WaitPrimitive();

    
	Canvas_1->Modified();
	Canvas_1->cd();
	Canvas_1->SetSelected(Canvas_1);

	// chi square test
	chi_cross_E7devE19[iL-1]    = E7devE19__3->Chi2Test(E7devE19__1,"UW CHI2/NDF");
	chi_original_E7devE19[iL-1] = E7devE19__3->Chi2Test(E7devE19__2,"UW CHI2/NDF");

	// ========== COGx ========== //
	TH1D* COGx__1;
	TH1D* COGx__2;
	TH1D* COGx__3;
	sprintf(title,"histo/layer%d/layer%d_COGx",iL,iL);
	COGx__1 = (TH1D *)f_MC.Get(title);
	COGx__2 = (TH1D *)f_MC_original.Get(title);
	COGx__3 = (TH1D *)f_Data.Get(title);

	COGx__1->SetStats(0);
	COGx__1->SetLineColor(2);
	COGx__1->SetLineWidth(2);
	COGx__1->SetMarkerColor(2);
	COGx__1->SetMarkerStyle(20);
	COGx__1->SetMarkerSize(0.5);
	COGx__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	COGx__1->GetXaxis()->SetLabelFont(42);
	COGx__1->GetXaxis()->SetLabelOffset(0.01125);
	COGx__1->GetXaxis()->SetLabelSize(0.045);
	COGx__1->GetXaxis()->SetTitleSize(0.052);
	COGx__1->GetXaxis()->SetTitleOffset(1.1);
	COGx__1->GetYaxis()->SetLabelFont(42);
	COGx__1->GetYaxis()->SetLabelOffset(0.01125);
	COGx__1->GetYaxis()->SetLabelSize(0.045);
	COGx__1->GetYaxis()->SetTitleSize(0.045);
	COGx__1->GetYaxis()->SetTitleOffset(1.4);
	COGx__1->GetYaxis()->SetTitleFont(42);
	COGx__1->GetZaxis()->SetLabelFont(42);
	COGx__1->GetZaxis()->SetLabelSize(0.045);
	COGx__1->GetZaxis()->SetTitleSize(0.045);
	COGx__1->GetZaxis()->SetTitleFont(42);
	//COGx__1->GetYaxis()->SetRangeUser(0,0.08);
	COGx__1->Draw();

	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	pt->Draw();
   
	COGx__2->SetLineColor(4);
	COGx__2->SetLineWidth(2);
	COGx__2->SetMarkerColor(4);
	COGx__2->SetMarkerStyle(20);
	COGx__2->SetMarkerSize(0.5);
	COGx__2->Draw("SAME");
    
	COGx__3->SetLineWidth(2);
	COGx__3->SetMarkerStyle(20);
	COGx__3->SetMarkerSize(0.5);
	COGx__3->Draw("SAME");

   
	TLegend *leg_COGx = new TLegend(0.13,0.7,0.43,0.9,NULL,"brNDC");
	leg_COGx->SetBorderSize(1);

	ci = TColor::GetColor("#000000");
	leg_COGx->SetTextColor(ci);
	leg_COGx->SetTextFont(62);
	

	ci = 1183;
	color = new TColor(ci, 0, 0, 0, " ", 0.011);
	leg_COGx->SetLineColor(ci);
	leg_COGx->SetLineStyle(1);
	leg_COGx->SetLineWidth(1);
	ci = 1180;
	color = new TColor(ci, 1, 1, 1, " ", 0);
	leg_COGx->SetFillColor(ci);
	leg_COGx->SetFillStyle(1001);
	entry=leg_COGx->AddEntry("","with xtalk","lpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(2);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(2);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg_COGx->AddEntry("","no xtalk","lpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(4);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(4);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg_COGx->AddEntry("","data","lpflpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(1);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(1);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	sprintf(title,"TB2018 %dGeV layer%d",Energy, iL);
        leg_COGx->SetHeader(title);
	leg_COGx->Draw();
	Canvas_1->Update();	

	sprintf(title,"plots/%dGeV/%dGeV_COGx_layer%02d.png", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	sprintf(title,"plots/%dGeV/%dGeV_COGx_layer%02d.pdf", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	//gPad->WaitPrimitive();

    
	Canvas_1->Modified();
	Canvas_1->cd();
	Canvas_1->SetSelected(Canvas_1);

	// chi square test
	chi_cross_COGx[iL-1]    = COGx__3->Chi2Test(COGx__1,"UW CHI2/NDF");
	chi_original_COGx[iL-1] = COGx__3->Chi2Test(COGx__2,"UW CHI2/NDF");

	// ========== COGy ========== //
	TH1D* COGy__1;
	TH1D* COGy__2;
	TH1D* COGy__3;
	sprintf(title,"histo/layer%d/layer%d_COGy",iL,iL);
	COGy__1 = (TH1D *)f_MC.Get(title);
	COGy__2 = (TH1D *)f_MC_original.Get(title);
	COGy__3 = (TH1D *)f_Data.Get(title);

	COGy__1->SetStats(0);
	COGy__1->SetLineColor(2);
	COGy__1->SetLineWidth(2);
	COGy__1->SetMarkerColor(2);
	COGy__1->SetMarkerStyle(20);
	COGy__1->SetMarkerSize(0.5);
	COGy__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	COGy__1->GetXaxis()->SetLabelFont(42);
	COGy__1->GetXaxis()->SetLabelOffset(0.01125);
	COGy__1->GetXaxis()->SetLabelSize(0.045);
	COGy__1->GetXaxis()->SetTitleSize(0.052);
	COGy__1->GetXaxis()->SetTitleOffset(1.1);
	COGy__1->GetYaxis()->SetLabelFont(42);
	COGy__1->GetYaxis()->SetLabelOffset(0.01125);
	COGy__1->GetYaxis()->SetLabelSize(0.045);
	COGy__1->GetYaxis()->SetTitleSize(0.045);
	COGy__1->GetYaxis()->SetTitleOffset(1.4);
	COGy__1->GetYaxis()->SetTitleFont(42);
	COGy__1->GetZaxis()->SetLabelFont(42);
	COGy__1->GetZaxis()->SetLabelSize(0.045);
	COGy__1->GetZaxis()->SetTitleSize(0.045);
	COGy__1->GetZaxis()->SetTitleFont(42);
	//COGy__1->GetYaxis()->SetRangeUser(0,0.08);
	COGy__1->Draw();

	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	pt->Draw();
   
	COGy__2->SetLineColor(4);
	COGy__2->SetLineWidth(2);
	COGy__2->SetMarkerColor(4);
	COGy__2->SetMarkerStyle(20);
	COGy__2->SetMarkerSize(0.5);
	COGy__2->Draw("SAME");
    
	COGy__3->SetLineWidth(2);
	COGy__3->SetMarkerStyle(20);
	COGy__3->SetMarkerSize(0.5);
	COGy__3->Draw("SAME");

   
	TLegend *leg_COGy = new TLegend(0.13,0.7,0.43,0.9,NULL,"brNDC");
	leg_COGy->SetBorderSize(1);

	ci = TColor::GetColor("#000000");
	leg_COGy->SetTextColor(ci);
	leg_COGy->SetTextFont(62);
	

	ci = 1183;
	color = new TColor(ci, 0, 0, 0, " ", 0.011);
	leg_COGy->SetLineColor(ci);
	leg_COGy->SetLineStyle(1);
	leg_COGy->SetLineWidth(1);
	ci = 1180;
	color = new TColor(ci, 1, 1, 1, " ", 0);
	leg_COGy->SetFillColor(ci);
	leg_COGy->SetFillStyle(1001);
	entry=leg_COGy->AddEntry("","with xtalk","lpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(2);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(2);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg_COGy->AddEntry("","no xtalk","lpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(4);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(4);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg_COGy->AddEntry("","data","lpflpflpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(1);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(1);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	sprintf(title,"TB2018 %dGeV layer%d",Energy, iL);
        leg_COGy->SetHeader(title);
	leg_COGy->Draw();
	Canvas_1->Update();	

	sprintf(title,"plots/%dGeV/%dGeV_COGy_layer%02d.png", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	sprintf(title,"plots/%dGeV/%dGeV_COGy_layer%02d.pdf", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	//gPad->WaitPrimitive();

    
	Canvas_1->Modified();
	Canvas_1->cd();
	Canvas_1->SetSelected(Canvas_1);

	// chi square test
	chi_cross_COGy[iL-1]    = COGy__3->Chi2Test(COGy__1,"UW CHI2/NDF");
	chi_original_COGy[iL-1] = COGy__3->Chi2Test(COGy__2,"UW CHI2/NDF");



	// E1devE7 vs layerE/TotalE

	TH2D* E1devE7_layerEdevTotalE__1;
	TH2D* E1devE7_layerEdevTotalE__2;
	TH2D* E1devE7_layerEdevTotalE__3;
	sprintf(title,"histo/layer%d/layer%i_E1devE7_layerEdevTotalE",iL,iL);
	E1devE7_layerEdevTotalE__1 = (TH2D *)f_MC.Get(title);
	E1devE7_layerEdevTotalE__2 = (TH2D *)f_MC_original.Get(title);
	E1devE7_layerEdevTotalE__3 = (TH2D *)f_Data.Get(title);

	E1devE7_layerEdevTotalE__3->SetStats(0);
	E1devE7_layerEdevTotalE__3->SetLineColor(2);
	E1devE7_layerEdevTotalE__3->SetLineWidth(2);
	E1devE7_layerEdevTotalE__3->SetMarkerColor(2);
	E1devE7_layerEdevTotalE__3->SetMarkerStyle(20);
	E1devE7_layerEdevTotalE__3->SetMarkerSize(0.5);
	E1devE7_layerEdevTotalE__3->GetXaxis()->SetTitle("E1/E7 containment variable");
	E1devE7_layerEdevTotalE__3->GetXaxis()->SetLabelFont(42);
	E1devE7_layerEdevTotalE__3->GetXaxis()->SetLabelOffset(0.01125);
	E1devE7_layerEdevTotalE__3->GetXaxis()->SetLabelSize(0.045);
	E1devE7_layerEdevTotalE__3->GetXaxis()->SetTitleSize(0.052);
	E1devE7_layerEdevTotalE__3->GetXaxis()->SetTitleOffset(1.1);
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetTitle("layerE/TotalE containment variable");
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetLabelFont(42);
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetLabelOffset(0.01125);
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetLabelSize(0.045);
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetTitleSize(0.045);
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetTitleOffset(1.4);
	E1devE7_layerEdevTotalE__3->GetYaxis()->SetTitleFont(42);
	E1devE7_layerEdevTotalE__3->GetZaxis()->SetLabelFont(42);
	E1devE7_layerEdevTotalE__3->GetZaxis()->SetLabelSize(0.045);
	E1devE7_layerEdevTotalE__3->GetZaxis()->SetTitleSize(0.045);
	E1devE7_layerEdevTotalE__3->GetZaxis()->SetTitleFont(42);
	E1devE7_layerEdevTotalE__3->Draw();
	Canvas_1->Update();
	sprintf(title,"plots/%dGeV/%dGeV_E1devE7_layerEdevTotalE_layer%02d.png", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	sprintf(title,"plots/%dGeV/%dGeV_E1devE7_layerEdevTotalE_layer%02d.pdf", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	
	
    }

    // ========== chi square plot ========== //
    TCanvas* c4 = new TCanvas();
    TGraph* g_chi_cross_E1devE7 = new TGraph(NLAYER, layerID, chi_cross_E1devE7); 
    g_chi_cross_E1devE7->SetMarkerColor(2);
    g_chi_cross_E1devE7->SetMarkerStyle(20);
    g_chi_cross_E1devE7->SetFillColor(0);
    g_chi_cross_E1devE7->SetTitle("w/ xtalk");
    TGraph* g_chi_original_E1devE7 = new TGraph(NLAYER, layerID, chi_original_E1devE7);
    g_chi_original_E1devE7->SetTitle("w/o xtalk");
    g_chi_original_E1devE7->SetFillColor(0);
    g_chi_original_E1devE7->SetMarkerStyle(20);
    g_chi_original_E1devE7->SetMarkerColor(4);
    TMultiGraph* multi_chi_E1devE7 = new TMultiGraph();
    multi_chi_E1devE7->Add(g_chi_cross_E1devE7);
    multi_chi_E1devE7->Add(g_chi_original_E1devE7);
    sprintf(title,"Chi2Test_%dGeV_E1devE7",Energy);
    multi_chi_E1devE7->SetTitle(title);
    multi_chi_E1devE7->Draw("AP");
    multi_chi_E1devE7->GetXaxis()->SetTitle("layerID");
    multi_chi_E1devE7->GetYaxis()->SetTitle("Chi2 / NDF");
    multi_chi_E1devE7->GetYaxis()->SetTitleOffset(1);
    c4->BuildLegend(0.7,0.7,0.85,0.85);
    c4->Update();
    sprintf(title,"plots/%dGeV/chi2_compareE1devE7_%dGeV.png", Energy, Energy);
    c4->SaveAs(title);

    
    TGraph* g_chi_cross_E7devE19 = new TGraph(NLAYER, layerID, chi_cross_E7devE19);
    g_chi_cross_E7devE19->SetMarkerColor(2);
    g_chi_cross_E7devE19->SetMarkerStyle(20);
    g_chi_cross_E7devE19->SetFillColor(0);
    g_chi_cross_E7devE19->SetTitle("w/ xtalk");
    TGraph* g_chi_original_E7devE19 = new TGraph(NLAYER, layerID, chi_original_E7devE19);
    g_chi_original_E7devE19->SetTitle("w/o xtalk");
    g_chi_original_E7devE19->SetFillColor(0);
    g_chi_original_E7devE19->SetMarkerStyle(20);
    g_chi_original_E7devE19->SetMarkerColor(4);
    TMultiGraph* multi_chi_E7devE19 = new TMultiGraph();
    multi_chi_E7devE19->Add(g_chi_cross_E7devE19);
    multi_chi_E7devE19->Add(g_chi_original_E7devE19);
    sprintf(title,"Chi2Test_%dGeV_E7devE19",Energy);
    multi_chi_E7devE19->SetTitle(title);
    multi_chi_E7devE19->Draw("AP");
    multi_chi_E7devE19->GetXaxis()->SetTitle("layerID");
    multi_chi_E7devE19->GetYaxis()->SetTitle("Chi2 / NDF");
    multi_chi_E7devE19->GetYaxis()->SetTitleOffset(1);
    c4->BuildLegend(0.7,0.7,0.85,0.85);
    c4->Update();
    sprintf(title,"plots/%dGeV/chi2_compareE7devE19_%dGeV.png", Energy, Energy);
    c4->SaveAs(title);

    TGraph* g_chi_cross_COGx = new TGraph(NLAYER, layerID, chi_cross_COGx);
    g_chi_cross_COGx->SetMarkerColor(2);
    g_chi_cross_COGx->SetMarkerStyle(20);
    g_chi_cross_COGx->SetFillColor(0);
    g_chi_cross_COGx->SetTitle("w/ xtalk");
    TGraph* g_chi_original_COGx = new TGraph(NLAYER, layerID, chi_original_COGx);
    g_chi_original_COGx->SetTitle("w/o xtalk");
    g_chi_original_COGx->SetFillColor(0);
    g_chi_original_COGx->SetMarkerStyle(20);
    g_chi_original_COGx->SetMarkerColor(4);
    TMultiGraph* multi_chi_COGx = new TMultiGraph();
    multi_chi_COGx->Add(g_chi_cross_COGx);
    multi_chi_COGx->Add(g_chi_original_COGx);
    sprintf(title,"Chi2Test_%dGeV_COGx",Energy);
    multi_chi_COGx->SetTitle(title);
    multi_chi_COGx->Draw("AP");
    multi_chi_COGx->GetXaxis()->SetTitle("layerID");
    multi_chi_COGx->GetYaxis()->SetTitle("Chi2 / NDF");
    multi_chi_COGx->GetYaxis()->SetTitleOffset(1);
    c4->BuildLegend(0.7,0.7,0.85,0.85);
    c4->Update();
    sprintf(title,"plots/%dGeV/chi2_compareCOGx_%dGeV.png", Energy, Energy);
    c4->SaveAs(title);

    TGraph* g_chi_cross_COGy = new TGraph(NLAYER, layerID, chi_cross_COGy);
    g_chi_cross_COGy->SetMarkerColor(2);
    g_chi_cross_COGy->SetMarkerStyle(20);
    g_chi_cross_COGy->SetFillColor(0);
    g_chi_cross_COGy->SetTitle("w/ xtalk");
    TGraph* g_chi_original_COGy = new TGraph(NLAYER, layerID, chi_original_COGy);
    g_chi_original_COGy->SetTitle("w/o xtalk");
    g_chi_original_COGy->SetFillColor(0);
    g_chi_original_COGy->SetMarkerStyle(20);
    g_chi_original_COGy->SetMarkerColor(4);
    TMultiGraph* multi_chi_COGy = new TMultiGraph();
    multi_chi_COGy->Add(g_chi_cross_COGy);
    multi_chi_COGy->Add(g_chi_original_COGy);
    sprintf(title,"Chi2Test_%dGeV_COGy",Energy);
    multi_chi_COGy->SetTitle(title);
    multi_chi_COGy->Draw("AP");
    multi_chi_COGy->GetXaxis()->SetTitle("layerID");
    multi_chi_COGy->GetYaxis()->SetTitle("Chi2 / NDF");
    multi_chi_COGy->GetYaxis()->SetTitleOffset(1);
    c4->BuildLegend(0.7,0.7,0.85,0.85);
    c4->Update();
    sprintf(title,"plots/%dGeV/chi2_compareCOGy_%dGeV.png", Energy, Energy);
    c4->SaveAs(title);

}
