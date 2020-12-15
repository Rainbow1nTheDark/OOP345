//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
namespace sdds {
	template<typename T>
	class Collection
	{
		std::string c_name;
		T* c_item = nullptr;
		size_t c_cnt = 0;
		void (*itemAdded)(const Collection&, const T&) = nullptr;
	public:
		Collection(std::string name) { c_name = name; }
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			delete[] c_item;
		}
		void setObserver(void (*obs)(const Collection&, const T&)) {
			itemAdded = obs;
		}
		const std::string& name() const
		{
			return c_name;
		}
		size_t size() const
		{
			return c_cnt;
		}
		Collection& operator+=(const T& item)
		{
			for (auto i = 0u; i < c_cnt; i++)
			{
				if (c_item[i].title() == item.title())
				{
					return *this;
				}
			}
			T* temp = new T[c_cnt + 1];
			for (auto i = 0u; i < c_cnt; i++)
			{
				temp[i] = c_item[i];
			}
			temp[c_cnt] = item;
			delete[] c_item;
			c_item = temp;
			c_cnt++;
			if (itemAdded != nullptr)
			{
				itemAdded(*this, c_item[c_cnt - 1]);

			}
			return *this;
		}
		T& operator[](size_t i) const
		{
			if (i >= c_cnt)
			{
				std::string error = "Bad index [" + std::to_string(i) + "]. Collection has [" + std::to_string(c_cnt) + "] items.";
				throw std::out_of_range(error);
			}
			return this->c_item[i];
		}
		T* operator[](std::string title) const
		{
			
			for (auto i = 0u; i < c_cnt; i++)
			{
				if (c_item[i].title() == title)
				{
					return &c_item[i];
				}
			}
			
			return nullptr;
		}
		
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& collection)
	{
		for (auto i = 0u; i < collection.size(); i++)
		{
			os << collection[i];
		}
		return os;
	}
}
#endif
