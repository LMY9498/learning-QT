#ifndef STRUCTURAL_BODY_H
#define STRUCTURAL_BODY_H
#include <QString>
#define MAX 1000

struct Person
{
    //姓名
    QString m_Name;
    //性别
    QString m_Sex;
    //年龄
    QString m_Age;
    //电话
    QString m_Phone;
    //住址
    QString m_Address;
};
struct Addressbooks
{
    //通讯录中保存的联系人的数组
    struct Person personArray[MAX];
    //通讯录中当前记录联系人个数
    int m_Size;

};


#endif // STRUCTURAL_BODY_H
