
#include <iostream>
#include <string>
#include "Train.h"
#include "TrainV1.h"
#include "TemplateClass.h"

template<typename T>
T search_max(T* arr, unsigned count)
{
    T max = *arr;
    T* ptr = arr;
    while (count--)
    {
        if (*arr > max) ptr = arr, max = *arr;
        arr++;
    }
    return max;
}

template <typename T>
T middle(T massive[], int size) {
	T value = 0;
	for (int i = 0; i < size; i++) {
		value += massive[i];
	}
	return value / size;
}

int main()
{
    TemplateClass<int> tclass1(3);

    tclass1[0] = 1;
    tclass1[1] = 2;
    tclass1[2] = 3;

    tclass1.showArray();
    tclass1.average();
    tclass1.max();

    const int k = 5;

    int a1[k] = { 1,2,3,4,5 };
    float a2[k] = { 1.1,2.2,8,4,5 };

    std::cout << "Max value a1 = " << search_max(a1, k) << std::endl;
    std::cout << "Max value a2 = " << search_max(a2, k) << std::endl;
    const int n = 5;

    int m1[n] = { 1,2,3,4,5 };
    long m2[n] = { 5,6,7,8,9};
    double m3[n] = { 1.0,3.0,4.0,5.0,6.0 };
    char m4[n] = {'M', 'a', 'r', 'r', 'y'};

    std::cout << "Middle value m1 = " << middle(m1, n) << std::endl;
    std::cout << "Middle value m2 = " << middle(m2, n) << std::endl;
    std::cout << "Middle value m3 = " << middle(m3, n) << std::endl;
    std::cout << "Middle value m4 = " << middle(m4, n) << std::endl;

    Train train1s;
    Train train2s;

    train1s.setDepartureTime("1:00");
    train1s.setDestination("New York");
    train1s.setNumber(33);
    train1s.setNOP(2, 3, 4, 5);

    train2s.setDepartureTime("2:00");
    train2s.setDestination("Paris");
    train2s.setNumber(44);
    train2s.setNOP(2, 3, 4, 5);

    train1s.saveToFile("Object1.txt");
    train2s.saveToFile("Object2.txt");

    Train train3l;
    Train train4l;

    train3l.loadFromFile("Object1.txt");
    train4l.loadFromFile("Object2.txt");

    Train train1;

    train1.setDepartureTime("12:00");
    train1.setDestination("London");
    train1.setNumber(15);
    train1.setNOP(2, 3, 4, 5);

    int nop1, nop2, nop3, nop4;

    train1.getNOP(nop1, nop2, nop3, nop4);

    std::string str, timestr;

    std::cout << "Please, enter destination: " << std::endl;
    std::cin >> str;

    std::cout << "Please, enter time: " << std::endl;
    std::cin >> timestr;

	if (train1.transportStatus(timestr)) {
		std::cout << "Train available" << std::endl;
	}
	else
	{
		std::cout << "Train is NOT available" << std::endl;
	};

	if (str == train1.getDestination()) {

	std::cout << "Number: " << train1.getNumber() << std::endl;
	std::cout << "Destination: " << train1.getDestination() << std::endl;
	std::cout << "DepartureTime: " << train1.getDepartureTime() << std::endl;
	std::cout << "Nop: " << nop1 << nop2 << nop3 << nop4 << std::endl;
    }
    else {
        std::cout << "No match found" << std::endl;
    }

    Transport* trasnportArray[4];
    std::string className;

    int num;
    std::string departTime, dest;

    for (int i = 0; i < 4; i++)
    {
		std::cout << "Enter class name" << std::endl;
		std::cin >> className;
		if (className == "Train") {
			trasnportArray[i] = new Train;

            std::cout << "DepartureTime: " << std::endl;
            std::cin >> departTime;
            trasnportArray[i]->setDepartureTime(departTime);

            std::cout << "Destination: " << std::endl;
            std::cin >> dest;
            trasnportArray[i]->setDestination(dest);

            std::cout << "Number: " << std::endl;
            std::cin >> num;
            trasnportArray[i]->setNumber(num);
		}
		else { trasnportArray[i] = 0; }

    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Number: " << trasnportArray[i]->getNumber() << std::endl;
        std::cout << "Destination: " << trasnportArray[i]->getDestination() << std::endl;
        std::cout << "DepartureTime: " << trasnportArray[i]->getDepartureTime() << std::endl;
        trasnportArray[i]->vTest();
    }

    

    TrainV1 train2;

    std::cout << "Operator >> test" << std::endl;

    std::cin >> train2;

    std::cout << "Operator << test" << std::endl;

    std::cout << train2 << std::endl;

}

