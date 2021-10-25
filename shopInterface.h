#pragma once
//
// Created by liruijie666 on 2021/10/25.
//
using namespace std;

#ifndef SOFTWAREARC_SHOPMANAGER_H
#define SOFTWAREARC_SHOPMANAGER_H

#include <iostream>
#include <list>
#include <utility>
#include "shop.h"

/*
*   Factory Mode-����ģʽ������������ͬ���͵ĵ��̡�
*   ֻ��Ҫ����һ�����͵Ĳ�������������������Ӧ�ĵ��̣�����Ϊָ�룩��
*   ����һ���������ָ�롣
*/
class ShopFactory {
public:
    // �������̵Ĺ�����
    Shop* createShop(string type);
};

/*
*   �鿴���̵���ز�����ȫ����װ���˽ӿڿɹ�������ϵͳ���á�
*/
class shopInterface {
private:
    list<Shop*> _shopList;
    ShopFactory _shopFactory;

public:

    void showAllShops();

    Shop* createShop(string type);

    void editStorage(int ID);

    void initialize();

    void mainInterface();
};

#endif //SOFTWAREARC_SHOPMANAGER_H
