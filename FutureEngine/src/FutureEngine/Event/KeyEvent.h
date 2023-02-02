#pragma once

#include "Event.h"

namespace FutureEngine 
{
	class FE_API KeyEvent :public Event
	{
	public:
		inline int GetKeycode()const { return m_Keycode; }
		EVENT_CLASS_GET_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		KeyEvent(int keycode) :m_Keycode(keycode) {}
		int m_Keycode;
	};

	class FE_API KeyPressedEvent :public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int keyRepeated)
			:KeyEvent(keycode), m_KeyRepeated(keyRepeated){}
		inline int GetRepeated() const { return m_KeyRepeated; }

		EVENT_CLASS_TYPE(KeyPressed)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed:\n Keycode : " << m_Keycode << ", KeyRepeated : " << m_KeyRepeated;
			return ss.str();
		}

	protected:
		int m_KeyRepeated;
	};

	class FE_API KeyReleasedEvent :public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) :KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased:\n Keycode : " << m_Keycode;
			return ss.str();
		}

	};

	class FE_API KeyTypedEvent :public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) :KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyTyped)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTyped:\n Keycode : " << m_Keycode;
			return ss.str();
		}

	};

}