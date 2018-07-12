#pragma once

using namespace System;

// �������
enum Ages {
	CHILD, // ��� �����
	ADULT // ��� ��������
};

// ���������� � ���������
ref class PerformanceInfo
{
private:
	String ^ name;
	String ^ info;
	Ages age;

public:
	property String ^ Name {
		String ^ get() {
			return name;
		}
		void set(String ^ name) {
			this->name = name;
		}
	}

	property String ^ Info {
		String ^ get() {
			return info;
		}
		void set(String ^ info) {
			this->info = info;
		}
	}

	property Ages Age {
		Ages get() {
			return age;
		}
		void set(Ages age) {
			this->age = age;
		}
	}

	PerformanceInfo();
	PerformanceInfo(String ^ name, String ^ info, Ages age);
};