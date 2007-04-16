{

   //======================================================================
      printf("track3D: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
	  gStyle->SetOptStat(0);   //  no statistics _or_
	 	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//gStyle->SetOptStat(0101);// name and entries
	//gStyle->SetOptStat(11110000);// under, over, integral
	//  gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	gStyle->SetOptFit(00010);// constant, mean and sigma only !!
	//gStyle->SetOptFit(00001);// hi2/nu, constant, mean and sigma only !!
	//gStyle->SetOptFit(00011);// constant, mean and sigma only !!
	// gStyle->SetOptFit(1101);
	// gStyle->SetOptFit(1011);
	//
	//gStyle->SetStatX(0.98);
	//gStyle->SetStatY(0.99);
	//gStyle->SetStatW(0.30);
	//gStyle->SetStatH(0.25);
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
        gStyle->SetTitleH(0.15);             // title height
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
      printf("track3D: root file TheAnalysis is Open    \n");
    hfile.ls();
    hfile->Print();
//    getchar();
//
//    TPostScript* psfile = new TPostScript("zhplot.ps",111);
    TPostScript psfile ("track3D.ps", 111);
//
//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);

   c1 = new TCanvas("c1","FP420Analysis",200,10,700,900);

//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);
      printf("TCanvas Test for FP420Analysis is Open \n");


    //======================================================================0-0000000000000
      /*
   int Axis;        // "A"  Axis are not drawn around the graph.
   int Bar;         // "B"  A Bar chart is drawn at each point.
   int Curve;       // "C"  A smooth Curve is drawn.
   int Error;       // "E"  Draw Errors with current marker type and size.
   int Fill;        // "F"  A fill area is drawn ("CF" draw a smooth fill area).
   int Off;         // "][" With H option, the first and last vertical lines are not drawn.
   int Keep;        // "K"  The status of the histogram is kept in memory
   int Line;        // "L"  A simple polyline beetwen every point is drawn.
   int Mark;        // "P"  The current Marker is drawn at each point
   int Same;        // "S"  Histogram is plotted in the current PAD.
   int Update;      // "U"  Update histogram previously plotted with option K
   int Plus;        // "+", "-", "+-"  Bin contents are added and/or substracted
   int Star;        // "*"  A * is plotted at each point
   int Arrow;       // "ARR"   Draw 2D plot with Arrows.
   int Box;         // "BOX"   Draw 2D plot with proportional Boxes.
   int Char;        // "CHAR"  Draw 2D plot with a character set.
   int Color;       // "COL"   Draw 2D plot with Colored boxes.
   int Contour;     // "CONT"  Draw 2D plot as a Contour plot.
   int Func;        // "FUNC"  Draw only the function (for example in case of fit).
   int Hist;        // "HIST"  Draw only the histogram.
   int Lego;        // "LEGO"  Draw as a Lego plot(LEGO,Lego=1, LEGO1,Lego1=11, LEGO2,Lego=12).
   int Scat;        // "SCAT"  Draw 2D plot a Scatter plot.
   int Surf;        // "SURF"  Draw as a Surface (SURF,Surf=1, SURF1,Surf=11, SURF2,Surf=12)
   int Text;        // "TEXT"  Draw 2D plot with the content of each cell.
   int Tri;         // "TRI"   Draw 2D plot with Delaunay triangles.
   int System;      // type of coordinate system(1=car,2=pol,3=cyl,4=sph,5=psr)
   int Zscale;      // "Z"   to display the Z scale (color palette)
   int FrontBox;    //  = 0 to suppress the front box
   int BackBox;     //  = 0 to suppress the back box
   int List;        //  = 1 to generate the TObjArray "contours"
   int HighRes;     //  = 1 to select high resolution
   int Proj;        //  = 1 to get an Aitoff projection, usefull for skymaps or exposure maps..   
                    //  = 2 to get a Mercator ptojection
                    //  = 3 to get a Sinusoidal ptojection
                    //  = 4 to get a Parabolic ptojection
   int AxisPos;     //  Axis position

   // the following structure members are set to 1 if the corresponding option
   // in the current style is selected.

   int Logx;        // log scale in X. Also set by histogram option
   int Logy;        // log scale in Y. Also set by histogram option
   int Logz;        // log scale in Z. Also set by histogram option
*/
    //======================================================================0-0000000000000
      /*
       c->cd(2);
       TPaveText *pt = new TPaveText(0.01,0.01,0.99,0.99);
       pt->SetLineColor(1);
       TText *text = pt->AddText("TGeoCompositeShape - composite shape class");
       text->SetTextColor(2);
       pt->AddText("----- It's an example of boolean union operation : A + B");
       pt->AddText("----- A == part of sphere (5-175, 0-340), B == pgon");
       pt->AddText(" ");
       pt->SetAllWith("-----","color",4);
       pt->SetAllWith("-----","font",72);
       pt->SetAllWith("-----","size",0.04);
       pt->SetTextAlign(12);
       pt->SetTextSize(.044);
       pt->Draw();
       c->cd(1);  
*/
  //======================================================================0-0000000000000
      /*
    Float_t x;
       for (i=0;i<=ncx+1;i++) {
          x = h1->GetBinCenter(i);
          h1->Fill(x,hi(id,i));
          if (hcbits[8]) h1->SetBinError(i,hie(id,i));
          if (gr && i>0 && i<=ncx) gr->SetPoint(i,x,hif(id,i));
       }
       Float_t ymin, ymax;
       if (hcbits[19]) {
          ymax = q[lcid+kMAX1];
          h1->SetMaximum(ymax);
       }
       if (hcbits[20]) {
          ymin = q[lcid+kMIN1];
          h1->SetMinimum(ymin);
       }
       h1->SetEntries(nentries);
*/
    //======================================================================0-0000000000000
      /*
int nentries; Int_t i;
h1->GetEntries(nentries);
       for (i=0;i<=nentries;i++) 
	 // Float_t error   = TMath::Sqrt(q[lw+i]);
Float_t error   = 0.0
h1->SetBinError(i,error);
       }
*/
    //======================================================================0-0000000000000
      /*
    Int_t i;
       Float_t x;
       Float_t y = 0.5*(ymin+ymax);
       for (i=1;i<=ncx;i++) {
          Int_t n = Int_t(q[ln+i]);
          hix(id,i,x);
          for (Int_t j=0;j<n;j++) {
             p->Fill(x+offsetx,y);
          }
          Float_t content = q[lcont+kCON1+i];
          Float_t error   = TMath::Sqrt(q[lw+i]);
          p->SetBinContent(i,content);
          p->SetBinError(i,error);
       }   
*/
//======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //================

    //================   Clusters   =========================================

    //==============================================================================0-0000000000000 1
    //================
     c1->Clear();

     c1->Divide(1,2);

     c1_1->Divide(2,1);
          c1_1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("ZSimHit");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
			Int_t i;
			//			mpelec->GetEntries(nentries);
			Int_t nentries = (Int_t)(mpelec->GetEntries());
			for (i=1;i<=nentries+1;i++) {
			   Float_t error   = i-i ;
			   //Float_t error   = TMath::Sqrt(i);
			   //Float_t error   = TMath::Sqrt(q[lw+i]);
			  //Float_t error   = 0.0// doesn't work if numerically
			    mpelec->SetBinError(i,error);
			}
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("ZSimHit");
       mpelec->GetYaxis()->SetTitle("Bottom");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1_1->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("ZSimHitNumbCl");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("ZSimHitNumbCl");
       mpelec1->GetYaxis()->SetTitle("Top");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       c1_2->Divide(1,1);
     c1_2->cd(1);
                        TH1* histe5 = (TH1*)mpelec1->Clone("Efficiency");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
                        histe5->GetYaxis()->SetTitle("<N cl>");
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
			// histe5->SetMaximum(10.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("XY planes");
			histe5->Draw("Error");
                        //histe5->Draw();

             }
           }
     c1->Update();
    //==================================================================================================== 2
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //==================================================================================================== 3
     c1->Clear();
     c1->Divide(1,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("npart420");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("npart420");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

     c1->cd(2); 
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


     c1->Update();
    //==================================================================================================== 4
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("npart420");
    //  gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(1.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("N particles - tracks");
       mpelec1->SetLineColor(4);
       mpelec1->Draw("Error");
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(1.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw("Same");
       mpelec3->Draw("Same");
//       mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("NHitsAll");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(1.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("NHitsAll");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //==================================================================================================== 5
    //======================================================================0-2D
     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryEta");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");
       mpelec3->GetXaxis()->SetTitle("#eta ");
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryEtaTr");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kRed);
       mpelec3->SetLineColor(4);
       mpelec3->Draw("Same");


     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryXi");
        gPad->SetLogx();
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");
       mpelec3->GetXaxis()->SetTitle("#xi ");
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryXiTr");
        gPad->SetLogx();
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kRed);
       mpelec3->SetLineColor(4);
       mpelec3->Draw("Same");



     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryXiLog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");
       mpelec3->GetXaxis()->SetTitle("log(#xi) ");
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryXiTrLog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kRed);
       mpelec3->SetLineColor(4);
       mpelec3->Draw("Same");



     c1->Update();
    //======================================================================
    //==============================================================================0-0000000000000 6
    //================
     c1->Clear();

     c1->Divide(1,2);

     c1_1->Divide(2,1);

     c1_1->cd(1);
      TH1F *mpelec1= (TH1F*)hfile->Get("thetaXmrad");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       mpelec1->GetXaxis()->SetTitle("#theta X, mr");

     c1_1->cd(2);
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryPhigrad");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
//        mpelec3->GetXaxis()->SetTitle("Ecra");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");
       mpelec3->GetXaxis()->SetTitle("#phi, degree");

     c1_2->Divide(1,1);
     c1_2->cd(1);
      TH2F *mp2d= (TH2F*)hfile->Get("2DXY420");
       mp2d->SetMarkerStyle(20);
       mp2d->SetMarkerSize(0.4);
       mp2d->GetYaxis()->SetLabelSize(0.04);
       mp2d->SetMarkerColor(kBlue);
       mp2d->SetLineColor(3);
       mp2d->GetXaxis()->SetTitle("2D X vs. Y, mm at 420m");
       mp2d->Draw("Box");
       //       mp2d->Draw();
      TH2F *mp2d= (TH2F*)hfile->Get("2DXY420Tr");
       mp2d->SetMarkerStyle(20);
       mp2d->SetMarkerSize(0.4);
       mp2d->GetYaxis()->SetLabelSize(0.04);
       mp2d->SetMarkerColor(kRed);
       mp2d->SetLineColor(4);
       mp2d->Draw("BoxSame");

     c1->Update();
    //==============================================================================0-0000000000000 7
    //================
     c1->Clear();

     c1->Divide(1,2);

     c1_1->Divide(2,1);

     c1_1->cd(1);
      TH1F *mpeler = (TH1F*)hfile->Get("NumOfClusters");
//           if(mpeler->IsA()->InheritsFrom("TH1F")){
//            Double_t mintegral = mpeler->Integral();
//             if(mintegral>0.0){
//              Double_t mscale = 100./mintegral;
//                mpeler->Scale(mscale);
                gPad->SetLogy();
		mpeler->SetLineColor(2);
		mpeler->SetMarkerStyle(20);
		mpeler->SetMarkerSize(0.4);
		mpeler->GetYaxis()->SetLabelSize(0.04);
		mpeler->SetMarkerColor(kBlue);
 		mpeler->GetXaxis()->SetTitle("Number of clusters found");
// 		mpeler->GetYaxis()->SetTitle("Nev");
		mpeler->Draw("Error");
//             }
//           }

     c1_1->cd(2);
     //      TH1F *mpelec2d= (TH1F*)hfile->Get("2DZSimHitNumbCl");
      TH2F *mpelec2d= (TH2F*)hfile->Get("2DZSimHitNumbCl");
       mpelec2d->SetMarkerStyle(20);
       mpelec2d->SetMarkerSize(0.4);
       mpelec2d->GetYaxis()->SetLabelSize(0.04);
       mpelec2d->SetMarkerColor(kBlue);
        mpelec2d->GetXaxis()->SetTitle("Z, mm");
        mpelec2d->GetYaxis()->SetTitle("Ncl");
       mpelec2d->SetLineColor(3);
       mpelec2d->Draw();
//       mpelec2d->Draw("Error");

     c1_2->Divide(1,1);
     c1_2->cd(1);
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
			// histe5->SetMaximum(10.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetYaxis()->SetTitle("<N cl>");
                        histe5->GetXaxis()->SetTitle("XYplanes");
			histe5->Draw("Error");
                        //histe5->Draw();

     c1->Update();
    //====================================================================================================  8

    //======================================================================
    //================
     c1->Clear();
   //   c1->Clear();
     c1->Divide(2,2); 

     //gStyle->SetCanvasDefW(650);
     //Style->SetCanvasDefH(950);
     c1->cd(1); 
      TH1F *mpelec = (TH1F*)hfile->Get("XClusterCog");
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.4);
       mpelec->GetXaxis()->SetTitle("CogX, [channel]");
       mpelec->GetXaxis()->SetLabelSize(0.04);
       mpelec->GetYaxis()->SetLabelSize(0.02);
       //mpelec->GetYaxis()->SetTitle("Nev");
       // mpelec->SetMinimum(0.);
       // mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("YClusterCog");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetXaxis()->SetTitle("CogY, [channel]");
       mpelec1->GetXaxis()->SetLabelSize(0.04);
       mpelec1->GetYaxis()->SetLabelSize(0.02);
       //mpelec1->GetYaxis()->SetTitle("Nev");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

             c1->cd(3); 
	     //   pad1 = new TPad("pad1"," ",0.05,0.50,0.95,0.95,21);

   pad1 = new TPad("pad1"," ",0.01,0.01,0.99,0.99,21);
   pad1->Draw();
   pad1->cd();
   pad1->SetGridx();
   pad1->SetGridy();
   pad1->GetFrame()->SetFillColor(23);
   pad1->GetFrame()->SetBorderMode(-1);
   pad1->GetFrame()->SetBorderSize(5);
   TH2F *hpxpy = (TH2F*)hfile->Get("X2DSimHitcogCopy");
 //   hpxpy->SetFillColor(33);
   hpxpy->GetXaxis()->SetLabelSize(0.03);
   hpxpy->GetYaxis()->SetLabelSize(0.03);
   hpxpy->SetMarkerColor(kRed);
   hpxpy->GetXaxis()->SetTitle("X SimHit, [mm]");
   hpxpy->GetYaxis()->SetTitle("X cog, [mm]");
   hpxpy->Draw();


   c1->cd(4); 
   // pad2 = new TPad("pad2"," ",0.05,0.05,0.95,0.45,21);
   pad2 = new TPad("pad2"," ",0.001,0.001,0.999,0.999,21);
   pad2->Draw();
   pad2->cd();
   pad2->SetGridx();
   pad2->SetGridy();
   pad2->GetFrame()->SetFillColor(40);
   //   pad2->GetFrame()->SetBorderMode(-1);
   // pad2->GetFrame()->SetBorderSize(5);
   TH2F *hpxpy = (TH2F*)hfile->Get("Y2DSimHitcogCopy");
    hpxpy->GetXaxis()->SetLabelSize(0.03);
   hpxpy->GetYaxis()->SetLabelSize(0.03);
   hpxpy->SetMarkerColor(kRed);
   hpxpy->GetXaxis()->SetTitle("Y SimHit, [mm]");
   hpxpy->GetYaxis()->SetTitle("Y cog, [mm]");
   hpxpy->Draw();



     c1->Update();

    //============================================================================================================ 9
    //================
     c1->Clear();
     c1->Divide(2,2);
     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("XClusterCog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XClusterCog");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

           c1->cd(2); 
      TH1F *mpeled3= (TH1F*)hfile->Get("YClusterCog");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("YClusterCog");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");

       c1->cd(3); 

      TH1F *mpelec3= (TH1F*)hfile->Get("XClustSize");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XClustSize");
       mpelec3->SetFillColor(33);
       mpelec3->SetLineColor(3);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

          c1->cd(4); 
      TH1F *mpeled3= (TH1F*)hfile->Get("YClustSize");
       mpeled3->SetMarkerStyle(20);
       mpeled3->SetMarkerSize(0.4);
       mpeled3->GetYaxis()->SetLabelSize(0.04);
       mpeled3->SetMarkerColor(kBlue);
       mpeled3->GetXaxis()->SetTitle("YClustSize");
       mpeled3->SetFillColor(20);
       mpeled3->SetLineColor(3);
       mpeled3->Draw();
       mpeled3->Draw("ErrorSame");



      c1->Update();
     //================
    //==================================================================================================== 10
    //======================================================================
     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
      TH1F *mpelec = (TH1F*)hfile->Get("XstripSimHit");
//           if(mpelec->IsA()->InheritsFrom("TH1F")){
//            Double_t mintegral = mpelec->Integral();
//             if(mintegral>0.0){
//              Double_t mscale = 100./mintegral;
//                mpelec->Scale(mscale);
		mpelec->SetLineColor(2);
		mpelec->SetMarkerStyle(20);
		mpelec->SetMarkerSize(0.4);
		mpelec->GetYaxis()->SetLabelSize(0.04);
		mpelec->SetMarkerColor(kBlue);
// 		mpelec->GetXaxis()->SetTitle("Energy");
// 		mpelec->GetYaxis()->SetTitle("Nev");
		mpelec->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("XSimHit");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");



     c1->cd(3); 
      TH1F *mpelec2= (TH1F*)hfile->Get("XDeltaStrip");
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerSize(0.4);
       mpelec2->GetYaxis()->SetLabelSize(0.04);
       mpelec2->SetMarkerColor(kBlue);
//        mpelec2->GetXaxis()->SetTitle("Ecra");
//        mpelec2->GetYaxis()->SetTitle("Nev");
       mpelec2->SetLineColor(3);
       mpelec2->Draw("Error");


                     c1->cd(4); 
			TH1F* histe2 = (TH1F*) hfile->Get("XClustSize");
			histe2->SetMarkerStyle(20);
			histe2->SetMarkerSize(0.4);
			histe2->GetYaxis()->SetLabelSize(0.05);
//			histe2->Divide(mpelec1,mpelec, 1, 1, "b2");
// 			histe2->GetXaxis()->SetTitle("Energy");
// 			histe2->GetYaxis()->SetTitle("MeanEcra");
			histe2->SetLineColor(6);
                        histe2->Draw("Error");
//             }
//           }
     c1->Update();
    //====================================================================================================

    //==================================================================================================== 11
    //======================================================================
     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
      TH1F *mpelec = (TH1F*)hfile->Get("YstripSimHit");
//           if(mpelec->IsA()->InheritsFrom("TH1F")){
//            Double_t mintegral = mpelec->Integral();
//             if(mintegral>0.0){
//              Double_t mscale = 100./mintegral;
//                mpelec->Scale(mscale);
		mpelec->SetLineColor(2);
		mpelec->SetMarkerStyle(20);
		mpelec->SetMarkerSize(0.4);
		mpelec->GetYaxis()->SetLabelSize(0.04);
		mpelec->SetMarkerColor(kBlue);
// 		mpelec->GetXaxis()->SetTitle("Energy");
// 		mpelec->GetYaxis()->SetTitle("Nev");
		mpelec->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("YSimHit");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");



     c1->cd(3); 
      TH1F *mpelec2= (TH1F*)hfile->Get("YDeltaStrip");
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerSize(0.4);
       mpelec2->GetYaxis()->SetLabelSize(0.04);
       mpelec2->SetMarkerColor(kBlue);
//        mpelec2->GetXaxis()->SetTitle("Ecra");
//        mpelec2->GetYaxis()->SetTitle("Nev");
       mpelec2->SetLineColor(3);
       mpelec2->Draw("Error");


                     c1->cd(4); 
			TH1F* histe = (TH1F*)hfile->Get("YClustSize");
			histe->SetMarkerStyle(20);
			histe->SetMarkerSize(0.4);
			histe->GetYaxis()->SetLabelSize(0.05);
//			histe->Divide(mpelec1,mpelec, 1, 1, "b2");
// 			histe->GetXaxis()->SetTitle("Energy");
// 			histe->GetYaxis()->SetTitle("MeanEcra");
			histe->SetLineColor(6);
                        histe->Draw("Error");
//             }
//           }
     c1->Update();
    //====================================================================================================  12
     c1->Clear();
     c1->Divide(2,3); 

     c1->cd(1); 
      TH1F *mpelec = (TH1F*)hfile->Get("YDeltaStrip");
//           if(mpelec->IsA()->InheritsFrom("TH1F")){
//            Double_t mintegral = mpelec->Integral();
//             if(mintegral>0.0){
//              Double_t mscale = 100./mintegral;
//                mpelec->Scale(mscale);
		mpelec->SetLineColor(6);
		mpelec->SetMarkerStyle(20);
		mpelec->SetMarkerSize(0.4);
		mpelec->GetYaxis()->SetLabelSize(0.04);
		mpelec->SetMarkerColor(kBlue);
		mpelec->GetXaxis()->SetTitle("#Delta channels");
// 		mpelec->GetXaxis()->SetTitle("Energy");
// 		mpelec->GetYaxis()->SetTitle("Nev");
//		mpelec->Draw("Error");
		mpelec->Draw();

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("XDeltaStrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("#Delta channelX");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();



     c1->cd(3); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Xstrip_deltaxx_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Xsim-Xrec], [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");


                     c1->cd(4); 
		     //gStyle->SetOptFit();
		     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Ystrip_deltayy_clsize1->Fit("f1","RI");

			TH1F* histe7 = (TH1F*)hfile->Get("Ystrip_deltayy_clsize1");
			histe7->SetMarkerStyle(20);
			histe7->SetMarkerSize(0.8);
			histe7->GetYaxis()->SetLabelSize(0.05);
//			histe7->Divide(mpelec1,mpelec, 1, 1, "b2");
// 			histe7->GetXaxis()->SetTitle("Energy");
// 			histe7->GetYaxis()->SetTitle("MeanEcra");
			histe7->SetLineColor(2);
//                        histe7->Draw("Error");
			histe7->GetYaxis()->SetTitleSize(0.06);
			histe7->GetXaxis()->SetTitleSize(0.06);
			histe7->GetXaxis()->SetTitle("#Delta [Ysim-Yrec], [mm]");
			histe7->Draw();
			histe7->Draw("ErrorSame");


     c1->cd(5); 
      TH1F *mpelec1= (TH1F*)hfile->Get("XClustSize");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(4);
//       mpelec1->Draw("Error");
       mpelec1->Draw();

     c1->cd(6); 
      TH1F *mpelec1= (TH1F*)hfile->Get("YClustSize");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(4);
//       mpelec1->Draw("Error");
       mpelec1->Draw();



//             }
//           }
     c1->Update();
    //==========================================================================================================13
    //=======SetTitle("m_{K#pi#pi} - m_{K#pi}[GeV/c^{2}]");
    c1->Clear();
    c1->Divide(1,2);
    //    c1->SetBottomMargin(0.15);

     c1->cd(1); 
     //gStyle->SetOptFit();
//    TF1 *f1 = new TF1("f1","gaus",-0.15,0.15);

    c1->cd(1); 
    //Xstrip_deltaxx_clsize1->GetXaxis()->SetTitle("#Delta_{Xsim-Xrec}, [mm]"); 
    //Xstrip_deltaxx_clsize1->GetXaxis()->SetTitleSize(0.06); 
    //Xstrip_deltaxx_clsize1->GetYaxis()->SetTitleSize(0.06); 
    ////Xstrip_deltaxx_clsize1->GetXaxis()->SetTitleOffset(0.4); 
Xstrip_deltaxx_clsize1->SetMarkerSize(1.1);
Xstrip_deltaxx_clsize1->SetMarkerColor(4);
Xstrip_deltaxx_clsize1->SetMarkerStyle(8);
Xstrip_deltaxx_clsize1->Draw("Error");
Xstrip_deltaxx_clsize1->Draw("ErrorSame");
    //Xstrip_deltaxx_clsize1->Fit("f1","RI");


    //   gStyle->SetOptStat(1101);// mean and rms only !!
    //   gStyle->SetOptFit(0);
    //   gStyle->SetOptFit(0);

   c1->SetGrid();
   c1->cd(2); Ystrip_deltayy_clsize1->SetLineColor(3);Ystrip_deltayy_clsize1->SetMarkerColor(4);Ystrip_deltayy_clsize1->Draw("Error");Ystrip_deltayy_clsize1->Draw("ErrorSame");




     c1->Update();

    //======================================================================                                 14
     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
//       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AdcAmplitudeX");
       mpelec1->GetYaxis()->SetTitle(" ");
       mpelec1->SetLineColor(3);
       mpelec1->SetFillColor(33);
       mpelec1->Draw();
       mpelec1->Draw("ErrorSame");



     c1->cd(2); 
      TH1F *mpelec2= (TH1F*)hfile->Get("DigiXstripAdcSigma");
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerSize(0.4);
//       mpelec2->GetYaxis()->SetLabelSize(0.04);
       mpelec2->SetMarkerColor(kBlue);
        mpelec2->GetXaxis()->SetTitle("AdcAmpSigNoiseX");
        mpelec2->GetYaxis()->SetTitle(" ");
       mpelec2->SetLineColor(3);
       mpelec2->SetFillColor(33);
       mpelec2->Draw();
       mpelec2->Draw("ErrorSame");


     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("DigiYstripAdc");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
//       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("AdcAmplitudeY");
        mpelec3->GetYaxis()->SetTitle(" ");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("DigiYstripAdcSigma");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
//       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
        mpelec3->GetXaxis()->SetTitle("AdcAmpSigNoiseY");
        mpelec3->GetYaxis()->SetTitle(" ");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");


     c1->Update();



    //======================================================================0-0000000000000 15
    //================
     c1->Clear();
     c1->Divide(2,2);

     c1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("iu0");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
			Int_t i;
			//			mpelec->GetEntries(nentries);
			Int_t nentries = (Int_t)(mpelec->GetEntries());
			for (i=1;i<=nentries+1;i++) {
			   Float_t error   = i-i ;
			   //Float_t error   = TMath::Sqrt(i);
			   //Float_t error   = TMath::Sqrt(q[lw+i]);
			  //Float_t error   = 0.0// doesn't work if numerically
			    mpelec->SetBinError(i,error);
			}
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("iu");
       mpelec->GetYaxis()->SetTitle("Bottom");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");

     c1->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("iu1");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("iu");
       mpelec1->GetYaxis()->SetTitle("Top");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
     c1->cd(3);
                        TH1* histe5 = (TH1*)mpelec1->Clone("Efficiency b");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
                        histe5->GetYaxis()->SetTitle("Efficiency");
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
                        histe5->SetMaximum(1.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("Channel");
			histe5->Draw("Error");
                        //histe5->Draw();

     c1->cd(4);
                        TH1* histe6 = (TH1*)mpelec1->Clone("Efficiency");
                        histe6->Divide(mpelec1,mpelec, 1, 1, "b2");
                        histe6->GetYaxis()->SetTitle("Efficiency");
                        histe6->SetLineColor(6);
                        histe6->SetMinimum(0.);
                        histe6->SetMaximum(1.1);
                        histe6->SetMarkerStyle(20);
                        histe6->SetMarkerColor(4);
                        histe6->SetMarkerSize(0.2);
                        histe6->GetXaxis()->SetTitle("Plane continuius number");
			 histe6->Draw("Error");
                        //histe6->Draw();
             }
           }
     c1->Update();
    //======================================================================0-0000000000000- 16

     //     gStyle->SetOptStat(0);
     
     c1->Clear();
     c1->Divide(1,1);

     c1->cd(1);
     TF1 *p1 = new TF1("p1","pol1",1.,81.); histe5->Fit("p1","RI");
     histe5->Draw("Error");

     c1->cd(2);
     TF1 *p1 = new TF1("p1","pol1",1.,81.); histe6->Fit("p1","RI");
     histe6->Draw("Error");

     c1->Update();

    //======================================================================                         17
     //     gStyle->SetOptStat(0);
     c1->Clear();
     c1->Divide(1,2);

     c1->cd(1);
       histe6->SetMarkerSize(0.4);
     histe6->Draw("Error");

     c1->Divide(2,2);
     c1->cd(3);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta_{Xsim-Xrec}, [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");
     c1->cd(4);
       histe7->SetMarkerSize(0.8);
       histe7->GetYaxis()->SetTitleSize(0.06);
       histe7->GetXaxis()->SetTitleSize(0.06);
       histe7->GetXaxis()->SetTitle("#Delta_{Ysim-Yrec}, [mm]");
       histe7->Draw();
       histe7->Draw("ErrorSame");

     c1->Update();


    //====================================================================================================
    //======================================================================                                     18
     //     gStyle->SetOptStat(0);
     c1->Clear();
     c1->Divide(2,2);

     c1->cd(1);
       mpeler->SetMarkerSize(0.8);
     mpeler->Draw("Error");
     mpeler->SetFillColor(33);

     c1->cd(2);
       histe6->SetMarkerSize(0.6);
     histe6->Draw("Error");
     histe6->SetFillColor(33);

     c1->cd(3);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta_{Xsim-Xrec}, [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");
       mpelec7->SetFillColor(33);
     c1->cd(4);
       histe7->SetMarkerSize(0.8);
       histe7->GetYaxis()->SetTitleSize(0.06);
       histe7->GetXaxis()->SetTitleSize(0.06);
       histe7->GetXaxis()->SetTitle("#Delta_{Ysim-Yrec}, [mm]");
       histe7->Draw();
       histe7->Draw("ErrorSame");
       histe7->SetFillColor(33);

     c1->Update();


    //====================================================================================================
    //============================================================================================================19
    //================
     c1->Clear();
     c1->Divide(2,3);
     c1->cd(1); 

      TH1F *mpelec3= (TH1F*)hfile->Get("XClusterCog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XClusterCog");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");


     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("XWClusterCog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XWClusterCog");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("XXW2DTrue");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.8);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XXW2DTrue");
       mpelec3->SetLineColor(2);
       mpelec3->Draw();
       mpelec3->Draw("Box");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("XXW2DCluster");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.8);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XXW2DCluster");
       mpelec3->SetLineColor(2);
       mpelec3->Draw();
       mpelec3->Draw("Box");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("XXW2DReco");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.8);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("XXW2DReco");
       mpelec3->SetLineColor(2);
       mpelec3->Draw();
       mpelec3->Draw("Box");

     c1->cd(6); 
      TH1F *mpelec1= (TH1F*)hfile->Get("NumOfClustersX");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("NumOfClustersX");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();

     c1->Update();


    //============================================================================================================20
    //================
     c1->Clear();
     c1->Divide(2,3);
     c1->cd(1); 

     c1->cd(1); 

      TH1F *mpelec3= (TH1F*)hfile->Get("YClusterCog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("YClusterCog");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");


     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("YWClusterCog");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("YWClusterCog");
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw();
       mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("YYW2DTrue");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.8);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("YYW2DTrue");
       mpelec3->SetLineColor(2);
       mpelec3->Draw();
       mpelec3->Draw("Box");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("YYW2DCluster");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.8);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("YYW2DCluster");
       mpelec3->SetLineColor(2);
       mpelec3->Draw();
       mpelec3->Draw("Box");

     c1->cd(5); 
      TH1F *mpelec3= (TH1F*)hfile->Get("YYW2DReco");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.8);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->GetXaxis()->SetTitle("YYW2DReco");
       mpelec3->SetLineColor(2);
       mpelec3->Draw();
       mpelec3->Draw("Box");


     c1->cd(6); 
      TH1F *mpelec1= (TH1F*)hfile->Get("NumOfClustersY");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("NumOfClustersY");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();

     c1->Update();


    //====================================================================================================  21
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("XDeltaStrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("#Delta channelX");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();



     c1->cd(3); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Xstrip_deltaxx_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Xsim-Xrec], [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("XDeltaStripW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("#Delta channelXW");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();



     c1->cd(4); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Xstrip_deltaxxW_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->SetFillColor(33);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Xsim-Xrec]W, [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");


     c1->Update();
    //====================================================================================================  22
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("YDeltaStrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("#Delta channelY");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();



     c1->cd(3); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Ystrip_deltayy_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Ysim-Yrec], [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("YDeltaStripW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("#Delta channelYW");
       mpelec1->SetLineColor(6);
//       mpelec1->Draw("Error");
       mpelec1->Draw();



     c1->cd(4); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Ystrip_deltayyW_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->SetFillColor(33);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Ysim-Yrec]W, [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");


     c1->Update();
    //======================================================================                          23
    //================
     c1->Clear();
     c1->Divide(2,3); 

     c1->cd(1); 
      TH1F *mpelec = (TH1F*)hfile->Get("XClustSize");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
	      //              mpelec->Scale(mscale);
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.8);
       mpelec->GetXaxis()->SetTitle("XClustSize");
       mpelec->GetYaxis()->SetTitle(" ");
       // mpelec->SetMinimum(0.);
       // mpelec->SetMaximum(20.);
       mpelec->SetLineColor(3);
       mpelec->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("XAmplitudesMax");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetXaxis()->SetTitle("XAmplitudeMax");
       mpelec1->GetYaxis()->SetTitle(" ");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

            c1->cd(5); 
                        TH1F *histe= (TH1F*)hfile->Get("XAmplitudesRest");
//			histe->Divide(mpelec1,mpelec, 1, 1, "b");
//			histe->GetYaxis()->SetTitle("Efficiency b");
			histe->SetLineColor(3);
			histe->SetMarkerStyle(20);
//			histe->SetMinimum(0.);
//			histe->SetMaximum(1.1);
			histe->SetMarkerColor(4);
			histe->SetMarkerSize(0.4);
                        histe->GetXaxis()->SetTitle("XAmplitudeRest");
                        histe->GetYaxis()->SetTitle(" ");
			histe->SetLineColor(3);
			histe->Draw("Error");

     c1->cd(2); 
                        TH1F *histe1= (TH1F*)hfile->Get("YClustSize");
//			histe1->Divide(mpelec1,mpelec, 1, 1, "b2");
//			histe1->GetYaxis()->SetTitle("Efficiency b2");
//			histe1->SetMinimum(0.);
//			histe1->SetMaximum(1.1);
			histe1->SetMarkerStyle(20);
			histe1->SetMarkerColor(4);
			histe1->SetMarkerSize(0.8);
                        histe1->GetXaxis()->SetTitle("YClustSize");
                        histe1->GetYaxis()->SetTitle(" ");
			histe1->SetLineColor(6);
                        histe1->Draw("Error");
     c1->cd(4); 
                        TH1F *histe1= (TH1F*)hfile->Get("YAmplitudesMax");
//			histe1->Divide(mpelec1,mpelec, 1, 1, "b2");
//			histe1->GetYaxis()->SetTitle("Efficiency b2");
//			histe1->SetMinimum(0.);
//			histe1->SetMaximum(1.1);
			histe1->SetMarkerStyle(20);
			histe1->SetMarkerColor(4);
			histe1->SetMarkerSize(0.4);
                        histe1->GetXaxis()->SetTitle("YAmplitudesMax");
                        histe1->GetYaxis()->SetTitle(" ");
			histe1->SetLineColor(6);
                        histe1->Draw("Error");
     c1->cd(6); 
                        TH1F *histe1= (TH1F*)hfile->Get("YAmplitudesRest");
//			histe1->Divide(mpelec1,mpelec, 1, 1, "b2");
//			histe1->GetYaxis()->SetTitle("Efficiency b2");
//			histe1->SetMinimum(0.);
//			histe1->SetMaximum(1.1);
			histe1->SetMarkerStyle(20);
			histe1->SetMarkerColor(4);
			histe1->SetMarkerSize(0.4);
                        histe1->GetXaxis()->SetTitle("YAmplitudeRest");
                        histe1->GetYaxis()->SetTitle(" ");
			histe1->SetLineColor(6);
                        histe1->Draw("Error");
             }
           }
     c1->Update();

    //======================================================================0-0000000000000                  24


     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1);
     TF1 *f1 = new TF1("f1","gaus",-0.04,0.04); Xstrip_deltaxx_clsize2->Fit("f1","RI");
      TH1F *mpelec2= (TH1F*)hfile->Get("Xstrip_deltaxx_clsize2");
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerSize(0.4);
//       mpelec2->GetYaxis()->SetLabelSize(0.04);
       mpelec2->SetMarkerColor(kBlue);
        mpelec2->GetYaxis()->SetTitle(" ");
       mpelec2->SetLineColor(3);
			mpelec2->GetYaxis()->SetTitleSize(0.06);
			mpelec2->GetXaxis()->SetTitleSize(0.06);
			mpelec2->GetXaxis()->SetTitle("#Delta [Xsim-Xrec], size2, [mm]");
			mpelec2->Draw();
			mpelec2->Draw("ErrorSame");
			   mpelec2->SetFillColor(33);



     c1->cd(2); 
     TF1 *f1 = new TF1("f1","gaus",-0.04,0.04); Ystrip_deltayy_clsize2->Fit("f1","RI");
      TH1F *mpelec4= (TH1F*)hfile->Get("Ystrip_deltayy_clsize2");
       mpelec4->SetMarkerStyle(20);
       mpelec4->SetMarkerSize(0.4);
//       mpelec4->GetYaxis()->SetLabelSize(0.04);
       mpelec4->SetMarkerColor(kBlue);
        mpelec4->GetYaxis()->SetTitle(" ");
       mpelec4->SetLineColor(3);
			mpelec4->GetYaxis()->SetTitleSize(0.06);
			mpelec4->GetXaxis()->SetTitleSize(0.06);
			mpelec4->GetXaxis()->SetTitle("#Delta [Ysim-Yrec], size2, [mm]");
			mpelec4->Draw();
			mpelec4->Draw("ErrorSame");
			   mpelec4->SetFillColor(33);


     c1->cd(3);
     TF1 *f1 = new TF1("f1","gaus",-0.05,0.05); Xstrip_deltaxx_clsize3->Fit("f1","RI");
      TH1F *mpelec2= (TH1F*)hfile->Get("Xstrip_deltaxx_clsize3");
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerSize(0.4);
//       mpelec2->GetYaxis()->SetLabelSize(0.04);
       mpelec2->SetMarkerColor(kBlue);
        mpelec2->GetYaxis()->SetTitle(" ");
       mpelec2->SetLineColor(3);
			mpelec2->GetYaxis()->SetTitleSize(0.06);
			mpelec2->GetXaxis()->SetTitleSize(0.06);
			mpelec2->GetXaxis()->SetTitle("#Delta [Xsim-Xrec], size3, [mm]");
			mpelec2->Draw();
			mpelec2->Draw("ErrorSame");
			   mpelec2->SetFillColor(33);



     c1->cd(4); 
     TF1 *f1 = new TF1("f1","gaus",-0.04,0.04); Ystrip_deltayy_clsize3->Fit("f1","RI");
      TH1F *mpelec4= (TH1F*)hfile->Get("Ystrip_deltayy_clsize3");
       mpelec4->SetMarkerStyle(20);
       mpelec4->SetMarkerSize(0.4);
//       mpelec4->GetYaxis()->SetLabelSize(0.04);
       mpelec4->SetMarkerColor(kBlue);
        mpelec4->GetYaxis()->SetTitle(" ");
       mpelec4->SetLineColor(3);
			mpelec4->GetYaxis()->SetTitleSize(0.06);
			mpelec4->GetXaxis()->SetTitleSize(0.06);
			mpelec4->GetXaxis()->SetTitle("#Delta [Ysim-Yrec], size3, [mm]");
			mpelec4->Draw();
			mpelec4->Draw("ErrorSame");
			   mpelec4->SetFillColor(33);


     c1->Update();
    //======================================================================0-0000000000000                            25
    //================
     c1->Clear();

     c1->Divide(1,2);

     c1_1->Divide(1,1);
          c1_1->cd(1);
      TH1F *mpelec1 = (TH1F*)hfile->Get("clnum0X");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.6);
       mpelec1->GetXaxis()->SetTitle("Num Cl All X");
       mpelec1->GetYaxis()->SetTitle(" ");
       //mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       //gPad->SetLogy();
       //mpelec1->Draw("Error");
       mpelec1->Draw();
	      mpelec1->Draw("ErrorSame");



       c1_2->Divide(3,1);


     c1_2->cd(1);

      TH1F *mpelec2= (TH1F*)hfile->Get("clnum1X");
        gPad->SetLogy();
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerColor(4);
       mpelec2->SetMarkerSize(0.6);
       mpelec2->GetXaxis()->SetTitle("Num Cl 1st St X");
       mpelec2->GetYaxis()->SetTitle(" ");
       //       mpelec2->SetMinimum(0.);
       //mpelec2->SetMaximum(20.);
       mpelec2->SetLineColor(3);
       //       mpelec2->Draw("Error");
       mpelec2->GetXaxis()->SetTitleSize(0.06);
       mpelec2->Draw();
       mpelec2->Draw("ErrorSame");
    //  TH1F *mpel1   = (TH1F*)hfile->Get("clnum1Xinside");
//	      mpel1->Draw("Same");



     c1_2->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnum2X");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.6);
       mpelec1->GetXaxis()->SetTitle("Num Cl 2nd St X");
       mpelec1->GetYaxis()->SetTitle(" ");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       //       mpelec1->Draw("Error");
       mpelec1->GetXaxis()->SetTitleSize(0.06);
       mpelec1->Draw();
       mpelec1->Draw("ErrorSame");
    //  TH1F *mpel3   = (TH1F*)hfile->Get("clnum2Xinside");
//	      mpel3->Draw("Same");

     c1_2->cd(3);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnum3X");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.6);
       mpelec1->GetXaxis()->SetTitle("Num Cl 3rd St X");
       mpelec1->GetYaxis()->SetTitle(" ");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       //       mpelec1->Draw("Error");
       mpelec1->GetXaxis()->SetTitleSize(0.06);
       mpelec1->Draw();
       mpelec1->Draw("ErrorSame");

       c1->Update();

    //======================================================================0-0000000000000                             26
    //================
     c1->Clear();

     c1->Divide(1,2);

     c1_1->Divide(1,1);
          c1_1->cd(1);
      TH1F *mpelec1 = (TH1F*)hfile->Get("clnum0Y");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.6);
       mpelec1->GetXaxis()->SetTitle("Num Cl All Y");
       mpelec1->GetYaxis()->SetTitle(" ");
       //mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       //gPad->SetLogy();
       //mpelec1->Draw("Error");
       mpelec1->Draw();
	      mpelec1->Draw("ErrorSame");




       c1_2->Divide(3,1);


     c1_2->cd(1);

      TH1F *mpelec2= (TH1F*)hfile->Get("clnum1Y");
        gPad->SetLogy();
       mpelec2->SetMarkerStyle(20);
       mpelec2->SetMarkerColor(4);
       mpelec2->SetMarkerSize(0.6);
       mpelec2->GetXaxis()->SetTitle("Num Cl 1st St Y");
       mpelec2->GetYaxis()->SetTitle(" ");
       //       mpelec2->SetMinimum(0.);
       //mpelec2->SetMaximum(20.);
       mpelec2->SetLineColor(3);
       //       mpelec2->Draw("Error");
       mpelec2->GetXaxis()->SetTitleSize(0.06);
       mpelec2->Draw();
       mpelec2->Draw("ErrorSame");


     c1_2->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnum2Y");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.6);
       mpelec1->GetXaxis()->SetTitle("Num Cl 2nd St Y");
       mpelec1->GetYaxis()->SetTitle(" ");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       //       mpelec1->Draw("Error");
       mpelec1->GetXaxis()->SetTitleSize(0.06);
       mpelec1->Draw();
       mpelec1->Draw("ErrorSame");

     c1_2->cd(3);
      TH1F *mpelec1= (TH1F*)hfile->Get("clnum3Y");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.6);
       mpelec1->GetXaxis()->SetTitle("Num Cl 3rd St Y");
       mpelec1->GetYaxis()->SetTitle(" ");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       //       mpelec1->Draw("Error");
       mpelec1->GetXaxis()->SetTitleSize(0.06);
       mpelec1->Draw();
       mpelec1->Draw("ErrorSame");

       c1->Update();

    //============================================================================================================27
    //================
     c1->Clear();
     c1->Divide(2,4);
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
     TF1 *f1 = new TF1("f1","gaus",-0.20,0.20); dXinVtxTrack->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("dXinVtxTrack");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta X, 1st track, mm");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(6); 
     TF1 *f1 = new TF1("f1","gaus",-0.20,0.20); dYinVtxTrack->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("dYinVtxTrack");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta Y, 1st track, mm");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");
      //                                                    mintheta    dthetax
     c1->cd(7); 
     TF1 *f1 = new TF1("f1","gaus",-25.,25.); dthetax->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetax");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(8); 
     TF1 *f1 = new TF1("f1","gaus",-25.,25.); dthetay->Fit("f1","RI");
      TH1F *mpelec3= (TH1F*)hfile->Get("dthetay");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaY, 1st track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");



      c1->Update();
     //================
    //======================================================================                                         28

     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");
    //======================================================================0-0000000000000   fit
     TF1 *f1 = new TF1("f1","gaus",-25.,25.); dthetay->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-25.,25.); dthetay3->Fit("f1","RI");

     TF1 *f1 = new TF1("f1","gaus",-25.,25.); dthetax->Fit("f1","RI");
     TF1 *f1 = new TF1("f1","gaus",-25.,25.); dthetax3->Fit("f1","RI");

    //======================================================================0-0000000000000   fit


      TH1F *mpelec7= (TH1F*)hfile->Get("dthetax");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta #thetaX , [mkrad]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");


     c1->cd(2); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("dthetay");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta #thetaY , [mlrad]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");


     c1->cd(3); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("dthetax3");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta #thetaX 3St, [mkrad]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");


     c1->cd(4); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("dthetay3");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta #thetaY 3St, [mkrad]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");





     c1->Update();

    //======================================================================                                 29

     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("chisq3X");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("chisq3X");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");
     c1->cd(2); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");
      TH1F *mpelec7= (TH1F*)hfile->Get("chisq3Y");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("chisq3Y");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");

     c1->cd(3); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("chisqX");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("chisqX");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");
     c1->cd(4); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");
      TH1F *mpelec7= (TH1F*)hfile->Get("chisqY");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("chisqY");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->Update();

    //======================================================================                                   30

     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("dYinVtxTrack");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta Y track at Zref, [mm]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(2); 
      TH1F *mpelec7= (TH1F*)hfile->Get("d3YinVtxTrack");
     TF1 *f1 = new TF1("f1","gaus",-0.20,0.20); d3YinVtxTrack->Fit("f1","RI");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta Y track at Zref, 3St, [mm]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");





     c1->cd(3); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("dXinVtxTrack");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta X track at Zref, [mm]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");




     c1->cd(4); 
      TH1F *mpelec7= (TH1F*)hfile->Get("d3XinVtxTrack");
     TF1 *f1 = new TF1("f1","gaus",-0.20,0.20); d3XinVtxTrack->Fit("f1","RI");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta X track at Zref, 3St [mm]");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");




     c1->Update();

    //==================================================================================================== 
    //======================================================================                                   31

     c1->Clear();
     c1->Divide(2,4); 

     c1->cd(1); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("xref");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("xref");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(2); 
      TH1F *mpelec7= (TH1F*)hfile->Get("yref");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("yref");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");


     c1->cd(3); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("xref2");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("xref2");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(4); 
      TH1F *mpelec7= (TH1F*)hfile->Get("yref2");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("yref2");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");

     c1->cd(5); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("dref12");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("dref12");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(6); 
      TH1F *mpelec7= (TH1F*)hfile->Get("drefy12");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("drefy12");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");

     c1->cd(7); 
      TH1F *mpelec7= (TH1F*)hfile->Get("thetaXmrad");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("thetaXmrad");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");

     c1->cd(8); 
      TH1F *mpelec7= (TH1F*)hfile->Get("eff2tracktheta");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("eff2tracktheta");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->Update();

    //======================================================================                                   32

     c1->Clear();
     c1->Divide(2,4); 

     c1->cd(1); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Txref");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("Txref");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(2); 
      TH1F *mpelec7= (TH1F*)hfile->Get("Tyref");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("Tyref");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");


     c1->cd(3); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Txref2");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("Txref2");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(4); 
      TH1F *mpelec7= (TH1F*)hfile->Get("Tyref2");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("Tyref2");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");

     c1->cd(5); 
     //     gStyle->SetOptFit();
     //TF1 *f1 = new TF1("f1","gaus",-0.06,0.06); Xstrip_deltaxx_clsize2->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Tdref12");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("Tdref12");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");



     c1->cd(6); 
      TH1F *mpelec7= (TH1F*)hfile->Get("Tdrefy12");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("Tdrefy12");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");

     c1->cd(7); 
      TH1F *mpelec7= (TH1F*)hfile->Get("TthetaXmrad");
      mpelec7->GetXaxis()->SetLabelSize(0.06);
      mpelec7->GetYaxis()->SetLabelSize(0.06);
      //mpelec7->SetMarkerColor(kYellow);
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("TthetaXmrad");
       mpelec7->Draw();
       //mpelec7->Draw("ErrorSame");




     c1->Update();

    //====================================================================================================== 33
    //================
     c1->Clear();
     c1->Divide(2,2);
     // getchar();

     c1->cd(1); 
      TH1F *mpelec3= (TH1F*)hfile->Get("nhitplanesX");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("nhitplanesX");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(2); 
      TH1F *mpelec3= (TH1F*)hfile->Get("chisqX");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->GetXaxis()->SetLabelSize(1.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("chisqX");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec3= (TH1F*)hfile->Get("nhitplanesY");
      //   gPad->SetLogy();
       mpelec->SetMarkerColor(4);
      mpelec3->SetMarkerStyle(20);
      mpelec3->SetMarkerSize(0.8);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("nhitplanesY");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->cd(4); 
      TH1F *mpelec3= (TH1F*)hfile->Get("chisqY");
      //  gPad->SetLogy();
      mpelec3->SetMarkerStyle(20);
      // mpelec3->SetMarkerSize(0.4);
      //  mpelec3->GetYaxis()->SetLabelSize(0.04);
      mpelec3->GetXaxis()->SetLabelSize(1.04);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("chisqY");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");


      c1->Update();
     //================
    //====================================================================================================           34
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
      mpelec3->GetXaxis()->SetLabelSize(1.04);
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
    //==================================================================================================== 35
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
      mpelec3->GetXaxis()->SetLabelSize(4.);
      mpelec3->GetYaxis()->SetLabelSize(4.);
      mpelec3->SetMarkerColor(kBlue);
      mpelec3->GetXaxis()->SetTitle("#Delta #thetaX, 2nd track, [#murad]");
      mpelec3->SetLineColor(3);
      mpelec3->Draw("");
      mpelec3->Draw("ErrorSame");

     c1->Update();
    //================
    //==============================================================================================        36
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
    //====================================================================================================  37
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 


     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Xstrip_deltaxx_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Xsim-Xrec], [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");

     c1->cd(2); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Xstrip_deltaxxW_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->SetFillColor(33);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Xsim-Xrec]W, [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");

     c1->cd(3); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Ystrip_deltayy_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Ysim-Yrec], [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");



     c1->cd(4); 
     //     gStyle->SetOptFit();
     //1 *f1 = new TF1("f1","gaus",-0.15,0.15); Xstrip_deltaxx_clsize1->Fit("f1","RI");


      TH1F *mpelec7= (TH1F*)hfile->Get("Ystrip_deltayyW_clsize1");
       mpelec7->SetMarkerStyle(20);
       mpelec7->SetMarkerSize(0.8);
       mpelec7->GetYaxis()->SetLabelSize(0.04);
       mpelec7->SetMarkerColor(kBlue);
//        mpelec7->GetXaxis()->SetTitle("Ecra");
//        mpelec7->GetYaxis()->SetTitle("Nev");
       mpelec7->SetLineColor(2);
//       mpelec7->Draw("Error");
       mpelec7->SetFillColor(33);
       mpelec7->GetYaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitleSize(0.06);
       mpelec7->GetXaxis()->SetTitle("#Delta [Ysim-Yrec]W, [mm]");
       mpelec7->Draw();
       mpelec7->Draw("ErrorSame");


     c1->Update();
    //==================================================================================================== 
    //======================================================================
    // close and delete all possible things:

   psfile->Close();

    hfile->Close();
    hfile->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}
