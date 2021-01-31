//Gerekli kütüphaneler eklendi.
#include <iostream>

#include <conio.h>

#include <fstream>

#include <string>

#include <windows.h>

#include <clocale>

#include <iomanip>

#include <stdio.h>

#include <vector>


using namespace std;

//String ve int. değerler veriliyor.
struct Urun
{
	string urunNo; //String tipinde değişken.
	string urunAdi; //String tipinde değişken.
	string urunBirimTipi; //String tipinde değişken.
	int urunBirimFiyati = 0; //Integer tipinde değişken.
	string urunMarkasi; //String tipinde değişken.
};

//String ve int. değerler veriliyor.
struct Proje
{
	string projeNo; //String tipinde değişken.
	string projeAdi; //String tipinde değişken.
	string projeYurutucuFirma; //String tipinde değişken.
	string projeSorumlusu; //String tipinde değişken.
	string projeKontroloru; //String tipinde değişken.
};

//String ve int. değerler veriliyor.
struct Hakedis
{
	string projeNo; //String tipinde değişken.
	string urunNo; //String tipinde değişken.
	int hakedisUrunAdet = 0; //Integer tipinde değişken.
	int kullanilanUrunFiyati = 0; //Integer tipinde değişken.
	int hakedisDonemi = 0; //Integer tipinde değişken.
	int toplamFiyat = 0; //Integer tipinde değişken.
};

//Dosya içindeki veriler stringe uyarlanıp ayrıştırma yapılıyor.
vector < string > split(string bilgiler, string ayrac)
{
	vector < string > bilgiListesi; //Liste oluşturuluyor.
	size_t index = 0;
	string urunBilgisi;
	while ((index = bilgiler.find(ayrac)) != string::npos)
	{
		urunBilgisi = bilgiler.substr(0, index);
		bilgiListesi.push_back(urunBilgisi);
		bilgiler.erase(0, index + ayrac.length());
	}
	bilgiListesi.push_back(bilgiler);
	return bilgiListesi;
}

//Dosya içindeki veriler satıt satır ve virgül virgül okunuyor.
vector < Urun > urunDosyasiniOku(string dosyaAdi, boolean showUrunListesi)
{

	vector < Urun > urunListesi; //Ürün listesi oluşturuluyor.

	ifstream dosyaOku(dosyaAdi);
	string satir = "";

	if (dosyaOku.is_open())
	{

		while (getline(dosyaOku, satir))
		{
			//Her bir satır virgüllerle ayrılarak okutuluyor.
			vector < string > urunBilgileriList = split(satir, ",");

			Urun urun;
			urun.urunNo = urunBilgileriList[0];
			urun.urunAdi = urunBilgileriList[1];
			urun.urunBirimTipi = urunBilgileriList[2];
			urun.urunBirimFiyati = stoi(urunBilgileriList[3]);
			urun.urunMarkasi = urunBilgileriList[4];
			urunListesi.push_back(urun);

			if (showUrunListesi)
			{
				cout << satir << endl;
			}

		}

		dosyaOku.close();
	}

	return urunListesi;
}

//Dosya içinde yapılacak değişiklikler burada güncelleniyor.
void urunListesiDosyasiniGuncelle(vector <Urun> urunListesi)
{
	ofstream dosyaYaz;
	dosyaYaz.open("urun.txt");
	for (size_t i = 0; i < urunListesi.size(); i++)
	{
		string satir = urunListesi.at(i).urunNo + "," + urunListesi.at(i).urunAdi + "," + urunListesi.at(i).urunBirimTipi + "," + to_string(urunListesi.at(i).urunBirimFiyati) + "," + urunListesi.at(i).urunMarkasi;
		dosyaYaz << satir << endl;
	}
	dosyaYaz.close();
}

//Dosya içindeki veriler satıt satır ve virgül virgül okunuyor.
vector < Proje > projeDosyasiniOku(string dosyaAdi, boolean showProjeListesi)
{
	//Her bir satır virgüllerle ayrılarak okutuluyor.
	vector < Proje > projeListesi; //Proje listesi oluşturuluyor.

	ifstream dosyaOku(dosyaAdi);
	string satir = "";

	if (dosyaOku.is_open())
	{

		while (getline(dosyaOku, satir)) {
			vector < string > projeBilgileriList = split(satir, ",");

			Proje proje;
			proje.projeNo = projeBilgileriList[0];
			proje.projeAdi = projeBilgileriList[1];
			proje.projeYurutucuFirma = projeBilgileriList[2];
			proje.projeSorumlusu = projeBilgileriList[3];
			proje.projeKontroloru = projeBilgileriList[4];
			projeListesi.push_back(proje);

			if (showProjeListesi) {
				cout << satir << endl;
			}

		}

		dosyaOku.close();
	}

	return projeListesi;
}

//Dosya içinde yapılacak değişiklikler burada güncelleniyor.
void projeListesiDosyasiniGuncelle(vector<Proje> projeListesi)
{
	ofstream dosyaYaz;
	dosyaYaz.open("projeler.txt");
	for (size_t i = 0; i < projeListesi.size(); i++)
	{
		string satir = projeListesi.at(i).projeNo + "," + projeListesi.at(i).projeAdi + "," + projeListesi.at(i).projeYurutucuFirma + "," + projeListesi.at(i).projeSorumlusu + "," + projeListesi.at(i).projeKontroloru;
		dosyaYaz << satir << endl;
	}
	dosyaYaz.close();
}

//Dosya içindeki veriler satıt satır ve virgül virgül okunuyor.
vector < Hakedis > hakedisDosyasiniOku(string dosyaAdi, boolean showHakedisListesi)
{
	//Her bir satır virgüllerle ayrılarak okutuluyor.
	vector < Hakedis > hakedisListesi; //Hakediş listesi oluşturuluyor.

	ifstream dosyaOku(dosyaAdi);
	string satir = "";

	if (dosyaOku.is_open())
	{

		while (getline(dosyaOku, satir))
		{
			vector < string > hakedisBilgileriList = split(satir, ",");

			Hakedis hakedis;
			hakedis.hakedisDonemi = stoi(hakedisBilgileriList[0]);
			hakedis.projeNo = hakedisBilgileriList[1];
			hakedis.urunNo = hakedisBilgileriList[2];
			hakedis.hakedisUrunAdet = stoi(hakedisBilgileriList[3]);
			hakedis.kullanilanUrunFiyati = stoi(hakedisBilgileriList[4]);
			hakedis.toplamFiyat = stoi(hakedisBilgileriList[5]);
			hakedisListesi.push_back(hakedis);

			if (showHakedisListesi) {
				cout << satir << endl;
			}

		}

		dosyaOku.close();
	}

	return hakedisListesi;
}

//Dosya içinde yapılacak değişiklikler burada güncelleniyor.
void hakedisListesiDosyasiniGuncelle(vector<Hakedis> hakedisListesi)
{
	ofstream dosyaYaz;
	dosyaYaz.open("hakedis-islemleri.txt");
	for (size_t i = 0; i < hakedisListesi.size(); i++)
	{
		string satir = to_string(hakedisListesi.at(i).hakedisDonemi) + "," + hakedisListesi.at(i).projeNo + "," + hakedisListesi.at(i).urunNo + "," + to_string(hakedisListesi.at(i).hakedisUrunAdet) + "," + to_string(hakedisListesi.at(i).kullanilanUrunFiyati) + "," + to_string(hakedisListesi.at(i).hakedisUrunAdet* hakedisListesi.at(i).kullanilanUrunFiyati);
		dosyaYaz << satir << endl;
	}
	dosyaYaz.close();
}

//Ana menü içeriği oluşturuluyor.
void anaMenuIcerigiGoster()
{
	cout << "HAKKEDIS PROGRAMI" << endl;
	cout << "************************************************" << endl;
	cout << "Lutfen Yapmak Istediginiz Islemi Secin" << endl;
	cout << "1- Urun Islemleri" << endl;
	cout << "2- Proje Islemleri" << endl;
	cout << "3- Hakedis Islemleri" << endl;
	cout << "9- Cikis Yap" << endl;
}

//Ürün bilgileri menü içeriği oluşturuluyor.
void urunBilgileriMenuIcerigi()
{
	cout << "Urun Islemleri" << endl;
	cout << "************************************************" << endl;
	cout << "1- Mevcut Urun Listesini Gorme" << endl;
	cout << "2- Urun Ekleme" << endl;
	cout << "3- Urun Silme" << endl;
	cout << "4- Urun Arama" << endl;
	cout << "5- Raporlama" << endl;
	cout << "9- Ana Menuye Don" << endl;
}

//Dosya açılıyor , okutuluyor ve yazdırılıyor.
void mevcutUrunListesiGorme()
{
	cout << "1- Mevcut Urun Listesini Gorme" << endl;

	ifstream dosyaOku("urun.txt");
	string satir = "";

	if (dosyaOku.is_open())
	{

		while (getline(dosyaOku, satir))
		{
			cout << satir << endl;
		}

		dosyaOku.close();
	}
}

//Dosya içerisine yeni veri girişi sağlanıyor.
void urunEkleme()
{
	cout << "2- Urun Ekleme" << endl;
	string urunBilgileri = "";
	cout << "Urun eklemek icin aralarinda bosluk olmadan virgul ile ayrilmis olacak sekilde UrunNo,UrunAdi,UrunBirimTipi,UrunBirimFiyati,UrunMarkasi seklinde giris yapin." << endl;
	cin >> urunBilgileri;

	vector < string > urunBilgileriList = split(urunBilgileri, ",");
	if (urunBilgileriList.size() == 5) //Eğer 5 farklı veri girişi yapılmassa ürün eklemesi yapılmıyor.
	{
		ofstream dosyaYaz;
		dosyaYaz.open("urun.txt", ios::app);
		dosyaYaz << urunBilgileri << endl;
		dosyaYaz.close();
	} 
	else
	{
		cout << "Hatali formatta giris yaptiniz. Lutfen tekrar deneyiniz." << endl;
	}
}

//Dosya içerisinden veri siliniyor.
void urunSilme()
{
	cout << "3- Urun Silme" << endl;
	string satir = "";
	string urunNoSilme;
	int control = 0;
	Urun urun;
	vector <Urun> urunListesi = urunDosyasiniOku("urun.txt", true);
	cout << "Silmek Istediginiz Urun Numarasini Giriniz : ";
	cin >> urunNoSilme;
	bool isUrunBulundu = false;
	for (size_t i = 0; i < urunListesi.size(); i++) {
		if (urunListesi.at(i).urunNo.compare(urunNoSilme) == 0) //Compare komutu stringlerin karşılaştırması için kullanılır.
		{
			urunListesi.erase(urunListesi.begin() + i); //Bulunan ürün satırı sildiriliyor.
			isUrunBulundu = true;
		}
	}

	if (isUrunBulundu)
	{
		urunListesiDosyasiniGuncelle(urunListesi);
		cout << endl << "Silme Islemi Basariyla Tamamlandi" << endl;
	}
	else
	{
		cout << endl << "Silinecek urun bulunamadi lutfen urun nosunu kontrol ediniz." << endl;
	}
}

//Dosya içerisinden urun araması yapılıyor. Ürün numarası veya adına göre.
void urunArama()
{
	cout << "4- Urun Arama" << endl;
	string satir = "";
	string urunNoArama;
	int secimarama;
	int control = 0;
	Urun urun;

	cout << "Nasil Arama Yapmak Istersiniz ?" << endl;
	cout << "1- Urun numarasina gore..." << endl;
	cout << "2- Urun adina gore..." << endl;
	cin >> secimarama;
	switch (secimarama)
	{
	case 1:
	{
		cout << "Aranan urunun nosunu giriniz..." << endl;
		cin >> urunNoArama;
		vector <Urun> urunListesi = urunDosyasiniOku("urun.txt", false);
		Urun bulunanUrun;
		bool isUrunBulundu = false;
		for (size_t i = 0; i < urunListesi.size(); i++)
		{
			if (urunListesi.at(i).urunNo.compare(urunNoArama) == 0)
			{
				isUrunBulundu = true;
				bulunanUrun = urunListesi.at(i);
				break;
			}
		}
		if (isUrunBulundu)
		{

			cout << bulunanUrun.urunNo << " " << bulunanUrun.urunAdi << " " << bulunanUrun.urunBirimTipi << " " << bulunanUrun.urunBirimFiyati << " " << bulunanUrun.urunMarkasi << endl;

		}
		else
		{
			cout << "Aranilan urun bulunulamadi." << endl;
		}
		break;
	}
	case 2:
	{
		cout << "Aranan urunun adini giriniz..." << endl;
		cin >> urunNoArama;
		vector <Urun> urunListesi = urunDosyasiniOku("urun.txt", false);
		Urun bulunanUrun;
		bool isUrunBulundu = false;
		for (size_t i = 0; i < urunListesi.size(); i++) {
			if (urunListesi.at(i).urunAdi.compare(urunNoArama) == 0)
			{
				isUrunBulundu = true;
				bulunanUrun = urunListesi.at(i);
				break;
			}
		}
		if (isUrunBulundu)
		{

			cout << bulunanUrun.urunNo << " " << bulunanUrun.urunAdi << " " << bulunanUrun.urunBirimTipi << " " << bulunanUrun.urunBirimFiyati << " " << bulunanUrun.urunMarkasi << endl;

		}
		else
		{
			cout << "Aranilan urun bulunulamadi." << endl;
		}
	}
	}
}

//Dosya içerisindeki ürünlerin sayısı ve toplam fiyatları yazdırılıyor.
void urunRaporlama()
{
	cout << "5- Raporlama" << endl;
	int urunsayisi = 0;
	string line;
	int urunFiyatToplam = 0;

	vector<Urun> urunListesi = urunDosyasiniOku("urun.txt", false);

	for (size_t i = 0; i < urunListesi.size(); i++)
	{
		Urun urun = urunListesi.at(i);
		urunFiyatToplam += urun.urunBirimFiyati;
	}

	cout << "Toplam Urun Fiyati: " << urunFiyatToplam << endl;
	cout << "Toplam Urun Sayisi: " << urunListesi.size() << endl;
}

//Döngü ile beraber menü içeriği oluşturuluyor.
void urunIslemleriMenu()
{
	boolean icDonguFlagUrun = true;
	int urunSecim;
	while (icDonguFlagUrun)
	{
		urunBilgileriMenuIcerigi();
		cin >> urunSecim;
		switch (urunSecim)
		{

		case 1:
		{
			mevcutUrunListesiGorme();
			break;
		}
		case 2:
		{
			urunEkleme();
			break;
		}
		case 3:
		{
			urunSilme();
			break;
		}
		case 4:
		{
			urunArama();
			break;
		}
		case 5:
		{
			urunRaporlama();
			break;
		}
		case 9:
		{
			cout << "girdi" << endl;
			icDonguFlagUrun = false;
			break;
		}
		}
	}
}

//Proje bilgileri menü içeriği oluşturuluyor.
void projeBilgileriMenuIcerigi()
{
	cout << "Proje Islemleri" << endl;
	cout << "************************************************" << endl;
	cout << "1- Mevcut Proje Listesini Gorme" << endl;
	cout << "2- Proje Ekleme" << endl;
	cout << "3- Proje Silme" << endl;
	cout << "4- Proje Arama" << endl;
	cout << "5- Raporlama" << endl;
	cout << "9- Ana Menuye Don" << endl;
}

//Dosya açılıyor , okutuluyor ve yazdırılıyor.
void mevcutProjeListesiniGorme()
{
	cout << "1- Mevcut Proje Listesini Gorme" << endl;
	ifstream dosyaOku("projeler.txt");
	string satir = "";

	if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir))
		{
			cout << satir << endl;
		}
		dosyaOku.close();
	}
}

//Dosya içerisine yeni veri girişi sağlanıyor.
void projeEkleme()
{
	cout << "2- Proje Ekleme" << endl;
	string projeBilgileri = "";
	cout << "Proje eklemek icin aralarinda bosluk olmadan virgul ile ayrilmis olacak sekilde ProjeNo,ProjeAdi,ProjeYurutucuFirma,ProjeSorumlusu,ProjeKontroloru seklinde giris yapin." << endl;
	cin >> projeBilgileri;
	vector < string > projeBilgileriList = split(projeBilgileri, ",");
	if (projeBilgileriList.size() == 5)
	{
		ofstream dosyaYaz;
		dosyaYaz.open("projeler.txt", ios::app);
		dosyaYaz << projeBilgileri << endl;
		dosyaYaz.close();
	}
	else
	{
		cout << "Hatali formatta giris yaptiniz. Lutfen tekrar deneyiniz." << endl;
	}
}

//Dosya içerisinden veri siliniyor.
void projeSilme()
{
	cout << "3- Proje Silme" << endl;
	string satir = "";
	string projeNoSilme;
	int control = 0;
	Proje proje;
	vector <Proje> projeListesi = projeDosyasiniOku("projeler.txt", true);
	cout << "Silmek Istediginiz Proje Nosu : ";
	cin >> projeNoSilme;
	bool isProjeBulundu = false;
	for (size_t i = 0; i < projeListesi.size(); i++)
	{
		if (projeListesi.at(i).projeNo.compare(projeNoSilme) == 0)
		{
			projeListesi.erase(projeListesi.begin() + i);
			isProjeBulundu = true;
		}
	}

	if (isProjeBulundu)
	{
		projeListesiDosyasiniGuncelle(projeListesi);
		cout << endl << "Silme Islemi Basariyla Tamamlandi" << endl;
	}
	else
	{
		cout << endl << "Silinecek proje bulunamadi . Lutfen proje nosunu kontrol ediniz." << endl;
	}
}

//Dosya içerisinden proje araması yapılıyor. Proje numarası veya adına göre.
void projeArama()
{
	cout << "4- Proje Arama" << endl;
	string satir = "";
	string projeNoArama;
	int secimarama;
	int control = 0;
	Proje proje;
	cout << "Nasil arama yapmak istersiniz ?" << endl;
	cout << "1- Proje numarasina gore..." << endl;
	cout << "2- Proje adina gore..." << endl;
	cin >> secimarama;
	switch (secimarama)
	{
	case 1:
	{
		cout << "Aranan projenin nosunu giriniz..." << endl;
		cin >> projeNoArama;
		vector <Proje> projeListesi = projeDosyasiniOku("projeler.txt", false);
		Proje bulunanProje;
		bool isProjeBulundu = false;
		for (size_t i = 0; i < projeListesi.size(); i++)
		{
			if (projeListesi.at(i).projeNo.compare(projeNoArama) == 0)
			{
				isProjeBulundu = true;
				bulunanProje = projeListesi.at(i);
				break;
			}
		}
		if (isProjeBulundu)
		{
			cout << bulunanProje.projeNo << " " << bulunanProje.projeAdi << " " << bulunanProje.projeYurutucuFirma << " " << bulunanProje.projeSorumlusu << " " << bulunanProje.projeKontroloru << endl;
		}
		else
		{
			cout << "Aranilan urun bulunulamadi." << endl;
		}
		break;
	}
	case 2:
	{
		cout << "Aranan projenin adini giriniz..." << endl;
		cin >> projeNoArama;
		vector <Proje> projeListesi = projeDosyasiniOku("projeler.txt", false);
		Proje bulunanProje;
		bool isProjeBulundu = false;
		for (size_t i = 0; i < projeListesi.size(); i++)
		{
			if (projeListesi.at(i).projeAdi.compare(projeNoArama) == 0)
			{
				isProjeBulundu = true;
				bulunanProje = projeListesi.at(i);
				break;
			}
		}

		if (isProjeBulundu) {
			cout << bulunanProje.projeNo << " " << bulunanProje.projeAdi << " " << bulunanProje.projeYurutucuFirma << " " << bulunanProje.projeSorumlusu << " " << bulunanProje.projeKontroloru << endl;
		}
		else
		{
			cout << "Aranilan proje bulunulamadi." << endl;
		}		
	}
	}
}

//Dosya içerisindeki projelerin sayısı yazdırılıyor.
void projeRaporlama()
{
	cout << "5- Raporlama" << endl;
	string line;
	
	vector<Proje> projeListesi = projeDosyasiniOku("projeler.txt", false);

	cout << "Toplam Urun Sayisi: " << projeListesi.size() << endl;
}

//Döngü ile beraber menü içeriği oluşturuluyor.
void projeIslemleriMenu()
{
	int projeSecim;
	boolean icDonguFlagProjeler = true;
	while (icDonguFlagProjeler) 
	{
		projeBilgileriMenuIcerigi();
		cin >> projeSecim;
		switch (projeSecim)
		{
			case 1: 
			{
				mevcutProjeListesiniGorme();
				break;
			}
			case 2: 
			{
				projeEkleme();
				break;
			}
			case 3: 
			{
				projeSilme();
				break;
			}
			case 4: 
			{
				projeArama();
				break;
			}
			case 5: 
			{
				projeRaporlama();
				break;
			}
			case 9: 
			{
				cout << "girdi" << endl;
				icDonguFlagProjeler = false;
				break;
			}
		}
	}
}

//Hakediş bilgileri menü içeriği oluşturuluyor.
void hakedisBilgileriMenuIcerigi()
{
	cout << "Hakedis Islemleri" << endl;
	cout << "************************************************" << endl;
	cout << "1- Hakedis Ekle" << endl;
	cout << "2- Urun Silme" << endl;
	cout << "3- Urun Guncelleme" << endl;
	cout << "4- Urun Arama" << endl;
	cout << "5- Urunleri Listele" << endl;
	cout << "9- Ana Menuye Don" << endl;
}

//Hakediş eklemesi yapılıyor.
void hakedisEkle()
{
	cout << "1- Hakedis Ekle" << endl;
	Proje proje;
	Urun urun;
	Hakedis hakedis;

	cout << "Hakedis eklemek icin sirasiyla Hakedis donemi,Proje numarasi,Urun numarasi,Urun adeti,Urun birim fiyati seklinde giris yapin." << endl;
	cout << "Hakedis donemini giriniz : " << endl;
	cin >> hakedis.hakedisDonemi;
	vector <Proje> projeListesi = projeDosyasiniOku("projeler.txt", true); //Buradaki true listenin yazdırılıp yazdırılmayacağını kontrol ediyor.

	string projeNo;

	cout << "Hakedis proje no giriniz : " << endl;
	cin >> projeNo;


	bool isProjeBulundu = false;
	for (size_t i = 0; i < projeListesi.size(); i++)
	{
		if (projeListesi.at(i).projeNo.compare(projeNo) == 0)
		{
			isProjeBulundu = true; //Proje , proje dosyası içinde bulunduysa true bulunmadıysa false döndürüyor.
			hakedis.projeNo = projeNo;
		}
	}

	if (!isProjeBulundu) 
	{
		cout << "Proje numarasi bulunamadi" << endl;
		
	}
	else
	{
		string hakedisUrunNo;

		vector <Urun> urunListesi = urunDosyasiniOku("urun.txt", true);
		cout << "Urun numarasini giriniz : " << endl;
		cin >> hakedisUrunNo;
		Urun hakedisBulunanUrun;

		boolean isUrunBulundu = false;
		for (size_t i = 0; i < urunListesi.size(); i++)
		{
			if (urunListesi.at(i).urunNo.compare(hakedisUrunNo) == 0)
			{
				isUrunBulundu = true;
				hakedisBulunanUrun = urunListesi.at(i);
			}
		}


		if (!isUrunBulundu) 
		{
			cout << "Aranilan urun bulunamadi." << endl;
		}
		else {
			hakedis.urunNo = hakedisBulunanUrun.urunNo;
			hakedis.kullanilanUrunFiyati = hakedisBulunanUrun.urunBirimFiyati;

			cout << "Urun adetini giriniz : " << endl;
			cin >> hakedis.hakedisUrunAdet;
			
			hakedis.toplamFiyat = hakedis.hakedisUrunAdet * hakedis.kullanilanUrunFiyati;

			ofstream dosyaYaz;
			dosyaYaz.open("hakedis-islemleri.txt", ios::app);
			dosyaYaz << hakedis.hakedisDonemi << "," << hakedis.projeNo << "," << hakedis.urunNo << "," << hakedis.hakedisUrunAdet << "," << hakedis.kullanilanUrunFiyati << "," << hakedis.toplamFiyat << endl;
			dosyaYaz.close();

			cout << "Hakedis ekleme basariyla tamamlandi." << endl;

		}
		
	}

}

//Hakediş içinden ürün silmesi yapılıyor.
void hakedisUrunSilme()
{
	string satir = "";
	string hakedisUrunAramaDonem;
	string hakedisProjeArama;
	string hakedisUrunArama;
	int control = 0;
	Hakedis hakedis;
	cout << "Hakedis donem numarasini giriniz..." << endl;
	cin >> hakedisUrunAramaDonem;
	vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
	Hakedis bulunanHakedis;
	bool isHakedisBulundu = false;

	for (size_t i = 0; i < hakedisListesi.size(); i++)
	{
		if (to_string(hakedisListesi.at(i).hakedisDonemi).compare(hakedisUrunAramaDonem) == 0)
		{
			isHakedisBulundu = true;
			bulunanHakedis = hakedisListesi.at(i);
			break;
		}
	}
	if (isHakedisBulundu)
	{
		cout << "Lutfen proje numarasini giriniz" << endl;
		cin >> hakedisProjeArama;
		vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
		Hakedis bulunanProjeHakedis;
		bool isHakedisBulundu = false;
		for (size_t i = 0; i < hakedisListesi.size(); i++)
		{
			if (hakedisListesi.at(i).projeNo.compare(hakedisProjeArama) == 0)
			{
				isHakedisBulundu = true;
				bulunanProjeHakedis = hakedisListesi.at(i);
			}

		}
		if (isHakedisBulundu)
		{
			cout << "Lutfen urun numarasini giriniz" << endl;
			cin >> hakedisUrunArama;
			vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
			Hakedis bulunanHakedis;
			bool isHakedisBulundu = false;
			for (size_t i = 0; i < hakedisListesi.size(); i++)
			{
				if (hakedisListesi.at(i).urunNo.compare(hakedisUrunArama) == 0)
				{
					hakedisListesi.erase(hakedisListesi.begin() + i);
					isHakedisBulundu = true;
				}

			}

			if (isHakedisBulundu)
			{
				hakedisListesiDosyasiniGuncelle(hakedisListesi);
				cout << endl << "Silme Islemi Basariyla Tamamlandi" << endl;
			}
			else
			{
				cout << endl << "Silinecek urun bulunamadi lutfen urun numarasini kontrol ediniz." << endl;
			}
		}
	}
}

//Hakediş içerisinden ürün adeti güncellemesi yapılıyor.
void hakedisUrunGuncelleme()
{
	string satir = "";
	string hakedisUrunAramaDonem;
	string hakedisProjeArama;
	string hakedisUrunArama;
	string yeniUrunNo;
	int control = 0;
	Hakedis hakedis;
	cout << "Hakedis donem numarasini giriniz..." << endl;
	cin >> hakedisUrunAramaDonem;
	vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
	Hakedis bulunanHakedis;
	bool isHakedisBulundu = false;

	for (size_t i = 0; i < hakedisListesi.size(); i++)
	{
		if (to_string(hakedisListesi.at(i).hakedisDonemi).compare(hakedisUrunAramaDonem) == 0)
		{
			isHakedisBulundu = true;
			bulunanHakedis = hakedisListesi.at(i);
			break;
		}
	}
	if (isHakedisBulundu)
	{
		cout << "Lutfen proje numarasini giriniz" << endl;
		cin >> hakedisProjeArama;
		vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
		Hakedis bulunanProjeHakedis;
		bool isHakedisBulundu = false;
		for (size_t i = 0; i < hakedisListesi.size(); i++)
		{
			if (hakedisListesi.at(i).projeNo.compare(hakedisProjeArama) == 0)
			{
				isHakedisBulundu = true;
				bulunanProjeHakedis = hakedisListesi.at(i);
			}

		}
		if (isHakedisBulundu)
		{
			cout << "Lutfen urun numarasini giriniz" << endl;
			cin >> hakedisUrunArama;
			vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
			Hakedis bulunanHakedis;
			bool isHakedisBulundu = false;
			for (size_t i = 0; i < hakedisListesi.size(); i++)
			{
				if (hakedisListesi.at(i).urunNo.compare(hakedisUrunArama) == 0)
				{
					bulunanHakedis = hakedisListesi.at(i);
					hakedisListesi.erase(hakedisListesi.begin() + i);
					isHakedisBulundu = true;
				}

			}

			if (isHakedisBulundu)
			{

				hakedisListesiDosyasiniGuncelle(hakedisListesi);

				int yeniHakedisAdeti = 0; //Yeni bir değişken oluşturuluyor. Bu değişken yeni adeti tutuyor ve kullanıcadan istiyoruz.
				cout << "Guncellenmek istenen urun adetini giriniz : " << endl;
				cin >> yeniHakedisAdeti;

				bulunanHakedis.hakedisUrunAdet = yeniHakedisAdeti;
				bulunanHakedis.toplamFiyat = bulunanHakedis.kullanilanUrunFiyati * bulunanHakedis.hakedisUrunAdet;


				ofstream dosyaYaz;
				dosyaYaz.open("hakedis-islemleri.txt", ios::app);
				dosyaYaz << bulunanHakedis.hakedisDonemi << "," << bulunanHakedis.projeNo << "," << bulunanHakedis.urunNo << "," << bulunanHakedis.hakedisUrunAdet << "," << bulunanHakedis.kullanilanUrunFiyati << "," << bulunanHakedis.toplamFiyat << endl;
				dosyaYaz.close();

				cout << "Hakedis guncelleme islemi basariyla tamamlandi." << endl;
				
			}
			else
			{
				cout << "Aranilan urun hakedis icinde bulunamadi." << endl;
			}
		}
	}
}

//Hakediş dosyası içerisinden var olan hakediş dönemi aratılıyor.
//Hakediş araması yapmak için ilk dönemin ikinci proje numarasının üçüncü olarakta ürün numarasının doğru girilmesi gerekli.
void hakedisUrunArama()
{
	string satir = "";
	string hakedisUrunAramaDonem;
	string hakedisProjeArama;
	string hakedisUrunArama;
	int control = 0;
	Hakedis hakedis;
	cout << "Hakedis donem numarasini giriniz..." << endl;
	cin >> hakedisUrunAramaDonem;
	vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
	Hakedis bulunanHakedis;
	bool isHakedisBulundu = false;
	
	for (size_t i = 0; i < hakedisListesi.size(); i++) 
	{
		if (to_string(hakedisListesi.at(i).hakedisDonemi).compare(hakedisUrunAramaDonem) == 0)
		{
			isHakedisBulundu = true;
			bulunanHakedis = hakedisListesi.at(i);
			break;
		}
	}
	if (isHakedisBulundu)
	{
		cout << "Lutfen proje numarasini giriniz" << endl;
		cin >> hakedisProjeArama;
		vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
		Hakedis bulunanProjeHakedis;
		bool isHakedisBulundu = false;
		for (size_t i = 0; i < hakedisListesi.size(); i++)
		{
			if (hakedisListesi.at(i).projeNo.compare(hakedisProjeArama) == 0)
			{
				isHakedisBulundu = true;
				bulunanProjeHakedis = hakedisListesi.at(i);
			}

		}
		if (isHakedisBulundu)
		{
			cout << "Lutfen urun numarasini giriniz" << endl;
			cin >> hakedisUrunArama;
			vector <Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);
			Hakedis bulunanHakedis;
			bool isHakedisBulundu = false;
			for (size_t i = 0; i < hakedisListesi.size(); i++)
			{
				if (hakedisListesi.at(i).urunNo.compare(hakedisUrunArama) == 0)
				{
					isHakedisBulundu = true;
					bulunanHakedis = hakedisListesi.at(i);
					cout << "Aranilan urun bulundu " << endl;
					cout << bulunanHakedis.hakedisDonemi << "," << bulunanHakedis.projeNo << "," << bulunanHakedis.urunNo << "," << bulunanHakedis.hakedisUrunAdet << "," << bulunanHakedis.kullanilanUrunFiyati << "," << bulunanHakedis.toplamFiyat << endl;
				}

			}
			if (!isHakedisBulundu)
			{
				cout << "Aranilan urun hakedis icinde bulunamadi." << endl;
			}
		}
	}
	
}

//Hakedişler listeleniyor.Toplam fiyat ve hakediş dosyası içerisindeki hakediş sayısı yazdırılıyor. 
void hakedisUrunListeleme()
{
	ifstream dosyaOku("hakedis-islemleri.txt");
	string satir = "";

	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			cout << satir << endl;
		}

		dosyaOku.close();
	}
	int urunsayisi = 0;
	string line;
	int urunFiyatToplam = 0;

	vector<Hakedis> hakedisListesi = hakedisDosyasiniOku("hakedis-islemleri.txt", false);

	for (size_t i = 0; i < hakedisListesi.size(); i++)
	{
		Hakedis hakedis = hakedisListesi.at(i);
		urunFiyatToplam += hakedis.toplamFiyat;
	}

	cout << "Toplam Urun Fiyati: " << urunFiyatToplam << endl;
	cout << "Toplam Urun Sayisi: " << hakedisListesi.size() << endl;
}

//Döngü ile beraber menü içeriği oluşturuluyor.
void hakedisIslemleriMenu()
{
	int hakediSecim;
	boolean icDonguFlagHakedis = true;
	while (icDonguFlagHakedis)
	{
		hakedisBilgileriMenuIcerigi();
		cin >> hakediSecim;
		switch (hakediSecim)
		{
		case 1:
		{
			hakedisEkle();
			break;
		}
		case 2:
		{
			hakedisUrunSilme();
			break;
		}
		case 3:
		{
			hakedisUrunGuncelleme();
			break;
		}
		case 4:
		{
			hakedisUrunArama();
			break;
		}
		case 5:
		{
			hakedisUrunListeleme();
			break;
		}
		case 9:
		{
			cout << "girdi" << endl;
			icDonguFlagHakedis = false;
			break;
		}
		}
	}
}

//Döngü ile beraber ana menü içeriği oluşturuluyor.
int main()
{
	//Yazı rengi değiştiriliyor.
	system("color A");

	int secim;
	boolean donguFlag = true;
	while (donguFlag) 
	{
		anaMenuIcerigiGoster();
		cin >> secim;

		switch (secim)
		{
		case 1:
		{
			urunIslemleriMenu();
			break;
		}
		case 2:
		{
			projeIslemleriMenu();
			break;
		}
		case 3:
		{
			hakedisIslemleriMenu();
			break;
		}
		case 9:
		{
			exit(0);
		}
		}
	}
}
