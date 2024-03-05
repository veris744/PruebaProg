
#include <iostream>
#include <vector>
#include <algorithm>
#include "Persona.h"
#include <string>
#include <fstream>

//Para esta prueba he creado varias funciones de lectura de datos para probar yo el código.
//Las funciones reales vuestras que hay que usar las he dejado comentadas para evitar los errores que me da el no tenerlas.
//Las funciones con los algoritmos son: ParOImpar, Clasificar y CalculoSalario que reciben cada una los parametros necesarios.

//Adicionalmente, al no tener claro como funcionaba la lectura de datos al principio de la prueba implementé una lectura de archivo
//para el ejercicio 1 (pregunté pero ya lo tenía implementado cuando recibí la respuesta de como funcionaba la lectura).

//MUCHAS GRACIAS!

static std::string DATOS1 = "datos1.txt";

//EJERCICIO 1 ////////////////////////////////////////////////////////////////
void LeerNumeroPrueba(int& n)
{
    char cadena[128];
    std::ifstream file(DATOS1);

    while (!file.eof())
    {
        file >> cadena;
    }

    file.close();

    for (char c : cadena)
    {
        if (c == '\0') break;
        if (!std::isdigit(c))
        {
            std::cout << "Error archivo." << std::endl;
            return;
        }
    }

    n = atoi(cadena);
}

void ParOImpar(int n)
{

    if (n <= 0)
    {
        std::cout << "Error n." << std::endl;
        return;
    }

    if (n % 2 == 0)
    {
        for (int i = n; i >= 0; i -= 2)
        {
            std::cout << i << " ";
        }
    }
    else
    {
        for (int i = n; i >= 1; i -= 2)
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}



//EJERCICIO 2 ////////////////////////////////////////////////////////////////
void LeerPersonasPrueba(std::vector<Persona>& personas)
{
    Persona p = Persona();
    p.edad = 1;
    p.sexo = Genero::FEMENINO;
    personas.push_back(p);

    p = Persona();
    p.edad = 15;
    p.sexo = Genero::MASCULINO;
    personas.push_back(p);

    p = Persona();
    p.edad = 45;
    p.sexo = Genero::FEMENINO;
    personas.push_back(p);

    p = Persona();
    p.edad = 18;
    p.sexo = Genero::MASCULINO;
    personas.push_back(p);

    p = Persona();
    p.edad = 18;
    p.sexo = Genero::MASCULINO;
    personas.push_back(p);
}

void Clasificar(std::vector<Persona>& personas)
{

    if (personas.empty())
    {
        std::cout << "Error no hay personas." << std::endl;
        return;
    }
    if (personas.size() != 50)
    {
        std::cout << "Warning no hay 50 personas." << std::endl;
        
    }

    int totalMayores = 0;
    int totalMayoresM = 0;
    int totalMayoresF = 0;
    int totalF = 0;

    for (auto p : personas)
    {
        if (p.edad >= 18)
        {
            totalMayores++;

            if (p.sexo == Genero::FEMENINO) totalMayoresF++;
            else totalMayoresM++;
        }
        if (p.sexo == Genero::FEMENINO) totalF++;
    }

    std::cout << "Total Mayores de Edad: " << totalMayores << std::endl;
    std::cout << "Total Menores de Edad: " << personas.size() - totalMayores << std::endl;
    std::cout << "Total Masculinos Mayores de Edad: " << totalMayoresM << std::endl;
    std::cout << "Total Femeninos Mayores de Edad: " << totalMayoresF << std::endl;

    float pctMayores = (float)totalMayores * 100 / (float)personas.size();
    float pctF = (float)totalF * 100 / (float)personas.size();

    std::cout << "Porcentaje Mayores de Edad: " << pctMayores << "%" << std::endl;
    std::cout << "Porcentaje Mujeres: " << pctF << "%" << std::endl;
}


//EJERCICIO 3 ////////////////////////////////////////////////////////////////

void LeerHorasTrabajadasPrueba(float& f)
{
    f = 45;
}

void LeerTarifaPrueba(float& f)
{
    f = 50;
}

void CalculoSalario(float horasTrabajadas, float tarifa)
{
    if (horasTrabajadas <= 0)
    {
        std::cout << "Error salario." << std::endl;
        return;
    }
    if (tarifa <= 0)
    {
        std::cout << "Error tarifa." << std::endl;
        return;
    }

    float horasBase = (horasTrabajadas <= 40) ? horasTrabajadas : 40.f;
    float horasExtra = (horasTrabajadas < 40) ? 0.f : horasTrabajadas - 40.f;
    float salario = horasBase * tarifa + horasExtra * (tarifa + tarifa * 50 / 100);

    std::cout << "Salario: " << salario << std::endl;



    //LOGICA ALTERNATIVA PREGUNTA 3 (TARIFA CUMULATIVA)
    //No entendí bien la pregunta y programé ambas logicas antes de recibir una respuesta aclarandome mis dudas
    //La dejo comentada porque ya la programé y no quiero borrarla

    /*float salario = 0;

    if (horasTrabajadas <= 40)
    {
        salario = horasTrabajadas * tarifa;
    }
    else
    {
        int horasExtra = horasTrabajadas - 40;
        salario = 40 * tarifa;
        float tarifaUp = tarifa;

        for (int i = 1; i <= horasExtra; i++)
        {
            tarifaUp += tarifa * 50 / 100;
            salario += tarifaUp;
        }
    }*/
}


int main()
{
    //EJERCICIO 1 ////////////////////////////////////////////////////////////////
    int NUMERO;

    LeerNumeroPrueba(NUMERO);

    //LEERNUMERO(NUMERO)

    ParOImpar(20);
    ParOImpar(NUMERO);


    //EJERCICIO 2 ////////////////////////////////////////////////////////////////
    std::vector<Persona> PERSONAS;

    LeerPersonasPrueba(PERSONAS);

    //LEERPERSONAS(PERSONAS);

    Clasificar(PERSONAS);


    //EJERCICIO 3 ////////////////////////////////////////////////////////////////
    float TARIFA;
    float HORASTRABAJADAS;

    LeerHorasTrabajadasPrueba(HORASTRABAJADAS);
    LeerTarifaPrueba(TARIFA);

    //LEERTARIFA(TARIFA);
    //LEERHORASTRABAJADAS(HORASTRABAJADAS)

    CalculoSalario(HORASTRABAJADAS, TARIFA);
}

