#include <iostream>
#include <string>
#include <exception>
#include"MyexceptionInherit.h"
#include"Empty.h"
#include"MyException.h"
using namespace std;

double Variant1(double a,double b, double c) throw (MyExceptionInherit){
    double D = b * b - 4 * a * c;
    if (D<0)
    {
        throw MyExceptionInherit("D<0");
    }
    else {
        return (-b + sqrt(D)) / (2 * a);
    }
}
double Variant2(double a, double b, double c) throw (int) {
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        throw 0;
    }
    else {
        return (-b + sqrt(D)) / (2 * a);
    }
}

double Variant3(double a, double b, double c) throw (Empty) {
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        throw Empty();
    }
    else {
        return (-b + sqrt(D)) / (2 * a);
    }
}

double Variant4(double a, double b, double c) throw (MyException) {
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        throw MyException("D<0");
    }
    else {
        return (-b + sqrt(D)) / (2 * a);
    }
}

double Variant5(double a, double b, double c) throw (bad_exception) {
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        throw "21";
    }
    else {
        return (-b + sqrt(D)) / (2 * a);
    }
}

void FU()
{
    cout << "unexpected error! - bad_exception" << endl;
    throw;
}
void FT()
{
    cout << "unknown error! - terminate" << endl;
    //unexpected();
    abort();
}

int main()
{
    //set_unexpected(FU);
    set_terminate(FT);
    int a, b, c;
    cout << "Input a: "; cin >> a;
    cout << "Input b: "; cin >> b;
    cout << "Input c: "; cin >> c;
    try {
        cout<<"Answer is : "<<Variant1(a, b, c)<<endl;
        cout<<"Answer is : "<<Variant2(a, b, c)<<endl;
        cout<<"Answer is : "<<Variant3(a, b, c)<<endl;
        cout<<"Answer is : "<<Variant4(a, b, c)<<endl;
        cout<<"Answer is : "<<Variant5(a, b, c)<<endl;
    }
    catch (MyExceptionInherit& e) {
        cout << "Error " << e.what() << endl;
    }
    catch (MyException& e) {
        cout << "Error " << e.what() << endl;
    }
    catch (int i) {
        cout << "Error " << i << endl;
    }
    catch (Empty *e) {
        cout << "Error Empty" << endl;
    }
    catch (bad_exception)
    {
        cout << " catch (bad_exception)" << endl;
    }
    catch (exception e)
    {
        cout << " catch (exception) " <<e.what()<< endl;
    }
}

