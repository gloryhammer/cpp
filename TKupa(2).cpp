#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

class TGeometrijskoTijelo{
	protected:		//privatni clanovi koji se mogu naslijediti
		float r, h; //h->visina trougla
		float H;    //visina piramide
	public:
		TGeometrijskoTijelo(){r=0;brojac++;}          //konstruktor 
		TGeometrijskoTijelo(float t){r=t;brojac++;}   //konstruktor
		~TGeometrijskoTijelo(){brojac--;}             //destruktor
		
		static int brojac;
		
		void setR(float t){r=t;}
		void setH(float t){h=t*sqrt(3)/2;}
		float getR(){return r;}
		float getH(){return h;}
		
		virtual float Povrsina()=0;    //ciste virtuelne funkcije clanice koje cine klasu apstraktnom
		virtual float Zapremina()=0;   // i zahtijevaju svoju definiciju u svakoj izvedenoj klasi
};
int TGeometrijskoTijelo::brojac=0;

class TKupa:public TGeometrijskoTijelo{
	public:
		TKupa(){};
		TKupa(float t){r=t; h=t*sqrt(3)/2;}
		~TKupa(){}
	
		float Povrsina(){
			return(4*(r*r*sqrt(3)/4));
		}
		float Zapremina(){
			return(((h*r)/2) * (sqrt((r*r)-(4/9)*(h*h))));
		}
};

int main(){
	
	TGeometrijskoTijelo* ptr=new TKupa();
	ptr->setH(6);
	ptr->setR(6);
	
	cout<<"Dimenzije piramide su: "<<ptr->getR()<<" i "<<ptr->getH()<<"."<<endl;
	cout<<"Povrsina i zapremina su: "<<ptr->Povrsina()<<" i "<<ptr->Zapremina()<<"."<<endl;
	cout<<"Broj objekata je: "<<ptr->brojac<<"."<<endl;
	return 0;
		
	
}

