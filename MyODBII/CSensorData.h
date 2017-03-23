#ifndef CSENSORDATA_H_HEADER_INCLUDED_B1C0BDA1
#define CSENSORDATA_H_HEADER_INCLUDED_B1C0BDA1

#include <string>
#include <set>
using namespace std;

//##ModelId=4E3F29CE03C8
class CSensorData
{
  public:
	  void SetValue(const string & val);
	  void SetValue(unsigned int val);
	  void SetValue(int val);
	  void SetValue(double val);
    //##ModelId=4E3F2A9B031C
    CSensorData(unsigned int val);
    CSensorData(int val);
    CSensorData(double val);
    CSensorData(){};
    CSensorData(const string & val);
    CSensorData(unsigned int tm,const string &val);

    //##ModelId=4E3F2A9B034B
    virtual ~CSensorData();

    //##ModelId=4E3F29E80286
    unsigned int m_uTime;

    //##ModelId=4E3F29FB0258
    std::string m_sValue;

};

//´íÎóÂë
typedef set<string> CTCDSet;

extern CTCDSet g_objCTCDSet;


#endif /* CSENSORDATA_H_HEADER_INCLUDED_B1C0BDA1 */
