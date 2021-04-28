#include<iostream>
#include <ctype.h> //<---aqui se encuentran las funciones toupper y tolower
using namespace std;
int opcion;
char genero, estadoCivil;
float nota, AcumuladorMujeresAprob = 0, notaPromedioMujeresAprobadas, AcumuladorMujerDesapro = 0, notaPromedioMujeresDesaprobadas;
int numeroTotalDesaprobados = 0, hombresAprobados = 0;
int mujeresAprobadas = 0,mujeresDesaprob=0, hombresCasadosAprobados = 0,
hombresCasadosDesaprobados = 0, mujeresSolterasAprobadas = 0 , mujeresDivorciadas = 0;

int main() {
	do {
		do
		{
			cout << "Menu principal" << endl;
			cout << "1 Recaudar Datos" << endl;
			cout << "2 Reportar Datos" << endl;
			cout << "3 Salir" << endl;
			cout << "Ingrese Opcion" << endl;
			cin >> opcion;
		} while (opcion == 1 && opcion == 2 && opcion == 3);
		switch (opcion)
		{
		case 1: {
			// ingresando el genero
			do {
				cout << "Ingresar Genero" << endl;
				cin >> genero;
				genero = tolower(genero);// pasar a minuscula todo
				if (genero != 'f' && genero != 'm')

				{
					cout << "Ingreso incorrecto (F o M), vuelva a intentar" << endl;

				}
			} while (genero != 'f' && genero != 'm');

			//ingresando el estado civil
			do {
				cout << "Ingresar Estado civil" << endl;
				cin >> estadoCivil;
				estadoCivil = tolower(estadoCivil);
				if (estadoCivil != 'c' && estadoCivil != 's' && estadoCivil != 'd')


				{
					cout << "Ingreso incorrecto es (C, S o D),vuelva a intentar" << endl;

				}
			} while (estadoCivil != 'c' && estadoCivil != 's' && estadoCivil != 'd');

			// ingresando las notas
			do {
				cout << "Ingrese Nota" << endl;
				cin >> nota;
				if (nota <= 0 || nota >= 20)
					cout << "Nota incorrecta" << endl;

			} while (nota <= 0 || nota >= 20);
			
			if (nota <+ 10.5)
				numeroTotalDesaprobados++;
			

			if (nota >= 10.5 and estadoCivil == 'c' and genero == 'm')
				hombresCasadosAprobados++;

			if (nota <= 10.5 and estadoCivil == 'c' and genero == 'm')
				hombresCasadosDesaprobados++;

			if (nota >= 10.5 and estadoCivil == 's' and genero == 'f')
				mujeresSolterasAprobadas++;
			
			if (genero == 'f' and estadoCivil == 'd')
				mujeresDivorciadas++;

			if (nota >= 10.5 and genero == 'f')
			{
				mujeresAprobadas++;
				AcumuladorMujeresAprob = AcumuladorMujeresAprob + nota;
				notaPromedioMujeresAprobadas = AcumuladorMujeresAprob / mujeresAprobadas;
			}
			
			if (nota <= 10.5 and genero == 'f')
			{
				mujeresDesaprob++;
				AcumuladorMujerDesapro = AcumuladorMujerDesapro + nota;
				notaPromedioMujeresAprobadas = AcumuladorMujeresAprob / mujeresDesaprob;
			}
			
				
			if (nota >= 10.5 and genero == 'm')
				hombresAprobados++;
			
			
			break;
		}
		case 2: {
			cout << "Cant de varones aprobado es " << hombresAprobados << endl;
			cout << "Cant de mujeres aprobado es " << mujeresAprobadas << endl;
			cout << "Cant de varones casados aprobado es " << hombresCasadosAprobados << endl;
			cout << "Cant de varones casados desaprobado es " << hombresCasadosDesaprobados << endl;
			cout << "Cant de Mujeres solteras aprobadas es " << mujeresSolterasAprobadas << endl;

			cout << "Cant de Mujeres divorciadas es " << mujeresDivorciadas << endl;
			cout << "Cant de Desaprobado es " << numeroTotalDesaprobados << endl;
			cout << "La nota promedio de las mujeres aprobadas es " << notaPromedioMujeresAprobadas << endl;

			cout << "La nota promedio de los varones desaprobadas es " << notaPromedioMujeresDesaprobadas << endl;

			break;
		}
		}
	} while (opcion != 3);

}
