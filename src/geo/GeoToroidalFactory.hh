#ifndef __RAT_GeoToroidalFactory__
#define __RAT_GeoToroidalFactory__

#include <RAT/GeoSolidFactory.hh>

namespace RAT {
 class GeoToroidalFactory : public GeoSolidFactory {
 public:
   GeoToroidalFactory() : GeoSolidFactory("toroidal") {};
   virtual G4VSolid *ConstructSolid(DBLinkPtr table);
 };
  
} // namespace RAT

#endif
