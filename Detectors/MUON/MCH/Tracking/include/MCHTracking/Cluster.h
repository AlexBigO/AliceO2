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

/// \file Cluster.h
/// \brief Definition of the MCH cluster for internal use
///
/// \author Philippe Pillot, Subatech

#ifndef ALICEO2_MCH_CLUSTER_H_
#define ALICEO2_MCH_CLUSTER_H_

#include <iostream>
#include <string>

#include "DataFormatsMCH/ClusterBlock.h"

namespace o2
{
namespace mch
{

/// cluster for internal use
class Cluster
{
 public:
  Cluster() = default;
  Cluster(const ClusterStruct& cl);
  ~Cluster() = default;

  Cluster(const Cluster& cl) = default;
  Cluster& operator=(const Cluster& cl) = default;
  Cluster(Cluster&&) = default;
  Cluster& operator=(Cluster&&) = default;

  ClusterStruct getClusterStruct() const;

  /// Return the cluster position along x
  double getX() const { return mX; }
  /// Return the cluster position along y
  double getY() const { return mY; }
  /// Return the cluster position along z
  double getZ() const { return mZ; }
  /// Return the cluster resolution along x
  double getEx() const { return mEx; }
  /// Return the cluster resolution along y
  double getEy() const { return mEy; }
  /// Return the cluster resolution square along x
  double getEx2() const { return mEx * mEx; }
  /// Return the cluster resolution square along y
  double getEy2() const { return mEy * mEy; }

  /// Return the unique ID of this cluster
  uint32_t getUniqueId() const { return mUid; }
  /// Return the chamber ID (0..), part of the unique ID
  int getChamberId() const { return ClusterStruct::getChamberId(mUid); }
  /// Return the detection element ID, part of the unique ID
  int getDEId() const { return ClusterStruct::getDEId(mUid); }
  /// Return the index of this cluster (0..), part of the unique ID
  int getClusterIndex() const { return ClusterStruct::getClusterIndex(mUid); }
  /// Return the unique ID of this cluster in human readable form
  std::string getIdAsString() const { return "DE" + std::to_string(getDEId()) + "#" + std::to_string(getClusterIndex()); }

 private:
  double mX;     ///< cluster position along x
  double mY;     ///< cluster position along y
  double mZ;     ///< cluster position along z
  double mEx;    ///< cluster resolution along x
  double mEy;    ///< cluster resolution along y
  uint32_t mUid; ///< cluster unique ID
};

} // namespace mch
} // namespace o2

#endif // ALICEO2_MCH_CLUSTER_H_
