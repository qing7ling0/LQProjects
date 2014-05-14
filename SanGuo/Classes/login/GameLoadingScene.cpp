#include "GameLoadingScene.h"
#include "CCSHead.h"
#include "battle\BattleScene.h"
#include "LoginScene.h"

GameLoading::~GameLoading()
{
	CC_SAFE_RELEASE(_res);
	CC_SAFE_DELETE(_lastUpdate);
}

bool GameLoading::init()
{
	if (Layer::init())
	{
		loginUI = NodeGrid::create(); 
		//��UILayer����뵽��ǰ�ĳ��� 
		this->addChild(loginUI); 
		Layout *m_pWidget = dynamic_cast<Layout*>(cocostudio::GUIReader::shareReader()->widgetFromJsonFile("login_1.json"));
		loginUI->addChild(m_pWidget);

		startBtn = dynamic_cast<Button*> (Helper::seekWidgetByName(m_pWidget, "btn_start"));

		startBtn->setPressedActionEnabled(true);
		startBtn->setBright(true);

		startBtn->addTouchEventListener(this, SEL_TouchEvent(&GameLoading::startGameTouchListener));

		this->schedule(schedule_selector(GameLoading::doing), 0.0f, kRepeatForever, 1);

		_res = new CommonRes();
		_res->load();

		_waveAction = WaterWaveAction::create(10000, Size(200, 200));
		loginUI->runAction(_waveAction);
		
		_lastUpdate = new struct timeval;
		
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
		setTouchEnabled(true);

		return true;
	}

	return false;
}

void GameLoading::dropStone(const Point& position)
{
	if (_waveAction)
	{
		_waveAction->dropStone(position.x/5.12f, position.y/5.12f,  RANDOM_0_TO(10)+5);
	}
}

bool GameLoading::onTouchBegan(Touch *touch, Event *unused_event)
{
	dropStone(touch->getLocation());

	return true;
}

void GameLoading::onTouchMoved(Touch *touch, Event *unused_event)
{
	struct timeval now;

    if (gettimeofday(&now, nullptr) != 0)
    {
        return;
    }

    long _deltaTime = (now.tv_sec - _lastUpdate->tv_sec)*1000 + (now.tv_usec - _lastUpdate->tv_usec)/1000;
	if (_deltaTime > 100)
	{
		dropStone(touch->getLocation());
		*_lastUpdate = now;
	}
} 

void GameLoading::onEnter()
{
	Layer::onEnter();

	startBtn->setVisible(false);
}

void GameLoading::doing(float dt)
{
	if (_res && _res->loadProgress()>=1 && !startBtn->isVisible())
	{
		auto *action = ScaleTo::create(0.5f, 1, 1);
		auto *action2 = EaseBounceInOut::create(action);

		startBtn->setVisible(true);
		startBtn->setScale(0.5f);
		startBtn->runAction(action2);
	}
}

void GameLoading::startGameTouchListener(Object* pSender, int eventType)
{
	// ����ɹ�
	if (eventType == TOUCH_EVENT_ENDED)
	{
		/*startBtn->setColor(Color3B::WHITE);
		startBtn->setScale(1);*/
		Scene *sc = LoginScene::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(1, sc));
	}
}

void GameLoading::loadingFinsih(float dt)
{
}