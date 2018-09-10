#include <iostream>
//#include <vector>
#include "circle.h"
#include "myarray.h"
#include "student.h"

using namespace std;


int comp(student* a, student* b){
    if ( a->avg() > b->avg() ) return 1;
    else if ( a->avg() < b->avg() ) return -1;
    else return 0;
}

int main()
{
    //Тест создание объекта окружность
    Circle* c = new Circle(0, 0, 2);
    cout << "Площадь окружности:" << c->Area() << endl;

    //Тест хранение объектов
    mylib::array<student*>* arr = new mylib::array<student*>(10);

    arr->push_back( new student("Петров", 4, 4, 4) );
    arr->push_back( new student("Сидоров", 2, 2, 2) );
    arr->push_back( new student("Семенов", 3, 4, 5) );
    arr->push_back( new student("Смирнов", 3, 4, 3) );
    arr->push_back( new student("Иванов", 5, 5, 5) );
    arr->qsort(0, arr->size() - 1, comp);
    for(int i = 0; i < arr->size(); i++)
        arr->at(i)->print();

    //Хранение базовых типов
    mylib::array<int>* arr2 = new mylib::array<int>(2);
    arr2->push_back(2);
    arr2->push_back(3);
    arr2->push_back(5);
    arr2->push_back(9);
    arr2->remove(1);


    for(int i = 0; i < arr2->size(); i++)
        cout <<  arr2->at(i) << '\n';

    //Нагрузочные тесты
     mylib::array<int>* arr3 = new mylib::array<int>(2000);
    srand(2000);
    for (int i = 0; i < 2000; i++)
        arr3->push_back( rand() % 2000 );

    arr3->qsort(0, arr3->size() - 1);
    for(int i = 0; i < arr3->size(); i++)
        if ( i < 20 ) cout <<  arr3->at(i) << ',';
        else if (i == 21 )  cout << "...";
    cout << '\n';

    //Тест связанных списков

    return 0;
}
