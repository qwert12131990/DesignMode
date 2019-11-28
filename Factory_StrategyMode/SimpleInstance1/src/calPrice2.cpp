/*
最大替换在于使用switch替换if
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

class Buyer
{
public:
    Buyer()
    {
        superVipExpiredDays = 6;
        superVipLeadDiscountTimes = 0;
    }

    double calPrice(double orderPrice, BuyerType buyerType) {
        switch (buyerType)
        {
            case PARTICULARLY_VIP:
                if (orderPrice > 30.0)
                    return orderPrice * 0.7;
                break;
            case SUPER_VIP;
                return orderPrice * 0.8;
            case VIP;
                if(superVipExpiredDays < 7 && superVipLeadDiscountTimes =0)
                {
                    superVipLeadDiscountTimes++;
                    return orderPrice * 0.8;
                } 
                return orderPrice * 0.7;
            default:
                break;
        }

        return orderPrice;
    }

private:
    int superVipExpiredDays;
    int superVipLeadDiscountTimes;

};

int main()
{
    Buyer buyer = new Buyer();
    cout << buyer.calPrice(300, PARTICULARLY_VIP) <<endl;
    cout << buyer.calPrice(300, SUPER_VIP) <<endl;
    cout << buyer.calPrice(300, VIP) <<endl;
    return 0;
}
