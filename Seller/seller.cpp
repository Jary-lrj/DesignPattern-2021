#include<iostream>
#include"seller.h"

using std::cout;
using std::endl;

Seller::Seller(list<ShopSeller*> shopList) {
	this->shopList = shopList;
}

/*
���ܣ��жϵ����б����Ƿ���ĳ������
������ָ����̵�ָ��
*/
bool Seller::HasShop(ShopSeller* shop) {
	for (auto my_shop : this->shopList) {
		if (shop == my_shop) return true;
	}
	return false;
}

/*
���ܣ���ӵ���
*/
bool Seller::AddShop(ShopSeller* shop) {
	if (HasShop(shop)) {
		return false;
	}
	else {
		this->shopList.push_back(shop);
		return true;
	}
}

/*
���ܣ��Ƴ�����
*/
bool Seller::RemoveShop(ShopSeller* shop) {
	if (HasShop(shop)) {
		this->shopList.remove(shop);
		return true;
	}
	else return false;
}

/*
���ܣ�չʾ�����б�
*/
void Seller::DisplayShop() {
	cout << "�����б�" << endl;
	for (auto my_shop : this->shopList) {
		cout << "��������:" << my_shop->GetName;
		cout << "��������:" << my_shop->GetType;
		cout << "���̴�������:" << my_shop->GetDate;
		cout << endl;
	}
}
