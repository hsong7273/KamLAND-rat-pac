#ifndef __RAT_GeoTorusArrayFactory__
#define __RAT_GeoTorusArrayFactory__

#include <RAT/GeoSolidArrayFactoryBase.hh>

namespace RAT {
 class GeoTorusArrayFactory : public GeoSolidArrayFactoryBase {
 public:
   GeoTorusArrayFactory() : GeoSolidArrayFactoryBase("torusarray") {};
   using GeoSolidArrayFactoryBase::Construct;
   virtual G4VPhysicalVolume *Construct(DBLinkPtr table);
 };
  
} // namespace RAT

#endif
