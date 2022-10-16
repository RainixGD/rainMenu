#define CAC_PROJ_NAME "Template"

#if __APPLE__
	#include <CacKit>
	using namespace cocos2d;
#else
	#include "win32cac.h"
#endif

#include "nodes/BrownAlertDelegate.hpp";
#include "nodes/BrownAlertDelegate.cpp";
#include <array>



class checkTools {
public:
	void go(CCObject*) {
		CCApplication::sharedApplication()->openURL("https://21.rainixgdps.com/login.php");
	}
};



void copyHack(bool state);
void objectBypass(bool state);
void customObjectBypass(bool state);
void defaultSongBypass(bool state);
void verifyHack(bool state);
void sliderLimit(bool state);
void practiceMusicHack(bool state);
void noPulse(bool state);
void noDeathEffect(bool state);
void unlockIcons(bool state);
void noParticles(bool state);
void zoomBypass(bool state);
void rotationHack(bool state);
void placeOver(bool state);
void textLength(bool state);
void noClip(bool state);
void saveNoclip(bool state);
int Mods14_modCount = 9; //14 max
std::string Mods14_modNames[] = { "0", "Verify Hack", "Zoom Bypass", "Object Bypass", "Custom Object Bypass", "Practice Music Hack", "No Pulse", "No Death Effect", "Unlock Icons", "Save Noclip" };
void (*Mods14_modLinks[15])(bool) = { 0, verifyHack, zoomBypass, objectBypass, customObjectBypass, practiceMusicHack, noPulse, noDeathEffect, unlockIcons, saveNoclip };
bool Mods14_addBtnToScene[] = { NULL, 1, 1 }; //MenuLayer, PauseLayer



struct {
	std::array <bool, 15> isMod = { NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int icon = 1;
	int ship = 1;
	int ball = 1;
	int ufo = 1;
	int wave = 1;
	int robot = 1;
	int spider = 1;
	int trail = 1;
	int deathEffect = 1;
	int Firstcolor = 1;
	int Secondcolor = 1;
	bool isGlow = 1;
}Mods14_saveFile;

bool Mods14_loadData = 1;
CCPoint Mods14_checkboxPos[] = { ccp(NULL, NULL), ccp(-180, 80), ccp(-180, 50), ccp(-180, 20), ccp(-180, -10), ccp(-180, -40), ccp(-180, -70), ccp(-180, -100), ccp(30, 80), ccp(30, 50), ccp(30, 20), ccp(30, -10), ccp(30, -40), ccp(30, -70), ccp(30, -100) };
class Mods14_ModPopup : public BrownAlertDelegate {
protected:
	void setup() override {
		for (int i = 1; i < Mods14_modCount + 1; i++) {
			auto modNameLabel = CCLabelBMFont::create(Mods14_modNames[i].c_str(), "bigFont.fnt");
			modNameLabel->limitLabelWidth(150, 0.7, 0.1);
			modNameLabel->setPosition({ Mods14_checkboxPos[i].x + 20, Mods14_checkboxPos[i].y + 2 });
			modNameLabel->setAnchorPoint({ 0, 0.5 });
			m_pButtonMenu->addChild(modNameLabel);
		}
		updateDev();
	}
public:
	static Mods14_ModPopup* create() {
		auto ret = new Mods14_ModPopup;
		if (ret && ret->init(415, 270, "GJ_square01.png", "Mods")) {
			ret->autorelease();
			return ret;
		}
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
	void updateDev() {
		for (int i = 1; i < Mods14_modCount + 1; i++) {
			if (m_pButtonMenu->getChildByTag(i))
				m_pButtonMenu->getChildByTag(i)->removeFromParent();
		}
		for (int i = 1; i < Mods14_modCount + 1; i++) {
			auto onCheckbox = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
			onCheckbox->setScale(0.7);
			auto offCheckbox = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
			offCheckbox->setScale(0.7);
			auto previousArrow = CCMenuItemSpriteExtra::create(Mods14_saveFile.isMod[i] ? onCheckbox : offCheckbox, this, menu_selector(Mods14_ModPopup::updateModMenu));
			previousArrow->setPosition(Mods14_checkboxPos[i]);
			m_pButtonMenu->addChild(previousArrow, 5, i);
		}
	}
	void updateModMenu(CCObject* obj) {
		Mods14_saveFile.isMod[obj->getTag()] = !Mods14_saveFile.isMod[obj->getTag()];
		Mods14_modLinks[obj->getTag()](Mods14_saveFile.isMod[obj->getTag()]);
		updateDev();
	}
	void start(CCObject*) {
		Mods14_ModPopup::create()->show();
	}
	static void loadData() {
		if (Mods14_loadData) {
			Mods14_loadData = 0;
			auto file = fopen("Resources/Mods14_saveFile.dat", "rb");
			if (file) {
				fseek(file, 0, SEEK_END);
				auto size = ftell(file);

				if (size == sizeof(Mods14_saveFile)) {
					fseek(file, 0, SEEK_SET);
					fread(&Mods14_saveFile, sizeof(Mods14_saveFile), 1, file);
					fclose(file);
				}
			}
			for (int i = 1; i < Mods14_modCount + 1; i++) {
				Mods14_modLinks[i](Mods14_saveFile.isMod[i]);
			}

			gd::GameManager::sharedState()->setPlayerFrame(Mods14_saveFile.icon);
			gd::GameManager::sharedState()->setPlayerShip(Mods14_saveFile.ship);
			gd::GameManager::sharedState()->setPlayerBall(Mods14_saveFile.ball);
			gd::GameManager::sharedState()->setPlayerBird(Mods14_saveFile.ufo);
			gd::GameManager::sharedState()->setPlayerDart(Mods14_saveFile.wave);
			gd::GameManager::sharedState()->setPlayerRobot(Mods14_saveFile.robot);
			gd::GameManager::sharedState()->setPlayerSpider(Mods14_saveFile.spider);
			gd::GameManager::sharedState()->setPlayerStreak(Mods14_saveFile.trail);
			gd::GameManager::sharedState()->setPlayerDeathEffect(Mods14_saveFile.deathEffect);
			gd::GameManager::sharedState()->setPlayerColor(Mods14_saveFile.Firstcolor);
			gd::GameManager::sharedState()->setPlayerColor2(Mods14_saveFile.Secondcolor);
			gd::GameManager::sharedState()->setPlayerGlow(Mods14_saveFile.isGlow);
		}

	}
	static void saveData() {
		Mods14_saveFile.icon = gd::GameManager::sharedState()->getPlayerFrame();
		Mods14_saveFile.ship = gd::GameManager::sharedState()->getPlayerShip();
		Mods14_saveFile.ball = gd::GameManager::sharedState()->getPlayerBall();
		Mods14_saveFile.ufo = gd::GameManager::sharedState()->getPlayerBird();
		Mods14_saveFile.wave = gd::GameManager::sharedState()->getPlayerDart();
		Mods14_saveFile.robot = gd::GameManager::sharedState()->getPlayerRobot();
		Mods14_saveFile.spider = gd::GameManager::sharedState()->getPlayerSpider();
		Mods14_saveFile.trail = gd::GameManager::sharedState()->getPlayerStreak();
		Mods14_saveFile.deathEffect = gd::GameManager::sharedState()->getPlayerDeathEffect();
		Mods14_saveFile.Firstcolor = gd::GameManager::sharedState()->getPlayerColor();
		Mods14_saveFile.Secondcolor = gd::GameManager::sharedState()->getPlayerColor2();
		Mods14_saveFile.isGlow = gd::GameManager::sharedState()->getPlayerGlow();

		auto file = fopen("Resources/Mods14_saveFile.dat", "wb");
		if (file) {
			fwrite(&Mods14_saveFile, sizeof(Mods14_saveFile), 1, file);
			fclose(file);
		}
	}
};









CCSprite* Lightning;
CCSprite* BG;
CCSprite* Frame;
CCSprite* BGWhite;

CCSprite* CreateBtnS;
CCSprite* CreateBtnSX;
CCSprite* CreateBtnSB;

CCSprite* OnlineLevelsBtnS;
CCSprite* OnlineLevelsBtnSX;
CCSprite* OnlineLevelsBtnSB;

CCSprite* MainLevelsBtnS;
CCSprite* MainLevelsBtnSX;
CCSprite* MainLevelsBtnSB;

CCSprite* IconsBtnS;
CCSprite* IconsBtnSX;
CCSprite* IconsBtnSB;

CCSprite* TopBtnS;
CCSprite* TopBtnSX;
CCSprite* TopBtnSB;

CCSprite* FeaturedBtnS;
CCSprite* FeaturedBtnSX;
CCSprite* FeaturedBtnSB;

CCSprite* EpicBtnS;
CCSprite* EpicBtnSX;
CCSprite* EpicBtnSB;

CCSprite* GauntletsBtnS;
CCSprite* GauntletsBtnSX;
CCSprite* GauntletsBtnSB;

CCSprite* MapPacksBtnS;
CCSprite* MapPacksBtnSX;
CCSprite* MapPacksBtnSB;

CCSprite* OptionsBtnS;
CCSprite* OptionsBtnSX;
CCSprite* OptionsBtnSB;

CCSprite* DailyBtnS;
CCSprite* DailyBtnSX;
CCSprite* DailyBtnSB;

CCSprite* WeeklyBtnS;
CCSprite* WeeklyBtnSX;
CCSprite* WeeklyBtnSB;

CCSprite* ToolsBtnS;
CCSprite* ToolsBtnSX;
CCSprite* ToolsBtnSB;

CCSprite* ModsBtnS;
CCSprite* ModsBtnSX;
CCSprite* ModsBtnSB;

CCSprite* SavedLevelsBtnS;
CCSprite* SavedLevelsBtnSX;
CCSprite* SavedLevelsBtnSB;

CCParticleSystemQuad* MenuBtnGlow1;
CCParticleSystemQuad* MenuBtnGlow2;
CCParticleSystemQuad* MenuBtnGlow3;
CCParticleSystemQuad* MenuBtnGlow4;
CCParticleSystemQuad* MenuBtnGlow5;
CCParticleSystemQuad* MenuBtnGlow6;
CCParticleSystemQuad* MenuBtnGlow7;
CCParticleSystemQuad* MenuBtnGlow8;
CCParticleSystemQuad* MenuBtnGlow9;
CCParticleSystemQuad* MenuBtnGlow10;
CCParticleSystemQuad* MenuBtnGlow11;
CCParticleSystemQuad* MenuBtnGlow12;
CCParticleSystemQuad* MenuBtnGlow13;
CCParticleSystemQuad* MenuBtnGlow14;
CCParticleSystemQuad* MenuBtnGlow15;

CCParticleSystemQuad* MenuBtnGlowX1;
CCParticleSystemQuad* MenuBtnGlowX2;
CCParticleSystemQuad* MenuBtnGlowX3;
CCParticleSystemQuad* MenuBtnGlowX4;
CCParticleSystemQuad* MenuBtnGlowX5;
CCParticleSystemQuad* MenuBtnGlowX6;
CCParticleSystemQuad* MenuBtnGlowX7;
CCParticleSystemQuad* MenuBtnGlowX8;
CCParticleSystemQuad* MenuBtnGlowX9;
CCParticleSystemQuad* MenuBtnGlowX10;
CCParticleSystemQuad* MenuBtnGlowX11;
CCParticleSystemQuad* MenuBtnGlowX12;
CCParticleSystemQuad* MenuBtnGlowX13;
CCParticleSystemQuad* MenuBtnGlowX14;
CCParticleSystemQuad* MenuBtnGlowX15;

class ClassForOptions : CCLayer {
public:
	void onOptions(CCObject*) {
		GJDropDownLayer* layerX = GJDropDownLayer::create(0, 0);
		layerX = OptionsLayer::create();
		CCDirector::sharedDirector()->getRunningScene()->addChild(layerX);
		layerX->showLayer(FALSE);
	}
};

std::string MenuButtonsTexture[] = { "", "newCreate", "newOnlineLevels", "newMainLevels", "newIcons", "newTop", "newFeatured", "newEpic", "newGauntlets", "newMapPacks", "newOptions", "newDaily", "newWeekly", "newTools", "newMods", "newSavedLevels"};
std::array<SEL_MenuHandler, 20> MenuButtonsLinks = { NULL, menu_selector(CreatorLayer::onCreateLevels), menu_selector(CreatorLayer::onOnlineLevels), menu_selector(MenuLayer::onOficialLevels), menu_selector(MenuLayer::onIcons), menu_selector(CreatorLayer::onTop), menu_selector(CreatorLayer::onFeatured), menu_selector(CreatorLayer::onEpic), menu_selector(CreatorLayer::onGauntlets), menu_selector(CreatorLayer::onMapPacks), menu_selector(ClassForOptions::onOptions), menu_selector(CreatorLayer::onDaily), menu_selector(CreatorLayer::onWeekly), menu_selector(checkTools::go),  menu_selector(Mods14_ModPopup::start), menu_selector(CreatorLayer::onSavedLevels)};
CCPoint MenuButtonsPos[] = { ccp(NULL, NULL), ccp(1, 126), ccp(-54, 125), ccp(-119, 114), ccp(46, 93), ccp(138, 43), ccp(-147, 63), ccp(90, 109), ccp(-120, -22), ccp(-102, -17), ccp(-157, -13), ccp(129, 86), ccp(-162, 23), ccp(103, -33), ccp(121, -2), ccp(-110, -47)};
float MenuButtonsFadeTime[] = { NULL, 4, 3.5, 3.7, 3.3, 3.4, 4.1, 3.9, 4.2, 3.8, 3.6, 4.3, 4.4, 4.5, 4.7, 4.6 };
float MenuButtonsScale[] = {NULL, 1.85, 1.825, 1.475, 1.575, 1.425, 1.55, 1.575, 0.9, 0.625, 1.125, 1.3, 1.275, 0.775, 1.15, 0.675 };
CCSprite* MenuButtonsS[] = {NULL, CreateBtnS, OnlineLevelsBtnS, MainLevelsBtnS, IconsBtnS, TopBtnS, FeaturedBtnS, EpicBtnS, GauntletsBtnS, MapPacksBtnS, OptionsBtnS, DailyBtnS, WeeklyBtnS, ToolsBtnS, ModsBtnS, SavedLevelsBtnS };
CCSprite* MenuButtonsSX[] = { NULL, CreateBtnSX, OnlineLevelsBtnSX, MainLevelsBtnSX, IconsBtnSX, TopBtnSX, FeaturedBtnSX, EpicBtnSX, GauntletsBtnSX, MapPacksBtnSX, OptionsBtnSX, DailyBtnSX, WeeklyBtnSX, ToolsBtnSX, ModsBtnSX, SavedLevelsBtnSX };
CCSprite* MenuButtonsSB[] = { NULL, CreateBtnSB, OnlineLevelsBtnSB, MainLevelsBtnSB, IconsBtnSB, TopBtnSB, FeaturedBtnSB, EpicBtnSB, GauntletsBtnSB, MapPacksBtnSB, OptionsBtnSB, DailyBtnSB, WeeklyBtnSB, ToolsBtnSB, ModsBtnSB, SavedLevelsBtnSB };
CCParticleSystemQuad* MenuButtonsGlow[] = {NULL, MenuBtnGlow1, MenuBtnGlow2, MenuBtnGlow3, MenuBtnGlow4, MenuBtnGlow5, MenuBtnGlow6, MenuBtnGlow7, MenuBtnGlow8, MenuBtnGlow9, MenuBtnGlow10, MenuBtnGlow11, MenuBtnGlow12, MenuBtnGlow13, MenuBtnGlow14, MenuBtnGlow15 };
CCParticleSystemQuad* MenuButtonsGlowX[] = { NULL, MenuBtnGlowX1, MenuBtnGlowX2, MenuBtnGlowX3, MenuBtnGlowX4, MenuBtnGlowX5, MenuBtnGlowX6, MenuBtnGlowX7, MenuBtnGlowX8, MenuBtnGlowX9, MenuBtnGlowX10, MenuBtnGlowX11, MenuBtnGlowX12, MenuBtnGlowX13, MenuBtnGlowX14, MenuBtnGlowX15 };

CCSprite* cloud1;
CCSprite* cloud2;
CCSprite* cloud3;
CCSprite* cloud4;

float RedOffset = 255;
float GreenOffset = 0;
float BlueOffset = 0;

CCParticleSystemQuad* eff;

bool btnsCanChangeColor = 1;

class Loops {
public:
	void LightningMomentStart(float dt) {
		Lightning->runAction(CCFadeTo::create(0.1, 255));
		BG->runAction(CCFadeTo::create(0.1, 50));

		BG->runAction(CCMoveBy::create(0.05, { 0.3, 0 }));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.05), CCMoveBy::create(0.05, { -0.3, 0 } )));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.1), CCMoveBy::create(0.05, { 0.3, 0 } )));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.15), CCMoveBy::create(0.05, { -0.3, 0 })));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.2), CCMoveBy::create(0.05, { 0.3, 0 })));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.25), CCMoveBy::create(0.05, { -0.3, 0 })));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.3), CCMoveBy::create(0.05, { 0.3, 0 })));
		BG->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.35), CCMoveBy::create(0.05, { -0.3, 0 })));

		BGWhite->runAction(CCMoveBy::create(0.05, { 0.3, 0 }));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.05), CCMoveBy::create(0.05, { -0.3, 0 })));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.1), CCMoveBy::create(0.05, { 0.3, 0 })));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.15), CCMoveBy::create(0.05, { -0.3, 0 })));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.2), CCMoveBy::create(0.05, { 0.3, 0 })));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.25), CCMoveBy::create(0.05, { -0.3, 0 })));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.3), CCMoveBy::create(0.05, { 0.3, 0 })));
		BGWhite->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(0.35), CCMoveBy::create(0.05, { -0.3, 0 })));

		GameSoundManager::playSound("Resources/thunder.mp3");

		Lightning->unschedule(schedule_selector(Loops::LightningMomentStart));
		Lightning->schedule(schedule_selector(Loops::LightningMomentFinish), 0.4);

		btnsCanChangeColor = 0;
		ccColor3B colorTemp1 = { 0, 0, 0 };
		for (int i = 1; i < 16; i++) {
			MenuButtonsS[i]->setColor(colorTemp1);
			MenuButtonsSX[i]->setColor(colorTemp1);
			MenuButtonsGlowX[i]->setVisible(0);
			MenuButtonsGlow[i]->setVisible(0);
		}
		eff->setVisible(0);
	}
	void LightningMomentFinish(float dt) {
		Lightning->runAction(CCFadeTo::create(0.1, 0));
		BG->runAction(CCFadeTo::create(0.3, 255));
		Lightning->unschedule(schedule_selector(Loops::LightningMomentFinish));
		Lightning->schedule(schedule_selector(Loops::LightningMomentStart), 10);
		for (int i = 1; i < 16; i++) {
			MenuButtonsGlowX[i]->setVisible(1);
			MenuButtonsGlow[i]->setVisible(1);
		}
		eff->setVisible(1);
		btnsCanChangeColor = 1;
	}

	void MainButtonsColorChange(float dt) {

		if (RedOffset == 255 && GreenOffset < 255 && BlueOffset == 0) {
			GreenOffset = GreenOffset + 1;
			if (GreenOffset > 255) GreenOffset = 255;
		}
		else if (RedOffset > 0 && GreenOffset == 255 && BlueOffset == 0) {
			RedOffset = RedOffset - 1;
			if (RedOffset < 0) RedOffset = 0;
		}
		else if (RedOffset == 0 && GreenOffset == 255 && BlueOffset < 255) {
			BlueOffset = BlueOffset + 1;
			if (BlueOffset > 255) BlueOffset = 255;

		}
		else if (RedOffset == 0 && GreenOffset > 0 && BlueOffset == 255) {
			GreenOffset = GreenOffset - 1;
			if (GreenOffset < 0) GreenOffset = 0;
		}
		else if (RedOffset < 255 && GreenOffset == 0 && BlueOffset == 255) {
			RedOffset = RedOffset + 1;
			if (RedOffset > 255) RedOffset = 255;
		}
		else if (RedOffset == 255 && GreenOffset == 0 && BlueOffset > 0) {
			BlueOffset = BlueOffset - 1;
			if (BlueOffset < 0) BlueOffset = 0;
		}

		if (btnsCanChangeColor) {

			ccColor3B colorTemp1 = { RedOffset, GreenOffset, BlueOffset };
			for (int i = 1; i < 16; i++) {
				MenuButtonsS[i]->setColor(colorTemp1);
				MenuButtonsSX[i]->setColor(colorTemp1);
				MenuButtonsGlow[i]->setStartColor({ RedOffset / float(255), GreenOffset / float(255), BlueOffset / float(255), 0 });
				MenuButtonsGlow[i]->setEndColor({ RedOffset / float(255), GreenOffset / float(255), BlueOffset / float(255), 0 });
				MenuButtonsGlowX[i]->setStartColor({ RedOffset / float(255), GreenOffset / float(255), BlueOffset / float(255), 0 });
				MenuButtonsGlowX[i]->setEndColor({ RedOffset / float(255), GreenOffset / float(255), BlueOffset / float(255), 0 });
				MenuButtonsGlow[i]->setOpacityModifyRGB(1);
			}
			eff->setStartColor({ RedOffset / float(255), GreenOffset / float(255), BlueOffset / float(255), 0 });
			eff->setEndColor({ RedOffset / float(255), GreenOffset / float(255), BlueOffset / float(255), 0 });
		}
	}
	void cloudUpdate(float dt){
		if (cloud1->getPositionX() == CCDirector::sharedDirector()->getWinSize().width + cloud1->getContentSize().width / 2) {
			cloud1->runAction(CCMoveTo::create(10 + rand() % 30, ccp(-1 * (cloud1->getContentSize().width / 2), cloud1->getPositionY())));
		}

		if (cloud1->getPositionX() == cloud1->getContentSize().width / -2) {
			cloud1->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width + cloud1->getContentSize().width / 2, float(rand() % int(CCDirector::sharedDirector()->getWinSize().height))));
			cloud1->setScale( 1 * (rand() % 3 + 1) );
		}

		if (cloud2->getPositionX() == CCDirector::sharedDirector()->getWinSize().width + cloud2->getContentSize().width / 2) {
			cloud2->runAction(CCMoveTo::create(10 + rand() % 30, ccp(-1 * (cloud2->getContentSize().width / 2), cloud2->getPositionY())));
		}

		if (cloud2->getPositionX() == cloud2->getContentSize().width / -2) {
			cloud2->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width + cloud2->getContentSize().width / 2, float(rand() % int(CCDirector::sharedDirector()->getWinSize().height))));
			cloud2->setScale(1 * (rand() % 3 + 1));
		}

		if (cloud3->getPositionX() == CCDirector::sharedDirector()->getWinSize().width + cloud3->getContentSize().width / 2) {
			cloud3->runAction(CCMoveTo::create(10 + rand() % 30, ccp(-1 * (cloud3->getContentSize().width / 2), cloud3->getPositionY())));
		}

		if (cloud3->getPositionX() == cloud3->getContentSize().width / -2) {
			cloud3->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width + cloud3->getContentSize().width / 2, float(rand() % int(CCDirector::sharedDirector()->getWinSize().height))));
			cloud3->setScale(1 * (rand() % 3 + 1));
		}

		if (cloud4->getPositionX() == CCDirector::sharedDirector()->getWinSize().width + cloud4->getContentSize().width / 2) {
			cloud4->runAction(CCMoveTo::create(10 + rand() % 30, ccp(-1 * (cloud4->getContentSize().width / 2), cloud4->getPositionY())));
		}

		if (cloud4->getPositionX() == cloud4->getContentSize().width / -2) {
			cloud4->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width + cloud4->getContentSize().width / 2, float(rand() % int(CCDirector::sharedDirector()->getWinSize().height))));
			cloud4->setScale(1 * (rand() % 3 + 1));
		}
	}
};


bool(__thiscall* menulayer)(CCLayer* self);
bool __fastcall menulayer_hk(CCLayer* self, void*) {
	if (!menulayer(self)) return false;
	Mods14_ModPopup::loadData();
	for (int i = 0; i < self->getChildrenCount() - 1; i++) {
		auto tempDelObj = dynamic_cast<CCNode*>(self->getChildren()->objectAtIndex(i));
		tempDelObj->setVisible(0);
	}

		//GameSoundManager::sharedState()->playBackgroundMusic(1, "rainSound.mp3");

	BG = CCSprite::create("mainMenuBG.png");
	BG->setScaleX(CCDirector::sharedDirector()->getWinSize().width / (BG->getContentSize().width - 10));
	BG->setScaleY(CCDirector::sharedDirector()->getWinSize().height / (BG->getContentSize().height - 10));
	BG->setPosition({ CCDirector::sharedDirector()->getWinSize().width / 2, 0 });
	BG->setZOrder(3);
	self->addChild(BG);

	BG->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCSkewTo::create(4, -2, 0), 2), CCEaseInOut::create(CCSkewTo::create(4, 2, 0), 2))));
	BG->setAnchorPoint({ 0.5, 0 });

	BGWhite = CCSprite::create("mainMenuBGWhite.png");
	BGWhite->setZOrder(2);
	BGWhite->setScaleX(CCDirector::sharedDirector()->getWinSize().width / (BGWhite->getContentSize().width - 10));
	BGWhite->setScaleY(CCDirector::sharedDirector()->getWinSize().height / (BGWhite->getContentSize().height - 10));
	BGWhite->setPosition({ CCDirector::sharedDirector()->getWinSize().width / 2, 0 });
	self->addChild(BGWhite);

	BGWhite->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCSkewTo::create(4, -2, 0), 2), CCEaseInOut::create(CCSkewTo::create(4, 2, 0), 2))));
	BGWhite->setAnchorPoint({ 0.5, 0 });


	Frame = CCSprite::create("mainMenuFrame.png");
	Frame->setScaleX(CCDirector::sharedDirector()->getWinSize().width / Frame->getContentSize().width);
	Frame->setScaleY(CCDirector::sharedDirector()->getWinSize().height / Frame->getContentSize().height);
	Frame->setPosition({ 0, 0 });
	Frame->setAnchorPoint({ 0, 0 });
	Frame->setZOrder(10);
	self->addChild(Frame);

	auto Tree = CCSprite::create("mainMenuTree.png");
	Tree->setScale(CCDirector::sharedDirector()->getWinSize().width / Tree->getContentSize().width * 0.94);
	Tree->setPosition({ CCDirector::sharedDirector()->getWinSize().width / 2 + 10, 0 });
	Tree->setZOrder(7);
	self->addChild(Tree);

	Tree->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCSkewTo::create(0.05, -0.03, -0.03), 3), CCEaseInOut::create(CCSkewTo::create(0.05, 0.03, 0.03), 3))));
	Tree->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseIn::create(CCRotateTo::create(4, -1), 3), CCEaseIn::create(CCRotateTo::create(4, 2), 3))));
	Tree->setAnchorPoint({ 0.5, 0 });

	auto rainEffectBack = CCParticleSystemQuad::create("rainEffect.plist");
	rainEffectBack->setPosition(CCDirector::sharedDirector()->getWinSize() / 2);
	rainEffectBack->setScaleY(5);
	rainEffectBack->setSourcePosition({ CCDirector::sharedDirector()->getWinSize().width, CCDirector::sharedDirector()->getWinSize().height / float(1.5) });
	rainEffectBack->setZOrder(5);
	self->addChild(rainEffectBack);

	auto rainEffect = CCParticleSystemQuad::create("rainEffect2.plist");
	rainEffect->setPosition(CCDirector::sharedDirector()->getWinSize() / 2);
	rainEffect->setScaleY(5);
	rainEffect->setSourcePosition({ CCDirector::sharedDirector()->getWinSize().width, CCDirector::sharedDirector()->getWinSize().height / float(1.5) });
	rainEffect->setZOrder(8);
	self->addChild(rainEffect);

	auto rainEffectFront = CCParticleSystemQuad::create("rainEffect3.plist");
	rainEffectFront->setPosition(CCDirector::sharedDirector()->getWinSize() / 2);
	rainEffectFront->setScaleY(5);
	rainEffectFront->setSourcePosition({ CCDirector::sharedDirector()->getWinSize().width, CCDirector::sharedDirector()->getWinSize().height / float(1.5) });
	rainEffectFront->setZOrder(12);
	self->addChild(rainEffectFront);


	Lightning = CCSprite::create();
	Lightning->setZOrder(2);
	Lightning->setPosition({ 227, 227 });
	Lightning->setScale(0.425);
	Lightning->setRotation(71);
	auto LightningArr = CCArray::create();
	for (int i = 1; i < 3; i++) {
		auto findLightningSprite = CCSpriteFrameCache::sharedSpriteFrameCache();
		std::string findLightningSpriteS = std::string("LightningMenu_" + std::to_string(i) + ".png");
		auto nextLightningSprite = findLightningSprite->spriteFrameByName(findLightningSpriteS.c_str());
		LightningArr->addObject(nextLightningSprite);
	}
	auto LightningAnimation = CCAnimation::createWithSpriteFrames(LightningArr, 1.0 / float(17));
	Lightning->runAction(CCRepeatForever::create(CCAnimate::create(LightningAnimation)));
	BG->addChild(Lightning);

	Lightning->setOpacity(0);

	Lightning->schedule(schedule_selector(Loops::LightningMomentStart), 3);

	
	
	CCMenu* buttonsMenu = CCMenu::create();
	buttonsMenu->setPosition(Tree->getContentSize() / 2);
	buttonsMenu->setZOrder(25);
	Tree->addChild(buttonsMenu);
	
	for (int i = 1; i < 16; i++){
		MenuButtonsS[i] = CCSprite::create((MenuButtonsTexture[i] + ".png").c_str());
		MenuButtonsS[i]->setScale(MenuButtonsScale[i]);
		MenuButtonsSX[i] = CCSprite::create((MenuButtonsTexture[i] + "Hover.png").c_str());
		MenuButtonsSX[i]->setScale(MenuButtonsScale[i]);
		MenuButtonsSB[i] = CCSprite::create((MenuButtonsTexture[i] + ".png").c_str());
		MenuButtonsSB[i]->setPosition(MenuButtonsS[i]->getContentSize() / 2);
		MenuButtonsSB[i]->setZOrder(-1);
		MenuButtonsSB[i]->setColor({ 0, 0, 0 });
		MenuButtonsS[i]->addChild(MenuButtonsSB[i]);
		auto MenuButtonItem = CCMenuItemSprite::create(MenuButtonsS[i], MenuButtonsSX[i], buttonsMenu, MenuButtonsLinks[i]);
		MenuButtonItem->setPosition(MenuButtonsPos[i]);
		MenuButtonsS[i]->setAnchorPoint({ 0.5, 0.5 });
		MenuButtonsSX[i]->setAnchorPoint({ 0.5, 0.5 });
		MenuButtonsS[i]->setPosition({ MenuButtonItem->getContentSize() / 2 });
		MenuButtonsSX[i]->setPosition({ MenuButtonItem->getContentSize() / 2 });
		buttonsMenu->addChild(MenuButtonItem);
		MenuButtonsS[i]->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCScaleBy::create(MenuButtonsFadeTime[i], 0.4), 2), CCEaseInOut::create(CCScaleBy::create(6 - MenuButtonsFadeTime[i], 2.5), 2)))); //timeArray
		MenuButtonsS[i]->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCFadeTo::create(MenuButtonsFadeTime[i], 0), 2), CCEaseInOut::create(CCFadeTo::create(6 - MenuButtonsFadeTime[i], 255), 2))));
		MenuButtonsSX[i]->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCScaleBy::create(MenuButtonsFadeTime[i], 0.4), 2), CCEaseInOut::create(CCScaleBy::create(6 - MenuButtonsFadeTime[i], 2.5), 2))));


		MenuButtonsGlow[i] = CCParticleSystemQuad::create("neonEffect.plist");
		MenuButtonsGlow[i]->setPosition(MenuButtonsS[i]->getContentSize() / 2);
		MenuButtonsGlow[i]->setZOrder(-5);
		MenuButtonsS[i]->addChild(MenuButtonsGlow[i]);
		MenuButtonsGlow[i]->runAction(CCRepeatForever::create(CCSequence::createWithTwoActions(CCEaseInOut::create(CCScaleBy::create(MenuButtonsFadeTime[i] * 1.5, -0.99), 2), CCEaseInOut::create(CCScaleBy::create(6 - MenuButtonsFadeTime[i] * 1.5, 1), 2))));

		MenuButtonsGlowX[i] = CCParticleSystemQuad::create("neonEffect.plist");
		MenuButtonsGlowX[i]->setPosition(MenuButtonsSX[i]->getContentSize() / 2);
		MenuButtonsGlowX[i]->setZOrder(-5);
		MenuButtonsSX[i]->addChild(MenuButtonsGlowX[i]);
	}

	buttonsMenu->schedule(schedule_selector(Loops::MainButtonsColorChange), 0.001);

	cloud1 = CCSprite::create("Cloud_1.png");
	cloud1->setPosition({ CCDirector::sharedDirector()->getWinSize().width + cloud1->getContentSize().width / 2,  float(rand() % int(CCDirector::sharedDirector()->getWinSize().height))});
	cloud1->setOpacity(20);
	cloud1->setColor({ 0, 242, 242 });
	self->addChild(cloud1, 6);

	cloud2 = CCSprite::create("Cloud_1.png");
	cloud2->setPosition({ CCDirector::sharedDirector()->getWinSize().width + cloud2->getContentSize().width / 2,  float(rand() % int(CCDirector::sharedDirector()->getWinSize().height)) });
	cloud2->setOpacity(20);
	cloud2->setColor({ 0, 242, 242 });
	self->addChild(cloud2, 6);

	cloud3 = CCSprite::create("Cloud_1.png");
	cloud3->setPosition({ CCDirector::sharedDirector()->getWinSize().width + cloud3->getContentSize().width / 2,  float(rand() % int(CCDirector::sharedDirector()->getWinSize().height)) });
	cloud3->setOpacity(100);
	cloud3->setColor({ 0, 0, 0 });
	self->addChild(cloud3, 6);

	cloud4 = CCSprite::create("Cloud_1.png");
	cloud4->setPosition({ CCDirector::sharedDirector()->getWinSize().width + cloud4->getContentSize().width / 2,  float(rand() % int(CCDirector::sharedDirector()->getWinSize().height)) });
	cloud4->setOpacity(100);
	cloud4->setColor({ 0, 0, 0 });
	self->addChild(cloud4, 6);

	eff = CCParticleSystemQuad::create("nebelEffect.plist");
	eff->setPosition({ CCDirector::sharedDirector()->getWinSize().width / 2, 0 });
	self->addChild(eff, 8);
	eff->setStartColor({ 0, 242, 242, 0.01 });
	eff->setEndColor({ 0, 242, 242, 0.01 });

	self->schedule(schedule_selector(Loops::cloudUpdate), float(float(1) / float(60)));

	return true;
}




void(__thiscall* OptionsCorrect)(gd::OptionsLayer* self);
bool __fastcall OptionsCorrect_hk(gd::OptionsLayer* self, void* edx) {
	OptionsCorrect(self);

	self->sortAllChildren();
	auto testX = dynamic_cast<CCNode*>(self->getChildren()->objectAtIndex(0));
	auto testXx = dynamic_cast<CCNode*>(testX->getChildren()->objectAtIndex(0));
	testXx->setVisible(0);
	auto testXxx = dynamic_cast<CCNode*>(testX->getChildren()->objectAtIndex(2));
	testXxx->setVisible(0);
	auto testXxxx = dynamic_cast<CCNode*>(testX->getChildren()->objectAtIndex(3));
	testXxxx->setVisible(0);

	return TRUE;

}


namespace gd {
	class GDH_DLL AppDelegate : public CCApplication {
	public:

	};
}
void(__thiscall* onTrySave)(gd::AppDelegate* self);
void __fastcall onTrySave_hk(gd::AppDelegate* self) {
	onTrySave(self);
	Mods14_ModPopup::saveData();
}


DWORD libcocosbase = (DWORD)GetModuleHandleA("libcocos2d.dll");
void copyHack(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x8B\xCA\x90", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\xB0\x01\x90", 3, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x75\x0E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x0F\x44\xCA", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\x0F\x95\xC0", 3, NULL);
	}
}

void objectBypass(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x73169), "\xFF\xFF\xFF\x7F", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x856A4), "\xFF\xFF\xFF\x7F", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87B17), "\xFF\xFF\xFF\x7F", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87BC7), "\xFF\xFF\xFF\x7F", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87D95), "\xFF\xFF\xFF\x7F", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x880F4), "\xFF\xFF\xFF\x7F", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160B06), "\xFF\xFF\xFF\x7F", 4, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x73169), "\x80\x38\x01\x00", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x856A4), "\x80\x38\x01\x00", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87B17), "\x80\x38\x01\x00", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87BC7), "\x80\x38\x01\x00", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87D95), "\x80\x38\x01\x00", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x880F4), "\x80\x38\x01\x00", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160B06), "\x80\x38\x01\x00", 4, NULL);
	}
}

void customObjectBypass(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A100), "\xEB", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A022), "\xEB", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A203), "\x90\x90", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A100), "\x72", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A022), "\x76", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x7A203), "\x77\x3A", 2, NULL);
	}
}

void defaultSongBypass(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174407), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174411), "\x90\x90\x90", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174456), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174460), "\x90\x90\x90", 3, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174407), "\x74\x2F", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174411), "\x0F\x4F\xC6", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174456), "\x74\x2F", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x174460), "\x0F\x4F\xC6", 3, NULL);
	}
}

void verifyHack(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\xEB", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x71D48), "\x74", 1, NULL);
	}
}

void sliderLimit(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\xEB", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\xEB", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8F196), "\x83", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8F1A2), "\x90\x90\x90\x90\x90\x90", 6, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5CA), "\x76", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2E5F8), "\x76", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8F196), "\x87", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8F1A2), "\x0F\x87\x6A\x01\x00\x00", 6, NULL);
	}
}

void practiceMusicHack(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x90\x90\x90\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x90\x90", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x0F\x85\xF7\x00\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x75\x41", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x75\x3E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x75\x0C", 2, NULL);
	}
}

void noPulse(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2060D9), "\xEB\x4A", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2060D9), "\x74\x4A", 2, NULL);
	}
}

void noDeathEffect(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\xC3", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\x55", 1, NULL);
	}
}

void unlockIcons(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xB0\x01\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xB0\x01\x90\x90\x90", 5, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xE8\x7A\xCD\x19\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xE8\x68\xC9\x19\x00", 5, NULL);
	}
}

void noParticles(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(libcocosbase + 0xB76C5), "\x31\xF6", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(libcocosbase + 0xB8ED6), "\x00", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(libcocosbase + 0xB76C5), "\x8B\xF0", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(libcocosbase + 0xB8ED6), "\x01", 1, NULL);
	}
}

void zoomBypass(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87801), "\x90\x90\x90", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87806), "\x90\x90\x90", 3, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87801), "\x0F\x2F\xC8", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x87806), "\x0F\x28\xC8", 3, NULL);
	}
}

void rotationHack(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x85CBC), "\xB8\x01\x00\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8BDDD), "\xB8\x01\x00\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8BE16), "\xB8\x01\x00\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xECA3D), "\xB8\x01\x00\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xEE5A9), "\xB8\x01\x00\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20181E), "\xB8\x01\x00\x00\x00\x90", 6, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x85CBC), "\x8B\x80\x00\x03\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8BDDD), "\x8B\x80\x00\x03\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x8BE16), "\x8B\x80\x00\x03\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xECA3D), "\x8B\x87\x00\x03\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xEE5A9), "\x8B\x86\x00\x03\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20181E), "\x8B\x83\x00\x03\x00\x00", 6, NULL);
	}
}

void placeOver(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160EE1), "\x8B\xC1\x90", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160EF2), "\xE9\x23\x02\x00\x00\x90", 6, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160EE1), "\x0F\x48\xC1", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x160EF2), "\x0F\x8F\x22\x02\x00\x00", 6, NULL);
	}
}

void textLength(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\xEB\x04", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x21ACB), "\x7C\x04", 2, NULL);
	}
}

void noClip(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xEB\x37", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x8A\x80", 2, NULL);
	}
}

void saveNoclip(bool state) {
	if (state) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xEB\x37", 2, NULL);

		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3D1), "\xE9\x7B\x01\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FF80B), "\x90\x90\x90\x90\x90\x90\x90", 7, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x8A\x80", 2, NULL);

		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3D1), "\x0F\x85\x7A\x01\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FF80B), "\x7D\x0C\xE9\xC2\xFB\xFF\xFF", 7, NULL);
	}
}


//LevelBrowserLayer

void inject() {
	#if _WIN32
	auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
	
	MH_CreateHook(
		(PVOID)(base + 0x1907b0),
		menulayer_hk,
		(LPVOID*)&menulayer
	);

	MH_CreateHook(
		(PVOID)(base + 0x5dd420 - 0x400000),
		OptionsCorrect_hk,
		(LPVOID*)&OptionsCorrect
	);
	MH_CreateHook(
		(PVOID)(base + 0x3D5E0),
		onTrySave_hk,
		(LPVOID*)&onTrySave
	);
	

	MH_EnableHook(MH_ALL_HOOKS);
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif
