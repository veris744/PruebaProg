#pragma once

enum class Genero
{
	FEMENINO,
	MASCULINO
};

struct Persona
{
	Genero sexo = Genero::FEMENINO;
	unsigned int edad = 0;
};

