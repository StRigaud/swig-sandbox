
#ifndef __cleAddImageAndScalarKernel_h
#define __cleAddImageAndScalarKernel_h

#include "cleKernel.h"

namespace clic
{

class AddImageAndScalarKernel : public Kernel
{
private:
    // std::string source_2d = 
    //     "__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP_TO_EDGE | CLK_FILTER_NEAREST;\n \n  __kernel void add_image_and_scalar_2d(\n  IMAGE_src_TYPE  src,\n  IMAGE_dst_TYPE  dst,\n  float scalar\n  )\n  {\n  const int x = get_global_id(0);\n  const int y = get_global_id(1);\n \n  const int2 pos = (int2){x,y};\n \n  const IMAGE_dst_PIXEL_TYPE value = CONVERT_dst_PIXEL_TYPE(READ_src_IMAGE(src, sampler, pos).x + scalar);\n \n  WRITE_dst_IMAGE (dst, pos, value);\n  }\n"
    //     ;     
    // std::string source_3d = 
    //     "__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP_TO_EDGE | CLK_FILTER_NEAREST;\n \n  __kernel void add_image_and_scalar_3d(\n  IMAGE_src_TYPE  src,\n  IMAGE_dst_TYPE  dst,\n  float scalar\n  )\n  {\n  const int x = get_global_id(0);\n  const int y = get_global_id(1);\n  const int z = get_global_id(2);\n \n  const int4 pos = (int4){x,y,z,0};\n \n  const IMAGE_dst_PIXEL_TYPE value = CONVERT_dst_PIXEL_TYPE(READ_src_IMAGE(src, sampler, pos).x + scalar);\n \n  WRITE_dst_IMAGE(dst, pos, value);\n  }\n"
    //     ; 

    std::string source_2d = 
        #include "cle_add_image_and_scalar_2d.h"
        ;     
    std::string source_3d = 
        #include "cle_add_image_and_scalar_3d.h"
        ;     

public:
    AddImageAndScalarKernel(GPU *gpu) : 
        Kernel( gpu, 
                "add_image_and_scalar", 
                {"src", "dst", "scalar"}
            ) 
    {
        m_Sources.insert({this->m_KernelName + "_2d", source_2d});
        m_Sources.insert({this->m_KernelName + "_3d", source_3d});
    }

    void SetInput(Buffer&);
    void SetOutput(Buffer&);
    void SetScalar(float);
    void Execute();

};

} // namespace clic

#endif // __cleAddImageAndScalarKernel_h
