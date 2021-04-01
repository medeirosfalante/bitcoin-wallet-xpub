#include "wallet.h"
#include <bitcoin/system.hpp>

Wallet::Wallet()
{
}

Wallet::~Wallet()
{
}

bool Wallet::LoadingXpub(const string &keyString)
{

    bc::wallet::ec_public from_string(keyString);
    key = from_string;
    return true;
}