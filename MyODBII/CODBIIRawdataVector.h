#ifndef CODBIIRAWDATAVECTOR_H_HEADER_INCLUDED_B1C48313
#define CODBIIRAWDATAVECTOR_H_HEADER_INCLUDED_B1C48313

#include <vector>
#include "CODBIIRawdata.h"

#include "afxmt.h"

//##ModelId=4E381189034E
typedef std::vector<CODBIIRawdata> CODBIIRawdataVector;

	#ifndef CODBIIRAWDATAVECTOR_CPP_HEADER_INCLUDED_B1C48313

		extern CODBIIRawdataVector g_objCODBIIRawdataVector;

		extern CODBIIRawdataVector g_cmdCODBIIRawdataVector;		

		extern CMutex  g_mutexCODBIIRawdata;

		class CODBIIRawdataVectorSection
		{
		public:
			CODBIIRawdataVectorSection(int iSec)
			{
				g_mutexCODBIIRawdata.Lock(iSec);
			};

			virtual ~CODBIIRawdataVectorSection()
			{
				g_mutexCODBIIRawdata.Unlock();
			};
		};
	#endif


#endif /* CODBIIRAWDATAVECTOR_H_HEADER_INCLUDED_B1C48313 */
