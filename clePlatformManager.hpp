#ifndef __clePlatformManager_h
#define __clePlatformManager_h

#include "clic.hpp"

#include <vector>

namespace clic
{
    
class PlatformManager
{
private:
    std::vector<cl::Platform> m_PlatformList;

public:
    PlatformManager();
    ~PlatformManager();

    std::vector<cl::Platform> GetPlatforms();

    std::string PlatformsInfo();

};

} // namespace clic

#endif //__clePlatformManager_h