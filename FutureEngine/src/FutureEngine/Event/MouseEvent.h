#pragma once

#include "Event.h"

namespace FutureEngine 
{
	class FE_API MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos)
			:m_XPos(xPos), m_YPos(yPos) {}
		inline float GetXPos() const { return m_XPos; }
		inline float GetYPos() const { return m_YPos; }
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_GET_CATEGORY(EventCategoryInput | EventCategoryMouse)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: xPos : " << GetXPos() << ", yPos : " << GetYPos();
			return ss.str();
		}

	private:
		int m_XPos, m_YPos;
	};

	class FE_API MouseButtonEvent :public Event
	{
	public:
		MouseButtonEvent(int button): m_Button(button) {}
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_TYPE(MouseButton)
		EVENT_CLASS_GET_CATEGORY(EventCategoryInput | EventCategoryMouseButton)

	private:
		int m_Button;
	};

	class FE_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonPressed)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed";
			return ss.str();
		}
	};

	class FE_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {}
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_GET_CATEGORY(EventCategoryInput | EventCategoryMouseButton)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: xOffset : " << GetXOffset() << ", yOffset : " << GetYOffset();
			return ss.str();
		}

	private:
		int m_XOffset, m_YOffset;
	};

}