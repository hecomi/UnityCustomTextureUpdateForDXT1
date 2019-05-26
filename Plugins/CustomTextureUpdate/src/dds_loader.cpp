#include <cstdio>
#include "dds_loader.h"
#include "util.h"

using namespace CustomTextureUpdate;


void DdsLoader::Load(const void *pData, size_t dataSize)
{
    const auto *pHeader = reinterpret_cast<const DdsHeader*>(pData);

    // check if the given buffer is .dds file.
    if (pHeader->dwMagic != 0x20534444 /* " SDD" */) return;

     // only DXT1 is supported now for the simplicity.
    if (pHeader->dwFourCC != 0x31545844 /* "1TXD" */) return;

    m_width = pHeader->dwWidth;
    m_height = pHeader->dwHeight;

    constexpr size_t headerSize = sizeof(DdsHeader);
    const size_t blockWidth = (m_width + 3) / 4;
    const size_t blockHeight = (m_height + 3) / 4;
    const size_t bufferSize = blockWidth * blockHeight * 8; 
    const auto *pBuffer = reinterpret_cast<const char*>(pData) + headerSize;

    m_data = std::make_unique<char[]>(bufferSize);
    std::memcpy(m_data.get(), pBuffer, bufferSize);

    m_hasLoaded = true;
}
