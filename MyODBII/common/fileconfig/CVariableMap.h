// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��xml-like�����ļ��Ķ�ȡ��  
// *************************************************

#ifndef CVARIABLEMAP_H_HEADER_INCLUDED_B3F0C1D9
#define CVARIABLEMAP_H_HEADER_INCLUDED_B3F0C1D9

#include "mysoft_config.h"
#include "CVariable.h"

namespace MyConfig {

//##ModelId=4C0C5F700221
typedef std::map<std::string,CVariable> CVariableMap;

typedef std::vector<CVariable>CVariableVector;

typedef std::map<std::string,CVariableVector> CVariableVectorMap;

} // namespace MyConfig



#endif /* CVARIABLEMAP_H_HEADER_INCLUDED_B3F0C1D9 */
