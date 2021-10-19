#include <iostream>
#include <cstring>

using namespace std;


struct Maillon{

	int e; // (e) --> Element
	Maillon * suivant;

};

struct Chlist{

	int nbE;
	Maillon * tete;
	Maillon * queue;
	
};

Chlist creerlistevide(){

	Chlist chl;

	chl.tete = NULL;
	chl.queue = NULL;
	chl.nbE = 0;

	return chl;
}

int cardinalite(Chlist chl){

	return chl.nbE;
}

bool estvide(Chlist chl){

	return cardinalite(chl) == 0;
}

Chlist ajouterEntete(Chlist chl, int e){

	Maillon * p;
	p = new Maillon;

	(*p).e = e;
	(*p).suivant = chl.tete;

	if(estvide(chl)){

		chl.queue = p;
	}

	chl.tete = p;
	chl.nbE = chl.nbE + 1;
	return chl;

}

void ajouterEnqueue(Chlist chl, int e){

	Maillon * p;
	p = new Maillon;

	(*p).e = e;
	(*p).suivant = NULL;

	if(estvide(chl)){

		chl.tete = p;
	}
	else
		(*chl.queue).suivant = p;

	chl.queue = p;
	chl.nbE = chl.nbE + 1;

}

void ajouerAUrang(Chlist chl, int rang, int e){

	Maillon * p;
	p = new Maillon;
	Maillon * m;
	m = new Maillon;

	if(rang <=1){

		ajouterEntete(chl, e);
	    }
		else if ( rang > cardinalite(chl)){

			ajouterEnqueue(chl, e);
		}
		else
			p = chl.tete;

		while(rang > 2){

			p = (*p).suivant;
			rang = rang - 1;

		}

		(*m).e = e;
		(*m).suivant = (*p).suivant;

		(*p).suivant = m;
		chl.nbE = chl.nbE + 1;

}

Chlist clonerChliste(Chlist chl1){

	Chlist chl2;
	Maillon * p;

	chl2 = creerlistevide();
	p = chl1.tete;

	while(! NULL){

		ajouterEnqueue(chl2, (*p).e);
		p = (*p).suivant;
	}

	return chl2;
}

Chlist supprimerENtete(Chlist chl1){
	
	Maillon * p;
	p = new Maillon;

	if(estvide(chl1)){

		throw runtime_error("Chainlist vide");
	}
	else
		chl1.tete = (*chl1.tete).suivant;

	delete p;

	chl1.nbE = chl1.nbE + 1;

	if(cardinalite(chl1) == 0){

		chl1.queue = NULL;
	}
	return chl1;
}

Chlist supprimerENqueue(Chlist chl){
	
	
	Maillon * p;
	Maillon * tempus;

	if(estvide(chl)){

		throw runtime_error("Chainlist vide");
	}
	else if(cardinalite(chl) == 1){

		delete chl.tete;
		chl.tete = NULL;
		chl.queue = NULL;
		chl.nbE = 0;
	}
	else
	{
		p = chl.queue;
		tempus = chl.tete;
	}

	while((*tempus).suivant != chl.queue){

		tempus = (*tempus).suivant;
	}

	(*tempus).suivant = NULL;
	delete (p);

	chl.nbE = chl.nbE - 1;
	chl.queue = tempus;

	return chl;
}

int main(){
	
	Chlist Liste;
	int elem;
	Liste = creerlistevide();
	cout << cardinalite(Liste) << "et" << Liste.tete << endl;
	cout << "Saisissez un nombre " << endl;
	cin >> elem;
	Liste = ajouterEntete(Liste,elem);
	cout << cardinalite(Liste) << "et" << Liste.tete << endl;
	
}
