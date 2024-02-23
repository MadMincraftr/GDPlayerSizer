#include <Geode\modify\PauseLayer.hpp>

#include "PScaleUIPopup.cpp"
using namespace geode::prelude;
namespace ScalerUI
{
	class PScaleUIPauseButton : CCLayer
	{
		public: void onButton(CCObject* sender)
		{
			UIPopup::create()->show();
		};

		public: static CCMenuItemSpriteExtra* ElementCreate(CCObject* menu)
		{
    		auto spr = CCSprite::create("PScalePauseBTN.png"_spr);
		
    		auto btn = CCMenuItemSpriteExtra::create(spr, menu, menu_selector(onButton));
			return btn;
		};
	};
}