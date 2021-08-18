#ifndef __cleContextManager_h
#define __cleContextManager_h


#include "clic.hpp"

#include <vector>


namespace clic
{
    
class ContextManager
{
private:
    cl::Context m_Context;

public:
    ContextManager() =default;
    ContextManager(cl::Device);
    ContextManager(std::vector<cl::Device>);
    ~ContextManager();

    cl::Context GetContext();
    std::vector<cl::Device> GetDevices();
};

} // namespace clic

#endif // __cleContextManager_h