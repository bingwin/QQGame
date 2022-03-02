#include "StdAfx.h"
#include "AtlBase.h"
#include "InitParamter.h"

//////////////////////////////////////////////////////////////////////////

CInitParamter::CInitParamter() 
{ 
	InitParamter();
}

CInitParamter::~CInitParamter()
{
}

//��ʼ��
void CInitParamter::InitParamter()
{
	//��������
	m_wMaxConnect=512;
	m_wListenPort=PORT_CENTER_SERVER;

	//��Ϣ���ݿ�
	m_wServerDataBasePort=1433;
	m_szServerDataBaseAddr[0]=0;
	m_szServerDataBaseUser[0]=0;
	m_szServerDataBasePass[0]=0;
	lstrcpyn(m_szServerDataBaseName,
				szServerInfoDB,
				CountArray(m_szServerDataBaseName));

	return ;
}

//��������
void CInitParamter::LoadInitParamter()
{
	//��ʼ������
	InitParamter();

	//��ע���
	CRegKey RegParamter;
	TCHAR szRegName[MAX_PATH];
	_snwprintf(szRegName,
				sizeof(szRegName),
				TEXT("Software\\%s\\CenterServer"),
				g_szSystemRegKey);
	if (RegParamter.Open(HKEY_CURRENT_USER,szRegName,KEY_READ)!=ERROR_SUCCESS) 
	{
		return ;
	}

	//��������
	TCHAR szReadData[1024]=TEXT("");
	DWORD dwDataType,dwReadData,dwDataSize;

	//�������
	dwDataSize=sizeof(dwReadData);
	LONG lErrorCode = RegParamter.QueryValue(TEXT("MaxConnect"),&dwDataType,&dwReadData,&dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
	{
		m_wMaxConnect=(WORD)dwReadData;
	}

	//�����˿�
	dwDataSize=sizeof(dwReadData);
	lErrorCode=RegParamter.QueryValue(TEXT("ListenPort"),&dwDataType,&dwReadData,&dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
	{
		m_wListenPort=(WORD)dwReadData;
	}

	//���ݿ�˿�
	dwDataSize=sizeof(dwReadData);
	lErrorCode=RegParamter.QueryValue(TEXT("ServerDataBasePort"),&dwDataType,&dwReadData,&dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
	{
		m_wServerDataBasePort=(WORD)dwReadData;
	}

	//���ݿ��ַ
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerDataBaseAddr"), &dwDataType, m_szServerDataBaseAddr, &dwDataSize);
	if (lErrorCode==ERROR_SUCCESS)
	{
		//CXOREncrypt::CrevasseData(szReadData,m_szServerDataBaseAddr, ARRAYSIZE(m_szServerDataBaseAddr));
	}

	//���ݿ��û���
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerDataBaseUser"), &dwDataType, m_szServerDataBaseUser, &dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
	{
		//CXOREncrypt::CrevasseData(szReadData,m_szServerDataBaseUser, ARRAYSIZE(m_szServerDataBaseUser));
	}

	//���ݿ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerDataBasePass"), &dwDataType, m_szServerDataBasePass, &dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
	{
		//CXOREncrypt::CrevasseData(szReadData,m_szServerDataBasePass, ARRAYSIZE(m_szServerDataBasePass));
	}

	//���ݿ�����
	szReadData[0]=0;
	dwDataSize=sizeof(szReadData);
    lErrorCode = RegParamter.QueryValue(TEXT("ServerDataBaseName"), &dwDataType, m_szServerDataBaseName, &dwDataSize);
	if (lErrorCode==ERROR_SUCCESS) 
	{
		//CXOREncrypt::CrevasseData(szReadData,m_szServerDataBaseName, ARRAYSIZE(m_szServerDataBaseName));
	}

	return;
}

//��������
void CInitParamter::SaveInitParamter(bool bSaveAll)
{
	//��ע���
	CRegKey RegParamter;
	TCHAR szRegName[MAX_PATH];
	_snwprintf(szRegName, sizeof(szRegName), TEXT("Software\\%s\\CenterServer"), g_szSystemRegKey);
	if (RegParamter.Create(HKEY_CURRENT_USER,szRegName)!=ERROR_SUCCESS) return;

	//��������
	TCHAR szWriteBuffer[1024]=TEXT("");

    //���ܺͽ��ܺ����ڴ�char���wchar_tʱ���ܷ���ƥ���ˣ����Ҳ��ӽ�����, by zhangyl
	//��Ϣ���ݿ�
	RegParamter.SetDWORDValue(TEXT("ServerDataBasePort"),m_wServerDataBasePort);
	//CXOREncrypt::EncryptData(m_szServerDataBaseAddr,szWriteBuffer,ARRAYSIZE(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szServerDataBaseAddr, TEXT("ServerDataBaseAddr"));
	//CXOREncrypt::EncryptData(m_szServerDataBaseUser,szWriteBuffer, ARRAYSIZE(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szServerDataBaseUser, TEXT("ServerDataBaseUser"));
	//CXOREncrypt::EncryptData(m_szServerDataBasePass,szWriteBuffer, ARRAYSIZE(szWriteBuffer));
    RegParamter.SetKeyValue(TEXT(""), m_szServerDataBasePass, TEXT("ServerDataBasePass"));

	if (bSaveAll==true)
	{
		//��������
		RegParamter.SetDWORDValue(TEXT("MaxConnect"),m_wMaxConnect);
		RegParamter.SetDWORDValue(TEXT("ListenPort"),m_wListenPort);

		//��Ϣ���ݿ�
		//CXOREncrypt::EncryptData(m_szServerDataBaseName,szWriteBuffer, ARRAYSIZE(szWriteBuffer));
        RegParamter.SetKeyValue(TEXT(""), m_szServerDataBaseName, TEXT("ServerDataBaseName"));
	}

	return;
}

//////////////////////////////////////////////////////////////////////////
