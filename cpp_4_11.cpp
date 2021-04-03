#include <iostream>
#include <string>
using namespace std;

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    inflatable guest = {
        "Glorious Gloria",
        1.88,
        29.99
    };

    inflatable pal = {
        "Audacious Arthur",
        3.12,
        32.99
    };

    cout << "지금 판매하고 있는 모형풍선은 " << guest.name << "와 " << pal.name << "입니다.\n";

    cout << "두 제품을 $" << guest.price + pal.price << "에 드리겠습니다.\n";

    return 0;
}