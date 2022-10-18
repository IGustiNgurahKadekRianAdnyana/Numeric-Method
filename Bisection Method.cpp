#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

double func(double x, double n, double k[], double c){
	double sum, sum2 = 0;
	for(int i=0; i<n; i++){
		sum = 1;
		sum *= k[i];
		for(int j=n; j>i; j--){
			sum *= x;
		}
		sum2 += sum;
	}
	
	sum2 += c;
	
	return sum2;
}

int main(){
	system("cls");
	
	double n, k[50], c, bAtas, bBawah, bC, error, input_error;
	int i = 0;
	
	cout <<"Masukan n / pangkat tertinggi : ";
	cin >> n;
	for (int i=0; i<n; i++){
		cout << "Masukan koefisien (k"<< i+1 << ") dari x^" << n-i <<" : ";
		cin >> k[i];
	}
	cout << "Masukan c (konstanta) : ";
	cin >> c;
	
	cout << "Masukan Batas Bawah : ";
	cin >> bBawah;
	cout <<"Masukan Batas Atas : ";
	cin >> bAtas;
	
	cout << "Masukan nilai error yang diinginkan : ";
	cin >> input_error;
	
	if(func(bBawah,n,k,c) * func(bAtas,n,k,c) >= 0){
		cout << "\nProses dibatalkan, Anda tidak memasukan bAtas dan bBawah dengan benar sesuai teori" << endl;
		return 0;
	}
	else if (func(bBawah,n,k,c) == 0 || func(bAtas,n,k,c) == 0)
	{
		cout <<"Akar merupakan salah satu dari batas atas dan bawah" << endl;
		cout <<"Akar persamaan = " << (func(bAtas,n,k,c)==0?bAtas:bBawah) <<endl;
	}
	
	cout << "Ite\ta\t\tb\t\tf(a)\t\tf(b)\t\tc\t\tf(c)\t\terror\n" << endl;
	
	double mC;
	
	do{
		mC = bC;
		bC = (bBawah+bAtas)/2; 
		
		cout << ++i << "\t" << bBawah << "\t\t" << bAtas << "\t\t" << (func(bBawah,n,k,c)) << "\t\t" << (func(bAtas,n,k,c)) << "\t\t" << bC << "\t\t" << (func(bC,n,k,c)) << endl;
		
		if(func(bC,n,k,c) == 0){
			cout << "Akar persamaan : " << bC << endl;
		} else if ((func(bBawah,n,k,c)*func(bC,n,k,c)) > 0 ){
			bBawah = bC;
		} else {
			bAtas = bC;
		}
		
		error = fabs(bC-mC);
		
		if(i==1)
		{
			cout << "_ _ _ _" << endl;
		} else
		{
			cout << error << endl;
		}
		 
	}while (error > input_error);
	cout << "\n\nAproksimasi Akar = " << bC <<endl;
	
	return 0;
}
