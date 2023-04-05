#ifndef __DECO_H__
#define __DECO_H__

#include <iostream>
using namespace std;

class Cake
{
public:
    virtual void showCake()=0;
    virtual ~Cake(){};
    std::string name;
};
 
class ConcreteCake :public Cake
{
public:
    ConcreteCake()
    {
        name = "ԭʼ����";
    }
    void showCake(){ std::cout << name.c_str() << std::endl; };
    virtual  ~ConcreteCake(){};
};

class CakeDecrator :public Cake
{
protected:
    Cake* pCake;  //ά��һ��Cake��������ã�ΪCake�������װ��
public:
    virtual void showCake() = 0;
    virtual	~CakeDecrator(){};
};

class CakeDecratorMilk : public CakeDecrator
{
    public:
    CakeDecratorMilk(Cake* pCake)
    {
        this->pCake = pCake;
    }
    void showCake()
    {
        this->name = pCake->name + "������";
        std::cout << name.c_str()<<std::endl;
    };
    virtual ~CakeDecratorMilk(){};
};

#endif 