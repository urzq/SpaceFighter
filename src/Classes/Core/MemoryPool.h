#ifndef _MEMORY_POOL_H_
#define _MEMORY_POOL_H_

namespace Core
{
	template<typename Type>
	class MemoryPool
	{
	public:
		MemoryPool(int nbObjects)
		{
			for (int i = 0; i < nbObjects; ++i)
			{
				auto place = operator new(sizeof(Type));
				m_FreeMemory.push(static_cast<Type*>(place));
			}
		}

		//delete all of the available memory chunks:
		~MemoryPool()
		{
			while (!m_FreeMemory.empty())
			{
				::operator delete(m_FreeMemory.top());
				m_FreeMemory.pop();
			}
		}

		MemoryPool(const MemoryPool &) = delete;
		MemoryPool& operator=(const MemoryPool&) = delete;
		MemoryPool(MemoryPool && other) = delete;
		MemoryPool& operator=(MemoryPool&& other) = delete;

		//create an instance of Type:
		template<typename... Args>
		Type* Create(Args && ...args)
		{
			auto place = (Type*)(_Allocate());
			new (place)Type(std::forward<Args>(args)...);
			return place;
		}

		//remove an instance of Type (add memory to the pool):
		void Remove(Type * o)
		{
			o->~Type();
			m_FreeMemory.push(o);
		}

	private:
		//allocate a chunk of memory as big as Type needs:
		void *_Allocate()
		{
			void * place;
			if (!m_FreeMemory.empty())
			{
				place = static_cast<void*>(m_FreeMemory.top());
				m_FreeMemory.pop();
			}
			else
			{
				place = operator new(sizeof(Type));
			}
			return place;
		}

	private:
		//stack to hold pointers to free chunks:
		std::stack<Type*> m_FreeMemory;
	};
}
#endif //_MEMORY_POOL_H_