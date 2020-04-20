#include "Purchase.h"
#include "Product.h"

Purchase::Purchase()
{
	this->nameRepository.push_back("default name");
	this->priceRepository.push_back(std::to_string(0.1));
	this->countOfPurchasedProducts = 0;
	this->totalWeigthOfPurchasedProducts = 0;
}

Purchase::Purchase(Product product)
{
	this->nameRepository.push_back(product.GetName());
	this->priceRepository.push_back(std::to_string(product.GetPrice()));
	this->countOfPurchasedProducts += 1;
	this->totalWeigthOfPurchasedProducts += product.GetWeigth();
}

int Purchase::GetCountOfPurchasedProducts() const
{
	return this->countOfPurchasedProducts;
}

double Purchase::GetTotalWeigthOfPurchasedProducts() const
{
	return this->totalWeigthOfPurchasedProducts;
}

std::string Purchase::GetNameRepository(int index) const
{
	return nameRepository[index];
}

int Purchase::GetRepositoryLengths() const
{
	return nameRepository.size();
}

std::string Purchase::GetPriceRepository(int index) const
{
	return priceRepository[index];
}

void Purchase::BuyProduct(Product product)
{
	this->nameRepository.push_back(product.GetName());
	this->priceRepository.push_back(std::to_string(product.GetPrice()));
	this->countOfPurchasedProducts = this->countOfPurchasedProducts + 1;
	this->totalWeigthOfPurchasedProducts += product.GetWeigth();
}
