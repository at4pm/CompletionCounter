#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace cocos2d;

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {		
		LevelInfoLayer::init(level, challenge);

		auto levelID = std::to_string(level->m_levelID);
		auto numToShow = geode::Mod::get()->getSavedValue<int>(levelID + "_completions", 0);
		
		auto parent = this->getChildByID("normal-mode-bar");

		auto fire = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("GJ_epicCoin_001.png"), nullptr, nullptr);
		fire->setPosition({ -36.0f, 5.0f });
		fire->setID("completion-fire");
			
		auto counter = CCLabelBMFont::create("", "bigFont.fnt");
		counter->setPosition({ 23.5f, 29.5f });
		counter->setID("completion-counter");
		counter->setString(fmt::format("{}", numToShow).c_str());
		fire->addChild(counter);

		parent->addChild(fire);

		return true;
	}
};

class $modify(PlayLayer) {
	void levelComplete() {
		PlayLayer::levelComplete();
		int levelID = this->m_level->m_levelID;
		int prev = geode::Mod::get()->getSavedValue<int>(fmt::format("{}_completions", levelID), 0);
		geode::Mod::get()->setSavedValue<int>(fmt::format("{}_completions", levelID), ++prev);
	}
};