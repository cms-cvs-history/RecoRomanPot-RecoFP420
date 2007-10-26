{

   //======================================================================
      printf("zz3: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
	gStyle->SetOptStat(0);   //  no statistics _or_
	   //   gStyle->SetOptStat(11111111);
	  //  gStyle->SetOptStat(111111);
	  //gStyle->SetOptStat(1101);// mame mean and rms 
	  //gStyle->SetOptStat(0101);// name and entries
	  //gStyle->SetOptStat(1100);// mean and rms only !!!!!
	      // 	gStyle->SetOptStat(1110000);// und over, integral !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



	//gStyle->SetOptFit(00001);// hi2/nu, constant, mean and sigma only !!
	  // gStyle->SetOptFit(0010);// constant, mean and sigma only !!
	//gStyle->SetOptFit(00011);// constant, mean and sigma only !!
	      gStyle->SetOptFit(0100);// constant, mean and sigma only !!!!!!!!!!!!!!!!!!!!!!!!!!
       //
	 /*
          gStyle->SetStatX(0.90);
          gStyle->SetStatY(0.60);
          gStyle->SetStatW(0.40);
          gStyle->SetStatH(0.10);
*/
	   gStyle->SetStatX(0.91);
          gStyle->SetStatY(0.75);
          gStyle->SetStatW(0.20);
	  gStyle->SetStatH(0.10);

           // gStyle->SetStatH(0.35);
        //

	  //        Float_t LeftOffset = 0.12;
        //Float_t TopOffset = 0.12;
        Float_t LeftOffset = 0.12;
        Float_t TopOffset = 0.22;

        gStyle->SetLineWidth(1);
        gStyle->SetErrorX(0);

//---=[ Titles,Labels ]=-----------
        gStyle->SetOptTitle(0);             // title on/off
        //      gStyle->SetTitleColor(0);           // title color
        gStyle->SetTitleColor(1);           // title color
        //      gStyle->SetTitleX(0.35);            // title x-position
        gStyle->SetTitleX(0.15);            // title x-position
        gStyle->SetTitleH(0.25);             // title height
        //      gStyle->SetTitleW(0.53);            // title width
        gStyle->SetTitleW(0.60);            // title width
        gStyle->SetTitleFont(42);           // title font
        gStyle->SetTitleFontSize(0.07);     // title font size

//---=[ Histogram style ]=----------
//      gStyle->SetHistFillColor(38);
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
//  TBrowser *b = new TBrowser
// macro to recreate a H1Tree
// using the H1EventList in skel_writelist.C
//
//      TFile *hfile = new TFile("newntfp420.root", "READ");     //open file
      TFile *hfile = new TFile("TheAnalysis.root", "READ");     //open file
      printf("zz3: root file TheAnalysis is Open    \n");
    hfile.ls();
    hfile->Print();
//    getchar();
//
//    TPostScript* psfile = new TPostScript("zhplot.ps",111);
    TPostScript psfile ("zz3.ps", 111);
//
//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);

// c1 = new TCanvas("c1","FP420Analysis",200,10,700,900);
   c1 = new TCanvas("c1"," ",200,10,600,800);
   c1->SetFillColor(18);

//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);
      printf("TCanvas Test for FP420Analysis is Open \n");


    //================
    //================
    //================
    //================
    //================
    //================
    //================
    //============================================================================================================0-0000000000000 1
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("chisqX");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("chisqX");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");
           c1->cd(2); 
      TH1F *mpeled3= (TH1F*)hfile->Get("chisq3X");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("chisq3X");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

       c1->cd(3); 

      TH1F *mpelec3= (TH1F*)hfile->Get("nhitplanesX");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("nhitplanesX");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

          c1->cd(4); 
      TH1F *mpeled3= (TH1F*)hfile->Get("nhitplanes3X");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("nhitplanes3X");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("ntrackscoll");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       gPad->SetLogy();
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("ntrackscoll");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");




     c1->Update();
    //================
    //================
    //============================================================================================================0-0000000000000 2
   //chisq3X d3XinVtxTrack nhitplanes3X dphitrack2 dthtrack2 dthetax2 clnum3Xinside d3thetax2
   //chisqX dXinVtxTrack nhitplanesX dphitrack dthtrack dthetax 
     //   c1->Divide(1,3);
     //c1_1->Divide(2,1);
     // c1_1->cd(1);
    //================
     c1->Clear();
     c1->Divide(1,2);
     //     TF1 *f1 = new TF1("f1","gaus",-8.,8.); dthetax2->Fit("f1","RI");
     // TF1 *f1 = new TF1("f1","gaus",-8.,8.); dthetax->Fit("f1","RI");
     // TF1 *f1 = new TF1("f1","gaus",-0.03,0.03); d3XinVtxTrack->Fit("f1","RI");
     // TF1 *f1 = new TF1("f1","gaus",-0.03,0.03); dXinVtxTrack->Fit("f1","RI");

      c1_1->Divide(2,1);
      c1_1->cd(1);
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetax");
      mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("dthetax");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

       c1_1->cd(2); 
       TH1F *mpeled3= (TH1F*)hfile->Get("dthetax3");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       // mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("dthetax3");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

       c1_2->Divide(2,1);
       c1_2->cd(1); 
       TH1F *mpelec3= (TH1F*)hfile->Get("dXinVtxTrack");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("dXinVtxTrack");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

       c1_2->cd(2); 
       TH1F *mpeled3= (TH1F*)hfile->Get("d3XinVtxTrack");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("d3XinVtxTrack");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");


     c1->Update();
    //================
    //================

    //============================================================================================================0-0000000000000 3
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("NumofpartNoMI");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("NumofpartNoMI");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("NumberHitsNoMI");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("NumberHitsNoMI");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");
     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("NumberHitsOnlyMI");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("NumberHitsOnlyMI");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("NumofpartOnlyMI");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("NumofpartOnlyMI");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 4
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("numberOfXandYtracks");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("numberOfXandYtracks");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("ntrackscoll");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dphitrack");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("dphitrack");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthtrack");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("dthtrack");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");


     c1->Update();
    //================
    //============================================================================================================0-0000000000000 5
    //================
     c1->Clear();
     c1->Divide(2,4);
     c1->cd(1); 

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetax");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       //  mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 3St, [mkrad]");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");


     c1->cd(2); 
      TH1F *mpelec7= (TH1F*)hfile->Get("dthetax3");
      //        gPad->SetLogy();
      //  mpelec7->GetXaxis()->SetLabelSize(0.06);
      // mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
       mpelec7->SetLineColor(2);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta #thetaX3, 3St, [mkrad]");
       mpelec7->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetay");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("dthetay");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetay3");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("dthetay3");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dphitrack");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("dphitrack");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

       c1->cd(6); 
      TH1F *mpeled3= (TH1F*)hfile->Get("dphitrack3");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       //  mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("dphitrack3");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

       c1->cd(7); 

      TH1F *mpelec3= (TH1F*)hfile->Get("dthtrack");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("dthtrack");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

          c1->cd(8); 
      TH1F *mpeled3= (TH1F*)hfile->Get("dthtrack3");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       //  mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("dthtrack3");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");


     c1->Update();
    //================
    //============================================================================================================0-0000000000000 6
    //================
     c1->Clear();
     c1->Divide(1,1);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetax");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 3St, [mkrad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");

      TH1F *mpelec7= (TH1F*)hfile->Get("dthetax3");
      //        gPad->SetLogy();
      //  mpelec7->GetXaxis()->SetLabelSize(0.06);
      // mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
      mpelec7->SetMarkerStyle(20);
      mpelec7->SetMarkerSize(0.8);
      mpelec7->SetMarkerColor(kBlue);
      mpelec7->SetLineColor(2);
      mpelec7->GetYaxis()->SetTitleSize(0.06);
      mpelec7->GetXaxis()->SetTitleSize(0.06);
      mpelec7->GetXaxis()->SetTitle("#Delta #thetaX, 3St, [mkrad]");
      mpelec7->Draw("ErrorSame");
      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 7
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("tocollection");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("tocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("tocollection1");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X III, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("tocollection2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X IV, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 8
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection1");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X III, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X IV, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 9
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection1");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X III, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X IV, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 10
    //================
     c1->Clear();
     c1->Divide(2,2);

     c1->cd(1); 

     TF1 *f1 = new TF1("f1","gaus",-0.1,0.1); ntocollection->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); ntocollection0->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-0.1,0.1); ntocollection1->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-0.1,0.1); ntocollection2->Fit("f1","RI");

     TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection1");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X III, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X IV, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      
      c1->Update();
    //================

    //============================================================================================================0-0000000000000 11
   //chisq3X d3XinVtxTrack nhitplanes3X dphitrack2 dthtrack2 dthetax2 clnum3Xinside d3thetax2
   //chisqX dXinVtxTrack nhitplanesX dphitrack dthtrack dthetax 
     //   c1->Divide(1,3);
     //c1_1->Divide(2,1);
     // c1_1->cd(1);
    //================
     c1->Clear();
     c1->Divide(2,2);
     
     //c1->Divide(1,2);
     //  c1_1->Divide(2,1);
     //  c1_1->cd(1);
       c1->cd(1); 
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); dthetax->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); dthetax3->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-0.03,0.03); d3XinVtxTrack->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-0.03,0.03); dXinVtxTrack->Fit("f1","RI");

      TH1F *mpe3= (TH1F*)hfile->Get("dthetax");
      mpe3->SetMarkerStyle(20);
      mpe3->SetMarkerSize(0.4);
      // mpe3->GetYaxis()->SetLabelSize(0.04);
      mpe3->SetMarkerColor(kBlue);
      mpe3->GetXaxis()->SetTitle("dthetax");
      mpe3->SetFillColor(33);
      mpe3->SetLineColor(3);
      mpe3->Draw();
      mpe3->Draw("ErrorSame");

       c1->cd(2); 
       // c1_1->cd(2); 
       TH1F *mpeled3= (TH1F*)hfile->Get("dthetax3");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       // mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("dthetax3");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

       c1->cd(3); 
       //  c1_2->Divide(2,1);
       //c1_2->cd(1); 
       TH1F *mpe4= (TH1F*)hfile->Get("dXinVtxTrack");
       mpe4->SetMarkerStyle(20);
       mpe4->SetMarkerSize(0.4);
       mpe4->GetYaxis()->SetLabelSize(0.04);
       mpe4->SetMarkerColor(kBlue);
       mpe4->GetXaxis()->SetTitle("dXinVtxTrack");
       mpe4->SetFillColor(33);
       mpe4->SetLineColor(3);
       mpe4->Draw();
       mpe4->Draw("ErrorSame");

       // c1_2->cd(2); 
       c1->cd(4); 
       TH1F *mpeled3= (TH1F*)hfile->Get("d3XinVtxTrack");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("d3XinVtxTrack");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");


     c1->Update();
    //================
    //================
    //============================================================================================================0-0000000000000 12
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);
     // getchar();

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("efftracktheta");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              //Double_t mscale = 100./mintegral;
              ////              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("#theta X");
       mpelec->GetYaxis()->SetTitle("efftracktheta");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(3);
      TH1F *mpelec1= (TH1F*)hfile->Get("efftracktheta4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("#theta X");
       mpelec1->GetYaxis()->SetTitle("efftracktheta4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(5);
                        TH1* histe1 = (TH1*)mpelec1->Clone("Efficiency2");
                        histe1->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe1 ->SetBinError(i, error);
			}
                        histe1->GetYaxis()->SetTitle("Eff. 1 good tr. at least");
			gPad->SetGridy();
                        histe1->SetLineColor(3);
                        histe1->SetMarkerStyle(20);
                        //histe1->SetMinimum(0.);
                        //histe1->SetMaximum(1.1);
                        histe1->SetMarkerColor(4);
                        histe1->SetMarkerSize(0.8);
                        histe1->GetXaxis()->SetTitle("#theta X");
			histe1->Draw("Error");
                        //histe1->Draw();

			}


     c1->cd(2);
      TH1F *mpelec = (TH1F*)hfile->Get("efftracktheta");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("#theta X");
       mpelec->GetYaxis()->SetTitle("efftracktheta");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(4);
       TH1F *mpelec1= (TH1F*)hfile->Get("eff2tracktheta4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("#theta X");
       mpelec1->GetYaxis()->SetTitle("eff2tracktheta4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(6);
                        TH1* histe2 = (TH1*)mpelec1->Clone("efftheta2good");
                        histe2->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe2 ->SetBinError(i, error);
			}
                        histe2->GetYaxis()->SetTitle("Eff. 2 good tr.");
			gPad->SetGridy();
                        histe2->SetLineColor(3);
                        histe2->SetMarkerStyle(20);
                        //histe2->SetMinimum(0.);
                        //histe2->SetMaximum(1.1);
                        histe2->SetMarkerColor(4);
                        histe2->SetMarkerSize(0.8);
                        histe2->GetXaxis()->SetTitle("#theta X");
			histe2->Draw("Error");
                        //histe2->Draw();

			}

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 13
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);
     // getchar();

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("effnhitplanes2X");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("Xplanes");
       mpelec->GetYaxis()->SetTitle("effnhitplanes2X");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(3);
      TH1F *mpelec1= (TH1F*)hfile->Get("effnhitplanes2X4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("Xplanes");
       mpelec1->GetYaxis()->SetTitle("effnhitplanes2X4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(5);
                        TH1* histe3 = (TH1*)mpelec1->Clone("Efficiency2");
                        histe3->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe3 ->SetBinError(i, error);
			}
                        histe3->GetYaxis()->SetTitle("Efficiency2");
			gPad->SetGridy();
                        histe3->SetLineColor(3);
                        histe3->SetMarkerStyle(20);
                        //histe3->SetMinimum(0.);
                        //histe3->SetMaximum(1.1);
                        histe3->SetMarkerColor(4);
                        histe3->SetMarkerSize(0.2);
                        histe3->GetXaxis()->SetTitle("Xplanes");
			histe3->Draw("Error");
                        //histe3->Draw();

			}


     c1->cd(2);
      TH1F *mpelec = (TH1F*)hfile->Get("effnhitplanesX");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
	       //Double_t mscale = 100./mintegral;
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("Xplanes");
       mpelec->GetYaxis()->SetTitle("effnhitplanesX");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(4);
      TH1F *mpelec1= (TH1F*)hfile->Get("effnhitplanesX4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("Xplanes");
       mpelec1->GetYaxis()->SetTitle("effnhitplanesX4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(6);
                        TH1* histe4 = (TH1*)mpelec1->Clone("Efficiency");
                        histe4->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe4 ->SetBinError(i, error);
			}
                        histe4->GetYaxis()->SetTitle("Efficiency");
			gPad->SetGridy();
                        histe4->SetLineColor(3);
                        histe4->SetMarkerStyle(20);
                        //histe4->SetMinimum(0.);
                        //histe4->SetMaximum(1.1);
                        histe4->SetMarkerColor(4);
                        histe4->SetMarkerSize(0.2);
                        histe4->GetXaxis()->SetTitle("Xplanes");
			histe4->Draw("Error");
                        //histe4->Draw();

			}

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 14
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);
     // getchar();

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("losthitsX3D");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
	      Int_t nentries = (Int_t)(mpelec->GetEntries());
	     for (Int_t i=0;i<=nentries;i++) {
	      Float_t error = (Stat_t) (mpelec->GetBinError(i));
	       error   = error - error ;
	        mpelec ->SetBinError(i, error);
	      }
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("Xplanes");
       mpelec->GetYaxis()->SetTitle("losthitsX3D");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(3);
      TH1F *mpelec1= (TH1F*)hfile->Get("losthitsX3Dnhit");
	      Int_t nentries = (Int_t)(mpelec1->GetEntries());
	     for (Int_t i=0;i<=nentries;i++) {
	      Float_t error = (Stat_t) (mpelec1->GetBinError(i));
	       error   = error/2.;
	        mpelec1 ->SetBinError(i, error);
	      }
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("Xplanes");
       mpelec1->GetYaxis()->SetTitle("losthitsX3Dnhit");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(5);
                        TH1* histe5 = (TH1*)mpelec1->Clone("Efficiency2");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
			/*
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t cr = (Stat_t) (histe5->GetBinError(i));
			  Float_t error==0.; 
			  if(t>0.&& a2r>0.){
			    //  error = fabs(x*y/t**2)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			    error = cr*fabs(x/t)*fabs(a1r/a2r);
			  }
			  if(x==0.) error=0.;
			  histe5 ->SetBinError(i, error);
			}
*/

                        histe5->GetYaxis()->SetTitle("<N> lost hits");
			gPad->SetGridy();
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        //histe5->SetMinimum(0.);
                        //histe5->SetMaximum(1.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("Xplanes");
			histe5->Draw("Error");
                        //histe5->Draw();

			}



     c1->cd(2);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("DX");
       mpelec->GetYaxis()->SetTitle("efftrackdref12");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(4);
      TH1F *mpelec1= (TH1F*)hfile->Get("efftrackdref124");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("DX");
       mpelec1->GetYaxis()->SetTitle("efftrackdref124");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(6);
                        TH1* histe15 = (TH1*)mpelec1->Clone("Efficiency");
                        histe15->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe15 ->SetBinError(i, error);
			}
                        histe15->GetYaxis()->SetTitle("Efficiency");
			gPad->SetGridy();
                        histe15->SetLineColor(3);
                        histe15->SetMarkerStyle(20);
                        //histe15->SetMinimum(0.);
                        //histe15->SetMaximum(1.1);
                        histe15->SetMarkerColor(4);
                        histe15->SetMarkerSize(0.2);
                        histe15->GetXaxis()->SetTitle("DX");
			histe15->Draw("Error");
                        //histe15->Draw();

			}



     c1->Update();
    //================
    //============================================================================================================0-0000000000000 15
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(3,3);
     // getchar();

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks1Sec");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
	     // Int_t nentries = (Int_t)(mpelec->GetEntries());
	     //for (Int_t i=0;i<=nentries;i++) {
	     // Float_t error = (Stat_t) (mpelec->GetBinError(i));
	     //  error   = error - error ;
	     //   mpelec ->SetBinError(i, error);
	     // }
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("Xplanes");
       mpelec->GetYaxis()->SetTitle("clnumX2Ttacks1Sec");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(4);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnumX2Ttacks1Sec4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("Xplanes");
       mpelec1->GetYaxis()->SetTitle("clnumX2Ttacks1Sec4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(7);
                        TH1* histe6 = (TH1*)mpelec1->Clone("Efficiency");
                        histe6->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe6 ->SetBinError(i, error);
			}
                        histe6->GetYaxis()->SetTitle("Efficiency 1Sec");
			gPad->SetGridy();
                        histe6->SetLineColor(3);
                        histe6->SetMarkerStyle(20);
                        //histe6->SetMinimum(0.);
                        //histe6->SetMaximum(1.1);
                        histe6->SetMarkerColor(4);
                        histe6->SetMarkerSize(0.2);
                        histe6->GetXaxis()->SetTitle("Xplanes");
			histe6->Draw("Error");
                        //histe6->Draw();

			}

     c1->cd(2);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks2Sec");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("Xplanes");
       mpelec->GetYaxis()->SetTitle("clnumX2Ttacks2Sec");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(5);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnumX2Ttacks2Sec4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("Xplanes");
       mpelec1->GetYaxis()->SetTitle("clnumX2Ttacks2Sec4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(8);
                        TH1* histe7 = (TH1*)mpelec1->Clone("Efficiency");
                        histe7->Divide(mpelec1,mpelec, 1, 1, "b");

			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe7 ->SetBinError(i, error);
			}
                        histe7->GetYaxis()->SetTitle("Efficiency 2Sec");
			gPad->SetGridy();
                        histe7->SetLineColor(3);
                        histe7->SetMarkerStyle(20);
                        //histe7->SetMinimum(0.);
                        //histe7->SetMaximum(1.1);
                        histe7->SetMarkerColor(4);
                        histe7->SetMarkerSize(0.2);
                        histe7->GetXaxis()->SetTitle("Xplanes");
			histe7->Draw("Error");
                        //histe7->Draw();

			}

     c1->cd(3);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks3Sec");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("Xplanes");
       mpelec->GetYaxis()->SetTitle("clnumX2Ttacks3Sec");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(6);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnumX2Ttacks3Sec4");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("Xplanes");
       mpelec1->GetYaxis()->SetTitle("clnumX2Ttacks3Sec4");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(9);
                        TH1* histe77= (TH1*)mpelec1->Clone("Efficiency");
                        histe77->Divide(mpelec1,mpelec, 1, 1, "b");

			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe77 ->SetBinError(i, error);
			}
                        histe77->GetYaxis()->SetTitle("Efficiency 3Sec");
			gPad->SetGridy();
                        histe77->SetLineColor(3);
                        histe77->SetMarkerStyle(20);
                        //histe77->SetMinimum(0.);
                        //histe77->SetMaximum(1.1);
                        histe77->SetMarkerColor(4);
                        histe77->SetMarkerSize(0.2);
                        histe77->GetXaxis()->SetTitle("Xplanes");
			histe77->Draw("Error");
                        //histe77->Draw();

			}




     c1->Update();
    //================
    //============================================================================================================0-0000000000000 16
    //================
     c1->Clear();
     c1->Divide(2,5);
     // getchar();

     c1->cd(1); 

     TH1F *mpelec3= (TH1F*)hfile->Get("xref");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("xref");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xref2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("xref2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dref12");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("dref12");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); mintheta->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); mintheta2->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mintheta");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mintheta2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("ntrackscoll");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(7); 
      TH1F *mpelec3= (TH1F*)hfile->Get("numberOfXandYtracks");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("numberOfTtracks");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(8); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("ccchindfx");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(9); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx2");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("ccchindfx2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(10); 
      TH1F *mpelec3= (TH1F*)hfile->Get("drefy12");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("drefy12");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


      c1->Update();
    //================

    //============================================================================================================0-0000000000000 17
    //================
     c1->Clear();
     c1->Divide(2,4);
     // getchar();

     c1->cd(1); 
     TH1F *mpelec3= (TH1F*)hfile->Get("mindthtrack");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mindthtrack");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mindphitrack");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mindphitrack");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("minthtrue");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("minthtrue");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("minthreal");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("minthreal");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(5); 
     TH1F *mpelec3= (TH1F*)hfile->Get("mindthtrack2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mindthtrack2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mindphitrack2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mindphitrack2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(7); 
      TH1F *mpelec3= (TH1F*)hfile->Get("minthtrue2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("minthtrue2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(8); 
      TH1F *mpelec3= (TH1F*)hfile->Get("minthreal2");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("minthreal2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");



      c1->Update();
    //================

    //============================================================================================================0-0000000000000 18
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax  averdthetavsd12
    //================
     c1->Clear();
     c1->Divide(2,3);
     
     c1->cd(1);
     histe2->GetYaxis()->SetTitle("Track Finder Eff.");
     gPad->SetGridy();
     histe2->SetLineColor(3);
     histe2->SetMarkerStyle(20);
     //histe2->SetMinimum(0.);
     //histe2->SetMaximum(1.1);
     histe2->SetMarkerColor(4);
     histe2->SetMarkerSize(1.4);
     histe2->GetXaxis()->SetTitle("#theta X, [mrad]");
     histe2->Draw("Error");
     //histe2->Draw();

     c1->cd(2);
     histe5->GetYaxis()->SetTitle("<N> lost RecHits");
     gPad->SetGridy();
     histe5->SetLineColor(3);
     histe5->SetMarkerStyle(20);
     //histe5->SetMinimum(0.);
     //histe5->SetMaximum(2.1);
     histe5->SetMarkerColor(4);
     histe5->SetMarkerSize(1.4);
     histe5->GetXaxis()->SetTitle("N RecHits");
     histe5->Draw("Error");
     //histe5->Draw();
     c1->cd(3);
     histe4->GetYaxis()->SetTitle("Efficiency");
     gPad->SetGridy();
     histe4->SetLineColor(3);
     histe4->SetMarkerStyle(20);
     //histe4->SetMinimum(0.);
     //histe4->SetMaximum(1.1);
     histe4->SetMarkerColor(4);
     histe4->SetMarkerSize(1.4);
     histe4->GetXaxis()->SetTitle("Xplanes");
     histe4->Draw("Error");
     //histe4->Draw();

     c1->cd(4);
     histe15->GetYaxis()->SetTitle("Efficiency");
     gPad->SetGridy();
     histe15->SetLineColor(3);
     histe15->SetMarkerStyle(20);
     //histe15->SetMinimum(0.);
     //histe15->SetMaximum(1.1);
     histe15->SetMarkerColor(4);
     histe15->SetMarkerSize(1.4);
     histe15->GetXaxis()->SetTitle("DX");
     histe15->Draw("Error");
     //histe15->Draw();
     
     c1->cd(5);
     histe6->GetYaxis()->SetTitle("Efficiency 1Sec");
     gPad->SetGridy();
     histe6->SetLineColor(3);
     histe6->SetMarkerStyle(20);
     //histe6->SetMinimum(0.);
     //histe6->SetMaximum(1.1);
     histe6->SetMarkerColor(4);
     histe6->SetMarkerSize(1.4);
     histe6->GetXaxis()->SetTitle("Xplanes");
     histe6->Draw("Error");
     //histe6->Draw();

     c1->cd(6);
     histe7->GetYaxis()->SetTitle("Efficiency 2Sec");
     gPad->SetGridy();
     histe7->SetLineColor(3);
     histe7->SetMarkerStyle(20);
     //histe7->SetMinimum(0.);
     //histe7->SetMaximum(1.1);
     histe7->SetMarkerColor(4);
     histe7->SetMarkerSize(1.4);
     histe7->GetXaxis()->SetTitle("Xplanes");
     histe7->Draw("Error");
     //histe7->Draw();



     c1->Update();
    //================
    //============================================================================================================0-0000000000000 19
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);
     // getchar();




     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.8);
       mpelec->GetXaxis()->SetTitle("DX");
       mpelec->GetYaxis()->SetTitle("efftrackdref12");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mintheta");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("mintheta2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3);
      TH1F *mpelec1= (TH1F*)hfile->Get("eff1trackdref124");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.8);
       mpelec1->GetXaxis()->SetTitle("DX");
       mpelec1->GetYaxis()->SetTitle("eff1trackdref124");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(5);
                        TH1* histe16 = (TH1*)mpelec1->Clone("Efficiency1");
                        histe16->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error==0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe16 ->SetBinError(i, error);
			}
               histe16->GetYaxis()->SetTitle("Efficiency1");
	       gPad->SetGridy();
	       histe16->SetLineColor(3);
	       histe16->SetMarkerStyle(20);
	       //histe16->SetMinimum(0.);
	       //histe16->SetMaximum(1.1);
	       histe16->SetMarkerColor(4);
	       histe16->SetMarkerSize(0.2);
	       histe16->GetXaxis()->SetTitle("#Delta X at Z=8m");
	       histe16->Draw("Error");
	       //histe16->Draw();
	     }
     c1->cd(6);
     histe15->GetYaxis()->SetTitle("EfficiencyDX");
     gPad->SetGridy();
     histe15->SetLineColor(3);
     histe15->SetMarkerStyle(20);
     //histe15->SetMinimum(0.);
     //histe15->SetMaximum(1.1);
     histe15->SetMarkerColor(3);
     histe15->SetMarkerSize(0.8);
     histe15->GetXaxis()->SetTitle("#Delta X at Z=8m");
     histe15->Draw("Error");

     histe16->SetMarkerSize(0.8);
     histe16->SetLineColor(2);
     histe16->SetMarkerColor(2);
     histe16->Draw("ErrorSame");



     c1->Update();
    //================
    //============================================================================================================0-0000000000000 20
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(3,4);

     c1->cd(7); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dref12");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X at Z=8m");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("N tracks found");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("numberOfXandYtracks");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("N tracks selected");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 1st track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx2");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 2nd track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(10);
     TF1 *p1 = new TF1("p1","pol1",1.,6.); histe16->Fit("p1","RI");
     histe15->GetYaxis()->SetTitle("Efficiency");
     gPad->SetGridy();
     histe15->SetLineColor(3);
     histe15->SetMarkerStyle(20);
     histe15->SetMinimum(0.);
     histe15->SetMaximum(1.2);
     histe15->SetMarkerColor(4);
     histe15->SetMarkerSize(1.4);
     histe15->GetXaxis()->SetTitle("#Delta X at Z=8m");
     histe15->Draw("ErrorSame");
     //histe15->Draw();
     histe16->SetMarkerSize(0.8);
     histe16->SetMinimum(0.);
     histe16->SetMaximum(1.2);
     histe16->SetLineColor(2);
     histe16->SetMarkerColor(2);
     histe16->Draw("ErrorSame");
     // TF1 *p1 = new TF1("p3","pol3",1.,18.); histe16->Fit("p3","RI");
     //   histe16->Draw("ErrorSame");
     
     c1->cd(11);
     histe6->GetYaxis()->SetTitle("Efficiency (Station 1)");
     gPad->SetGridy();
     histe6->SetLineColor(3);
     histe6->SetMarkerStyle(20);
     histe6->SetMinimum(0.);
     histe6->SetMaximum(1.2);
     histe6->SetMarkerColor(4);
     histe6->SetMarkerSize(1.4);
     histe6->GetXaxis()->SetTitle("N planes w/ 2 cl");
     histe6->Draw("Error");
     //histe6->Draw();

     c1->cd(12);
     histe7->GetYaxis()->SetTitle("Efficiency (Station 2)");
     gPad->SetGridy();
     histe7->SetLineColor(3);
     histe7->SetMarkerStyle(20);
     histe7->SetMinimum(0.);
     histe7->SetMaximum(1.2);
     histe7->SetMarkerColor(4);
     histe7->SetMarkerSize(1.4);
     histe7->GetXaxis()->SetTitle("N planes w/ 2 cl");
     histe7->Draw("Error");
     //histe7->Draw();

     c1->cd(8);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks1Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 2 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 1)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(9);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks2Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 2 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 2)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->GetXaxis()->SetLabelSize(1.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 21
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(3,2);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("N tracks found");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("numberOfXandYtracks");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("N tracks selected");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 1st track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx2");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 2nd track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
       mpelec3->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 22
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(3,2);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dref12");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X at Z=8m");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(4);
     TF1 *p1 = new TF1("p1","pol1",1.,6.); histe16->Fit("p1","RI");
     histe15->GetYaxis()->SetTitle("Efficiency");
     gPad->SetGridy();
     histe15->SetLineColor(3);
     histe15->SetMarkerStyle(20);
     histe15->SetMinimum(0.);
     histe15->SetMaximum(1.2);
     histe15->SetMarkerColor(4);
     histe15->SetMarkerSize(1.4);
     histe15->GetXaxis()->SetTitle("#Delta X at Z=8m");
     histe15->Draw("ErrorSame");
     //histe15->Draw();
     histe16->SetMarkerSize(0.8);
     histe16->SetMinimum(0.);
     histe16->SetMaximum(2.0);
     histe16->SetLineColor(2);
     histe16->SetMarkerColor(2);
     histe16->Draw("ErrorSame");
     // TF1 *p1 = new TF1("p3","pol3",1.,18.); histe16->Fit("p3","RI");
     //   histe16->Draw("ErrorSame");
     
     c1->cd(5);
     histe6->GetYaxis()->SetTitle("Efficiency (Station 1)");
     gPad->SetGridy();
     histe6->SetLineColor(3);
     histe6->SetMarkerStyle(20);
     histe6->SetMinimum(0.);
     histe6->SetMaximum(2.0);
     histe6->SetMarkerColor(4);
     histe6->SetMarkerSize(1.4);
     histe6->GetXaxis()->SetTitle("N planes w/ 2 cl");
     histe6->Draw("Error");
     //histe6->Draw();

     c1->cd(6);
     histe7->GetYaxis()->SetTitle("Efficiency (Station 2)");
     gPad->SetGridy();
     histe7->SetLineColor(3);
     histe7->SetMarkerStyle(20);
     histe7->SetMinimum(0.);
     histe7->SetMaximum(2.0);
     histe7->SetMarkerColor(4);
     histe7->SetMarkerSize(1.4);
     histe7->GetXaxis()->SetTitle("N planes w/ 2 cl");
     histe7->Draw("Error");
     //histe7->Draw();

     c1->cd(2);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks1Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 2 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 1)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(3);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks2Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 2 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 2)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");


     c1->Update();
    //================
    //============================================================================================================0-0000000000000 23
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("N tracks found");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("numberOfXandYtracks");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("N tracks selected");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 1st track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx2");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 2nd track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
       mpelec3->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 24
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,4);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dref12");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X at Z=8m");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(2);
     TF1 *p1 = new TF1("p1","pol1",1.,6.); histe16->Fit("p1","RI");
     histe15->GetYaxis()->SetTitle("Efficiency");
     gPad->SetGridy();
     histe15->SetLineColor(3);
     histe15->SetMarkerStyle(20);
     histe15->SetMinimum(0.);
     histe15->SetMaximum(1.2);
     histe15->SetMarkerColor(4);
     histe15->SetMarkerSize(1.4);
     histe15->GetXaxis()->SetTitle("#Delta X at Z=8m");
     histe15->Draw("ErrorSame");
     //histe15->Draw();
     histe16->SetMarkerSize(0.8);
     histe16->SetMinimum(0.);
     histe16->SetMaximum(2.0);
     histe16->SetLineColor(2);
     histe16->SetMarkerColor(2);
     histe16->Draw("ErrorSame");
     // TF1 *p1 = new TF1("p3","pol3",1.,18.); histe16->Fit("p3","RI");
     //   histe16->Draw("ErrorSame");
     
     c1->cd(4);
     histe6->GetYaxis()->SetTitle("Efficiency (Station 1)");
     gPad->SetGridy();
     histe6->SetLineColor(3);
     histe6->SetMarkerStyle(20);
     histe6->SetMinimum(0.);
     histe6->SetMaximum(2.0);
     histe6->SetMarkerColor(4);
     histe6->SetMarkerSize(1.4);
     histe6->GetXaxis()->SetTitle("N planes w/ 2 cl");
     histe6->Draw("Error");
     //histe6->Draw();

     c1->cd(6);
     histe7->GetYaxis()->SetTitle("Efficiency (Station 2)");
     gPad->SetGridy();
     histe7->SetLineColor(3);
     histe7->SetMarkerStyle(20);
     histe7->SetMinimum(0.);
     histe7->SetMaximum(2.0);
     histe7->SetMarkerColor(4);
     histe7->SetMarkerSize(1.4);
     histe7->GetXaxis()->SetTitle("N planes w/ 2 cl");
     histe7->Draw("Error");
     //histe7->Draw();

     c1->cd(8);
     histe77->GetYaxis()->SetTitle("Efficiency (Station 3)");
     gPad->SetGridy();
     histe77->SetLineColor(3);
     histe77->SetMarkerStyle(20);
     histe77->SetMinimum(0.);
     histe77->SetMaximum(2.0);
     histe77->SetMarkerColor(4);
     histe77->SetMarkerSize(1.4);
     histe77->GetXaxis()->SetTitle("N planes w/ 3 cl");
     histe77->Draw("Error");
     //histe77->Draw();

     c1->cd(3);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks1Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 2 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 1)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(5);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks2Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 2 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 2)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(7);
      TH1F *mpelec = (TH1F*)hfile->Get("clnumX2Ttacks3Sec");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("N planes w/ 3 cl");
       mpelec->GetYaxis()->SetTitle("N ev. (Station 3)");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");


     c1->Update();
    //================
    //============================================================================================================0-0000000000000 25
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(1,2);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dref12");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X at Z=8m");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2);
     TF1 *p1 = new TF1("p1","pol1",1.,6.); histe16->Fit("p1","RI");
     histe15->GetYaxis()->SetTitle("Efficiency");
     gPad->SetGridy();
     histe15->SetLineColor(3);
     histe15->SetMarkerStyle(20);
     histe15->SetMinimum(0.);
     histe15->SetMaximum(1.2);
     histe15->SetMarkerColor(4);
     histe15->SetMarkerSize(1.4);
     histe15->GetXaxis()->SetTitle("#Delta X at Z=8m");
     histe15->Draw("ErrorSame");
     //histe15->Draw();
     histe16->SetMarkerSize(0.8);
     histe16->SetMinimum(0.);
     histe16->SetMaximum(2.0);
     histe16->SetLineColor(2);
     histe16->SetMarkerColor(2);
     histe16->Draw("ErrorSame");
     // TF1 *p1 = new TF1("p3","pol3",1.,18.); histe16->Fit("p3","RI");
     //   histe16->Draw("ErrorSame");
     
     c1->Update();
    //================
    //============================================================================================================0-0000000000000 26
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,2);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yref");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("yref");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(2);
      TH1F *mpelec3= (TH1F*)hfile->Get("yref2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("yref2");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3);
      TH1F *mpelec3= (TH1F*)hfile->Get("thetaXmrad");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("thetaXmrad");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");
     
     c1->cd(4);
      TH1F *mpelec3= (TH1F*)hfile->Get("thetaX2mrad");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("thetaX2mrad");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");
     

     c1->Update();
    //================
    //================
    //============================================================================================================0-0000000000000 27
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax  
    //================
     //bool ch55=true;
							   // bool ch55=false;
     //witch(ch55) {
       c1->Clear();
       c1->Divide(1,3);
       // getchar();
       
       c1->cd(1);
       TH1F *mpelec = (TH1F*)hfile->Get("averdthetavsd12");
       /*             
       if(mpelec->IsA()->InheritsFrom("TH1F")){
	 Double_t mintegral = mpelec->Integral();
	 if(mintegral != 0.0){
	   Double_t mscale = 100./mintegral;
	   //              mpelec->Scale(mscale);
	   Int_t nentries = (Int_t)(mpelec->GetEntries());
	   for (Int_t i=0;i<=nentries;i++) {
	     Float_t error = (Stat_t) (mpelec->GetBinError(i));
	     error   = error - error/1.5;
	     mpelec ->SetBinError(i, error);
	   }
*/
	   //  gPad->SetLogy();
	   mpelec->SetMarkerStyle(20);
	   mpelec->SetMarkerColor(4);
	   mpelec->SetMarkerSize(0.8);
	   mpelec->GetXaxis()->SetTitle("DX");
	   mpelec->GetYaxis()->SetTitle("averdthetavsd12");
	   //mpelec->SetMinimum(0.);
	   //mpelec->SetMaximum(20.);
	   mpelec->SetLineColor(2);
	   mpelec->Draw("Error");
	   
	   c1->cd(2);
	   TH1F *mpelec1= (TH1F*)hfile->Get("eff1trackdref124");
	   /*
	   Int_t nentries = (Int_t)(mpelec1->GetEntries());
	   for (Int_t i=0;i<=nentries;i++) {
	     Float_t error = (Stat_t) (mpelec1->GetBinError(i));
	     error   = error/2.;
	     mpelec1 ->SetBinError(i, error);
	   }
*/
	   mpelec1->SetMarkerStyle(20);
	   mpelec1->SetMarkerColor(4);
	   mpelec1->SetMarkerSize(0.8);
	   mpelec1->GetXaxis()->SetTitle("DX");
	   mpelec1->GetYaxis()->SetTitle("eff1trackdref124");
	   //       mpelec1->SetMinimum(0.);
	   //mpelec1->SetMaximum(20.);
	   mpelec1->SetLineColor(3);
	   mpelec1->Draw("Error");
	   c1->cd(3);
	   TH1* histe55 = (TH1*)mpelec1->Clone("Efficiency");
	   histe55->Divide(mpelec1,mpelec, 1, 1, "b");
			
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t cr = (Stat_t) (histe55->GetBinError(i));
			  Float_t error==0.; 
			  if(t>0.&& a2r>0.){
			    //  error = fabs(x*y/t**2)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			    error = cr*fabs(x/t)*fabs(a1r/a2r);
			  }
			  if(x==0.) error=0.;
			  histe55 ->SetBinError(i, error);
			}

	   
	   histe55->GetYaxis()->SetTitle("<#Delta #theta X>");
	   gPad->SetGridy();
	   histe55->SetLineColor(3);
	   histe55->SetMarkerStyle(20);
	   histe55->SetMinimum(-9.);
	   histe55->SetMaximum(9.1);
	   histe55->SetMarkerColor(4);
	   histe55->SetMarkerSize(0.8);
	   histe55->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
	   histe55->Draw("Error");
	   //histe55->Draw();
	   
	   //	 }
	   //  }
	 
	 
       c1->Update();
       //
       //================
       //====================================================================================================0-0000000000000 28
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(1,3);
     // getchar();

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
       mpelec->GetYaxis()->SetTitle("N");
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(2);
     histe16->GetYaxis()->SetTitle("Eff. for at least 1 tr.");
     gPad->SetGridy();
     histe16->SetLineColor(2);
     histe16->SetMarkerStyle(20);
     //histe16->SetMinimum(0.);
     //histe16->SetMaximum(1.1);
     histe16->SetMarkerColor(2);
     histe16->SetMarkerSize(1.4);
     histe16->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
     histe16->Draw("Error");
     //histe16->Draw();

     //     bool ch55=false;
     //witch(ch55) {

     c1->cd(3);
     histe55->GetYaxis()->SetTitle("<#Delta #theta X>");
     gPad->SetGridy();
     histe55->SetLineColor(3);
     histe55->SetMarkerStyle(20);
     histe55->SetMinimum(-5.);
     histe55->SetMaximum(5.);
     histe55->SetMarkerColor(4);
     histe55->SetMarkerSize(1.4);
     histe55->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
     histe55->Draw("Error");
     //histe55->Draw();
     // }
     c1->Update();
    //================
       //====================================================================================================0-0000000000000 29
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(1,2);
     // getchar();

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.8);
       mpelec->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
       mpelec->GetYaxis()->SetTitle("N");
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(2);
     histe16->GetYaxis()->SetTitle("Eff. for at least 1 tr.");
     gPad->SetGridy();
     histe16->SetLineColor(2);
     histe16->SetMarkerStyle(20);
     //histe16->SetMinimum(0.);
     //histe16->SetMaximum(1.1);
     histe16->SetMarkerColor(2);
     histe16->SetMarkerSize(0.8);
     histe16->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
     histe16->Draw("Error");
     //histe16->Draw();

     c1->Update();
    //================
    //============================================================================================================0-0000000000000 30
    //================
     c1->Clear();
     c1->Divide(2,3);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xxxxxx");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("X at Y=0");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yyyyyy");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("Y at X=0");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xxxxxxeq");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("X at Y=0 eq");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yyyyyyeq");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("Y at X=0 eq");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xxxxxxno");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("X at Y=0 no");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yyyyyyno");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("Y at X=0 no");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 31
    //================
     c1->Clear();
     c1->Divide(2,3);

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthdifno");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("|(#Delta X + #Delta Y)| ghosts");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthdif");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("|(#Delta X + #Delta Y)|");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthdifeq");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("|(#Delta X + #Delta Y)| tracks");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthdiffno");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("(#Delta X + #Delta Y) ghosts");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthdiff");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("(#Delta X + #Delta Y)");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("dthdiffeq");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("(#Delta X + #Delta Y) tracks");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 32
    //================
     c1->Clear();
     c1->Divide(2,3);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xxxxxxs");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("X at Y=Yvtx");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yyyyyys");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("Y at X=Xvtx");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xxxxxxeqs");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("X at Y=Yvtx tracks");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yyyyyyeqs");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("Y at X=Xvtx tracks");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("xxxxxxnos");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("X at Y=Yvtx ghosts");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("yyyyyynos");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("Y at X=Xvtx ghosts");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


      
      c1->Update();
    //============================================================================================================0-0000000000000 33
    //================
     c1->Clear();
     c1->Divide(2,2);
     // getchar();

     c1->cd(1); 
     TH1F *mpelec3= (TH1F*)hfile->Get("mindthtrack");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #theta #mur (track 1)");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mindphitrack");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #phi, mr (track 1)");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
     TH1F *mpelec3= (TH1F*)hfile->Get("mindthtrack2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #theta #mur (track 2)");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mindphitrack2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #phi, mr (track 2)");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");




      c1->Update();
    //================
    //============================================================================================================0-0000000000000 34
    //================
     c1->Clear();
     c1->Divide(2,2);
     // getchar();

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("minthetay");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaY, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("minthetay2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->GetXaxis()->SetLabelSize(1.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaY, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


      c1->Update();
     //================
    //============================================================================================================0-0000000000000 35
    //================
     c1->Clear();
     c1->Divide(1,2);
     // getchar();

     c1->cd(1); 
     TH1F *mpelec3= (TH1F*)hfile->Get("NHitsAll");
     //   gPad->SetLogy();
     mpelec3->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("NHitsAll");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      c1->cd(2); 
      TH1F *mpelec7= (TH1F*)hfile->Get("ATest");
      gPad->SetLogy();
      mpelec7->SetMarkerColor(4);
      mpelec7->SetMarkerStyle(20);
      mpelec7->SetMarkerSize(0.8);
      mpelec7->SetMarkerColor(kBlue);
      mpelec7->GetXaxis()->SetTitle("ATest");
      mpelec7->SetLineColor(3);
      mpelec7->Draw("");
      mpelec7->Draw("ErrorSame");



      c1->Update();
     //================

     //================
     //================
     //================
     //================
     //================
     //================
      // bool ch=false;
    // bool ch=true;
   //  switch(ch) {
    //============================================================================================================0-0000000000000 36
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);

      c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("nhitplanesX");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("N RecHits");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");


     c1->cd(2);
      TH1F *mpelec3 = (TH1F*)hfile->Get("efftracktheta");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("#theta X");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");
       
     c1->cd(3);
     histe5->GetYaxis()->SetTitle("<N> lost");
     gPad->SetGridy();
     histe5->SetLineColor(3);
     histe5->SetMarkerStyle(20);
     //histe5->SetMinimum(0.);
     //histe5->SetMaximum(2.1);
     histe5->SetMarkerColor(4);
     histe5->SetMarkerSize(0.8);
     histe5->GetXaxis()->SetTitle("N RecHits");
     histe5->Draw("Error");
     //histe5->Draw();



     c1->cd(4);
     histe1->GetYaxis()->SetTitle("Track Finder Eff. MaxA");
     gPad->SetGridy();
     histe1->SetLineColor(3);
     histe1->SetMarkerStyle(20);
     histe1->SetMinimum(0.8);
     histe1->SetMaximum(1.2);
     histe1->SetMarkerColor(4);
     histe1->SetMarkerSize(0.8);
     histe1->GetXaxis()->SetTitle("#theta X");
     histe1->Draw("Error");
     //histe1->Draw();

     c1->cd(5);
     histe4->GetYaxis()->SetTitle("Track Finder Eff. Var1");
     gPad->SetGridy();
     histe4->SetLineColor(3);
     histe4->SetMarkerStyle(20);
     histe4->SetMinimum(0.8);
     histe4->SetMaximum(1.2);
     histe4->SetMarkerColor(4);
     histe4->SetMarkerSize(0.8);
     histe4->GetXaxis()->SetTitle("N RecHits");
     histe4->Draw("Error");
     //histe4->Draw();
     
     c1->cd(6);
     histe2->GetYaxis()->SetTitle("Track Finder Eff. Var1");
     gPad->SetGridy();
     histe2->SetLineColor(3);
     histe2->SetMarkerStyle(20);
     histe2->SetMinimum(0.8);
     histe2->SetMaximum(1.2);
     histe2->SetMarkerColor(4);
     histe2->SetMarkerSize(0.8);
     histe2->GetXaxis()->SetTitle("#theta X, [mrad]");
     histe2->Draw("Error");
     //histe2->Draw();

      c1->Update();


    //================
    //============================================================================================================0-0000000000000 37
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
     TF1 *f1 = new TF1("f1","gaus",-0.1,0.1); tocollection->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); tocollection0->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("abs#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("abs#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 38
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,3);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("chisqX");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("#chi2 Var1");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");
           c1->cd(2); 
      TH1F *mpeled3= (TH1F*)hfile->Get("chisq3X");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("#chi2 MaxA");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

       c1->cd(3); 

      TH1F *mpelec3= (TH1F*)hfile->Get("nhitplanesX");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("N RecHits Var1");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

          c1->cd(4); 
      TH1F *mpeled3= (TH1F*)hfile->Get("nhitplanes3X");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("N RecHits MaxA");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");
       
     c1->cd(5); 
     histe5->GetYaxis()->SetTitle("<N> lost");
     gPad->SetGridy();
     histe5->SetLineColor(3);
     histe5->SetMarkerStyle(20);
     //histe5->SetMinimum(0.);
     //histe5->SetMaximum(2.1);
     histe5->SetMarkerColor(4);
     histe5->SetMarkerSize(0.8);
     histe5->GetXaxis()->SetTitle("N RecHits");
     histe5->Draw("Error");
     //histe5->Draw();

     c1->cd(6); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       // mpelec3->SetMarkerSize(0.4);
       // mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("N tracks found");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");



     c1->Update();
    //================
    //============================================================================================================0-0000000000000 39
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
     TF1 *f1 = new TF1("f1","gaus",-0.1,0.1); tocollection->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-5.,5.); tocollection0->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection2");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X I, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ntocollection1");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X III, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("stocollection0");
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("abs#Delta X II, 3St, [mm]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

      
      c1->Update();
    //================
    //============================================================================================================0-0000000000000 40
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);

	      TH1F *mpelec1= (TH1F*)hfile->Get("efftrackdref124");

                        TH1* histe81 = (TH1*)mpelec1->Clone("Efficiency");
                        histe81->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error=0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe81 ->SetBinError(i, error);
			}
                        histe81->GetYaxis()->SetTitle("Eff. good 2 tracks");
			gPad->SetGridy();
                        histe81->SetLineColor(3);
                        histe81->SetMarkerStyle(20);
                        //histe81->SetMinimum(0.);
                        //histe81->SetMaximum(1.1);
                        histe81->SetMarkerColor(1);
                        histe81->SetMarkerSize(0.8);
                        histe81->GetXaxis()->SetTitle("DX");
			histe81->Draw("Error");
                        //histe81->Draw();

			}
			}
     c1->cd(2);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);

	      TH1F *mpelec1= (TH1F*)hfile->Get("Tdref12");

                        TH1* histe82 = (TH1*)mpelec1->Clone("Efficiency");
                        histe82->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error=0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe82 ->SetBinError(i, error);
			}
                        histe82->GetYaxis()->SetTitle("Eff. track in coll.");
			gPad->SetGridy();
                        histe82->SetLineColor(3);
                        histe82->SetMarkerStyle(20);
                        //histe82->SetMinimum(0.);
                        //histe82->SetMaximum(1.1);
                        histe82->SetMarkerColor(2);
                        histe82->SetMarkerSize(0.8);
                        histe82->GetXaxis()->SetTitle("DX");
			histe82->Draw("Error");
                        //histe82->Draw();

			}
			}
     c1->cd(3);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);

	      TH1F *mpelec1= (TH1F*)hfile->Get("eff1trackdref124");

                        TH1* histe83 = (TH1*)mpelec1->Clone("Efficiency");
                        histe83->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error=0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe83 ->SetBinError(i, error);
			}
                        histe83->GetYaxis()->SetTitle("Eff. 1 good at least");
			gPad->SetGridy();
                        histe83->SetLineColor(3);
                        histe83->SetMarkerStyle(20);
                        //histe83->SetMinimum(0.);
                        //histe83->SetMaximum(1.1);
                        histe83->SetMarkerColor(3);
                        histe83->SetMarkerSize(0.8);
                        histe83->GetXaxis()->SetTitle("DX");
			histe83->Draw("Error");
                        //histe83->Draw();

			}
			}
     c1->cd(4);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);

	      TH1F *mpelec1= (TH1F*)hfile->Get("efftrackdref12NoMI");

                        TH1* histe84 = (TH1*)mpelec1->Clone("Efficiency");
                        histe84->Divide(mpelec1,mpelec, 1, 1, "b");
			//         d(x/t)=(x*y/t**2)*sqrt((dx/x)**2+(dy/y)**2), where t=x+y,  y=t-x
			Int_t nentries = (Int_t)(mpelec1->GetEntries());
			for (Int_t i=0;i<=nentries;i++) {
			  Float_t a1r = (Stat_t) (mpelec1->GetBinError(i));
			  Float_t x = (Stat_t) (mpelec1->GetBinContent(i));
			  Float_t a2r = (Stat_t) (mpelec->GetBinError(i));
			  Float_t t = (Stat_t) (mpelec->GetBinContent(i));
			  Float_t error=0.; Float_t y = t-x;
			  if(y==0.) y=1.;
			  if(y>0.&& x>0.){
			    error = fabs(x*y/t**2/2.)*sqrt( (a1r**2/x)**2+(fabs(a2r**2-a1r**2)/y)**2);
			  }
			  if(x==0.) error=0.;
			  histe84 ->SetBinError(i, error);
			}
                        histe84->GetYaxis()->SetTitle("Eff. NoMI");
			gPad->SetGridy();
                        histe84->SetLineColor(3);
                        histe84->SetMarkerStyle(20);
                        //histe84->SetMinimum(0.);
                        //histe84->SetMaximum(1.1);
                        histe84->SetMarkerColor(4);
                        histe84->SetMarkerSize(0.8);
                        histe84->GetXaxis()->SetTitle("DX");
			histe84->Draw("Error");
                        //histe84->Draw();

			}
			}

      c1->Update();
    //====================================================================================================
    //==============================================================================0-0000000000000 41
    //================
     c1->Clear();
     c1->Divide(2,2);

     c1->cd(1); 
      TH1F *mpelec31 = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec31->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec31->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec31->Scale(mscale);
			Int_t i;
			//			mpelec31->GetEntries(nentries);
			Int_t nentries = (Int_t)(mpelec31->GetEntries());
			for (i=1;i<=nentries+1;i++) {
			   Float_t error   = i-i ;
			   //Float_t error   = TMath::Sqrt(i);
			   //Float_t error   = TMath::Sqrt(q[lw+i]);
			  //Float_t error   = 0.0// doesn't work if numerically
			    mpelec31->SetBinError(i,error);
			}
			TH1F *mpelec34= (TH1F*)hfile->Get("efftrackdref124");
                        TH1* histe91 = (TH1*)mpelec34->Clone("Efficiency");
                        histe91->Divide(mpelec34,mpelec31, 1, 1, "b");
                        histe91->GetYaxis()->SetTitle("Eff. good 2 tracks");
                        histe91->SetLineColor(3);
                        histe91->SetMarkerStyle(20);
			gPad->SetGridy();
//                        histe91->SetMinimum(0.8);
//			histe91->SetMaximum(1.2);
                        histe91->SetMarkerColor(1);
                        histe91->SetMarkerSize(0.8);
                        histe91->GetXaxis()->SetTitle("DX");
			histe91->Draw("Error");
                        //histe91->Draw();

	     }
	   }

     c1->cd(2); 
      TH1F *mpelec31 = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec31->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec31->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec31->Scale(mscale);
			Int_t i;
			//			mpelec31->GetEntries(nentries);
			Int_t nentries = (Int_t)(mpelec31->GetEntries());
			for (i=1;i<=nentries+1;i++) {
			   Float_t error   = i-i ;
			   //Float_t error   = TMath::Sqrt(i);
			   //Float_t error   = TMath::Sqrt(q[lw+i]);
			  //Float_t error   = 0.0// doesn't work if numerically
			    mpelec31->SetBinError(i,error);
			}
			TH1F *mpelec34= (TH1F*)hfile->Get("Tdref12");
                        TH1* histe92 = (TH1*)mpelec34->Clone("Efficiency");
                        histe92->Divide(mpelec34,mpelec31, 1, 1, "b");
                        histe92->GetYaxis()->SetTitle("Eff. track in coll.");
                        histe92->SetLineColor(3);
                        histe92->SetMarkerStyle(20);
			gPad->SetGridy();
//                        histe92->SetMinimum(0.8);
//			histe92->SetMaximum(1.2);
                        histe92->SetMarkerColor(2);
                        histe92->SetMarkerSize(0.8);
                        histe92->GetXaxis()->SetTitle("DX");
			histe92->Draw("Error");
                        //histe92->Draw();

	     }
	   }
     c1->cd(3); 
      TH1F *mpelec31 = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec31->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec31->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec31->Scale(mscale);
			Int_t i;
			//			mpelec31->GetEntries(nentries);
			Int_t nentries = (Int_t)(mpelec31->GetEntries());
			for (i=1;i<=nentries+1;i++) {
			   Float_t error   = i-i ;
			   //Float_t error   = TMath::Sqrt(i);
			   //Float_t error   = TMath::Sqrt(q[lw+i]);
			  //Float_t error   = 0.0// doesn't work if numerically
			    mpelec31->SetBinError(i,error);
			}
			TH1F *mpelec34= (TH1F*)hfile->Get("eff1trackdref124");
                        TH1* histe93 = (TH1*)mpelec34->Clone("Efficiency");
                        histe93->Divide(mpelec34,mpelec31, 1, 1, "b");
                        histe93->GetYaxis()->SetTitle("Eff. 1 good at least");
                        histe93->SetLineColor(3);
                        histe93->SetMarkerStyle(20);
			gPad->SetGridy();
//                        histe93->SetMinimum(0.8);
//			histe93->SetMaximum(1.2);
                        histe93->SetMarkerColor(3);
                        histe93->SetMarkerSize(0.8);
                        histe93->GetXaxis()->SetTitle("DX");
			histe93->Draw("Error");
                        //histe93->Draw();

	     }
	   }
     c1->cd(4); 
      TH1F *mpelec31 = (TH1F*)hfile->Get("efftrackdref12");
           if(mpelec31->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec31->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec31->Scale(mscale);
			Int_t i;
			//			mpelec31->GetEntries(nentries);
			Int_t nentries = (Int_t)(mpelec31->GetEntries());
			for (i=1;i<=nentries+1;i++) {
			   Float_t error   = i-i ;
			   //Float_t error   = TMath::Sqrt(i);
			   //Float_t error   = TMath::Sqrt(q[lw+i]);
			  //Float_t error   = 0.0// doesn't work if numerically
			    mpelec31->SetBinError(i,error);
			}
			TH1F *mpelec34= (TH1F*)hfile->Get("efftrackdref12NoMI");
                        TH1* histe94 = (TH1*)mpelec34->Clone("Efficiency");
                        histe94->Divide(mpelec34,mpelec31, 1, 1, "b");
                        histe94->GetYaxis()->SetTitle("Eff. NoMI");
                        histe94->SetLineColor(3);
                        histe94->SetMarkerStyle(20);
			gPad->SetGridy();
//                        histe94->SetMinimum(0.8);
//			histe94->SetMaximum(1.2);
                        histe94->SetMarkerColor(4);
                        histe94->SetMarkerSize(0.8);
                        histe94->GetXaxis()->SetTitle("DX");
			histe94->Draw("Error");
                        //histe94->Draw();

	     }
	   }


      c1->Update();
    //====================================================================================================
    //==============================================================================0-0000000000000 42
    //================
     c1->Clear();
     c1->Divide(1,2);

     c1->cd(1); 
			histe81->Draw("Error");
			histe82->Draw("ErrorSame");
			histe83->Draw("ErrorSame");
			histe84->Draw("ErrorSame");

      c1->cd(2); 
			}
                        histe2->GetYaxis()->SetTitle("Eff. 2 good tr.");
			gPad->SetGridy();
                        histe2->SetLineColor(3);
                        histe2->SetMarkerStyle(20);
                        histe2->SetMinimum(0.);
                        histe2->SetMaximum(1.1);
                        histe2->SetMarkerColor(4);
                        histe2->SetMarkerSize(0.8);
                        histe2->GetXaxis()->SetTitle("#theta X");
			histe2->Draw("Error");
			}
                        histe1->GetYaxis()->SetTitle("Eff. 1 good");
			gPad->SetGridy();
                        histe1->SetLineColor(3);
                        histe1->SetMarkerStyle(20);
                        histe1->SetMinimum(0.);
                        histe1->SetMaximum(1.1);
                        histe1->SetMarkerColor(4);
                        histe1->SetMarkerSize(0.8);
                        histe1->GetXaxis()->SetTitle("#theta X");
			histe1->Draw("ErrorSame");




     c1->Update();
    //====================================================================================================
    //==============================================================================0-0000000000000 43
    //================
     c1->Clear();
     c1->Divide(1,2);

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("efftrackdref12");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(1.4);
       mpelec->GetXaxis()->SetTitle("#Delta X, mm at Z=8m");
       mpelec->GetYaxis()->SetTitle("N");
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(2); 
			histe91->Draw("Error");
			gPad->SetGridy();
                        histe91->GetYaxis()->SetTitle("Eff. with 2 tracks");
			histe91->GetXaxis()->SetTitle("#Delta X at Z=8m");
			histe92->Draw("ErrorSame");
			histe93->Draw("ErrorSame");
			histe94->Draw("ErrorSame");


     c1->Update();
    //============================================================================================================0-0000000000000 44
   //    dphitrack2 dthtrack2 dthetax2                           clnum3Xinside d3thetax2
   //    dphitrack dthtrack dthetax 
    //================
     c1->Clear();
     c1->Divide(2,2);

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 1st track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("ccchindfx2");
      //   gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#chi2 2nd track");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta");
      //   gPad->SetLogy();
       mpelec3->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("mintheta2");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->Update();
    //================
    //====================================================================================================
    //====================================================================================================
    //====================================================================================================
    //====================================================================================================
    //====================================================================================================





                               //// wait

//    getchar();

    //======================================================================
	   }//switch
    //======================================================================
    // close and delete all possible things:

   psfile->Close();

    hfile->Close();
    hfile->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}
