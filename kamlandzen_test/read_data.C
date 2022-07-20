/**
 * Example script for drawing MCPhoton information from RAT-PAC ROOT files.
 *
 * Usage:
 *
 *     root[0] .L mcphoton.cpp+
 *     root[1] plotMCData("myfile.root");
 *
 * A. Mastbaum <mastbaum@hep.upenn.edu>, June 2015
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <TH1F.h>
#include <TCanvas.h>
// #include <RAT/DSReader.hh>
// #include <RAT/DS/Root.hh>
// #include <RAT/DS/MC.hh>
// #include <RAT/DS/MCPMT.hh>

// void plotMCData(const char* filename) {
void read_data() {
  const char* filename = "output.root";
  ofstream myfile;
  myfile.open("pmt_ids.txt");

  // Canvases and histograms
  // TCanvas* c1 = new TCanvas();
  // TH1F* htimes = new TH1F("htimes", ";Time (ns);Counts", 250, 20, 90);
  // TCanvas* c2 = new TCanvas();
  // TH1F* hlambda = new TH1F("hlambda", ";Wavelength (nm);Counts", 500, 100, 800);

  // Set up RAT ROOT file reader
  RAT::DSReader dsReader(filename);
  RAT::DS::Root* ds;

  // Loop over DS events in the file
  int event_id = 0;
  while (ds = dsReader.NextEvent()) {
    // Get the MC data and loop over MCPMTs
    myfile << event_id << ": ";
    RAT::DS::MC* mc = ds->GetMC();
    for (size_t ipmt=0; ipmt<mc->GetMCPMTCount(); ipmt++) {
      // Get the MCPMT and loop over MCPhotons
      RAT::DS::MCPMT* pmt = mc->GetMCPMT(ipmt);
      myfile << pmt->GetID() << ", ";
      // for (size_t iphoton=0; iphoton<pmt->GetMCPhotonCount(); iphoton++) {
      //   // Get the MCPhoton and extract information
      //   RAT::DS::MCPhoton* photon = pmt->GetMCPhoton(iphoton);
      //   float lambda = photon->GetLambda() * 1e6;  // mm -> nm
      //   float time = photon->GetHitTime();
      //   std::cout << lambda << " " << time << std::endl;

      //   // Fill the histograms (for real hits)
      //   if (!photon->IsDarkHit()) {
      //     htimes->Fill(time);
      //     hlambda->Fill(lambda);
      //   }
      // }
    }
    event_id++;
    myfile << endl;
  }
  myfile.close();

  // // Draw
  // c1->cd();
  // htimes->Draw();
  // c1->Update();

  // c2->cd();
  // hlambda->Draw();
  // c2->Update();
}
