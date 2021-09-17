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

/// \file digits-to-timeclusters-workflow.cxx
/// \brief This is an executable that runs the time clusterization via DPL.
///
/// This is an executable that takes digits from the Data Processing Layer, runs the time clusterization and sends the time clusters via the Data Processing Layer.
///
/// \author Andrea Ferrero, CEA

#include "Framework/CallbackService.h"
#include "Framework/ControlService.h"
#include "Framework/Task.h"
#include "Framework/runDataProcessing.h"
#include "MCHWorkflow/TimeClusterFinderSpec.h"

using namespace o2;
using namespace o2::framework;

WorkflowSpec defineDataProcessing(const ConfigContext&)
{
  return {o2::mch::getTimeClusterFinderSpec()};
}