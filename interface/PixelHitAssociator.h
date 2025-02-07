#ifndef PixelHitAssociator_h
#define PixelHitAssociator_h

/* \class PixelHitAssociator
 *
 ** Associates SimHits and RecHits based on information produced during
 *  digitisation (StripDigiSimLinks).
 *  The association works in both ways: from a SimHit to RecHits and
 *  from a RecHit to SimHits.
 *
 * \author Patrizia Azzi (INFN PD), Vincenzo Chiochia (Uni Zuerich)
 *
 * \version   1st version: April 2006. Add configurable switch: August 2006   
 * Adopted for pixel only. dk 3/2014
 *
 ************************************************************/

#ifndef CMSSW_VERSION
#define CMSSW_VERSION 106
#endif

//#include <vector>
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"

//--- for SimHit
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"

#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "SimDataFormats/TrackerDigiSimLink/interface/PixelDigiSimLink.h"
#include "SimDataFormats/TrackerDigiSimLink/interface/StripDigiSimLink.h"

//--- for RecHit
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
//#include "TrackingTools/TransientTrackingRecHit/interface/TransientTrackingRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit1D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/ProjectedSiStripRecHit2D.h"
//#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiTrackerMultiRecHit.h"
//#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSMatchedRecHit2D.h"

#include "SimDataFormats/CrossingFrame/interface/MixCollection.h"

#if CMSSW_VERSION > 110
#include "Geometry/CommonTopologies/interface/PixelGeomDetUnit.h"
#elif CMSSW_VERSION > 106
#include "Geometry/CommonDetUnit/interface/PixelGeomDetUnit.h"
#else
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#endif

#include <string>
#include <vector>


typedef std::pair<uint32_t, EncodedEventId> SimHitIdpr;

class PixelHitAssociator {
  
 public:
  
  // Simple constructor
  PixelHitAssociator(const edm::Event& e);
  // Constructor with configurables
  PixelHitAssociator(const edm::Event& e, const edm::ParameterSet& conf);
  // Destructor
  virtual ~PixelHitAssociator(){}
  
  std::vector<PSimHit> associateHit(const TrackingRecHit&, LocalPoint);
  //std::vector<PSimHit> associateHit(const SiPixelRecHit & thit);
  void associatePixelRecHit(const SiPixelRecHit*, std::vector<SimHitIdpr>&);

  /*  std::vector<unsigned int> associateHitId(const TrackingRecHit & thit);
      std::vector<unsigned int> associateSimpleRecHit(const SiStripRecHit2D * simplerechit);
      std::vector<unsigned int> associateMatchedRecHit(const SiStripMatchedRecHit2D * matchedrechit);
      std::vector<unsigned int> associatePixelRecHit(const SiPixelRecHit * pixelrechit);
  */
  //for PU events
  //std::vector<SimHitIdpr> associateHitId(const TrackingRecHit & thit);
  //void associateHitId(const TrackingRecHit & thit,std::vector<SimHitIdpr> &simhitid);
  //  std::vector<SimHitIdpr> associateSimpleRecHit(const SiStripRecHit2D * simplerechit);


  //void associateSimpleRecHit(const SiStripRecHit2D * simplerechit,std::vector<SimHitIdpr> & simhitid);
  //void associateSiStripRecHit1D(const SiStripRecHit1D * simplerechit,std::vector<SimHitIdpr> & simhitid);
  //void associateSimpleRecHitCluster(const SiStripCluster* clust,
  //				    const uint32_t& detID,
  //				    std::vector<SimHitIdpr>& theSimtrackid,
  //				    std::vector<PSimHit>& simhit);
  //void associateSimpleRecHitCluster(const SiStripCluster* clust,
  //				    const uint32_t& detID,
  //				    std::vector<PSimHit>& simhit);
  //void associateSimpleRecHitCluster(const SiStripCluster* clust,
  //				    const uint32_t& detID,
  //				    std::vector<SimHitIdpr>& simtrackid);

  //std::vector<SimHitIdpr> associateMatchedRecHit(const SiStripMatchedRecHit2D * matchedrechit);
  //std::vector<SimHitIdpr> associateProjectedRecHit(const ProjectedSiStripRecHit2D * projectedrechit);
  //  std::vector<SimHitIdpr> associatePixelRecHit(const SiPixelRecHit * pixelrechit);

  //std::vector<SimHitIdpr> associateGSRecHit(const SiTrackerGSRecHit2D * gsrechit);
  //std::vector<SimHitIdpr> associateMultiRecHitId(const SiTrackerMultiRecHit * multirechit);
  //std::vector<PSimHit>    associateMultiRecHit(const SiTrackerMultiRecHit * multirechit);
  //std::vector<SimHitIdpr> associateGSMatchedRecHit(const SiTrackerGSMatchedRecHit2D * gsmrechit);
  
  //std::vector<PSimHit> theStripHits;
  typedef std::map<unsigned int, std::vector<PSimHit> > simhit_map;
  typedef simhit_map::iterator simhit_map_iterator;
  simhit_map SimHitMap;
  //std::vector<PSimHit> thePixelHits;
 
 private:
  const edm::Event& myEvent_;
  typedef std::vector<std::string> vstring;
  vstring trackerContainers;

  //ADDED NOW AS A PRIVATE MEMBER
  //edm::Handle<CrossingFrame<PSimHit> > cf_simhit;
  //std::vector<const CrossingFrame<PSimHit> *> cf_simhitvec;
  MixCollection<PSimHit>  TrackerHits;

  edm::Handle< edm::DetSetVector<StripDigiSimLink> >  stripdigisimlink;
  edm::Handle< edm::DetSetVector<PixelDigiSimLink> >  pixeldigisimlink;
  //vector with the trackIds
  //  std::vector<unsigned int> simtrackid; 
  std::vector<SimHitIdpr> simtrackid; 
  //vector with the simhits
  std::vector<int> simhitCFPos;
  std::vector<PSimHit> simhitassoc;
  bool StripHits;  
  //bool doPixel_, doStrip_, doTrackAssoc_;
  
};  


#endif

