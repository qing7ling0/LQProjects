#include "ListViewTest.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/DictionaryHelper.h"
#include <fstream>
#include <iostream>

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace cocostudio;

Scene* ListViewTest::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ListViewTest::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

ListViewTest::ListViewTest(void)
	: _listView(nullptr)
{
}

ListViewTest::~ListViewTest(void)
{
	CC_SAFE_RELEASE(_listView);
}

// on "init" you need to initialize your instance
bool ListViewTest::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(ListViewTest::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

	auto _layout = Layout::create();
	_layout->setSize(visibleSize);
	_layout->setBackGroundColorType(LayoutBackGroundColorType::LAYOUT_COLOR_SOLID);
	_layout->setBackGroundColor(Color3B(0x46,0x75,0));
	addChild(_layout);

	_listView = ListView::create();
    _listView->setDirection(SCROLLVIEW_DIR_VERTICAL);
	_listView->setGravity(ListViewGravity::LISTVIEW_GRAVITY_LEFT);
    _listView->setBounceEnabled(true);
	_listView->setSize(Size(visibleSize)-Size(20,20));
	_listView->setPosition(origin+Point(10,10));
	_listView->setItemsMargin(10);
	_layout->addChild(_listView);
	
	CC_SAFE_RETAIN(_listView);

	_itemDatas.reserve(20);
    return true;
}

void ListViewTest::onEnter()
{
	Layer::onEnter();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(s_listIcosPlist);

	readListItemDatas(_itemDatas, s_listsJson);

	_listView->removeAllItems();

	for(auto &item : _itemDatas)
	{
		auto listItem = createListItem(item->imageName, item->contentStr);
		_listView->pushBackCustomItem(listItem);
	}
}

void ListViewTest::onExit()
{
	Layer::onExit();
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile(s_listIcosPlist);
}


void ListViewTest::readListItemDatas(Vector<ItemData*> &datas, const std::string &fileName)
{
	std::string jsonpath;
	rapidjson::Document jsonDict;
    jsonpath = CCFileUtils::getInstance()->fullPathForFilename(fileName);
    std::string _content = FileUtils::getInstance()->getStringFromFile(jsonpath);
	jsonDict.Parse<0>(_content.c_str());

	int itemCount = DictionaryHelper::getInstance()->getArrayCount_json(jsonDict, "lists");
    
    for (int i=0; i<itemCount; i++)
    {
        const rapidjson::Value& itemData = DictionaryHelper::getInstance()->getDictionaryFromArray_json(jsonDict, "lists", i);
		auto data = ItemData::create(DICTOOL->getStringValue_json(itemData, "image"), DICTOOL->getStringValue_json(itemData, "content"));
		if (data)
		{
			datas.pushBack(data);
		}
    }
}

Layout* ListViewTest::createListItem(const std::string &imageID, const std::string &itemStr)
{
	// 九宫格最小Size
	Size minSize(40,20);

	// 列表最大宽度
	float maxW = _listView->getSize().width-140;

	auto layout = Layout::create();

	// 头像
	const char* path = String::createWithFormat("images/%s.jpg", imageID.c_str())->getCString();
	auto avatar = Sprite::create(path);
	avatar->setAnchorPoint(Point(0, 1));
	avatar->setPosition(Point(5, 0));
	layout->addChild(avatar);

	// 九宫格背景
	auto bg = Scale9Sprite::createWithSpriteFrameName(s_listBg);
	bg->setPositionX(125);
	bg->setAnchorPoint(Point(0, 1));

	// 箭头
	auto arrow = Sprite::createWithSpriteFrameName(s_listArrow);
	arrow->setAnchorPoint(Point(1, 1));
	arrow->setPositionX(2);
	bg->addChild(arrow);

	// 信息内容
	auto contentLable = Label::createWithTTF(itemStr, "fonts/Marker Felt.ttf", 25, Size(0, 0), TextHAlignment::LEFT, TextVAlignment::TOP);
	contentLable->setSystemFontSize(25);
    contentLable->setSystemFontName("fonts/Marker Felt.ttf");
	contentLable->setColor(Color3B(0,0,0));
	contentLable->ignoreAnchorPointForPosition(true);
	contentLable->setPosition(Point(5, 5));
	bg->addChild(contentLable);

	// 现获取没有换行的宽度
	float tempW = contentLable->getContentSize().width;
	// 再根据宽度来换行
	contentLable->setDimensions(maxW, 0);
	// 获取换行后的大小
	Size tempSize = contentLable->getContentSize();
	
	if (tempSize.width > tempW) tempSize.width = tempW;
	if (tempSize.width < minSize.width) tempSize.width = minSize.width;
	if (tempSize.height < minSize.height) tempSize.height = minSize.height;

	bg->setContentSize(tempSize+Size(10, 10));
	tempSize = bg->getContentSize();
	arrow->setPositionY(tempSize.height-5);

	if (tempSize.height < 90) tempSize.height = 90;
	bg->setPositionY(tempSize.height);
	avatar->setPositionY(tempSize.height);

	layout->addChild(bg);
	layout->setSize(tempSize);

	return layout;
}


void ListViewTest::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
