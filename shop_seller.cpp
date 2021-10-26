#include<iostream>
#include<iomanip>
#include"shop_seller.h"

using std::cout;
using std::endl;

ShopSeller::ShopSeller(int ID, string name, string type, string date, list<string*> commentList, list<CompositeCommoditySeller*> commodityList, Seller* seller) {
	this->ID = ID;
	this->name = name;
	this->type = type;
	this->date = date;
	this->commentList = commentList;
	this->commodityList = commodityList;
	this->owner = seller;
}

/*
���ܣ���ӵ�������
*/
void ShopSeller::AddComment(string* comment) {
	this->commentList.push_back(comment);
}

/*
���ܣ�չʾ��������
*/
void ShopSeller::DisplayCommentList() {
	cout << "�������ۣ�" << endl;
	for (auto my_comment : this->commentList) {
		cout << *my_comment << endl;
	}
}

/*
���ܣ��жϵ�����Ʒ�б����Ƿ���ĳ����Ʒ
������ָ����Ʒ�����ָ��
*/
bool ShopSeller::HasCommodity(CompositeCommoditySeller* commodity) {
	for (auto my_commodity : this->commodityList) {
		if (my_commodity->HasCommodity(commodity)) {
			return true;
		}
	}
}

/*
���ܣ��ڵ�����Ʒ�б��������Ʒ
����������б����Ѵ��ڴ���Ʒ�򷵻�false�����������Ʒ������true
*/
bool ShopSeller::AddCommodity(CompositeCommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //�˵����Ѵ���������Ʒ
		return false;
	}
	else {
		this->commodityList.push_back(commodity);
		return true;
	}
}

/*
���ܣ��ڵ�����Ʒ�б����Ƴ���Ʒ
����������б��в����ڴ���Ʒ�򷵻�false������ɾ����Ʒ������true
*/
bool ShopSeller::RemoveCommodity(CompositeCommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //�˵����Ѵ���������Ʒ
		this->commodityList.remove(commodity);
		return true;
	}
	else return false;
}

/*
���ܣ���ʾ������Ʒ�б�
*/
void ShopSeller::DisplayCommodityList() {
	cout << "��Ʒ�б�" << endl;
	for (auto my_composite_commodity : this->commodityList) {
		cout << "ID: ";
		cout << std::left << std::setw(4) << this->ID;
		cout << "��Ʒ���: ";
		cout << std::left << std::setw(10) << this->name;
		cout << endl;
		cout << "{" << endl;
/*		for (auto my_commodity : CompositeCommpditySeller::commodity_list) {
			
		}
		cout << "}" << endl; */
	}
}
