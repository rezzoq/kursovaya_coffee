#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath>
#include <string>
//using namespace std;
std::string n;
std::string u;
std::string p;
unsigned int w;
unsigned int q;
unsigned int b;
double c;
double pp;
double rp;
int CheckInt()
{
	double k, ik, dk;
	while (true)
	{
		std::cin >> k;
		dk = modf(k, &ik);
		if ((std::cin.fail()) || (k < 0) || (dk != 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "������! ������� ����� �����: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return ik;
		}
	}
}
double CheckDouble()
{
	double k;
	while (true)
	{
		std::cin >> k;
		if ((std::cin.fail()) || (k < 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "������! ������� ����� �����: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return k;
		}
	}
}

class base { // ���� ������
public:
	base(int t, std::string n, std::string u, std::string p, unsigned int w, unsigned int q, unsigned
		int b, double c, double pp, double rp) : type(t), name(n), unit(u), provider(p),
		weight(w), quantity(q), barcode(b), calories(c), p_price(pp), r_price(rp) {}
	int type; // "����" = 0, "���" = 1, "��������" = 2, "��������" = 3, "���������" = 4, "������" = 5, "�������" = 6, "������" = 7
		std::string name; // �������� ��������
	std::string unit; // ������� ���������
	std::string provider; // ���������
	unsigned int weight; // ��� ������ ��������
	unsigned int quantity; // ���������� ���������
	unsigned int barcode; // ����� ��� ��������
	double calories; // ������� ��������
	double p_price; // ���������� ����
	double r_price; // ��������� ���� (���� ������)
	int GetType() { return type; }
	std::string GetName() { return name; }
	std::string GetUnit() { return unit; }
	std::string GetProvider() { return provider; }
	unsigned int GetWeight() { return weight; }
	unsigned int GetQuantity() { return quantity; }
	unsigned int GetBarcode() { return barcode; }
	double GetCalories() { return calories; }
	double GetPprice() { return p_price; }
	double GetRprice() { return r_price; }
	void AddQuantity(unsigned int emp_q) { quantity = quantity + emp_q; }
	void DeleteQuantity(unsigned int emp_q) { quantity = quantity - emp_q; }
	void GetInfo()
	{
		std::cout << "\n�������� ��������: " << GetName();
		std::cout << "\n���������� �������� �� ������: " << GetQuantity() << ' ' <<
			GetUnit();
		std::cout << "\n���������: " << GetProvider();
		std::cout << "\n��� ������ ��������: " << GetWeight();
		std::cout << "\n�����-���: " << GetBarcode();
		std::cout << "\n������������: " << GetCalories();
		std::cout << "\n���������� ����: " << GetPprice();
		std::cout << "\n��������� ����: " << GetRprice() << "\n";
	}
	void ChangeBarcode(unsigned int emp_barcode) { barcode = emp_barcode; }
	void ChangeInfo()
	{
		std::cout << "��������, ��� �� ������ ��������:\n1 - ��������\n2 - ������� ���������\n3 - ����������\n4 - ��� ������ ��������\n5 - ������������\n6 - ���������� ����\n7 - ��������� ����\n����� ������ ����� ��� ������\n������� ����� : ";
			int r = CheckInt();
		if (r == 1) {
			std::cout << "������� ����� ��������: "; getline(std::cin, n); name = n;
		}
		if (r == 2) {
			std::cout << "������� ����� ������� ���������: "; getline(std::cin, u);
			unit = u;
		}
		if (r == 3) {
			std::cout << "������� ������ ����������: "; getline(std::cin, p);
			provider = p;
		}
		if (r == 4) {
			std::cout << "������� ��� ��������: "; w = CheckInt(); weight = w;
		}
		if (r == 5) {
			std::cout << "������� ����� ������������: "; c = CheckDouble();
			calories = c;
		}
		if (r == 6) {
				std::cout << "������� ����� ���������� ����: "; pp =
					CheckDouble(); p_price = pp;
		}
		if (r == 7) {
			std::cout << "������� ����� ��������� ����: "; rp = CheckDouble();
			r_price = rp;
		}
	}
};
int Menu()
{
	std::cout << "\n������� ����� ������, ����� ����������...";
	_getch();
	system("cls");
	std::cout << "��������, ��� �� ������ �������.\n0) ������� ���������. \n1) ���������� ���������� �� ���� ���������.\n2) �������� ����� � ����.\n3) ������� ����� �� ����.\n";
	std::cout << "4) ������� ���������� �� ���������� ��������.\n5) ������ � ���� ���������� ������������� ��������. \n6) ������� �� ���� ���������� ���������������� ��������.\n";
	std::cout << "7) �������� ���������� � ��������.\n8) �������� �����-��� ��������\n";
	double k, ik, dk;
	std::cout << "\n������� �����: ";
	while (true)
	{
		std::cin >> k;
		dk = modf(k, &ik);
		if ((std::cin.fail()) || (k < 0) || (k > 8) || (dk != 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "������! ������� ����� �����: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return ik;
		}
	}
}
int Choice()
{
	std::cout << "�������� ��� ��������:\n1) ����\n2) ���\n3) ��������\n4) ��������, �����\n5) ���������\n6) ������\n7) �������\n8) ������\n��� ������ �������� ������� 0.\n������� ����� : ";
		double k, ik, dk;
	while (true)
	{
		std::cin >> k;
		dk = modf(k, &ik);
		if ((std::cin.fail()) || (k < 0) || (k > 8) || (dk != 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "������! ������� ����� �����: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return ik;
		}
	}
}
int main()
{
	system("chcp 1251 >> null");
	std::vector<base> products;
	std::vector<int> numbers = { 0,0,0,0,0,0,0,0 };
	int y, z, check;
	std::cout << "�����������! \n������� ����� ��������� ��������.";
	while (1 > 0)
	{
		z = Menu();
		check = 0;
		switch (z)
		{
		case 0: // �������� ���������
			exit(0);
		case 1: // ����� ������
		{
			std::cout << "\n\n���������� ��������� ���� ����: " << numbers[0] <<
				"\n���������� ��������� ���� ���: " << numbers[1];
			std::cout << "\n���������� ��������� ���� ��������: " << numbers[2] <<
				"\n���������� ��������� ���� ��������: " << numbers[3];
			std::cout << "\n���������� ��������� ���� ���������: " << numbers[4] <<
				"\n���������� ��������� ���� ������: " << numbers[5];
			std::cout << "\n���������� ��������� ���� �������: " << numbers[6] <<
				"\n���������� ��������� ���� ������: " << numbers[7] << "\n";
			break;
		}
		case 2: // ���������� ��������
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "���������� ��������...\n";
			numbers[y]++;
			std::cout << "������� �������� ��������: "; getline(std::cin, n);
			std::cout << "������� ��� ������� ���������: "; getline(std::cin, u);
			std::cout << "������� ����������: "; getline(std::cin, p);
			std::cout << "������� ��� ������ ��������: "; w = CheckInt();
			std::cout << "������� �����-���: "; b = CheckInt();
			std::cout << "������� ������� ��������: "; c = CheckDouble();
			std::cout << "������� ���������� ����: "; pp = CheckDouble();
			std::cout << "������� ��������� ����: "; rp = CheckDouble();
			q = 0;
			base a(y, n, u, p, w, q, b, c, pp, rp);
			products.push_back(a);
			std::cout << "\n������� ������� �������� � ����!\n\n";
			break;
		}
		case 3: // �������� ��������
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "�������� ��������...\n";
			std::cout << "������� �����-��� ��������, ������� ������ �������: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products.erase(products.begin() + i);
					numbers[y]--;
					std::cout << "\n������� ������� ������ �� ����!\n\n";
					check = 3;
				}
			if (check != 3) std::cout << "������� �� ������!";
			break;
		}
		case 4: // ����� ���������� �� ���������� ��������
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "����� ���������� �� ���������� �������� �������...\n";
			std::cout << "������� �����-��� ��������: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products[i].GetInfo();
					check = 4;
				}
			if (check != 4) std::cout << "������� �� ������!";
			break;
		}
		case 5: // ������ � ���� ���������� ������������� ��������
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "���������� � ���� �������� �������� ������������...\n";
			std::cout << "������� ���������� ��������: ";
			q = CheckInt();
			std::cout << "������� �����-��� ��������, �������� �������� ���� �����������: ";
				b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products[i].AddQuantity(q);
					check = 5;
				}
			if (check != 5) std::cout << "������� �� ������!";
			break;
		}
		case 6: // ������� �� ���� ���������� ���������������� ��������
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "�������� �� ���� �������������� �������� ������������...\n";
			std::cout << "������� ���������� ��������: ";
			q = CheckInt();
			std::cout << "������� �����-��� ��������, ������� ��� ������������: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() == y)
				{
					products[i].DeleteQuantity(q);
					check = 6;
				}
			if (check != 6) std::cout << "������� �� ������!";
			break;
		}
		case 7: // ��������� ���������� � ��������
		{
				y = Choice() - 1;
			if (y == -1) break;
			std::cout << "��������� ���������� � �������� ������������...\n";
			std::cout << "������� �����-��� ��������, ���������� � ������� ������ ��������: ";
				b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products[i].ChangeInfo();
					check = 7;
				}
			if (check != 7) std::cout << "������� �� ������!";
		}
		case 8:
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "��������� ���������� � �����-���� ������������...\n";
			std::cout << "������� �����-��� ��������, ������� ������ ��������: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() == y)
				{
					std::cout << "������� ����� �����-���: ";
					b = CheckInt();
					products[i].ChangeBarcode(b);
					check = 7;
					break;
				}
			if (check != 7) std::cout << "�����-��� �� ������!";
		}
		default:
			break;
		};
	}
}