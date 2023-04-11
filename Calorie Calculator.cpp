#include <iostream>
using namespace std;

class Data
{
public:
    int kg, height, years;
    char sex;
}person;

class Macronutrients
{
public:
    int prot, fats, carbo12, carbo14, carbo12Cut, carbo14Cut, carbo12Bulk, carbo14Bulk;
}macro;

class Calories
{
public:
    int P, G, C12, C14, C12Cut, C14Cut, C12Bulk, C14Bulk;
    float Effort12, Effort14, Effort12Cut, Effort14Cut, Effort12Bulk, Effort14Bulk;
}kcal;

void macronutrientsMent()
{
    cout << macro.prot << "g proteins" << endl;
    cout << macro.fats << "g fats" << endl;
    cout << macro.carbo12 << "g carbs (lazy day)" << endl;
    cout << macro.carbo14 << "g carbs (gym day)" << endl << endl;
}

void macronutrientsCut()
{
    cout << macro.prot << "g proteins" << endl;
    cout << macro.fats << "g fats" << endl;
    cout << macro.carbo12Cut << "g carbs (lazy day)" << endl;
    cout << macro.carbo14Cut << "g carbs (gym day)" << endl << endl;
}

void macronutrientsBulk()
{
    cout << macro.prot << "g proteins" << endl;
    cout << macro.fats << "g fats" << endl;
    cout << macro.carbo12Bulk << "g carbs (lazy day)" << endl;
    cout << macro.carbo14Bulk << "g carbs (gym day)" << endl << endl;
}

int main() {

    int m, n;
    char goal;
    do {
        cout << "Type your gender M / F: ";
        cin >> person.sex;
        cout << "Type your weight (kg): ";
        cin >> person.kg;
        cout << "Type your height (cm): ";
        cin >> person.height;
        cout << "Type your age (years): ";
        cin >> person.years;
        cout << endl;

        if (person.sex == 'M') {
            kcal.Effort12 = (66 + (float)(13.7 * person.kg) + (float)(5 * person.height) - (float)(6 * person.years)) * 1.2;
            kcal.Effort14 = (66 + (float)(13.7 * person.kg) + (float)(5 * person.height) - (float)(6 * person.years)) * 1.4;
        }
        else {
            kcal.Effort12 = (655 + (float)(9.6 * person.kg) + (float)(1.7 * person.height) - (float)(4.7 * person.years)) * 1.2;
            kcal.Effort14 = (655 + (float)(9.6 * person.kg) + (float)(1.7 * person.height) - (float)(4.7 * person.years)) * 1.4;
        }

        cout << "MAINTENANCE" << endl;
        cout << "Calories:" << endl;
        cout << kcal.Effort12 << "kcal (lazy day)" << endl;
        cout << kcal.Effort14 << "kcal (gym day)" << endl << endl;

        cout << "Macronutrients:" << endl;
        macro.prot = 2 * person.kg;
        macro.fats = 0.4 * 2.2 * person.kg;
        kcal.P = macro.prot * 4;
        kcal.G = macro.fats * 9;
        kcal.C12 = kcal.Effort12 - kcal.P - kcal.G;
        kcal.C14 = kcal.Effort14 - kcal.P - kcal.G;
        macro.carbo12 = kcal.C12 / 4;
        macro.carbo14 = kcal.C14 / 4;

        macronutrientsMent();

        do {
            cout << "What is your goal? Cutting or Bulking?(C sau B): ";
            cin >> goal;
            cout << endl;

            if (goal == 'C' || goal == 'C') {
                kcal.Effort12Cut = kcal.Effort12 - 350;
                kcal.Effort14Cut = kcal.Effort14 - 350;
                cout << "CUTTING" << endl;
                cout << "Calories:" << endl;
                cout << kcal.Effort12Cut << "kcal (lazy day)" << endl;
                cout << kcal.Effort14Cut << "kcal (gym day)" << endl << endl;

                cout << "Macronutrients:" << endl;
                kcal.C12Cut = kcal.Effort12Cut - kcal.P - kcal.G;
                kcal.C14Cut = kcal.Effort14Cut - kcal.P - kcal.G;
                macro.carbo12Cut = kcal.C12Cut / 4;
                macro.carbo14Cut = kcal.C14Cut / 4;

                macronutrientsCut();

            }
            else {
                kcal.Effort12Bulk = kcal.Effort12 + 200;
                kcal.Effort14Bulk = kcal.Effort14 + 200;
                cout << "Bulking" << endl;
                cout << "Calories:" << endl;
                cout << kcal.Effort12Bulk << "kcal (lazy day)" << endl;
                cout << kcal.Effort14Bulk << "kcal (gym day)" << endl << endl;

                cout << "Macronutrients:" << endl;
                kcal.C12Bulk = kcal.Effort12Bulk - kcal.P - kcal.G;
                kcal.C14Bulk = kcal.Effort14Bulk - kcal.P - kcal.G;
                macro.carbo12Bulk = kcal.C12Bulk / 4;
                macro.carbo14Bulk = kcal.C14Bulk / 4;

                macronutrientsBulk();
            }
            cout << "Do you have another goal? If yes, please press Y" << endl;
            getchar();
            m = getchar();
        } while (m == 'Y' || m == 'y');
        cout << "Do you want to type another measurements? If yes, please press Y" << endl;
        getchar();
        n = getchar();
    } while (n == 'Y' || n == 'y');
    return 0;
}