/********************************************************************
	�ļ���: 	TacNodeLoaderLibrary.cpp
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:18
	
	˵��:		
*********************************************************************/
//project
#include "NodeLoaderLibrary.h"
#include "LabelBMFontLoader.h"
#include "LabelTTFLoader.h"
#include "ControlButtonLoader.h"

namespace walkbin
{
    NodeLoaderLibrary::NodeLoaderLibrary(void)
    {
    }


    NodeLoaderLibrary::~NodeLoaderLibrary(void)
    {
    }

    void NodeLoaderLibrary::registerDefaultCCNodeLoaders()
    {
        registerCCNodeLoader("CCLabelTTF", LabelTTFLoader::loader());
        registerCCNodeLoader("CCLabelBMFont", LabelBMFontLoader::loader());
        registerCCNodeLoader("CCControlButton", ControlButtonLoader::loader());
        CCNodeLoaderLibrary::registerDefaultCCNodeLoaders();
    }

    NodeLoaderLibrary * NodeLoaderLibrary::newDefaultCCNodeLoaderLibrary() 
    {
        NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::library();
        ccNodeLoaderLibrary->registerDefaultCCNodeLoaders();
        return ccNodeLoaderLibrary;
    }
}