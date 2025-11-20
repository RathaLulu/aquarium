#ifndef ALGUE_H
#define ALGUE_H 

class Algue
{
    public : 
    /*
    */
    Algue(int pSize, int pId);
    /*
    */
    ~Algue() = default;
    /*
    */
    void evPousse();
    /*
    */ 
    void beEat();
    /*
    */ 
    int getSize() const;
    /*
    */
    int getId() const; 
    /*
    */
    bool isDead() const; 
    /*
    */ 
    void printInfo() const; 
    private : 
    /*
    */ 
    int mSize = 0;  
    /*
    */
    const int mId = 0;
};

#endif