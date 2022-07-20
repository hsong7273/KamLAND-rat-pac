#ifndef __RAT_VertexGen_DBeta__
#define __RAT_VertexGen_DBeta__

#include <RAT/GLG4VertexGen.hh>
#include <RAT/DBetagen.hh>

/** vertex generator that can generate the products of a inverse
    beta-decay reaction from a reactor anti-neutrino.  The direction
    of the neutrino is supplied, and the energy and angle of the
    produced positron and neutron are drawn from the distribution
    produced by the differential cross-section and a reactor anti-neutrino
    energy spectrum.
*/

namespace RAT {

class VertexGen_DBeta : public GLG4VertexGen {
public:
  VertexGen_DBeta(const char *arg_dbname="dbeta");
  virtual ~VertexGen_DBeta();
  virtual void GeneratePrimaryVertex( G4Event *argEvent,
				      G4ThreeVector &dx,
				      G4double dt);
  // generates a primary vertex with given particle type, direction, energy,
  // and consistent polarization.

  virtual void SetState( G4String newValues );
  // format: dir_x dir_y dir_z
  // If dir_x==dir_y==dir_z==0, the directions are isotropic.

  virtual G4String GetState();
  // returns current state formatted as above

private:
  // G4ParticleDefinition *nu, *n, *eplus;
  G4ParticleDefinition *e1, *e2;
  // ReacIBDgen reacibd;
  DBetagen* dbeta;
  // G4ThreeVector nu_dir;
  G4ThreeVector fixed_e1_dir;
};


} // namespace RAT

#endif
