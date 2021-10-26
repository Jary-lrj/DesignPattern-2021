#ifndef _COMMIDITY_SELLER_H_
#define _COMMIDITY_SELLER_H_

#include<string>
#include<list>
#include"shop_seller.h"

using std::string;
using std::list;

class CommoditySeller {
protected:
	string name, type; //��Ʒ���ƣ��������
	int ID, price; //��Ʒ�۸�����
	ShopSeller* owner; //��Ʒ��������

public:
	CommoditySeller(int ID, string name, int price, ShopSeller* shop);

	string GetName() { return this->name; }
	string GetType() { return this->type; }
	int GetPrice() { return this->price; }
	ShopSeller* GetOwner() { return this->owner; }

	virtual bool Add(CommoditySeller* commodity);
	virtual bool Remove(CommoditySeller* commodity);

	virtual bool HasCommodity(CommoditySeller* commodity) = 0;
	virtual bool Enough(int amount) = 0;
	virtual bool Sell(int amount) = 0;
	virtual void Display() = 0;
};

class SingleCommoditySeller : public CommoditySeller {
protected:
	int amount; //��Ʒ�������

public:
	SingleCommoditySeller(int ID, string name, int price, ShopSeller* shop, int amount);

	virtual bool HasCommodity(CommoditySeller* commodity);
	virtual bool Enough(int amount);
	virtual bool Sell(int amount);
	virtual void Display();
};

class CompositeCommoditySeller : public CommoditySeller {
protected:
	list<CommoditySeller*> commodity_list;

public:
	CompositeCommoditySeller(int ID, string name, int price, ShopSeller* shop);

	bool Add(CommoditySeller* commodity);
	bool Remove(CommoditySeller* commodity);

	virtual bool HasCommodity(CommoditySeller* commodity);
	virtual bool Enough(int amount);
	virtual bool Sell(int amount);
	virtual void Display();
};

#endif 