#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// �� Windows ͷ���ų�����ʹ�õ�����
#endif

// ���������ʹ��������ָ����ƽ̨֮ǰ��ƽ̨�����޸�����Ķ��塣
// �йز�ͬƽ̨����Ӧֵ��������Ϣ����ο� MSDN��
#ifndef WINVER				// ����ʹ���ض��� Windows 95 �� Windows NT 4 ����߰汾�Ĺ��ܡ�
#define WINVER 0x0602		// ���˸���Ϊ����� Windows 98 �� Windows 2000 ����߰汾�ĺ��ʵ�ֵ��
#endif

#ifndef _WIN32_WINNT		// ����ʹ���ض��� Windows NT 4 ����߰汾�Ĺ��ܡ�
#define _WIN32_WINNT 0x0602	// ���˸���Ϊ����� Windows 2000 ����߰汾�ĺ��ʵ�ֵ��
#endif						

#ifndef _WIN32_WINDOWS		// ����ʹ���ض��� Windows 98 ����߰汾�Ĺ��ܡ�
#define _WIN32_WINDOWS 0x0602 // ���˸���Ϊ����� Windows Me ����߰汾�ĺ��ʵ�ֵ��
#endif

#ifndef _WIN32_IE			// ����ʹ���ض��� IE 4.0 ����߰汾�Ĺ��ܡ�
#define _WIN32_IE 0x0602	// ���˸���Ϊ����� IE 5.0 ����߰汾�ĺ��ʵ�ֵ��
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯����Ϊ��ʽ��

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE ��
#include <afxodlgs.h>       // MFC OLE �Ի�����
#include <afxdisp.h>        // MFC �Զ�����
#endif // _AFX_NO_OLE_SUPPORT

#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �����ؼ���֧��
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

//////////////////////////////////////////////////////////////////////////

//���ͷ�ļ�
#include "..\��Ϣ����\CMD_Sparrow.h"
#include "..\..\������\Include\GameServiceExport.h"
#include "..\..\������\Include\Module.h"

//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//
////��Ʒ�汾��
//#define PRODUCT_VER1
//
////�汾����
//#define INTERFACE_VERSION(cbMainVer,cbSubVer)\
//(DWORD)(\
//(((BYTE)(PRODUCT_VER))<<24)+\
//(((BYTE)(cbMainVer))<<16)+\
//((BYTE)(cbSubVer)<<8))
//
////��ȡ��Ʒ�汾
//inline BYTE GetProductVer(DWORD dwVersion)
//{
//
//    BYTE * cbVersion = (BYTE *)&dwVersion;
//    return cbVersion[3];
//
//}
//
////��ȡ���汾
//inline BYTE GetMainVer(DWORD dwVersion)
//{
//
//    BYTE * cbVersion = (BYTE *)&dwVersion;
//    return cbVersion[2];
//
//}
//
////��ȡ�Ӱ汾
//inline BYTE GetSubVer(DWORD dwVersion)
//{
//
//    BYTE * cbVersion = (BYTE *)&dwVersion;
//    return cbVersion[1];
//
//}
//
////��ȡ����汾
//inline BYTE GetBulidVer(DWORD dwVersion)
//{
//
//    BYTE * cbVersion = (BYTE *)&dwVersion;
//    return cbVersion[0];
//
//}
//
////�汾�ԱȺ���
//inline bool InterfaceVersionCheck(DWORD dwQueryVer, DWORD dwInterfaceVer)
//{
//
//    if (GetProductVer(dwQueryVer) != GetProductVer(dwInterfaceVer)) return false;
//    if (GetMainVer(dwQueryVer) != GetMainVer(dwInterfaceVer)) return false;
//    if (GetSubVer(dwQueryVer)>GetSubVer(dwInterfaceVer)) return false;
//    return true;
//
//};
//
////////////////////////////////////////////////////////////////////////////
//
////�ӿڶ���
//#define STD_METHOD(TYPE,METHOD) virtual TYPE __cdecl METHOD
//
////�ӿ������������˵��
//typedef void * (__cdecl ModuleCreateFunc)(const GUID & Gudi, DWORD dwInterfaceVer);
//
////////////////////////////////////////////////////////////////////////////
//
//#define VER_IUnknownEx INTERFACE_VERSION(1,1)
//static const GUID IID_IUnknownEx = {
//    0x92d87e91, 0x5a5b, 0x4a45, 0x8c, 0xfd, 0x38, 0x2f, 0xe6, 0xb3, 0x2b, 0xb
//};
//
////�����ӿ�
//interface IUnknownEx
//{
//
//    //�Ƿ���Ч
//    virtual bool __cdecl IsValid() = NULL;
//    //�ͷŶ���
//    virtual bool __cdecl Release() = NULL;
//    //�ӿڲ�ѯ
//    virtual void * __cdecl QueryInterface(const IID & Guid, DWORD dwQueryVer) = NULL;
//
//};
//
////////////////////////////////////////////////////////////////////////////
//
////�ӿڲ�ѯ��
//#define QUERYINTERFACE(Interface,Guid,dwQueryVer)\
//if ((Guid==IID_##Interface)&&(InterfaceVersionCheck(dwQueryVer,VER_##Interface)))\
//return static_cast<Interface *>(this);
//
//#define QUERYINTERFACE_IUNKNOWNEX(BaseInterface,Guid,dwQueryVer)\
//if ((Guid==IID_IUnknownEx)&&(InterfaceVersionCheck(dwQueryVer,VER_IUnknownEx)))\
//return static_cast<IUnknownEx *>(static_cast<BaseInterface *>(this));
//
////��ȡ�ӿں�
//#define GET_MYSELF_INTERFACE(Interface)\
//((Interface *)QueryInterface(IID_##Interface,VER_##Interface))
//
//#define GET_OBJECT_INTERFACE(Object,Interface)\
//((Interface *)Object.QueryInterface(IID_##Interface,VER_##Interface))

#define GET_OBJECTPTR_INTERFACE(pObject,Interface)\
((pObject==NULL)?NULL:((Interface *)pObject->QueryInterface(IID_##Interface,VER_##Interface)))