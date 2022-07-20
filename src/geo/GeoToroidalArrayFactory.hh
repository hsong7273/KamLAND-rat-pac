#ifndef __RAT_GeoToroidalArrayFactory__
#define __RAT_GeoToroidalArrayFactory__

#include <RAT/GeoSolidArrayFactoryBase.hh>

namespace RAT {
 class GeoToroidalArrayFactory : public GeoSolidArrayFactoryBase {
 public:
   GeoToroidalArrayFactory() : GeoSolidArrayFactoryBase("toroidalarray") {};
   using GeoSolidArrayFactoryBase::Construct;
   virtual G4VPhysicalVolume *Construct(DBLinkPtr table);
 };
  
} // namespace RAT

#endif
