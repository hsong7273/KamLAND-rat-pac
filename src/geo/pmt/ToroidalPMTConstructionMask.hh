#ifndef __RAT_ToroidalPMTConstructionMask__
#define __RAT_ToroidalPMTConstructionMask__

#include <string>
#include <vector>
#include <RAT/DB.hh>
#include <G4Material.hh>
#include <RAT/GLG4TorusStack.hh>
#include <G4OpticalSurface.hh>
#include <G4VSensitiveDetector.hh>
#include <G4VSolid.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <RAT/WaveguideFactory.hh>
#include <RAT/Factory.hh>
#include <RAT/PMTConstruction.hh>

namespace RAT {


struct ToroidalPMTConstructionMaskParams {
    ToroidalPMTConstructionMaskParams () { 
        efficiencyCorrection = 1.0;
        simpleVis = false;
    };

    bool simpleVis;

    // Envelope control
    bool useEnvelope;
    double faceGap;
    double minEnvelopeRadius;

    // Body
    std::vector<double> zEdge; // n+1
    std::vector<double> rhoEdge; // n+1
    std::vector<double> zOrigin; // n
    double wallThickness; // mm

    double dynodeRadius; // mm
    double dynodeTop; // mm

    G4Material *exterior;
    G4Material *glass;
    G4Material *vacuum;
    G4Material *dynode;

    G4OpticalSurface *photocathode;
    G4OpticalSurface *mirror;
    G4OpticalSurface *dynode_surface;

    double efficiencyCorrection; // default to 1.0 for no correction

    // Masks
    bool needmask20;
    bool needmask17;
};

// Construction for PMTs based on GLG4TorusStack
class ToroidalPMTConstructionMask : public PMTConstruction {
public:
    ToroidalPMTConstructionMask(DBLinkPtr params, G4LogicalVolume *mother);
    virtual ~ToroidalPMTConstructionMask() { }
    
    virtual G4LogicalVolume *BuildVolume(const std::string &prefix);
    virtual G4VSolid *BuildSolid(const std::string &prefix);
    virtual G4PVPlacement* PlacePMT(
            G4RotationMatrix *pmtrot, 
            G4ThreeVector pmtpos, 
            const std::string &name, 
            G4LogicalVolume *logi_pmt, 
            G4VPhysicalVolume *mother_phys, 
            bool booleanSolid, int copyNo);
            
protected:
    G4VSolid *NewEnvelopeSolid(const std::string &name);
  
    void CalcInnerParams(GLG4TorusStack *body,
                         std::vector<double> &innerZEdge, 
                         std::vector<double> &innerRhoEdge,
                         int &equatorIndex, 
                         double &zLowestDynode); 
                          
    // phyiscal volumes 
    G4PVPlacement* body_phys;
    G4PVPlacement* inner1_phys;
    G4PVPlacement* inner2_phys;
    G4PVPlacement* central_gap_phys; 
    G4PVPlacement* dynode_phys; 

    G4PVPlacement* mask20_phys;
    G4PVPlacement* mask17_phys;
    
    G4LogicalVolume *log_pmt;        

    WaveguideFactory *fWaveguideFactory;
    
    ToroidalPMTConstructionMaskParams fParams;
};

} // namespace RAT

#endif
