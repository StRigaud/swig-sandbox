
#include "cleDeviceManager.h"

#include <iostream>

namespace clic
{

DeviceManager::DeviceManager(cl::Platform platform)
{
    platform.getDevices(CL_DEVICE_TYPE_ALL, &m_DeviceList);
    if (m_DeviceList.size() == 0)
    {
        std::cerr << "DeviceManager : No devices found." << std::endl;
    }
}

DeviceManager::DeviceManager(std::vector<cl::Platform> platform_list)
{
    std::vector<cl::Device> tmp_device_list;
    for(auto ite = platform_list.begin(); ite != platform_list.end(); ++ite)
    {
        ite->getDevices(CL_DEVICE_TYPE_ALL, &tmp_device_list);
        if (tmp_device_list.size() > 0)
        {
            m_DeviceList.insert(
                m_DeviceList.end(),
                std::make_move_iterator(tmp_device_list.begin()),
                std::make_move_iterator(tmp_device_list.end())
                );    
        }
        tmp_device_list.clear();
    }
    if (m_DeviceList.size() == 0)
    {
        std::cerr << "DeviceManager : No devices found." << std::endl;
    }
}

DeviceManager::~DeviceManager()
{
    if (this->m_DeviceList.size() != 0)
    {
        this->m_DeviceList.clear();
    }
}

void DeviceManager::SetDevice(int index)
{
    if (m_DeviceList.size() < index)
    {
        std::cerr << "DeviceManager : Wrong device index." << std::endl;
    }
    else
    {
        this->m_DeviceId = index;
    }
}

void DeviceManager::SetDevice(std::string name)
{
    bool deviceFound = false;
    auto ite = m_DeviceList.begin();
    while(!deviceFound && ite != m_DeviceList.end())
    {
        std::size_t found = ite->getInfo<CL_DEVICE_NAME>().find(name);
        bool available = ite->getInfo<CL_DEVICE_AVAILABLE>();
        if(available && found > 0)
        {
            deviceFound = true;
            this->m_DeviceId = ite - this->m_DeviceList.begin();
        }
        ite++;
    }
    if(!deviceFound)
    {
        std::cerr << "DeviceManager : No available device found with the name '" + name + "'. Use default device." << std::endl;
    }
}

std::vector<cl::Device> DeviceManager::GetDevices()
{
    return this->m_DeviceList;
}

cl::Device DeviceManager::GetDevice()
{
    return this->m_DeviceList[this->m_DeviceId];
}

cl::Device DeviceManager::GetDevice(int device_id)
{
    if (device_id < this->m_DeviceList.size())
    {
        return this->m_DeviceList[device_id];
    }
    else
    {
        std::cerr << "DeviceManager : wrong device id. Return default device instead." << std::endl;
        return this->m_DeviceList[this->m_DeviceId];
    }
}

std::string DeviceManager::DeviceInfo(int index)
{
    if(index == -1)
    {
        index = this->m_DeviceId;
    }
    auto ite = this->m_DeviceList.begin() + index;
    std::string out("");
    out += "[" + std::to_string(ite - this->m_DeviceList.begin()) + "] - " + ite->getInfo<CL_DEVICE_NAME>() + "\n";
    out += "\tMaxComputeUnits: " + std::to_string(ite->getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>()) + "\n";
    out += "\tMaxClockFrequency: " + std::to_string(ite->getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>()) + "\n";
    out += "\tVersion: " + ite->getInfo<CL_DEVICE_VERSION>() + "\n";
    out += "\tExtensions: " + ite->getInfo<CL_DEVICE_EXTENSIONS>() + "\n";
    out += "\tGlobalMemorySizeInBytes: " + std::to_string(ite->getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>()) + "\n";
    out += "\tLocalMemorySizeInBytes: " + std::to_string(ite->getInfo<CL_DEVICE_LOCAL_MEM_SIZE>()) + "\n";
    out += "\tMaxMemoryAllocationSizeInBytes: " + std::to_string(ite->getInfo<CL_DEVICE_MAX_MEM_ALLOC_SIZE>()) + "\n";
    out += "\tMaxWorkGroupSize: " + std::to_string(ite->getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>()) + "\n";
    return out;
}


std::string DeviceManager::DevicesInfo()
{
    std::string out ("List of Device available:\n");
    for( auto ite = this->m_DeviceList.begin(); ite != this->m_DeviceList.end(); ++ite)
    {
        out += DeviceInfo(ite - this->m_DeviceList.begin());
    }

    int id_bestForImages(0), id_bestForMemory(0), id_bestForSpeed(0);
    for( auto ite = this->m_DeviceList.begin(); ite != this->m_DeviceList.end(); ++ite)
    {
        if(ite->getInfo<CL_DEVICE_LOCAL_MEM_SIZE>() > this->m_DeviceList[id_bestForMemory].getInfo<CL_DEVICE_LOCAL_MEM_SIZE>())
        {
            id_bestForMemory = ite - this->m_DeviceList.begin();
        }
        if(ite->getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>() > this->m_DeviceList[id_bestForSpeed].getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>())
        {
            id_bestForSpeed = ite - this->m_DeviceList.begin();
        }
    }
    out += "\n";
    out += "Fastest Device: " + this->m_DeviceList[id_bestForSpeed].getInfo<CL_DEVICE_NAME>() + "\n";
    out += "Largest Device: " + this->m_DeviceList[id_bestForMemory].getInfo<CL_DEVICE_NAME>() + "\n";
    out += "Image adapted Device: " + this->m_DeviceList[id_bestForImages].getInfo<CL_DEVICE_NAME>() + "\n";

    return out;
}


} // namespace clic

