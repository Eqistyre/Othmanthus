#include "OsmanthusBeginner.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "OsmanthusMenu.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* OsmanthusBeginner::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = OsmanthusBeginner::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool OsmanthusBeginner::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //create a RootNode and rootScene,add the rootScene as the first root
    auto RootNode = CSLoader::createNode("OsmanthusBeginner.csb");
    auto RootScene = Scene::create();
    RootScene->addChild(RootNode);
    this->addChild(RootScene);
    //create a BeginnerNode and BeginnerScene,in order in the future we can run this scene
    auto BeginnerNode = CSLoader::createNode("BeginnerLayer.csb");
    auto BeginnerScene = Scene::create();
    BeginnerScene->addChild(BeginnerNode);
    this->addChild(BeginnerScene);
    
    cocos2d::ui::Button* BeginnerStartBtn = (cocos2d::ui::Button*)BeginnerNode->getChildByName("BeginnerStartBtn");
    cocos2d::ui::Button* BeginnerContinueBtn = (cocos2d::ui::Button*)BeginnerNode->getChildByName("BeginnerContinueBtn");
    cocos2d::ui::Button* BeginnerMenuBtn = (cocos2d::ui::Button*)BeginnerNode->getChildByName("BeginnerMenuBtn");
    cocos2d::ui::Button* BeginnerExitBtn = (cocos2d::ui::Button*)BeginnerNode->getChildByName("BeginnerExitBtn");
    
    BeginnerStartBtn->addTouchEventListener([](Ref* pSender,cocos2d::ui::Widget::TouchEventType type) {
        switch(type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                CCLOG("BEGAN");
                break;
                
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                CCLOG("MOVED");
                break;
                
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                CCLOG("ENDED");
                break;
                
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                CCLOG("CANCELED");
                break;
                
            default:
                break;
        }
    });
    
    BeginnerContinueBtn->addTouchEventListener([](Ref* pSender,cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
                
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
                
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                
                break;
                
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
                
            default:
                break;
        }
        
    });

    BeginnerMenuBtn->addTouchEventListener([](Ref* pSender,cocos2d::ui::Widget::TouchEventType type) {
        switch(type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
                
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
                
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                break;
                
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
                
            default:
                break;
        }
    });

    BeginnerExitBtn->addTouchEventListener([](Ref* pSender,cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
                
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            //just when you ended touch,the program br exited
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                exit(0);
                break;
                
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
                
            default:
                break;
        }
        
    });
    return true;
}
