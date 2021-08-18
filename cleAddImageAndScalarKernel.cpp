
#include "cleAddImageAndScalarKernel.hpp"

namespace clic
{

void AddImageAndScalarKernel::SetInput(Buffer& x)
{
    this->AddObject(x, "src");
}

void AddImageAndScalarKernel::SetOutput(Buffer& x)
{
    this->AddObject(x, "dst");
}

void AddImageAndScalarKernel::SetScalar(float x)
{
    this->AddObject(x, "scalar");
}

void AddImageAndScalarKernel::Execute()
{
    if(this->m_Sources.size() > 1)
    {
        this->ManageDimensions("dst");
    }
    this->BuildProgramKernel();
    this->SetArguments();
    this->EnqueueKernel();
}
} // namespace clic

