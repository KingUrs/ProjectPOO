#include<iostream>
#include<conio.h>
#include<numeric>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

class  Software
{
public:
	virtual double getStoc_total() = 0;
	virtual double getValoare_totala() = 0;
};
class  Drink {
private:
	int id;
	int stoc_initial;
	float pret;
	char* denumire;

public:
	Drink()
	{
		id = 0;
		stoc_initial = 0;
		pret = 0;
		denumire = NULL;
	}
	Drink(int ID,int STOC, float PRET, char* DEN)
	{
		this->id = ID;
		this->stoc_initial = STOC;
		this->pret = PRET;
		this->denumire = new char[strlen(DEN) + 1];
		strcpy(this->denumire, DEN);
	}
	double getStoc_total(Drink&d)
	{

	}
	int getStoc()
	{
		return this->stoc_initial;
	}
	void setStoc(int stoc_init)
	{
		this->stoc_initial = stoc_init;
	}
	char* getDenumire()
	{
		return this->denumire;
	}
	void setDenumire(char* Denumire)
	{
		if (this->denumire != NULL)
		{
			delete[]this->denumire;
		}
		this->denumire = new char[strlen(Denumire) + 1];
		strcpy(this->denumire, Denumire);
	}
	int getId()
	{
		return this->id;
	}
	void setId(int Id)
	{
		this->id = Id;
	}
	float getPret()
	{
		return this->pret;
	}
	void setPret(float Pret)
	{
		this->pret = Pret;
	}

	~Drink()
	{
		if (this->denumire != NULL)
		{
			delete[]this->denumire;
		}
	}
	Drink(Drink & d)
	{
		this->id = d.id;
		this->pret = d.pret;
		this->denumire = new char[strlen(d.denumire) + 1];
		strcpy(this->denumire, d.denumire);
	}
	Drink&operator =(Drink &d)
	{
		this->id = d.id;
		this->pret = d.pret;
		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = new char[strlen(d.denumire) + 1];
		strcpy(this->denumire, d.denumire);
		return *this;
	}
	friend ostream&operator<<(ostream&out, Drink dd);
	friend istream&operator>>(istream&in, Drink dd);
};

ostream&operator<<(ostream&out, Drink dd)
{
	out << dd.id;
	out << dd.pret;
	out << dd.denumire;
	return out;
}
istream&operator>>(istream&in, Drink dd)
{
	cout << "Alegeti tasta bauturii dorite :";
	in >> dd.id;
	cout << "Pretul bauturii este :" << dd.pret << endl;
	cout << "Denumirea bauturii este :";
	char aux[25];
	in >> aux;
	if (dd.denumire != NULL)
		delete[]dd.denumire;
	dd.denumire = new char[strlen(aux) + 1];
	strcpy(dd.denumire, aux);
	return in;
}

class Livrare
{
private:
	int nr_stoc;
	float pret;
	float bani;
	Drink** bauturi;
public:
	Livrare()
	{
		nr_stoc = 0;
		pret = 0;
		bani = 0;
	}
	int getNr_stoc()
	{
		return this->nr_stoc;
	}
	float getPret()
	{
		return this->pret;
	}
	Drink** getBauturi()
	{
		return this->bauturi;
	}
	void setNr_stoc(int stoc)
	{
		this->nr_stoc = stoc;
	}
	Livrare(int stoc, float cost)
	{
		this->nr_stoc = stoc;
		this->bauturi = new Drink*[nr_stoc];
		for (int i = 0; i < nr_stoc; i++)
			this->bauturi[i] = NULL;
		this->bauturi[nr_stoc];
		if (cost >= 0)
			pret = cost;
		else pret = 3.5;
	}
	float getBani()
	{
		return this->bani;
	}

	void setBani(float BANI)
	{
		this->bani = BANI;
	}
		float operator+(const Livrare &d)
		{
			float pretNou = this->pret + d.pret;
		}
		float operator-(const Livrare &a)
		{
			float reducere = this->pret - a.pret;
		}
};

template <class T>
T mult(T a,T b)
{
	T result;
	result = a*b;
	return result;
};
template <class S>
S scad(S a, S b)
{
	S result;
	result = a-b;
	return result;
};
class Bani
{
private:

	float valoare;

public:
	Bani(float banii = 25)
	{
		if (banii >= 0)
			valoare = banii;
		else
			valoare = 25;
	};
	float getValoare()
	{
		return this->valoare;
	};

	void setValoare(float v)
	{
		this->valoare = v;
	};

	void accept(int in)
	{
		valoare = valoare + in;
	};
	~Bani(){};

};
class Tipuri_bani :public Bani
{
private:
	char* tip_bani;
	float valoare_bani;
	int valoare_banc;
	
public:
	Tipuri_bani() :Bani()
	{
		this->tip_bani = new char[strlen("Bancnota/Moneda") + 1];
		strcpy(this->tip_bani, "Bancnota/Moneda");
		this->valoare_bani = 0;
		this->valoare_banc = 0;
	}
	Tipuri_bani(char* tip_bani, float valoare_bani,int valoare_banc, float valoare) :Bani(valoare)
	{
		this->tip_bani = new char[strlen(tip_bani) + 1];
		strcpy(this->tip_bani, tip_bani);
		this->valoare_bani = getValoare();
		this->valoare_banc = valoare_banc;
	}
	Tipuri_bani(Tipuri_bani&T) :Bani(T)
	{
		this->tip_bani = new char[strlen(T.tip_bani) + 1];
		strcpy(this->tip_bani, T.tip_bani);
		this->valoare_bani = T.getValoare();
		this->valoare_banc = T.valoare_banc;
	}
	Tipuri_bani&operator=(Tipuri_bani&T)
	{
		Bani::operator=(T);
		if (this->tip_bani != NULL)
			delete[]this->tip_bani;
		this->tip_bani = new char[strlen(T.tip_bani) + 1];
		strcpy(this->tip_bani, T.tip_bani);
		this->valoare_bani = T.getValoare();
		this->valoare_banc = T.valoare_banc;
		return *this;
	}
	~Tipuri_bani()
	{
		if (this->tip_bani != NULL)
			delete[]this->tip_bani;
	}
	void setTip_bani(char* tip_bani)
	{
		if (this->tip_bani != NULL)
			delete[]this->tip_bani;
		for (int i; i = 0;i++)
	/*	if (this->valoare_bani = i)
		{
			this->tip_bani = "Bancnote";
		}*/
		this->tip_bani = "Monede";
		//this->tip_bani = new char[strlen(tip_bani) + 1];
		//strcpy(this->tip_bani, tip_bani);
	}
	void setValoare_banc(int valoare_banc)
	{
		this->valoare_banc = valoare_banc;
	}
	int getValoare_banc()
	{
		return this->valoare_banc;
	}
	char* getTip_bani()
	{
		return this->tip_bani;
	}
	void setValoare_bani(float valoare_bani)
	{
		this->valoare_bani = valoare_bani;
	}
	float getValoare_bani()
	{
		return this->valoare_bani;
	}
	
};

void meniu(Drink&d1, Drink&d2, Drink&d3, Drink&d4, Drink&d5)
{
	float a1 = d1.getStoc(),
		a2 = d1.getPret(), 
		b1 = d2.getStoc(),
		b2 = d2.getPret(),
		c1 = d3.getStoc(),
		c2 = d3.getPret(),
		d11 = d4.getStoc(),
		d22 = d4.getPret(),
		e1 = d5.getStoc(),
		e2 = d5.getPret(),
		k1,k2,k3,k4,k5;
	k1 = mult<float>(a1, a2);
	k2 = mult<float>(b1, b2);
	k3 = mult<float>(c1, c2);
	k4 = mult<float>(d11, d22);
	k5 = mult<float>(e1, e2);

	cout << "\n\nEu sunt pregatit.Alege bautura:" << endl<<endl;
	cout << "Apasa 1 pentru * * * * * * * * * * * * * Coca-Cola" << endl<<endl;
	cout << "\tProduse in stoc : " << d1.getStoc()<<endl;
	cout << "\tValoarea totala a produsului " << d1.getDenumire() << " este " << k1 << " lei." << endl << endl;
	cout << "Apasa 2 pentru * * * * * * * * * * * * * * * Fanta" << endl <<endl;
	cout << "\tProduse in stoc : " << d2.getStoc() << endl;
	cout << "\tValoarea totala a produsului " << d2.getDenumire() << " este " << k2 << " lei." << endl << endl;
	cout << "Apasa 3 pentru  * * * * * * * * * * * * * * Sprite" << endl << endl;
	cout << "\tProduse in stoc : " << d3.getStoc() << endl;
	cout << "\tValoarea totala a produsului " << d3.getDenumire() << " este " << k3 << " lei." << endl << endl;
	cout << "Apasa 4 pentru * * * * * * * * * * Apa Plata Dorna" << endl << endl;
	cout << "\tProduse in stoc : " << d4.getStoc() << endl;
	cout << "\tValoarea totala a produsului " << d4.getDenumire() << " este " << k4 << " lei." << endl << endl;
	cout << "Apasa 5 pentru  * * * * * * * * Apa Minerala Dorna" << endl << endl;
	cout << "\tProduse in stoc : " << d5.getStoc() << endl;
	cout << "\tValoarea totala a produsului " << d5.getDenumire() << " este " << k5 << " lei." << endl<<endl;
	cout << "Apasa 0 pentru renuntare!" << endl << endl;
}
void vanzare(Livrare&livr, Bani&valoaref, Drink&d, Tipuri_bani&T)
{
	Tipuri_bani T1("bancnote", 10, 1, 10);
	Tipuri_bani T2("monede", 0.5, 1, 0.3);
	float pretul, diferenta, cantitatea;
	int bancnote;// = T.getValoare_banc();
	
//	cout << bancnote << endl;
	//bancnote = livr.getPret();
	float monede; //= T.getValoare_bani();
	/*monede = livr.getPret();*/

//	cout << bancnote << endl;
	if (livr.getPret() > 0 && d.getStoc() > 0)
	{
		std::cout << "Va rugam alegeti cantitatea dorita :";
		std::cin >> cantitatea;
		int scade_stoc = d.getStoc() - cantitatea;
		
		if (cantitatea > d.getStoc())
		{
			std::cout << endl << "Stoc indisponibil, puteti alege maximum " << d.getStoc() << " produse!" << endl << endl;
			return;
		}
		pretul = cantitatea*livr.getPret();
		std::cout << "Pretul total este : " << pretul << " : ";
		std::cin >> pretul;
		T.setValoare_banc(pretul);
		bancnote = T.getValoare_banc();
		monede = pretul - bancnote;
		if (bancnote > 0 && monede > 0)
		{
			std::cout << "Introduceti " << bancnote << " lei in " << T1.getTip_bani() << " : ";
			std::cin >> bancnote;
			std::cout << "Introduceti " << pretul - bancnote << " " << T2.getTip_bani();
			std::cin >> monede;
		}//astva e ifu pe care nu il ia. 
		if (pretul < cantitatea*livr.getPret())
		{
			std::cout << "Va rugam introduceti diferenta de " << cantitatea*livr.getPret() - pretul << " lei: ";
			std::cin >> diferenta;
			pretul = pretul + diferenta;
		}
		if (pretul >= cantitatea*livr.getPret())
		{
			valoaref.accept(pretul);
			std::cout << "\nSe livreaza produsul. Multumim!" << endl << endl;
			d.setStoc(scade_stoc);
			std::cout << "Produse ramase in stoc: " << d.getStoc() << endl << endl;
			if (pretul > cantitatea*livr.getPret())
				std::cout << "Se returneaza restul : " << pretul - cantitatea*livr.getPret() << " lei" << endl << endl;
		}
		else {
			std::cout << "Suma insuficienta. Se returneaza banii introdusi." << endl;
		}
	}

	else {
		std::cout << "Stoc epuizat. Ne pare rau." << endl;
	}
}

void main()
{
	
	Tipuri_bani T;
	//Tipuri_bani Tip_B2("Monede", .5, 10);
	Bani banii;
	Drink d1(1, 15, 3.5, "Coca-Cola");
	Drink d2(2, 16, 3.5, "Fanta");
	Drink d3(3, 17, 3.5, "Sprite");
	Drink d4(4, 20, 3, "Apa Plata Dorna");
	Drink d5(5, 22, 3, "Apa Minerala Dorna");
	Livrare Cola(1, 3.5);
	Livrare Fanta(1, 3.5);
	Livrare Sprite(1, 3.5);
	Livrare DornaPlata(1, 3);
	Livrare DornaMinerala(1, 3);

	int optiune;

	meniu(d1,d2,d3,d4,d5);
	cout << "Introduceti numarul produsului dorit: ";
	cin >> optiune; cout << endl;
	while (optiune != 0)
	{
		switch (optiune)
		{
		case 1:
			vanzare(Cola, banii,d1,T);
			break;
		case 2:
			vanzare(Fanta, banii, d2, T);
			break;
		case 3:
			vanzare(Sprite, banii, d3, T);
			break;
		case 4:
			vanzare(DornaPlata, banii, d4, T);
			break;
		case 5:
			vanzare(DornaMinerala, banii, d5, T);
			break;
		default:
			cout << "Selectie gresita!Va rugam alegeti numarul produsului dorit." << endl<<endl;
		}
		meniu(d1, d2, d3, d4, d5);
		cout << "Introduceti numarul produsului dorit: ";
		cin >> optiune;
	}
	_getch();
}