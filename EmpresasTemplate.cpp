#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string empresas[5] = {
		"Microsoft", "Apple", "Google", "Warner", "Disney"
	};
	int matriz2023[5][12], matriz2024[5][12], matriz2025[5][12];
	string linea;
	int empresa = 0;
	ifstream datos2023("input/ingresos-2023.csv");
	ifstream datos2024("input/ingresos-2024.csv");
	ifstream datos2025("input/ingresos-2025.csv");
	ofstream totales("output/totales.txt");
	
	while (getline(datos2023, linea) && empresa < 5) {
		stringstream ss(linea);
		string valor;
		int mes = 0;
		while (getline(ss, valor, ',') && mes < 12) {
			matriz2023[empresa][mes] = stoi(valor);
			mes++;
		}
		empresa++;
	}
	
	
	empresa = 0;
	while (getline(datos2024, linea) && empresa < 5) {
		stringstream ss(linea);
		string valor;
		int mes = 0;
		while (getline(ss, valor, ',') && mes < 12) {
			matriz2024[empresa][mes] = stoi(valor);
			mes++;
		}
		empresa++;
	}
	
	empresa = 0;
	while (getline(datos2025, linea) && empresa < 5) {
		stringstream ss(linea);
		string valor;
		int mes = 0;
		while (getline(ss, valor, ',') && mes < 12) {
			matriz2025[empresa][mes] = stoi(valor);
			mes++;
		}
		empresa++;
	}
	
	for (int i = 0; i < 5; i++) {
		int total2023 = 0, total2024 = 0, total2025 = 0;
		
		for (int j = 0; j < 12; j++) {
			total2023 = total2023+matriz2023[i][j];
			total2024 = total2024+matriz2024[i][j];
			total2025 = total2025+matriz2025[i][j];
		}
		
		int GananciaTotal = total2023 + total2024 + total2025;
		
		totales << empresas[i] << endl;
		totales << "  2023: " << total2023 << endl;
		totales << "  2024: " << total2024 << endl;
		totales << "  2025: " << total2025 << endl;
		totales << "  Total 3 años: " << GananciaTotal << endl;
	}
	
	cout << "Archivo totales.txt generado exitosamente." << endl;
	
	datos2023.close();
	datos2024.close();
	datos2025.close();
	totales.close();
	
	return 0;
}
