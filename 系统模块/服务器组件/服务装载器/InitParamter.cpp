#include "StdAfx.h"
#include "AtlBase.h"
#include "InitParamter.h"

//////////////////////////////////////////////////////////////////////////

//���캯��
CInitParamter::CInitParamter() 
{ 
	InitParamter();
}

//��������
CInitParamter::~CInitParamter()
{
}

//��ʼ��
void CInitParamter::InitParamter()
{
	m_szAccreditID[0]=0;
	m_szCenterServerAddr[0]=0;

	m_wGameUserDBPort=1433;
	m_szGameUserDBAddr[0]=0;
	m_szGameUserDBUser[0]=0;
	m_szGameUserDBPass[0]=0;
	lstrcpyn(m_szGameUserDBName,szGameUserDB,CountArray(m_szGameUserDBName));

	m_wServerInfoDBPort=1433;
	m_szServerInfoDBAddr[0]=0;
	m_szServerInfoDBUser[0]=0;
	m_szServerInfoDBPass[0]=0;
	lstrcpyn(m_szServerInfoDBName,szServerInfoDB,CountArray(m_szServerInfoDBName));

	return;
}

//��������
void CInitParamter::LoadInitParamter()
{
	//��ʼ������
	InitParamter();

	//��ע���
	CRegKey RegParamter;
	TCHAR szRegName[MAX_PATH];
	_snwprintf(szRegName, sizeof(szRegName), TEXT("Software\\%s\\ServiceLoader"), g_szSystemRegKey);
	if (RegParamter.Open(HKEY_CURRENT_USER,szRegName,KEY_READ)!=ERROR_SUCCESS) return;

	//��������
	TCHAR szReadData[1024]=TEXT("");
	DWORD dwDataType,dwReadData,dwDataSize;

	//���ķ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    LONG lErrorCode = RegParamter.QueryValue(TEXT("CenterServerAddr"), &dwDataType, m_szCenterServerAddr, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szCenterServerAddr,sizeof(m_szCenterServerAddr));

	//��Ȩ����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("AccreditID"), &dwDataType, m_szAccreditID, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szAccreditID,sizeof(m_szAccreditID));

	//���ݿ�˿�
	dwDataSize=sizeof(dwReadData);
	lErrorCode=RegParamter.QueryValue(TEXT("GameUserDBPort"),&dwDataType,&dwReadData,&dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
        m_wGameUserDBPort=(WORD)dwReadData;

	//���ݿ��ַ
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("GameUserDBAddr"), &dwDataType, m_szGameUserDBAddr, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szGameUserDBAddr,sizeof(m_szGameUserDBAddr));

	//���ݿ��û���
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("GameUserDBUser"), &dwDataType, m_szGameUserDBUser, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szGameUserDBUser,sizeof(m_szGameUserDBUser));

	//���ݿ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("GameUserDBPass"), &dwDataType, m_szGameUserDBPass, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szGameUserDBPass,sizeof(m_szGameUserDBPass));

	//���ݿ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("GameUserDBName"), &dwDataType, m_szGameUserDBName, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szGameUserDBName,sizeof(m_szGameUserDBName));

	//���ݿ�˿�
	dwDataSize=sizeof(dwReadData);
	lErrorCode=RegParamter.QueryValue(TEXT("ServerInfoDBPort"),&dwDataType,&dwReadData,&dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
        m_wServerInfoDBPort=(WORD)dwReadData;

	//���ݿ��ַ
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerInfoDBAddr"), &dwDataType, m_szServerInfoDBAddr, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szServerInfoDBAddr,sizeof(m_szServerInfoDBAddr));

	//���ݿ��û���
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerInfoDBUser"), &dwDataType, m_szServerInfoDBUser, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szServerInfoDBUser,sizeof(m_szServerInfoDBUser));

	//���ݿ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerInfoDBPass"), &dwDataType, m_szServerInfoDBPass, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szServerInfoDBPass,sizeof(m_szServerInfoDBPass));

	//���ݿ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerInfoDBName"), &dwDataType, m_szServerInfoDBName, &dwDataSize);
	//if (lErrorCode==ERROR_SUCCESS) 
    //    CXOREncrypt::CrevasseData(szReadData,m_szServerInfoDBName,sizeof(m_szServerInfoDBName));

	return;
}

//��������
void CInitParamter::SaveInitParamter(bool bSaveAll)
{
	//��ע���
	CRegKey RegParamter;
	TCHAR szRegName[MAX_PATH];
	_snwprintf(szRegName, sizeof(szRegName), TEXT("Software\\%s\\ServiceLoader"), g_szSystemRegKey);
	if (RegParamter.Create(HKEY_CURRENT_USER,szRegName)!=ERROR_SUCCESS) return;

	//��������
	TCHAR szWriteBuffer[1024]=TEXT("");

	//���ķ�����
	//CXOREncrypt::EncryptData(m_szCenterServerAddr,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szCenterServerAddr, TEXT("CenterServerAddr"));

	//��Ȩ����
	//CXOREncrypt::EncryptData(m_szAccreditID,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szAccreditID, TEXT("AccreditID"));

	//��¼���ݿ�
	RegParamter.SetDWORDValue(TEXT("GameUserDBPort"),m_wGameUserDBPort);
	//CXOREncrypt::EncryptData(m_szGameUserDBAddr,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szGameUserDBAddr, TEXT("GameUserDBAddr"));
	//CXOREncrypt::EncryptData(m_szGameUserDBUser,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szGameUserDBUser, TEXT("GameUserDBUser"));
	//CXOREncrypt::EncryptData(m_szGameUserDBPass,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szGameUserDBPass, TEXT("GameUserDBPass"));

	//�������ݿ�
	RegParamter.SetDWORDValue(TEXT("ServerInfoDBPort"),m_wServerInfoDBPort);
	//CXOREncrypt::EncryptData(m_szServerInfoDBAddr,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szServerInfoDBAddr, TEXT("ServerInfoDBAddr"));
	//CXOREncrypt::EncryptData(m_szServerInfoDBUser,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szServerInfoDBUser, TEXT("ServerInfoDBUser"));
	//CXOREncrypt::EncryptData(m_szServerInfoDBPass,szWriteBuffer,sizeof(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szServerInfoDBPass, TEXT("ServerInfoDBPass"));

	if (bSaveAll==true)
	{
		//��¼���ݿ�
		//CXOREncrypt::EncryptData(m_szServerInfoDBName,szWriteBuffer,sizeof(szWriteBuffer));
        RegParamter.SetKeyValue(TEXT(""), m_szServerInfoDBName, TEXT("ServerInfoDBName"));
	}

	return;
}

//////////////////////////////////////////////////////////////////////////
