#include <idc.idc>

static xor_setp1(){
    auto addr = 0x00414c3c;   //这里填入要解密字节串的起始地址
    auto i = 0;
    for(i=0;addr+i<0x00414C7F;i++)   //循环结束的条件为字节串的结束地址
    {
        PatchByte(addr+i,Byte(addr+i)^0x7D);   //异或的数字根据情况修改
    }
}

static xor_setp2(){
    auto addr = 0x00414be0;   //这里填入要解密字节串的起始地址
    auto i = 0;
    for(i=0;addr+i<0x00414C3A;i++)   //循环结束的条件为字节串的结束地址
    {
        PatchByte(addr+i,Byte(addr+i)^0x43);   //异或的数字根据情况修改
    }
}

static xor_setp3(){
    auto addr = 0x00414a84;   //这里填入要解密字节串的起始地址
    auto i = 0;
    for(i=0;addr+i<0x00414a84 + 347;i++)   //循环结束的条件为字节串的结束地址
    {
        PatchByte(addr+i,Byte(addr+i)^0x55);   //异或的数字根据情况修改
    }
}

static xor_setp4(){
    auto addr = 0x00427a40;   //这里填入要解密字节串的起始地址
    auto i = 0;
    for(i=0;addr+i<0x00427c70;i++)   //循环结束的条件为字节串的结束地址
    {
        PatchByte(addr+i,Byte(addr+i)^0x18);   //异或的数字根据情况修改
    }
}

static main()
{
	xor_setp4();
}
