#include <Geode\modify\CCLayer.hpp>
#include <Geode\ui\Popup.hpp>
#include <Geode\binding\CCTextInputNode.hpp>
#include "UI\PScaleInputEvents"
#include <Geode/c++stl/string.hpp>
using namespace geode::prelude;
using namespace geode;
using namespace gd;
namespace ScalerUI
{
	class UIPopup : public Popup<std::string const&>
	{
        public: CCTextInputNode* inputBox;
		public: PScaleInputEventManager* inputDelegate;
		protected: bool setup(std::string const& value) override
		{
			setTitle("Player Sizer", "bigFont.fnt", 0.925, 0);

			auto winSize = CCDirector::get()->getWinSize();
			inputDelegate = new PScaleInputEventManager();
            inputBox = CCTextInputNode::create(100, 95,"Player Size","bigFont.fnt");
            inputBox->setPosition(winSize.width / 2, winSize.height / 2);
			inputBox->m_allowedChars = "1234567890.";
			inputBox->m_delegate = inputDelegate;
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