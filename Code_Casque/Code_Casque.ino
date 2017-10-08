#include "LedControl.h" //inclusion de la bibliothèque pour gérer les leds


//définition des pins de branchement
int DIN = 8;  //données en entrée
int CS =  9;  //données d'initialisation
int CLK = 10; //horloge (16 MHz)
LedControl lc=LedControl(DIN,CLK,CS,5); //5 multiplexeurs

//Variables de réglages
unsigned int delais =100; //Délais de 100ms = 0,1sS
unsigned int delaisT=10;  //Délais de 10ms
byte intensite =0;

  ///////ENCODAGE DES CARACTERES//////////
    //minuscules
byte a[6]={0x40,0xA8,0xA8,0xA8,0xF0,0x00};
byte b[6]={0xFE,0xA0,0x90,0x90,0xE0,0x00};
byte c[6]={0x70,0x88,0x88,0x88,0x40,0x00};
byte d[6]={0x60,0x90,0x90,0xA0,0xFE,0x00};
byte e[6]={0x70,0xA8,0xA8,0xA8,0x30,0x00};
byte f[6]={0x10,0xF8,0x14,0x04,0x08,0x00};
byte g[6]={0x18,0xA4,0xA4,0xA4,0x7C,0x00};
byte h[6]={0xFE,0x10,0x08,0x08,0xF0,0x00};
byte i[6]={0x00,0x00,0xF4,0x00,0x00,0x00};
byte j[6]={0x00,0x40,0x80,0x88,0x7A,0x00};
byte k[6]={0xFE,0x20,0x50,0x88,0x00,0x00};
byte l[6]={0x00,0x82,0xFE,0x80,0x00,0x00};
byte m[6]={0xF8,0x08,0x30,0x08,0xF0,0x00};
byte n[6]={0xF8,0x10,0x08,0x08,0xF0,0x00};
byte o[6]={0x70,0x88,0x88,0x88,0x70,0x00};
byte p[6]={0xF8,0x28,0x28,0x28,0x10,0x00};
byte q[6]={0x10,0x28,0x28,0x30,0xF8,0x00};
byte r[6]={0xF8,0x10,0x08,0x08,0x10,0x00};
byte s[6]={0x90,0xA8,0xA8,0xA8,0x40,0x00};
byte t[6]={0x08,0x7C,0x88,0x80,0x40,0x00};
byte u[6]={0x78,0x80,0x80,0x40,0xF8,0x00};
byte v[6]={0x38,0x40,0x80,0x40,0x38,0x00};
byte w[6]={0x78,0x80,0x60,0x80,0x78,0x00};
byte x[6]={0x88,0x50,0x20,0x50,0x88,0x00};
byte y[6]={0x18,0xA0,0xA0,0xA0,0x78,0x00};
byte z[6]={0xC4,0xA4,0x94,0x8C,0x84,0x00};

    //majuscules
byte A[6]={0xFC,0x12,0x12,0x12,0xFC,0x00};
byte B[6]={0xFE,0x92,0x92,0x92,0x6C,0x00};
byte C[6]={0x7C,0x82,0x82,0x82,0x44,0x00};
byte D[6]={0xFE,0x82,0x82,0x44,0x38,0x00};
byte E[6]={0xFE,0x92,0x92,0x92,0x82,0x00};
byte F[6]={0xFE,0x12,0x12,0x12,0x02,0x00};
byte G[6]={0x7C,0x82,0x92,0x92,0xF4,0x00};
byte H[6]={0xFE,0x10,0x10,0x10,0xFE,0x00};
byte I[6]={0x00,0x82,0xFE,0x82,0x00,0x00};
byte J[6]={0x40,0x80,0x82,0x7E,0x02,0x00};
byte K[6]={0xFE,0x10,0x28,0x44,0x82,0x00};
byte L[6]={0xFE,0x80,0x80,0x80,0x80,0x00};
byte M[6]={0xFE,0x04,0x08,0x04,0xFE,0x00};
byte N[6]={0xFE,0x08,0x10,0x20,0xFE,0x00};
byte O[6]={0x7C,0x82,0x82,0x82,0x7C,0x00};
byte P[6]={0xFE,0x12,0x12,0x12,0x0C,0x00};
byte Q[6]={0x7C,0x82,0xA2,0x42,0xBC,0x00};
byte R[6]={0xFE,0x12,0x32,0x52,0x8C,0x00};
byte S[6]={0x8C,0x92,0x92,0x92,0x62,0x00};
byte T[6]={0x02,0x02,0xFE,0x02,0x02,0x00};
byte U[6]={0x7E,0x80,0x80,0x80,0x7E,0x00};
byte V[6]={0x3E,0x40,0x80,0x40,0x3E,0x00};
byte W[6]={0x7E,0x80,0x60,0x80,0x7E,0x00};
byte X[6]={0xC6,0x28,0x10,0x28,0xC6,0x00};
byte Y[6]={0x06,0x08,0xF0,0x08,0x06,0x00};
byte Z[6]={0xC2,0xA2,0x92,0x8A,0x86,0x00};

    //accents
byte e2[6]={0x70,0xA8,0xAC,0xAA,0x30,0x00};//é
byte e3[6]={0x70,0xAA,0xAC,0xA8,0x30,0x00};//è
byte a2[6]={0x40,0xAA,0xAC,0xA8,0xF0,0x00};//à

    //chiffres
byte zero[6]={0x7C,0x8A,0x92,0xA2,0x7C,0x00};
byte un[6]={0x00,0x84,0xFE,0x80,0x00,0x00};
byte deux[6]={0x84,0xC2,0xA2,0x92,0x8C,0x00};
byte trois[6]={0x42,0x82,0x8A,0x96,0x62,0x00};
byte quatre[6]={0x30,0x28,0x24,0xFE,0x20,0x00};
byte cinq[6]={0x4E,0x8A,0x8A,0x8A,0x72,0x00};
byte six[6]={0x78,0x94,0x92,0x92,0x60,0x00};
byte sept[6]={0x02,0x02,0xF2,0x0A,0x06,0x00};
byte huit[6]={0x6C,0x92,0x92,0x92,0x6C,0x00};
byte neuf[6]={0x0C,0x92,0x92,0x52,0x3C,0x00};

    //caractères spéciaux
byte espace[6]={0x00,0x00,0x00,0x00,0x00,0x00};
byte point[6]={0x00,0xC0,0xC0,0x00,0x00,0x00};         //.
byte exclamation[6]={0x00,0x00,0x9E,0x00,0x00,0x00};   //!
byte interrogation[6]={0x04,0x02,0xA2,0x12,0x0C,0x00}; //?
byte virgule[6]={0x00,0xA0,0x60,0x00,0x00,0x00};       //,
byte pVirgule[6]={0x00,0xAC,0x6C,0x00,0x00,0x00};      //;
byte point2[6]={0x00,0x6C,0x6C,0x00,0x00,0x00};        //:
byte crochet1[6]={0x00,0xFE,0x82,0x82,0x00,0x00};      //[
byte crochet2[6]={0x00,0x82,0x82,0xFE,0x00,0x00};      //]
byte accolade1[6]={0x00,0x10,0x6C,0x82,0x00,0x00};     //{
byte accolade2[6]={0x00,0x82,0x6C,0x10,0x00,0x00};     //}
byte parenthese1[6]={0x00,0x38,0x44,0x82,0x00,0x00};   //(
byte parenthese2[6]={0x00,0x82,0x44,0x38,0x00,0x00};   //)
byte chevron1[6]={0x10,0x28,0x44,0x82,0x00,0x00};      //<
byte chevron2[6]={0x82,0x44,0x28,0x10,0x00,0x00};      //>
byte arobase[6]={0x64,0x92,0xF2,0x82,0x7C,0x00};       //@
byte hashtag[6]={0x28,0xFE,0x28,0xFE,0x28,0x00};       //#
byte pourcent[6]={0x46,0x26,0x10,0xC8,0xC4,0x00};      //%
byte dollar[6]={0x48,0x54,0xFE,0x54,0x24,0x00};        //$
byte slash[6]={0x40,0x20,0x10,0x08,0x04,0x00};         // /
byte circonflexe[6]={0x08,0x04,0x02,0x04,0x08,0x00};   //^
byte esperluette[6]={0x6C,0x92,0xAA,0x44,0xA0,0x00};   //&
byte etoile[6]={0x28,0x10,0x7C,0x10,0x28,0x00};        //*
byte guillemet[6]={0x00,0x0E,0x00,0x0E,0x00,0x00};     //"
byte plus[6]={0x10,0x10,0x7C,0x10,0x10,0x00};          //+
byte tiret[6]={0x10,0x10,0x10,0x10,0x10,0x00};         //-
byte underscore[6]={0x80,0x80,0x80,0x80,0x80,0x00};    //_
byte egal[6]={0x28,0x28,0x28,0x28,0x28,0x00};          //=

  //////TESTS//////
//Tableau de test pour afficher tous les caractères
char testCaracteres[200]={'A','a','B','b','C','c','D','d','E','e','F','f',
'G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P',
'p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y',
'Z','z',' ','0','1','2','3','4','5','6','7','8','9','.',',',';',':','!','?',
'+','-','=','_','[',']','(',')','{','}','<','>','@','#','%','$','/','^','&',
'*','"'};

//Tests d'affichage pour vérifier chaque led et matrice
void test() {
  //Chaque led est allumée puis éteinte
  for(int ligne=0;ligne<8;ligne++) { //Boucle pour chaque ligne
    for(int col=0;col<8;col++) { //Boucle pour chaque colonne
      for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        delay(delaisT); //Délais de 10ms
        lc.setLed(adresse,ligne,col,true); //Led allumée
        delay(delaisT); //Délais de 10ms
        lc.setLed(adresse,ligne,col,false); //Led éteinte
      }
    }
  }
  //Chaque colonne est allumée puis éteinte
  for(int col=0;col<8;col++) { //Boucle pour chaque colonne
    for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        delay(delaisT); //Délais de 10ms
        lc.setColumn(adresse,col,B11111111); //Ligne allumée
        delay(delaisT); //Délais de 10ms
        lc.setColumn(adresse,col,B00000000); //Ligne éteinte
    }
  }
  //Chaque ligne est allumée puis éteinte
  for(int ligne=0;ligne<8;ligne++) { //Boucle pour chaque ligne
    for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        delay(delaisT); //Délais de 10ms
        lc.setRow(adresse,ligne,B11111111); //Colonne allumée
        delay(delaisT); //Délais de 10ms
        lc.setRow(adresse,ligne,B00000000); //Colonne éteinte
    }
  }
  //Chaque led est allumée une à une
  for(int col=0;col<8;col++) { //Boucle pour chaque colonne
    for(int ligne=0;ligne<8;ligne++) { //Boucle pour chaque ligne
      for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        delay(delaisT); //Délais de 10ms
        lc.setLed(adresse,ligne,col,true); //Led allumée
        delay(delaisT); //Délais de 10ms
      }
    }
  }
  //Intensité réduite de 15 à 0 progressivement
  for(int i=15;i>0;i--) {
    for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        lc.setIntensity(adresse,i); //Intensité appliquée
        delay(delaisT*2); //Délais de 20ms
    }
  }
  //Intensité augmentée de 0 à 15 progressivement
   for(int l=0;l<16;l++) {
    for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        lc.setIntensity(adresse,l); //Intensité appliquée
        delay(delaisT*2); //Délais de 20ms
    }
  }
  //Chaque led est éteinte une à une mais les lignes avant les colonnes
  for(int ligne=0;ligne<8;ligne++) {  //Boucle pour chaque ligne
    for(int col=0;col<8;col++) {  //Boucle pour chaque colonne
      for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        delay(delaisT); //Délais de 10ms
        lc.setLed(adresse,ligne,col,false);
        delay(delaisT); //Délais de 10ms
      }
    }
  }
}

  ///////FONCTIONS PRINCIPALES//////////
//Fonction de nettoyage des 5 matrices en instantané
void nettoyer(){
  for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
    lc.clearDisplay(adresse); //nettoyage de la matrice
  }
}

//Fonction de nettoyage des 5 matrices par balayage
void nettoyer2(){
  for(int adresse=4;adresse>-1;adresse--){ //Boucle pour chaque matrice
    for(int ligne=0;ligne<8;ligne++){ //Boucle pour chaque ligne
      lc.setRow(adresse,ligne,B00000000); //Eteindre la ligne
      delay(delais/2); //delais de 0,2s
    }
  }
}

//Affichage d'un caractère
void afficher(byte tableau [],int col,int limite){
  for(int i=0;i<6*limite;i++){ //affichage jusqu'au nombre max de caractères(un caractère=6 lignes)
    lc.setRow(0,i+col+8,tableau[i]);  //Matrice n°1 avec 8 colonnes de décalage pour commencer avant la matrice
    lc.setRow(1,i+col+16,tableau[i]); //Matrice n°2 avec 16 colonnes de décalage
    lc.setRow(2,i+col+24,tableau[i]); //Matrice n°3 avec 24 colonnes de décalage
    lc.setRow(3,i+col+32,tableau[i]); //Matrice n°4 avec 32 colonnes de décalage
    lc.setRow(4,i+col+40,tableau[i]); //Matrice n°5 avec 40 colonnes de décalage
  }
}

//Defilement d'un tableau de caractères
void defiler(byte tableau [],int limite){
  for(int i=0;i>-40-limite*6;i--){ //il faut aller jusqu'à la fin de la matrice (40 colonnes)
    afficher(tableau,i,limite); //en paramètres, le tableau, la position actuelle et la limite
    delay(delais); //delais de 0,1s
  }
}

//Fonction d'affichage par balayage
void balayage(byte tableau []){
  for(int adresse=4;adresse>-1;adresse--){ //Boucle pour chaque matrice
    for(int ligne=0;ligne<8;ligne++){ //Boucle pour chaque ligne
      lc.setRow(adresse,ligne,tableau[adresse*8+ligne]); //Affichage en fonction de la position
      delay(delais/2); //delais de 0,2s
    }
  }
}

//Fonction principale d'affichage des messages indéfinis
char input[200]="Bonjour"; //Reception des données dans ce tableau avec une limite de 200 caractères
void chaine(char tab[]){
  byte chaineCompil[1200]; //limite de 1200 colonnes pour le tableau final à afficher (6xNombre de caractères)
  unsigned int limite=200; //Initialisation de la limite des caractères à 200 au début puis réduit dans la fonction
  for(int Caractere=0;Caractere<limite;Caractere++){ //Boucle pour de chaque case du tableau "input"
    for (int Case=0;Case<6;Case++){ //Boucle pour chaque case du tableau "chaineCompil"
    switch (tab[Caractere]){ //Detection du caractère
        case '\0': //"\0" signifie fin de chaine de caractère, on trouve donc la limite
            limite=Caractere; //On définit donc la limite en fonction du nombre dans la boucle
            Case=6; //Et on termine la boucle
            break;
        case 'a':
            chaineCompil[Caractere*6+Case]=a[Case]; break;
        case 'b':
            chaineCompil[Caractere*6+Case]=b[Case]; break;
        case 'c':
            chaineCompil[Caractere*6+Case]=c[Case]; break;
        case 'd':
            chaineCompil[Caractere*6+Case]=d[Case]; break;
        case 'e':
            chaineCompil[Caractere*6+Case]=e[Case]; break;
        case 'f':
            chaineCompil[Caractere*6+Case]=f[Case]; break;
        case 'g':
            chaineCompil[Caractere*6+Case]=g[Case]; break;
        case 'h':
            chaineCompil[Caractere*6+Case]=h[Case]; break;
        case 'i':
            chaineCompil[Caractere*6+Case]=i[Case]; break;
        case 'j':
            chaineCompil[Caractere*6+Case]=j[Case]; break;
        case 'k':
            chaineCompil[Caractere*6+Case]=k[Case]; break;
        case 'l':
            chaineCompil[Caractere*6+Case]=l[Case]; break;
        case 'm':
            chaineCompil[Caractere*6+Case]=m[Case]; break;
        case 'n':
            chaineCompil[Caractere*6+Case]=n[Case]; break;
        case 'o':
            chaineCompil[Caractere*6+Case]=o[Case]; break;
        case 'p':
            chaineCompil[Caractere*6+Case]=p[Case]; break;
        case 'q':
            chaineCompil[Caractere*6+Case]=q[Case]; break;
        case 'r':
            chaineCompil[Caractere*6+Case]=r[Case]; break;
        case 's':
            chaineCompil[Caractere*6+Case]=s[Case]; break;
        case 't':
            chaineCompil[Caractere*6+Case]=t[Case]; break;
        case 'u':
            chaineCompil[Caractere*6+Case]=u[Case]; break;
        case 'v':
            chaineCompil[Caractere*6+Case]=v[Case]; break;
        case 'w':
            chaineCompil[Caractere*6+Case]=w[Case]; break;
        case 'x':
            chaineCompil[Caractere*6+Case]=x[Case]; break;
        case 'y':
            chaineCompil[Caractere*6+Case]=y[Case]; break;
        case 'z':
            chaineCompil[Caractere*6+Case]=z[Case]; break;
        case 'A':
            chaineCompil[Caractere*6+Case]=A[Case]; break;
        case 'B':
            chaineCompil[Caractere*6+Case]=B[Case]; break;
        case 'C':
            chaineCompil[Caractere*6+Case]=C[Case]; break;
        case 'D':
            chaineCompil[Caractere*6+Case]=D[Case]; break;
        case 'E':
            chaineCompil[Caractere*6+Case]=E[Case]; break;
        case 'F':
            chaineCompil[Caractere*6+Case]=F[Case]; break;
        case 'G':
            chaineCompil[Caractere*6+Case]=G[Case]; break;
        case 'H':
            chaineCompil[Caractere*6+Case]=H[Case]; break;
        case 'I':
            chaineCompil[Caractere*6+Case]=I[Case]; break;
        case 'J':
            chaineCompil[Caractere*6+Case]=J[Case]; break;
        case 'K':
            chaineCompil[Caractere*6+Case]=K[Case]; break;
        case 'L':
            chaineCompil[Caractere*6+Case]=L[Case]; break;
        case 'M':
            chaineCompil[Caractere*6+Case]=M[Case]; break;
        case 'N':
            chaineCompil[Caractere*6+Case]=N[Case]; break;
        case 'O':
            chaineCompil[Caractere*6+Case]=O[Case]; break;
        case 'P':
            chaineCompil[Caractere*6+Case]=P[Case]; break;
        case 'Q':
            chaineCompil[Caractere*6+Case]=Q[Case]; break;
        case 'R':
            chaineCompil[Caractere*6+Case]=R[Case]; break;
        case 'S':
            chaineCompil[Caractere*6+Case]=S[Case]; break;
        case 'T':
            chaineCompil[Caractere*6+Case]=T[Case]; break;
        case 'U':
            chaineCompil[Caractere*6+Case]=U[Case]; break;
        case 'V':
            chaineCompil[Caractere*6+Case]=V[Case]; break;
        case 'W':
            chaineCompil[Caractere*6+Case]=W[Case]; break;
        case 'X':
            chaineCompil[Caractere*6+Case]=X[Case]; break;
        case 'Y':
            chaineCompil[Caractere*6+Case]=Y[Case]; break;
        case 'Z':
            chaineCompil[Caractere*6+Case]=Z[Case]; break;
        case ' ':
            chaineCompil[Caractere*6+Case]=espace[Case]; break;
        case '.':
            chaineCompil[Caractere*6+Case]=point[Case]; break;
        case ',':
            chaineCompil[Caractere*6+Case]=virgule[Case]; break;
        case ';':
            chaineCompil[Caractere*6+Case]=pVirgule[Case]; break;
        case ':':
            chaineCompil[Caractere*6+Case]=point2[Case]; break;
        case '!':
            chaineCompil[Caractere*6+Case]=exclamation[Case]; break;
        case '?':
            chaineCompil[Caractere*6+Case]=interrogation[Case]; break;
        case '+':
            chaineCompil[Caractere*6+Case]=plus[Case]; break;
        case '-':
            chaineCompil[Caractere*6+Case]=tiret[Case]; break;
        case '=':
            chaineCompil[Caractere*6+Case]=egal[Case]; break;
        case '_':
            chaineCompil[Caractere*6+Case]=underscore[Case]; break;
        case '[':
            chaineCompil[Caractere*6+Case]=crochet1[Case]; break;
        case ']':
            chaineCompil[Caractere*6+Case]=crochet2[Case]; break;
        case '(':
            chaineCompil[Caractere*6+Case]=parenthese1[Case]; break;
        case ')':
            chaineCompil[Caractere*6+Case]=parenthese2[Case]; break;
        case '{':
            chaineCompil[Caractere*6+Case]=accolade1[Case]; break;
        case '}':
            chaineCompil[Caractere*6+Case]=accolade2[Case]; break;
        case '<':
            chaineCompil[Caractere*6+Case]=chevron1[Case]; break;
        case '>':
            chaineCompil[Caractere*6+Case]=chevron2[Case]; break;
        case '@':
            chaineCompil[Caractere*6+Case]=arobase[Case]; break;
        case '#':
            chaineCompil[Caractere*6+Case]=hashtag[Case]; break;
        case '%':
            chaineCompil[Caractere*6+Case]=pourcent[Case]; break;
        case '$':
            chaineCompil[Caractere*6+Case]=dollar[Case]; break;
        case '/':
            chaineCompil[Caractere*6+Case]=slash[Case]; break;
        case '^':
            chaineCompil[Caractere*6+Case]=circonflexe[Case]; break;
        case '&':
            chaineCompil[Caractere*6+Case]=esperluette[Case]; break;
        case '*':
            chaineCompil[Caractere*6+Case]=etoile[Case]; break;
        case '"':
            chaineCompil[Caractere*6+Case]=guillemet[Case]; break;
        case '0':
            chaineCompil[Caractere*6+Case]=zero[Case]; break;
        case '1':
            chaineCompil[Caractere*6+Case]=un[Case]; break;
        case '2':
            chaineCompil[Caractere*6+Case]=deux[Case]; break;
        case '3':
            chaineCompil[Caractere*6+Case]=trois[Case]; break;
        case '4':
            chaineCompil[Caractere*6+Case]=quatre[Case]; break;
        case '5':
            chaineCompil[Caractere*6+Case]=cinq[Case]; break;
        case '6':
            chaineCompil[Caractere*6+Case]=six[Case]; break;
        case '7':
            chaineCompil[Caractere*6+Case]=sept[Case]; break;
        case '8':
            chaineCompil[Caractere*6+Case]=huit[Case]; break;
        case '9':
            chaineCompil[Caractere*6+Case]=neuf[Case]; break;
        default:
            chaineCompil[Caractere*6+Case]=espace[Case]; break;
      }
    }
  }
  defiler(chaineCompil,limite); // on affiche ensuite le tableau compilé "chaineCompil" avec comme paramètre la limite
}

  ///////ANIMATIONS/////////
//Fonction secondaire du volume: affichage des niveaux du volume
void volumeAff(int adresse, int l, int donnee){ //réglages: adresse, ligne, donnée
  lc.setRow(adresse,l*4,donnee); //affichage sur la première ligne
  lc.setRow(adresse,l*4+1,donnee); //affichage sur la deuxième ligne
  lc.setRow(adresse,l*4+2,donnee); //affichage sur la troisième ligne
}

//Fonction principale du volume
long int vol[10]={random(0,9),random(0,9),random(0,9),random(0,9),random(0,9),random(0,9),
random(0,9),random(0,9),random(0,9),random(0,9)};//Initialisation des 10 barres de volume aléatoirement
void volume(){
  int r; //Création variable de contrôle
  for(int i=0;i<300;i++){ //Répétition de l'animation 300 fois
    for(int l=0;l<2;l++){ //Chaque matrice possède deux barres
      for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
        //Changement aleatoire du niveau de la barre
        r=random(0,2); //Aléatoire entre 0 inclus et 2 exclus
        if(r==0&&vol[adresse*2+l]>0){ //Si r=0 et le niveau n'est pas >0 alors:
          vol[adresse*2+l]-=1; //On baisse le niveau d'un
        }
        else if(r==1&&vol[adresse*2+l]<8){ //Si r=1 et le niveau n'est pas <8 alors:
          vol[adresse*2+l]+=1;//On augmente le niveau d'un
        }
          
        //Affichage du niveau en fonction de la valeur
        if(vol[adresse*2+l]==0){
          volumeAff(adresse,l,B00000000);
        }
        else if(vol[adresse*2+l]==1){
          volumeAff(adresse,l,B10000000);
        }
        else if(vol[adresse*2+l]==2){
          volumeAff(adresse,l,B11000000);
        }
        else if(vol[adresse*2+l]==3){
          volumeAff(adresse,l,B11100000);
        }
        else if(vol[adresse*2+l]==4){
          volumeAff(adresse,l,B11110000);
        }
        else if(vol[adresse*2+l]==5){
          volumeAff(adresse,l,B11111000);
        }
        else if(vol[adresse*2+l]==6){
          volumeAff(adresse,l,B11111100);
        }
        else if(vol[adresse*2+l]==7){
          volumeAff(adresse,l,B11111110);
        }
        else if(vol[adresse*2+l]==8){
          volumeAff(adresse,l,B11111111);
        }
      }
    }
    delay(delaisT); //Délais de 10ms
  }
}

//Fonction d'affichage aléatoire de pixels
void aleatoire(){
  for(int i=0;i<3000;i++){ //Répétition de l'animation 3000 fois
  lc.setLed(random(0,5),random(0,8),random(0,8),true); //Sélection aléatoire d'un pixel pour l'allumer
  lc.setLed(random(0,5),random(0,8),random(0,8),false); //Sélection aléatoire d'un pixel pour l'éteindre
  }
}


//Fonction secondaire d'affichage des flèches: image par image
byte fl1[8]={0x3C,0x66,0xC3,0x99,0x3C,0x66,0xC3,0x99};//image 1 fleche1
byte fl2[8]={0x66,0xC3,0x99,0x3C,0x66,0xC3,0x99,0x3C};//image 2 fleche1
byte fl3[8]={0xC3,0x99,0x3C,0x66,0xC3,0x99,0x3C,0x66};//image 3 fleche1
byte fl4[8]={0x99,0x3C,0x66,0xC3,0x99,0x3C,0x66,0xC3};//image 4 fleche1
byte fl5[8]={0x99,0xC3,0x66,0x3C,0x99,0xC3,0x66,0x3C};//image 1 fleche2
byte fl6[8]={0x3C,0x99,0xC3,0x66,0x3C,0x99,0xC3,0x66};//image 2 fleche2
byte fl7[8]={0x66,0x3C,0x99,0xC3,0x66,0x3C,0x99,0xC3};//image 3 fleche2
byte fl8[8]={0xC3,0x66,0x3C,0x99,0xC3,0x66,0x3C,0x99};//image 4 fleche2
void flecheAff(byte caractere []){
  for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
    for(int ligne=0;ligne<8;ligne++) //Boucle pour chaque ligne
    {
      lc.setRow(adresse,ligne,caractere[ligne]);
    }
  }
  delay(delaisT*2); //Délais de 20ms
}

//Fonction principale d'affichage des flèches vers la gauche
void fleche1(){
  for(int i=0;i<30;i++){ //Répétition de l'animation 30 fois
    flecheAff(fl1); //image 1
    flecheAff(fl2); //image 2
    flecheAff(fl3); //image 3
    flecheAff(fl4); //image 4
  }
}

//Fonction principale d'affichage des flèches vers la droite
void fleche2(){
  for(int i=0;i<30;i++){ //Répétition de l'animation 30 fois
    flecheAff(fl5); //image 1
    flecheAff(fl6); //image 2
    flecheAff(fl7); //image 3
    flecheAff(fl8); //image 4
  }
}

//Fonction d'affichage du clignement des yeux
byte oeil_o[40]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x3C,0x66,0x66,0x66,0x66,0x3C,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x3C,0x66,0x66,0x66,0x66,0x3C,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte oeil_f[40]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte oeil_c[40]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x3C,0x66,0x66,0x66,0x66,0x3C,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
void yeux (){
  afficher(oeil_o,-40,10); delay(delais*5); //affichage des yeux ouverts
  afficher(oeil_f,-40,10); delay(delais*5); //affichage des yeux fermés
  afficher(oeil_o,-40,10); delay(delais*5); //affichage des yeux ouverts
  afficher(oeil_c,-40,10); delay(delais*5); //affichage du clin d'oeil
  afficher(oeil_o,-40,10); delay(delais*5); //affichage des yeux ouverts
}

//Fonction d'affichage de toutes les animations
char daft[10]="DAFT PUNK"; //Message "daft punk"
byte human[40]={0x00,0x00,0x00,0x00,0x00,0xFE,0x10,0x10, //Message "human"
0x10,0xFE,0x00,0x7E,0x80,0x80,0x80,0x7E,
0x00,0xFE,0x04,0x08,0x04,0xFE,0x00,0xFC,
0x12,0x12,0x12,0xFC,0x00,0xFE,0x08,0x10,
0x20,0xFE,0x00,0x00,0x00,0x00,0x00,0x00};
byte robot[40]={0x00,0x00,0x00,0x00,0x00,0xFE,0x12,0x22, //Message "robot"
0x52,0x8C,0x00,0x7C,0x82,0x82,0x82,0x7C,
0x00,0xFE,0x92,0x92,0x92,0x6C,0x00,0x7C,
0x82,0x82,0x82,0x7C,0x00,0x02,0x02,0xFE,
0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00};
byte tension[40]={0x0C,0x08,0x08,0x08,0x08,0x08,0x08,0x08, //image tension
0x08,0x18,0x30,0x60,0x30,0x18,0x0C,0x06,
0x60,0x30,0x18,0x0C,0x06,0x0C,0x08,0x08,
0x0C,0x06,0x0C,0x08,0x08,0x08,0x18,0x30,
0x08,0x08,0x08,0x18,0x30,0x60,0x30,0x18};
void animations(){
  int anim=random(0,9); //Variable de sélection aléatoire
  switch (anim) //Sélection en fonction de "anim"
      {
        case 0:
            Serial.println("Animation: Fleches vers la gauche");
            fleche1(); nettoyer(); break;
        case 1:
            Serial.println("Animation: Fleches vers la droite");
            fleche2(); nettoyer(); break;
        case 2:
            Serial.println("Animation: Volume");
            volume(); nettoyer(); break;
        case 3:
            Serial.println("Animation: Affichage aleatoire");
            aleatoire(); nettoyer(); break;
        case 4:
            Serial.println("Message: DAFT PUNK");
            chaine(daft); nettoyer(); break;
        case 5:
            Serial.println("Message: HUMAN");
            afficher(human,-40,10); delay(delais*30); nettoyer(); break;
        case 6:
            Serial.println("Message: ROBOT");
            afficher(robot,-40,10); delay(delais*30); nettoyer(); break;
        case 7:
            Serial.println("Animation: Rythme cardiaque");
            balayage(tension); nettoyer2(); break;
        case 8:
            Serial.println("Animation: Clignement des yeux");
            yeux (); nettoyer(); break;
      }
}

  /*******INITIALISATION*******/
//Fonction d'initialisation 
void setup() {
  //initialisation de toutes les matrices dans une boucle
  for(int adresse=0;adresse<5;adresse++) { //Boucle pour chaque matrice
    lc.shutdown(adresse,false); //Le MAX7219 est en mode économie d'énergie au démarrage
    lc.setIntensity(adresse,intensite); //Réglage de l'intensité
    lc.clearDisplay(adresse); //Nettoyer l'affichage
  }
  Serial.begin(9600);
  Serial.println("Connexion etablie avec la matrice.");
  chaine(input);
}

//Fonction Générale qui tourne en boucle
void loop() {
  int donneesALire = Serial.available(); //lecture du nombre de caractères disponibles dans le buffer
  if(donneesALire > 0){ //si le buffer n'est pas vide
    for(int i=0;i<200;i++){ //Nettoyage ddu tableau d'entrée
      input[i] = B00000000; //Chaque case est remplacée par un octet rempli de zeros
    }
    for(int i=0;i<donneesALire;i++){
      input[i] = Serial.read();
    }
    Serial.print("Donnees recues");
    chaine(input);
    Serial.println(" - Donnees affichees");
  }
  else{ //S'il n'y a pas de données à afficher, une animation est choisie
    Serial.println("Aucunes donnees a afficher");
  animations();
  }
}

