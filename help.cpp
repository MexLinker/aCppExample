#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Message
{
	//功能函数声明
public:
	Message(string name, int password, int id, string type,int number);
	void setname(string name);
	void setpassword(int password);
	void setid(int id);
	void settype(string type);
	void setnumber(int number);

	string getname();
	int getpassword();
	int getid();
	string gettype();
	int getnumber();

	//创建类对象
private:
	string name;
	int password;
	int id;
	string type;
	int number;
};
//成员函数中使用this指针确定变量地址
void Message::setname(string name)
{
	this->name = name;
}
void Message::setid(int id) {
	this->id = id;
}
void Message::setpassword(int password) {
	this->password = password;
}
void Message::settype(string type) {
	this->type = type;
}
void Message::setnumber(int number) {
	this->number = number;
}
//定义返回值
string Message::getname() {
	return this->name;
}
int Message::getid() {
	return this->id;
}
int Message::getpassword() {
	return this->password;
}
string Message::gettype() {
	return this->type;
}
int Message::getnumber() {
		return this->number;
}
//右箭头
//类作用域表示message属于message
//全部为this指针
Message::Message(string name, int password, int id, string type,int number)
{
	this->name = name;
	this->password = password;
	this->id = id;
	this->type = type;
	this->number = number;
}
//创建引用变量vec
void addMessage(vector<Message>& vec)
{
	string name;
	int password;
	int id;
	string type;
	int number;
	int a;
	do
	{cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> password;
	cout << "请输入员工编号" << endl;
	cin >> id;
	cout << "请输入用户类型" << endl;
	cin >> type;
	cout << "请输入所需添加用户信息数目" << endl;
	cin >> number;
	Message tmpmessage(name, password, id, type,number);
	vec.push_back(tmpmessage);
	cout << "*系统用户信息添加成功*" << endl;
	cout << "0 继续输入" << '\n' << "1 返回程序" << endl;
	cin >> a;
	if (a == 1)break;
	} while (a==0);
	
}

void showmessage(vector<Message>& vec) {
	cout << setw(24) << "*系统用户信息如下*" << endl;
	cout << "用户名\t员工编号\t密码\t用户类型" << endl;
	//循环体内声明自动变量
	//auto变量在函数结束时即释放了，再次调用这个函数时，又重新定义了一个新的变量。
	//循环遍历auto：
	for (auto& ivec : vec) {
		cout << ivec.getname() <<'\t' << ivec.getid()<<'\t' << ivec.getpassword() <<'\t' << ivec.gettype() << endl;
	}
	cout <<setw(22)<< "已显示所有信息!" << endl;
}

void findmessage(vector<Message>&vec) {
	string name;
	cin >> name;
	for (auto& ivec : vec) {
		if (ivec.getname() == name)
			cout << "修改前信息为" << endl;
			cout << ivec.getname() << '\t' << ivec.getid() <<'\t' << ivec.getpassword() <<'\t' << ivec.gettype() << endl;
	}
}

void modifiy(vector<Message>&vec) {
	cout << "请输入用户名称" << endl;
	findmessage(vec);
}

void deleatemessage(vector<Message>&vec) {
	string name;
	// int find;
	cout << "请输入删除用户名" << endl;
	cin >> name;

    //在进行单个元素删除后，传入的迭代器指向不变，仍然指向被删除元素的位置，
    //而被删除元素之后的所有元素都向前移动一位，
    //也就是该迭代器实际上是指向了原来被删除元素的下一个元素
    
    vector<Message>::iterator itr = vec.begin();

	for(; itr<=vec.end(); itr++) {
		if (name == (*itr).getname()){
			itr = vec.erase(itr);
			cout<<"delete the user" + (*itr).getname() + "successfully"<<endl;
			break;
		}
	}
}

//显示主菜单
void ShowMeun()
{
	cout << setw(24) << setfill('*');
	cout << "系统用户管理功能" << setw(8)<<"*"<<endl;
	cout << setw(24)<<setfill(' ') << "1 添加系统用户信息" << endl;
	cout << setw(24) << setfill(' ') << "2 修改系统用户信息" << endl;
	cout << setw(24) << setfill(' ') << "3 删除系统用户信息" << endl;
	cout << setw(24) << setfill(' ') << "4 查看系统用户信息" << endl;
	cout << setw(22)<<"* 5 退出系统 *" << endl;
}
int main() {
	vector<Message>vec;
	ShowMeun();
	while (1) {
		int select;
		cout << "请选择功能:" << endl;
		cin >> select;
		if (select == 5)
			break;
		switch (select)
		{case 1:
			addMessage(vec);
			break;
		case 2:
			modifiy(vec);
			break;
		case 3:
			deleatemessage(vec);
			break;
		case 4:
			showmessage(vec);
			break;
		default:
			break;
		}
	}

}
