#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <bitcoin/system.hpp>
using std::string;

class Wallet
{
protected:
    bc::wallet::ec_public key;

private:
public:
    Wallet();
    ~Wallet();
    bool LoadingXpub(const string &keyString);
    bool Create(const string &keyString);
};

#endif
