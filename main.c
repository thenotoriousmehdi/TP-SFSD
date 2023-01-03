#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LNOF.h"   // LObarreF
#include "TOF.h"    // TOF
#define PRIMARY 100069
#include "conio2.h"
#include <time.h>
#include <windows.h>
#include"TP.h"
#define lar 160

int main(){

fichg*f;
Tbloc buf;
int NE,NBE;
int j=1;
int i=1;
int a;
int nb=0;
int reply,mat,matt,mattt,x=1;
int cout_lecture=0;
int cout_ecriture=0;

Sleep(2000);
TP(60,10);
Sleep(1000);
system("cls");


    Sleep(2000);
	acceuil();
	gotoxy(1,40);
	message_attente();
TENREG*tab;//declaration de la table d index
tab=malloc(sizeof(TENREG)*350000);
Tenrg en;
  //allouer dynamiquement la zone mémoire nécessaire pour la table d index
f=Ouvrir("ENSEIGNANTS-MESRS.bin",'n');//creation du fichier
Fermer(f);


printf("\n\n\t\tVeuillez donner le nombre d'enregistrements que vous voulez creer:\t");
scanf("%d",&NE);
Color(1,15);
printf("\n\n");
printf("\t\t\t\t ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ ____ ____  \n"
       "\t\t\t\t||C |||H |||A |||R |||G |||E |||M |||E |||N |||T |||       |||I |||N |||I |||T |||I |||A |||L || \n"
       "\t\t\t\t||__|||__|||__|||__|||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__|||__|| \n"
       "\t\t\t\t|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\| \n");
chargem_init("ENSEIGNANTS-MESRS.bin",NE,tab);
printf("\n\n\t\t\t\t\t\t\tChargement en cours, veuillez patienter svp... ");
Sleep(2000);
Color(12,15);
printf("\n\n\t\t\t\t\t\t\t  Chargement initial fait avec success !\n");
 f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
 cout_ecriture=entete(f,1);
 Fermer(f);
 quicksort(tab,1,NE);//trier la table d index
int ce1=0;
creation_index("index.bin",NE,tab);
cout_ecriture=cout_ecriture+ce1;
Sleep(500);
Color(12,15);
printf("\n\n\t\t\t\tAFFICHEGE DE L'ENTETE:\t");
f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
printf("\tNombre de blocs:  %d",entete(f,1));
printf("\t\tNombre d'enregistrements: %d\n\n\n",entete(f,2));
Fermer(f);
printf("Pour acceder au menu principal");
message_attente();
int continu=1;
while(continu==1){


menu:
reply=menu();
switch(reply){    // les choix du menu

    case  1:             // inserer un nouvel enregistrement
    {
    system("cls");
    int jour1,annee1,mois1,jour2,mois2,annee2,region,wilaya,groupe,grade,sexe,dp,etab_univ,specialite;
    int jl, al;
    char nom[30];
    char prenom[30];
    int ce2=0;
    int cl2=0;
    printf("\n\nVeuillez entrer le matricule que vous voulez inserer (6 chiffres):\t");
    scanf("%d",&mat);
    while (mat<111111 || mat>999999){
        printf("\n\n\t");
        Color(12,15);
        printf_point(12);
        Color(12,15);
        printf("\tMatricule errone!\n\n");
        Color(12,15);
        printf("\tEntrez un autre!\t");
        scanf("%d",&mat);
    }
    en.matricule=mat;
    printf("-----------------------------------------------------------------------------");
    printf("\n\nVeuillez entrer le nom:\t");
    scanf("%s",nom);
    printf("Veuillez entrer le prenom:\t");
    scanf("%s",prenom);
    printf("-----------------------------------------------------------------------------");
    printf("\n\nVeuillez entrer la date de naissance:\n");
    printf("Annee de naissance (entre 1953 et 1998):\t");
    scanf("%d",&annee1);
    while (annee1 > 1998 || annee1 < 1953 ){
    printf("\tVeuillez inserer une annee comprise entre 1953 et 1988, ici:\t");
    scanf("%d",&annee1);}
    printf("Mois de naissance (entre 1 et 12):\t");
    scanf("%d",&mois1);
    while (mois1 > 12 || mois1 < 1){
    printf("\tVeuillez inserer un nombre correspondant au mois compris entre 1 et 12, ici:\t");
    scanf("%d",&mois1);}
    if (mois1==4 || mois1==6 || mois1==9 || mois1==11)
        jl = 30 ;
        else jl = 31 ;
    if (leap(annee1) && mois1 == 2)
        jl = 29 ;
    if (!(leap(annee1)) && mois1 == 2)
        jl = 28 ;
    printf("Jour de naissance (entre 1 et %d):\t",jl);
    scanf("%d",&jour1);
    while (jour1 > jl || jour1 < 1){
    printf("\tVeuillez inserer un numero de jour compris entre 1 et %d, ici:\t",jl);
    scanf("%d",&jour1);}

    printf("-----------------------------------------------------------------------------");
    if(annee1 > 1960)
    al = annee1 + 25;
    else al = 1985 ;
    printf("\n\nVeuillez entrer la date de recrutement:\n");
    printf("Annee de recrutement (entre %d et 2022):\t", al);
    scanf("%d",&annee2);
    while(annee2 > 2022 || annee2 < al){
        printf("\tVeuillez inserer une annee comprise entre 1953 et 1988, ici:\t");
        scanf("%d",&annee2);
    }
    printf("Mois de recrutement (entre 1 et 12):\t");
    scanf("%d",&mois2);
    while(mois2 > 12 || mois2 < 1){
        printf("\tVeuillez inserer un nombre correspondant au mois compris entre 1 et 12, ici:\t");
        scanf("%d",&mois2);
    }
    if (mois2==4 || mois2==6 || mois2==9 || mois2==11)
        jl = 30 ;
        else jl = 31 ;
    if (leap(annee2) && mois2 == 2)
        jl = 29 ;
    if (!(leap(annee2)) && mois2 == 2)
        jl = 28 ;
    printf("Jour de recrutement (entre 1 et %d) :\t", jl);
    scanf("%d",&jour2);
    while (jour2 > jl || jour2 < 1){
    printf("\tVeuillez inserer un numero de jour compris entre 1 et %d, ici:\t",jl);
    scanf("%d",&jour2);}
    printf("-----------------------------------------------------------------------------");
    printf("\n\nVeuillez entrer le numero de la wilaya de naissance:\t");
    scanf("%d",&wilaya);
    while (wilaya > 58){
        printf("\tVeuillez inserer un numero de wilaya compris entre 1 et 58, ici:\t");
        scanf("%d",&wilaya);
    }
    printf("-----------------------------------------------------------------------------");

    printf("\n\nVeuillez choisir un sexe:\n");
    printf("1-Masculin\n2-Feminin\n");
    printf("Votre reponse:\t ");
    scanf("%d",&sexe);
    while (sexe > 2){
        printf("\tVous devez choisir entre 1 et 2, reessayez ici :\t");
        scanf("%d",&sexe);
    }
    printf("-----------------------------------------------------------------------------");
    printf("\n\nVeuillez choisir un groupe sanguin:\n");
    printf("1- O+\n2- A+\n3- B+\n4- O-\n5- A-\n6- AB+\n7- B-\n8- AB-\n");
    printf("Votre reponse:\t ");
    scanf("%d",&groupe);
    while (groupe > 8){
            Color(12,15);
        printf("\tVous devez choisir un nombre compris en 1 et 8, reessayez ici :\t");
        scanf("%d",&groupe);
    }
    printf("-----------------------------------------------------------------------------");
    printf("\nVeuillez entrer le numero qui correspond un grade:\n");
    printf("1-Professeur(e)\n"
           "2-Maitre de conference Rang-A\n"
           "3-Maitre de conference Rang-B\n"
           "4-Maitre Assistant(e) Rang-A\n"
           "5-Maitre Assistant(e) Rang-B\n"
           "6-Assistant(e)\n");
           printf("Votre reponse:\t ");
    scanf("%d",&grade);
    while (grade > 6){
            Color(12,15);
        printf("\tVous devez choisir un nombre compris en 1 et 6, reessayez ici :\t");
        scanf("%d",&grade);
    }
    printf("-----------------------------------------------------------------------------");
    printf("\nVeuillez entrez le numero qui correspond a une specialite:\n");
    printf( "01-Arts                      15-CHIMIE                      29-SCIENCES POUR LA SANTE       \n"
            "02-Arts du spectale          16-ELECTRONIQUE                30-STAPS                        \n"
            "03-ARTS PLASTIQUES           17-ENERGIE ELECTRIQUE          31-GEOGRAPHIE ET AMENAGEMENT    \n"
            "04-HIST DE LART ET ARCHEO    18-AUTOMATIQUE                 32-HISTOIRE                     \n"
            "05-MUSICOLOGIE               19-GENIE CIVIL                 33-INFORMATION ET COMMUNICATION \n"
            "06-ADMINISTRATION PUBLIQUE   20-INFORMATIQUE                34-PHILOSOPHIE                  \n"
            "07-DROIT                     21-MATHEMATIQUES               35-PSYCHOLOGIE                  \n"
            "08-SCIENCE POLITIQUE         22-MECANIQUE                   36-SCIENCES DE L EDUCATION      \n"
            "09-AES                       23-MIASHS                      37-SOCIOLOGIE                   \n"
            "10-ECONOMIE                  24-PHYSIQUE                    38-MEDECINE                     \n"
            "11-GESTION                   25-SCIENCES DE LA TERRE        39-PHARMACIE                    \n"
            "12-LETTRES                   26-SCIENCES DE LA VIE          40-CHIRURGIE DENTAIRE           \n"
            "13-LANGUES                   27-SCIENCES ET TECHNOLOGIES                                    \n"
            "14-SCIENCES DU LANGAGE       28-SCIENCES POUR L INGENIEUR                                   \n");
            printf("Votre reponse:\t ");
    scanf("%d",&specialite);//specialite
    while (specialite > 40){
            Color(12,15);
        printf("\tVous devez choisir un nombre compris en 1 et 40, reessayez ici :\t");
        scanf("%d",&specialite);
    }

    printf("-----------------------------------------------------------------------------");
    printf("\n\nVeuillez enter votre dernier diplome:\n");
    printf("1- Doctor D'etat \n2- Doctorat en sciences \n3- Doctorat D-LMD \n4- PHD \n5- Habilitation Universitaire \n6- Magistere \n");
    printf("Votre reponse:\t ");
    scanf("%d",&dp);
    while (dp > 6){
            Color(12,15);
        printf("\tVous devez choisir un nombre compris en 1 et 6, reessayez ici :\t");
        scanf("%d",&dp);
    }
    printf("-----------------------------------------------------------------------------");
    printf("\nVeuillez entrer le numero qui correspond a une universite:\n");
    printf( "01-Univ_Bechar           24-Essb_Oran             47-Univ_Tmenghasset   70-ENSM_Alger        93-Univ_Setif2      \n"
            "02-Univ_Mascara          25-Esm_Tlemcen           48-CUniv_Tipaza       71-ENSIA_Alger       94-Univ_Constantine1\n"
            "03-Univ_Saida            26-ESSA_Telemcen         49-CUniv_Ilizi        72-ENS_Kouba         95-Univ_Constantine2\n"
            "04-Univ_Tlemcen          27-CUniv_Naama           50-CUniv_Aflou        73-ENSSM_Alger       96-Univ_Constantine3\n"
            "05-Univ_Adrar            28-CUniv_ELBayadh        51-ENP_Alger          74-ENS_Laghouat      97-Univ_Batna2      \n"
            "06-Univ_Tiaret           29-CUniv_Tindouf         52-ENSH_Alger         75-ENS_Bouzareah     98-CUniv_Mila       \n"
            "07-Univ_Sba              30-CUniv_Maghnia         53-ENSTP_Alger        76-Univ_Jijel        99-Cuniv_Barika     \n"
            "08-Univ_Mostaganem       31-Univ_Bouira           54-ENSV_Alger         77-Univ_Tebessa      100-ENSMM_Annaba    \n"
            "09-Univ_Oran1            32-Univ_Djelfa           55-EPAU_Alger         78-Univ_BBA          101-ENP_Constantine \n"
            "10-USTOMB_Oran           33-Univ_Laghouat         56-ENSA_Alger         79-Univ_Eltaref      102-ENSB_Constantine\n"
            "11-Univ_Oran2            34-Univ_Ghardaia         57-HEC_Kolea          80-Univ_Khenchela    103-ESSG_Annaba     \n"
            "12-Univ_Chlef            35-Univ_Khemis-meliana   58-ESI_Alger          81-Univ_ELoued       104-ESTI_Annaba     \n"
            "13-Univ_Tissemsilt       36-Univ_Medea            59-ENSSEA_Alger       82-Univ_Oelbouaghi   105-ESCF_Constantine\n"
            "14-Univ_Ain Témouchent   37-USTHB                 60-ESC_Alger          83-Univ_Soukahras    106-ENSF_Khenchla   \n"
            "15-Univ_Relizane         38-Univ_Bejaia           61-ENSSMAL_Alger      84-Univ_Annaba       107-hns-re2sd_Batna \n"
            "16-ENP_Oran              39-Univ_Boumerdes        62-ENSM_Kolea         85-Univ_Skikda       108-ENS_Ouargla     \n"
            "17-Esi_Sba               40-Univ_Tiziouzou        63-ENST_Alger         86-Univ_Guelma       109-ENS_Bousaada    \n"
            "18-Ese_Oran              41-Univ_Blida1           64-ensjsi_Alger       87-Univ_Batna1       110-ENS_Setif       \n"
            "19-ESGEE_Oran            42-Univ_Blida2           65-ENSSP_Alger        88-Univ_Biskra       111-ENSET_Skikda    \n"
            "20-ENS_Oran              43-Univ_Alger1           66-ESSAIA_ Alger      89-Univ_Msila        112-ENS_Constantine \n"
            "21-ENS_Bechar            44-Univ_Alger2           67-ESSA_Alger         90-Univ_Ouargla                          \n"
            "22-ENS_Mostaganem        45-Univ_Alger3           68-ESGEN_Alger        91-Univ-emir-const                       \n"
            "23-Esa_Mostaganem        46-UFC                   69-ESTIN_Bejaia       92-Univ_Setif1                           \n");
printf("Votre reponse:\t ");
    scanf("%d",&etab_univ);//etab_univ
while (etab_univ > 112){
        printf("\tVous devez choisir un nombre compris en 1 et 112, reessayez ici :\t");
        scanf("%d",&etab_univ);
    }
    en.date_de_naissance.annee=annee1;
    en.date_de_naissance.jour=jour1;
    en.date_de_naissance.mois=mois1;
    en.date_de_recrutement.annee=annee2;
    en.date_de_recrutement.jour=jour2;
    en.date_de_recrutement.mois=mois2;
    en.specialite=specialite;//specialite
    en.groupe_sanguin=groupe;
    en.sexe = sexe ;
    en.grade = grade ;
    en.dernier_diplome = dp;
    strcpy(en.prenom,prenom);
    strcpy(en.nom,nom);
    en.etablissement_univ=etab_univ;//etab univ
    en.wilaya_de_naissance=wilaya;
    system("cls");
    insertion("ENSEIGNANTS-MESRS.bin",en,tab,NE+nb,&cl2,&ce2);
    cout_lecture=cout_lecture+cl2;
    cout_ecriture=cout_ecriture+ce2;
    Color(0,15);
    printf("\nAffichage de l'enregistrement insere:\n\n");
    f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
    LireDir(f,entete(f,1),&buf);
    cout_lecture++;
    printf("\nMatricule |Nom            |Prenom         |Date_naissance|Wilaya_Naissance  |sexe    |G-S|Date_Recrutement|Grade             |Specialite      |Dernier_Diplome           |Etablissement_Univ \n");
    Color(1,15);
    printf("%-10d|%-15.15s|%-15.15s|%3.2d/%4.2d/%5.4d|%-18.18s|%-8.8s|%-2.2s |%4.2d/%4.2d/%5.4d |%-18.18s|%-16.16s|%-26.26s|%-23s \n",
           buf.t[buf.nb].matricule,
           buf.t[buf.nb].nom,
           buf.t[buf.nb].prenom,
           buf.t[buf.nb].date_de_naissance.jour,
           buf.t[buf.nb].date_de_naissance.mois,
           buf.t[buf.nb].date_de_naissance.annee,
           Wilaya_Naissance[buf.t[buf.nb].wilaya_de_naissance],
           Sexe[buf.t[buf.nb].sexe],
           Groupe_Sanguin[buf.t[buf.nb].groupe_sanguin],
           buf.t[buf.nb].date_de_recrutement.jour,
           buf.t[buf.nb].date_de_recrutement.mois,
           buf.t[buf.nb].date_de_recrutement.annee,
           Grade[buf.t[buf.nb].grade],
           Specialite[buf.t[buf.nb].specialite],
           Dernier_Diplome[buf.t[buf.nb].dernier_diplome],
           Etab_Univ[buf.t[buf.nb].etablissement_univ]);
           printf("\nLe nombre d'enregistrements est: %d\n\n",entete(f,2));
    Fermer(f);
    nb++;
    break;
    }

    case 2:
    {
    system("cls");
    printf("\n\nEntrez le matricule de l'enregistrement que vous voulez modifier:\t");
    scanf("%d",&matt);
     while (matt<111111 || matt>999999){
        Color(13,0);
        printf("Matricule errone! \nEntrez un autre!\t");
        scanf("%d",&matt);
    }
    int m,n,found;
    int cl3=0;
    int ce3=0;
   recherche_dichotomique(tab,NE+nb,matt,&m,&found);
    if(found==1 && tab[m].efface==0){
        f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
        LireDir(f,tab[m].num_bloc,&buf);
        cout_lecture++;
        printf("\n\nAvant modification:\n\n");
        Color(1,15);
        printf("Matricule:   %d  | Etablissement:  %s\n\n",buf.t[tab[m].num_enreg].matricule,Etab_Univ[buf.t[tab[m].num_enreg].etablissement_univ]);
        Fermer(f);
        Color(0,15);
    printf("\nVeuillez choisir le numero correspondant a la nouvelle universite:\n");
    int newuniv;
    printf( "01-Univ_Bechar           24-Essb_Oran             47-Univ_Tmenghasset   70-ENSM_Alger        93-Univ_Setif2      \n"
            "02-Univ_Mascara          25-Esm_Tlemcen           48-CUniv_Tipaza       71-ENSIA_Alger       94-Univ_Constantine1\n"
            "03-Univ_Saida            26-ESSA_Telemcen         49-CUniv_Ilizi        72-ENS_Kouba         95-Univ_Constantine2\n"
            "04-Univ_Tlemcen          27-CUniv_Naama           50-CUniv_Aflou        73-ENSSM_Alger       96-Univ_Constantine3\n"
            "05-Univ_Adrar            28-CUniv_ELBayadh        51-ENP_Alger          74-ENS_Laghouat      97-Univ_Batna2      \n"
            "06-Univ_Tiaret           29-CUniv_Tindouf         52-ENSH_Alger         75-ENS_Bouzareah     98-CUniv_Mila       \n"
            "07-Univ_Sba              30-CUniv_Maghnia         53-ENSTP_Alger        76-Univ_Jijel        99-Cuniv_Barika     \n"
            "08-Univ_Mostaganem       31-Univ_Bouira           54-ENSV_Alger         77-Univ_Tebessa      100-ENSMM_Annaba    \n"
            "09-Univ_Oran1            32-Univ_Djelfa           55-EPAU_Alger         78-Univ_BBA          101-ENP_Constantine \n"
            "10-USTOMB_Oran           33-Univ_Laghouat         56-ENSA_Alger         79-Univ_Eltaref      102-ENSB_Constantine\n"
            "11-Univ_Oran2            34-Univ_Ghardaia         57-HEC_Kolea          80-Univ_Khenchela    103-ESSG_Annaba     \n"
            "12-Univ_Chlef            35-Univ_Khemis-meliana   58-ESI_Alger          81-Univ_ELoued       104-ESTI_Annaba     \n"
            "13-Univ_Tissemsilt       36-Univ_Medea            59-ENSSEA_Alger       82-Univ_Oelbouaghi   105-ESCF_Constantine\n"
            "14-Univ_Ain Témouchent   37-USTHB                 60-ESC_Alger          83-Univ_Soukahras    106-ENSF_Khenchla   \n"
            "15-Univ_Relizane         38-Univ_Bejaia           61-ENSSMAL_Alger      84-Univ_Annaba       107-hns-re2sd_Batna \n"
            "16-ENP_Oran              39-Univ_Boumerdes        62-ENSM_Kolea         85-Univ_Skikda       108-ENS_Ouargla     \n"
            "17-Esi_Sba               40-Univ_Tiziouzou        63-ENST_Alger         86-Univ_Guelma       109-ENS_Bousaada    \n"
            "18-Ese_Oran              41-Univ_Blida1           64-ensjsi_Alger       87-Univ_Batna1       110-ENS_Setif       \n"
            "19-ESGEE_Oran            42-Univ_Blida2           65-ENSSP_Alger        88-Univ_Biskra       111-ENSET_Skikda    \n"
            "20-ENS_Oran              43-Univ_Alger1           66-ESSAIA_ Alger      89-Univ_Msila        112-ENS_Constantine \n"
            "21-ENS_Bechar            44-Univ_Alger2           67-ESSA_Alger         90-Univ_Ouargla                          \n"
            "22-ENS_Mostaganem        45-Univ_Alger3           68-ESGEN_Alger        91-Univ-emir-const                       \n"
            "23-Esa_Mostaganem        46-UFC                   69-ESTIN_Bejaia       92-Univ_Setif1                           \n");
    printf("Votre reponse:\t ");
    scanf("%d",&newuniv);
    modifier_univ("ENSEIGNANTS-MESRS.bin",matt,newuniv,tab,NE+nb,&cl3,&ce3);
    cout_lecture=cout_lecture+cl3;
    cout_ecriture=cout_ecriture+ce3;
    f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
    LireDir(f,tab[m].num_bloc,&buf);
    cout_lecture++;
    Color(1,15);
    printf("\nAffichage apres modification: \n");
    Color(1,15);
    printf("Matricule %d  | Universite %s\n",buf.t[tab[m].num_enreg].matricule,Etab_Univ[buf.t[tab[m].num_enreg].etablissement_univ]);
    Fermer(f);
    }else{
        Color(12,0);
        printf("Ce matricule n'existe pas dans le fichier\n");}

    break;
    }

    case 3:
    {
    system("cls");
    int sup,exist;
    int cl4=0;
    int ce4=0;
    int sur;
    printf("\n\nEntrer le matricule de l'enregistrement que vous voulez supprimer: \t");
    scanf("%d",&mattt);
    while (mattt<111111 || mattt>999999){
        Color(12,0);
        printf("Matricule errone! \nVeuillez entrez un autre!\t");
        scanf("%d",&mattt);
    }
    printf("Etes-vous sur de supprimer l'enseignant au matricule ci-dessus? (Repondez par oui ou non)\n");
    printf("1-Oui\n"
           "2-Non\n");
    printf("Veuillez donner une reponse: ");
    scanf("%d", &sur);
    if(sur == 1){
    supprimer("ENSEIGNANTS-MESRS.bin",mattt,tab,NE+nb,&exist,&sup,&cl4,&ce4);
    f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
    cout_ecriture=cout_ecriture+2;
    cout_lecture=cout_lecture+2;
   /*while(sup==1 || exist==0); {
        scanf("%d",&mattt);
        supprimer("ENSEIGNANTS-MESRS.bin",mattt,tab,300000+nb,&exist,&sup);
    }*/
    printf("le nombre actuel des enregistrements est %d\n",entete(f,2));
    Fermer(f);}
    else
    printf("\nVotre requete a ete bien enregistree.\n");
    break;
    }

    case 4:
    {
    system("cls");
    int SP, i,j;
    int Cl=0;
    int Ce=0;
    int sur1;
    Tbloc temp;
    printf("\nVeuillez entrer le numero correspondant a la specialite que vous voulez supprimer: \t\n");
    printf( "01-Arts                      15-CHIMIE                      29-SCIENCES POUR LA SANTE       \n"
            "02-Arts du spectale          16-ELECTRONIQUE                30-STAPS                        \n"
            "03-ARTS PLASTIQUES           17-ENERGIE ELECTRIQUE          31-GEOGRAPHIE ET AMENAGEMENT    \n"
            "04-HIST DE LART ET ARCHEO    18-AUTOMATIQUE                 32-HISTOIRE                     \n"
            "05-MUSICOLOGIE               19-GENIE CIVIL                 33-INFORMATION ET COMMUNICATION \n"
            "06-ADMINISTRATION PUBLIQUE   20-INFORMATIQUE                34-PHILOSOPHIE                  \n"
            "07-DROIT                     21-MATHEMATIQUES               35-PSYCHOLOGIE                  \n"
            "08-SCIENCE POLITIQUE         22-MECANIQUE                   36-SCIENCES DE L EDUCATION      \n"
            "09-AES                       23-MIASHS                      37-SOCIOLOGIE                   \n"
            "10-ECONOMIE                  24-PHYSIQUE                    38-MEDECINE                     \n"
            "11-GESTION                   25-SCIENCES DE LA TERRE        39-PHARMACIE                    \n"
            "12-LETTRES                   26-SCIENCES DE LA VIE          40-CHIRURGIE DENTAIRE           \n"
            "13-LANGUES                   27-SCIENCES ET TECHNOLOGIES    41-PSYCHOLOGIE                  \n"
            "14-SCIENCES DU LANGAGE       28-SCIENCES POUR L INGENIEUR                                  \n");
            printf("Votre reponse:\t ");
    scanf("%d", &SP);
    while (SP > 40){
        printf("\tVous devez choisir entre 1 et 40, reessayez ici :\t");
        scanf("%d",&SP);}
    printf("Etes-vous sur de supprimer l'enseignant au matricule ci-dessus? (Repondez par oui ou non)\n");
    printf("1-Oui\n"
           "2-Non\n");
    printf("Veuillez donner une reponse: ");
    scanf("%d", &sur1);
    if(sur1 == 1){
    printf("\n\n");
    supprimer_sp("ENSEIGNANTS-MESRS.bin",SP,&Cl,&Ce,tab,NE+nb);
    cout_ecriture=cout_ecriture+Ce;
    cout_lecture=cout_lecture+Cl;
    printf_point(10);
    Color(13,0);
    printf("\t\tSuppression terminee avec succes! \n\n");
    f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
    Color(1,15);
    printf("\n\tNombre d'enregistrement actuel:  %d", entete(f,2));
    Fermer(f);}
    else
    printf("\nVotre requete a ete bien enregistree.\n");

     break;
    }

    case 5:

    {
    system("cls");
    int EU;
    int MIN, MAX;
    x = 1;
    printf("\nVeuillez entrer le numero qui correspond a l'universite que vous chercher : \n");
    printf( "01-Univ_Bechar           24-Essb_Oran             47-Univ_Tmenghasset   70-ENSM_Alger        93-Univ_Setif2      \n"
            "02-Univ_Mascara          25-Esm_Tlemcen           48-CUniv_Tipaza       71-ENSIA_Alger       94-Univ_Constantine1\n"
            "03-Univ_Saida            26-ESSA_Telemcen         49-CUniv_Ilizi        72-ENS_Kouba         95-Univ_Constantine2\n"
            "04-Univ_Tlemcen          27-CUniv_Naama           50-CUniv_Aflou        73-ENSSM_Alger       96-Univ_Constantine3\n"
            "05-Univ_Adrar            28-CUniv_ELBayadh        51-ENP_Alger          74-ENS_Laghouat      97-Univ_Batna2      \n"
            "06-Univ_Tiaret           29-CUniv_Tindouf         52-ENSH_Alger         75-ENS_Bouzareah     98-CUniv_Mila       \n"
            "07-Univ_Sba              30-CUniv_Maghnia         53-ENSTP_Alger        76-Univ_Jijel        99-Cuniv_Barika     \n"
            "08-Univ_Mostaganem       31-Univ_Bouira           54-ENSV_Alger         77-Univ_Tebessa      100-ENSMM_Annaba    \n"
            "09-Univ_Oran1            32-Univ_Djelfa           55-EPAU_Alger         78-Univ_BBA          101-ENP_Constantine \n"
            "10-USTOMB_Oran           33-Univ_Laghouat         56-ENSA_Alger         79-Univ_Eltaref      102-ENSB_Constantine\n"
            "11-Univ_Oran2            34-Univ_Ghardaia         57-HEC_Kolea          80-Univ_Khenchela    103-ESSG_Annaba     \n"
            "12-Univ_Chlef            35-Univ_Khemis-meliana   58-ESI_Alger          81-Univ_ELoued       104-ESTI_Annaba     \n"
            "13-Univ_Tissemsilt       36-Univ_Medea            59-ENSSEA_Alger       82-Univ_Oelbouaghi   105-ESCF_Constantine\n"
            "14-Univ_Ain Témouchent   37-USTHB                 60-ESC_Alger          83-Univ_Soukahras    106-ENSF_Khenchla   \n"
            "15-Univ_Relizane         38-Univ_Bejaia           61-ENSSMAL_Alger      84-Univ_Annaba       107-hns-re2sd_Batna \n"
            "16-ENP_Oran              39-Univ_Boumerdes        62-ENSM_Kolea         85-Univ_Skikda       108-ENS_Ouargla     \n"
            "17-Esi_Sba               40-Univ_Tiziouzou        63-ENST_Alger         86-Univ_Guelma       109-ENS_Bousaada    \n"
            "18-Ese_Oran              41-Univ_Blida1           64-ensjsi_Alger       87-Univ_Batna1       110-ENS_Setif       \n"
            "19-ESGEE_Oran            42-Univ_Blida2           65-ENSSP_Alger        88-Univ_Biskra       111-ENSET_Skikda    \n"
            "20-ENS_Oran              43-Univ_Alger1           66-ESSAIA_ Alger      89-Univ_Msila        112-ENS_Constantine \n"
            "21-ENS_Bechar            44-Univ_Alger2           67-ESSA_Alger         90-Univ_Ouargla                          \n"
            "22-ENS_Mostaganem        45-Univ_Alger3           68-ESGEN_Alger        91-Univ-emir-const                       \n"
            "23-Esa_Mostaganem        46-UFC                   69-ESTIN_Bejaia       92-Univ_Setif1                           \n");
    printf("Votre reponse:\t ");
    scanf("%d",&EU);
    while (EU > 112){
        printf("\tVous devez choisir entre 1 et 112, reessayez ici :\t");
        scanf("%d",&EU);}
    printf("\tVeuillez preciser l'intervalle d'anciennete:\n");
    printf("\t\tEntre :\t");
    scanf("%d", &MIN);
    printf("\t\tEt :\t");
    scanf("%d", &MAX);
    if (MAX >= MIN){
        f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
        printf("\n   Matricule     |             Nom               |            Prenom             |\n");
        while(x <= entete(f,1) && (x != -1) ){
                Color(1,15);
            LireDir(f,x,&buf);
            cout_lecture++;
            x = buf.suiv;
            for(j=1; j < buf.nb; j++){
                    if ((buf.t[j].etablissement_univ == EU)&&((2022 - buf.t[j].date_de_recrutement.annee) > MIN)
                    && ((2022 - buf.t[j].date_de_recrutement.annee) < MAX)){
                    Color(1,15);
                    printf("%-8d \t | %-20.20s \t | %-20.20s \t  \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom);

                    }}
            }



    }

    else{
        Color(12,0);
        printf("Cet interval n'est pas valide!");
    }
    Fermer(f);
        break;
    }


    case 6:
    {
    system("cls");
    int region;
    printf("\n\nVeuillez entrer le numero de la region dont vous voulez consulter les enseignants exercant la bas: \n");
    printf("\n\t\t1 -Ouest\n"
           "\t\t2 -Centre\n"
           "\t\t3 -Est\n\n");
    printf("\n\tVotre reponse:\t");
    scanf("%d", &region);
    while (region > 3){
        printf("\tVous devez choisir entre 1 et 3, reessayez ici :\t");
        scanf("%d",&region);}
    f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
    Color(1,15);
    printf("\n\nConsultation des blocs:\n\n");
    Color(1,15);
    printf("\n   Matricule     |                  Nom                  |                 Prenom                |   Etablissement    \n");
    x=1;
    while((x <= entete(f,1)) && (x != -1)){
        Color(1,15);
        LireDir(f,x,&buf);
        cout_lecture++;
        x=buf.suiv;
        for(j=1; j<buf.nb; j++){
            if(region == 1)
            {
                if((buf.t[j].etablissement_univ >= 1 && buf.t[j].etablissement_univ <=30))
                    printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom,Etab_Univ[buf.t[j].etablissement_univ]);
            }
            else if(region == 2)
            {
                if(buf.t[j].etablissement_univ >= 31 && buf.t[j].etablissement_univ <=75)
                    printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom,Etab_Univ[buf.t[j].etablissement_univ]);
            }
            else if(region == 3)
            {
                    if(buf.t[j].etablissement_univ >= 76 && buf.t[j].etablissement_univ <=112)
                        printf("%-8d \t | %-30.20s \t | %-30.20s \t | %-30s \t\n", buf.t[j].matricule , buf.t[j].nom , buf.t[j].prenom,Etab_Univ[buf.t[j].etablissement_univ]);
            }

        }
    }
    Fermer(f);
    break;
    }

    case 7:{
        system("cls");
    fichg *g;
    Codage("ENSEIGNANTS-MESRS.bin");
    printf("Affichage du 1er bloc du fichier code: \n");
    f=Ouvrir("Fichier_code.bin",'a');
    LireDir(f,x,&buf);
    for(j=1; j<=buf.nb; j++){
        Color(0,15);

    Color(9,15);
    printf("%-10d|%-10.10s|%-10.10s|%3.2d/%4.2d/%5.4d|%4.2d/%4.2d/%5.4d |\n",
           buf.t[j].matricule,
           buf.t[j].nom,
           buf.t[j].prenom,
           buf.t[j].date_de_naissance.jour,
           buf.t[j].date_de_naissance.mois,
           buf.t[j].date_de_naissance.annee
           );
    }
    Color(0,15);

    Decodage();
    printf("Affichage du fichier apres decodage : \n");
    int x = 1;
    f=Ouvrir("Fichier_decode.bin",'a');
    Color(0,15);
    printf("\n");
    printf("\t  |  |   \n"
           "\t  |  |   \n"
           "\t _|__|_  \n"
           "\t \\    /   \n"
           "\t  \\  /    \n"
           "\t   \\/     \n");
    while(x<=entete(f,1)){
    LireDir(f,x,&buf);
    printf("     _______________\n"
           "    | Bloc numero %d |\n",x);
           printf("\n");
    Color(9,15);
           printf("Matricule |Nom       |Prenom    |Date_naissance|Wilaya_Naissance  |sexe    |G-S|Date_Recrutement|Grade             |Dernier_Diplome           |Specialite                |Etablissement_Univ      \n");
    Color(0,15);
           printf("__________ __________ __________ ______________ __________________ ________ ___ ________________ __________________ __________________________ __________________________ ____________________\n");
    printf("\n");
    x++;
    for(j=1; j<=buf.nb; j++){
        Color(0,15);

    Color(9,15);
    printf("%-10d|%-10.10s|%-10.10s|%3.2d/%4.2d/%5.4d|%-18.18s|%-8.8s|%-2.2s |%4.2d/%4.2d/%5.4d |%-18.18s|%-26.26s|%-26.26s|%-23s \n",
           buf.t[j].matricule,
           buf.t[j].nom,
           buf.t[j].prenom,
           buf.t[j].date_de_naissance.jour,
           buf.t[j].date_de_naissance.mois,
           buf.t[j].date_de_naissance.annee,
           Wilaya_Naissance[buf.t[j].wilaya_de_naissance],
           Sexe[buf.t[j].sexe],
           Groupe_Sanguin[buf.t[j].groupe_sanguin],
           buf.t[j].date_de_recrutement.jour,
           buf.t[j].date_de_recrutement.mois,
           buf.t[j].date_de_recrutement.annee,
           Grade[buf.t[j].grade],//
           Dernier_Diplome[buf.t[j].dernier_diplome],
           Specialite[buf.t[j].specialite],//specialite
           Etab_Univ[buf.t[j].etablissement_univ]);//etab_univ
    }
    Color(0,15);
           printf("__________ __________ __________ ______________ __________________ ________ ___ ________________ __________________ _________________________ _________________________ ____________________\n");
    printf("\n");
    printf("\n");
    printf("\t Suivant  \n"
           "\t  |  |   \n"
           "\t  |%d|   \n"
           "\t _|__|_  \n"
           "\t \\    /   \n"
           "\t  \\  /    \n"
           "\t   \\/     \n", buf.suiv);

    }

    break;
    }


    case 8:
    {
    system("cls");
    int x = 1;

    printf("\n\n\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n"
           "\t\t\t\t\t\t\t|R|E|P|R|E|S|E|N|T|A|T|I|O|N| |G|R|A|P|H|I|Q|U|E|\n"
           "\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+\n");
    f=Ouvrir("ENSEIGNANTS-MESRS.bin",'a');
Color(0,15);
    printf("\n");
    printf("\t  |  |   \n"
           "\t  |  |   \n"
           "\t _|__|_  \n"
           "\t \\    /   \n"
           "\t  \\  /    \n"
           "\t   \\/     \n");
    while(x<=entete(f,1)){
    LireDir(f,x,&buf);
    cout_lecture++;
    printf("     _______________\n"
           "    | Bloc numero %d |\n",x);
           printf("\n");
    Color(9,15);
           printf("Matricule |Nom       |Prenom    |Date_naissance|Wilaya_Naissance  |sexe    |G-S|Date_Recrutement|Grade             |Dernier_Diplome           |Specialite                |Etablissement_Univ      \n");
    Color(0,15);
           printf("__________ __________ __________ ______________ __________________ ________ ___ ________________ __________________ __________________________ __________________________ ____________________\n");
    printf("\n");
    x++;
    for(j=1; j<=buf.nb; j++){
        Color(0,15);

    Color(9,15);
    printf("%-10d|%-10.10s|%-10.10s|%3.2d/%4.2d/%5.4d|%-18.18s|%-8.8s|%-2.2s |%4.2d/%4.2d/%5.4d |%-18.18s|%-26.26s|%-26.26s|%-23s \n",
           buf.t[j].matricule,
           buf.t[j].nom,
           buf.t[j].prenom,
           buf.t[j].date_de_naissance.jour,
           buf.t[j].date_de_naissance.mois,
           buf.t[j].date_de_naissance.annee,
           Wilaya_Naissance[buf.t[j].wilaya_de_naissance],
           Sexe[buf.t[j].sexe],
           Groupe_Sanguin[buf.t[j].groupe_sanguin],
           buf.t[j].date_de_recrutement.jour,
           buf.t[j].date_de_recrutement.mois,
           buf.t[j].date_de_recrutement.annee,
           Grade[buf.t[j].grade],//
           Dernier_Diplome[buf.t[j].dernier_diplome],
           Specialite[buf.t[j].specialite],//specialite
           Etab_Univ[buf.t[j].etablissement_univ]);//etab_univ
    }
    Color(0,15);
           printf("__________ __________ __________ ______________ __________________ ________ ___ ________________ __________________ __________________________ __________________________ ____________________\n");
    printf("\n");
    printf("\n");
    printf("\t Suivant  \n"
           "\t  |  |   \n"
           "\t  |%d|   \n"
           "\t _|__|_  \n"
           "\t \\    /   \n"
           "\t  \\  /    \n"
           "\t   \\/     \n", buf.suiv);

    }
    break;
    }

    default:
        printf("Ce choix ne figure pas dans le menu!\n Veuillez choisir une autre fois");
}
// Affichage a la fin du programme
Color(9,15);
printf("\n\nLES COUTS: \n COUT DE LECTURES: %-4d   \n COUT D'ECRITURE:  %-4d\n",cout_lecture,cout_ecriture);
Color(9,15);
printf("\n\n\t\tVoulez vous:");
printf("\t\t\t1- Continuer \t\t 2- Sortir\n");
scanf("%d",&continu);
system("cls");
}
creation_index("index.bin",NE+nb,tab);//mise a jour du fichier index
printf("\n\n");
Color(9,15);
printf("\n\n\t\t\t\t\t\t\t\t\tFIN DU PROGRAMME\n\n\n\n\t\t\t\t\t\t\t\tVOTRE COUT DE LECTURE TOTALE: %d\n\n\t\t\t\t\t\t\t\tVOTRE COUT D'ECRITURE TOTALE: %d\n\n\n\n\n\n\n",cout_lecture,cout_ecriture);
Color(9,15);
printf("\n\n\n\n\n\n\t\t\t\t_  _ ____ ____ ____ _    ___  ____ _  _ ____    _  _ ____ ___ ____ ____    ____ ___ ___ ____ _  _ ___ _ ____ _  _ \n"
       "\t\t\t\t|\\/| |___ |__/ |    |    |__] |  | |  | |__/    |  | |  |  |  |__/ |___    |__|  |   |  |___ |\\ |  |  | |  | |\\ | \n"
       "\t\t\t\t|  | |___ |  \\ |___ |    |    |__| |__| |  \\     \\/  |__|  |  |  \\ |___    |  |  |   |  |___ | \\|  |  | |__| | \\| \n");
Color(9,15);
printf("\n\n\n\n\t\t\t\t\t\t\t On remercie touts les efforts fournis par nos chers enseignants\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}
