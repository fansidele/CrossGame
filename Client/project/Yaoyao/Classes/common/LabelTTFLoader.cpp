/********************************************************************
	�ļ���: 	TacLabelTTFLoader.cpp
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:18
	
	˵��:		
*********************************************************************/
// project
#include "Base\TacConfig.h"
#include "Base\TacLabelTTFLoader.h"
#include "Base\TacLanguageMan.h"

#define PROPERTY_STRING "string"

TacLabelTTFLoader::TacLabelTTFLoader(void)
{
}

TacLabelTTFLoader::~TacLabelTTFLoader(void)
{
}

void TacLabelTTFLoader::onHandlePropTypeText(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pText, CCBReader * pCCBReader)
{
	if(strcmp(pPropertyName, PROPERTY_STRING) == 0) 
	{
		// ������Ҫ����Ĭ�ϵ�Ӣ�İ�����ϵͳ��Ӧ���Եİ汾
		((CCLabelTTF *)pNode)->setString(TacLanguageMan::instance().findTxt(pText).c_str());
	} 
	else 
	{
		CCNodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, pCCBReader);
	}
}