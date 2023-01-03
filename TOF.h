//implementation du fichier d'index------------------------------------------//
 typedef struct{
 int cle;
 int num_bloc;
 int num_enreg;
 int efface;
 }TENREG;
 typedef TENREG TAB[1025];
 typedef struct{
 TAB t;
 int nb;
 }BUFFER;
 typedef struct{
 int NB_BLOC;
 int NB_ENREG;
 }TENTETE;
 typedef struct{
 FILE*fichier;
 TENTETE ENTETE;
 }TOF;

void Affentete(TOF *F,int i , int val) {
   switch (i) {
      case 1: {
         F->ENTETE.NB_BLOC = val;
         break;
      }
      case 2: {
         F->ENTETE.NB_ENREG= val;
         break;
      }



   }
}


 // fonction pour ouvrir un fichier LObarreF
TOF *ouvrir(char *nom_fichier, char mode) {
   TOF*F = (TOF*) malloc(sizeof(TOF));
	memset(F, 0, sizeof(TOF));
   if ((mode == 'a') || (mode == 'A')) {
      F->fichier = fopen(nom_fichier, "rb+");
      if (F->fichier != NULL) {
         rewind(F->fichier);
         fread(&(F->ENTETE), sizeof(TENTETE), 1, F->fichier);
      } else {
         perror("Fichier mal ouvert \n");
         exit(1);
      }
   } else if ((mode == 'n') || (mode == 'N')) {
      F->fichier = fopen(nom_fichier, "wb+");
      if (F->fichier != NULL) {
         Aff_entete(F, 1, 0);
         Aff_entete(F, 2, 1);
         Aff_entete(F, 3, 1);

         rewind(F->fichier);
         fwrite(&(F->ENTETE), sizeof(TENTETE), 1, F->fichier);
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
void fermer(TOF *F) {
   rewind(F->fichier);                                      // repositionnement en debut du fichier
   fwrite(&(F->ENTETE), sizeof(TENTETE), 1, F->fichier);     // eenregistrement de l'entete
   rewind(F->fichier);                                      // repositionnement den debut du fichier
   fclose(F->fichier);                                      // fermeture du fichier
   free(F);                                              // liberation du pointeur fichier
}

// procedure pour allouer un bloc dans un fichier LObarreF
void ecriredir(TOF *F, int i, BUFFER buf) {
   fseek(F->fichier, sizeof(TENTETE) + (i - 1) * sizeof(BUFFER), SEEK_SET);
   fwrite(&buf, sizeof(BUFFER), 1, F->fichier);
}
void liredir(TOF *F, int i , BUFFER* buf) {
   fseek(F->fichier, sizeof(TENTETE) + (i - 1) * sizeof(BUFFER), SEEK_SET);
   fread(buf, sizeof(BUFFER), 1, F->fichier);
	rewind(F->fichier);
}

int Entete(TOF *fichier,int num_caract )//retourner la cracterstique num_caract ds val
{int val;
    switch(num_caract)
  {
      case 1:val=fichier->ENTETE.NB_BLOC; break;
      case 2:val=fichier->ENTETE.NB_ENREG; break;
      //case 3:val=fichier->entete.num_bloc; break;
      default: printf("\n\t\t<<Le numero errone>>");
  }
  return val;
}
