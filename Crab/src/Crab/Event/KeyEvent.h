#pragma once

#include "Event.h">

namespace Crab {

	class DLL_API KeyEvent : public Event 
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode){}
		int m_KeyCode;
	};

	class DLL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int KeyCode , int RepeatCount) : KeyEvent(KeyCode) , m_RepeatCount(RepeatCount) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " ( " << m_RepeatCount << " repeats )";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	
}