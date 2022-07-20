#ifndef __RAT_DBetagen__
#define __RAT_DBetagen__

#include <RAT/LinearInterp.hh>
#include <CLHEP/Random/Randomize.h>
#include <G4ThreeVector.hh>
#include <G4LorentzVector.hh>

// #include "TGraph.h"
// #include "TGraph2D.h"

using namespace CLHEP;
using namespace std;

namespace RAT {

//Initialize class for adding messages to mac files to adjust isotope params
class DBetagenMessenger;

// Generate inverse beta decay event
class DBetagen {
public:
  DBetagen();
  ~DBetagen();
  
  //Resets parameters to all default values
  void Reset(); 

  // Initialization of messenger object that lets user change parameters in mac files.
  DBetagenMessenger* messenger;

  // // Generate random event vectors
  // //    Pass in the neutrino direction (unit vector)
  // //    Returns 4-momentum vectors for neutrino and resulting positron
  // //    and neutron.  Neutrino energy and positron direction drawn from
  // //    GenInteraction() distribution.
  // void GenEvent(const G4ThreeVector &nu_dir,
		// G4LorentzVector &neutrino,
		// G4LorentzVector &positron,
		// G4LorentzVector &neutron);
  // void GenEvent(bool is0NuBB, const G4ThreeVector &fixed_e1_dir, G4LorentzVector &electron1, G4LorentzVector &electron2);  
   void GenEvent(const G4ThreeVector &fixed_e1_dir, G4LorentzVector &electron1, G4LorentzVector &electron2);  

  double getEndpoint(int A, int Z);
  string getIsotope();
  void setIsotope(string s);
  bool if0Nubb();
  void set0Nubb(bool b);
  // void fillEnergy(bool isSum, bool is0NuBB, TString isotope, TGraph* gE);
  double evalEnergyFunction(double ix);
  void setEnergyFunction(bool is0NuBB, string isotope);

  // void fillEnergy2D(bool is0NuBB, TString isotope, TGraph2D* gE);
  double eval2DEnergyFunction(double ix, double iy);
  void set2DEnergyFunction(bool is0NuBB, string isotope);

  // void fillAngle(bool is0NuBB, TString isotope, TGraph* gE);
  double evalAngleFunction(bool is0NuBB, double x);
  void setAngleFunction(bool is0NuBB, string isotope);

  // // Generate random inverse beta decay interaction
  // //
  // //   Selects neutrino energy and cos(theta) of the produced
  // //   positron relative to neutrino direction.  They are pulled
  // //   from 2D distribution of reactor neutrinos which have interacted
  // //   with a proton, so both the incident flux, and the (relative) 
  // //   differential cross-section are factored in.
  // void GenInteraction(float &E, float &CosThetaLab);
  
  // // void SetU235Amplitude (double U235Am = U235DEFAULT);
  // // void SetU238Amplitude (double U238Am = U238DEFAULT);
  // // void SetPu239Amplitude (double Pu239Am = Pu239DEFAULT);
  // // void SetPu241Amplitude (double Pu241Am = Pu241DEFAULT); 
  // void SetXe136Amplitude (double Xe136Am = Xe136DEFAULT);

  // // Total cross section for inverse beta decay
  // static double CrossSection(float x);


  // // inline double GetU235Amplitude()   {return U235Amp;} ;
  // // inline double GetU238Amplitude()   {return U238Amp;} ;
  // // inline double GetPu239Amplitude()  {return Pu239Amp;} ;
  // // inline double GetPu241Amplitude()  {return Pu241Amp;} ;
  // inline double GetXe136Amplitude()   {return Xe136Amp;} ;

  // //Creates a probability density spectrum using the sum of the different
  // //reactor neutrino probability density spectrums as a function of energy.
  // //The function returns a random energy from the PDF based on the weighted
  // //probabilities.  This function uses the same method as the CfSource file
  // //to produce a random generator based on a probability density function.
  // float GetNuEnergy();

  // //Probability density functions of reactor neutrinos as a function of 
  // //energy.  Parametrization of fluxes for neutrinos from each reactor
  // //core isotope from "Determination of the Neutrino Mass Hierarchy at
  // //Intermediate Baseline", arxiv:0807.3203v2

  // //FIXME: Make the leading coefficients of these spectrums adjustable in
  // //the macro file that will call this generator.
  // // float U235ReacSpectrum(const float& x);
  // // float Pu239ReacSpectrum(const float& x);
  // // float U238ReacSpectrum(const float& x);
  // // float Pu241ReacSpectrum(const float& x);
  // float Xe136ReacSpectrum(const float& x);

  // //Sum of the reactor spectrums defined above.  the x value in this case is
  // //the energy of the neutrino, and the function would return the value of the
  // //PDF at that energy.
  // float NuReacSpectrum(const float& x);

  // //IBDEnergy which is a product of the above spectrums, the cross-section, and a
  // //square root factor with the cross section and electron mass.
  // double DBETASpectrum(float x);

protected:
  // double Emax;
  // double Emin;

  // double U238Amp;
  // double U235Amp;
  // double Pu239Amp;
  // double Pu241Amp;
  // double Xe136Amp;

  // static const double U235DEFAULT;
  // static const double U238DEFAULT;
  // static const double Pu239DEFAULT;
  // static const double Pu241FAULT;
  // static const double Xe136DEFAU;

  string Isotope;
  bool Is0nbb;

  double endpoint;
  // TGraph2D* g2D;
  double g2D_0;
  double g2D_1;
  double g2D_2;
  double g2D_3;
  double g2D_4;
  double g2D_5;
  // TGraph* g1D;
  double g1D_0;
  double g1D_1;
  double g1D_2;
  double g1D_3;
  double g1D_4;

  // TGraph* gAngle; 
  double gAngle_0;
  double gAngle_1;
  double gAngle_2;
  double gAngle_3;
  double gAngle_4;
  double gAngle_5;
  double gAngle_6;
  double gAngle_7;
};


} // namespace RAT

#endif
