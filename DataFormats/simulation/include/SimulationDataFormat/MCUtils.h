// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file MCUtils.h
/// \brief Utility functions for MC particles
/// \author S. Wenzel - November 2021

#ifndef O2_MCUTILS_H
#define O2_MCUTILS_H

#include <SimulationDataFormat/MCTrack.h>
#include "TPDGCode.h"

namespace o2
{
namespace mcutils
{
/// Function to determine if a MC track/particle p is a primary according to physics criteria.
/// Needs the particle as input, as well as the whole navigable container of particles
/// (of which p needs to be a part itself). The container can be fetched via MCKinematicsReader.
bool isPhysicalPrimary(o2::MCTrack const& p, std::vector<o2::MCTrack> const& pcontainer);

/// Determine if a particle (identified by pdg) is stable
inline bool isStable(int pdg)
{
  //
  // Decide whether particle (pdg) is stable
  //

  // All ions/nucleons are considered as stable
  // Nuclear code is 10LZZZAAAI
  if (pdg > 1000000000) {
    return true;
  }

  const int kNstable = 18;
  int pdgStable[kNstable] = {
    kGamma,      // Photon
    kElectron,   // Electron
    kMuonPlus,   // Muon
    kPiPlus,     // Pion
    kKPlus,      // Kaon
    kK0Short,    // K0s
    kK0Long,     // K0l
    kProton,     // Proton
    kNeutron,    // Neutron
    kLambda0,    // Lambda_0
    kSigmaMinus, // Sigma Minus
    kSigmaPlus,  // Sigma Plus
    3312,        // Xsi Minus
    3322,        // Xsi
    3334,        // Omega
    kNuE,        // Electron Neutrino
    kNuMu,       // Muon Neutrino
    kNuTau       // Tau Neutrino
  };

  // this is linear search ---> a hash map or binary search should be more appropriate??
  for (int i = 0; i < kNstable; ++i) {
    if (pdg == std::abs(pdgStable[i])) {
      return true;
    }
  }
  return false;
}

} // namespace mcutils
} // namespace o2

#endif //O2_MCUTILS_H
