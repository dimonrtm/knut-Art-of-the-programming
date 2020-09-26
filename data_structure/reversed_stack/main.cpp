#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>

class StackNode{
private:
    int data;
    StackNode *next;
public:
    StackNode(int data, StackNode *next){
        this->data = data;
        this->next = next;
        }
        
    int getData(){
        return this->data;
        }
        
    StackNode* getNext(){
        return this->next;
        }
        
    void setNext(StackNode *nextNode){
        this->next = nextNode;
        }
        
    ~StackNode(){}
    };
    
class ReversedStack{
private:
    StackNode *top;
public:
    ReversedStack(){
        this->top = nullptr;
        }
        
    void push(int value){
        StackNode *newStackNode = new StackNode(value, top);
        this->top = newStackNode;
        }
        
    int pop(){
        if(this->top == nullptr){
            throw -1;
            }
        StackNode *deletedStackNode = this->top;
        this->top = deletedStackNode->getNext();
        int value = deletedStackNode->getData();
        delete deletedStackNode;
        return value;
        }
        
    void reverse(){
        if(this->top == nullptr){
            return;
            }
        StackNode *reversed = nullptr;
        StackNode *current = this->top;
        while(current != nullptr){
            this->top = current->getNext();
            current->setNext(reversed);
            reversed = current;
            current = this->top;
            }
        this->top = reversed;
        }
        
    bool isEmpty(){
       return this->top == nullptr;
        }
        
    ~ReversedStack(){
        while(!this->isEmpty()){
            this->pop();
            }
        }
    };

int main(int argc, char **argv)
{
    ReversedStack *reversedStack = new ReversedStack;
    
    try{
        reversedStack->pop();
        }
    catch(int exc){
        std::cout << "stack is empty" << std:: endl;
        }
    
    reversedStack->push(1);
    reversedStack->push(2);
    reversedStack->push(3);
    delete reversedStack;
    
    ReversedStack *simpleStack = new ReversedStack;
    reversedStack = new ReversedStack;
    
    for(int i = 1; i <= 10; i++){
        simpleStack->push(i);
        reversedStack->push(i);
        }
        
    reversedStack->reverse();
    
    std::cout << "simple" << std::endl;
    while(!simpleStack->isEmpty()){
        int value = simpleStack->pop();
        std::cout << value << " "; 
        }
    std::cout << std::endl;
    
    std::cout << "reversed" << std::endl;    
    while(!reversedStack->isEmpty()){
        int value = reversedStack->pop();
        std::cout << value << " ";
        }
    std::cout << std::endl;
    
    delete reversedStack;
    delete simpleStack;
	return 0;
}
