#include <iostream>

int main()
{
    int m, n, result;
	std::cin >> m >> n;
    while(true){
        m = m % n;
        if(m == 0){
            result = n;
            break;
            }
        n = n % m;
        if(n == 0){
            result = m;
            break;
            }
        }
    std::cout << result;
	return 0;
}