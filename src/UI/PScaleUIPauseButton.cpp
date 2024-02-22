#include <Geode\modify\PauseLayer.hpp>

using namespace geode::prelude;

namespace ScalerUI
{
	class PScaleUIPauseButton : CCLayer
	{
		public: void onButton(CCObject* sender) {};

		public: static CCMenuItemSpriteExtra* ElementCreate(CCObject* menu)
		{
    		auto spr = CCSprite::create("PScalePauseBTN.png"_spr);
		
    		auto btn = CCMenuItemSpriteExtra::create(spr, menu, menu_selector(onButton));
			return btn;
		};
	};
}