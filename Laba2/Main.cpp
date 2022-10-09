#include <iostream>
#include <cmath>

using namespace std;

int counterPow = 0;
int counterRexPow = 0;
int counterQuickPower = 0;
int counterRecQuickPower = 0;


long double power(long double number, unsigned int powerNum)
{
    long double res = 1;

    for (int i = 1; i <= powerNum; i++)
    {
        counterPow++;
        res = res * number;
    }

    return res;
}

long double recPower(long double number, unsigned int powerNum)
{
    if (powerNum == 0) return 1;

    counterRexPow++;

    return number * power(number, powerNum - 1);
}

long double quickPower(long double number, unsigned int powerNum)
{
    double res = 1;

    while (powerNum > 0)
    {
        counterQuickPower++;

        if (powerNum % 2) res *= number;
            
        powerNum = powerNum / 2;

        number *= number;
    }

    return res;
}

long double recQuickPower(long double number, unsigned int powerNum)
{
    if (powerNum != 0)
    {
        if (powerNum % 2)
        {
            counterRecQuickPower++;
            return (number * recQuickPower(number * number, powerNum / 2));
        }
        else
        {
            counterRecQuickPower++;
            return (recQuickPower(number * number, powerNum / 2));
        }

    }
    else
    {
        return 1;
    }
}



int main()
{
    double number = 2.2;

    cout << "My power" << "My recPower" << "My quickPower" << "My recQuickPower" << "CMATH pow" << endl;

    for (int i = 0; i < 30; i++)
    {
        cout << "pow: " << i << " - " << power(number, i)<< endl;
    }
    cout << "Counter: " << counterPow << endl << endl;

    cout << "My recPower" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << "pow: " << i << " - " << recPower(number, i) << endl;
    }
    cout << "Counter: " << counterRexPow << endl << endl;

    cout << "My quickPower" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << "pow: " << i << " - " << quickPower(number, i) << endl;
    }
    cout << "Counter: " << counterQuickPower << endl << endl;

    cout << "My recQuickPower" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << "pow: " << i << " - " << recQuickPower(number, i) << endl;
    }
    cout << "Counter: " << counterRecQuickPower << endl << endl;

    cout << "CMATH pow" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << "pow: " << i << " - " << pow(number, i) << endl;
    }

    return 0;
}