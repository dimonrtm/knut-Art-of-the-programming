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
        
    ~StackNode(){}
    };
    
class LinkedStack{
private:
    StackNode *top;
public:
    LinkedStack(){
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
        
    bool isEmpty(){
       return this->top == nullptr;
        }
        
    ~LinkedStack(){
        while(!this->isEmpty()){
            this->pop();
            }
        }
    };

int main(int argc, char **argv)
{
    LinkedStack *linkedStack = new LinkedStack;
    
    try{
        linkedStack->pop();
        }
    catch(int exc){
        std::cout << "stack is empty" << std:: endl;
        }
    
    linkedStack->push(1);
    linkedStack->push(2);
    linkedStack->push(3);
    delete linkedStack;
    
    linkedStack = new LinkedStack;
    linkedStack->push(1);
    linkedStack->push(2);
    linkedStack->push(3);
    std::mt19937 gen(time(nullptr));
    std::uniform_real_distribution<> uid_prob(0, 1);
    int i = 4;
    
    while(!linkedStack->isEmpty()){
        double probability = uid_prob(gen);
        
        if(probability <= 0.50){
            linkedStack->push(i);
            std::cout << "Value " << i << " pushed into stack." << std::endl;
            i++;
            }
        
        if(probability > 0.50){
            int value = linkedStack->pop();
            std::cout << "Value " << value << " deleted from stack." << std::endl; 
            }
        }
    delete linkedStack;
	return 0;
}
