#include <RAT/GeoToroidalFactory.hh>
#include <RAT/GLG4TorusStack.hh>
// #include <G4TorusStack.hh> //no such file 
#include <CLHEP/Units/SystemOfUnits.h>

using namespace std;

namespace RAT {

G4VSolid *GeoToroidalFactory::ConstructSolid(DBLinkPtr table)
{
  // cout << "start" << endl;
  string volume_name        = table->GetIndex();

  const int &n = table->GetI("n");
  const vector<double> &z_edge = table->GetDArray("z_edge");
  const vector<double> &rho_edge = table->GetDArray("rho_edge");
  const vector<double> &z_origin = table->GetDArray("z_origin");

  assert(n+1 == (int)z_edge.size());
  assert(n+1 == (int)rho_edge.size());
  assert(n == (int)z_origin.size());

  GLG4TorusStack *torus_stk = new GLG4TorusStack(volume_name);  
  torus_stk->SetAllParameters(n, &z_edge[0], &rho_edge[0], &z_origin[0]);
  return torus_stk;

  // return new G4TorusStack(n, &z_edge[0], &rho_edge[0], &z_origin[0]);
}

} // namespace RAT
