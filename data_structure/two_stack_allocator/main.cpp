#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>

class TwoStackAllocator{
private:
    int topStack1;
    int topStack2;
    int memorySize;
    int *memory;
    
public:
    TwoStackAllocator(int memorySize){
        this->memorySize = memorySize;
        this->memory = new int[memorySize];
        this->topStack1 = -1;
        this->topStack2 = memorySize;
        }

    void pushStack1(int value){
        this->topStack1++;
        if(this->topStack1 == this->topStack2){
            throw -1;
            }
        this->memory[this->topStack1] = value;
        }
    
    void pushStack2(int value){
        this->topStack2--;
        if(this->topStack2 == this->topStack1){
            throw -2;
            }
        this->memory[this->topStack2] = value;
        }
        
    int popStack1(){
        if(this->topStack1 == -1){
            throw -3;
        }
        int value = this->memory[this->topStack1];
        this->topStack1--;
        return value;
        }
        
    int popStack2(){
        if(this->topStack2 == this->memorySize){
            throw -4;
            }
        int value = this->memory[this->topStack2];
        this->topStack2++;
        return value;
        }
        
    bool isEmptyStack1(){
        return this->topStack1 == -1;
        }
        
    bool isEmptyStack2(){
        return this->topStack2 == this->memorySize;
        }
    
    ~TwoStackAllocator(){
        delete [] this->memory;
        }
    };

int main(int argc, char **argv)
{
    TwoStackAllocator *twoStackAllocator = new TwoStackAllocator(20);
    
    try{
        twoStackAllocator->popStack1();
        }
    catch(int exc){
        std::cout << "stack1 is empty" << std::endl;
        }
        
    try{
        twoStackAllocator->popStack2();
        }
    catch(int exc){
        std::cout << "stack2 is empty" << std::endl;
        }
        
    twoStackAllocator->pushStack1(1);
    twoStackAllocator->pushStack1(2);
    twoStackAllocator->pushStack1(3);
    twoStackAllocator->pushStack2(4);
    twoStackAllocator->pushStack2(5);
    twoStackAllocator->pushStack2(6);
    
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> uid_prob(0, 1);
    int i = 7;
    
    while(!twoStackAllocator->isEmptyStack1() || !twoStackAllocator->isEmptyStack2()){
        double probability = uid_prob(gen);
        
        if(probability <= 0.25){
            try{
                twoStackAllocator->pushStack1(i);
                std::cout << "Push value " << i << " into stack1" << std::endl;
                i++;
                }
            catch(int exc){
                std::cout << "Stack1 overflow" << i << std::endl;
                delete twoStackAllocator;
                return 0;
                }
            }
            
        if(probability > 0.25 && probability <= 0.5){
            try{
                twoStackAllocator->pushStack2(i);
                std::cout << "Push value " << i << " into stack2" << std::endl;
                i++;
                }
            catch(int exc){
                std::cout << "Stack2 overflow " << i << std::endl;
                delete twoStackAllocator;
                return 0;  
                }
            }
            
        if(probability > 0.5 && probability <= 0.75){
            try{
                int value = twoStackAllocator->popStack1();
                std::cout << "Value " << value << " deleted from stack1." << std::endl;
                }
            catch(int exc){
                std::cout << "stack1 is empty" << std::endl;
                }
            }
            
        if(probability > 0.75){
            try{
                int value =twoStackAllocator->popStack2();
                std::cout << "Value " << value << " deleted form stack2." << std::endl;
                }
            catch(int exc){
                std::cout <<"stack2 is empty" << std::endl; 
                }
            }
        }
    delete twoStackAllocator;
	return 0;
}
