#include <iostream>

int main()
{
    int m, n, r;
	std::cin >> m >> n;
    do{
       r = m % n;
       m = n;
       n = r; 
        } while(r != 0);
    std::cout << m;
	return 0;
}
