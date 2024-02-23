#include <Geode\modify\PauseLayer.hpp>
#include <Geode\modify\PlayLayer.hpp>
#include "UI\PScaleUIPauseButton.cpp"

using namespace geode::prelude;

class $modify(PauseLayer)
{
	void customSetup()
	{
 		PauseLayer::customSetup();
		CCMenuItemSpriteExtra* button = ScalerUI::PScaleUIPauseButton::ElementCreate(this);
		button->setID("pscale-button");
		CCNode* menu = getChildByID("center-button-menu");
		menu->addChild(button);
		log::debug("Button Injected");
	};
};