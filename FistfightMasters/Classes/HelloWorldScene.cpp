#include "HelloWorldScene.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto bg = Sprite::create("images/loading_bg.png");
	bg->setAnchorPoint(Point(0.5f, 0));
	bg->setPosition(D_display.getRightX()-60, D_display.y+12);
	addChild(bg);

	auto bgBar = Sprite::create("images/loading_bar.png");
	bgBar->setPosition(Point(bg->getContentSize().width/2, bg->getContentSize().height/2));
	bgBar->runAction(RepeatForever::create(RotateBy::create(1, 360)));
	bg->addChild(bgBar);

    auto label = Label::create("Wu Qingqing Works", "Marker Felt", 30);
	label->setPositionY(D_display.cy);
	auto action = Sequence::create(
		EaseBackOut::create(MoveTo::create(1, D_display.getCenterPoint())),
		DelayTime::create(1),
        CallFunc::create(
                // lambda
                [&](){
					Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MainMenu::createScene()));
                }  ), NULL
	);
	label->runAction(action);
	addChild(label);
    
    return true;
}
