/********************************************************************
	�ļ���: 	TacLanguageMan.cpp
	����:		chuckey.tang
	����ʱ��:	12:12:2012   19:18
	
	˵��:		
*********************************************************************/
//project
#include "Base/TacLanguageMan.h"

// libxml2
#include <libxml/parser.h>

// cocos2d
#include "platform/CCFileUtils.h"

TacLanguageMan::TacLanguageMan(void)
	:m_nCurLanguage(TacLangEn)
{
}

TacLanguageMan::~TacLanguageMan(void)
{
}

bool TacLanguageMan::init(int curLan)
{
	m_nCurLanguage = curLan;
	xmlDocPtr doc;   //��������ĵ�ָ��
	xmlNodePtr curNode;  //������ָ��(����Ҫ��Ϊ���ڸ��������ƶ�)
	std::string str = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename("nf_conf_language.xml");
	unsigned long size = 0;
	unsigned char* pBuffer = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(str.c_str(),"rb",&size);
	if(!pBuffer)
		return false;

	doc = xmlReadMemory((const char*)pBuffer,size,str.c_str(), "utf-8", 256);
	if (NULL == doc)
	{  
		CC_SAFE_FREE(pBuffer);
		return false; 
	}

	curNode = xmlDocGetRootElement(doc); //ȷ���ĵ���Ԫ��

	if (NULL == curNode)
	{ 
		//���ڵ㲻��ȷ
		CC_SAFE_FREE(pBuffer);
		xmlFreeDoc(doc);
		return false;
	}

	if (xmlStrcmp(curNode->name, BAD_CAST"Lanuage"))			//������Ľ���
	{
		//���ò���ȷ
		CC_SAFE_FREE(pBuffer);
		xmlFreeDoc(doc);
		return false;
	}

	curNode = curNode->xmlChildrenNode;
	std::map<int, std::string> txtItem;

	while(curNode != NULL)
	{
		//ȡ���ڵ��е�����
		if ((xmlStrcmp(curNode->name, BAD_CAST"Txt")))
		{
			curNode = curNode->next;
			continue;
		}

		xmlNodePtr propNodePtr = curNode;
		int id = atoi((const char*)xmlGetProp(propNodePtr,BAD_CAST"id"));
		if (xmlHasProp(propNodePtr,BAD_CAST"id"))
		{
			m_mapLanguages[id] = txtItem;
		}
		else
		{
			CC_SAFE_FREE(pBuffer);
			//����Ҫ�еĲ���
			xmlFreeDoc(doc);
			return false;
		}

		if (xmlHasProp(propNodePtr,BAD_CAST"english"))
		{
			m_mapLanguages[id][TacLangEn] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"english");
		}

		if (xmlHasProp(propNodePtr,BAD_CAST"chinese"))
		{
			m_mapLanguages[id][TacLangCh] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"chinese");
		}

		if (xmlHasProp(propNodePtr,BAD_CAST"japanese"))
		{
			m_mapLanguages[id][TacLangJp] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"japanese");
		}

		curNode = curNode->next;
	}

	CC_SAFE_FREE(pBuffer);
	xmlFreeDoc(doc);
	return true;
}

std::string TacLanguageMan::findTxt(int id)
{
	return findTxt(id, m_nCurLanguage);
}

std::string TacLanguageMan::findTxt(std::string englishTxt)
{
	return findTxt(englishTxt, m_nCurLanguage);
}

std::string TacLanguageMan::findTxt(int id, int language)
{
	NFLanMap::iterator i = m_mapLanguages.find(id);
	if(i == m_mapLanguages.end())
		return "";

	if(!isLangSupported(language))
		return "";

	return (i->second.find(language))->second;
}

std::string TacLanguageMan::findTxt(std::string englishTxt, int language)
{
	// �ȼ򵥲��ң��Ⱥ����Ż� !!! #issue 00001
	for(NFLanMap::iterator i=m_mapLanguages.begin(); i!=m_mapLanguages.end(); i++)
	{
		if(englishTxt == i->second.find(TacLangEn)->second)
			return i->second.find(language)->second;
	}
	return "";
}

bool TacLanguageMan::isLangSupported(int language) const
{
	// ��������֧��
	if(language < TacLangEn || language >= TacLangNum)
		return false;
	return true;
}