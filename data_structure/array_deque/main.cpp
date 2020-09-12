#include <stdio.h>
#include <iostream>

class ArrayDeque{
private:
    int size;
    int *array;
    int front;
    int rear;
public:
    ArrayDeque(int size){
        this->size = size;
        this->array = new int[size];
        this->front = this->rear = 0;
    }
    
    void addTailItem(int value){
        if(this->rear == this->size - 1){
            this->rear = 0;
        }
        else{
            this->rear++;
            }
        if(this->rear == this->front){
               throw -1;
            }
        this->array[this->rear] = value;
        }
        
    void addTopItem(int value){
        this->array[this->front] = value;
        if(this->front == 0){
            this->front = this->size - 1;
            }
        else{
            this->front--;
            }
        if(this->front == this->rear){
            throw -1;
            }
        }
        
    int deleteTopItem(){
        if(this->front == this->rear){
            throw -2;
            }
        if(this->front == this->size -1){
            this->front = 0;
            }
        else{
            this->front++;
            }
        return this->array[this->front];
        }
        
    int deleteTailItem(){
        if(this->rear == this->front){
            throw -2;
            }
        int value = this->array[this->rear];
        if(this->rear ==0){
            this->rear = this->size - 1; 
            }
        else{
            this->rear--;
            }
        return value;
        }
        
    bool isEmpty(){
        return this->front == this->rear;
        }
        
    ~ArrayDeque(){
        delete [] this->array;
        }
    };
    
int main(int argc, char **argv){
    ArrayDeque *arrayDeque = new ArrayDeque(10);
    
    try{
        arrayDeque->deleteTopItem();
        }
    catch(int exc){
        std::cout << "Deque is empty"<< std::endl;
        }
        
    for(int i = 1; i <= 10; i++){
        try{
            arrayDeque->addTailItem(i);
            std::cout << i << " ";
            }
        catch(int exc){
            std::cout << "\nDeque overflow " << i << std::endl;
            delete arrayDeque;
            }
        }
    
    arrayDeque = new ArrayDeque(10);    
    
    for(int i = 1; i < 10; i++){
        arrayDeque->addTailItem(i);
        }
        
    while(!arrayDeque->isEmpty()){
        int value = arrayDeque->deleteTopItem();
        std::cout << value << " ";
        }
    std::cout << std::endl;
    delete arrayDeque;
    arrayDeque = new ArrayDeque(10);
        
    for(int i = 1; i < 10; i++){
        arrayDeque->addTopItem(i);
        }
        
    while(!arrayDeque->isEmpty()){
        int value = arrayDeque->deleteTailItem();
        std::cout << value << " ";
        }
    
    std::cout << std::endl;
    delete arrayDeque;
	return 0;
}

