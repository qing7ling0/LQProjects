#include "SGLauncher.h"
#include "QConfig.h"
#include "LauncherScene.h"

USING_NS_CC;

SGLauncher::SGLauncher(void) : GameLauncher()
{
}

SGLauncher::~SGLauncher(void)
{
}

void SGLauncher::create(void)
{
	new SGLauncher();
}

void SGLauncher::onLoad()
{
	GameLauncher::onLoad();

    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
	
    // turn on display FPS
	director->setDisplayStats(FPS_SHOW);

    // set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / FPS);

	eglView->setDesignResolutionSize(SCREEN_WIDTH, SCREEN_HEIGHT, kResolutionShowAll);

    // create a scene. it's an autorelease object
	for(int i=0; i<PATH_COUNT; i++)
	{
		FileUtils::getInstance()->addSearchPath(CONFIG_PATHS[i]);
	}
	
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	
	D_display.x = origin.x;
	D_display.y = origin.y;
	D_display.w = visibleSize.width;
	D_display.h = visibleSize.height;
	D_display.cx = D_display.x + D_display.w/2;
	D_display.cy = D_display.y + D_display.h/2;

	Director::getInstance()->runWithScene(LauncherLayer::createScene());
}

void SGLauncher::onDispose(void)
{
	GameLauncher::onDispose();
}
