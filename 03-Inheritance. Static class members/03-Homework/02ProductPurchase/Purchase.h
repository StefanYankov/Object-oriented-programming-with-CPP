#pragma once
#include "Product.h"
#include <vector>
class Purchase
    : public Product
{
public:
    Purchase();
    Purchase(Product);
    int GetCountOfPurchasedProducts() const;

    double GetTotalWeigthOfPurchasedProducts() const;

    std::string GetNameRepository(int) const;
    int GetRepositoryLengths() const;
    std::string GetPriceRepository(int) const;

    void BuyProduct(Product);
private:
    std::vector<std::string> nameRepository; // container required to store product information. Was not able to think of a better way
    std::vector<std::string> priceRepository; // container required to store product information. Was not able to think of a better way
    int countOfPurchasedProducts;
    double totalWeigthOfPurchasedProducts;
};

