#include "GameMap.hpp"

bool GameMap::init()
{		
	if(!CCLayer::init())
		return false;
/*
	_tileMap = new CCTMXTiledMap();
	_tileMap->initWithTMXFile("../Resources/TileMap.tmx");
	
	this->addChild(_tileMap);
*/
	// create a TMX map
	_tileMap = TMXTiledMap::create("../Resources/maps/TileMap.tmx");
	_background = _tileMap->layerNamed("Background");
	

	this->addChild(_tileMap, 0);
	

	return true;
}

CCScene* GameMap::createScene()
{
	auto *scene = Scene::create();
	auto *layer = GameMap::create();
	scene->addChild(layer);

	return scene;
}


