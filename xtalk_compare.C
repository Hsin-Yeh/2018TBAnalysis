void xtalk_compare()
{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Tue Oct 15 20:48:04 2019) by ROOT version6.10/04

    char title[200];
    int Energy = 300;
    
    sprintf(title,"root_plot/plot_sim_%dGeV_EMN.root",Energy);
    TFile f_MC(title);
    sprintf(title,"root_plot/plot_data_%dGeV_Ele.root",Energy);
    TFile f_Data(title);
    sprintf(title,"root_plot/plot_ntuple_sim_config22_pdgID11_beamMomentum%d_listFTFP_BERT_EMN.root",Energy);
    TFile f_MC_original(title);

    for( int iL = 1; iL <= 28; iL++) {
	TH1D* layer4_E1devE7_smallAngle_lessBins__1;
	TH1D* layer4_E1devE7_smallAngle_lessBins__2;
	TH1D* layer4_E1devE7_smallAngle_lessBins__3;
	sprintf(title,"histo/layer%d/layer%d_E1devE7_smallAngle_lessBins",iL,iL);
	layer4_E1devE7_smallAngle_lessBins__1 = (TH1D *)f_MC.Get(title);
	layer4_E1devE7_smallAngle_lessBins__2 = (TH1D *)f_MC_original.Get(title);
	layer4_E1devE7_smallAngle_lessBins__3 = (TH1D *)f_Data.Get(title);

    
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
   
	layer4_E1devE7_smallAngle_lessBins__1->SetStats(0);
	layer4_E1devE7_smallAngle_lessBins__1->SetLineColor(2);
	layer4_E1devE7_smallAngle_lessBins__1->SetLineWidth(2);
	layer4_E1devE7_smallAngle_lessBins__1->SetMarkerColor(2);
	layer4_E1devE7_smallAngle_lessBins__1->SetMarkerStyle(20);
	layer4_E1devE7_smallAngle_lessBins__1->SetMarkerSize(0.5);
	layer4_E1devE7_smallAngle_lessBins__1->GetXaxis()->SetTitle("E1/E7 contamination variable");
	layer4_E1devE7_smallAngle_lessBins__1->GetXaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__1->GetXaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7_smallAngle_lessBins__1->GetXaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__1->GetXaxis()->SetTitleSize(0.05);
	layer4_E1devE7_smallAngle_lessBins__1->GetXaxis()->SetTitleOffset(1.1);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetTitleOffset(1.4);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__1->GetZaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__1->GetZaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__1->GetZaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__1->GetZaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__1->GetYaxis()->SetRangeUser(0,0.07);
	layer4_E1devE7_smallAngle_lessBins__1->Draw("HIST");
   
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
   
	layer4_E1devE7_smallAngle_lessBins__2->SetLineColor(4);
	layer4_E1devE7_smallAngle_lessBins__2->SetLineWidth(2);
	layer4_E1devE7_smallAngle_lessBins__2->SetMarkerColor(4);
	layer4_E1devE7_smallAngle_lessBins__2->SetMarkerStyle(20);
	layer4_E1devE7_smallAngle_lessBins__2->SetMarkerSize(0.5);
	layer4_E1devE7_smallAngle_lessBins__2->GetXaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__2->GetXaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7_smallAngle_lessBins__2->GetXaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__2->GetXaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__2->GetXaxis()->SetTitleOffset(1.4);
	layer4_E1devE7_smallAngle_lessBins__2->GetXaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__2->GetYaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__2->GetYaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7_smallAngle_lessBins__2->GetYaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__2->GetYaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__2->GetYaxis()->SetTitleOffset(1.4);
	layer4_E1devE7_smallAngle_lessBins__2->GetYaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__2->GetZaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__2->GetZaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__2->GetZaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__2->GetZaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__2->Draw("HISTSAME");
    
	layer4_E1devE7_smallAngle_lessBins__3->SetLineWidth(2);
	layer4_E1devE7_smallAngle_lessBins__3->SetMarkerStyle(20);
	layer4_E1devE7_smallAngle_lessBins__3->SetMarkerSize(0.5);
	layer4_E1devE7_smallAngle_lessBins__3->GetXaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__3->GetXaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7_smallAngle_lessBins__3->GetXaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__3->GetXaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__3->GetXaxis()->SetTitleOffset(1.4);
	layer4_E1devE7_smallAngle_lessBins__3->GetXaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__3->GetYaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__3->GetYaxis()->SetLabelOffset(0.01125);
	layer4_E1devE7_smallAngle_lessBins__3->GetYaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__3->GetYaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__3->GetYaxis()->SetTitleOffset(1.4);
	layer4_E1devE7_smallAngle_lessBins__3->GetYaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__3->GetZaxis()->SetLabelFont(42);
	layer4_E1devE7_smallAngle_lessBins__3->GetZaxis()->SetLabelSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__3->GetZaxis()->SetTitleSize(0.045);
	layer4_E1devE7_smallAngle_lessBins__3->GetZaxis()->SetTitleFont(42);
	layer4_E1devE7_smallAngle_lessBins__3->Draw("SAME");

   
	TLegend *leg = new TLegend(0.1373955,0.6222628,0.437276,0.830292,NULL,"brNDC");
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
	TLegendEntry *entry=leg->AddEntry("","w/  xtalk","lpf");
	entry->SetFillStyle(1001);
	entry->SetLineColor(2);
	entry->SetLineStyle(1);
	entry->SetLineWidth(2);
	entry->SetMarkerColor(2);
	entry->SetMarkerStyle(20);
	entry->SetMarkerSize(0.5);
	entry->SetTextFont(42);
	entry=leg->AddEntry("","w/o xtalk","lpflpf");
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
	leg->Draw();

	sprintf(title,"TB2018 300GeV layer%d",iL);
	TLatex *   tex = new TLatex(0.0586392,0.063,title);
	tex->SetTextSize(0.0433213);
	tex->SetLineWidth(2);
	tex->Draw();
	Canvas_1->Update();

	sprintf(title,"plots/%dGeV/%dGeV_E1devE7_layer%02d.png", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	sprintf(title,"plots/%dGeV/%dGeV_E1devE7_layer%02d.pdf", Energy, Energy, iL);
	Canvas_1->SaveAs(title);
	//gPad->WaitPrimitive();

    
	Canvas_1->Modified();
	Canvas_1->cd();
	Canvas_1->SetSelected(Canvas_1);
    }
}
