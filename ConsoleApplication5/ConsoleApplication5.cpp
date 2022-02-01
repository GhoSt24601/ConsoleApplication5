#include <iostream>
using namespace std;

class Property
{
public:
    double taxes;

protected:
    int worth; //цена
    char name[20]; //название 
    char owner[20]; //чей
public:
    Property(int w, char* n, char* o); //конструктор
    void print();

};

class Appartment : protected Property
{
protected:
    int room_counter; //комнаты
    int floor_counter; //этажи
public:
    Appartment(int w, char* n, char* o, int r, int f); //конструктор 
    void print();
    void taxesAp();
    double ReturnAP();
};


class Car : protected Property
{
private:
    char type2[20];
protected:
    int engine_power; //лошадиные силы
    int type; //тип машины
public:
    Car(int w, char* n, char* o, int e, int t);
    void print();
    void taxesC();
    double ReturnC();
};

class CountryHouse : protected Property
{
protected:
    int gardern_counter;//кол-во грядок(да, да - высасоно из пальца, но лучше уж это, чем копипастить из Appartment)
public:
    CountryHouse(int w, char* n, char* o, int g);
    void print();
    void taxesCH();
    double ReturnCH();

};


Property::Property(int w, char* n, char* o)
{
    worth = w;
    strcpy_s(name, strlen(n) + 1, n);
    strcpy_s(owner, strlen(o) + 1, o);

}

void Property::print()
{
    cout << endl << "Общ. стоимость : " << worth << " долларов, владелец : " << owner << " название : " << name;
}


Appartment::Appartment(int w, char* n, char* o, int r, int f) :
    Property(w, n, o)
{
    if (r <= 8)
    {
        room_counter = r;
    }
    else
    {
        room_counter = 8;
    }

    if (f <= 4)
    {
        floor_counter = f;
    }
    else
    {
        floor_counter = 4;
    }

}

double Appartment::ReturnAP()
{
    double money = worth / 1000;
    return money;
}

void Appartment::taxesAp()
{

    taxes = Appartment::ReturnAP();
    cout << "\n";
    cout << "Плата в месяц : " << taxes << " долларов" << "\n";

}




void Appartment::print()
{


    Property::print();

    cout << " кол-во комнат : " << room_counter << " кол-во этажей : " << floor_counter << " ";
    Appartment::taxesAp();
}

Car::Car(int w, char* n, char* o, int e, int t) :
    Property(w, n, o)
{
    if (e <= 180)
    {
        engine_power = e;
    }
    else
    {
        engine_power = 180;
    }

    type = t;

}

double Car::ReturnC()
{
    double money = worth / 200;
    return money;
}

void Car::taxesC()
{
    taxes = Car::ReturnC();
    cout << "\n";
    cout << "Плата в месяц : " << taxes << " долларов" << "\n";

}

void Car::print()
{


    Property::print();
    cout << " мощность двигателя : " << engine_power << " км.ч  тип машины : " << type << " ";
    Car::taxesC();
}

CountryHouse::CountryHouse(int w, char* n, char* o, int g) :
    Property(w, n, o)
{
    if (g <= 10)
    {
        gardern_counter = g;
    }
    else
    {
        gardern_counter = 10;
    }
}

double CountryHouse::ReturnCH()
{
    double money = worth / 500;
    return money;
}

void CountryHouse::taxesCH()
{
    taxes = worth / 500;
    cout << "\n";
    cout << "Плата в месяц : " << taxes << " долларов" << "\n";
}



void CountryHouse::print()
{
    Property::print();
    cout << " кол-во грядок : " << gardern_counter;
    CountryHouse::taxesCH();
}





int main()
{
    system("cls");
    setlocale(LC_ALL, "Russian");
    int counter = 1;
    double tax = 0;
    char a[20];//имя

    cout << "Введи своё имя, щенок\n";
    cin >> a;
    try
    {
        Appartment z(25000, (char*)"Особняк на тисовой улице", (char*)a, 8, 4);
        Appartment x(19000, (char*)"Особняк на авеню 9 3/4", (char*)a, 6, 2);
        Appartment c(1000, (char*)"Особняк на птицевой улочке", (char*)a, 1, 1);

        Car v(2500000, (char*)"Rois Rolls", (char*)a, 150, 1);
        Car b(1000000, (char*)" Armored personnel carrier Rhino", (char*)a, 180, 3);

        CountryHouse n(250000, (char*)"Дедушкина дача(без деда)", (char*)a, 6);
        CountryHouse m(210000, (char*)"Бабушкина дача(без --РОСКОМНАДЗОР--)", (char*)a, 3);

        Appartment* ai = &z;
        Appartment* ao = &x;
        Appartment* ap = &c;

        Car* ci = &v;
        Car* co = &b;

        CountryHouse* hi = &n;
        CountryHouse* ho = &m;

        tax = z.ReturnAP() + x.ReturnAP() + c.ReturnAP() + v.ReturnC() + b.ReturnC() + n.ReturnCH() + m.ReturnCH();

        ;

        ai->print();
        ao->print();
        ap->print();

        ci->print();
        co->print();

        hi->print();
        ho->print();

        cout << "\n";
        cout << "Сейчас вы оплачиваете "; cout << tax << " долларов.\n";
        cout << "\n";




    }
    catch (const std::exception&)
    {
        cout << "Произошёл отвал бошки, попробуйте снова (позже)\n";
    }







}

