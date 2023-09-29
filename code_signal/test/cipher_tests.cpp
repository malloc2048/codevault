#include <gtest/gtest.h>
#include "cipher/cipher.h"

TEST(CipherTest, Cipher26) {
    ASSERT_STREQ("thisisencryptedmessage", Cipher::cipher26("taiaiaertkixquxjnfxxdh").c_str());
}
