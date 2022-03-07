#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



    string compound;

    string cntA, cntB;

    int a=0, b=0;

    int mass;

    cin >> compound;


    for (int i = compound.find('C') + 1; i != compound.find('H'); i++)

    {
            cntA += compound[i];
    }
    
    if (cntA.empty()) cntA = "1";



    for (int i = compound.find('H') + 1; i <compound.size(); i++)

    {

            cntB += compound[i];

    }



    if (cntB.empty()) cntB = "1";



    a = stoi(cntA);

    b = stoi(cntB);



    mass = a * 12+ b;



    cout << mass << endl;



    return 0;
