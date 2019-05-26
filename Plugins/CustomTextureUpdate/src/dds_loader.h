#include <memory>

namespace CustomTextureUpdate
{

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
