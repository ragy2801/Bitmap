// --------------------------------------------------------
//    File: bitmap.cpp
//  Author: COP 3003 Programming II
// Purpose: main application file for bitmap program that
//  currently opens a bitmap and copies it to an output file
// --------------------------------------------------------
#include <iostream>
#include <fstream>

#include "BMFile.h"     // bitmap file class

int main() {

    std::string inFileName, outFileName;

    std::cout << "\nEnter bitmap file name to read: ";      ///Users/ragycostadejesus/Desktop/COP2
    std::cin >> inFileName;

    std::cout << "\nEnter bitmap file name to write: ";
    std::cin >> outFileName;

    // make sure the file names were entered
    if (inFileName.length() && outFileName.length()) {

        std::ifstream inFile;
        inFile.open(inFileName, std::ios::binary);

        std::ofstream outFile;
        outFile.open(outFileName, std::ios::out|std::ios::trunc|std::ios::binary);

        if (inFile.is_open() && outFile.is_open()) {

            BMFile bmFile = BMFile(&inFile, &outFile);

            int bytes = bmFile.load();

            std::cout << "Loaded Bitmap \"" << inFileName << "\" (" << std::to_string(bytes) << " bytes)\n";
            std::cout << bmFile.toString();

            bytes = bmFile.store();
            std::cout << "\n\nStored to Bitmap \"" << outFileName << "\" (" << std::to_string(bytes) << " bytes)\n";

        }
        else {
            std::cout << "Could not open input file: " << inFileName << std::endl;
        }


    } // filename lengths > 0
    else {
        std::cout << "File names must be > 0 length!\n";
    }

    return 0;
}
