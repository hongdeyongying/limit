// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��xml-like�����ļ��Ķ�ȡ��  
// *************************************************

#ifndef CPARAMETERMAP_H_HEADER_INCLUDED_B3F0E558
#define CPARAMETERMAP_H_HEADER_INCLUDED_B3F0E558

#include "mysoft_config.h"
#include "CParamerter.h"

namespace MyConfig {

//##ModelId=4C0C5FF40281
typedef std::map<std::string,CParameter> CParameterMap;

typedef std::vector<CParameter>CParameterVector;

typedef std::map<std::string,CParameterVector> CParameterVectorMap;

} // namespace MyConfig



#endif /* CPARAMETERMAP_H_HEADER_INCLUDED_B3F0E558 */
