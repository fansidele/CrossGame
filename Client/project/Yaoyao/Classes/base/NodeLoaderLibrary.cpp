/********************************************************************
	�ļ���: 	TacNodeLoaderLibrary.cpp
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:18
	
	˵��:		
*********************************************************************/
#include "NodeLoaderLibrary.h"
#include "LabelBMFontLoader.h"
#include "LabelTTFLoader.h"
#include "ControlButtonLoader.h"

//project view
#include "view/LayerLogo.h"
#include "view/LayerLoading.h"

NS_WALKBIN_BEGIN

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

    //project
    registerCCNodeLoader("logolayer",LayerLogoLoader::loader());
    registerCCNodeLoader("loadinglayer",LayerLoadingLoader::loader());
    
    CCNodeLoaderLibrary::registerDefaultCCNodeLoaders();
}

NodeLoaderLibrary * NodeLoaderLibrary::newDefaultCCNodeLoaderLibrary() 
{
    NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::library();
    ccNodeLoaderLibrary->registerDefaultCCNodeLoaders();
    return ccNodeLoaderLibrary;
}

NS_WALKBIN_END