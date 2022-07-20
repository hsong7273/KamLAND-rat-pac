// RAT:: ReacIBDgenMessenger
// 07-June-2015 Teal Pershing

// Provides user commands that allow the user to change
// The Reactor Isotope contents through the command line.

#ifndef RAT_DBetagenMessenger_hh
#define RAT_DBetagenMessenger_hh

#include "G4UImessenger.hh"
#include "G4String.hh"

//Forward declarations
class G4UIcommand;
class G4UIcmdWithADouble;
class G4UIcmdWithAString;
class G4UIcmdWithABool;

namespace RAT {

  //Forward declarations within RAT namespace
  class DBetagen;

  class DBetagenMessenger: public G4UImessenger
  {
  public:
    //ReacIBDgenMessenger(ReacIBDgen*);
    DBetagenMessenger(DBetagen*);
    ~DBetagenMessenger();

    void SetNewValue(G4UIcommand* command, G4String newValues);
    G4String GetCurrentValue(G4UIcommand* command);

  private:
    DBetagen* dbetagen;

    // G4UIcmdWithADouble* U235AmpCmd;
    // G4UIcmdWithADouble* U238AmpCmd;
    // G4UIcmdWithADouble* Pu239AmpCmd;
    // G4UIcmdWithADouble* Pu241AmpCmd;
    G4UIcmdWithAString* IsotopeCmd;
    G4UIcmdWithABool* Is0nbbCmd; 
  };

} // namespace RAT

#endif // RAT_ReacIBDgenMessenger_hh
