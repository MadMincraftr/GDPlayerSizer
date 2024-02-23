#include <Geode\modify\CCLayer.hpp>
#include <Geode\ui\Popup.hpp>
#include <Geode/ui/TextInput.hpp>
#include "UI\PScaleInputEvents"
using namespace geode::prelude;
using namespace geode;
namespace ScalerUI
{
	class UIPopup : public Popup<std::string const&>
	{
        public: TextInput* inputBox;
		protected: bool setup(std::string const& value) override
		{
			setTitle("Player Sizer", "bigFont.fnt", 0.925, 0);

			auto winSize = CCDirector::get()->getWinSize();

            inputBox = TextInput::create(150,"Player Size","bigFont.fnt");
            inputBox->setPosition(winSize.width / 2, winSize.height / 2);
			inputBox->setFilter("1234567890.");
			inputBox->setDelegate(dynamic_cast<TextInputDelegate*>(new PScaleInputEventManager()));
			addChild(inputBox);
			return true;
		};
		public:
    static UIPopup* create() {
        auto ret = new UIPopup();
        if (ret && ret->init(240.f, 160.f, "Done")) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
	};
};