#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include "TestHead.h"
#include "LQResources.h"

class ItemData : public Ref
{
public:
	std::string imageName;
	std::string contentStr;

	static ItemData* create(const std::string &imageName, const std::string &contentStr)
	{
		auto item = new ItemData();
		if (item)
		{
			item->imageName = imageName;
			item->contentStr = contentStr;
		}
		else
		{
			CC_SAFE_DELETE(item);
			item = nullptr;
		}
		return item;
	}
};


class ListViewTest : public cocos2d::Layer
{
public:
	ListViewTest(void);
	~ListViewTest(void);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	virtual void onEnter();

	virtual void onExit();
    
	void readListItemDatas(Vector<ItemData*> &datas, const std::string &fileName);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	Layout* createListItem(const std::string &imageID, const std::string &itemStr);

    // implement the "static create()" method manually
    CREATE_FUNC(ListViewTest);

private:
	Vector<ItemData*> _itemDatas;
	ListView *_listView;
};

#endif // __HELLOWORLD_SCENE_H__
