#include <Windows.h>
#include <memory>

namespace CustomTextureUpdate
{

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

class DdsLoader
{
public:
    void Load(const void *pData, size_t size);
    bool HasLoaded() const { return hasLoaded_; }
    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
    char * GetData() const { return data_.get(); }

private:
    std::unique_ptr<char[]> data_;
    bool hasLoaded_ = false;
	int width_ = 0;
    int height_ = 0;
};

}
