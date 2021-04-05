// Copyright (c) 2016-2018 The Tokyocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TOKYOCOIN_VERSIONBITSINFO_H
#define TOKYOCOIN_VERSIONBITSINFO_H

struct VBDeploymentInfo {
    /** Deployment name */
    const char *name;
    /** Whether GBT clients can safely ignore this rule in simplified usage */
    bool gbt_force;
};

extern const struct VBDeploymentInfo VersionBitsDeploymentInfo[];

#endif // TOKYOCOIN_VERSIONBITSINFO_H
