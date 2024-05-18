#include <iostream>
using namespace std;

class Phone {
private:
	string data;
public:
	Phone() {
		data = "";
	}

	string AboutPhone() {
		return data;
	}

	void AppendData(string str) {
		data += str;
	}
};

__interface IDeveloper {
	virtual void CreateDisplay() = 0;
	virtual void CreateBox() = 0;
	virtual void SystemInstrall() = 0;
	virtual Phone* GetPhone() = 0;
};

class AndroidDeveloper : public IDeveloper {
private:
	Phone* phone;
public:
	AndroidDeveloper() {
		phone = new Phone();
	}

	~AndroidDeveloper() {
		delete phone;
	}

	virtual void CreateDisplay() override {
		cout << "Samsung display manufactured\n";
	}

	virtual void CreateBox() override {
		phone->AppendData("The case is manufactured by Samsung\n");
	}

	virtual void SystemInstrall() override {
		phone->AppendData("Android system installed\n");
	}

	virtual Phone* GetPhone() override {
		return phone;
	}
};

class iPhoneDeveloper : public IDeveloper {
private:
	Phone* phone;
public:
	iPhoneDeveloper() {
		phone = new Phone();
	}

	~iPhoneDeveloper() {
		delete phone;
	}

	virtual void CreateDisplay() override {
		cout << "iPhone display manufactured\n";
	}

	virtual void CreateBox() override {
		phone->AppendData("The case is manufactured by Apple\n");
	}

	virtual void SystemInstrall() override {
		phone->AppendData("IOS system installed\n");
	}

	virtual Phone* GetPhone() override {
		return phone;
	}
};

class Director {
private:
	IDeveloper* developer;
public:
	Director(IDeveloper* dev) : developer(dev){}

	void SetDeveloper(IDeveloper* developer) {
		this->developer = developer;
	}

	Phone* MountOnlyPhone() {
		developer->CreateBox();
		developer->CreateDisplay();
		return developer->GetPhone();
	}

	Phone* MountFullPhone() {
		developer->CreateBox();
		developer->CreateDisplay();
		developer->SystemInstrall();
		return developer->GetPhone();
	}
};

int main() {
	IDeveloper* androidDeveloper = new AndroidDeveloper();
	Director director(androidDeveloper);
	Phone* samsung = director.MountFullPhone();
	cout << samsung->AboutPhone() << "\n";

	IDeveloper* IPhoneDeveloper = new iPhoneDeveloper();
	director.SetDeveloper(IPhoneDeveloper);
	Phone* iphone = director.MountOnlyPhone();
	cout << iphone->AboutPhone() << "\n";
}