#include <iostream>
#include <cmath>
using namespace std;

int EquationSolving(double a,double b = 0,double c = 0){

    double delta = b*b - 4*a*c;
    
    if(delta < 0){
        // 当无解时判断复数
        cout << "x1 = " << -b/(2*a) << " + " << sqrt(-delta)/(2*a) << "i" << endl;
        return 0;
    }
    else if(delta == 0){
        cout << "x1 = x2 = " << -b/(2*a) << endl;
        return 0;
    }
    else{
        cout << "x1 = " << (-b + sqrt(delta))/(2*a) << endl;
        cout << "x2 = " << (-b - sqrt(delta))/(2*a) << endl;
        return 0;
    }

}


int main(){

    //三个数求最大值，求解一元二次方程组
    //从键盘输入一元二次方程的系数，求解方程
    double a,b,c;
    cout << "Please input the coefficient of the quadratic equation: ";
    cin >> a >> b >> c;

    //判断输入的系数是否合法
    if(a == 0){
        cout << "The coefficient of x^2 cannot be 0!" << endl;
        return 0;
    }

    EquationSolving(a,b,c);

    return 0;
}