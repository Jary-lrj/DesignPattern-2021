#include "shop.h"

// ���������ຯ�� - ��ȡ������ϸ��Ϣ
void ShopRemark::getRemark() {
    {
        cout << "--remark--" << endl;
        cout << "remark date: " << _remarkDate << endl;
        cout << "remark user: " << _remarkUser << endl;
        cout << "remark body: " << _remarkBody << endl;
    }
}

// �������ຯ�� - ��ȡ������Ϣ
void foodShop::execute() {
    {
        cout << "Shop Name: " + _shopName << endl;
        cout << "Shop ID: " << _shopID << endl;
        cout << "Shop Type: " + _shopType << endl;
        cout << "Shop Date: " + _shopDate << endl;
        for (auto remark : _shopRemarks) {
            remark->getRemark();
        }
    }
}

// �������ຯ�� - ��ȡ������Ϣ
void clothesShop::execute() {
    {
        cout << "Shop Name: " + _shopName << endl;
        cout << "Shop ID: " << _shopID << endl;
        cout << "Shop Type: " + _shopType << endl;
        cout << "Shop Date: " + _shopDate << endl;
        for (auto remark : _shopRemarks) {
            remark->getRemark();
        }
    }
}