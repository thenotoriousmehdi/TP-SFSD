//implementation de la structure----------------------------------
//les table en MC pour l'affichege
char *Wilaya_Naissance[59] = {" ","Adrar", "Chlef", "Laghouat", "Oum El Bouaghi", "Batna", "Bejaia", "Biskra", "Bechar",
                            "Blida", "Bouira", "Tamanrasset", "Tebessa", "Tlemcen", "Tiaret", "Tizi Ouzou", "Alger",
                            "Djelfa", "Jijel", "Setif", "Saida", "Skikda", "Sidi Bel Abbes", "Annaba", "Guelma", "Constantine",
                            "Medea", "M'Sila", "Mostaganem", "Masacra", "Ouargla", "Oran", "El Bayadh", "Illizi", "Bordj Bou Arreridj",
                            "Boumerdes", "El Tarf", "Tindouf", "Tissemesilt", "El Oued", "Khenchela", "Souk Ahras", "Tipaza", "Mila",
                            "Ain Defla", "Naama", "Ain Timouchent", "Ghardaia", "Relizane", "Timimoun", "Bordj Badji Mokhtar",
                            "Ouled Djellal", "Beni Abbes", "In Salah", "In Guezzam", "Touggourt", "Djanet", "M'Ghair", "El Meniaa"};

char *Groupe_Sanguin[9] = {" ","O+", "A+", "B+", "O-", "A-", "AB+", "B-", "AB-"};

char *Grade[7] = {" ","Professeur", "MCR A", "MCR B", "MAR A", "MAR B", "Assistant"};

char *Specialite[42] = {" ","Arts", "Arts du spectale","ARTS PLASTIQUES", "HISTOIRE DE L ART ET ARCHEOLOGIE", "MUSICOLOGIE",
"ADMINISTRATION PUBLIQUE","DROIT", "SCIENCE POLITIQUE", "AES", "ECONOMIE","GESTION", "LETTRES", "LANGUES",
"SCIENCES DU LANGAGE", "CHIMIE", "ELECTRONIQUE", "ENERGIE ELECTRIQUE", "AUTOMATIQUE", "GENIE CIVIL", "INFORMATIQUE",
"MATHEMATIQUES", "MECANIQUE", "MIASHS", "PHYSIQUE", "SCIENCES DE LA TERRE","SCIENCES DE LA VIE", "SCIENCES ET TECHNOLOGIES",
"SCIENCES POUR L INGENIEUR", "SCIENCES POUR LA SANTE", "STAPS", "GEOGRAPHIE ET AMENAGEMENT", "HISTOIRE",
"INFORMATION ET COMMUNICATION", "PHILOSOPHIE","PSYCHOLOGIE", "SCIENCES DE L EDUCATION", "SOCIOLOGIE",
"MEDECINE", "PHARMACIE", "CHIRURGIE", "DENTAIRE"};//specialite
char *Sexe[3] = {" ","Masculin","Feminin"};
char *Dernier_Diplome[7]={" ","Doctorat d'etat","Doctorat en sciences","Doctorat D-LMD","PHD","Habilitation Universitaire","Magistere"};

char *Etab_Univ[113]={" ", "univ_bechar",  "univ_mascara",  "univ_saida", "univ_tlemcen",  "univ_adrar",
"univ-tiaret",  "univ-sba", "univ-mosta", "univ-oran1", "USTO", "univ-oran2",
"univ-chlef", "univ-tissemsilt",  "univ-temouchent",  "univ-relizane", "ENP_Oran", "ESI_Sba",
"ESE_Oran",  "ESGEE_Oran", "ENS_Oran",  "ENS_Bechar", "ENS_Mostaganem", "ESA_Mostaganem",  "ESSB_Oran",
"ESM_Tlemcen", "ESSA_Telemcen","cuniv_naama", "cuniv_elbayadh", "cuniv_tindouf", "cuniv_maghnia",
"univ-bouira", "univ-djelfa", "lagh-univ", "univ-ghardaia", "univ-dbkm", "univ-medea",
 "USTHB", "univ-bejaia", "umbb", "ummto", "univ_blida1", "univ_blida2", "univ_alger1",
 "univ-alger2", "univ-alger3", "UFC", "univ-tam", "cuniv_tipaza", "cuniv_illizi", "cuniv_aflou",
 "ENP_Alger", "ENSH_Alger", "ENSTP_Alger", "ENSV_Alger", "EPAU_Alger", "ENSA_Alger", "HEC_Kolea", "ESI_Alger",
 "ENSSEA_Alger", "ESC_Alger" , "ENSSMAL_Alger", "ENSM_Kolea", "ENST_Alger", "ENSJSI_Alger", "ENSSP_Alger",
 "ESSAIA_ Alger", "ESSA_Alger", "ESGEN_Alger", "ESTIN_Bejaia", "ENSM_Alger", "ENSIA_Alger", "ENS_Kouba" ,
 "ENSSM_Alger", "ENS_Laghouat", "ENS_Bouzareah", "univ_jijel", "univ_tebessa" ,"univ_BBA", "univ_eltaref",
 "univ-khenchela", "univ-eloued", "univ-oeb", "univ-soukahras", "univ-annaba", "univ_skikda",
  "univ-guelma", "univ-batna1" ,"univ-biskra", "univ-msila", "univ-ouargla", "univ-emir-constantine",
  "univ-setif1", "univ-setif2", "umc", "univ-constantine2", "univ-constantine3",
  "univ-batna2", "cuniv-Mila", "cuniv-barika", "ENSMM_Annaba", "ENP_Constantine",
  "ENSB_Constantine", "ESSG_Annaba", "ESTI_Annaba", "ESCF_Constantine", "ENSF_Khenchla",
  "HNS-RE2SD_Batna", "ENS_Ouargla", "ENS_Bousaada", "ENS_Setif", "ENSET_Skikda", "ENS_Constantine"};//1 ->30 ouest   31-75 centre 76-112 est
// 26 -> 111


int random(int min,int max){//generer un nombre aleatoirement entre deux valeurs min et max
int x=max-min+1;
int   r=rand();
int y=(r%x)+min;
return y;}
//2-------------------------------
char*randname(int nb){// generer un nom aleatoire qui a nb caractères
int i;
int j;
char*name=malloc(nb+1);
char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
for(i=0;i<nb;i++){
 j=random(1,25);
  *(name+i)=Chr1[j];
}
name[i]= '\0';
return (name);
}
int leap(int year){//fonction qui indique si une annee est bisextille ou non
if (year%400==0){
    return 1;
}else if(year%100==0){
return 0;}else
if (year%4==0){
return 1;}else{
return 0;}
}

//procédures fondamentales---------------------------------------
void chargem_init(char*nomf,int Nb,TENREG*tab){//chargement initial d'un fichier avec nb enregistrements + remplire une table d index en sortie
int i,j,l,k;
i=1;
j=1;
l=1;
fichg*f;
Tbloc buf;
Tenrg e;
int booleen = 1;
f=Ouvrir(nomf,'a');
int lower = 111111, upper = 999999;//pour generer des matricules qui ne se repetent jamais(basée sur une caractéristique des nombres premiers)
int num = (rand() % (upper - lower + 1)) + lower;
for(k=1;k<=Nb;k++){
    if (num > 999999){
            num = lower + (num % upper);
            }
    e.matricule=num;
              num = num + PRIMARY;

    tab[l].cle=e.matricule;
    tab[l].num_bloc=i;
    tab[l].num_enreg=j;
    tab[l].efface=0;
    l++;
    strcpy(e.nom,randname(random(4,30)));
    strcpy(e.prenom,randname(random(4,30)));
    e.date_de_naissance.mois=random(1,12);
    e.date_de_recrutement.mois=random(1,12);
    while(booleen){
    e.date_de_recrutement.annee=random(1985,2022);
    e.date_de_naissance.annee=random(1953,1998);
    if(verif_date_valide(e.date_de_naissance.annee,e.date_de_recrutement.annee))
        booleen = 0 ;
    }
     booleen = 1;
    if(e.date_de_naissance.mois==2 && leap(e.date_de_naissance.annee)==1){
        e.date_de_naissance.jour=random(1,29);
    }
    if(e.date_de_naissance.mois==2 && leap(e.date_de_naissance.annee)==0){
                    e.date_de_naissance.jour=random(1,28);}


        if(e.date_de_naissance.mois==4 || e.date_de_naissance.mois==6 ||e.date_de_naissance.mois==9 || e.date_de_naissance.mois==11){
        e.date_de_naissance.jour=random(1,30);
        }else{
            e.date_de_naissance.jour=random(1,31);
        }
    if(e.date_de_recrutement.mois==2 && leap(e.date_de_recrutement.annee)==1){
        e.date_de_recrutement.jour=random(1,29);
    }
    if(e.date_de_recrutement.mois==2 && leap(e.date_de_recrutement.annee)==0){

                    e.date_de_recrutement.jour=random(1,28);}


        if(e.date_de_recrutement.mois==4 || e.date_de_recrutement.mois==6 ||e.date_de_recrutement.mois==9 || e.date_de_recrutement.mois==11){
        e.date_de_recrutement.jour=random(1,30);
        }else{
            e.date_de_recrutement.jour=random(1,31);
        }


            e.wilaya_de_naissance=random(1,58);
            e.groupe_sanguin=random(1,8);
            e.etablissement_univ=random(1,112);
            e.specialite=random(1,41);
            e.grade=random(1,6);
            e.sexe=random(1,2);
            e.dernier_diplome=random(1,6);



  if(j<1025){
    buf.t[j]=e;
    j++;
  }else{
  buf.nb=j-1;
  buf.suiv=i+1;
  EcrireDir(f,i,buf);
  i++;
  buf.t[1]=e;
  j=2;
  }
}
buf.nb=j-1;
buf.suiv=-1;
EcrireDir(f,i,buf);
Aff_entete(f,1,i);
Aff_entete(f,2,Nb);

Fermer(f);
}
void quicksort(TENREG number[],int first,int last){//tri par fusion recursive (compléxité de O(nlog n))
   int i, j, pivot;
   TENREG temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i].cle<=number[pivot].cle&&i<last)
         i++;
         while(number[j].cle>number[pivot].cle)
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}

void creation_index(char*nomf,int nb,TENREG*tab){ //creation du fichier d index à partir d'une table d index

TOF*f;
TENREG e;
BUFFER buf;
int i=1,j=1,k;
f=ouvrir(nomf,'n');
//fermer(f);
//f=ouvrir(nomf,'a');
int l=1;
for(k=1;k<nb;k++){
    e.cle=tab[l].cle;
    e.num_bloc=tab[l].num_bloc;
    e.num_enreg=tab[l].num_enreg;
    l++;
    if(j<1025){
       buf.t[j]=e;
       j++;
    }else{
    buf.nb=j-1;
    ecriredir(f,i,buf);

    i++;
    buf.t[1]=e;
    j=2;

    }
}
  buf.nb=j-1;
   ecriredir(f,i,buf);
  Affentete(f,1,i);
  Affentete(f,2,nb);
  fermer(f);

}

void recherche_dichotomique(TENREG tableau[], int taille, int valeur,int*i,int*trouv){ //recherche dichotomique dans la table d index qui retourne en plus l indice du tableau ou la cle va exister
    *trouv=0;
	int borne_inf = 1;
	int borne_sup = taille;

	int position_milieu;
	while( borne_inf < borne_sup)
	{
		position_milieu = borne_inf + ((borne_sup - borne_inf) / 2);

		//--- Variante : arrêt si élément trouvé au niveau du "milieu"...
		//               mais cela génère plus de tests !!!
		if( tableau[position_milieu].cle == valeur )
		{
			 *trouv=1;

			 *i=position_milieu;

		}
		//--- Fin de la variante

		if( tableau[position_milieu].cle < valeur )
		{
			borne_inf = position_milieu + 1;
		}
		else // tableau[position_milieu] >= valeur
		{
			borne_sup = position_milieu;
		}
	}

	int position_resultat = -1;
	if( tableau[borne_inf].cle == valeur )
	{
		*trouv=1;
		*i=borne_inf;

	}

}

//insertion
void insertion(char*nomf,Tenrg e,TENREG t[],int taille,int*cout_l,int* cout_ec){
fichg*f;
Tbloc buf,buf1;
TENREG en;
int nb,trouv;
int i;
recherche_dichotomique(t,taille,e.matricule,&nb,&trouv);
while(trouv==1 && t[nb].efface==0){
    printf("\n\n\t");
    Color(12,0);
    printf_point(12);
    Color(12,0);
    printf("\tCe matricule existe deja!\n");
    Color(15,0);
    printf("\n\tVeuillez saisir un autre:\t");
    scanf("%d",&e.matricule);
    recherche_dichotomique(t,taille,e.matricule,&nb,&trouv);

}if(trouv!=1 || (trouv==1 || t[nb].efface==1)){
f=Ouvrir(nomf,'a');
i=entete(f,1);
LireDir(f,i,&buf);
cout_l++;
if(buf.nb<1025){
    buf.t[buf.nb+1]=e;
    buf.nb=buf.nb+1;
    Aff_entete(f,2,entete(f,2)+1);
    EcrireDir(f,i,buf);
   *cout_ec++;

}else{
buf.suiv=i+1;
EcrireDir(f,i,buf);
*cout_ec++;
i++;
Aff_entete(f,1,i);
buf1.t[1]=e;
buf1.nb=1;
buf1.suiv=-1;
    Aff_entete(f,2,entete(f,2)+1);

    EcrireDir(f,i,buf1);
    *cout_ec++;


}

int Nb=insertSorted(t,taille,e.matricule,i,buf.nb,350000);

}

Fermer(f);

printf("\n\n\t\t");
printf_point(10);
Color(10,0);
printf("\tInsertion bien faite!\n");
}


//modification de l'universite d un enregistrement donnee
void modifier_univ(char*nomf,int matricule,int etab,TENREG t[],int taille,int*cout_l,int *cout_ec){
int trouve,i,j,b;
fichg*f;
Tbloc buf;
Tenrg e;
f=Ouvrir(nomf,'a');
recherche_dichotomique(t,taille,matricule,&b,&trouve);
if(trouve ==1 && t[b].efface==0){
    i=t[b].num_bloc;
    j=t[b].num_enreg;
    LireDir(f,i,&buf);
    e=buf.t[j];
    e.etablissement_univ= etab ;
    buf.t[j]=e;
    EcrireDir(f,i,buf);
    printf("\n\n");
    printf_point(10);
    Color(10,0);
    printf("\tModification enregistree\n");
}else{
    Color(12,0);
    printf("Matricule non trouve! \n");
}
Fermer(f);
}
//suppression par matricule
void supprimer(char*nomf,int matricule,TENREG t[],int taille,int *existe,int*supprime,int*cout_l,int*cout_ec){ //supprimer un enregistrement donné par son matricule
int trouve,b,i,j;
fichg*f;                                                       //taille: la taille de la table d index
Tbloc buf;
Tenrg e;
recherche_dichotomique(t,taille,matricule,&b,&trouve);
if(trouve==0){
    Color(12,0);
    printf("Ce matricule n'existe pas! \nEntrez un autre\n");
    *existe=0;
    *supprime=0;
}else{*existe=1;
       if(t[b].efface==1){
        printf("Ce matricule a deja ete supprime! \nEntrez un autre:\n");
        *supprime=1;
       }else{
           *supprime=0;
           f=Ouvrir(nomf,'a');
           LireDir(f,entete(f,1),&buf);
           *cout_l++;
           e=buf.t[buf.nb];
           if(buf.nb==1){
            Aff_entete(f,1,entete(f,1)-1);
           }
           buf.nb=buf.nb-1;
           EcrireDir(f,entete(f,1),buf);
           *cout_ec++;
           i=t[b].num_bloc;
           j=t[b].num_enreg;
           LireDir(f,i,&buf);
           *cout_l++;
           buf.t[j]=e;
           EcrireDir(f,i,buf);
           *cout_ec;
           t[b].efface=1;
           Aff_entete(f,2,entete(f,2)-1);
        Fermer(f);
        printf("\n\n");
        printf_point(10);
        Color(10,0);
        printf("\tSuppression terminee!\n");
       }
}

}

int insertSorted(TENREG arr[], int n,int key,int bloc,int enreg, int capacity){//inserer un element dans un tableau dans l ordre decroissant
    if (n >= capacity)
        return n;

    int i;
    TENREG e;
    e.cle = key;
    e.efface=0;
    e.num_bloc=bloc;
    e.num_enreg=enreg;
    for (i = n - 1; (i >= 0 && arr[i].cle > key); i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = e;

    return (n + 1);
}

int Requete_Intervalle(int min , int max){
    if ((min >= 1985 && min <= 2022)&&(max >= 1985 && min <= 2022)&&(max > min))
        return 1;
    else
    return 0;
}
int verif_date_valide(int n, int r){
    int diff = r - n ;
    if (diff > 24)
        return 1;
    return 0;
}

//suppression de tous les enregistrements d'une specialite
void supprimer_sp(char*nomf,int sp,int *cout_lect,int*cout_ecr,TENREG t[],int taille){
int  i,j,x=1,b,trouv;
fichg*f;
Tbloc temp,buf;
*cout_lect = 0;
*cout_ecr = 0 ;
if(sp>=1 && sp<=41){
        f=Ouvrir(nomf,'a');
        while(x!=-1){
            LireDir(f,x,&buf);
            (*cout_lect)++;
            for(j=1 ; j <= buf.nb; j++){
                if (buf.t[j].specialite == sp){
                    recherche_dichotomique(t,taille,buf.t[j].matricule,&b,&trouv);
                    t[b].efface=1;
                    buf.t[j] = buf.t[buf.nb];
                    buf.nb--;
                    j--;
                    Aff_entete(f,2,(entete(f,2)-1));
                }
            }
            if (buf.nb == 0){
                LireDir(f,entete(f,1),&buf);
                (*cout_lect)++;
                Aff_entete(f,1,(entete(f,1)-1));
                EcrireDir(f,x,buf);
                (*cout_ecr)++;
                x--;
            }
                EcrireDir(f,x,buf);
                (*cout_ecr)++;
                x=buf.suiv;
        }
    }
    else{
        Color(12,0);
        printf("Ce choix n'est pas valide!\n");
    }
    Fermer(f);
}
void  Codage (char*nomf){
int y,i,j,cpt,k ;


char cle[30];
Tbloc buf1,buf2;
fichg* f, *g ;
printf("\n-------------------------------------------------------\n");
printf("--------------------------codage------------------------ \n");
printf("--------------------------------------------------------\n\n");

printf ("\nVeuillez saisir la cle de cryptage  : \n\n");

scanf ("%s", cle);
y = strlen(cle);
f = ouvrir(nomf,'a');
g = ouvrir("Fichier_code.bin",'n');
Fermer(g);
g = ouvrir("Fichier_code.bin",'a');
printf("\n\nCodage en cours ....\n");sleep(1);
for (i=1;i<=Entete(f,1);i++)
{
LireDir(f,i,&buf1);
  for (j=1;j<=buf1.nb;j++)
{
    // codage du champs date de naissance
    buf2.t[j].date_de_naissance.jour=(-10+(buf1.t[j].date_de_naissance.jour));
    buf2.t[j].date_de_naissance.mois=(+10+(buf1.t[j].date_de_naissance.mois));
    buf2.t[j].date_de_naissance.annee=(-10+(buf1.t[j].date_de_naissance.annee));

    // codage du champs date de recrutement
    buf2.t[j].date_de_recrutement.jour=(-10+(buf1.t[j].date_de_recrutement.jour));
    buf2.t[j].date_de_recrutement.mois=(+10+(buf1.t[j].date_de_recrutement.mois));
    buf2.t[j].date_de_recrutement.annee=(-10+(buf1.t[j].date_de_recrutement.annee));

    // codage du champs dernier diplome
    buf2.t[j].dernier_diplome=(buf1.t[j].dernier_diplome-1000);

    // codage du champs etablissement universitaire
    buf2.t[j].etablissement_univ=(buf1.t[j].etablissement_univ-10000);

    // codage du champs grade
    buf2.t[j].grade=(buf1.t[j].grade-1000);

    // codage du champs groupe sanguin
    buf2.t[j].groupe_sanguin=(buf1.t[j].groupe_sanguin-1000);

    // codage du champs matricule
    buf2.t[j].matricule=(buf1.t[j].matricule-1000000);

    // codage du champs nom
    k=0;cpt=0;
    while(  buf1.t[j].nom[k]!='\0')
	{

	buf2.t[j].nom[k]=  buf1.t[j].nom[k]+cle[cpt];
	cpt = (cpt + 1 ) % y ; // pour aller au prochain caractere de la cle
    k++;
    }


    // codage du champs prénom
    k=0;cpt=0;
    while(buf1.t[j].prenom[k]!='\0')
	{

	buf2.t[j].prenom[k]=  buf1.t[j].prenom[k] + cle[cpt];
	cpt = (cpt + 1 ) % y ; // pour aller au prochain caractere de la cle
    k++;
    }


    // codage du champs sexe
    buf2.t[j].sexe=(buf1.t[j].sexe-1000);

    // codage du champs spécialité
    buf2.t[j].specialite= (buf1.t[j].specialite-1000);

    // codage du champs wilaya de naissance
    buf2.t[j].wilaya_de_naissance=(buf1.t[j].wilaya_de_naissance-10000);


}
  buf2.nb=j;
  buf2.suiv=i+1;
  EcrireDir(g,i,buf2);
}
buf2.nb=j;
buf2.suiv=-1;
EcrireDir(g,i,buf2);
Aff_entete(g,1,i);
Aff_entete(g,2,entete(f,2));
Color(10,0);
printf("codage reussi");

Fermer(f);
Fermer(g);
}
void Decodage (){


char cle[10];
int y,i,j,k, cpt ;

Tbloc buf1,buf2;
char Nomcoded[30];
fichg *f, *g ;

printf("\n-------------------------------------------------------\n");
printf("------------------------Decodage------------------------ \n");
printf("--------------------------------------------------------\n\n");
printf ("\nVeuillez saisir la cle du decryptage : \n\n");
scanf ("%s", cle);
y = strlen(cle);

f = ouvrir("Fichier_code.bin", 'a');
g = ouvrir("Fichier_decode.bin", 'n');
fseek (f->f , 0 , SEEK_SET);
Color(10,0);
printf("\n\nDecodage en cours ....\n");sleep(1);
for (i=1;i<=Entete(f,1);i++)
{
LireDir(f,i,&buf1);
  for (j=1;j<buf1.nb;j++)
{
    // décodage du champs date de naissance
    buf2.t[j].date_de_naissance.jour=(10+(buf1.t[j].date_de_naissance.jour));
    buf2.t[j].date_de_naissance.mois=(-10+(buf1.t[j].date_de_naissance.mois));
    buf2.t[j].date_de_naissance.annee=(10+(buf1.t[j].date_de_naissance.annee));

    // décodage du champs date de recrutement
    buf2.t[j].date_de_recrutement.jour=(10+(buf1.t[j].date_de_recrutement.jour));
    buf2.t[j].date_de_recrutement.mois=(-10+(buf1.t[j].date_de_recrutement.mois));
    buf2.t[j].date_de_recrutement.annee=(10+(buf1.t[j].date_de_recrutement.annee));

    // décodage du champs dernier diplome
    buf2.t[j].dernier_diplome=(buf1.t[j].dernier_diplome+1000);

    // décodage du champs etablissement universitaire
    buf2.t[j].etablissement_univ=(buf1.t[j].etablissement_univ+10000);

    // décodage du champs grade
    buf2.t[j].grade=(buf1.t[j].grade+1000);

    // décodage du champs groupe sanguin
    buf2.t[j].groupe_sanguin=(buf1.t[j].groupe_sanguin+1000);

    // décodage du champs matricule
    buf2.t[j].matricule=(buf1.t[j].matricule+1000000);

    // décodage du champs nom
    k=0;cpt=0;
    while(  buf1.t[j].nom[k]!='\0')
	{
    buf2.t[j].nom[k]=  buf1.t[j].nom[k]-cle[cpt];
	cpt = (cpt + 1 ) % y ; // pour aller au prochain caractere de la cle
    k++;

    }

    // décodage du champs prénom
    k=0;cpt=0;
    while(buf1.t[j].prenom[k]!='\0')
	{
	buf2.t[j].prenom[k] =  buf1.t[j].prenom[k] - cle[cpt];
	cpt = (cpt + 1 ) % y ; // pour aller au prochain caractere de la cle
    k++;
    }


    // décodage du champs sexe
    buf2.t[j].sexe=(buf1.t[j].sexe + 1000);

    // décodage du champs spécialité
    buf2.t[j].specialite= (buf1.t[j].specialite + 1000);

    // décodage du champs wilaya de naissance
    buf2.t[j].wilaya_de_naissance=(buf1.t[j].wilaya_de_naissance+10000);


}
  buf2.nb=j;
  buf2.suiv=i+1;
  EcrireDir(g,i,buf2);
}
buf2.nb=j;
buf2.suiv=-1;
EcrireDir(g,i,buf2);
Aff_entete(g,2,100000);
Aff_entete(g,1,i);
Color(10,0);
printf("decodage reussi");

Fermer(f);
Fermer(g);
}


