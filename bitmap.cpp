// --------------------------------------------------------
//    File: bitmap.cpp
//  Author: COP 3003 Programming II
// Purpose: main application file for bitmap program that
//  currently opens a bitmap and copies it to an output file
// --------------------------------------------------------
#include <iostream>
#include <fstream>

#include "BMFile.h"                 // bitmap file class
#include "EncryptedBMFile.h"        //encrypted bitmap type

int main() {

    std::string inFileName, outFileName;

    std::string encMsg;

    std::ifstream inFile;
    inFile.open(inFileName, std::ios::binary);

    std::ofstream outFile;
    outFile.open(outFileName, std::ios::out | std::ios::trunc | std::ios::binary);

    BMFile bmFile = BMFile(&inFile, &outFile);

    int decision;



    //while loop for user interaction
    do {

        std::cout << "\nType 1 to encrypt or 2 to decrypt or 3 to exit: ";
        std::cin>> decision;

        //encrypt the file if decision is 1
        if (decision == 1) {

            std::cout
                    << "\nEnter bitmap file name to read: ";      ///Users/ragycostadejesus/Desktop/COP2/azul_small.bmp
            std::cin >> inFileName;

            std::cout << "\nEnter bitmap file name to write: ";
            std::cin >> outFileName;

            inFile.open(inFileName, std::ios::binary);
            outFile.open(outFileName, std::ios::out | std::ios::trunc | std::ios::binary);

            std::cout << "Write the encrypted message: ";
            std::cin >> encMsg;

            int bytes = bmFile.load();
            std::cout << "Loaded Bitmap \"" << inFileName << "\" (" << std::to_string(bytes) << " bytes)\n";
            std::cout << bmFile.toString();

            EncryptedBMFile *encrypted = reinterpret_cast<EncryptedBMFile *>(&bmFile);
            encrypted->encryptBMFile(encMsg);

            encrypted->store();
            std::cout << "\n\nStored to Bitmap \"" << outFileName << "\" (" << std::to_string(bytes) << " bytes)\n";

        //decrypting the input file
        } else if(decision == 2) {
            std::cout << "What is the file name you wish to decrypt: ";
            std::cin >> inFileName;
            inFile.open(inFileName, std::ios::binary);

            bmFile.load();
            EncryptedBMFile *decrypted = reinterpret_cast<EncryptedBMFile *>(&bmFile);
            encMsg = decrypted->decryptBMFile();
            std::cout << "Encrypted message is: " << encMsg;
        }

    }while(decision != 3);




    return 0;
}
