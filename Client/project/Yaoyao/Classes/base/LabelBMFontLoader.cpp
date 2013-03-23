/********************************************************************
	�ļ���: 	TacLabelBMFontLoader.cpp
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:18
	
	˵��:		
*********************************************************************/
// project
#include "Base\TacConfig.h"
#include "Base\TacLabelBMFontLoader.h"
#include "Base\TacLanguageMan.h"

#define PROPERTY_STRING "string"

TacLabelBMFontLoader::TacLabelBMFontLoader(void)
{
}

TacLabelBMFontLoader::~TacLabelBMFontLoader(void)
{
}

void TacLabelBMFontLoader::onHandlePropTypeText(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char* pText, CCBReader * pCCBReader) {
	if(strcmp(pPropertyName, PROPERTY_STRING) == 0) {
		((CCLabelBMFont *)pNode)->setString(LangMgr::instance().findTxt(pText).c_str());
	} else {
		CCNodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, pCCBReader);
	}
}