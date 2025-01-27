游戏角色创建

#include <iostream>
#include<string>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;
class Message
{
	protected:
		string name;
		string sex;
		string racename;
		string jobname;
	public:
		void setName();
		void setSex();
		void setRace();
		void setJob();
 } ;
 void Message::setName()	//输出姓名函数 
 {
 	cout<<"请输入您游戏角色的姓名：";
	cin>>name; 
 }
 void Message::setSex()		//输出性别函数 
{
	int flag=1,x;
	cout<<"请输入您游戏中的性别：0（男），1（女）";
	cin>>x;
	while(flag)
	{
		switch(x)
		{
			case 0: sex="男";flag=0; break;
			case 1: sex="女";flag=0; break;
			default: cout<<"输入错误，请重新输入您的性别"; 
		}
	}
 } 
  int i,j;	//对应于所属种族可以被要求选择的职业的所有可能 
	 string arr[5][6]={
	 	{"狂战士","圣骑士","刺客","猎手","祭司","巫师"},
					   {"刺客","猎手","祭司" ,"巫师"},
					   {"狂战士","猎手","祭司"},
					   {"狂战士","圣骑士","祭司"},
					   {"祭司","巫师"}
	 };
 void Message::setRace()	//输出种族函数 
 {
 	cout<<"请输入您游戏中属于的种族：（0）人类，（1）精灵，（2）兽人，（3）矮人，（4）元素";
 	cin>>i;
 	switch(i)
 	{
 		case 0: racename="人类"; break;
		case 1: racename="精灵"; break;
		case 2: racename="兽人"; break;
		case 3: racename="矮人"; break;
		case 4: racename="元素"; break;  
	 }
};
 void Message::setJob()		//选择职业函数（狂战士、圣骑士、刺客、猎手、祭司和巫师） 
 {
 	switch(i)
 	{
 		case 0:cout<<"请选择您的职业(0)狂战士 (1)圣骑士 (2)刺客 (3)猎手 (4)祭司 (5)巫师";
		   	   cin>>j ;break; 
		case 1:cout<<"请选择您的职业(0)刺客 (1)猎手 (2)祭司 (3)巫师";
		   	   cin>>j ;break; 
		case 2:cout<<"请选择您的职业(0)狂战士 (1)猎手 (2)祭司 ";
		   	   cin>>j ;break; 
		case 3:cout<<"请选择您的职业(0)狂战士 (1)圣骑士 (2)祭司 ";
		   	   cin>>j ;break; 
		case 4:cout<<"请选择您的职业(0)祭司 (1)巫师";
		   	   cin>>j ;break; 
	 }
	if(i<=4&&i<=5)
		jobname=arr[i][j];
 }
 class Property:public Message
{
private:
	int power,agility,physical,wit,wisdom ; //力量 敏捷 体力 智力 智慧
	int HP ,MP ;    //生命值Health Point和魔法值Magic Point        
public:
	int result(int x, int y);
	int output(int i,int power1,int agility1,int physical1,int wit1,int wisdom1);
	void setPro();
	void display();
	void file();
};
//定义一个成员函数result，随机计算大于或小于y的值
int Property::result(int x , int y)
{ 
    srand(time(NULL));
	int z; 
	z=rand()%2  ; //产生随机数0或1
	if(z == 0)
	{
       return x+y ;		
	}
	else
	{
		return y-x ;
	}
}
//定义一个成员函数output，计算初始属性值
int Property::output(int i ,int power1 ,int agility1 , int physical1 ,int wit1, int wisdom1)
{
	int sum = 0; 
	int a[5],w ;
	a[0] = result(i, power1);
	a[1] = result(i, agility1);
	a[2] = result(i, physical1);
	a[3] = result(i, wit1);
	a[4] = result(i, wisdom1);
	sum = a[0]+a[1]+a[2]+a[3]+a[4];
	sum-=100 ;  
    if(sum >0)
    {
       for(w = 0;sum != 0;sum--)
       {
     	   a[w]-- ;
       	   w++ ;
       	   if(w == 5)
       	   w = 0 ;
       }
            }
            if(sum < 0)
            {
               for(w = 0;sum != 0 ; sum++ )
               {
               	   a[w]++ ;
               	   i++ ;
               	   if(w == 5)
               	   {
               	   	w = 0 ;
               	   }
               }
            }
		 power=a[0]; agility = a[1] ; physical = a[2] ; wit = a[3] ; wisdom = a[4] ; 
		 HP = physical * 20 ;
		 MP = (wit + wisdom) * 10 ;
	 	return 0;
}
//定义成员函数setPro，输出各个职业的初始属性值
void Property::setPro()
{
	if(jobname =="狂战士")
	output(rand()%5,40,20,30,5,5) ;
	if(jobname =="圣骑士")
	output(rand()%5,25,15,30,20,10) ;
	if(jobname =="刺客")
	output(rand()%5,20,35,20,15,10) ;
	if(jobname =="猎手")
	output(rand()%5,15,40,15,10,20) ;	
	if(jobname =="祭司")
	output(rand()%5,15,20,15,35,15) ;
	if(jobname =="巫师")
	output(rand()%5,10,20,10,20,40) ;
}
//定义成员函数display，显示角色信息			
void Property::display()
{	
	cout<<"=====================================\n";
	cout<<"姓名\t\t"<<name<<endl;	 
	cout<<"=====================================\n";
	cout<<"性别\t\t"<<sex<<endl;
	cout<<"=====================================\n";
	cout<<"种族\t\t"<<racename<<endl;
	cout<<"=====================================\n";
	cout<<"职业\t\t"<<jobname<<endl;
	cout<<"=====================================\n";
	cout<<"力量\t\t"<<power <<endl;
	cout<<"=====================================\n";
	cout<<"敏捷\t\t"<<agility <<endl;
	cout<<"=====================================\n";
	cout<<"体力\t\t"<<physical<<endl;
	cout<<"=====================================\n";
	cout<<"智力\t\t"<<wit<<endl; 
	cout<<"=====================================\n";
	cout<<"智慧\t\t"<<wisdom<<endl;
	cout<<"=====================================\n";
	cout<<"生命值\t\t"<<HP<<endl;
	cout<<"=====================================\n";
	cout<<"魔法值\t\t"<<MP<<endl;
	cout<<"=====================================\n";	
}
//定义成员函数file，将角色信息写入文件
void Property::file()
{
	ofstream f1("output.txt",ios::app);
    if(!f1) 
    return  ;
	f1<<"=====================================\n";
	f1<<"姓名\t\t\t\t"<<name<<endl;	 
	f1<<"=====================================\n";
	f1<<"性别\t\t\t\t"<<sex<<endl;
	f1<<"=====================================\n";
	f1<<"种族\t\t\t\t"<<racename<<endl;
    f1<<"=====================================\n";
	f1<<"职业\t\t\t\t"<<jobname<<endl;
	f1<<"=====================================\n";
	f1<<"力量\t\t\t\t"<<power<<endl;	 
	f1<<"=====================================\n";
	f1<<"敏捷\t\t\t\t"<<agility<<endl;
	f1<<"=====================================\n";
	f1<<"体力\t\t\t\t"<<physical<<endl;
    f1<<"=====================================\n";
	f1<<"智力\t\t\t\t"<<wit<<endl;
	f1<<"=====================================\n";
	f1<<"智慧\t\t\t\t"<<wisdom<<endl;
	f1<<"=====================================\n";
	f1.close(); 
}
int main()
{
	Property N;
	int flag=1;
    char n;
	char m;
	while(flag)
    {
		N.setName();
  		N.setSex();
  		N.setRace();
  		N.setJob();
  		N.setPro();
		N.display();
  		cout<<"是否创建此角色(Y or N)"<<endl; 
  		cin>>n; 
  		if(n== 'Y')     //创建角色
		{  
			N.file();
			cout<<"创建成功"<<endl;
			flag=0;
			break;
		}
		else if(n=='N')
		{
			cout<<"是否重新创建（Y or N）"<<endl;
			cin>>m;
			if(m=='Yes')     //重新创建角色
			{
				flag=1;
				break;
			}
			else if(m=='No')   //退出
				flag=0;
		}
	}
	return 0;
}
