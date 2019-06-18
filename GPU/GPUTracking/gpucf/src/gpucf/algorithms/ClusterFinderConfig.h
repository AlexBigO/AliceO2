#pragma once

#include <gpucf/algorithms/ChargemapLayout.h>
#include <gpucf/algorithms/ClusterBuilder.h>

#include <cstddef>


namespace gpucf
{

struct ClusterFinderConfig
{
    size_t chunks = 1;

    #define CLUSTER_FINDER_FLAG(name, val, def, desc) bool name = val;
    #include <gpucf/algorithms/ClusterFinderFlags.def>

    ChargemapLayout layout = ChargemapLayout::TimeMajor;

    ClusterBuilder clusterbuilder = ClusterBuilder::Naive;
};

} // namespace gpucf

// vim: set ts=4 sw=4 sts=4 expandtab:
