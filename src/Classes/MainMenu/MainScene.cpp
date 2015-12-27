#include "MainScene.h"
#include <Game/GameScene.h>

#include <iostream>

#include"cocostudio/CocoStudio.h" 

using namespace SpaceFighter;
using namespace cocos2d;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainSceneLayer::create();
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainSceneLayer::init()
{
	if ( !LayerColor::initWithColor(Color4B(0, 0, 0, 255)))
    {
        return false;
    }
    
    Size size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
      
	Node *rootNode = CSLoader::createNode("Scenes/MainScene.csb"); 
	this->addChild(rootNode); 
  
	Node* background = rootNode->getChildByName("Background");
	Button* button =  static_cast<ui::Button*> (background-> getChildByName("PlayButton"));
	button->addTouchEventListener(CC_CALLBACK_2(MainSceneLayer::PlayButtonPressed, this));

    return true;
}

void MainSceneLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainSceneLayer::PlayButtonPressed(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::BEGAN) 
	{
		auto gameScene = GameScene::createScene();
		auto transition = TransitionFade::create(0.5, gameScene, Color3B::BLACK);
		Director::getInstance()->replaceScene(transition);
	}
}