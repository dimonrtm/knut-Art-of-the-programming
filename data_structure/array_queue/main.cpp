#include <stdio.h>
#include <iostream>

class ArrayQueue{
private:
    int size;
    int *array;
    int front;
    int rear;
public:
    ArrayQueue(int size){
        this->size = size;
        this->array = new int[size];
        this->front = this->rear = 0;
    }
    
    void addItem(int value){
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
        
    int deleteItem(){
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
        
    bool isEmpty(){
        return this->front == this->rear;
        }
        
    ~ArrayQueue(){
        delete [] this->array;
        }
    };
    
int main(int argc, char **argv){
    ArrayQueue *arrayQueue = new ArrayQueue(10);
    
    try{
        arrayQueue->deleteItem();
        }
    catch(int exc){
        std::cout << "Queue is empty"<< std::endl;
        }
        
    for(int i = 1; i <= 10; i++){
        try{
            arrayQueue->addItem(i);
            std::cout << i << " ";
            }
        catch(int exc){
            std::cout << "\nQueue overflow " << i << std::endl;
            delete arrayQueue;
            }
        }
    
    arrayQueue = new ArrayQueue(10);    
    
    for(int i = 1; i < 10; i++){
        arrayQueue->addItem(i);
        }
        
    while(!arrayQueue->isEmpty()){
        int value = arrayQueue->deleteItem();
        std::cout << value << " ";
        }
    
    std::cout << std::endl;
    delete arrayQueue;
	return 0;
}
