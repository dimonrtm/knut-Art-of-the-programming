#include <iostream>

int max(int *array, int *index, int size){
    *index = size - 1;
    int max = array[size - 1];
    for(int i = size - 2; i >= 0; i--){
        if(array[i] <= max){
            continue;
            }
        else{
            *index = i;
            max = array[i];
            }
        }
    return max;
    }

int main(int argc, char **argv)
{
    int n;
    int index;
	std::cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        std::cin >> array[i];
        }
    int maximum = max(array, &index, n);
    std::cout << maximum << "\n";
    std::cout << index << "\n";
    delete [] array;
	return 0;
}
