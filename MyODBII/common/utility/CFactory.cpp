// author      :  gaussgao
// create date :  2011-03-02
// modify date :  2011-03-02
// descriptor  :  qzone feeds format dll  
#include "CFactory.h"

namespace MyUtility {

// 全局变量
//typedef std::map<std::string,void*(*)()>  CStringMethodMap;
//typedef std::map<std::string,void*> CStringInstanceMap;
//typedef std::map<std::string,CStringMethodMap> CStringCStringMethodMapMap;
//typedef std::map<std::string,CStringInstanceMap> CStringCStringInstanceMapMap;

CStringCStringMethodMapMap g_mmMethod;
CStringCStringInstanceMapMap g_mmInstance;

};//namespace MyUtility {



