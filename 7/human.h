#ifndef __HUMAN_H__
#define __HUMAN_H__
//class define
class Human{
public:
    Human(const char *name,int age);
    Human(const char *name);
    const char *getName();
    void setAge(int age);
    int getAge();
    void print();

private:
    const char *name;
    int age;
};

#endif /*__HUMAN_H__*/