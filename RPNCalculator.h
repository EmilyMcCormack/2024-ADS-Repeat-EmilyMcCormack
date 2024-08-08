#pragma once

#include <vector>

template <class T> class RPNCalculator
{
	private
		vector<T> m_stack;
	size_t m_stackSize; 
public:
	RPNCalculator() : m_stack{}, m_stackSize{ 0 }
	{}

	//pushes a new operand onto the stack 
	void push(T operand) {
		m_stack.emplace_back(operand);
		m_stackSize++;
	}
	
	//binary operators: 
	void add() {
		if (m_stackSize >= 2) {
			T temp = m_stack[m_stackSize - 1];
			temp += m_stack[m_stackSize - 2];
			m_stack.pop_back();
			m_stack -= 1;
			m_stack[m_stackSize - 1] = temp; 
		}
	}

	void subtract() {
		if (m_stackSize >= 2) {
			T temp = m_stack[m_stackSize - 2]; 
			temp -= m_stack[m_stackSize - 1];
			m_stack.pop_back();
			m_stackSize -= 1; 
			m_stack[m_stackSize - 1] = temp;
		}

	}

	void multiply() {
		if (m_stackSize >= 2) {
			T temp = m_stack[m_stackSize - 1];
			temp *= m_stack[m_stackSize - 2];
			m_stack.pop_back();
			m_stackSize -= 1; 
			m_stack[m_stackSize - 1] = temp; 
		}
	}

	void divide() {
		if (m_stackSize >= 2) {
			T temp = m_stack[m_stackSize - 2];
			temp /= m_stack[m_stackSize - 1];
			m_stack.pop_back();
			m_stackSize -= 1;
			m_stack[m_stackSize - 1] = temp;
		}

	}
};

