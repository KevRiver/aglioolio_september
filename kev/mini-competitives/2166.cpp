#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define ll long long

struct Point
{
    ll x;
    ll y;
};

ll cross(const array<ll, 3>& x, const array<ll, 3> y)
{
    ll product = 0;
    for (int i = 0; i < 3; ++i)
    {
        int j = (i + 1) % 3;
        product += x[i] * y[j] - x[j] * y[i];
    }
    return product;
}

int main()
{
    int N;
    cin >> N;
    
    vector<Point> points(N);
    for (auto &p : points)
    {
        cin >> p.x >> p.y;
    }

    ll cross_product = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        const Point& a = points[0];
        const Point& b = points[i];
        const Point& c = points[i + 1];

        cross_product += cross({a.x, b.x, c.x}, {a.y, b.y, c.y});
    }

    if(cross_product < 0)
        cross_product = -cross_product;

    cout << (cross_product >> 1) << 
    "." << ((cross_product & 1) * 5) << '\n';

    return 0;
}