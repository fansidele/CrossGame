/********************************************************************
	�ļ���: 	TacLabelBMFontLoader.h
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:17
	
	˵��:		
*********************************************************************/
#pragma once

// cocos2d
#include "ccbreader\CCLabelBMFontLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TacLabelBMFontLoader :
	public CCLabelBMFontLoader
{
public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TacLabelBMFontLoader, loader);

	TacLabelBMFontLoader(void);
	virtual ~TacLabelBMFontLoader(void);

	virtual void onHandlePropTypeText(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char* pText, CCBReader * pCCBReader);
};

