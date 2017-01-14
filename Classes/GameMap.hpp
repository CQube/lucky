#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "cocos2d.h"

using namespace cocos2d;

class GameMap : public cocos2d::Layer
{
private:
	CCTMXTiledMap *_tileMap;
	CCTMXLayer *_background;
	
public:
	CREATE_FUNC(GameMap);
	
	virtual bool init();
	static CCScene* createScene();
};

#endif //_MAP_HPP_
