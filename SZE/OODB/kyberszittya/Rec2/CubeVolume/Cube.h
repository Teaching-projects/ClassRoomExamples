#pragma once

// Kisz�m�tjuk a kocka t�rfogat�t
class Cube
{
private:
	const double a, b, c;
public:

	Cube(const double a, const double b, const double c);

	// Sz�moljunk t�rfogatot!
	double volume() const;
	// Ellen�rizz�k, j�-e a kocka
	bool validCube() const;
};