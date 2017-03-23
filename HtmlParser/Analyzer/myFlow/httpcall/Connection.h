// Connection.h: interface for the CConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTION_H__E442EAA1_24A8_4A28_9ECC_A4CBF42446F8__INCLUDED_)
#define AFX_CONNECTION_H__E442EAA1_24A8_4A28_9ECC_A4CBF42446F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "openssl/bio.h"
#include "openssl/err.h"
#include "openssl/rand.h"
#include "openssl/ssl.h"
#include "openssl/x509v3.h"

enum CONNECTION_FLAG{
	HTTP,
	HTTPS_NO_VALID,
	HTTPS_SERVER_VALID,
	HTTPS_BOTH_VALID
};

class CConnection  
{
private:
	BOOL OpenHttpsCheckBoth(const char * host,short port,const char * root_cert_file_path,const char *cert_file_path,const char * pwd);
	OpenHttpsCheckServer(const char * host,short port,const char * root_cert_file_path = NULL);
	BOOL OpenHttpsWithoutCheck(const char * host,short port);
	BOOL OpenHttp(const char * host ,short port);
	BOOL InitOpenssl(void);
	BOOL PostConnectionServerCheck(const char * host);

	BIO *conn;
	SSL *ssl;
	SSL_CTX *ctx;

	BOOL m_bOpened;
	int m_iState;
public:
	

	int Read(char * szRes,int size);
	int Send(const char * szReq,int size);
	void Close();
	BOOL Open(const char * host,short port,short flag=HTTP,const char * root_cert_file_path = NULL,const char * cert_file_path=NULL,const char * pwd=NULL);
	CConnection();
	virtual ~CConnection();

};

#endif // !defined(AFX_CONNECTION_H__E442EAA1_24A8_4A28_9ECC_A4CBF42446F8__INCLUDED_)
