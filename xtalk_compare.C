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

    for( int iL = 1; iL <= 28; iL++) {
	TH1D* layer4_E1devE7__1;
	TH1D* layer4_E1devE7__2;
	TH1D* layer4_E1devE7__3;
	sprintf(title,"histo/layer%d/layer%d_E1devE7",iL,iL);
	layer4_E1devE7__1 = (TH1D *)f_MC.Get(title);
	layer4_E1devE7__2 = (TH1D *)f_MC_original.Get(title);
	layer4_E1devE7__3 = (TH1D *)f_Data.Get(title);

    
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
   
	layer4_E1devE7__1->SetStats(0);
	layer4_E1devE7__1->SetLineColor(2);
	layer4_E1devE7__1->SetLineWidth(2);
	layer4_E1devE7__1->SetMarkerColor(2);
	layer4_E1devE7__1->SetMarkerStyle(20);
	layer4_E1devE7__1->SetMarkerSize(0.5);
	layer4_E1devE7__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	layer4_E1devE7__1->GetXaxis()->SetLabelFont(42);
	layer4_E1devE7__1->GetXaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7__1->GetXaxis()->SetLabelSize(0.045);
	layer4_E1devE7__1->GetXaxis()->SetTitleSize(0.052);
	layer4_E1devE7__1->GetXaxis()->SetTitleOffset(1.1);
	layer4_E1devE7__1->GetYaxis()->SetLabelFont(42);
	layer4_E1devE7__1->GetYaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7__1->GetYaxis()->SetLabelSize(0.045);
	layer4_E1devE7__1->GetYaxis()->SetTitleSize(0.045);
	layer4_E1devE7__1->GetYaxis()->SetTitleOffset(1.4);
	layer4_E1devE7__1->GetYaxis()->SetTitleFont(42);
	layer4_E1devE7__1->GetZaxis()->SetLabelFont(42);
	layer4_E1devE7__1->GetZaxis()->SetLabelSize(0.045);
	layer4_E1devE7__1->GetZaxis()->SetTitleSize(0.045);
	layer4_E1devE7__1->GetZaxis()->SetTitleFont(42);
	layer4_E1devE7__1->GetYaxis()->SetRangeUser(0,0.064);
	layer4_E1devE7__1->Draw("HIST");
   
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
   
	layer4_E1devE7__2->SetLineColor(4);
	layer4_E1devE7__2->SetLineWidth(2);
	layer4_E1devE7__2->SetMarkerColor(4);
	layer4_E1devE7__2->SetMarkerStyle(20);
	layer4_E1devE7__2->SetMarkerSize(0.5);
	layer4_E1devE7__2->Draw("HISTSAME");
    
	layer4_E1devE7__3->SetLineWidth(2);
	layer4_E1devE7__3->SetMarkerStyle(20);
	layer4_E1devE7__3->SetMarkerSize(0.5);
	layer4_E1devE7__3->Draw("SAME");

   
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


	// E7 dev E19
	TH1D* layer4_E7devE19__1;
	TH1D* layer4_E7devE19__2;
	TH1D* layer4_E7devE19__3;
	sprintf(title,"histo/layer%d/layer%d_E7devE19",iL,iL);
	layer4_E7devE19__1 = (TH1D *)f_MC.Get(title);
	layer4_E7devE19__2 = (TH1D *)f_MC_original.Get(title);
	layer4_E7devE19__3 = (TH1D *)f_Data.Get(title);

	layer4_E7devE19__1->SetStats(0);
	layer4_E7devE19__1->SetLineColor(2);
	layer4_E7devE19__1->SetLineWidth(2);
	layer4_E7devE19__1->SetMarkerColor(2);
	layer4_E7devE19__1->SetMarkerStyle(20);
	layer4_E7devE19__1->SetMarkerSize(0.5);
	layer4_E7devE19__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	layer4_E7devE19__1->GetXaxis()->SetLabelFont(42);
	layer4_E7devE19__1->GetXaxis()->SetLabelOffset(0.01125);
	layer4_E7devE19__1->GetXaxis()->SetLabelSize(0.045);
	layer4_E7devE19__1->GetXaxis()->SetTitleSize(0.052);
	layer4_E7devE19__1->GetXaxis()->SetTitleOffset(1.1);
	layer4_E7devE19__1->GetYaxis()->SetLabelFont(42);
	layer4_E7devE19__1->GetYaxis()->SetLabelOffset(0.01125);
	layer4_E7devE19__1->GetYaxis()->SetLabelSize(0.045);
	layer4_E7devE19__1->GetYaxis()->SetTitleSize(0.045);
	layer4_E7devE19__1->GetYaxis()->SetTitleOffset(1.4);
	layer4_E7devE19__1->GetYaxis()->SetTitleFont(42);
	layer4_E7devE19__1->GetZaxis()->SetLabelFont(42);
	layer4_E7devE19__1->GetZaxis()->SetLabelSize(0.045);
	layer4_E7devE19__1->GetZaxis()->SetTitleSize(0.045);
	layer4_E7devE19__1->GetZaxis()->SetTitleFont(42);
	layer4_E7devE19__1->GetYaxis()->SetRangeUser(0,0.08);
	layer4_E7devE19__1->Draw("HIST");

	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	pt->Draw();
   
	layer4_E7devE19__2->SetLineColor(4);
	layer4_E7devE19__2->SetLineWidth(2);
	layer4_E7devE19__2->SetMarkerColor(4);
	layer4_E7devE19__2->SetMarkerStyle(20);
	layer4_E7devE19__2->SetMarkerSize(0.5);
	layer4_E7devE19__2->Draw("HISTSAME");
    
	layer4_E7devE19__3->SetLineWidth(2);
	layer4_E7devE19__3->SetMarkerStyle(20);
	layer4_E7devE19__3->SetMarkerSize(0.5);
	layer4_E7devE19__3->Draw("SAME");

   
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


	// COGx
	TH1D* layer4_COGx__1;
	TH1D* layer4_COGx__2;
	TH1D* layer4_COGx__3;
	sprintf(title,"histo/layer%d/layer%d_COGx",iL,iL);
	layer4_COGx__1 = (TH1D *)f_MC.Get(title);
	layer4_COGx__2 = (TH1D *)f_MC_original.Get(title);
	layer4_COGx__3 = (TH1D *)f_Data.Get(title);

	layer4_COGx__1->SetStats(0);
	layer4_COGx__1->SetLineColor(2);
	layer4_COGx__1->SetLineWidth(2);
	layer4_COGx__1->SetMarkerColor(2);
	layer4_COGx__1->SetMarkerStyle(20);
	layer4_COGx__1->SetMarkerSize(0.5);
	layer4_COGx__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	layer4_COGx__1->GetXaxis()->SetLabelFont(42);
	layer4_COGx__1->GetXaxis()->SetLabelOffset(0.01125);
	layer4_COGx__1->GetXaxis()->SetLabelSize(0.045);
	layer4_COGx__1->GetXaxis()->SetTitleSize(0.052);
	layer4_COGx__1->GetXaxis()->SetTitleOffset(1.1);
	layer4_COGx__1->GetYaxis()->SetLabelFont(42);
	layer4_COGx__1->GetYaxis()->SetLabelOffset(0.01125);
	layer4_COGx__1->GetYaxis()->SetLabelSize(0.045);
	layer4_COGx__1->GetYaxis()->SetTitleSize(0.045);
	layer4_COGx__1->GetYaxis()->SetTitleOffset(1.4);
	layer4_COGx__1->GetYaxis()->SetTitleFont(42);
	layer4_COGx__1->GetZaxis()->SetLabelFont(42);
	layer4_COGx__1->GetZaxis()->SetLabelSize(0.045);
	layer4_COGx__1->GetZaxis()->SetTitleSize(0.045);
	layer4_COGx__1->GetZaxis()->SetTitleFont(42);
	layer4_COGx__1->GetYaxis()->SetRangeUser(0,0.08);
	layer4_COGx__1->Draw("HIST");

	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	pt->Draw();
   
	layer4_COGx__2->SetLineColor(4);
	layer4_COGx__2->SetLineWidth(2);
	layer4_COGx__2->SetMarkerColor(4);
	layer4_COGx__2->SetMarkerStyle(20);
	layer4_COGx__2->SetMarkerSize(0.5);
	layer4_COGx__2->Draw("HISTSAME");
    
	layer4_COGx__3->SetLineWidth(2);
	layer4_COGx__3->SetMarkerStyle(20);
	layer4_COGx__3->SetMarkerSize(0.5);
	layer4_COGx__3->Draw("SAME");

   
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

	// COGy
	TH1D* layer4_COGy__1;
	TH1D* layer4_COGy__2;
	TH1D* layer4_COGy__3;
	sprintf(title,"histo/layer%d/layer%d_COGy",iL,iL);
	layer4_COGy__1 = (TH1D *)f_MC.Get(title);
	layer4_COGy__2 = (TH1D *)f_MC_original.Get(title);
	layer4_COGy__3 = (TH1D *)f_Data.Get(title);

	layer4_COGy__1->SetStats(0);
	layer4_COGy__1->SetLineColor(2);
	layer4_COGy__1->SetLineWidth(2);
	layer4_COGy__1->SetMarkerColor(2);
	layer4_COGy__1->SetMarkerStyle(20);
	layer4_COGy__1->SetMarkerSize(0.5);
	layer4_COGy__1->GetXaxis()->SetTitle("E1/E7 containment variable");
	layer4_COGy__1->GetXaxis()->SetLabelFont(42);
	layer4_COGy__1->GetXaxis()->SetLabelOffset(0.01125);
	layer4_COGy__1->GetXaxis()->SetLabelSize(0.045);
	layer4_COGy__1->GetXaxis()->SetTitleSize(0.052);
	layer4_COGy__1->GetXaxis()->SetTitleOffset(1.1);
	layer4_COGy__1->GetYaxis()->SetLabelFont(42);
	layer4_COGy__1->GetYaxis()->SetLabelOffset(0.01125);
	layer4_COGy__1->GetYaxis()->SetLabelSize(0.045);
	layer4_COGy__1->GetYaxis()->SetTitleSize(0.045);
	layer4_COGy__1->GetYaxis()->SetTitleOffset(1.4);
	layer4_COGy__1->GetYaxis()->SetTitleFont(42);
	layer4_COGy__1->GetZaxis()->SetLabelFont(42);
	layer4_COGy__1->GetZaxis()->SetLabelSize(0.045);
	layer4_COGy__1->GetZaxis()->SetTitleSize(0.045);
	layer4_COGy__1->GetZaxis()->SetTitleFont(42);
	layer4_COGy__1->GetYaxis()->SetRangeUser(0,0.08);
	layer4_COGy__1->Draw("HIST");

	ci = 1180;
	color = new TColor(ci, 0, 0, 0, " ", 0);
	pt->SetTextColor(ci);
	pt->SetTextFont(42);
	pt->Draw();
   
	layer4_COGy__2->SetLineColor(4);
	layer4_COGy__2->SetLineWidth(2);
	layer4_COGy__2->SetMarkerColor(4);
	layer4_COGy__2->SetMarkerStyle(20);
	layer4_COGy__2->SetMarkerSize(0.5);
	layer4_COGy__2->Draw("HISTSAME");
    
	layer4_COGy__3->SetLineWidth(2);
	layer4_COGy__3->SetMarkerStyle(20);
	layer4_COGy__3->SetMarkerSize(0.5);
	layer4_COGy__3->Draw("SAME");

   
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
	
    }
}
