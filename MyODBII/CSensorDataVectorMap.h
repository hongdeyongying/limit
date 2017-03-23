#ifndef CSENSORDATAVECTORMAP_H_HEADER_INCLUDED_B1C0B8A2
#define CSENSORDATAVECTORMAP_H_HEADER_INCLUDED_B1C0B8A2


#pragma warning (disable: 4514 4786)

#pragma warning(disable:4786) 
#pragma warning(disable:4530)
#pragma warning(disable:4503)

#include <map>
#include "CSensorDataVector.h"

//##ModelId=4E3F2AF00218
typedef std::map<unsigned int,CSensorDataVector> CSensorDataVectorMap;

typedef std::map<unsigned int,CSensorDataVectorMap> CECUSensorDataVectorMap;


extern CSensorDataVectorMap g_objCSensorDataVectorMap;

extern CECUSensorDataVectorMap g_objCECUSensorDataVectorMap;

extern CECUSensorDataVectorMap g_objCECUSensorDataVectorMap_freeze;
//
typedef std::map<unsigned int ,std::string> CCarInfoMap;
typedef std::map<unsigned int ,CCarInfoMap> CECUCarInfoMap;

extern CECUCarInfoMap g_objCECUCarInfoMap;


#endif /* CSENSORDATAVECTORMAP_H_HEADER_INCLUDED_B1C0B8A2 */
