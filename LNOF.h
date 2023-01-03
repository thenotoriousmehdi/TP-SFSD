#define lar 160
//machines abstraites//
typedef struct{
    int jour;
    int mois;           // structure de la date de naissance
    int annee;
    }date;

typedef struct{
    int matricule;
    char nom[30];
    char prenom[30];
    date date_de_naissance;
    date date_de_recrutement;          // structure d'un enregistrement
    int wilaya_de_naissance;
    int groupe_sanguin;
    int grade;
    int specialite; //specialite
    int etablissement_univ;//etablissemnt universitaire
    //date_recrutement
    //sexe
    int sexe;
    int dernier_diplome;
    //dernier diplome
    }Tenrg;

typedef Tenrg tab[1025];//1024

//2-structure d'un bloc
typedef struct{
    tab t;
    int nb;
    int suiv;
    }Tbloc;

//3-structure de l'entete
typedef struct{
    int num_bloc; //numero du 1er bloc du fichier
    int nb_enreg; //nombre total des enregistrement dans un bloc
    int nb_bloc; //nombre  total des blocs dans le fichier
    }Tentete;

//4-structure du fichier
typedef struct{
    FILE*f;
    Tentete entete;
    }fichg;



void Aff_entete(fichg *F,int i , int val) {
   switch (i) {
      case 1: {
         F->entete.nb_bloc = val;
         break;
      }
      case 2: {
         F->entete.nb_enreg = val;
         break;
      }
      case 3: {
         F->entete.num_bloc= val;
         break;
      }

   }
}

 // fonction pour ouvrir un fichier LObarreF
fichg *Ouvrir(char *nom_fichier, char mode) {
   fichg *F = (fichg*) malloc(sizeof(fichg));
	memset(F, 0, sizeof(fichg));
   if ((mode == 'a') || (mode == 'A')) {
      F->f = fopen(nom_fichier, "rb+");
      if (F->f != NULL) {
         rewind(F->f);
         fread(&(F->entete), sizeof(Tentete), 1, F->f);
      } else {
         perror("Fichier mal ouvert \n");
         exit(1);
      }
   } else if ((mode == 'n') || (mode == 'N')) {
      F->f = fopen(nom_fichier, "wb+");
      if (F->f != NULL) {
         Aff_entete(F, 1, 0);
         Aff_entete(F, 2, 1);
         Aff_entete(F, 3, 1);

         rewind(F->f);
         fwrite(&(F->entete), sizeof(Tentete), 1, F->f);
      } else {
         perror("Fichier mal cree \n");
         exit(1);
      }
   } else {
      perror("Format d'ouverture non disponible\n");
      exit(1);
   }
   return (F);
}

// fonction pour fermer un fichier LObarreF
void Fermer(fichg *F) {
   rewind(F->f);                                      // repositionnement en debut du fichier
   fwrite(&(F->entete), sizeof(Tentete), 1, F->f);     // eenregistrement de l'entete
   rewind(F->f);                                      // repositionnement den debut du fichier
   fclose(F->f);                                      // fermeture du fichier
   free(F);                                              // liberation du pointeur fichier
}

// procedure pour allouer un bloc dans un fichier LObarreF
void EcrireDir(fichg *F, int i, Tbloc buf) {

   fseek(F->f, sizeof(Tentete) + (i - 1) * sizeof(Tbloc), SEEK_SET);
   fwrite(&buf, sizeof(Tbloc), 1, F->f);
}

void LireDir(fichg *F, int i , Tbloc* buf) {
   fseek(F->f, sizeof(Tentete) + (i - 1) * sizeof(Tbloc), SEEK_SET);
   fread(buf, sizeof(Tbloc), 1, F->f);
   rewind(F->f);
}

int entete(fichg *fichier,int num_caract ){//retourner la cracterstique num_caract ds val

int val;
    switch(num_caract)
  {
      case 1:val=fichier->entete.nb_bloc; break;
      case 2:val=fichier->entete.nb_enreg; break;
      case 3:val=fichier->entete.num_bloc; break;
      default: printf("\n\t\t<<Le numero errone>>");
  }
  return val;
}

void alloc_bloc(fichg*fichier,char nom_fich[30],Tbloc *buf){//initialise un buffer
    int i;
    (*buf).suiv=-1;//initialiser le champs suiv à nil
    (*buf).nb=0;//initialiser le nb d'articles à 0

}
/* A conio implementation for Mingw/Dev-C++.
 *
 * Written by:
 * Hongli Lai <hongli@telekabel.nl>
 * tkorrovi <tkorrovi@altavista.net> on 2002/02/26.
 * Andrew Westcott <ajwestco@users.sourceforge.net>
 * Michal Molhanec <michal@molhanec.net>
 *
 * Offered for use in the public domain without any warranty.
 *
 */

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <windows.h>
#include <string.h>
#include "conio2.h"

#ifdef __cplusplus
extern "C" {
#endif

static int __BACKGROUND = WHITE;
static int __FOREGROUND = LIGHTGRAY;
static struct text_info __text_info = {
    1, 1,
    LIGHTGRAY + (BLACK << 4),
    LIGHTGRAY + (BLACK << 4),
    80, 25
};
static int __CONIO_TOP = 0;
static int __CONIO_LEFT = 0;

static void
__fill_text_info (void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    __CONIO_LEFT = info.srWindow.Left;
    __CONIO_TOP = info.srWindow.Top;
    __text_info.curx = info.dwCursorPosition.X - __CONIO_LEFT + 1;
    __text_info.cury = info.dwCursorPosition.Y - __CONIO_TOP  + 1;
    __text_info.attribute = info.wAttributes;
    __text_info.screenwidth  = info.srWindow.Right - info.srWindow.Left + 1;
    __text_info.screenheight = info.srWindow.Bottom - info.srWindow.Top + 1;
}

void
gettextinfo (struct text_info * info)
{
    __fill_text_info();
    *info = __text_info;
}

void
inittextinfo (void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &info);
    __text_info.normattr = info.wAttributes;
}

void
clrscr (void)
{
    DWORD written;
    int i;

    __fill_text_info();
    for (i = __CONIO_TOP; i < __CONIO_TOP + __text_info.screenheight; i++) {
      FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
        __FOREGROUND + (__BACKGROUND << 4), __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},
        &written);
      FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
        __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},
        &written);
    }
    gotoxy (1, 1);
}


void
clreol (void)
{
    COORD coord;
    DWORD written;

    __fill_text_info();
    coord.X = __CONIO_LEFT + __text_info.curx - 1;
    coord.Y = __CONIO_TOP  + __text_info.cury - 1;

    FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (__BACKGROUND << 4),
      __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    FillConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
      ' ', __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    gotoxy (__text_info.curx, __text_info.cury);
}


void
delline (void)
{
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury - 1;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 1;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#endif


    gotoxy (__text_info.curx, __text_info.cury);
}

void
insline (void)
{
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury - 1;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 2;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#endif

    gotoxy (__text_info.curx, __text_info.cury);
}

void
movetext (int left, int top, int right, int bottom, int destleft, int desttop)
{
    struct char_info * buffer;

    buffer = malloc ((right - left + 1) * (bottom - top + 1) * sizeof(struct char_info));
    gettext (left, top, right, bottom, buffer);
    puttext (destleft, desttop, destleft + right - left, desttop + bottom - top, buffer);
    free(buffer);
}

void
_conio_gettext (int left, int top, int right, int bottom,
  struct char_info * buf)
{
    int i;
    SMALL_RECT r;
    CHAR_INFO* buffer;
    COORD size;

    __fill_text_info();
    r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
      __CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
    size.X = right - left + 1;
    size.Y = bottom - top + 1;
    buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

    ReadConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
      (PCHAR_INFO) buffer, size, (COORD) {0, 0}, &r);

    for (i = 0; i < size.X * size.Y; i++)
    {
#ifdef UNICODE
        buf[i].letter = buffer[i].Char.UnicodeChar;
#else
        buf[i].letter = buffer[i].Char.AsciiChar;
#endif
        buf[i].attr = buffer[i].Attributes;
    }
    free (buffer);
}

void
puttext (int left, int top, int right, int bottom, struct char_info * buf)
{
    int i;
    SMALL_RECT r;
    CHAR_INFO* buffer;
    COORD size;

    __fill_text_info();
    r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
      __CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
    size.X = right - left + 1;
    size.Y = bottom - top + 1;
    buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

    for (i = 0; i < size.X * size.Y; i++)
    {
#ifdef UNICODE
        buffer[i].Char.UnicodeChar = buf[i].letter;
#else
        buffer[i].Char.AsciiChar = buf[i].letter;
#endif
        buffer[i].Attributes = buf[i].attr;
    }

    WriteConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
      buffer, size, (COORD) {0, 0}, &r);
    free (buffer);
}

void
gotoxy(int x, int y)
{
  COORD c;

  c.X = __CONIO_LEFT + x - 1;
  c.Y = __CONIO_TOP  + y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void
cputsxy (int x, int y, char * str)
{
    gotoxy (x, y);
    cputs (str);
}

void
putchxy (int x, int y, char ch)
{
    gotoxy (x, y);
    putch (ch);
}

void
_setcursortype (int type)
{
    CONSOLE_CURSOR_INFO Info;

    if (type == 0) {
        Info.bVisible = FALSE;
    } else {
      Info.dwSize = type;
      Info.bVisible = TRUE;
    }
    SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE),
      &Info);
}


void
textattr (int _attr)
{
    __FOREGROUND = _attr & 0xF;
    __BACKGROUND = _attr >> 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
}

void
normvideo (void)
{
    textattr (__text_info.normattr);
}

void
textbackground (int color)
{
    __BACKGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (color << 4));
}


void
textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      color + (__BACKGROUND << 4));
}


int
wherex (void)
{
    __fill_text_info();
    return __text_info.curx;
}


int
wherey (void)
{
    __fill_text_info();
    return __text_info.cury;
}

char *
getpass (const char * prompt, char * str)
{
    int maxlength = str[0];
    int length = 0;
    int ch = 0;
    int x, y;

    cputs(prompt);
    __fill_text_info();
    x = __text_info.curx;
    y = __text_info.cury;

    while (ch != '\r') {
        ch = getch();
        switch (ch) {
            case '\r' : /* enter */
                break;
            case '\b' : /* backspace */
                if (length > 0) putchxy (x + --length, y, ' ');
                gotoxy (x + length, y);
                break;
            default:
                if (length < maxlength) {
                    putchxy (x + length, y, '*');
                    str[2 + length++] = ch;
                }
        }
    }

    str[1] = length;
    str[2 + length] = '\0';
    return &str[2];
}

void
highvideo (void)
{
    if (__FOREGROUND < DARKGRAY) textcolor(__FOREGROUND + 8);
}

void
lowvideo (void)
{
    if (__FOREGROUND > LIGHTGRAY) textcolor(__FOREGROUND - 8);
}

void
delay (int ms)
{
    Sleep(ms);
}

void
switchbackground (int color)
{
    struct char_info* buffer;
    int i;

    buffer = malloc(__text_info.screenwidth * __text_info.screenheight *
      sizeof(struct char_info));
    _conio_gettext(1, 1, __text_info.screenwidth, __text_info.screenheight,
      buffer);
    for (i = 0; i < __text_info.screenwidth * __text_info.screenheight; i++) {
        unsigned short attr = buffer[i].attr & 0xF;
        buffer[i].attr = (color << 4) | attr;
    }
    puttext(1, 1, __text_info.screenwidth, __text_info.screenheight, buffer);
    free(buffer);
}

void
flashbackground (int color, int ms)
{
    struct char_info* buffer;

    buffer = malloc(__text_info.screenwidth * __text_info.screenheight *
      sizeof(struct char_info));
    _conio_gettext(1, 1, __text_info.screenwidth, __text_info.screenheight,
      buffer);
    switchbackground(color);
    delay(ms);
    puttext(1, 1, __text_info.screenwidth, __text_info.screenheight, buffer);
    free(buffer);
}

void
clearkeybuf (void)
{
    while (kbhit()) {
        getch();
    }
}

#ifdef __cplusplus
}
#endif

void Color(int couleurDuTexte,int couleurDeFond) /*Fonction d'affichage de couleurs*/
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void printf_encadre(char chaine []) /*Procédure qui permet d'afficher un texte tout en l'encadrant*/
{
    int cpt=0,i=0,j=0;
    int pgl=0;
    for(i=0;i<strlen(chaine);i++)
{           cpt++;
            if (chaine[i]=='.'){
            if (cpt>pgl){
            pgl=cpt;
            }
            cpt=0;
        }
}   printf("\n ");
    for (i=0;i<(pgl+1);i++){
        printf("_");
    }
    printf("\n|");
    for (i=0;i<(pgl+1);i++){
        printf(" ");
    }
    printf("|\n");
    cpt=0;
    printf("|");
    for(i=0;i<strlen(chaine);i++){
        printf("%c", chaine[i]);
        cpt++;
        if (chaine[i]=='.'){
                for (j=0;j<(pgl-cpt+1);j++){
                    printf(" ");
                }
                printf("|\n|");
                cpt=0;
    }
}
    for (i=0;i<(pgl+1);i++){
        printf("_");
    }
    printf("|\n");
}
void printf_centre (const char* str) /*Procédure qui permet d'imprimer un texte centré sur la console*/
{
    int n,v;
    v=(lar-strlen(str)) / 2;
    for (n = 0; n < v; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
    for (n=(v+strlen(str)); n< 166;n++){
        putchar(' ');
    }
}
void TP(int x,int y) //fonction personelle qui permet d'affiche TP SFSD dans le terminal
{
    clrscr();
   system("color f0");
   textcolor(BLUE);
   textbackground(WHITE);
    gotoxy(x,y);
    printf("\333\333\333");
    gotoxy(x+1,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+1,y+2);
        Sleep(200);

    printf("\333");
    gotoxy(x+1,y+3);
        Sleep(50);

    printf("\333");
    gotoxy(x+1,y+4);
        Sleep(50);

    printf("\333");

    ///////////////////

    Sleep(200);
    gotoxy(x+5,y);
    printf("\333\333\333\333");
    gotoxy(x+5,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+5,y+2);
    Sleep(50);
    printf("\333\333\333\333");
    gotoxy(x+5,y+3);
    Sleep(50);
    printf("\333");
    gotoxy(x+5,y+4);
    Sleep(50);
    printf("\333");
    gotoxy(x+8,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+8,y+2);
    Sleep(50);
    printf("\333");
    ///////////////////

     Sleep(200);
    gotoxy(x+15,y);
    Sleep(50);
    printf("\333\333\333");
    gotoxy(x+15,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+15,y+2);
    Sleep(50);
    printf("\333\333\333");
    gotoxy(x+15,y+3);
    Sleep(50);
    printf("  \333");
    gotoxy(x+15,y+4);
    Sleep(50);
    printf("\333\333\333");
    ////////////
    gotoxy(x+20,y);
    Sleep(50);
    printf("\333\333\333");
    gotoxy(x+20,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+20,y+2);
    Sleep(50);
    printf("\333\333\333");
    gotoxy(x+20,y+3);
    Sleep(50);
    printf("\333");
    gotoxy(x+20,y+4);
    Sleep(50);
    printf("\333");
    ////////////
    Sleep(200);
    gotoxy(x+25,y);
    Sleep(50);
    printf("\333\333\333");
    gotoxy(x+25,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+25,y+2);
    Sleep(50);
    printf("\333\333\333");
    gotoxy(x+25,y+3);
    Sleep(50);
    printf("  \333");
    gotoxy(x+25,y+4);
    Sleep(50);
    printf("\333\333\333");
    ///////////

    Sleep(500);
    gotoxy(x+30,y);
    printf("\333\333\333\333\333");
    gotoxy(x+31,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+31,y+2);
    Sleep(50);
   printf("\333");
 gotoxy(x+31,y+3);
    Sleep(50);
   printf("\333");
    gotoxy(x+34,y+1);
    Sleep(50);
    printf("\333");
    gotoxy(x+34,y+2);
    Sleep(50);

    printf("\333");

    gotoxy(x+34,y+3);
    Sleep(50);

    printf("\333");



   gotoxy(x+30,y+4);
   Sleep(50);
   printf("\333\333\333\333\333");



}
void acceuil()//fonction qui gere la page de l acceuil
{
    gotoxy(1,11);
	Color(0,15);
	printf_centre("Sujet:");
	gotoxy(1,12);
	Color(9,15);
	printf_centre("Gestion des enseignants de tous les etablissements");
	gotoxy(1,13);
    Color(9,15);
	printf_centre("universitaires algeriens");
	gotoxy(1,17);
	Color(0,15);
	Sleep(500);
	printf_centre("Realise par:");
	Sleep(500);
	gotoxy(1,18);
	Color(9,15);
	printf_centre("MAMOUNI      Mahdi");
	gotoxy(1,19);
	printf_centre("SERIR      Mouloud");
	gotoxy(1,21);
	Color(0,15);
	printf_centre("Groupe:");
	Color(9,15);
	printf_centre("                                            06");
	gotoxy(1,24);
	Color(0,15);
	Sleep(500);
	printf_centre("Encadre par:");
	Color(9,15);
	printf_centre("                                              M. KERMI Adel");
	gotoxy(1,32);
	Color(9,15);
	printf_centre("***Ecole Nationale Superieure d'Informatique***");
	gotoxy(1,34);
	Color(7,15);
	printf_centre("Annee universitaire: 2022/2023");
	printf_cadremenu(50,110,8,37,7);
	Sleep(500);
}
void printf_cadremenu(int x1, int x2, int y1,int y2,int col) //POUR LE CADRE
{
	int a,k;
	Color(1,15);
	k=x2;
	for(a=x1;a<x2;a++){
	gotoxy(a,y2);
	printf("\333\333");
	gotoxy(k,y1);
	printf("\333\333");
	k--;
	Sleep(1);
	}
	k=y2;
	for(a=y1;a<y2;a++){
	gotoxy(x1,a);
	printf("\333\333");
	gotoxy(x2,k);
	printf("\333\333");
	k--;
	Sleep(1);
	}
	Color(1,15);
}

void message_attente() /*Procédure qui affiche un message sur la console pour inviter l'utilisateur à appuyer sur une touche pour continuer*/
{

    printf("\n");
    system("pause");
    system("cls");
    Color(0,15);
    }

void printf_point(int a)
{
    Color(a,0);
    printf("\333\333");
    Color(0,15);
}

int menu()
{
   int cpt=1, x,y;
   char c=0;

   clrscr();
   system("color f0");
   textcolor(BLUE);
   textbackground(WHITE);


   printf("\n\n\t\t\t\t\t         __  __ _____ _   _ _   _   ____  ____  ___ _   _  ____ ___ ____   _    _     \n");
   printf("\t\t\t\t\t        |  \\/  | ____| \\ | | | | | |  _ \\|  _ \\|_ _| \\ | |/ ___|_ _|  _ \\ / \\  | |    \n");
   printf("\t\t\t\t\t        | |\\/| |  _| |  \\| | | | | | |_) | |_) || ||  \\| | |    | || |_) / _ \\ | |    \n");
   printf("\t\t\t\t\t        | |  | | |___| |\\  | |_| | |  __/|  _ < | || |\\  | |___ | ||  __/ ___ \\| |___ \n");
   printf("\t\t\t\t\t        |_|  |_|_____|_| \\_|\\___/  |_|   |_| \\_\\___|_| \\_|\\____|___|_| /_/   \\_\\_____|\n");
   printf("\n");
   printf("\n");
    textcolor(BLACK);
    c=1,cpt=1;
    x=70; y=18;
     printf("\n");
     Color(9,15);
     printf_cadremenu(35,140,5,50,8);
    do
      {

      textcolor(BLACK);textbackground(WHITE);

      gotoxy(x,y-4);printf("_______________________________");gotoxy(x-1,y-2);printf(" _______________________________ ");
      gotoxy(x-1,y-3);printf("|");gotoxy(x+31,y-3);printf("|");
      gotoxy(x,y-3);printf("           Insertion           ");

      gotoxy(x,y);printf("_______________________________");gotoxy(x-1,y+2);printf(" _______________________________ ");
      gotoxy(x-1,y+1);printf("|");gotoxy(x+31,y+1);printf("|");
      gotoxy(x,y+1);printf("Modification de l'etablissement");

      gotoxy(x,y+4);printf("_______________________________");gotoxy(x-1,y+6);printf(" _______________________________ ");
      gotoxy(x-1,y+5);printf("|");gotoxy(x+31,y+5);printf("|");
      gotoxy(x,y+5);printf("           Suppression          ");

      gotoxy(x,y+8);printf("_______________________________");gotoxy(x-1,y+10);printf(" _______________________________ ");
      gotoxy(x-1,y+9);printf("|");gotoxy(x+31,y+9);printf("|");
      gotoxy(x,y+9);printf("   Suppression par specialite   ");

      gotoxy(x,y+12);printf("_______________________________");gotoxy(x-1,y+14);printf(" _______________________________ ");
      gotoxy(x-1,y+13);printf("|");gotoxy(x+31,y+13);printf("|");
      gotoxy(x,y+13);printf("    Affichage par anciente      ");

      gotoxy(x,y+16);printf("_______________________________");gotoxy(x-1,y+18);printf(" _______________________________ ");
      gotoxy(x-1,y+17);printf("|");gotoxy(x+31,y+17);printf("|");
      gotoxy(x,y+17);printf("    Consultation par region    ");

      gotoxy(x,y+20);printf("_______________________________");gotoxy(x-1,y+22);printf(" _______________________________ ");
      gotoxy(x-1,y+21);printf("|");gotoxy(x+31,y+21);printf("|");
      gotoxy(x,y+21);printf("      Codage et decodage       ");

      gotoxy(x,y+24);printf("_______________________________");gotoxy(x-1,y+26);printf(" _______________________________ ");
      gotoxy(x-1,y+25);printf("|");gotoxy(x+31,y+25);printf("|");
      gotoxy(x,y+25);printf("      Affichage des blocs      ");


      if (c==80){cpt%=10;cpt++;}
      if (c==72){cpt--;if(cpt==0)cpt=10;}

      if(cpt==1)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y-4);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y-3);printf("|");gotoxy(x+20,y-3);printf("|");
          gotoxy(x-1,y-2);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y-3);printf("           Insertion            ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }
      if(cpt==2)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+1);printf("|");gotoxy(x+20,y+1);printf("|");
          gotoxy(x-1,y+2);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+1);printf("Modification de l'etablissement ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }
      if (cpt==3)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+5);printf("|");gotoxy(x+20,y+5);printf(" |");
          gotoxy(x-1,y+6);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+5);printf("           Suppression          ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }

      if (cpt==4)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y+8);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+9);printf("|");gotoxy(x+20,y+9);printf("|");
          gotoxy(x-1,y+10);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+9);printf("   Suppression par specialite   ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);

      }

      if (cpt==5)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y+12);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+13);printf("|");gotoxy(x+20,y+13);printf("|");
          gotoxy(x-1,y+14);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+13);printf("    Affichage par anciente      ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }
      if (cpt==6)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y+16);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+17);printf("|");gotoxy(x+20,y+17);printf("|");
          gotoxy(x-1,y+18);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+17);printf("    Consultation par region     ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }
      if (cpt==7)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y+20);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+21);printf("|");gotoxy(x+20,y+21);printf("|");
          gotoxy(x-1,y+22);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+21);printf("      Codage et decodage        ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }
      if (cpt==8)
      {
          textcolor(WHITE);textbackground(WHITE);
          gotoxy(x,y+24);printf("_________________________________");
          textcolor(BLUE);textbackground(BLUE);
          gotoxy(x-1,y+25);printf("|");gotoxy(x+20,y+25);printf("|");
          gotoxy(x-1,y+26);printf("_________________________________");
          textcolor(WHITE);textbackground(BLUE);
          gotoxy(x,y+25);printf("      Affichage des blocs       ");
          textcolor(BLACK);textbackground(WHITE);
          gotoxy(1,50);
      }


      c=getch();

      }while(c!=13);

      return cpt;


};
