#pragma once

using namespace std;

#ifndef SOFTWAREARC_SHOPMANAGER_H
#define SOFTWAREARC_SHOPMANAGER_H

#include <iostream>
#include <list>
#include <utility>
#include <string>
#include "shop.h"
#include "shopFilter.h"
#include "../Basic/welcome.h"
#include "../Customer/Customer.h"
#include "../Commodity/Commodity.h"

/*
 * 设计模式-工厂模式 Factory Mode
 * 顾名思义，工厂模式是用来生产对应的对象的。
 * 该工厂只有一个函数，参数为店铺的类型，可以根据用户提供的类型生产对应的店铺对象。
 */
class ShopFactory {
public:
    Shop *createShop(string type);
};
/*
 * 店铺子系统和整体系统进行耦合的接口类
 * 里面有对子系统内操作所用的临时数据，以及对上述临时数据进行操作的方法。
 * 详细介绍将在内部进行。
 */
class shopInterface {

private:
    // 店铺列表、货物列表、用来生产的工厂
    list<Shop *> _shopList;
    map<CommodityInformation *, int> _commodityList;
    ShopFactory _shopFactory; // Factory Mode. In order to create some shops by users or admins.

public:
    //获取所有货物列表
    map<CommodityInformation *, int> &getCommodityList() { return _commodityList; }

    //展示所有货物列表
    void showCommodityList(map<CommodityInformation *, int> List);

    //更新指定货物列表
    void setCommodityList(const map<CommodityInformation *, int> &commodityList) { _commodityList = commodityList; }

    //获取所有店铺列表
    const list<Shop *> &getShopList() const { return _shopList; };

    //展示所有店铺
    void showAllShops();

    //生产店铺
    Shop *createShop(string type);

    // 用户为指定ID的店铺添加评价
    void addRemark(int, Customer *customer);

    // 查看指定ID店铺的详细信息
    void checkShop(int ID);

    // 初始化接口类中的相关信息
    void initialize();

    // 展示给用户以进行操作的主界面
    void mainInterface(Customer *customer);

    // 根据店铺评分筛选店铺
    void filterShopByScore();

    // 将货物列表按所属商店ID同步到对应商店
    void prepareGoods(int ID);

    // 展示所有商店的所有货物
    void showAllGoodsInShops();

    // 查看指定ID商店中的所有货物
    void checkGoods(int ID);

    // 将指定ID的商品加入购物车
    CommodityInformation *addCart(int ID);
};

#endif //SOFTWAREARC_SHOPMANAGER_H