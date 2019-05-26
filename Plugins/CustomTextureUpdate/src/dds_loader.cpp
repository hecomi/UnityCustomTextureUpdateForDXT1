#include <cstdio>
#include <Windows.h>
#include "dds_loader.h"
#include "util.h"

using namespace CustomTextureUpdate;

// https://dench.flatlib.jp/ddsformat
struct DdsHeader
{
    DWORD dwMagic;
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwHeight;
    DWORD dwWidth;
    DWORD dwPitchOrLinearSize;
    DWORD dwDepth;
    DWORD dwMipMapCount;
    DWORD dwReserved1[11];
    DWORD dwPfSize;
    DWORD dwPfFlags;
    DWORD dwFourCC;
    DWORD dwRGBBitCount;
    DWORD dwRBitMask;
    DWORD dwGBitMask;
    DWORD dwBBitMask;
    DWORD dwRGBAlphaBitMask;
    DWORD dwCaps;
    DWORD dwCaps2;
    DWORD dwReservedCaps[2];
    DWORD dwReserved2;
};

void DdsLoader::Load(const void *pData, size_t dataSize)
{
    const auto *pHeader = reinterpret_cast<const DdsHeader*>(pData);

    // check if the given buffer is .dds file.
    if (pHeader->dwMagic != 0x20534444 /* " SDD" */) return;

     // only DXT1 is supported now for the simplicity.
    if (pHeader->dwFourCC != 0x31545844 /* "1TXD" */) return;

    width_ = pHeader->dwWidth;
    height_ = pHeader->dwHeight;

    constexpr size_t headerSize = sizeof(DdsHeader);
    const size_t bufferSize = dataSize - headerSize;
    const auto *pBuffer = reinterpret_cast<const char*>(pData) + headerSize;

    data_ = std::make_unique<char[]>(bufferSize);
    std::memcpy(data_.get(), pBuffer, bufferSize);

    hasLoaded_ = true;
}
