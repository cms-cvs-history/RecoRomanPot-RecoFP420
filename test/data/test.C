{
   //======================================================================
      printf("za1: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
	gStyle->SetOptStat(0);   //  no statistics _or_
	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



	    gStyle->SetOptFit(0100);// constant, mean and sigma only !!!!!!!!!!!!!!!!!!!!!!!!!!
	   gStyle->SetStatX(0.91);
          gStyle->SetStatY(0.75);
          gStyle->SetStatW(0.20);
	  gStyle->SetStatH(0.10);

        Float_t LeftOffset = 0.12;
        Float_t TopOffset = 0.22;

        gStyle->SetLineWidth(1);
        gStyle->SetErrorX(0);

//---=[ Titles,Labels ]=-----------
        gStyle->SetOptTitle(0);             // title on/off
        gStyle->SetTitleColor(1);           // title color
        gStyle->SetTitleX(0.15);            // title x-position
        gStyle->SetTitleH(0.15);             // title height
        gStyle->SetTitleW(0.60);            // title width
        gStyle->SetTitleFont(42);           // title font
        gStyle->SetTitleFontSize(0.07);     // title font size

//---=[ Histogram style ]=----------
                gStyle->SetFrameFillColor(41);

//---=[ Pad style ]=----------------
        gStyle->SetPadTopMargin(TopOffset);
        gStyle->SetPadBottomMargin(LeftOffset);
        gStyle->SetPadRightMargin(TopOffset);
        gStyle->SetPadLeftMargin(LeftOffset);
//---=[ SetCanvasDef           ]=----------------
    //======================================================================
//
// Connect the input file and get the 2-d histogram in memory
    //======================================================================
	TFile *hfile = new TFile("TheAnalysis.root", "READ");     //open file
	printf("test: root file TheAnalysis is Open    \n");
	hfile.ls();
	hfile->Print();
	TPostScript psfile ("test.ps", 111);
	c1 = new TCanvas("c1"," ",200,10,600,800);
	c1->SetFillColor(18);
	printf("TCanvas Test for FP420Analysis is Open \n");
	
    //================
     c1->Clear();
     c1->Divide(1,1);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("ntrackscoll");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");
           c1->cd(2); 


     c1->Update();
    //================


    // close and delete all possible things:

   psfile->Close();

    hfile->Close();
    hfile->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}
