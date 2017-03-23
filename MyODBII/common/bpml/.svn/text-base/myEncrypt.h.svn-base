#ifndef MYUTILITY_MYENCRYPT_H
#define MYUTILITY_MYENCRYPT_H

#include <openssl/evp.h>
#include <openssl/sha.h>
#include "openssl/md5.h"


#include "openssl/des.h"

class CMyEncrypt
{ 
public:
	static string &md5(const string &in, string &out)
	{
		char szSign[1024] = {0};

		unsigned char md[MD5_DIGEST_LENGTH];

		char *pszResult = szSign;

		EVP_Digest((void *)in.data(),in.size(),md,NULL,EVP_md5(), NULL);

		for (int i=0; i<MD5_DIGEST_LENGTH; i++)
			snprintf(pszResult+2*i,2,"%02X",md[i]);

		out =  szSign;

		return out;
	}


	static string &Des3(const string &in,const string &key, string &out)
	{
		string inTmp = in;
		string keyTmp = key;

		if(keyTmp.size() == 8)
			return Des(in,key,out);

		else if(keyTmp.size() == 16)
			keyTmp.append(key.data(),8);

		else if(keyTmp.size() < 24)
			keyTmp.append(1,'\0');

		des_key_schedule ks1,ks2,ks3;
                des_cblock 	 desKey,desIV;

                memset(desIV, 0, sizeof(desIV));

                memcpy(desKey, keyTmp.data()+0, sizeof(desKey));
		des_set_key_unchecked(&desKey, ks1);

                memcpy(desKey, keyTmp.data()+8, sizeof(desKey));
		des_set_key_unchecked(&desKey, ks2);

                memcpy(desKey, keyTmp.data()+16, sizeof(desKey));
		des_set_key_unchecked(&desKey, ks3);

                int iBlockCount =  in.size() / sizeof(des_cblock);
                if (in.size() % sizeof(des_cblock) > 0)       iBlockCount++;
                int     iDestLen = iBlockCount * sizeof(des_cblock);

                unsigned char *des = (unsigned  char*)malloc(iDestLen * sizeof(unsigned char));
                memset(des , 0 ,iDestLen);

		des_ede3_cbc_encrypt((const unsigned char *)in.data(), des, in.size(), ks1,ks2,ks3, &desIV, DES_ENCRYPT);

		out.append((const char *)des,iDestLen * sizeof(unsigned char));

		delete []des;

		return out;
	

	}
	static string &UnDes3(const string &in,const string &key, string &out)
	{
		string inTmp = in;
		string keyTmp = key;

		if(keyTmp.size() == 8)
			return UnDes(in,key,out);

		else if(keyTmp.size() == 16)
			keyTmp.append(key.data(),8);

		else if(keyTmp.size() < 24)
			keyTmp.append(1,'\0');

		des_key_schedule ks1,ks2,ks3;
                des_cblock 	 desKey,desIV;

                memset(desIV, 0, sizeof(desIV));

                memcpy(desKey, keyTmp.data()+0, sizeof(desKey));
		des_set_key_unchecked(&desKey, ks1);

                memcpy(desKey, keyTmp.data()+8, sizeof(desKey));
		des_set_key_unchecked(&desKey, ks2);

                memcpy(desKey, keyTmp.data()+16, sizeof(desKey));
		des_set_key_unchecked(&desKey, ks3);

                int iBlockCount =  in.size() / sizeof(des_cblock);
                if (in.size() % sizeof(des_cblock) > 0)       iBlockCount++;
                int     iDestLen = iBlockCount * sizeof(des_cblock);

                unsigned char *des = (unsigned  char*)malloc(iDestLen * sizeof(unsigned char));
                memset(des , 0 ,iDestLen);

		des_ede3_cbc_encrypt((const unsigned char *)in.data(), des, in.size(), ks1,ks2,ks3, &desIV, DES_DECRYPT);

		out.append((const char *)des,iDestLen * sizeof(unsigned char));

		delete []des;

		return out;
	

	}

	static string &Des(const string &in,const string &key, string &out)
	{
		des_key_schedule ks;
                des_cblock 	 desKey,desIV;

		string keyTmp = key;
		while(keyTmp.size() < 8)
			keyTmp.append(1,'\0');
		

                memcpy(desKey, keyTmp.data(), sizeof(desKey));
                memset(desIV, 0, sizeof(desIV));
		/**
  		* 检查key的强度
                switch(des_set_key_checked(&desKey, ks))
                {
                        case -1:
                                DEBUG_LOGER << "DES KEY Bad parity";
                                throw(MyUtility::CMyException("DES KEY Bad parity.",10003006));
                                return 6;
                                break;
                        break;
                        case -2:
                                DEBUG_LOGER << "DES KEY weak";
                                throw(MyUtility::CMyException("DES KEY weak.",10003006));
                                return 6;
                                break;
                        default:
                                // good
                                break;
                }
		**/
		des_set_key_unchecked(&desKey, ks);

                int iBlockCount =  in.size() / sizeof(des_cblock);
                if (in.size() % sizeof(des_cblock) > 0)       iBlockCount++;
                int     iDestLen = iBlockCount * sizeof(des_cblock);

                unsigned char *des = (unsigned  char*)malloc(iDestLen * sizeof(unsigned char));
                memset(des , 0 ,iDestLen);

		des_ncbc_encrypt((const unsigned char *)in.data(), des, in.size(), ks, &desIV, DES_ENCRYPT);

		out.append((const char *)des,iDestLen * sizeof(unsigned char));

		delete []des;

		return out;
	}

	static string &UnDes(const string &in,const string &key, string &out)
	{
		des_key_schedule ks;
                des_cblock 	 desKey,desIV;

		string keyTmp = key;
		while(keyTmp.size() < 8)
			keyTmp.append(1,'\0');

                memcpy(desKey, keyTmp.data(), sizeof(desKey));
                memset(desIV, 0, sizeof(desIV));
		/**
  		* 检查key的强度
                switch(des_set_key_checked(&desKey, ks))
                {
                        case -1:
                                DEBUG_LOGER << "DES KEY Bad parity";
                                throw(MyUtility::CMyException("DES KEY Bad parity.",10003006));
                                return 6;
                                break;
                        break;
                        case -2:
                                DEBUG_LOGER << "DES KEY weak";
                                throw(MyUtility::CMyException("DES KEY weak.",10003006));
                                return 6;
                                break;
                        default:
                                // good
                                break;
                }
		**/
		des_set_key_unchecked(&desKey, ks);

                int iBlockCount =  in.size() / sizeof(des_cblock);
                if (in.size() % sizeof(des_cblock) > 0)       iBlockCount++;
                int     iDestLen = iBlockCount * sizeof(des_cblock);

                unsigned char *des = (unsigned  char*)malloc(iDestLen * sizeof(unsigned char));
                memset(des , 0 ,iDestLen);

		des_ncbc_encrypt((const unsigned char *)in.data(), des, in.size(), ks, &desIV, DES_DECRYPT);

		out.append((const char *)des,iDestLen * sizeof(unsigned char));

		delete []des;

		return out;
	}
};

#endif


