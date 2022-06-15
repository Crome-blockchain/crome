// Copyright (c) 2020 The PIVX developers
// Copyright (c) 2021-2022 The DECENOMY Core Developers
// Copyright (c) 2022 The Crome Core Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "wallet/hdchain.h"

#include "base58.h"
#include "chainparams.h"
#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"

bool CHDChain::SetNull()
{
    nVersion = CURRENT_VERSION;
    seed_id = CKeyID();
    nExternalChainCounter = 0;
    nInternalChainCounter = 0;
    nECommerceChainCounter = 0;
    return IsNull();
}

bool CHDChain::IsNull() const
{
    return seed_id.IsNull();
}

bool CHDChain::SetSeed( const CKeyID& seedId)
{
    // Cannot be initialized twice
    if (!IsNull())
        return false;

    seed_id = seedId;
    return true;
}