// --------------------------------------------------------
//    File: EncryptedBMFile.h
//  Author: COP 3003 Programming II
// Purpose: class definition to create encryption of bitmap file
// --------------------------------------------------------


#ifndef BITMAP_ENCRYPTEDBMFILE_H
#define BITMAP_ENCRYPTEDBMFILE_H

#include "BMFile.h"

class EncryptedBMFile: public BMFile{
public:

    void encryptBMFile(std::string bmFile );

    std::string decryptBMFile();

};


#endif //BITMAP_ENCRYPTEDBMFILE_H
