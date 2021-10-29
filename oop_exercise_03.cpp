#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct cord {
	double x, y;
};

class Figure {
public:
	vector<cord> v;

	void init(vector<cord> t) {
		v = t;
	}
	void printler() {
		for (int i = 0; i < v.size(); i++) {
			cout << "(" << v[i].x << ";" << v[i].y << ") ";
		}
		cout << '\n';
	}
	cord centrer() {
		cord center;
		double xs = 0, ys = 0;
		for (int i = 0; i < v.size(); i++) {
			xs += v[i].x;
			ys += v[i].y;
		}
		center.x = xs / v.size();
		center.y = ys / v.size();
		return center;
	}
	double squarer() {
		double p = 0;
		for (int i = 0; i < (v.size() - 1); i++) {
			p += (v[i].x * v[i + 1].y - v[i + 1].x * v[i].y);
		}
		p += (v[v.size() - 1].x * v[0].y - v[0].x * v[v.size() - 1].y);
		double square = abs(p) / 2;
		return square;
	}

};

class Five : public Figure {
public:
};

class Six : public Figure {
public:
};

class Eight : public Figure {
public:
};

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<Figure*> a;
	int menu, f = 1;
	while (f) {
		cout << "1.  Добавить пятиугольник" << endl;
		cout << "2.  Добавить шестиугольник" << endl;
		cout << "3.  Добавить восьмиугольник" << endl;
		cout << "4.  Распечатать площадь фигур в массиве" << endl;
		cout << "5.  Распечатать координаты вершин фигур в массиве" << endl;
		cout << "6.  Распечатать геометрический центр для каждой фигуры массива" << endl;
		cout << "7.  Вывести общую площадь фигур в массиве" << endl;
		cout << "8.  Удалить фигуру из массива по индексу" << endl;
		cout << "9.  Выход" << endl;
		cin >> menu;
		switch (menu) {
		case 1: {
			cout << "Введите координаты вершин пятиугольника:" << '\n';
			cout << "        3     " << '\n';
			cout << "    .       .    " << '\n';
			cout << "  .           .   " << '\n';
			cout << " 2             4" << '\n';
			cout << "  .           .   " << '\n';
			cout << "   .         .   " << '\n';
			cout << "    1. . . .5      " << '\n';
			Five* f = new Five();
			vector<cord> k(5);
			for (int i = 0; i < 5; i++) {
				cout << i + 1 << "-ая вершина: " << '\n';
				cin >> k[i].x >> k[i].y;
			}
			f->init(k);
			if (f->squarer() > 0) {
				a.push_back(f);
			}
			else {
				cout << "Неправильно введена фигура, попробуйте снова :)" << '\n';
				delete f;
			}
			break;
		}
		case 2: {
			cout << "Введите координаты вершин шестиугольника:" << '\n';
			cout << "    3. . . .4      " << '\n';
			cout << "   .         ." << '\n';
			cout << "  .           ." << '\n';
			cout << " 2             5" << '\n';
			cout << "  .           ." << '\n';
			cout << "   .         ." << '\n';
			cout << "    1. . . .6      " << '\n';
			Six* f = new Six();
			vector<cord> k(6);
			for (int i = 0; i < 6; i++) {
				cout << i + 1 << "-ая вершина: " << '\n';
				cin >> k[i].x >> k[i].y;
			}
			f->init(k);
			if (f->squarer() > 0) {
				a.push_back(f);
			}
			else {
				cout << "Неправильно введена фигура, попробуйте снова :)" << '\n';
				delete f;
			}
			break;
		}
		case 3: {
			cout << "Введите координаты вершин восьмиугольника:" << '\n';
			cout << "     4. . . .5      " << '\n';
			cout << "   .           ." << '\n';
			cout << " 3               6" << '\n';
			cout << " .               ." << '\n';
			cout << " 2               7" << '\n';
			cout << "   .           ." << '\n';
			cout << "     1. . . .8      " << '\n';
			Eight* f = new Eight();
			vector<cord> k(8);
			for (int i = 0; i < 8; i++) {
				cout << i + 1 << "-ая вершина: " << '\n';
				cin >> k[i].x >> k[i].y;
			}
			f->init(k);
			if (f->squarer() > 0) {
				a.push_back(f);
			}
			else {
				cout << "Неправильно введена фигура, попробуйте снова :)" << '\n';
				delete f;
			}
			break;
		}
		case 4: {
			for (int i = 0; i < a.size(); i++) {
				cout << "Площадь " << i + 1 << "-ой фигуры: ";
				cout << a[i]->squarer() << '\n';
			}
			break;
		}
		case 5: {
			for (int i = 0; i < a.size(); i++) {
				cout << "Координаты вершин " << i + 1 << "-ой фигуры: " << '\n';
				a[i]->printler();
			}
			break;
		}
		case 6: {
			for (int i = 0; i < a.size(); i++) {
				cout << "Координаты геометрического центра " << i + 1 << "-ой фигуры: " << '\n';
				cout << "x=" << a[i]->centrer().x << " y=" << a[i]->centrer().y << '\n';
			}
			break;
		}
		case 7: {
			double k = 0;
			for (int i = 0; i < a.size(); i++) {
				k += a[i]->squarer();
			}
			cout << "Площадь всех фигур в массиве: " << k << '\n';
			break;
		}
		case 8: {
			int k;
			cout << "Введите индекс удаляемого элемента: ";
			cin >> k;
			if ((k <= a.size()) && (k > 0)) {
				delete a[k - 1];
				a.erase(a.begin() + k - 1);
			}
			else cout << "Некорректный индекс" << '\n';
			break;
		}
		case 9: {
			f = 0;
			for (int i = 0; i < a.size(); i++) {
				delete a[i];
			}
			break;
		}
		default: {
			cout << "Неверная команда" << '\n';
			break;
		}
		}

	}

	return 0;
}
