/*
switch可以使用继承类替换
并且继承好处可以有效分割该功能类型下所需要的成员变量
和前两个版本比较，发现少了3个if或者1个switch。好处显而易见，在使用对象时，可确认目标对象，少了if的判断
但是，会发现一个问题，需要使用该类时，手动创建所使用策略类。另外，也可能存在很多策略情况
客户端必须知道所有的策略类，并自行决定使用哪一个策略类。这就意味着客户端必须理解这些算法的区别，以便适时选择恰当的算法类。这种策略类的创建及选择其实也可以通过工厂模式来辅助进行。
由于策略模式把每个具体的策略实现都单独封装成为类，如果备选的策略很多的话，那么对象的数目就会很可观。可以通过使用享元模式在一定程度上减少对象的数量。
*/
#include <iostream>
#include <string>

using namespace std;

enum BuyerType
{
PARTICULARLY_VIP,
SUPER_VIP,
VIP
};

Class Buyer {
public:
    /**
     * 计算应付价格
     */
    virtual double calPrice(double orderPrice) = 0;
};

class ParticularlyVipBuyer : public Buyer 
{
public:
    @override
    double calPrice(double orderPrice) 
    {
        if (orderPrice > 30.0)
            return orderPrice * 0.7;
    }
};

/**
 * 超级会员
 */
class SuperVipBuyer : public Buyer 
{
public:
    @override
    double calPrice(double orderPrice) 
    {
        return orderPrice * 0.8;
    }
};

/**
 * 普通会员
 */
class VipBuyer implements Buyer {
public:
    VipBuyer()
    {
        superVipExpiredDays = 6;
        superVipLeadDiscountTimes = 0;
    }
    @override
    double calPrice(double orderPrice)
    {
        if(superVipExpiredDays < 7 && superVipLeadDiscountTimes =0)
        {
            superVipLeadDiscountTimes++;
            return orderPrice * 0.8;
        } 

        return orderPrice * 0.7;
    }
private:
    int superVipExpiredDays;
    int superVipLeadDiscountTimes;
}
/*
这个Cashier类就是一个上下文类，该类的定义体现了多用组合，少用继承、针对接口编程，不针对实现编程两个设计原则
组合+接口的方式，后面我们在推出其他类型会员的时候无须修改Cashier类。只要再定义一个类实现Buyer接口 就可以了
*/
class Cashier {

    /**
     * 会员,策略对象
     */
public: 
    Cashier(BuyerType buyerType)
    {
        buyer =  UserPayServiceStrategyFactory.getByUserType(vipType);
    }

    quote(double orderPrice) 
    {
        return this.buyer.calPrice(orderPrice);
    }
private:
    Buyer* buyer;
}

/*
工厂类
*/
class UserPayServiceStrategyFactory 
{

private:
    static Map<BuyerType,Buyer> services = new ConcurrentHashMap<BuyerType,Buyer>();

public:
    static Buyer getByUserType(BuyerType buyerType)
    {
        return services.get(buyerType);
    }

    static void register(BuyerType userType,Buyer buyer)
    {
        Assert.notNull(userType,"userType can't be null");
        services.put(userType, buyer);
    }
}

int main()
{
    //选择并创建需要使用的策略对象

    Cashier cashier = new Cashier(PARTICULARLY_VIP);
    
    cout << cashier.quote(300) <<endl;

    cashier = new Cashier(SUPER_VIP);

    cout << cashier.quote(300) <<endl;

    cashier = new Cashier(VIP);

    cout << cashier.quote(300) <<endl;

    return 0;
}
