// Petxam.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
int ejercicio;
int numeros[8];
//vector<int> numbers = {9386,8642,4621,5232,3314};
using namespace std;
//int numbersread();

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int crazy = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Crazymedicine(int crazy = 4);
    void Checkifdie(int &choice);
    bool Checkifdead();

private:
    int m_Hunger;
    int m_Boredom;
    int m_crazy;
    bool m_dead = false;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int crazy) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_crazy(crazy)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_crazy += time;
}

void Critter::Talk()
{
    cout << "Hola humano que tal tu dia? yo..." << endl;
    if (m_Hunger<2)
    {
        cout << "no tengo mucha hambre" << endl;
    }
    if (m_Boredom<2)
    {
        cout << "La diversion esta en todos lados" << endl;
    }
    if (m_crazy<2)
    {
        cout << "Todo bien todo correcto" << endl;
    }
    if (m_Hunger>=2)
    {
        cout << "Tengo algo de hambre" << endl;
    }
    if (m_Boredom>=2)
    {
        cout << "Estoy algo aburrido" << endl;
    }
    if (m_crazy>=2)
    {
        cout << "Que son esas sombras?" << endl;
    }
    if (m_Hunger>=4)
    {
        cout << "ESTOY MURIENDO DE HAMBRE" << endl;
    }
    if (m_Boredom>=4)
    {
        cout << "MI CEREBRO SE VA A DETENER DE ABURRIMIENTO" << endl;
    }
    if (m_crazy>=4)
    {
        cout << "LO VEO TODO, LOS ANGELES Y DEMONIOS" << endl;
    }
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}
void Critter::Crazymedicine(int crazy)
{
    cout << "Reeee" << endl;
    m_crazy -= crazy;
    if (m_crazy<0)
    {
        m_crazy = 0;
    }
    PassTime();
}
void Critter::Checkifdie(int &choice)
{
    if (m_Boredom>6||m_Hunger>6||m_crazy>6)
    {
        choice = 0;
        m_dead = true;
    }
}
bool Critter::Checkifdead()
{
    if (m_dead)
    {
        return true;
    }
    else
    {
        return false;
    }
}
using namespace std;
int main()
{
	
	cout << "Que ejercicio quieres?"<<endl;
	cin >> ejercicio;
	switch (ejercicio)
	{
	case 1:
        /*numbersread();*/
		break;
	case 2:
        Critter crit;
        crit.Talk();
        int choice;
        do
        {
            cout << "\n Mascotas Virtuales\n\n";
            cout << "0 - Salir.\n";
            cout << "1 - Escucha a tu mascota.\n";
            cout << "2 - Alimentar.\n";
            cout << "3 - Jugar con tu mascota.\n";
            cout << "4 - Darle las pastillas.\n\n\n";
            cout << "Elige una opción: ";
            cin >> choice;
            crit.Checkifdie(choice);
            switch (choice)
            {
            case 0:
                if (crit.Checkifdead())
                {
                    cout << "Tu mascota murio y no volvera nunca mas, aprende a ser mas responsable\n";
                }
                cout << "Vuelve pronto!.\n";
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3:
                crit.Play();
                break;
            case 4:
                crit.Crazymedicine();
                break;
            default:
                cout << "\n Tu elección es inválida. \n";
            }
        } while (choice != 0);

        
		break;

	}

	
}
//int numbersread()
//{
//	for (int i = 0; i < 8; i++)
//	{
//		cin >> numeros[i];
//        numbers.push_back(numeros[i]);
//	}
//    for (int i = 0; i < numbers.count; i++)
//    {
//        cout << numbers[i];
//    }
//    return 0;
//}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
