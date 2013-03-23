/********************************************************************
	Copyright (c) 2012-2013 walkbin.com

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.

	created:	2013/03/23
	filename: 	BaseScene.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "BaseScene.h"

USING_NS_CC;

namespace walkbin
{
    BaseScene *BaseScene::create()
    {
        BaseScene *pRet = new BaseScene();
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            CC_SAFE_RELEASE(pRet);
            return NULL;
        }
    }

    BaseScene::BaseScene()
    {

    }

    BaseScene::~BaseScene()
    {
    }

    bool BaseScene::init()
    {
        if(!CCScene::init())
            return false;

        this->scheduleUpdate();
        return true;
    }

    void BaseScene::update(float dt)
    {
        CCScene::update(dt);
    }
}