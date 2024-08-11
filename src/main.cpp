#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace cocos2d;

class $modify(RBLevelInfoLayer, LevelInfoLayer) {
	void init(GJGameLevel* level, bool challenge) {
		auto glm = CCDirector::sharedDirector();
		
		LevelInfoLayer::init(level, challenge);
		
		auto parent = this->getChildByID("normal-mode-bar");
		auto counter = CCLabelBMFont::create("1", "bigFont.fnt");
		
		counter->setID("rebeat-counter");

		parent->addChild(counter);
	}

	void onCounterClick(CCObject* sender) {

	}
};

class $modify(PlayLayer) {
	void levelComplete() {
		PlayLayer::levelComplete();

		FLAlertLayer::create("Level", "you beat the level", "OK")->show();
	}
};