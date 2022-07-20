#include <globals.hh>
#include <G4ParticleDefinition.hh>
#include <Randomize.hh>
#include <G4ParticleTable.hh>
#include <G4ThreeVector.hh>
#include <G4LorentzVector.hh>
#include <G4PrimaryVertex.hh>
#include <G4PrimaryParticle.hh>
#include <G4Event.hh>

#include <RAT/GLG4PosGen.hh>
#include <sstream>
#include <RAT/VertexGen_DBeta.hh>
#include <RAT/DBetagen.hh>
#include <RAT/GLG4StringUtil.hh>

namespace RAT {

  
VertexGen_DBeta::VertexGen_DBeta(const char *arg_dbname)
  : GLG4VertexGen(arg_dbname), fixed_e1_dir(0.,0.,0.)
{
  // nu = G4ParticleTable::GetParticleTable()->FindParticle("anti_nu_e");  
  // eplus = G4ParticleTable::GetParticleTable()->FindParticle("e+");  
  // n = G4ParticleTable::GetParticleTable()->FindParticle("neutron"); 
  e1 = G4ParticleTable::GetParticleTable()->FindParticle("e-"); 
  e2 = G4ParticleTable::GetParticleTable()->FindParticle("e-"); 
  dbeta = new DBetagen(); 
}

VertexGen_DBeta::~VertexGen_DBeta()
{
  
}

void VertexGen_DBeta::GeneratePrimaryVertex(G4Event *argEvent, G4ThreeVector &dx, G4double dt)
{
  G4PrimaryVertex* vertex= new G4PrimaryVertex(dx, dt);
  // G4ThreeVector ev_nu_dir(nu_dir); // By default use specified direction
  G4ThreeVector ev_fixed_e1_dir(fixed_e1_dir); // By default use specified direction
  
  // if (ev_nu_dir.mag2() == 0.0) {
  //   // Pick isotropic direction for incoming neutrino
  //   double theta = acos(2.0 * G4UniformRand() - 1.0);
  //   double phi = 2.0 * G4UniformRand() * CLHEP::pi;
  //   ev_nu_dir.setRThetaPhi(1.0, theta, phi);
  // }
  if (ev_fixed_e1_dir.mag2() == 0.0) {
    // Pick isotropic direction for incoming neutrino
    double theta = acos(2.0 * G4UniformRand() - 1.0);
    double phi = 2.0 * G4UniformRand() * CLHEP::pi;
    ev_fixed_e1_dir.setRThetaPhi(1.0, theta, phi);
  }

  // -- Generate inverse beta decay interaction
  // G4LorentzVector mom_nu, mom_eplus, mom_n;
  G4LorentzVector mom_e1, mom_e2;

  // reacibd.GenEvent(ev_nu_dir, mom_nu, mom_eplus, mom_n);
  dbeta->GenEvent(ev_fixed_e1_dir, mom_e1, mom_e2); 

  // -- Create particles
  
  // // positron
  // G4PrimaryParticle* eplus_particle =
  //   new G4PrimaryParticle(eplus,              // particle code
		// 	  mom_eplus.px(),     // x component of momentum
		// 	  mom_eplus.py(),     // y component of momentum
		// 	  mom_eplus.pz());    // z component of momentum
  // eplus_particle->SetMass(eplus->GetPDGMass()); // Geant4 is silly.
  // vertex->SetPrimary( eplus_particle );  

  // // neutron
  // G4PrimaryParticle* n_particle =
  //   new G4PrimaryParticle(n,                  // particle code
		// 	  mom_n.px(),         // x component of momentum
		// 	  mom_n.py(),         // y component of momentum
		// 	  mom_n.pz());        // z component of momentum
  // n_particle->SetMass(n->GetPDGMass()); // Geant4 is silly.
  // vertex->SetPrimary( n_particle );

  // electron 1
  G4PrimaryParticle* e1_particle =
    new G4PrimaryParticle(e1,              // particle code
        mom_e1.px(),     // x component of momentum
        mom_e1.py(),     // y component of momentum
        mom_e1.pz());    // z component of momentum
  e1_particle->SetMass(e1->GetPDGMass()); // Geant4 is silly.
  vertex->SetPrimary( e1_particle );  
  // electron 2
  G4PrimaryParticle* e2_particle =
    new G4PrimaryParticle(e2,              // particle code
        mom_e2.px(),     // x component of momentum
        mom_e2.py(),     // y component of momentum
        mom_e2.pz());    // z component of momentum
  e2_particle->SetMass(e2->GetPDGMass()); // Geant4 is silly.
  vertex->SetPrimary( e2_particle );  

  argEvent->AddPrimaryVertex(vertex);

}


void VertexGen_DBeta::SetState(G4String newValues)
{
  newValues = util_strip_default(newValues); // from GLG4StringUtil
  if (newValues.length() == 0) {
    // print help and current state
    // G4cout << "Current state of this VertexGen_ReacIBD:\n"
	   // << " \"" << GetState() << "\"\n" << G4endl;
    G4cout << "Current state of this VertexGen_DBeta:\n" << " \"" << GetState() << "\"\n" << G4endl;
    // G4cout << "Format of argument to VertexGen_ReacIBD::SetState: \n"
    //   " \"nu_dir_x nu_dir_y nu_dir_z\"\n"
    //   " where nu_dir is the initial direction of the reactor antineutrino.\n"
    //   " Does not have to be normalized.  Set to \"0. 0. 0.\" for isotropic\n"
    //   " neutrino direction."
	   // << G4endl;
    G4cout << "Format of argument to VertexGen_DBeta::SetState: \n"
      " \"fixed_e1_dir_x fixed_e1_dir_y fixed_e1_dir_z\"\n"
      " where fixed_e1_dir is the fixed direction of the one product electron.\n"
      " Does not have to be normalized.  Set to \"0. 0. 0.\" for isotropic direction."
     << G4endl;
    return;
  }

  std::istringstream is(newValues.c_str());
  double x, y, z;
  is >> x >> y >> z;
  if (is.fail())
    return;

  if ( x == 0. && y == 0. && z == 0. )
    // nu_dir.set(0., 0., 0.);
    fixed_e1_dir.set(0., 0., 0.);
  else
    // nu_dir = G4ThreeVector(x, y, z).unit();
    fixed_e1_dir = G4ThreeVector(x, y, z).unit();
}


G4String VertexGen_DBeta::GetState()
{
  std::ostringstream os;

  // os << nu_dir.x() << "\t" << nu_dir.y() << "\t" << nu_dir.z() << std::ends;
  os << fixed_e1_dir.x() << "\t" << fixed_e1_dir.y() << "\t" << fixed_e1_dir.z() << std::ends;

  G4String rv(os.str());
  return rv;
}


} // namespace RAT
