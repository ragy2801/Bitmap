//
// Created by Ragy Costa de jesus on 12/5/21.
//

#include "EncryptedBMFile.h"
#include "PixelArray.h"


/* Desc  :   Encrypts the bitmap file
 * Param :   Bitmap File
 */
void EncryptedBMFile::encryptBMFile(std::string bmFile ){
    int bytes;

    int row = 0, column = 0;
    for (int next = 0; next < bmFile.length(); next++) {
        char nextChar = bmFile[next];

        for (int bit = 0; bit < 8; bit++) {

            PixelArray *nextPixel = nullptr;

            nextPixel->getPixels();

            uint8_t blue = nextPixel->getBlue();

            //encryption
            if (nextChar & 1) {
                blue |= 1;
            }
            else {
                blue &= 0xFE;
            }

            nextPixel->setBlue(blue);         //setBlue(blue);

            nextChar >>= 1;
        }

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
 */
std::string EncryptedBMFile::decryptBMFile(){

    int row = 0, column = 0;
    char nextChar;
    std::string decryptMSg = "";

// until we hit the null terminator
    do {

        for (int i = 0; i < 8; i++) {

            Pixel *pixel = &pixels.getPixels()[row][column];

            //or the result of {Blue & 1 (isolate bit-0) shifted i times to the left}
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

