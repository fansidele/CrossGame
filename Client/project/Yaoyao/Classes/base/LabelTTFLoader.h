/********************************************************************
	�ļ���: 	TacLabelTTFLoader.h
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:17
	
	˵��:		
*********************************************************************/
#pragma once

#include "ccbreader\cclabelttfloader.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TacLabelTTFLoader :
	public CCLabelTTFLoader
{
public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TacLabelTTFLoader, loader);

	TacLabelTTFLoader(void);
	virtual ~TacLabelTTFLoader(void);

	virtual void onHandlePropTypeText(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pText, CCBReader * pCCBReader);
};