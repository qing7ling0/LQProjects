#pragma once
#include "RPGHead.h"

class AnimiPlayer : public Layer, public Clonable
{
public:
	AnimiPlayer(void);
	~AnimiPlayer(void);

	virtual bool init(Vector<SpriteFrame*> frames, float delay);

	virtual bool init(Animation *animi);

	virtual Animation* getAnimation() { return _animi; }

	virtual void start(unsigned int loop=0, bool visible=false);

	virtual void resume();

	virtual void pause();

	virtual void stop(bool visible=false);

	virtual unsigned int getLoops();

	virtual bool isOver() const;
	
	virtual AnimiPlayer* clone() const override;

	static AnimiPlayer* create(Vector<SpriteFrame*> frames, float delay=0.05f);

	/** ���Ž������Ƿ������� */
	CC_SYNTHESIZE(bool, overVisible, OverVisible);

	/** �������Ž�������  */
	CC_SYNTHESIZE(std::function<void(AnimiPlayer*)>, _stopEvent, StopEvent);

protected:
	Animation *_animi;

	Sprite *_animiSprite;

};

