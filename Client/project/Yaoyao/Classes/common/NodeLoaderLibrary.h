/********************************************************************
	�ļ���: 	TacNodeLoaderLibrary.h
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:17
	
	˵��:		
*********************************************************************/
#pragma once

// cocos2d
#include "ccbreader\ccnodeloaderlibrary.h"

USING_NS_CC_EXT;

class TacNodeLoaderLibrary :
	public CCNodeLoaderLibrary
{
public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TacNodeLoaderLibrary, library);
	static TacNodeLoaderLibrary * newDefaultCCNodeLoaderLibrary();

	TacNodeLoaderLibrary(void);
	virtual ~TacNodeLoaderLibrary(void);

	void registerDefaultCCNodeLoaders();
};

