

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jan 15 18:54:32 2016
 */
/* Compiler settings for D:/workspace/FireBreath/build/dwale/gen/FireBreathWin.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_dwaleLib,0x55ea13d8,0x041c,0x5ba2,0xa6,0xcf,0x74,0x3c,0xb4,0x7a,0x19,0xa9);


MIDL_DEFINE_GUID(IID, IID_IFBControl,0xe6936c89,0xccd5,0x5d67,0xb2,0x30,0x69,0xb9,0x35,0x1c,0x56,0x4c);


MIDL_DEFINE_GUID(IID, IID_IFBComJavascriptObject,0x9b68782f,0xeeb8,0x58b9,0xad,0xad,0xf3,0x9a,0xab,0x70,0x35,0xef);


MIDL_DEFINE_GUID(IID, DIID_IFBComEventSource,0x2c74a0ee,0x9c67,0x558a,0x94,0xaf,0xbc,0x6f,0x6e,0xf9,0x69,0xda);


MIDL_DEFINE_GUID(CLSID, CLSID_FBControl0,0xde5f4c92,0xc370,0x517f,0xa0,0xfa,0x99,0x7d,0xe9,0x68,0xb2,0x99);


MIDL_DEFINE_GUID(CLSID, CLSID_FBComJavascriptObject,0x06d72e39,0x9ccf,0x5dd2,0xb5,0x41,0xfd,0x9f,0xa3,0xbb,0x34,0xe1);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



