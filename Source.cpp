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
			std::cout << "Ошибка! Введите число снова: ";
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
			std::cout << "Ошибка! Введите число снова: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return k;
		}
	}
}

class base { // база товара
public:
	base(int t, std::string n, std::string u, std::string p, unsigned int w, unsigned int q, unsigned
		int b, double c, double pp, double rp) : type(t), name(n), unit(u), provider(p),
		weight(w), quantity(q), barcode(b), calories(c), p_price(pp), r_price(rp) {}
	int type; // "Кофе" = 0, "Чай" = 1, "Коктейли" = 2, "Пирожные" = 3, "Мороженое" = 4, "Салаты" = 5, "Выпечка" = 6, "Другое" = 7
		std::string name; // название продукта
	std::string unit; // единица измерения
	std::string provider; // поставщик
	unsigned int weight; // вес одного продукта
	unsigned int quantity; // количество продуктов
	unsigned int barcode; // штрих код продукта
	double calories; // пищевая ценность
	double p_price; // закупочная цена
	double r_price; // розничная цена (цена продаж)
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
		std::cout << "\nНазвание продукта: " << GetName();
		std::cout << "\nКоличество продукта на складе: " << GetQuantity() << ' ' <<
			GetUnit();
		std::cout << "\nПоставщик: " << GetProvider();
		std::cout << "\nВес одного продукта: " << GetWeight();
		std::cout << "\nШтрих-код: " << GetBarcode();
		std::cout << "\nКалорийность: " << GetCalories();
		std::cout << "\nЗакупочная цена: " << GetPprice();
		std::cout << "\nРозничная цена: " << GetRprice() << "\n";
	}
	void ChangeBarcode(unsigned int emp_barcode) { barcode = emp_barcode; }
	void ChangeInfo()
	{
		std::cout << "Выберите, что вы хотите изменить:\n1 - название\n2 - единицу измерения\n3 - поставщика\n4 - вес одного продукта\n5 - калорийность\n6 - закупочную цену\n7 - розничную цену\nЛюбое другое число для отмены\nВведите число : ";
			int r = CheckInt();
		if (r == 1) {
			std::cout << "Введите новое название: "; getline(std::cin, n); name = n;
		}
		if (r == 2) {
			std::cout << "Введите новую единицу измерения: "; getline(std::cin, u);
			unit = u;
		}
		if (r == 3) {
			std::cout << "Введите нового поставщика: "; getline(std::cin, p);
			provider = p;
		}
		if (r == 4) {
			std::cout << "Введите вес продукта: "; w = CheckInt(); weight = w;
		}
		if (r == 5) {
			std::cout << "Введите новую калорийность: "; c = CheckDouble();
			calories = c;
		}
		if (r == 6) {
				std::cout << "Введите новую закупочную цену: "; pp =
					CheckDouble(); p_price = pp;
		}
		if (r == 7) {
			std::cout << "Введите новую розничную цену: "; rp = CheckDouble();
			r_price = rp;
		}
	}
};
int Menu()
{
	std::cout << "\nНажмите любую кнопку, чтобы продолжить...";
	_getch();
	system("cls");
	std::cout << "Выберите, что вы хотите сделать.\n0) Закрыть программу. \n1) Посмотреть информацию по базе продуктов.\n2) Добавить товар в базу.\n3) Удалить товар из базы.\n";
	std::cout << "4) Вывести информацию по отдельному продукту.\n5) Внести в базу количество поставленного продукта. \n6) Удалить из базы количество израсходованного продукта.\n";
	std::cout << "7) Изменить информацию о продукте.\n8) Изменить штрих-код продукта\n";
	double k, ik, dk;
	std::cout << "\nВведите число: ";
	while (true)
	{
		std::cin >> k;
		dk = modf(k, &ik);
		if ((std::cin.fail()) || (k < 0) || (k > 8) || (dk != 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Ошибка! Введите число снова: ";
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
	std::cout << "Выберите тип продукта:\n1) Кофе\n2) Чай\n3) Коктейли\n4) Пирожные, торты\n5) Мороженое\n6) Салаты\n7) Выпечка\n8) Другое\nДля отмены действия нажмите 0.\nВведите число : ";
		double k, ik, dk;
	while (true)
	{
		std::cin >> k;
		dk = modf(k, &ik);
		if ((std::cin.fail()) || (k < 0) || (k > 8) || (dk != 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Ошибка! Введите число снова: ";
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
	std::cout << "Здраствуйте! \nСистема учёта продуктов запущена.";
	while (1 > 0)
	{
		z = Menu();
		check = 0;
		switch (z)
		{
		case 0: // закрытие программы
			exit(0);
		case 1: // вывод отчета
		{
			std::cout << "\n\nКоличество продуктов типа Кофе: " << numbers[0] <<
				"\nКоличество продуктов типа Чай: " << numbers[1];
			std::cout << "\nКоличество продуктов типа Коктейли: " << numbers[2] <<
				"\nКоличество продуктов типа Пирожные: " << numbers[3];
			std::cout << "\nКоличество продуктов типа Мороженое: " << numbers[4] <<
				"\nКоличество продуктов типа Салаты: " << numbers[5];
			std::cout << "\nКоличество продуктов типа Выпечка: " << numbers[6] <<
				"\nКоличество продуктов типа Другое: " << numbers[7] << "\n";
			break;
		}
		case 2: // добавление продукта
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Добавление продукта...\n";
			numbers[y]++;
			std::cout << "Введите название продукта: "; getline(std::cin, n);
			std::cout << "Введите его единицу измерения: "; getline(std::cin, u);
			std::cout << "Введите поставщика: "; getline(std::cin, p);
			std::cout << "Введите вес одного продукта: "; w = CheckInt();
			std::cout << "Введите штрих-код: "; b = CheckInt();
			std::cout << "Введите пищевую ценность: "; c = CheckDouble();
			std::cout << "Введите закупочную цену: "; pp = CheckDouble();
			std::cout << "Введите розничную цену: "; rp = CheckDouble();
			q = 0;
			base a(y, n, u, p, w, q, b, c, pp, rp);
			products.push_back(a);
			std::cout << "\nПродукт успешно добавлен в базу!\n\n";
			break;
		}
		case 3: // удаление продукта
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Удаление продукта...\n";
			std::cout << "Введите штрих-код продукта, который хотите удалить: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products.erase(products.begin() + i);
					numbers[y]--;
					std::cout << "\nПродукт успешно удален из базы!\n\n";
					check = 3;
				}
			if (check != 3) std::cout << "Продукт не найден!";
			break;
		}
		case 4: // вывод информации по отдельному продукту
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Поиск информации по отдельному продукту запущен...\n";
			std::cout << "Введите штрих-код продукта: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products[i].GetInfo();
					check = 4;
				}
			if (check != 4) std::cout << "Продукт не найден!";
			break;
		}
		case 5: // Внести в базу количество поставленного продукта
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Добавление в базу поставки продукта активировано...\n";
			std::cout << "Введите количество продукта: ";
			q = CheckInt();
			std::cout << "Введите штрих-код продукта, поставка которого была произведена: ";
				b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products[i].AddQuantity(q);
					check = 5;
				}
			if (check != 5) std::cout << "Продукт не найден!";
			break;
		}
		case 6: // Удалить из базы количество израсходованного продукта
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Удаление из базы расходованного продукта активировано...\n";
			std::cout << "Введите количество продукта: ";
			q = CheckInt();
			std::cout << "Введите штрих-код продукта, который был израсходован: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() == y)
				{
					products[i].DeleteQuantity(q);
					check = 6;
				}
			if (check != 6) std::cout << "Продукт не найден!";
			break;
		}
		case 7: // изменение информации о продукте
		{
				y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Изменение информации о продукте активировано...\n";
			std::cout << "Введите штрих-код продукта, информацию о котором хотите изменить: ";
				b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() ==
					y)
				{
					products[i].ChangeInfo();
					check = 7;
				}
			if (check != 7) std::cout << "Продукт не найден!";
		}
		case 8:
		{
			y = Choice() - 1;
			if (y == -1) break;
			std::cout << "Изменение информации о штрих-коде активировано...\n";
			std::cout << "Введите штрих-код продукта, который хотите изменить: ";
			b = CheckInt();
			for (int i = 0; i < products.size(); i++)
				if (products[i].GetBarcode() == b && products[i].GetType() == y)
				{
					std::cout << "Введите новый штрих-код: ";
					b = CheckInt();
					products[i].ChangeBarcode(b);
					check = 7;
					break;
				}
			if (check != 7) std::cout << "Штрих-код не найден!";
		}
		default:
			break;
		};
	}
}