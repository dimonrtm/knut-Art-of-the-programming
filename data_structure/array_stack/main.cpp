#include <stdio.h>
#include <iostream>

class ArrayStack{
private:
    int size;
    int *array;
    int top;
public:
    ArrayStack(int size){
        this->size = size;
        this->array = new int[size];
        this->top = -1;
        }
    
    void push(int value){
        this->top++;
        if(this->top > this->size - 1){
           this->top--;
           throw -1;
        }
        else{
            this->array[this->top] = value;
            }
    }
    
    int pop(){
        if(this->top == -1){
            throw -2;
            }
        else{
            int value = this->array[this->top];
            this->top--;
            return value;
            }
        }
        
    bool isEmpty(){
        return this->top == -1;
        }
    
    ~ArrayStack(){
        delete [] this->array;
        }
    };

int main(int argc, char **argv)
{
    ArrayStack *stack = new ArrayStack(10);
    try{
        stack->pop();
        }
    catch(int exc){
        if(exc == -2){
            std::cout << "stack is empty" << std::endl;
            }
        }
    for(int i = 1; i <= 11; i++){
        try{
            stack->push(i);
            std::cout << i << " ";
            }
        catch(int exc){
            std::cout << "\nstack overflow " << i << std::endl;
            }
        }
    while(!stack->isEmpty()){
        int value = stack->pop();
        std::cout << value << " ";
        }
    std::cout << std::endl;
    delete stack;
	return 0;
}
