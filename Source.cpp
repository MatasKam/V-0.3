#include "duomenys.h"

int main()
{
	duomenys D;
	ifstream klasiokai;
	klasiokai.open("kursiokai.txt");

	try {
		if (klasiokai.is_open())
		{
			klasiokai >> D.var >> D.pav;
			while (D.q != "Egz.") // perskaito visus namu darbus kiek ju yra
			{
				klasiokai >> D.q;
				if (D.q == "Egz.") {
					break;
				}
				D.kiek.push_back(D.q);
			}
			D.ilgis = D.kiek.size();

			D.ndp.reserve(D.ilgis);




			while (!klasiokai.eof())
			{
				klasiokai >> D.vardas >> D.pavarde;
				int xxx;
				for (int i = 1; i <= D.ilgis; i++)
				{
					klasiokai >> xxx;
					D.ndp.push_back(xxx);
				}
				klasiokai >> D.egzp;

				

				D.gaidz.push_back(D);
				D.ndp.clear();
			}


			cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(33) << "Galutinis balas (Vid.)" << setw(25) << "Galutinis (Med.)" << endl;
			cout << setfill('-') << setw(90) << "-" << endl;
			float med;
			for (auto& elementas : D.gaidz)
			{
				float balas = (double)accumulate(elementas.ndp.begin(), elementas.ndp.end(), 0) / elementas.ndp.size() * 0.4 + elementas.egzp * 0.6;


				if (elementas.ndp.size() % 2 != 0)
				{
					med = (double)elementas.ndp[elementas.ndp.size() / 2];
				}
				else
				{
					med = (double)(elementas.ndp[(elementas.ndp.size() - 1) / 2] + elementas.ndp[elementas.ndp.size() / 2]) / 2.0;
				}
				cout << setfill(' ') << setw(17) << elementas.vardas << setw(20) << elementas.pavarde << setw(14) << setprecision(2) << fixed << balas << setw(31) << setprecision(2) << fixed << med << endl;
			}
		}
	}
	catch (const ifstream::failure& e) 
	{
		cout << "Nepavyko atidaryti failo";
	}
	klasiokai.close();





	return 0;
}
