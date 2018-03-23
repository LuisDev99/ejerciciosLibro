//#include <vector>
//#include <iostream>
//using namespace std;
//
//
//bool palindromo(const vector<int>&);
//
//int main() {
//	vector<int> ints;
//	cout << "### ENTERO PALINDROMO DE VECTOR ###" << endl;
//	int menu;
//	do {
//		
//		cout << "Ingrese valor al vector (-1 para dejar de dar valores al arreglo y ver si es palindromo): ";
//		cin >> menu;
//
//		if (menu != -1)
//			ints.push_back(menu);
//
//	} while (menu !=-1);
//
//	cout << ((palindromo(ints) == true) ? "Es palindromo" : "No es palindromo") << endl;
//
//	system("pause");
//}
//
////cout << "Ingrese el numero palindromo: ";
////
//bool palindromo(const vector<int>& entero) {
//
//	for (int i = 0; i < entero.size(); i++) {
//		int size = entero.size() - (i + 1);
//		if (entero[i] != entero[size])
//			return false;
//		
//	}
//
//	return true;
//
//}

#include <iostream>


#include <algorithm>
#include <array>
#include <iterator>
#include <string>
#include <vector>


using namespace std;

bool palindromo(const vector< int > &ints) {

	vector< int > ints2;

	reverse_copy(ints.cbegin(), ints.cend(), back_inserter(ints2));

	return ints == ints2;

}

string reverseString(string p) {
	string r;
	for (int i = p.size() - 1; i >= 0; i--)
		r += p[i];
	return r;
}




int main() {
	ostream_iterator< int > out(cout, " ");

	vector<int> ints;

	int data = 0, data1 = 0, menu = 0;
	string palabra, reversa;

	array< int , 20> valores;

	do {

		cout << "1. Palindromo con vector ints \n2. Valores Unico \n3. Palindromo String \n4. Salir \nIngrese lo que quiere hacer: ";
		cin >> menu;

		switch (menu) {

		case 1:
		{
			do {
				cout << "Ingrese el dato que desea agregar (-1 para salir y ver resultado): ";
				cin >> data;
				if (data != -1)
					ints.push_back(data);
			} while (data != -1);

			cout << "El vector contiene los siguientes numeros: ";
			cout << ((palindromo(ints) ? "\nEs palindromo" : "\nNo es palindromo")) << endl;
			ints.clear();
		}
			break;

		case 2: 
		{
			cout << "Ingrese 20 valores ordenados: ";

			for (int i = 0; i < 20; i++) {
				cin >> data1;
				valores[i] = data1;
			}

			cout << "Arreglo original: "; copy(valores.cbegin(), valores.cend(), out);
			_Array_iterator<int, 20> ubicacionFinal = unique(valores.begin(), valores.end());
			cout << endl;
			cout << "Usando el algoritmo: ";
			copy(valores.begin(), ubicacionFinal, out);
			cout << endl;
		}

		break;

		case 3:
		{
			cout << "Ingrese la palabra para ver palindromidad: ";
			cin >> palabra;
			reversa = reverseString(palabra);
	
			if (palabra == reversa)
				cout << "Es palindromo";
			else
				cout << "No es palindromo";
			cout << endl;
		}
			break;

		}

	} while (menu != 4);
}