//    file: EncryptedBMFile.h
//  Author: COP 3003 Programming II
// Purpose: class implementation file for a encrypted message
// --------------------------------------------------------


#include "EncryptedBMFile.h"



/* Desc  :   Encrypts the bitmap file
 * Param :   Bitmap File
 ---------------------------------------------------------*/
void EncryptedBMFile::encryptBMFile(std::string msg ) {
    int bytes;

    int row = 0, column = 0;
    for (int next = 0; next < msg.length(); next++) {
        char nextChar = msg[next];

        for (int bit = 0; bit < 8; bit++) {

            Pixel *nextPixel = &pixels.getPixels()[row][column];

            uint8_t blue = nextPixel->getBlue();

            if (nextChar & 1) {
                blue |= 1;
            } else {
                blue &= 0xFE;
            }

            nextPixel->setBlue(blue);

            nextChar >>= 1;
        }

        column++;
        if (column == pixels.getWidth()) {
            row++;
            column = 0;
        }
        bytes++;
    }


    for (int term = 0; term < 8; term++) {
        Pixel *nextPixel = &pixels.getPixels()[row][column];
        uint8_t blue = nextPixel->getBlue();
        blue &= 0xFE;
        nextPixel->setBlue(blue);
        column++;
        if (column == pixels.getWidth()) {
            row++;
            column = 0;
        }
        bytes++;
    }

}


/* Desc  :   Decrypts the bitmap file
 * Return:   string
 ---------------------------------------------------------*/
std::string EncryptedBMFile::decryptBMFile(){

    int row = 0, column = 0;
    char nextChar;
    std::string decryptMSg = "";

// until we hit the null terminator
    do {

        for (int i = 0; i < pixels.getWidth() ; i++) {

            Pixel *pixel = &pixels.getPixels()[row][column];

            nextChar |= (pixel->getBlue() & 1) << i;

            // get next pixel
            column++;
            if (column == pixels.getWidth()) {
                column = 0;
                row++;
            }

        }

        decryptMSg += nextChar;
    } while (nextChar);

    return decryptMSg;
}

