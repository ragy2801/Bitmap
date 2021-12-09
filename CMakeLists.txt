cmake_minimum_required(VERSION 3.20)
project(bitmap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bitmap
        bitmap.cpp
        bitmap_defs.h
        BMCoreHeader.cpp
        BMCoreHeader.h
        BMFile.cpp
        BMFile.h
        BMFileHeader.cpp
        BMFileHeader.h
        BMInfoHeader.cpp
        BMInfoHeader.h
        BMReader.cpp
        BMReader.h
        BMWriter.cpp
        BMWriter.h
        Pixel.cpp
        Pixel.h
        PixelArray.cpp
        PixelArray.h EncryptedBMFile.cpp EncryptedBMFile.h)
