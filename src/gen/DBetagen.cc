#include <CLHEP/Units/PhysicalConstants.h>
#include <CLHEP/Random/RandFlat.h>
#include <CLHEP/Random/RandGeneral.h>
#include <CLHEP/Vector/ThreeVector.h>

#include <RAT/DBetagenMessenger.hh>
#include <RAT/DBetagen.hh>
#include <RAT/DB.hh>
#include <fstream>
#include <iostream>

// #include "TGraph.h"
// #include "TGraph2D.h"
// #include "TFile.h"
#include "TMath.h"

// using namespace CLHEP;
// using namespace std;

namespace RAT {

//#define DEBUG

// Additional constants
const double DELTA = neutron_mass_c2 - proton_mass_c2;
int mass_number=136;        
int atomic_number=54; 

//We start with the Reactor Isotope components given in Marc Bergevin's original
//IBDgenerator file

// const double ReacIBDgen::U235DEFAULT = 0.496;
// const double ReacIBDgen::U238DEFAULT = 0.087;
// const double ReacIBDgen::Pu239DEFAULT = 0.391;
// const double ReacIBDgen::Pu241DEFAULT = 0.066;
// const double DBetagen::Xe136DEFAULT = 1.000;
 
DBetagen::DBetagen()
{
  //initialize your initial isotope values.
  Reset();
  Isotope = "Xe136";
  Is0nbb = true; 

  // Get parameters from database
  // DBLinkPtr libd = DB::Get()->GetLink("IBD");
  DBLinkPtr ldbeta = DB::Get()->GetLink("DBETA");

  //initialize the messenger to adjust isotope parameters in mac files
  messenger = new DBetagenMessenger(this);


  // endpoint, his2D, g1D, gAngle
  // endpoint = 1.0;
  endpoint = getEndpoint(136, 54);

  // g2D = new TGraph2D();
  // g2D->SetName("g2D");
  // fillEnergy2D(false, "Xe136", g2D);
  set2DEnergyFunction(Is0nbb, Isotope); 

  // g1D = new TGraph();
  // g1D->SetName("g1D");
  // fillEnergy(false, true, "Xe136", g1D); 
  setEnergyFunction(Is0nbb, Isotope); 

  // gAngle = new TGraph();
  // gAngle->SetName("gAngle");
  // fillAngle(true, "Xe136", gAngle);
  setAngleFunction(Is0nbb, Isotope);
}

DBetagen::~DBetagen()
{
  //If there's no messenger adjustments, delete the messenger pointer.
  if ( messenger != 0 )
    {
      delete messenger;
      messenger = 0;
    }
    // delete g2D;
    // delete g1D;
    // delete gAngle;
}



// void DBetagen::GenEvent(bool is0NuBB, const Hep3Vector &fixed_e1_dir, HepLorentzVector &electron1, HepLorentzVector &electron2)
void DBetagen::GenEvent(const Hep3Vector &fixed_e1_dir, HepLorentzVector &electron1, HepLorentzVector &electron2)
{
  bool is0NuBB = Is0nbb;
  // TH2F* his2D;
  double e1, e2;
  // double esum;
  double r1, r2, r3; // These are the energies.
  double r1s; //these are the norm.
  double a1, a2, phi; //relative angles.
  // Double_t rphi, rtheta, rpsi; //final rotation.
  // Double_t diff;
  Bool_t isFixed = true;
  if (fixed_e1_dir.x()==0 && fixed_e1_dir.y()==0 && fixed_e1_dir.y()==0) isFixed = false;

  // determine E1 & E2
  if(!is0NuBB){  //for 2NuBB we use the 2D input data: draw E1 and E2 together, reject with box method, input data is stored in TGraph2D or TH2F
    bool doneE = false;
    while(!doneE){
      r1 = HepUniformRand()*endpoint;
      r2 = HepUniformRand()*endpoint;
      r3 = HepUniformRand(); // differential probabilities in TGraph2D have been normalized to 1 at the maximum 
      // if(his2D->Interpolate(r1,r2) >= r3){ //Using the TH2F to interpolate is faster
      // if(g2D->Interpolate(r1,r2) >= r3) {
      if(eval2DEnergyFunction(r1, r2) >= r3){
        e1 = r1;
        e2 = r2;
        // esum = e1+e2;
        doneE = true;
      }
    }
  }
  if(is0NuBB){  // 0nuBB decay: use single electron spectrum to draw e1
    bool doneE = false;
    while(!doneE){
      r1 = HepUniformRand()*endpoint;
      r2 = HepUniformRand();
      // if(g1D->Eval(r1) >= r2){
      if(evalEnergyFunction(r1) >= r2){
        doneE = true;
      }
    }
    //Is this overly simple, new physics?
    r1s = endpoint - r1;
    // Kinematics. (gives distorted sum spectrum). 
    e1 = r1;
    // esum = r1s+r1;
    e2 = r1s;
    doneE = true;
  }

  // determine angle 
  Hep3Vector momentum_dir1(0, 0, 1); //define z
  //Now get the correlation.
  // double corrA = gAngle->Eval(e1);
  double corrA = evalAngleFunction(Is0nbb, e1);
  // double corrA = gAngle_0 * pow( (gAngle_1+e1)*(endpoint+gAngle_1-e1), gAngle_2) + gAngle_3;
  double funcA = 0;
  bool doneA=false;
  while(!doneA){
    a1 = 2.0*HepUniformRand()-1.0; //cos_theta from -1 to 1.
    funcA = corrA*a1;
    a2 = HepUniformRand()*2.0-1.0;
    if(funcA >= a2){
      doneA=true;
    }
  }
  //Next: Draw random orientation in (x,y) plane
  phi = HepUniformRand()*2*TMath::Pi();
  Hep3Vector momentum_dir2(sqrt(1-a1*a1)*TMath::Cos(phi),sqrt(1-a1*a1)*TMath::Sin(phi),a1);
  if (!isFixed) {
    //now we find a random direction for the first electron
    double phi2 = HepUniformRand()*2.0*TMath::Pi();
    double theta2 = TMath::ACos(2.0*HepUniformRand() - 1.0);
    double dirx_rand = TMath::Sin(theta2)*TMath::Cos(phi2);
    double diry_rand = TMath::Sin(theta2)*TMath::Sin(phi2);
    double dirz_rand = TMath::Cos(theta2);  
    momentum_dir1.setX(dirx_rand);
    momentum_dir1.setY(diry_rand);
    momentum_dir1.setZ(dirz_rand);
  } else {
    momentum_dir1.setX(fixed_e1_dir.x());
    momentum_dir1.setY(fixed_e1_dir.y());
    momentum_dir1.setZ(fixed_e1_dir.z());
  }

  //find the vector (cross product) and angle (scalar product) to rotate (0,0,1) into the new random vector momentum_dir
  Hep3Vector z_dir(0.,0.,1.);
  Hep3Vector rot_axis = z_dir.cross(momentum_dir1);    
  double rot_axis_norm = sqrt(rot_axis.x()*rot_axis.x() + rot_axis.y()*rot_axis.y() + rot_axis.z()*rot_axis.z());
  rot_axis = rot_axis * 1./rot_axis_norm ;
  double rot_angle = TMath::ACos(z_dir.dot(momentum_dir1));
  //Finally, apply the same rotation to momentum_dir2
  momentum_dir2.rotate(rot_angle, rot_axis);

  // calculate the 3-momentum 
  double melec = electron_mass_c2;
  e1 += melec;
  e2 += melec;
  // double p1=sqrt(e1*e1 - melec*melec) * 1e-3;
  double p1=sqrt(e1*e1 - melec*melec);  //MeV
  // double p2=sqrt(e2*e2 - melec*melec) * 1e-3;
  double p2=sqrt(e2*e2 - melec*melec); //MeV

  // final result
  electron1.setVect(momentum_dir1 * p1);
  electron1.setE(p1);
  electron2.setVect(momentum_dir2 * p2);
  electron2.setE(p2);

}

double DBetagen::getEndpoint(int A, int Z)
{
  double end_point = 0.0;
  //Values from J. Kotila and F. Iachello paper: PHYSICAL REVIEW C 85, 034316 (2012)
  if(A==160 && Z==64) end_point=1.72969; //160Gd, we didn't get the differential probability file for this isotope which is needed for 2NuBB. 
  else if(A==116 && Z==48) end_point=2.81350; //116Cd, value from COBRA: 2.809
  else if(A==128 && Z==52) end_point=0.86587; //128Te
  else if(A==130 && Z==52) end_point=2.52697; //130Te
  else if(A==136 && Z==54) end_point=2.45783; //136Xe
  // more isotopes added by AE (Q values are from TIPP2014 talk table):
  else if(A==48 && Z==20) end_point=4.271; //48Ca
  else if(A==82 && Z==34) end_point=2.995; //82Se
  else if(A==100 && Z==42) end_point=3.034; //100Mo
  else if(A==150 && Z==60) end_point=3.367; //150Nd
  
  else cout << "The specified isotope is not supported. Have a look at the function getEndpoint(A,Z) for a list of supported isotopes." << endl; 
  // return endpoint;
  end_point = end_point;
  return end_point;
}

string DBetagen::getIsotope()
{
  return Isotope;
}
void DBetagen::setIsotope(string s)
{
  Isotope = s;
}

bool DBetagen::if0Nubb()
{
  return Is0nbb;
}
void DBetagen::set0Nubb(bool b)
{
  Is0nbb = b;
}


/*void DBetagen::fillEnergy(bool isSum, bool is0NuBB, TString isotope, TGraph* gE)
{
  // char* datadir = getenv("DBETA_DATA");
  // char* datadir = "/usr2/collab/fuzh/RAT/DBeta-master/data";
  TString datadir = "/usr2/collab/fuzh/RAT/DBeta-master/data";
  //Open up a file - Sum First.
  ifstream infile;
  //Get the right data file;
  TString fileName=datadir;

  fileName.Append(Form("/%s",isotope.Data()));
  if(isSum){
    fileName.Append("sumssfs");
  }else{
    fileName.Append("sessfs");
  }
  if(is0NuBB)  fileName.Append("_0nuBB");
  fileName.Append(".dat");

  //Go Ahead and Open.
  infile.open(fileName.Data());
  if(!infile){
    cout << "[ERROR] Could not find energy file "<< fileName.Data() <<endl;
    return;
  }

  //These should be reset.
  int npoints=0;
  double xp=-1;
  double sum=0;
  double max=0;
  //
  int index;
  double x, dx;
  double y;
  string line;
  while (getline (infile, line)){
    istringstream linestream(line);
    linestream >> index >> x >> y;
    if(xp>0) {
      dx=x-xp;
      sum+=y*dx;
      if(y>max) max=y;
    }
    if(x>0) {
      gE->SetPoint(npoints, x, y);
      npoints++;
    }
    xp=x;
  }
  
  //Always Normalize.
  for(Int_t i=0; i<gE->GetN(); i++){
    gE->GetPoint(i, x, y);
    gE->SetPoint(i, x, y/max);
  }
  infile.close();
} */
double DBetagen::evalEnergyFunction(double ix)
{
  double x = ix * 1.0;
  double result = g1D_0 * exp(g1D_1*x*x + g1D_2*x + g1D_3) + g1D_4; //gauss function
  return result;
}
void DBetagen::setEnergyFunction(bool is0NuBB, string isotope)
{
  if(isotope == "Xe136") {
    g1D_0 = 0.787096;
    g1D_1 = -0.389711;
    g1D_2 = 0.957875;
    g1D_3 = 0.14555;
    g1D_4 = -0.638598;
  } else if(isotope == "Te130") {
    g1D_0 = 0.785276;
    g1D_1 = -0.378253;
    g1D_2 = 0.955845;
    g1D_3 = 0.132101;
    g1D_4 = -0.637707;
  } else if(isotope == "Te128") {
    g1D_0 = 0.639226;
    g1D_1 = -2.02047;
    g1D_2 = 1.74968;
    g1D_3 = 0.176759;
    g1D_4 = -0.113436;
  } else if(isotope == "Cd116") {
    g1D_0 = 0.759901;
    g1D_1 = -0.329597;
    g1D_2 = 0.927318;
    g1D_3 = 0.114181;
    g1D_4 = -0.633704;
  } else {
    cout << "[ERROR] Could not find input isotope "<<endl;
    return;
  }
}


/*void DBetagen::fillEnergy2D(bool is0NuBB, TString isotope, TGraph2D* gE)
{
  // char* datadir = getenv("DBETA_DATA");
  // char* datadir = "/usr2/collab/fuzh/RAT/DBeta-master/data";
  TString datadir = "/usr2/collab/fuzh/RAT/DBeta-master/data";

  //Open up a file - Sum First.
  ifstream infile;

  //Get the right data file; for example 116cdtwodimspectsfs.dat
  TString fileName=datadir;
  fileName.Append("/2D_differential_probabilities");
  fileName.Append(Form("/%s",isotope.Data()));
  fileName.Append("twodimspectsfs");
  if(is0NuBB)  fileName.Append("_0nuBB");
  fileName.Append(".dat");

  //Go Ahead and Open.
  infile.open(fileName.Data());
  if(!infile){
    cout << "[ERROR] Could not find the 2D differential probability file. " << fileName.Data() <<endl;
    return;
  }

  //These should be reset.
  int npoints=0;
  double max=0;
  //
  int index1,index2;
  double x; //,dx;
  double y;
  double prob;
  string line;
  
  while (getline (infile, line)){    //get the input data from file and fill it into TGraph2D, also get max. probability, and the stepsize in both x and y directions  
    istringstream linestream(line);
    //cout << "npoints= " << npoints << endl;
    linestream >> index1 >> index2 >> x >> y >> prob;
    //cout << "index1= " << index1 << ", index2= " << index2 << ", x= " << x << ", y= " << y << ", prob= " << prob << endl;
    if(prob>max) max=prob;

    if(x>0 && y>0) {
      gE->SetPoint(npoints, x, y, prob);
      npoints++;
    }
    else {
      cout << "The input file format is not what we expect. At least one of the variables used for the electron energies is negative." << endl;
    }

  }

  //Run Interpolate command to calculate the delaunay triangles, from previous experience we know that otherwise the results can be unstable for the first Interpolate calls. For the actual interpolation we use the TH2F object now, so this step is not critical.  
  Int_t n_interpolate=10;
  Double_t x_test,y_test;
  for(Int_t jj=0;jj<n_interpolate;jj++){
    x_test = HepUniformRand()*getEndpoint(mass_number,atomic_number);
    y_test = HepUniformRand()*getEndpoint(mass_number,atomic_number); 
    if(x_test + y_test < getEndpoint(mass_number,atomic_number)) {
      gE->Interpolate(x_test,y_test);
    }
  }

  infile.close();
}*/
double DBetagen::eval2DEnergyFunction(double ix, double iy)
{
  double x = ix * 1.0; 
  double y = iy * 1.0; 
  double result = g2D_0 * exp( g2D_1*(x+y) + g2D_2*(x*x+y*y) + g2D_3*x*y + g2D_4 ) + g2D_5;  //2d gauss function
  return result;
}
void DBetagen::set2DEnergyFunction(bool is0NuBB, string isotope)
{
  if(isotope == "Xe136") {
    g2D_0 = 1.95414e-18;
    g2D_1 = 1.38104;
    g2D_2 = -1.94935;
    g2D_3 = -2.04192;
    g2D_4 = -0.565712;
    g2D_5 = -0.0111514e-18;
  } else if(isotope == "Te130") {
    g2D_0 = 1.889e-18;
    g2D_1 = 1.45115;
    g2D_2 = -1.89466;
    g2D_3 = -1.95288;
    g2D_4 = -0.586266;
    g2D_5 = -0.0108602e-18;
  } else if(isotope == "Te128") {
    g2D_0 = 6.24804e-21;
    g2D_1 = -1.78151;
    g2D_2 = -8.11522;
    g2D_3 = -11.1477;
    g2D_4 = -0.231194;
    g2D_5 = -2.25416e-23;
  } else if(isotope == "Cd116") {
    g2D_0 = 2.24784e-18;
    g2D_1 = 1.63364;
    g2D_2 = -1.67633;
    g2D_3 = -1.63308;
    g2D_4 = -0.597036;
    g2D_5 = -0.0131176e-18;
  } else {
    cout << "[ERROR] Could not find input isotope "<<endl;
    return;
  }
}

/*void DBetagen::fillAngle(bool is0NuBB, TString isotope, TGraph* gE)
{
  // char* datadir = getenv("DBETA_DATA");
  // char* datadir = "/usr2/collab/fuzh/RAT/DBeta-master/data";
  TString datadir = "/usr2/collab/fuzh/RAT/DBeta-master/data";
  
  //Open up a file - Sum First.
  ifstream infile;
  
  //Get the right data file;
  TString fileName=datadir;
  fileName.Append(Form("/%s",isotope.Data()));
  fileName.Append("correlationsfs");
  if(is0NuBB)  fileName.Append("_0nuBB");
  fileName.Append(".dat");

  //Open the file.
  infile.open(fileName.Data());
  if(!infile){
    cout << "[ERROR] Could not find angle file: " << fileName.Data() << endl;
    return;
  }

  //These should be reset.
  int npoints=0;
  double xp=-1;
  double sum=0;
  double max=0;
  //
  int index;
  double x,dx;
  double y;
  string line;
  while (getline (infile, line)){
    istringstream linestream(line);
    linestream >> index >> x >> y;
    if(xp>0) {
      dx=x-xp;
      sum+=y*dx;
      if(y>max) max=y;
    }
    if(x>0) {
      gE->SetPoint(npoints, x, y);
      npoints++;
    }
    xp=x;
  }
  infile.close();
} */
double DBetagen::evalAngleFunction(bool is0NuBB, double x)
{
  double result;
  if(is0NuBB) {
    // result = gAngle_0 * pow( (gAngle_1+x)*(endpoint+gAngle_1-x), gAngle_2) + gAngle_3; //beta function
    result = gAngle_0 * pow( (gAngle_1+x)*(endpoint+gAngle_1-x), gAngle_2) + gAngle_3; //beta function
  } else {
    result = gAngle_0 / (pow(gAngle_1+x, gAngle_2)*pow(gAngle_3-x, gAngle_4)+gAngle_5) + gAngle_6 + gAngle_7*x;
  }
  return result;
}
void DBetagen::setAngleFunction(bool is0NuBB, string isotope)
{
  if(is0NuBB) { // for function: gAngle_0 * pow( (gAngle_1+x)*(endpoint+gAngle_1-x), gAngle_2) + gAngle_3;
    gAngle_4 = 0.0;
    gAngle_5 = 0.0;
    gAngle_6 = 0.0;
    gAngle_7 = 0.0;
    if(isotope == "Xe136") {
      gAngle_0 = 0.309477;
      gAngle_1 = 0.187728;
      gAngle_2 = -1.14889;
      gAngle_3 = -1.06899;
    } else if(isotope == "Te130") {
      gAngle_0 = 0.313408;
      gAngle_1 = 0.168816;
      gAngle_2 = -1.0536;
      gAngle_3 = -1.07882;
    } else if(isotope == "Te128") {
      gAngle_0 = 0.25322;
      gAngle_1 = 0.122673;
      gAngle_2 = -0.618288;
      gAngle_3 = -1.2744;
    } else if(isotope == "Cd116") {
      gAngle_0 = 0.346706;
      gAngle_1 = 0.165979;
      gAngle_2 = -1.0715;
      gAngle_3 = -1.07167;
    } else {
      cout << "[ERROR] Could not find input isotope "<<endl;
      return;
    }
  } else {
    if(isotope == "Xe136") {  //TODO: check when E>2.43 MeV
      gAngle_0 = 17.6227;
      gAngle_1 = 0.0399988;
      gAngle_2 = 0.126972;
      gAngle_3 = 37.3501;
      gAngle_4 = 0.874487;
      gAngle_5 = -27.8038;
      gAngle_6 = 1.14617;
      gAngle_7 = 2.02267;
    } else if(isotope == "Te130") {
      gAngle_0 = 10.0125;
      gAngle_1 = 0.0313491;
      gAngle_2 = 0.121018;
      gAngle_3 = 34.1294;
      gAngle_4 = 0.764834;
      gAngle_5 = -17.2953;
      gAngle_6 = 1.03642;
      gAngle_7 = 1.95569;
    } else if(isotope == "Te128") {
      gAngle_0 = 237.109;
      gAngle_1 = 0.0292886;
      gAngle_2 = 0.267828;
      gAngle_3 = 7.27878;
      gAngle_4 = 1.7586;
      gAngle_5 = -96.217;
      gAngle_6 = 2.60506;
      gAngle_7 = 0.455844;
    } else if(isotope == "Cd116") {
      gAngle_0 = 13.6858;
      gAngle_1 = 0.0249188;
      gAngle_2 = 0.118249;
      gAngle_3 = 39.6407;
      gAngle_4 = 0.82439;
      gAngle_5 = -24.191;
      gAngle_6 = 0.998046;
      gAngle_7 = 1.86647;
    } else {
      cout << "[ERROR] Could not find input isotope "<<endl;
      return;
    }
  }
}



void DBetagen::Reset()
{
  endpoint = 1.0;
  // // g2D->Clear();
  // g2D_0 = 0;
  // g2D_1 = 0;
  // g2D_2 = 0;
  // g2D_3 = 0;
  // g2D_4 = 0;
  // g2D_5 = 0;
  // // g1D->Clear();
  // g1D_0 = 0;
  // g1D_1 = 0;
  // g1D_2 = 0;
  // g1D_3 = 0;
  // // gAngle->Clear(); 
  // gAngle_0 = 0;
  // gAngle_1 = 0;
  // gAngle_2 = 0;
  // gAngle_3 = 0;
  set2DEnergyFunction(true, "Xe136"); 
  setEnergyFunction(true, "Xe136"); 
  setAngleFunction(true, "Xe136");
}



} // namespace RAT
