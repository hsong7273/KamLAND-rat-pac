// Rat::ReacIBDgenMessenger
// 07-June-2015 Teal Pershing

// Provide user commands that allow the user to change
// the Reactor Isotope contents via the command line.

#include <RAT/DBetagenMessenger.hh>
#include <RAT/DBetagen.hh>

#include <G4UIcommand.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithABool.hh>
#include <G4String.hh>

namespace RAT {
  DBetagenMessenger::DBetagenMessenger(DBetagen* re) :
    dbetagen(re)
  {
    // Commands will be called in the mac with /generator/reacibd/
    G4UIdirectory* dir = new G4UIdirectory("/generator/dbeta/");
    dir->SetGuidance("Control the contents of the DBeta generator");

    IsotopeCmd = new G4UIcmdWithAString("/generator/dbeta/isotope", this);
    IsotopeCmd->SetGuidance("Sets the isotope for double beta decay");
    IsotopeCmd->SetParameterName("Isotope",false);
    string str = dbetagen->getIsotope();
    // char* cstr = new char[s.size() + 1];
    char* cstr = strcpy(new char[str.length() + 1], str.c_str());
    // strcpy(cstr, s.c_str());
    // IsotopeCmd->SetDefaultValue(dbetagen->getIsotope());
    IsotopeCmd->SetDefaultValue(cstr);

    Is0nbbCmd = new G4UIcmdWithABool("/generator/dbeta/is0nbb", this);
    Is0nbbCmd->SetGuidance("Sets if the double beta decay is neutrinoless");
    Is0nbbCmd->SetParameterName("Is0NBB",false);
    Is0nbbCmd->SetDefaultValue(dbetagen->if0Nubb());

  }

  DBetagenMessenger::~DBetagenMessenger() {;}

  void DBetagenMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
  {
    if ( command == IsotopeCmd )
    {
      // G4String IsotopeAmpl = IsotopeCmd->GetNewDoubleValue( newValue );
      G4String IsotopeAmpl = newValue;
      dbetagen->setIsotope( IsotopeAmpl );
    }
    else if ( command == Is0nbbCmd )
    {
      G4String Is0nbbAmpl = Is0nbbCmd->GetNewBoolValue( newValue );
      dbetagen->set0Nubb( Is0nbbAmpl );
    } else {
      G4cerr << "Error: Invalid DBetagenMessenger \"set\" command" << G4endl;
    }
  }

  G4String DBetagenMessenger::GetCurrentValue(G4UIcommand* command)
  {
    //Get here, you return an error.
    if ( command == IsotopeCmd ) return dbetagen->getIsotope();
    else if ( command == Is0nbbCmd ) return dbetagen->if0Nubb();
    // return G4String("Error: (Not finished yet) Invalid DBetagenMessenger \"get\" command");
    return G4String("Error: Invalid DBetagenMessenger \"get\" command");
  }

}  //namespace RAT


