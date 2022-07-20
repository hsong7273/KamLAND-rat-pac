#include <algorithm>
#include <RAT/Log.hh>
#include <RAT/Materials.hh>
#include <RAT/GLG4PMTOpticalModel.hh>
#include <RAT/PMTConstruction.hh>
#include <G4Tubs.hh>
#include <G4SubtractionSolid.hh>
#include <G4Region.hh>
#include <G4VisAttributes.hh>
#include <G4LogicalBorderSurface.hh>
#include <G4LogicalSkinSurface.hh>

#include <RAT/ToroidalPMTConstruction.hh>
#include <RAT/ToroidalPMTConstructionMask.hh>
#include <RAT/RevolutionPMTConstruction.hh>

using namespace std;

namespace RAT {

PMTConstruction* PMTConstruction::NewConstruction(DBLinkPtr table, G4LogicalVolume *mother) {
    std::string construction = table->Get<std::string>("construction");
    if (construction == "toroidal") {
        return new ToroidalPMTConstruction(table,mother);
    } else if (construction == "revolution") {
        return new RevolutionPMTConstruction(table,mother);
    } else if (construction == "cubic") {
        Log::Die("Cubic PMTs are not yet implemented!");
    } else if (construction == "toroidal_mask") {
        return new ToroidalPMTConstructionMask(table,mother);
    }
    return NULL;
}

} // namespace RAT

