#ifndef __cle_add_image_and_scalar_2d_h
#define __cle_add_image_and_scalar_2d_h

"__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_CLAMP_TO_EDGE | CLK_FILTER_NEAREST;\n"
"\n"
"__kernel void add_image_and_scalar_2d(\n"
"    IMAGE_src_TYPE  src,\n"
"    IMAGE_dst_TYPE  dst,\n"
"    float scalar\n"
")\n"
"{\n"
"  const int x = get_global_id(0);\n"
"  const int y = get_global_id(1);\n"
"\n"
"  const int2 pos = (int2){x,y};\n"
"\n"
"  const IMAGE_dst_PIXEL_TYPE value = CONVERT_dst_PIXEL_TYPE(READ_src_IMAGE(src, sampler, pos).x + scalar);\n"
"\n"
"  WRITE_dst_IMAGE (dst, pos, value);\n"
"}\n"

#endif //__cle_add_image_and_scalar_2d_h
