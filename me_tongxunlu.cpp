//————————————————————结构体应用二      手机通讯录——————————————————————
#include<iostream>
#include<string>
#include"caidan.h"
#include<stdlib.h>
#define MAX 1000
struct person//创建联系人结构体
{
    string name;//联系人的名字
    int age;//年龄
    int sex;//性别
    string num;//电话号码

};
struct textbox
{
    struct person personsarr[MAX];//创建联系人数组最大为1000
    int size;//记录联系人个数
};

void addperson(textbox* togxun)
{
    if (togxun->size == MAX)
    {
        cout << "通讯录已满无法再添加联系人" << endl;
        return;
    }
    else
    {
        string Name;
        cout << "请输入姓名" << endl;
        cin >> Name;
        togxun->personsarr[togxun->size].name = Name;//添加姓名

        cout << "请输入性别\n1------男 2--------女" << endl;
        int xing = 0;
        cin >> xing;
        while (xing != 1 && xing != 2)
        {
            cout << "性别输入错误，请重新输入：";
            cin >> xing;
        }
        togxun->personsarr[togxun->size].sex = xing;//添加性别

        cout<<"请输入年龄"<<endl;
        int Age=0;
        cin>>Age;
        togxun->personsarr[togxun->size].age=Age;//添加年龄

        cout<<"请输入电话号码"<<endl;
        string NUM;
        cin>>NUM;
        togxun->personsarr[togxun->size].num=NUM;//添加电话号码

        // 增加通讯录大小
        togxun->size++;
        cout<<"添加成功"<<endl;
    }
}
void xianshi(textbox * tongxun)//显示联系人
{
    if (tongxun->size==0)//如果联系人个数为零，那就没有人
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for (int i = 0; i < tongxun->size; i++)
        {
            cout<<"\033[33m姓名：\033[0m"<<tongxun->personsarr[i].name<<"\t";
            cout<<"\033[33m年龄：\033[0m"<<tongxun->personsarr[i].age<<"\t";
            cout<<"\033[33m性别：\033[0m"<<tongxun->personsarr[i].sex<<"\t";
            cout<<"\033[33m电话号码：\033[0m"<<tongxun->personsarr[i].num<<"\n";
        }
    }
    
    
}
int jiance(textbox *tongxun,string Name)//检测联系人是否存在，如果存在就返回联系人的位置
{
    for (int i = 0; i < tongxun->size; i++)//for循环遍历整个数组
    {
        if (tongxun->personsarr[i].name==Name)//有这名，就返回这名的下标
        {
            return i;
        }
        
    }
    return -1;//没找到就返回-1
}
void deleteperson(textbox *tongxun)//删除联系人
{
    cout<<"请输入你要删除的联系人"<<endl;
    string name;
    cin>>name;
    int ceshi;
    ceshi=jiance(tongxun,name);//先调用检测联系人是否存在
    if (ceshi!=-1)
    {
        for (int i = ceshi; i < tongxun->size; i++)
        {
            tongxun->personsarr[i]=tongxun->personsarr[i+1];//如果存在返回了下标，我们把下标后面的数据向前移动
        }//成功将下标数值覆盖
        tongxun->size--;
        cout<<"删除成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
}
void findperson(textbox *tongxun)
{
    cout<<"请输入你要查找人的名字"<<endl;
    string Name;
    cin>>Name;
    int kk=jiance(tongxun,Name);
    if (kk!=-1)
    {
        cout<<tongxun->personsarr[kk].name<<"\t";
        cout<<tongxun->personsarr[kk].sex<<"\t";
        cout<<tongxun->personsarr[kk].age<<"\t";
        cout<<tongxun->personsarr[kk].num<<endl;

    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    
}
void modifyperson(textbox *tongxun)
{
    cout<<"请输入要修改联系人的名字"<<endl;
    string name;
    cin>>name;
    int kk=jiance(tongxun,name);
    if (kk!=-1)
    {
        cout<<"请输入你要修改的指标\n1.姓名\n2.性别\n3.年龄\n4.电话号码"<<endl;
        int i;
        cin>>i;
        string nam;
        int xing;
        string num1;
        int ag;
        int j=1;
        while (j)
        {
            switch (i)
            {
                case 1:
                {   cout<<"你想要修改为："<<endl;
                    cin>>nam;
                    tongxun->personsarr[kk].name=nam;
                    cout<<"修改成功";
                    break;
                }

                case 2:
                {
                    cout<<"你想要修改为："<<endl;
                    cin>>xing;
                    tongxun->personsarr[kk].sex=xing;
                    cout<<"修改成功";
                    break;
                }
                case 3:
                {
                    cout<<"你想要修改为："<<endl;
                    cin>>ag;
                    tongxun->personsarr[kk].age=ag;
                    cout<<"修改成功";
                    break;
                }
                case 4:
                {
                    cout<<"你想修改为："<<endl;
                    cin>>num1;
                    tongxun->personsarr[kk].num=num1;
                    cout<<"修改成功";
                    break;
                }
            }
            cout<<"是否继续修改1---是 0---否"<<endl;
            cin>>j;
        }
        
        
    }
    
}
int main()
{
    textbox tongxun;
    tongxun.size=0;
    int kk;
    int shuru=0;
    while (true)
    {
        caidan();
        cin>>shuru;
        switch (shuru)
        {
        case 0:
            cout<<"退出 欢迎下次使用！"<<endl;
            system("pause");
            return 0;
            break;
        case 1:
            cout<<"添加联系人"<<endl;
            addperson(&tongxun);
            cout<<"\033[34m继续使用其他业务请继续键入其他数字\033[0m"<<endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout<<"显示联系人"<<endl;
            xianshi(&tongxun);
            cout<<"\033[34m继续使用其他业务请继续键入其他数字\033[0m"<<endl;
            system("pause");
            system("cls");
            break;
        case 3:
            cout<<"删除联系人"<<endl;
            deleteperson(&tongxun);
            cout<<"\033[34m继续使用其他业务请继续键入其他数字\033[0m"<<endl;
            system("pause");
            system("cls");
            break;
        case 4:
            cout<<"找查联系人"<<endl;
            findperson(&tongxun);
            cout<<"\033[34m继续使用其他业务请继续键入其他数字\033[0m"<<endl;
            system("pause");
            system("cls");
            break;
        case 5:
            cout<<"修改联系人"<<endl;
            modifyperson(&tongxun);
            cout<<"\033[34m继续使用其他业务请继续键入其他数字\033[0m"<<endl;
            system("pause");
            system("cls");
            break;
        case 6:
            cout<<"清空联系人"<<endl;
            cout<<"\033[34m继续使用其他业务请继续键入其他数字\033[0m"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    
    system("pause");
    return 0;
}