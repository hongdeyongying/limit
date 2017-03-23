#ifndef CODBIIRAWDATA_H_HEADER_INCLUDED_B1C4E470
#define CODBIIRAWDATA_H_HEADER_INCLUDED_B1C4E470

#include <string>


//##ModelId=4E380DAC035B
class CODBIIRawdata
{
  public:
	  void Clear();
    //##ModelId=4E3B31FA00F8
    CODBIIRawdata();
    CODBIIRawdata(const std::string & req)
	{
		Clear();
		m_sReq= req;
	};

    //##ModelId=4E3B31FA0107
    virtual ~CODBIIRawdata();

    //##ModelId=4E38113E01A4
    unsigned int m_uID;

    //##ModelId=4E380F9D03B6
    int m_iStatus;

    //##ModelId=4E380F62009B
    unsigned int m_uReqTime;	//系统时间戳

    //##ModelId=4E3B322402F5
    unsigned int m_uSpendTime;  // 消耗的时间，以毫秒计算

    //##ModelId=4E380FA702BC
    std::string m_sReq;

    //##ModelId=4E380FAE02D0
    std::string m_sRes;

};



#endif /* CODBIIRAWDATA_H_HEADER_INCLUDED_B1C4E470 */
