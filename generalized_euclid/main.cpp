#include <iostream>

int main()
{
	int m, n, a1, b, a, b1, c, d, t, q, r;
    std::cin >> m >> n;
    a1 = b = 1;
    a = b1 = 0;
    c = m;
    d = n;
    while(true){
        q = c / d;
        r = c % d;
        if(r == 0){
            break;
            }
        c = d;
        d = r;
        t = a1;
        a1 = a;
        a = t - q * a;
        t = b1;
        b1 = b;
        b = t - q * b;
        }
    std ::cout << d << " " << a << " " << b;    
	return 0;
}
