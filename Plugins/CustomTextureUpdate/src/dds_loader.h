#include <Windows.h>
#include <memory>

namespace CustomTextureUpdate
{

// https://dench.flatlib.jp/ddsformat
struct DdsHeader
{
    DWORD   dwMagic;
    DWORD   dwSize;
    DWORD   dwFlags;
    DWORD   dwHeight;
    DWORD   dwWidth;
    DWORD   dwPitchOrLinearSize;
    DWORD   dwDepth;
    DWORD   dwMipMapCount;
    DWORD   dwReserved1[11];
    DWORD   dwPfSize;
    DWORD   dwPfFlags;
    DWORD   dwFourCC;
    DWORD   dwRGBBitCount;
    DWORD   dwRBitMask;
    DWORD   dwGBitMask;
    DWORD   dwBBitMask;
    DWORD   dwRGBAlphaBitMask;
    DWORD   dwCaps;
    DWORD   dwCaps2;
    DWORD   dwReservedCaps[2];
    DWORD   dwReserved2;
};

class DdsLoader
{
public:
    void Load(const void *pData, size_t size);
    bool HasLoaded() const { return m_hasLoaded; }
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    char * GetData() const { return m_data.get(); }

private:
    std::unique_ptr<char[]> m_data;
    bool m_hasLoaded = false;
	int m_width = 0;
    int m_height = 0;
};

}
