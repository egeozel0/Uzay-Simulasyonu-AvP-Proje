#include <stdlib.h>
#include <stdio.h>
#include <math.h>
const char *gezegenler[] = {
    "Merkur", "Venus", "Dunya", "Mars", 
    "Jupiter", "Saturn", "Uranus", "Neptun"
};
void yukari_atis_deneyi(double *ivmeler_ptr){
    double v0;
    double hmax;
    int i;
    printf("\n--- YUKARI ATIS DENEYI ---\n");
    printf("Hava direncinin ihmal edildigi ortamda yukari atis hesabi.\n");
    printf("Lutfen cismin firlatilma hizini (m/s) giriniz: ");
    scanf("%lf", &v0);

    v0 = (v0 < 0) ? -v0 : v0;
    printf("\n%.2f m/s hizla firlatilan cismin cikabilecegi maksimum yukseklikler:\n", v0);
    printf("---------------------------------------------------\n");
    for (i = 0; i < 8; i++) {
        double g = *(ivmeler_ptr + i); 
        hmax = (v0 * v0) / (2 * g);
        printf("%-10s : %.2f m\n", gezegenler[i], hmax); 
    printf("---------------------------------------------------\n");}
}
void PEnerji_deneyi(double *ivmeler_ptr){
    double kutle;
    double h;
    double Ep;
    int i;
    printf("\n--- KUTLECEKIMSEL POTANSIYEL ENERJI DENEYI ---\n");
    printf("Cismin konumundan dolayi sahip oldugu enerjiyi hesaplamak icin;\n");

    printf("Lutfen cismin kutlesini (kg) giriniz: ");
    scanf("%lf", &kutle);
    kutle = (kutle < 0) ? -kutle : kutle;
    
    printf("Lutfen cismin bulundugu yuksekligi (m) giriniz: ");
    scanf("%lf", &h);
    h = (h < 0) ? -h : h;
    printf("\n%.2f kg kutleli ve %.2f m yukseklikteki cismin potansiyel enerjileri:\n", kutle, h);
    printf("---------------------------------------------------\n");

    for (i = 0; i < 8; i++) {

        
        Ep = kutle * (*(ivmeler_ptr + i)) * h;

        printf("%-10s : %.2f J\n", gezegenler[i], Ep);
    
    printf("---------------------------------------------------\n");
}
}
void hidrostatik_basinc_deneyi(double *ivmeler_ptr){
    double rho;
    double h;
    double P;
    int i;

    printf("\n--- HIDROSTATIK BASINC DENEYI ---\n");
    printf("Sivinin derinlige bagli uyguladigi basinci hesaplamak icin;\n");

    printf("Lutfen sivinin yogunlugunu (kg/m^3) giriniz (Orn: Su icin 1000): ");
    scanf("%lf", &rho);
    rho = (rho < 0) ? -rho : rho;

    printf("Lutfen derinligi (m) giriniz: ");
    scanf("%lf", &h);
    h = (h < 0) ? -h : h;

    printf("\n%.2f kg/m^3 yogunluklu sivinin %.2f m derinlikteki basinci:\n", rho, h);
    printf("---------------------------------------------------\n");

    for (i = 0; i < 8; i++) {
        // Formül: P = rho * g * h
        P = rho * (*(ivmeler_ptr + i)) * h;

        printf("%-10s : %.2f Pa\n", gezegenler[i], P);
    printf("---------------------------------------------------\n");
}

}

void ip_gerilmesi_deneyi(double *ivmeler_ptr){
    
    double kutle;
    double T;
    int i;
    printf("\n--- SABIT IP GERILMESI DENEYI ---\n");
    printf("Ucunda cisim asili olan ipin gerilmesini hesaplamak icin;\n");
    printf("Lutfen cismin kutlesini (kg) giriniz: ");
    scanf("%lf", &kutle);

    kutle = (kutle < 0) ? -kutle : kutle;

    printf("\n%.2f kg kutleli cismin ipe uyguladigi gerilme kuvvetleri:\n", kutle);
    printf("---------------------------------------------------\n");

        for (i = 0; i < 8; i++) {
        
        T = kutle * (*(ivmeler_ptr + i)); 

        printf("| %-10s : %.2f N\n", gezegenler[i], T);
    
    printf("---------------------------------------------------\n");
} }
void kaldirma_kuvveti_deneyi(double *ivmeler_ptr){
double rho;
double V;
double Fkaldirma;
int i;
printf("\n--- ARSIMET KALDIRMA KUVVETI DENEYI ---\n");
    printf("Sivi icindeki cisme etki eden kaldirma kuvvetini hesaplamak icin;\n");
printf("Lutfen sivinin yogunlugunu (kg/m^3) giriniz: ");
    scanf("%lf", &rho);
    
    rho = (rho < 0) ? -rho : rho;
printf("Lutfen cismin hacmini (m^3) giriniz?");
scanf("%lf",&V);
V = (V < 0) ? -V : V; 


printf("\n%.2f kg/m^3 yogunluklu sivinda %.2f m^3 batan cisme etki eden kuvvetler:\n", rho, V);
    printf("---------------------------------------------------\n"); 

    for (i = 0; i < 8; i++) {
        // Formül: Fk = rho * g * V
        Fkaldirma = rho * (*(ivmeler_ptr + i)) * V;

        printf("%-10s : %.2f N\n", gezegenler[i], Fkaldirma);
    
    printf("---------------------------------------------------\n");
}
}

void agirlik_deneyi(double *ivmeler_ptr) {
double kutle;
double agirlik;
int i;



printf("\n--- AGIRLIK DENEYI ---\n");
    printf("Lutfen cismin kutlesini (kg) giriniz: ");
    scanf("%lf", &kutle);
    kutle = (kutle < 0) ? -kutle : kutle;
    printf("\n%.2f kg kutleli bir cismin gezegenlerdeki agirligi:\n", kutle);
    printf("---------------------------------------------------\n");
for(i=0;i<8;i++){
    agirlik= kutle*(*(ivmeler_ptr+i));
    printf("| %-10s : %.2f N\n", gezegenler[i], agirlik);
    printf("---------------------------------------------------\n");
}
}
void basit_sarkac_deneyi(double *ivmeler_ptr) {
    double L;   
    double T;
    const double PI = 3.14159; 
    int i;

    printf("\n--- BASIT SARKAC PERIYODU DENEYI ---\n");
    printf("Sarkacin bir tam salinim suresini hesaplamak icin;\n");
    printf("Lutfen sarkacin ip uzunlugunu (metre) giriniz: ");
    scanf("%lf", &L);

    L = (L < 0) ? -L : L;

    printf("\n%.2f m uzunlugundaki sarkacin salinim periyotlari:\n", L);
    printf("---------------------------------------------------\n");

    for (i = 0; i < 8; i++) {
        double g = *(ivmeler_ptr + i);
        T = 2 * PI * sqrt(L / g);

        printf("%-10s : %.2f s\n", gezegenler[i], T);
    
    printf("---------------------------------------------------\n"); }
}
void serbest_dusme_deneyi(double *ivmeler_ptr){
double t;
double h;
int i;

printf("\n--- SERBEST DUSME DENEYI ---\n");
    printf("Hava direncinin ihmal edildigi ortamda serbest dusme hesabi.\n");
    printf("Lutfen dusus suresini (saniye) giriniz: ");
    scanf("%lf", &t);
    t = (t < 0) ? -t : t;
    printf("\n%.2f saniye sonunda cismin dustugu yukseklikler:\n", t);
    printf("---------------------------------------------------\n");
    for (i = 0; i < 8; i++) {
        h = 0.5 * (*(ivmeler_ptr + i)) * (t * t); 

        printf("%-10s : %.2f m\n", gezegenler[i], h);
    
    printf("---------------------------------------------------\n");
} }
void asansor_deneyi(double *ivmeler_ptr)
{
    double kutle;  
    double a;     
    double N;  
    int durum;     
    int i;

    printf("\n--- ASANSOR DENEYI ---\n");
    printf("Hissedilen agirligi hesaplamak icin");
    printf("\nLutfen asansorun icindeki cismin kutlesini (kg) giriniz: ");
    scanf("%lf", &kutle);
    kutle = (kutle < 0) ? -kutle : kutle; 

    printf("Lutfen asansorun ivmesini (m/s^2) giriniz: ");
    scanf("%lf", &a);
    a = (a < 0) ? -a : a; 

    printf("\nAsansorun Hareket Yönü Nedir?\n");
    printf("1. Yukari yonlu Hizlaniyor VEYA Asagi yonlu Yavasliyor (Agirlik Artar)\n");
    printf("2. Asagi yonlu Hizlaniyor VEYA Yukari yonlu Yavasliyor (Agirlik Azalir)\n");
    printf("Seciminiz (1 veya 2): ");
    scanf("%d", &durum);

    printf("\nAsansor ivmesi: %.2f m/s^2, Durum: %d icin sonuclar:\n", a, durum);
    printf("---------------------------------------------------\n");

    for (i = 0; i < 8; i++) {
        double g = *(ivmeler_ptr + i);
        double etkin_ivme;

        if (durum == 1) {
            etkin_ivme = g + a; 
        } else {
            etkin_ivme = g - a; 
              }

        N = kutle * etkin_ivme; 
        printf("%-10s : %.2f N\n", gezegenler[i], N);
    
    printf("---------------------------------------------------\n");
}
}
int main(){
    char bilim_insani_adi [50];
    int secim;

double yercekimivmeleri[]={
        3.70,   // Merkür
        8.87,   // Venüs
        9.80,   // Dünya
        3.71,   // Mars
        24.79,  // Jüpiter
        10.44,  // Satürn
        8.69,   // Uranüs
        11.15   // Neptün
        };
double *ivmeler_ptr = yercekimivmeleri;

printf("-------------------------\n");
printf("UZAY SIMULASYONUNA HOS GELDINIZ");
printf("-------------------------\n");
printf("Bilim Insani Ismi Gırınız :");
scanf("%s", bilim_insani_adi);

printf("\nMerhaba Sayin %s, deney ortamimiz hazirlaniyor...\n", bilim_insani_adi);

do {
        printf("\n----------------------------------------\n");
        printf("DENEY LISTESI:\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("-1. Cikis\n"); 
        printf("----------------------------------------\n");
        printf("Lutfen yapmak istediginiz deneyi seciniz: ");

        if (scanf("%d", &secim) != 1) { 
            while(getchar() != '\n')
           {} ; 
                secim = 0;
        }

else{        
        if (secim == -1) {
            printf("Program sonlandiriliyor. Iyi calismalar dileriz...\n");
            break; 
        }
        else if (secim >= 1 && secim <= 9) {
            
            printf("\nSecilen Deney: %d. deney baslatiliyor...\n", secim);
        }
        else {
            printf("\nHATALI GIRIS! Lutfen listeden bir numara seciniz.\n");
        } }
        switch (secim)
        {
        case 1:
            serbest_dusme_deneyi(ivmeler_ptr);
            break;
        case 2:
            yukari_atis_deneyi(ivmeler_ptr);
            break;
        case 3:
            agirlik_deneyi(ivmeler_ptr);
            break;
        case 4:
            PEnerji_deneyi(ivmeler_ptr);
            break;
        case 5:
            hidrostatik_basinc_deneyi(ivmeler_ptr);
            break;
        case 6:
            kaldirma_kuvveti_deneyi(ivmeler_ptr);
            break;
        case 7:
            basit_sarkac_deneyi(ivmeler_ptr);
            break;
        case 8:
            ip_gerilmesi_deneyi(ivmeler_ptr);
            break;
        case 9:
            asansor_deneyi(ivmeler_ptr);
            break;
        case -1:
            printf("Program sonlandiriliyor. Iyi calismalar dileriz...\n");
        break;
        default:
            printf("\nHATALI GIRIS! Lutfen listeden bir numara seciniz.\n");
        }
    }   
    while (secim != -1);

    return 0;
}
