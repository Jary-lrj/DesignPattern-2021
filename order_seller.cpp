#include<iostream>
#include<iomanip>
#include"order_seller.h"

using std::cout;
using std::endl;

//===================== OrderItemSeller ������Ʒ��Ŀ��========================

OrderItemSeller::OrderItemSeller(SingleCommoditySeller* singleCommodity, CompositeCommoditySeller* compositeCommodity, int amount) {
	this->singleCommodity = singleCommodity;
	this->compositeCommodity = compositeCommodity;
	this->amount = amount;
}

SingleCommoditySeller* OrderItemSeller::GetSingleCommodityPtr() {
	return 
}


