#ifndef CODEVAULT_CIPHER_H
#define CODEVAULT_CIPHER_H

#include <string>

class Cipher {
public:
    Cipher() = default;
    ~Cipher() = default;

    static std::string cipher26(std::string message);

protected:
private:
};
#endif
