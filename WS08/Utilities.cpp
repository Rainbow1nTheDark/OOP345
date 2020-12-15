// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <algorithm>
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t j = 0; j < desc.size(); j++)
		{
			for (size_t i = 0; i < price.size(); i++)
			{
				if (desc[j].code == price[i].code)
				{
					Product* product = nullptr;
					product = new Product(desc[j].desc, price[i].price);
					product->validate();
					priceList += std::move(product);
					delete product;

				}
			}
		}

		return priceList;
	}
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

		for (size_t j = 0; j < desc.size(); j++)
		{
			for (size_t i = 0; i < price.size(); i++)
			{
				if (desc[j].code == price[i].code)
				{

					std::shared_ptr<Product>product(new Product(desc[j].desc, price[i].price));
					product->validate();
					priceList += std::move(product);

				}
			}
		}
		return priceList;
	}
}