#include <stdio.h>
#include <iostream>
class NodeCard{
private:
    short tag;
    short suite;
    short rank;
    char *title;
    NodeCard *next;
public:
    NodeCard(short suite, short rank){
        this->tag = 0;
        if(suite < 1 || suite > 4){
            throw -1;
            }
        if (rank < 1 || rank > 13){
            throw -1;
            }
        this->suite = suite;
        this->rank = rank;
        char suite_char;
        if(suite == 1){
            suite_char ='C';
            }
        else if(suite == 2){
            suite_char = 'D';
            }
        else if(suite == 3){
            suite_char = 'H';
            }
        else if(suite == 4){
            suite_char = 'S';
            }
        this->title = new char[5];
        if(rank / 10 > 0)
        {
           sprintf(this->title, " %d %c", rank, suite_char); 
            }
        else{
            sprintf(this->title, "  %d %c", rank, suite_char);
            }
        this->next = nullptr;
        }
        
    void setTag(short tag){
        if(tag < 0 || tag > 1){
            throw -1;
            }
        this->tag = tag;
        }
        
    void setNext(NodeCard *nextNode){
        this->next = nextNode; 
        }
        
    NodeCard* getNext(){
        return this->next;
        }
        
    char* getTitle(){
        return this->title;
        }
        
    int getTag(){
        return this->tag;
        }
    
    ~NodeCard(){
        delete [] title;
        }
    };
    
class CardDeck{
private:
   NodeCard *top;
   NodeCard *tail;
public:
   CardDeck(){
       this->top = nullptr;
       }
       
   void addCardToTop(short suite, short rank){
       NodeCard *newCard = new NodeCard(suite, rank);
        newCard->setNext(this->top);
        this->top = newCard;
        this->top->setTag(0);
       }
       
    void addCardToTail(short suite, short rank){
        NodeCard *newCard = new NodeCard(suite, rank);
        if(this->top == nullptr){
            newCard->setNext(this->top);
            this->top = newCard;
            this->top->setTag(1);
            }
        else{
            NodeCard *currentCard = this->top;
            while(currentCard->getNext() != nullptr){
                currentCard = currentCard->getNext();
                }
            currentCard->setNext(newCard);
            newCard->setTag(1);
            }
        }
       
    int getSize(){
        int count = 0;
        NodeCard *current = this->top;
        while(current != nullptr){
            current = current->getNext();
            count++;
            }
        return count;
        }
        
    NodeCard* getTopCard(){
        NodeCard *topCard = this->top;
        if(this->top != nullptr){
            this->top = this->top->getNext();
            }
        return topCard;
        }
        
    NodeCard* getTailCard(){
        if(this->top == nullptr){
            return nullptr;
            }
        NodeCard *currentCard = this->top;
        if(currentCard->getNext() == nullptr){
            this->top = nullptr;
            return currentCard;
            }
        else{
            while(currentCard->getNext()->getNext() != nullptr){
                currentCard = currentCard->getNext();
                }
                NodeCard *result = currentCard->getNext();
                currentCard->setNext(nullptr);
                return result;
            }
        }
        
    void printCards(){
            NodeCard *currentCard = this->top;
            while(currentCard != nullptr){
                char *title =currentCard->getTitle();
                if(currentCard->getTag() == 1){
                    char *resultTitle = new char[7];
                    sprintf(resultTitle, "(%s)", title);
                    std::cout << resultTitle << std::endl;
                    delete [] resultTitle;
                    }
                else{
                    std::cout << title << std::endl;
                    }
                currentCard = currentCard->getNext();
                }
        }
        
    ~CardDeck(){
        NodeCard *current = this->top;
        while(current != nullptr){
            NodeCard *deletedCard = current;
            current = current->getNext();
            delete deletedCard; 
            }
        }
        };
    
    void testConstructorInvalidValue(short suite, short rank){
        try{
           NodeCard *node = new NodeCard(suite,rank);
           }
        catch(int exc){
           std::cout << "Invalid value" << std::endl;
           }
        }
    void testSetTagInvalidValue(short tag){
        NodeCard *node;
        try{
            node = new NodeCard(2,2);
            node->setTag(tag);
            }
        catch(int exc){
            std::cout << "Invalid value" << std::endl;
            delete node;
            }
        }
        
    int printDeckSize(CardDeck *cardDeck){
        int sizeCardDeck = cardDeck->getSize();
        std::cout << "number cards in the deck " << sizeCardDeck << "." << std::endl;
        return sizeCardDeck;
        }

int main(int argc, char **argv)
{
    testConstructorInvalidValue(0, 1);
    testConstructorInvalidValue(1, 0);
    testConstructorInvalidValue(5, 1);
    testConstructorInvalidValue(1, 14);
    testSetTagInvalidValue(-1);
    testSetTagInvalidValue(2);
    CardDeck *cardDeck = new CardDeck;
    cardDeck->printCards();
    cardDeck->addCardToTop(1, 10);
    cardDeck->addCardToTail(1, 6);
    cardDeck->addCardToTop(4, 3);
    cardDeck->addCardToTail(4, 4);
    cardDeck->addCardToTop(2, 2);
    cardDeck->addCardToTail(2, 3);
    cardDeck->printCards();
    int size = printDeckSize(cardDeck);
    for(int i = 1; i <= size + 1; i++){
        NodeCard *topCard = cardDeck->getTopCard();
        if(topCard == nullptr){
            std::cout << "top card is null" << std::endl;
            }
        else{
            std::cout << topCard->getTitle() << std::endl;
            printDeckSize(cardDeck);
            delete topCard;
            }
        }
    CardDeck *tailCardDeck = new CardDeck;
    tailCardDeck->printCards();
    tailCardDeck->addCardToTail(1, 10);
    tailCardDeck->addCardToTop(1, 6);
    tailCardDeck->addCardToTail(4, 3);
    tailCardDeck->addCardToTop(4, 4);
    tailCardDeck->addCardToTail(2, 2);
    tailCardDeck->addCardToTop(2, 3);
    tailCardDeck->printCards();
    size = printDeckSize(tailCardDeck);
     for(int i = 1; i <= size + 1; i++){
        NodeCard *tailCard = tailCardDeck->getTailCard();
        if(tailCard == nullptr){
            std::cout << "tail card is null" << std::endl;
            }
        else{
            std::cout << tailCard->getTitle() << std::endl;
            printDeckSize(tailCardDeck);
            delete tailCard;
            }
        }
    delete cardDeck;
    delete tailCardDeck;
	return 0;
}
