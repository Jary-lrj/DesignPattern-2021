#include<iostream>
#include<iomanip>
#include"commodity_seller.h"

using std::cout;
using std::endl;

//===================== CommoditySeller ��Ʒ�����========================

CommoditySeller::CommoditySeller(int ID, string name, int price, ShopSeller* shop) {
	this->ID = ID;
	this->name = name;
	this->price = price;
	this->owner = shop;
}

/*
���ܣ�����Ʒ����������Ʒ
Ĭ�Ϸ���false
*/
bool CommoditySeller::Add(CommoditySeller* commodity) {
	return false;
}

/*
���ܣ�����Ʒ������Ƴ���Ʒ
Ĭ�Ϸ���false
*/
bool CommoditySeller::Remove(CommoditySeller* commodity) {
	return false;
}

//===================== SingleCommoditySeller ������Ʒ��========================

SingleCommoditySeller::SingleCommoditySeller(int ID, string name, int price, ShopSeller* shop, int amount) 
	: CommoditySeller(ID, name, price, shop) {
	this->amount = amount;
}


/*
���ܣ��ж���Ʒ������Ƿ���ĳ����Ʒ
������ָ����Ʒ�����ָ��
����SingleCommoditySeller�࣬���жϺ�������ָ�����Ʒ�Ƿ�Ϊ�Լ�
*/
bool SingleCommoditySeller::HasCommodity(CommoditySeller* commodity) {
	if (commodity = this) return true;
	else return false;
}

/*
���ܣ��ж���Ʒ����Ƿ����
*/
bool SingleCommoditySeller::Enough(int amount) {
	if (amount < this->amount) return true;
	else return false;
}

/*
���ܣ��۳���Ʒ
�������۳�����
�����������۳��������������true����֮����false
*/
bool SingleCommoditySeller::Sell(int amount) {
	if (Enough(amount)) {
		this->amount -= amount;
		return true;
	}
	else return false;
}

/*
���ܣ���ʾ��Ʒ��Ϣ
*/
void SingleCommoditySeller::Display() {
	cout << "ID: ";
	cout << std::left << std::setw(4) << this->ID;
	cout << "��Ʒ����: ";
	cout << std::left << std::setw(10) << this->name;
	cout << "�������: ";
	cout << std::left << std::setw(6) << this->amount;
	cout << "�۸�: ";
	cout << std::left << std::setw(6) << this->ID;
	cout << endl;
}

//===================== CompositeCommoditySeller �����Ʒ�� ========================

CompositeCommoditySeller::CompositeCommoditySeller(int ID, string name, int price, ShopSeller* shop) 
	:CommoditySeller(ID, name, price, shop) {	}

/*
���ܣ�����Ʒ����������Ʒ
�����Ʒ��������д���Ʒ�򷵻�false�����������Ʒ������true
*/
bool CompositeCommoditySeller::Add(CommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //�����Ʒ���Ѿ����ڴ���Ʒ
		return false;
	}
	else { //�����Ʒ�в����ڴ���Ʒ 
		this->commodity_list.push_back(commodity);
		return true;
	}
}

/*
���ܣ�����Ʒ������Ƴ���Ʒ
�����Ʒ������޴���Ʒ�򷵻�false�������Ƴ���Ʒ������true
*/
bool CompositeCommoditySeller::Remove(CommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //�����Ʒ�д��ڴ���Ʒ
		this->commodity_list.remove(commodity);
		return true;
	}
	else return false; //�����Ʒ�в����ڴ���Ʒ 
}

/*
���ܣ��ж���Ʒ����Ƿ���ĳ����Ʒ
������ָ����Ʒ�����ָ��
����CompositeCommoditySeller�࣬�����ж�����е�ÿ����Ʒ�Ƿ��д���Ʒ
*/
bool CompositeCommoditySeller::HasCommodity(CommoditySeller* commodity) {
	for (auto my_commodity : this->commodity_list) {
		if (my_commodity->HasCommodity(commodity)) { //���ĳ����Ʒ���д���Ʒ
			return true;
		}
	}
	return false;
}

/*
���ܣ��۳���Ʒ
�������۳�����
�����ж������Ʒ�еĵ�����Ʒ����Ƿ����
*/
bool CompositeCommoditySeller::Enough(int amount) {
	for (auto my_commodity : this->commodity_list) {
		if (!my_commodity->Enough(amount)) { //���ĳ����Ʒ�Ŀ�治����
			return false;
		}
	}
	return true;
}

/*
���ܣ��۳���Ʒ
������������Ʒ
��������Ʒ�е�ÿһ��������Ʒ������������㣬�������۳�����е�ÿ����Ʒ
*/
bool CompositeCommoditySeller::Sell(int amount) {
	if (Enough(amount)) { //�ж�ÿ����Ʒ�Ŀ�涼����
		for (auto my_commodity : this->commodity_list) {
			my_commodity->Sell(amount);
		}
		return true;
	}
	else return false; //����Ʒ��治��
}

/*
���ܣ���ʾ�����Ʒ��Ϣ��������չʾ������Ʒ�۸���Ϣ
*/
void CompositeCommoditySeller::Display() {
	cout << "ID: ";
	cout << std::left << std::setw(4) << this->ID;
	cout << "��Ʒ���: ";
	cout << std::left << std::setw(10) << this->name;
	cout << endl;
	cout << "{" << endl;
	for (auto my_commodity : this->commodity_list) {
		my_commodity->Display();
	}
	cout << "}" << endl;
}