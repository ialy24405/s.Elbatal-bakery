#pragma once
using namespace System;
public ref class Admin {
private:
	String^ userName;
	String^ password;

public:
	Admin() {}
	Admin(String^ userName, String^ password) {
		this->userName = userName;
		this->password = password;
	}

	String^ getUserName() {
		return userName;
	}

	void setUserName(String^ userName) {
		this->userName = userName;
	}

	String^ getPassword() {
		return password;
	}

	void setPassword(String^ password) {
		this->password = password;
	}
};