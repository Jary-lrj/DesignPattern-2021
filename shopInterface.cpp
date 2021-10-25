#include "shopInterface.h"

Shop* ShopFactory::createShop(string type) {
    if (type == "")
        return nullptr;
    if (type == "food")
        return new foodShop("�ߺ���˾���⵰�м�רӪ��",
            2,
            "food",
            "2013-09-18",
            10029,
            list<ShopRemark*>());
    else if (type == "clothes")
        return new clothesShop("�ߺ������ް���Ӫ�콢��",
            192,
            "clothes",
            "2004-12-01",
            2912,
            list<ShopRemark*>());
}

void shopInterface::showAllShops() {
    for (auto _shop : _shopList) {
        cout << "����: " << _shop->getShopName() << endl;
        cout << "���: " << _shop->getShopStorage() << endl << endl;
    }
}

Shop* shopInterface::createShop(string type) {
    Shop* new_shop = _shopFactory.createShop(type);
    return new_shop;
}

void shopInterface::editStorage(int ID) {
    {
        for (auto _shop : _shopList) {
            if (ID == _shop->getShopId()) {
                cout << "���޸ı����棺" << endl;
                int new_storage;
                cin >> new_storage;
                _shop->setShopStorage(new_storage);
                return;
            }
        }
        cout << "δ֪�ĵ���ID" << endl;
    }
}

void shopInterface::initialize() {
    _shopList.push_back(new foodShop("�ߺ��⵰�м�רӪ��",
        2,
        "food",
        "2013-09-18",
        10029,
        list<ShopRemark*>()));
    _shopList.push_back(new clothesShop("�ߺ������ް�רӪ��",
        192,
        "clothes",
        "2004-12-01",
        2912,
        list<ShopRemark*>()));
}


void shopInterface::mainInterface() {
    int choice_status;
    int ID;
    initialize();
    while (1) {
        cout << "��ӭ����������������������Ϣ��" << endl;
        cout << "��1�鿴���е����б���2�޸ĵ��̿�棻��0�˳�" << endl;
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
        case 1:
            showAllShops();
            break;
        case 2: {
            cout << "��������Ҫ�޸Ŀ��ĵ���ID��" << endl;
            cin >> ID;
            editStorage(ID);
            break;
        }
        default:
            cout << "δ֪������������룡" << endl;
            break;
        }
    }
}