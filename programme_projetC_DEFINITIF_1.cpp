//DERNIERE MISE A JOUR mardi 21-05  02:27
#include <stdio.h>
#include <string.h>
#include <conio-bis.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define droite 77
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define gauche 75
#define vert textcolor(10);
#define blanc textcolor(15);


struct recherche {
int numero; // le numero de client
char nom[40];//nom du client
int position; // position de la fiche dans le fichier principal
};


struct date{
	char jour[3];
	char mois[3];
	char annee[5];
};
struct fiche {
     char type_client[12];
     char nom_agence[40];
	 char type_prestation[15];
	 int num_client;
     char nom_complet [40];
     char adresse [40];
     char cod_pos [5];
     char localite [20];
     char telephone [15];
     char gsm [15];
     char e_mail [50];
     int qte_adultes_allee;
     int qte_enfants_allee;
     int qte_adultes_retour;
     int qte_enfants_retour;
	 int siege_bebe;
     int rehausseur;
     struct date allee;
     char lieu_depose [50];
     char heure_prise_en_charge[6];
     char allee_numero_vol [20];
     char heure_decollage[6];
     char destination_vol[40];
     struct date retour;
     char lieu_retour [50];
     char heure_arrivee[6];
     char retour_numero_vol [20]; 
     char provenance_vol[40];
     float prix_total;
     short supp;
};

void retour_menu(char,char);
void cadre_affichage(char,int,int,int,int);
void ecran(int);
void interfacedebut(char,char*,int,int,int*,int*,int*,int*);
//void appeler(int,char);
void cadre(int ,int , int , int , int );
void gotoxy(int x, int y);
void window(int left,int top,int rignt, int bottom);
void affichage_tarifs(char [][20],int,char [][5],int,char[][30],float[][3]);
void devis(char*,int);
struct fiche reservation_saisie();
void control_saisie(char *,int);
float calcul_parcours_special(float);
int menu_choix(char *,int,int,int,int);
void affiche_choix_menu(char *,int,int,int,int,int);
void verification_date(struct fiche *,char*,char,int,int,int);
int validation_date(struct fiche*,char*,char);
int saisie_heure(char *, int, int);
float definition_parcours(char*,int,float,float*,int,int,int);
int def_type_prestation(int,int);
int passagers_simple_prestation(int,int,char);
void saisie_donnees_prestation(struct fiche *,int,char);
float calcul_prix_final(int,int,float,float); 
void modification_reservation(struct fiche *);
void suppression_reservation(struct fiche *);
void consult_reservations(struct fiche);
void consult_supprimees(struct fiche);
void consult_executees(struct fiche);
void affiche_par_numclient(struct fiche,int,int,char);
void en_tete(struct fiche ,int);
int recherche(int,struct fiche);
void affiche_retour(struct fiche,int);
void affiche_allee(struct fiche,int);
void affiche_critere(struct fiche,int,char*);
int menu_choix_critere(char *choix);
int creation_index(struct recherche*,struct fiche);
void tri(struct recherche*,int);
char affiche_index(struct recherche*,int);
int saisie_num();
int verif_num_client(struct fiche);
void modif(int,char*);
int define_champ_modifier(int ,char*);

int main()
{	
	char menu_principal[5][30]={"DEVIS","RESERVATION","TARIFS","CONSULTATION","QUITTER"};
 	char affich_encodage[4][30]={"ENCODER UNE RESERVATION","MODIFIER UNE RESERVATION","SUPPRIMER UNE RESERVATION","RETOUR MENU"};
 	char affich_consultation[3][26]={"CONSULTATION PAR CRITERE","RESERVATIONS SUPPRIMEES","RETOUR MENU"};
	
	char titres_tarifs[5][20]={"CDE POSTAL","LOCALITE","ZAVENTEM","CHARLEROI","LILLE-LESQUIN"};
    char codes_postaux[20][5]={"1400","7000","7040","7060","7080","7090","7100","7130","7180","7330",
                               "7500","7600","7640","7760","7800","7850","7860","7890","7900","7970"};

    char localites[20][30]={"NIVELLES","MONS","QUEVY","SOIGNIES","FRAMERIES","BRAINE-LE-COMPTE","LA LOUVIERE",
                             "BINCHE","SENEFFE","SAINT GHISLAIN","TOURNAI","PERUWELZ","ANTOING","CELLES",
                             "ATH","ENGHIEN","LESSINES","ELLEZELLES","LEUZE-EN-HAINAUT","BELOEIL"};

    float tarifs[20][3]={{40.00,32.00,85.00},{55.00,40.00,54.00},{64.50,37.00,70.00},{49.00,30.00,65.00},
                         {58.50,37.80,61.00},{42.00,29.00,84.00},{43.00,25.00,88.00},{50.00,26.00,85.50},
                         {38.00,19.00,87.50},{61.00,40.00,63.00},{75.00,65.10,42.00},{85.00,55.00,56.00},
                         {79.00,62.00,50.00},{73.00,75.00,38.50},{56.00,47.00,45.00},{52.00,45.00,63.00},
                         {62.50,48.00,45.50},{65.00,54.00,42.00},{70.50,59.00,35.00},{60.50,45.50,47.50}};  
	
	int posgot_R1[4]={30,32,29,35},posgot_R2[4]={12,15,18,21},poscadre_R[4]={11,14,17,20},k_R[4]={10,13,16,19};
	
	int posgot_C1[3]={29,31,36},posgot_C2[3]={12,15,18},poscadre_C[3]={11,14,17},k_C[4]={10,13,16};
	
	char font_appel;

	ecran(1);
	int x,i,ok,ok1,posgotoxy1[5]={37,36,37,34,36},posgotoxy2[5]={12,15,18,21,24},poscadre[5]={11,14,17,20,23},k[5]={10,13,16,19,22};
	ok=0;
	ok1=0;
    while(ok1==0)
    { 
	 do
     {
      //menudemarrer();

           for(i=0;i<5;i++)
           {  
               cadre(30,poscadre[i],18,2,k[i]);
               if(i==1 && ok==0)
               {    
                    ok=1;
                    gotoxy(posgotoxy1[i]-=2,posgotoxy2[i]);
                    textcolor(2);
                     cprintf("%s",menu_principal[i]);
               }
               else
               {
                    gotoxy(posgotoxy1[i],posgotoxy2[i]);
                    textcolor(2);
                    cprintf("%s",menu_principal[i]);
               }
           }
	 	i=0;

           do
           {
               cadre(30,poscadre[i],18,2,k[i]);
               gotoxy(posgotoxy1[i],posgotoxy2[i]);
               highvideo();
               cprintf("%s",menu_principal[i]);
               normvideo();
               x=getch();
               if(x==224)
               {
                    x=getch();
                    if(x==KEY_DOWN)
                    {
                         cadre(30,poscadre[i],18,2,k[i]);
                         gotoxy(posgotoxy1[i],posgotoxy2[i]);
                         textcolor(2);
                         cprintf("%s",menu_principal[i]);
                         i++;
                         if(i==5)
                         i=0;
                    }
                    if(x==KEY_UP)
                    {
                         cadre(30,poscadre[i],18,2,k[i]);
                         gotoxy(posgotoxy1[i],posgotoxy2[i]);
                         textcolor(2);
                         cprintf("%s",menu_principal[i]);
                         i--;
                         if(i==-1) i=4;
                    }
               }

           }while(x!=13); 

     	if(x==13)
    	{     clrscr();
			switch (i+1)
        	{
				case 1: ok1=1;
						clrscr();devis(&codes_postaux[0][0],5);
                    	break;
            	case 2: ok1=1;
						clrscr();
						font_appel='R';
						interfacedebut(font_appel, &affich_encodage[0][0], 30, 4, posgot_R1, posgot_R2, poscadre_R, k_R);
						break;
            	case 3: ok1=1;
						clrscr();
						affichage_tarifs(titres_tarifs,5,codes_postaux,20,localites,tarifs);
                    	break;
            	case 4: ok1=1;
						clrscr();
						font_appel='C';
						interfacedebut(font_appel,&affich_consultation[0][0],26,3,posgot_C1,posgot_C2,poscadre_C,k_C);
						break;
            	case 5: exit(0);break;
            }
		}
   	  clrscr();
  	 }while(i!=3);
   }
fflush(stdin);
getchar();
return(0);
}


void ecran(int Mode)  /*parametre Mode : 1=plein ecran et 2=mode fen?tre*/
{    typedef BOOL WINAPI(*SetConsoleDisplayModeT)(HANDLE,DWORD,DWORD*);
     SetConsoleDisplayModeT SetConsoleDisplayMode;

     HINSTANCE hLib=LoadLibrary("KERNEL32.DLL");
     SetConsoleDisplayMode=(SetConsoleDisplayModeT)
     GetProcAddress(hLib,"SetConsoleDisplayMode");

     HANDLE
     h=CreateFile("CONOUT$",GENERIC_WRITE|GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,0);
     DWORD oldmode;
     SetConsoleDisplayMode(h,Mode,&oldmode);
}

void cadre(int debutcol,int debutlig, int nbrcol, int nbrlig, int nbrk)
{
int i,j,k;


    gotoxy(debutcol,debutlig);
    printf("%c",201);

    for(i=0;i<nbrcol-1;i++)
    {
        printf("%c",205);
    }
    printf("%c",187);


k=nbrlig+nbrk;

    for(i=0;i<nbrlig-1;i++)
    {
        gotoxy(debutcol,k);
        printf("%c",186);
        for(j=0;j<nbrcol-1;j++)
        {
            printf(" ");
        }
        printf("%c",186);
        k++;
    }

    gotoxy(debutcol,k);
    printf("%c",200);

    for(i=0;i<nbrcol-1;i++)
    {
        printf("%c",205);
    }
printf("%c",188);
}//fin cadre


void interfacedebut(char font_appel,char *tab,int col,int max,int *posgotoxy1,int *posgotoxy2,int *poscadre,int *k)
{
    int ok1;

	struct fiche resv_client;
	
	int x,i,ok;//posgotoxy1[5]={37,36,37,37,36},posgotoxy2[5]={12,15,18,21,24},poscadre[5]={11,14,17,20,23},k[5]={10,13,16,19,22};
	ok=0;
	ok1=0;
    while(ok1==0)
    {
		do
     	{
      	//menudemarrer();

           		for(i=0;i<max;i++)
           		{  
               		cadre(25,poscadre[i],32,2,k[i]);
               		if(i==1 && ok==0)
               		{    
                    	ok=1;
                    	gotoxy(posgotoxy1[i]-=2,posgotoxy2[i]);
                    	textcolor(2);
                    	cprintf("%s",(tab+i*col));
               		}
               		else
               		{
                    	gotoxy(posgotoxy1[i],posgotoxy2[i]);
                    	textcolor(2);
                    	cprintf("%s",(tab+i*col));
               		}
           		}
	 			i=0;

           		do
           		{
              	 	cadre(25,poscadre[i],32,2,k[i]);
               	 	gotoxy(posgotoxy1[i],posgotoxy2[i]);
               	 	highvideo();
              	 	cprintf("%s",(tab+i*col));
              	 	normvideo();
               	 	x=getch();
               	 	if(x==224)
               	 	{
                    	x=getch();
                    	if(x==KEY_DOWN)
                    	{
                         	cadre(25,poscadre[i],32,2,k[i]);
                        	gotoxy(posgotoxy1[i],posgotoxy2[i]);
                         	textcolor(2);
                        	cprintf("%s",(tab+i*col));
                        	i++;
                         	if(i==max)
                        	i=0;
                    	}
                    	if(x==KEY_UP)
                    	{
                         	cadre(25,poscadre[i],32,2,k[i]);
                         	gotoxy(posgotoxy1[i],posgotoxy2[i]);
                         	textcolor(2);
                         	cprintf("%s",(tab+i*col));
                         	i--;
                         	if(i==-1) i=max-1;
                    	}
               		}

           		}while(x!=13); 

     		if(x==13)
    		clrscr();  
    

          		if(font_appel=='R')
          		{			
				  switch (i+1)
    			  {
		    			case 1: ok1=1;
								clrscr();
								resv_client=reservation_saisie();
                    			break;
            			case 2: ok1=1;
								clrscr();modification_reservation(&resv_client);
								break;
            			case 3: ok1=1;
								clrscr();suppression_reservation(&resv_client);
                    			break;
                    	case 4: ok=1;
                    			clrscr();main();
                    			break;
          		  } 	
		  		}
				else if(font_appel=='C')		
		  		{	
				  switch (i+1)
    			  {
					case 1: clrscr();
							consult_reservations(resv_client);
							break;
            		case 2: clrscr();
							consult_supprimees(resv_client);
							break;
					case 3: clrscr();
							consult_executees(resv_client);
							break;
				    case 4: ok=1;
                    		clrscr();main();
                    		break;
				  }
				}
      

		 clrscr();
    	 }while(i!=4);
    }
 }

//FONCTION DEVIS 
void devis(char *codes_postaux,int col_cp)
{
float tarifs[20][3]={{40.00,32.00,85.00},{55.00,40.00,54.00},{64.50,37.00,70.00},{49.00,30.00,65.00},
                     {58.50,37.80,61.00},{42.00,29.00,84.00},{43.00,25.00,88.00},{50.00,26.00,85.50},
                     {38.00,19.00,87.50},{61.00,40.00,63.00},{75.00,65.10,42.00},{85.00,55.00,56.00},
                     {79.00,62.00,50.00},{73.00,75.00,38.50},{56.00,47.00,45.00},{52.00,45.00,63.00},
                     {62.50,48.00,45.50},{65.00,54.00,42.00},{70.50,59.00,35.00},{60.50,45.50,47.50}};


char tab_choix_dest[4][25]={"Bruxelles National","Aeroport de Charleroi","Lille Lesquin","Autre"};
char tab_choix_typeClient[3][15]={"Particulier","Entreprise","Agence"};
char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
char rep_1,rep_2,type;
char codpos[5];
char f_appel='D';
char typ_affiche;
int ancpos, anci,pos,i,touche,max=5,choix_destination,nbre_adultes,nbre_enfants,type_client;
int adultes_allee,enfants_allee,adultes_retour,enfants_retour,ok,j,choix;
float prix_km= 0.7,prix_base,reduct,prix_adultes,prix_enfants,prix_final;

clrscr();
cadre_affichage(f_appel,1,1,79,24);

     
      gotoxy(4,6);
      textcolor(10);
      cprintf("Code postal de depart :\n");
      gotoxy(28,6);
      textcolor(15);
      control_saisie(codpos,4);
      gotoxy(28,6);
      clreol();
	  gotoxy(28,6);
	  cprintf("%s",codpos);
	  
	  gotoxy(35,6);
      textcolor(10);
      cprintf("Choix destination : ");
      textcolor(15);
      choix_destination= menu_choix(&tab_choix_dest[0][0],25,4,55,6);
   	  affiche_choix_menu(&tab_choix_dest[0][0],25,4,choix_destination,55,6);
	
	  gotoxy(4,8);
	  textcolor(10);
	  cprintf("Type de client : ");
	  textcolor(15);
	  type_client= menu_choix(&tab_choix_typeClient[0][0],15,3,23,8);
	  affiche_choix_menu(&tab_choix_typeClient[0][0],15,3,type_client,23,8);
	  
		 
	  
	/* Ici on demande d'entrer le code postal et la destination pour definir le 
	   type de parcour, si le code et la destination se trouvent dans le tab tarifs
	   c'est PARCOURS NORMAL sinon on demande le kilometres à parcourir pour calculer
	   le prix de base par personne  */
	  
	  prix_base=definition_parcours(codpos,choix_destination,prix_km,&tarifs[0][0],3,4,10);
/*	 gotoxy(4,14);
	 printf("%.2f",prix_base);
	  
	/* appel de la fonction type_prestation pour definir si sera un aller simple 
	   ou un aller / retour */
	  gotoxy(4,15);
	  textcolor(10);
	  choix=def_type_prestation(25,15); 
  /*	  gotoxy(3,20);
	  printf("%s",type_prestation[choix]);  */
	  typ_affiche='m';
	  retour_menu(f_appel,typ_affiche);
	  Sleep(200);
	  clrscr();
	  cadre_affichage(f_appel,1,1,79,24);

    if (choix!=2)
    {
			type='A';
			nbre_adultes= passagers_simple_prestation(3,5,type);
  
    		type='E';
			nbre_enfants=passagers_simple_prestation(3,5,type);
       	
//CONTROLE    gotoxy(1,1);  printf("%d     %d",nbre_adultes,nbre_enfants);
    } 
    else
    {
        gotoxy(3,6);
        textcolor(10);
        cprintf("Meme nombre de passager allee / retour? (o/n): ");
        textcolor(15);
        scanf("%c",&rep_1);  
        fflush(stdin);
        if(rep_1=='o')
        {
            type='A';
         	nbre_adultes= passagers_simple_prestation(3,9,type)*2;
            type='E';
            nbre_enfants= passagers_simple_prestation(3,9,type)*2;
           	
//CONTROLE
			 // gotoxy(1,1); printf("%d     %d",nbre_adultes,nbre_enfants);
        }
        else
        {
           gotoxy(3,9);
           textcolor(10);
           cprintf("ALLER");
           
		   type='A';
           adultes_allee= passagers_simple_prestation(3,11,type);
           
		   type='E';
           enfants_allee= passagers_simple_prestation(3,11,type);
           
           gotoxy(42,9);
		   textcolor(10);
           cprintf("RETOUR");
           
		   type='A';
           adultes_retour= passagers_simple_prestation(42,11,type);
           
		   type='E';
           enfants_retour= passagers_simple_prestation(42,11,type);
           
		   nbre_adultes=adultes_allee + adultes_retour;
           nbre_enfants=enfants_allee + enfants_retour;
          
//CONTROLE
	    //gotoxy(1,1);
	    //printf("%d\t %d\t %d\t %d\t %d\t %d",adultes_allee,enfants_allee,adultes_retour,enfants_retour,nbre_adultes,nbre_enfants);
        }
           
    }//fin else
          
			if(choix==2)
		  	gotoxy(3,16);
		  else
		  	gotoxy(3,10);
		  
		  textcolor(10);
		  cprintf("Est ce un nouveau client (o/n)? :  ");
		  textcolor(15);
		  scanf("%c",&rep_2);
		  fflush(stdin);
	 
		
	  		Sleep(200);
	 		clrscr();
	 		cadre_affichage(f_appel,1,1,79,24);
	 
		 
		//  calcul du prix final

 		  //definition de la reduction
		   if(type_client==1)  // choix indice 1 = ENTREPRISE
		   {
		   		if(rep_2=='o')
				   	reduct=1.0;
				else
				   	reduct=0.95;
		   } 
		   else if(type_client==2)  //AGENCE
		   {
		   		if(rep_2=='o')
				   	reduct=1.0;
				else
				   	reduct=0.92;
		   }
			else if(type_client==0)//PARTICULIER
			{
				if(rep_2=='o')
					reduct=1.0;
				else
					reduct=0.9;
		    }
				prix_adultes=((nbre_adultes * prix_base)*reduct);
          		prix_enfants=((nbre_enfants * prix_base)*0.5);
          		prix_final=(prix_adultes + prix_enfants);

		        	
		  gotoxy(10,10);
          textcolor(14);
          cprintf("TOTAL A PAYER");
		  gotoxy(10,13);
		  cprintf("ENFANTS =    ");
		  textcolor(15);
		  cprintf("%.2f",prix_enfants);    
		  textcolor(14);
		  gotoxy(10,15);
		  cprintf("ADULTES =    ");
		  textcolor(15);
		  cprintf("%.2f",prix_adultes);
		  gotoxy(9,16);
		  textcolor(14);
		  cprintf("___________________________");
          gotoxy(10,18);
		  cprintf("PRIX TOTAL=  ");
		  textcolor(15);
		  cprintf("%.2f euros",prix_final);
		  Sleep(1000);
		  gotoxy(10,24);
		  typ_affiche='f';
		  retour_menu(f_appel,typ_affiche);
}//FIN FONCTION DEVIS



//FONCTION POUR SAISIR LES DONNEES DANS L'STRUCTURE
struct fiche reservation_saisie()
{
struct fiche reservation;
float tarifs[20][3]={{40.00,32.00,85.00},{55.00,40.00,54.00},{64.50,37.00,70.00},{49.00,30.00,65.00},
                     {58.50,37.80,61.00},{42.00,29.00,84.00},{43.00,25.00,88.00},{50.00,26.00,85.50},
                     {38.00,19.00,87.50},{61.00,40.00,63.00},{75.00,65.10,42.00},{85.00,55.00,56.00},
                     {79.00,62.00,50.00},{73.00,75.00,38.50},{56.00,47.00,45.00},{52.00,45.00,63.00},
                     {62.50,48.00,45.50},{65.00,54.00,42.00},{70.50,59.00,35.00},{60.50,45.50,47.50}};


FILE *ptr;
float prix_km= 0.7,prix_base,prix_enfants,prix_adultes,prix_final,reduct;
char c_postal[5];
int numero,choix,nbre_adultes,nbre_enfants,type_client;
int heure_ok=0,ok1;
char tab_choix_typeClient[3][15]={"Particulier","Entreprise","Agence"};
char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
char rep;
char typeAffich;
char f_appel='R';
char typ_affiche;
char rep_3;
	clrscr();
	cadre_affichage(f_appel,1,1,79,24);

ptr=fopen("reservation_clients.dat","ab+");	
if(ptr==NULL)
{
	gotoxy(20,10);
	printf("Probleme de connexion à la base de donnees ");
}
else
{	
/*	gotoxy(28,2);
	textcolor(14);
	cprintf("ENCODAGE RESERVATIONS");  */
	
	gotoxy(4,6);
	textcolor(10);
	cprintf("Type de client : ");
	textcolor(15);
	type_client= menu_choix(&tab_choix_typeClient[0][0],15,3,23,6);
	affiche_choix_menu(&tab_choix_typeClient[0][0],15,3,type_client,23,6);

	strcpy(reservation.type_client,tab_choix_typeClient[type_client]);

	//cprintf("%s",reservation->type_client);      //CONTROLE 
	gotoxy(39,6);
	textcolor(10);
	if (type_client==2)
		cprintf("Est ce une nouvelle agence? (o/n) :  ");
	else
		cprintf("Est ce un nouveau client? (o/n) :  ");
	textcolor(15);
	scanf("%c",&rep);
	fflush(stdin);
	if(type_client==2)
	{
	    gotoxy(4,8);
		textcolor(10);
		cprintf("Nom de l'agence : ");
		textcolor(15);
		scanf("%[^\n]",reservation.nom_agence);
	}
	textcolor(10);
	gotoxy(4,10);
	choix=def_type_prestation(26,10);
	
//	gotoxy(3,22);
	typ_affiche='m';
	retour_menu(f_appel,typ_affiche);
	strcpy(reservation.type_prestation,type_prestation[choix]);
	clrscr();
	cadre_affichage(f_appel,1,1,79,24);
/*		gotoxy(28,2);
	textcolor(14);
	cprintf("ENCODAGE RESERVATIONS");  */
      gotoxy(3,4);
      textcolor(10);
      cprintf("DONNEES CLIENT");
      gotoxy(3,7);
      cprintf("Numero de client :");
      gotoxy(3,9);
      cprintf("Nom et prenom :");
      gotoxy(3,11);
      cprintf("Adresse et numero :");
      gotoxy(3,13);
      cprintf("Code postal :");
      gotoxy(3,15);
      cprintf("Localite :");
      gotoxy(3,17);
      cprintf("Telephone :");
      gotoxy(3,19);
      cprintf("GSM :");
      gotoxy(3,21);
      cprintf("e-mail :");

      
      //DONNEES CLIENTS
      gotoxy(25,7);
      textcolor(15);
      scanf("%d",&reservation.num_client);
      fflush(stdin);
      gotoxy(21,9);
      scanf("%[^\n]",reservation.nom_complet);
      fflush(stdin);
      gotoxy(25,11);
      scanf("%[^\n]",reservation.adresse);
      fflush(stdin);
      gotoxy(19,13);
      control_saisie(c_postal,4);
      strcpy(reservation.cod_pos,c_postal);
      fflush(stdin);
      gotoxy(16,15);
      scanf("%[^\n]",reservation.localite);
      fflush(stdin);
      gotoxy(17,17);
      scanf("%[^\n]",reservation.telephone);
      fflush(stdin);
      gotoxy(11,19);
      scanf("%[^\n]",reservation.gsm);
      fflush(stdin);
      gotoxy(15,21); 
      scanf("%s",reservation.e_mail);
      fflush(stdin);     
//Donnees prestation 
     typ_affiche='m';
	 retour_menu(f_appel,typ_affiche);
	  clrscr();
	  cadre_affichage(f_appel,1,1,79,24);
      if (choix==2) //choix 2 = type de prestation  "Aller / retour
      {
      	typeAffich='A';
	  	saisie_donnees_prestation(&reservation,choix,typeAffich); //choix= type de prestation
      	clrscr();
      	cadre_affichage(f_appel,1,1,79,24);
		typeAffich='R';
	  	saisie_donnees_prestation(&reservation,choix,typeAffich);
	  	      	clrscr();
      	cadre_affichage(f_appel,1,1,79,24);
	  //	printf("%d\t %d\t %d\t %d\t %d\t %d",reservation->qte_adultes_allee,reservation->qte_enfants_allee,reservation->qte_adultes_retour,reservation->qte_enfants_retour,reservation->siege_bebe,reservation->rehausseur);
	  }
	  else  //aller simple ou retour simple
		{
		typeAffich='S';
	  	saisie_donnees_prestation(&reservation,choix,typeAffich);
	  	      	clrscr();
      	cadre_affichage(f_appel,1,1,79,24);
	  }
	//	printf("%d\t %d\t %d\t %d\t %d\t %d",reservation->qte_adultes_allee,reservation->qte_enfants_allee,reservation->qte_adultes_retour,reservation->qte_enfants_retour,reservation->siege_bebe,reservation->rehausseur);
     
	//retour_menu();
	 // printf("%d\t %d\t %d\t %d\t %d\t %d",reservation->qte_adultes_allee,reservation->qte_enfants_allee,reservation->qte_adultes_retour,reservation->qte_enfants_retour,reservation->siege_bebe,reservation->rehausseur);
	
	
	/* appel de la fonction definition_parcours pour connaitre le prix de base
	   à payer par personne */
	  prix_base=definition_parcours(c_postal,choix,prix_km,&tarifs[0][0],3,3,4);
	  
	  	//  calcul du prix final

 		  //definition de la reduction
		   if(type_client==1)  // choix indice 1 = ENTREPRISE
		   {
		   		if(rep=='o')
				   	reduct=1.0;
				else
				   	reduct=0.95;
		   } 
		   else if(type_client==2)  //AGENCE
		   {
		   		if(rep=='o')
				   	reduct=1.0;
				else
				   	reduct=0.92;
		   }
			else if(type_client==0)
			{
				if(rep=='o')
					reduct=1.0;
				else
					reduct=0.9;
		    }
				
				if(choix==0)
				{
					nbre_adultes= reservation.qte_adultes_allee;
					nbre_enfants= reservation.qte_enfants_allee;
				}
				else if(choix==1)
				{
					nbre_adultes= reservation.qte_adultes_retour;
					nbre_enfants= reservation.qte_enfants_retour;
				}
				else
				{
					nbre_adultes= reservation.qte_adultes_allee + reservation.qte_adultes_retour;
					nbre_enfants= reservation.qte_enfants_allee + reservation.qte_enfants_retour;
				}
				
				
				prix_adultes=((nbre_adultes * prix_base)*reduct);
          		prix_enfants=((nbre_enfants * prix_base)*0.5);
          		prix_final=(prix_adultes + prix_enfants);
          		reservation.prix_total=prix_final;
          		reservation.supp=0;

		        	
		  gotoxy(10,10);
          textcolor(14);
          cprintf("TOTAL A PAYER");
		  gotoxy(10,13);
		  cprintf("ENFANTS =    ");
		  textcolor(15);
		  cprintf("%.2f",prix_enfants);    
		  textcolor(14);
		  gotoxy(10,15);
		  cprintf("ADULTES =    ");
		  textcolor(15);
		  cprintf("%.2f",prix_adultes);
		  gotoxy(9,16);
		  textcolor(14);
		  cprintf("___________________________");
          gotoxy(10,18);
		  cprintf("PRIX TOTAL=  ");
		  textcolor(15);
		  cprintf("%.2f euros",prix_final);
		  gotoxy(10,21);
		  
   fwrite(&reservation,sizeof(reservation),1,ptr);
}
fclose(ptr);
		  //gotoxy(10,24);
		/*  typ_affiche='f';
		 retour_menu(f_appel,typ_affiche);*/
   
		  Sleep(200);
		  gotoxy(10,24);
		  typ_affiche='f';
		  retour_menu(f_appel,typ_affiche);
		  cadre_affichage(f_appel,1,1,80,24);
return reservation;
	 
}   //FIN FONCTION SAISIE_RESERVATION


//FONCTION POUR SAISIR DONNEES POUR L'ALLEE ET POUR LE RETOUR
void saisie_donnees_prestation(struct fiche *reservation,int choix,char type)
{    
	char lieux[4][30]={"Bruxelles National","Aeroport de Charleroi","Lille Lesquin","Autre"};
	char date_complete[11];
	char heure_complete[6];
	char typ_affiche;
	char f_appel='R';
	int choix_lieu,heure_ok=0; 

//Donnees prestation affichage  
    //  cadre_affichage(1,1,79,24);
	  gotoxy(30,4);
      textcolor(10);
      cprintf("DONNEES PRESTATION");
	  gotoxy(3,7);  textcolor(10);
      
	  if(type=='A')
	  		cprintf("ALLEE");
	  else if(type=='R')
	  		cprintf("RETOUR");

	  		gotoxy(3,10);
      		cprintf("Nombre d'adulte(s) :");
     	   	gotoxy(36,10);  textcolor(10);
      		cprintf("Nombre d'enfant(s) -10 ans :");
	  		gotoxy(3,12);  textcolor(10);
	  if(choix==0 || choix==1 || type=='A')
	  	{
	  		cprintf("siege(s) bebe(s) :");
		  	gotoxy(36,12); textcolor(10);
	      	cprintf("Rehausseur(s) :");
	    }
	  

      if(choix==0 || type=='A')
	  {
	  	gotoxy(26,10);
	  	textcolor(15);
		scanf("%d",&reservation->qte_adultes_allee);
      	fflush(stdin);
       	gotoxy(67,10);  textcolor(15);
        scanf("%d",&reservation->qte_enfants_allee);
        fflush(stdin);
	  }
	  else if (choix==1 || type=='R')
	  {
      	gotoxy(26,10);	textcolor(15);
	  	scanf("%d",&reservation->qte_adultes_retour);
      	fflush(stdin);
       	gotoxy(67,10);  textcolor(15);
        scanf("%d",&reservation->qte_enfants_retour);
        fflush(stdin);
	  }
      if (type=='S')
      {
      		if(choix==0)
      		{
      			reservation->qte_adultes_retour=-1;
      			reservation->qte_enfants_retour=-1;
        	}
		 	else if(choix==1)
		  	{
      			reservation->qte_adultes_allee=-1;
      			reservation->qte_enfants_allee=-1;
      		}
      }
      		
	  if(choix==0 || choix==1 || type=='A')
	  {
			gotoxy(26,12);  textcolor(15);
	  		scanf("%d",&reservation->siege_bebe);
      		fflush(stdin);
      		gotoxy(67,12); textcolor(15);
      		scanf("%d",&reservation->rehausseur);
      		fflush(stdin);
      }
     
    
      if(choix==0 || type=='A')
	  {
	    	gotoxy(3,15);  textcolor(10);
	    	cprintf("Date allee : ");
      		gotoxy(36,15);
      		cprintf("Lieu de depose : ");
      		gotoxy(3,17);
      		cprintf("Heure prise en charge : ");
      		gotoxy(3,19);
      		cprintf("Heure de decollage : ");
      		gotoxy(3,21);
      		cprintf("No de vol/train : ");
      		gotoxy(36,21);
      		cprintf("Destination : ");
	  
	  }
	  else if(choix==1 || type=='R')
	  {
	  		gotoxy(3,15);  textcolor(10);
			cprintf("Date retour : ");
      		gotoxy(36,15);
      		cprintf("Lieu d'arrivee : ");
      		gotoxy(3,17);
      		cprintf("Heure d'arrivee : ");
      		gotoxy(3,19);
      		cprintf("No de vol/train : ");
      		gotoxy(36,19);
      		cprintf("Provenance : ");
     }
	if(choix==0 || type=='A')
	{
	  		textcolor(15);
	  		verification_date(reservation,date_complete,type,17,33,15);/*17=pos gotoxy x1
      													   				33=pos gotoxy x2
      													   				15=pos gotoxy y  */
     
	  		gotoxy(36,15);
	  		textcolor(10);
	  		cprintf("Lieu de depose : "); 
	  		textcolor(15);
	  	/*appel de la fonc choix pour recuperer le choix du lieu de depose c-à-d
	    l'endroit où le client doit être déposé à l'allée*/
	
     		 choix_lieu= menu_choix(&lieux[0][0],30,4,53,15);
	  	  	gotoxy(53,15);
			clreol();
			gotoxy(79,15);
			textcolor(14);
			cprintf("%c",179);
			gotoxy(53,16);
			clreol();
			gotoxy(79,16);
			textcolor(14);
			cprintf("%c",179);
			gotoxy(53,17);
			clreol();
			gotoxy(79,17);
			textcolor(14);
			cprintf("%c",179);
			gotoxy(53,18);
			clreol();
			gotoxy(79,18);
			textcolor(14);
			cprintf("%c",179);
	  	if(choix_lieu==3) //si choix = 3 c-à-d "autre" on recupere la chaine entrée au clavier
	  	{
	  		
				gotoxy(53,15); 
		    	textcolor(15);
				scanf("%[^\n]",reservation->lieu_depose);
		    	fflush(stdin);
      	}
	  	else 
	  	{
	  			gotoxy(53,15);
		    	textcolor(15);
				strcpy(reservation->lieu_depose,lieux[choix_lieu]);
	  			cprintf("%s",reservation->lieu_depose);
	  	}
		
		    
	//appel à la foction saisie_heure pour verifiez que l'heure soit valide
	 	 do
	  	 {
	       		heure_ok=saisie_heure(heure_complete,27,17);
	  
	  	 }while(heure_ok==1);
	  
	  	 strcpy(reservation->heure_prise_en_charge,heure_complete);
	   
	  	 do
	  	 {
	      	 	heure_ok=saisie_heure(heure_complete,24,19);
	  
	  	 }while(heure_ok==1);
	  
	     strcpy(reservation->heure_decollage,heure_complete);
	  
	  	 gotoxy(23,21);
         scanf("%[^\n]",reservation->allee_numero_vol);
         fflush(stdin);
	     gotoxy(51,21);
         scanf("%[^\n]",reservation->destination_vol);
	     fflush(stdin);	
	 // Sleep(100);
	  	 clrscr();
	     cadre_affichage(f_appel,1,1,79,24);
    } //fin if(choix==0 || type=='A') allee

	else if(choix==1 || type=='R')
	{
	 	textcolor(15);
	 	verification_date(reservation,date_complete,type,17,33,15);/*17=pos gotoxy x1   //CHANGER DANS FOCTION DATE VERIFF POUR RETOUR
      													   			33=pos gotoxy x2
      													   			15=pos gotoxy y  */
     
	  	gotoxy(36,15);
	  	textcolor(10);
	  	cprintf("Lieu d'arrivee : "); 
	  	textcolor(15);
	  /*appel de la fonc choix pour recuperer le choix du lieu d'arrivee c-à-d
	    l'endroit où il faudra aller chercher le client*/
	
      	choix_lieu= menu_choix(&lieux[0][0],30,4,54,15);
	  	  	gotoxy(54,15);
			clreol();
			gotoxy(79,15);
			textcolor(14);
			cprintf("%c",179);
			gotoxy(54,16);
			clreol();
		    gotoxy(79,16);
			textcolor(14);
			cprintf("%c",179);
			gotoxy(54,17);
			clreol();
			gotoxy(79,17);
			textcolor(14);
			cprintf("%c",179);			
			gotoxy(54,18);
			clreol();
			gotoxy(79,18);
			textcolor(14);
			cprintf("%c",179);
	  	if(choix_lieu==3) //si choix = 3 c-à-d "autre" on recupere la chaine entrée au clavier
	  	{
	  		
			gotoxy(54,15); 
		    textcolor(15);
			scanf("%[^\n]",reservation->lieu_retour);
		    fflush(stdin);
     	 }
	  	 else 
	  	 {
	  		strcpy(reservation->lieu_retour,lieux[choix_lieu]);
	  		gotoxy(54,15);
	  		textcolor(15);
			cprintf("%s",reservation->lieu_retour);
	  	 }
		
		    
	//appel à la foction saisie_heure pour verifiez que l'heure soit valide
      	 do
	  	 {
	       	heure_ok=saisie_heure(heure_complete,21,17);
	  
	  	 }while(heure_ok==1);
	  
	  	 strcpy(reservation->heure_arrivee,heure_complete);
	   
	  	 gotoxy(23,19);
      	 scanf("%[^\n]",reservation->retour_numero_vol);
      	 fflush(stdin);
	  	 gotoxy(49,19);
      	 scanf("%[^\n]",reservation->provenance_vol);
	  	 fflush(stdin);
 	
	}

}
			
//FONCTION POUR DEFINIR LE TYPE DE PRESTATION SOIT SIMPLE OU ALLEE / RETOUR
int def_type_prestation(int pos_x,int pos_y)
{
	int choix;
	char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
	cprintf("Type de prestation : ");
	textcolor(15);
	choix= menu_choix(&type_prestation[0][0],15,3,pos_x,pos_y);
	affiche_choix_menu(&type_prestation[0][0],15,3,choix,pos_x,pos_y);
	fflush(stdin); 
	return choix;
}

//FONCTION POUR DEFINIR LE NOMBRE DE PASSAGERS
int passagers_simple_prestation(int pos_x,int pos_y,char type)
{    
int nbre;
	if(type=='A')
	{
       gotoxy(pos_x,pos_y);
       textcolor(10);
       cprintf("Nombre d'adultes: ");
	   textcolor(15);
	   scanf("%d",&nbre);
	   fflush(stdin);
    }
	else
    {
	   gotoxy(pos_x,pos_y+2);
       textcolor(10);
       cprintf("Nombre d'enfants (-10 ans): "); 
       textcolor(15);
       scanf("%d",&nbre);
       fflush(stdin);
    }
	   return nbre;
}





//CONTROLE DE SAISIE
void control_saisie(char *tab,int col)
{
   int ok2,j=0; 
   char x;   
         do
         {  ok2=0;
          x=getche();
        if (x!=8)
           {
              tab[j]=x;
              if(tab[j]<'0'|| tab[j]>'9')
              {
                 ok2=1;
                 printf("\b \b");                          
              }
              if(ok2==1)  
              {
                j--;
              }
           } 
        if (x==8)
           { j--;}
        else {j++;}
     }while (j<col);
      tab[j]='\0'; 

}


//VERIFICATION DATE ET MESSAGE ERREUR OU OK SELON LE CAS
void verification_date(struct fiche *reservation,char *tableau,char type,int x_1,int x_2,int y)
{
	int valid,ok1=0;
	  do
      {	
			gotoxy(x_1,y);
			valid=validation_date(reservation,tableau,type);
			if (valid==0)
			{		
			
				gotoxy(x_1,y);
				clreol();
				gotoxy(79,y);
				textcolor(14);
				cprintf("%c",179);
				gotoxy(x_2,y);
				textcolor(15);
				printf("Date incorrecte reesayez");
				ok1=1;
			}
			if(valid==1)
			{
				if(ok1==1)
				{
					gotoxy(x_2,y);
					clreol();
				    gotoxy(79,y);
					textcolor(14);
					cprintf("%c",179);
				}
				gotoxy(x_1,y);
   		        textcolor(15);
				printf("%s",tableau);
			}
	  }while(valid==0);
}


int validation_date(struct fiche *structure,char *tab,char type)
{
	int i,jr,ms,an,ok;
	for(i=0;i<10;i++)
	{	
		if (i!=2 && i!=5) //recuperation date entrée dans un tableau provisoire
			tab[i]=getche();
		if (i==2 || i==5)
		{
			tab[i]='/';
			printf("/");
		}
	}
	tab[10]='\0';
//	gotoxy(3,10);
//	printf("%s\n",tab);
	    
//afectation de la date à partir du tableau vers chaque champ de la structure date allee
if(type=='A')
{
	structure->allee.jour[0]=tab[0];
	structure->allee.jour[1]=tab[1];
	structure->allee.jour[2]='\0';
	structure->allee.mois[0]=tab[3];
	structure->allee.mois[1]=tab[4];
	structure->allee.mois[2]='\0';
	structure->allee.annee[0]=tab[6];
	structure->allee.annee[1]=tab[7];
	structure->allee.annee[2]=tab[8];
	structure->allee.annee[3]=tab[9];
	structure->allee.annee[4]='\0';
	jr=atoi(structure->allee.jour);
	ms=atoi(structure->allee.mois);
	an=atoi(structure->allee.annee);
}
else
{
	structure->retour.jour[0]=tab[0];
	structure->retour.jour[1]=tab[1];
	structure->retour.jour[2]='\0';
	structure->retour.mois[0]=tab[3];
	structure->retour.mois[1]=tab[4];
	structure->retour.mois[2]='\0';
	structure->retour.annee[0]=tab[6];
	structure->retour.annee[1]=tab[7];
	structure->retour.annee[2]=tab[8];
	structure->retour.annee[3]=tab[9];
	structure->retour.annee[4]='\0';
	jr=atoi(structure->retour.jour);
	ms=atoi(structure->retour.mois);
	an=atoi(structure->retour.annee);
}

//test pour verifier que la date entree est correcte
	ok=0;
	if(an<2013)
	{
		ok=0;
	}
	else if(ms>=1&&ms<=12)
	{
		if(ms==4 || ms==6 || ms==9 || ms==11)
		{
			if(jr>=1 && jr<=30)
				ok=1; //ok=1 si la date est correcte
			else
				ok=0;
    	}
   		else if(ms==2)
    	{
    		if(an%4==0 && an%100!=0 || an%400==0)
    		{
    			if(jr>=1 && jr<=29)
    				ok=1;
    			else
					ok=0;
    		}
    		else if(jr>=1 && jr<=28)
    			ok=1;
    		else
				ok=0;
    	}
   		else if(jr>=1 && jr<=31)
    		ok=1;
   		else
    		ok=0;
	}
	else
		ok=0;

	return ok; /*ok=1 date est correcte */
}


int saisie_heure(char *heure_complete, int pos_x, int pos_y)
{
int i=0,hre,min,ok;
char autorise[11]="0123456789";
char heures[3];
char minutes[3];
char c;
gotoxy(pos_x+i,pos_y);
hre=0;min=0;
heure_complete;
do
    {
    c=getch();

        if(strchr(autorise,c)!=NULL)
        {
             gotoxy(pos_x+i,pos_y);
             if(i!=2)
             { 
			    printf("%c",c);
                heure_complete[i]=c;
             }
			 else
			 {
			    printf(":");
             	heure_complete[i]=':';
		     }
        i++;
		}
        else if(!c && i>=1)
        {
             i--;
             gotoxy(pos_x+i,pos_y);
             printf(" "); gotoxy(pos_x+i,pos_y);
        }
    }while(i<6-1 && c!='\r');
        heure_complete[i]='\0';

	  heures[0]=heure_complete[0];
	  heures[1]=heure_complete[1];
	  minutes[0]=heure_complete[3];
	  minutes[1]=heure_complete[4];

	  heures[2]='\0';
	  minutes[2]='\0';
	  
	  hre=atoi(heures);
	  min=atoi(minutes);
	 
	  
      ok=0;
	  if(hre<0 || hre>23)
	 {	
	 	ok=1;
	 }
	  else if(min<0 || min>59)
	 {
		ok=1;
	 }
	 else if(heure_complete[5]!='\0')
	  {
	  	ok=1;
	  }
	 gotoxy(1,1);
	 //printf("%s     ",heure_complete);
	 //printf("%d   %d",hre,min);
	 if (ok)
 	 {
	 	   	gotoxy(pos_x,pos_y);
		 	clreol();
		 	gotoxy(79,pos_y);
			textcolor(14);
			cprintf("%c",179);
		 	gotoxy(pos_x+9,pos_y);
		 	textcolor(15);
			cprintf("Heure incorrecte reesayez");
	 }
	 else
	 {
		 	gotoxy(pos_x,pos_y);
 			clreol();
 			gotoxy(79,pos_y);
			textcolor(14);
			cprintf("%c",179);
 			gotoxy(pos_x,pos_y);
			textcolor(15);
			cprintf("%s",heure_complete);	
	 }
	 	  
	 return ok;
}



float definition_parcours(char *codpos,int choix,float prix_km,float *tarifs,int col,int pos_x,int pos_y)
{
//Recherche du code postal dans le tableau codes_postaux
      char codes_postaux[20][5]={"1400","7000","7040","7060","7080","7090","7100","7130","7180","7330",
                                 "7500","7600","7640","7760","7800","7850","7860","7890","7900","7970"};
	  int j=0;
      int ok=0;
      int trouver;
      float prix_base;

      do
      {
          trouver=strcmp(codes_postaux[j],codpos);
           if(trouver==0)
		   {
               ok=1;
               j--;
           }
      j++;
      }while(ok==0 && j!=20);
      
      //cprintf("\n%d",ok);
      //cprintf("\n%d",j);  // CONTROLE

      /* Calcul du prix de base par personne pour un parcours special
         parcours special= si code postal n'est pas dans le tableau ou
                           si destination = autre */
      
      if(ok==0 || choix==3)
      {
               gotoxy(pos_x,pos_y);
               textcolor(10);
               cprintf("PARCOURS SPECIAL");
               textcolor(15);
               gotoxy(pos_x,pos_y+2);
               prix_base= calcul_parcours_special(prix_km);
               gotoxy(pos_x+31,pos_y+2);
               textcolor(15);
               cprintf("%.2f euros par personne",prix_base);
      }
      else
      {
               prix_base=*(tarifs + j * col + choix);
               gotoxy(pos_x,pos_y);
               textcolor(10);
               cprintf("PARCOURS NORMAL");
               gotoxy(pos_x,pos_y+2);
               textcolor(15);
               printf("%.2f euros par personne",prix_base);
      }
      return prix_base;
}

// FONCTION QUE CALCULE LE PRIX DE BASE POUR UN PARCOURS SPECIAL
float calcul_parcours_special(float prix_km)
{
    float prix,nbr_km;
          textcolor(10);
          cprintf("km a parcourir : ");
          textcolor(15);
          scanf("%f",&nbr_km);
          fflush(stdin);
          prix= prix_km * nbr_km;
          return prix;
}

 //FONCTION QUE CALCULE LE PRIX TOTAL A PAYER SUIVANT REDUCTIONS
 float calcul_prix_final(int adultes,int enfants,float prix,float reduct)
 {
       float prix_total,prix_a,prix_e;
             prix_a=(adultes * prix)*reduct;
             prix_e=(enfants * prix)*0.5;
             prix_total=prix_a + prix_e;
             return prix_total;
 }                           




//FONCTION POUR AFFICHER LES DONNEES PAR CRITERE OU PAR NUMERO DE CLIENT
void consult_reservations(struct fiche reservation)
{	
	char tab_choix_typeClient[3][15]={"Particulier","Entreprise","Agence"};
	char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
	char f_appel='C',typ_affiche,rep,x;
	char consult='A';
	char choix[17];
	int num_cl_entre=0;
	int pos=0;
	int critere;
	int cmp1,cmp2,cmp3;
	
	clrscr();
	cadre_affichage(f_appel,1,1,79,24);
	FILE *ptr;
	textcolor(10);
	gotoxy(10,8);
	cprintf("CONNAISEZ VOUS LE NUMERO DE CLIENT (o/n)? : ");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o')
	{
		pos=verif_num_client(reservation);		
		if(pos!=-1)
		{
			gotoxy(20,5);blanc
		
			affiche_par_numclient(reservation,num_cl_entre,pos,consult);
		}
	}
	else
	{
		critere=menu_choix_critere(choix);

		affiche_critere(reservation,critere,choix);
		clrscr();
	
		cadre_affichage(f_appel,1,1,79,23);
			vert;
		gotoxy(5,10);
		printf("END OF FILES ");
			
	}
	typ_affiche='f';
	retour_menu(f_appel,typ_affiche);
}

//FONCTION POUR AFFICHER LES RESERVATION PAR CRITERE
void affiche_critere(struct fiche reservation,int critere,char *choix)
{	
	char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
	int cmp1,cmp2,cmp3;
	int num_cl_entre=0;
	char typ_affiche,f_appel='C';
	clrscr();
	cadre_affichage(f_appel,1,1,79,24);
	
	FILE *ptr;
	ptr=fopen("reservation_clients.dat","rb");	
	if(ptr!=NULL)
	{
		fread(&reservation,sizeof(reservation),1,ptr);
				while(!feof(ptr))
          		{
					if (critere==0)
					{
						if(strcmp(reservation.type_prestation,choix)==0)
						{
							cmp1=strcmp(choix,"ALLEE");
							cmp2=strcmp(choix,"RETOUR");
							cmp3=strcmp(choix,"ALLEE / RETOUR");
							if(cmp1==0 || cmp3==0)
							{
								affiche_allee(reservation,num_cl_entre);
							}
							if(cmp2==0 || cmp3==0)
							{
								affiche_retour(reservation,num_cl_entre);
							}
				
								fread(&reservation,sizeof(reservation),1,ptr);
						}
						else
						{
							fread(&reservation,sizeof(reservation),1,ptr);
						}
					}
					else
					{
						if(strcmp(reservation.type_client,choix)==0)
						{
							cmp1=strcmp(reservation.type_prestation,type_prestation[0]);  /*ALLEE*/
							cmp2=strcmp(reservation.type_prestation,type_prestation[1]);  /*RETOUR*/	
							cmp3=strcmp(reservation.type_prestation,type_prestation[2]);  /*ALLEE / RETOUR*/
							if(cmp1==0 || cmp3==0)
							{
								affiche_allee(reservation,num_cl_entre);
							}
							if(cmp2==0 || cmp3==0)
							{
								affiche_retour(reservation,num_cl_entre);
							}					
							fread(&reservation,sizeof(reservation),1,ptr);
						}
						else
						{
							fread(&reservation,sizeof(reservation),1,ptr);
						}
					}
				 }//fin while	
			//retour_menu(f_appel,typ_affiche);
	}
	else
	{
    	gotoxy(18,10);
    	textcolor(14);
		cadre_affichage(f_appel,1,1,79,22);
		printf("Probleme de connexion a la base de donnees ");
		typ_affiche='f';
		retour_menu(f_appel,typ_affiche);
	}

		 retour_menu(f_appel,typ_affiche);
		 fclose(ptr);			
}


//FONCTION POUR DEMANDER PAR QUEL CRITERE RECHERCHER LES RESERVATIONS 
int menu_choix_critere(char *choix)
{
//char choix[17];
char f_appel='C';
char typ_affiche;
char tab[2][4][20]={{"TYPE DE PRESTATION","ALLEE","RETOUR","ALLEE / RETOUR"},{"TYPE DE CLIENT","Particulier","Entreprise","Agence"}};
    int nbchoix[2]={3,3};
    int pos,i,touche,max=2,j,k;
    clrscr();
    pos=0;
   	i=0;
	cadre_affichage(f_appel,1,1,79,24);
  					textcolor(10);
  					gotoxy(10,6);
  					cprintf("RECHERCHE PAR CRITERE");
  					gotoxy(10,7);
					cprintf("=====================");
 	textcolor(10);
  	do
  	{
      do
      {
         for(k=0;k<max;k++)
        {
            gotoxy(10+k*30,10);
		  	cprintf("%s",tab[k][0]);
      	}
          	gotoxy(10+i*30,10);textcolor(10);
  			cprintf("%s",tab[i][0]);textcolor(15);
          
		 for(j=1;j<=nbchoix[i];j++)
         {
             if(j==pos)
            {
             textcolor(10);;gotoxy(10+i*30,10+j);cprintf("%s",tab[i][j]);
                  textcolor(15);
             }
            else
            {
                 gotoxy(10+i*30,10+j);
                cprintf("%s",tab[i][j]);
            }
         }
         gotoxy(10+i*30,10);
         touche=getch();
         if (touche==224)
         {
             touche=getch();
             if(touche==KEY_DOWN)
             {
                
				 if(pos<nbchoix[i])
                 {
                     pos++;
                 }
                 else
                     pos=1;
             }
             if(touche==KEY_UP)
             {
              
                 
				 if(pos>1)
                     pos--;
                 else
                     pos=nbchoix[i];
             }
             if (touche==KEY_RIGHT)
             {
               
				pos=1;
                 if(i==max-1)
                 {
                     i=0;
                     clrscr();
                     cadre_affichage(f_appel,1,1,79,24); textcolor(10);
  					textcolor(10);
  					gotoxy(10,6);
  					cprintf("RECHERCHE PAR CRITERE");
  					gotoxy(10,7);
					cprintf("=====================");
                 }
                 else
             	 {
                 	++i;
                 	clrscr();
                 	cadre_affichage(f_appel,1,1,79,24); textcolor(10);
  					textcolor(10);
  					gotoxy(10,6);
  					cprintf("RECHERCHE PAR CRITERE");
  					gotoxy(10,7);
					cprintf("=====================");
                 	
             	 }
        	 }
        	 if(touche==KEY_LEFT)
         	{
            
			 	pos=1;
            	if(i==0)
             	{
                 	i=max-1;
               	 	clrscr();
               		cadre_affichage(f_appel,1,1,79,24); textcolor(10);
  					textcolor(10);
  					gotoxy(10,6);
  					cprintf("RECHERCHE PAR CRITERE");
  					gotoxy(10,7);
					cprintf("=====================");
             	}
             	else
             	{
                 	--i;
                 	clrscr();
                 	cadre_affichage(f_appel,1,1,79,24); textcolor(10);
  					textcolor(10);
  					gotoxy(10,6);
  					cprintf("RECHERCHE PAR CRITERE");
  					gotoxy(10,7);
					cprintf("=====================");
            	 }
         	}
   		}
	 }while(touche!=13);
	}while(pos==0);
		clrscr();
		strcpy(choix,tab[i][pos]);
	return i;
}
					

void affiche_allee(struct fiche reservation,int num_cl_entre)
{
	char typ_affiche,f_appel='C';
		
		clrscr();
		cadre_affichage(f_appel,1,1,79,24);
		en_tete(reservation,num_cl_entre);
		vert;
		gotoxy(4,8);
		printf("ALLEE");
		gotoxy(40,8); 
		printf("TYPE DE CLIENT :  %s",reservation.type_client);
		gotoxy(4,10);blanc;
		printf("adultes : %d",reservation.qte_adultes_allee);
		gotoxy(40,10);
    	printf("enfants : %d",reservation.qte_enfants_allee);
		gotoxy(4,12);
		printf("siege(s) bebe(s) :  %d",reservation.siege_bebe);
	    gotoxy(40,12);
		printf("Rehausseur(s) :%d",reservation.rehausseur);
	   	gotoxy(4,14);
		printf("Date :  %s/%s/%s",reservation.allee.jour,reservation.allee.mois,reservation.allee.annee);
	    gotoxy(40,14);
		printf("Lieu de depose :  %s",reservation.lieu_depose);
	    gotoxy(4,16);
		printf("Heure prise en charge :  %s",reservation.heure_prise_en_charge);
	    gotoxy(40,16);
		printf("Heure de decollage :  %s",reservation.heure_decollage);
		gotoxy(4,18);
	    printf("No de vol (allee) :  %s",reservation.allee_numero_vol);
	    gotoxy(40,18);
	    printf("Destination :  %s",reservation.destination_vol);
		gotoxy(4,21);  vert;
		printf("Prix total a payer : ");
		blanc;
		printf("%.2f",reservation.prix_total);
		typ_affiche='m';
		retour_menu(f_appel,typ_affiche);
}


void affiche_retour(struct fiche reservation,int num_cl_entre)
{
	char typ_affiche,f_appel='C';
		clrscr();
		cadre_affichage(f_appel,1,1,79,24);
		en_tete(reservation,num_cl_entre);
		vert;
		gotoxy(4,8);
		printf("RETOUR");
		gotoxy(40,8);
		printf("TYPE DE CLIENT :  %s",reservation.type_client);
		gotoxy(4,10);
		blanc;
		printf("adultes retour :  %d",reservation.qte_adultes_retour);
		gotoxy(40,10);
		printf("enfants retour :  %d",reservation.qte_enfants_retour);
		gotoxy(4,12);
		printf("Date de retour :  %s/%s/%s",reservation.retour.jour,reservation.retour.mois,reservation.retour.annee);
	   	gotoxy(40,12);
		printf("Lieu de retour :  %s",reservation.lieu_retour);
	    gotoxy(4,14);
		printf("Heure d'arrivee :  %s",reservation.heure_arrivee);
	    gotoxy(40,14);
		printf("No de vol (retour) :  %s",reservation.retour_numero_vol); 
	    gotoxy(4,16);
		printf("Provenance :  %s",reservation.provenance_vol);
	    gotoxy(4,21);  vert;
		printf("Prix total a payer : ");
		blanc;
		printf("%.2f",reservation.prix_total);
			
	    typ_affiche='m';
		retour_menu(f_appel,typ_affiche);
	}


void affiche_par_numclient(struct fiche reservation,int num_cl_entre,int pos,char procedure)
{
  	char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
	char type_prest[15];
	char f_appel='C';
  	char typ_affiche,rep,rep2;
  	int cmp1,cmp2,cmp3,ok=0,ok2,i;
	FILE *ptr;
//	clrscr();
	
	ptr=fopen("reservation_clients.dat","rb");	
	if(ptr!=NULL)
	{		
			ok2=0;i=0;
			fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
			fread(&reservation,sizeof(reservation),1,ptr);
        	while(!feof(ptr) && !ok)
			{
					clrscr();
					Sleep(300);
				
					cadre_affichage(f_appel,1,1,79,24);
					en_tete(reservation,num_cl_entre);
					textcolor(15);
					gotoxy(4,8);blanc
					printf("TYPE DE CLIENT : %s",reservation.type_client);
    				gotoxy(40,8);
					printf("TYPE DE PRESTATION : %s",reservation.type_prestation);
	 					if(procedure=='M')
	 					{
	 						strcpy(type_prest,reservation.type_prestation);
	 					}
					 gotoxy(4,10);
					printf("NOM COMPLET :  %s",reservation.nom_complet);
        			gotoxy(4,12);
					printf("ADRESSE :  %s",reservation.adresse);
     				gotoxy(4,14);
					printf("CODE POSTAL :  %s",reservation.cod_pos);
   					gotoxy(40,14);
					printf("LOCALITE :  %s",reservation.localite);
   	 				gotoxy(4,16);
					printf("TELEPHONE :  %s",reservation.telephone);
    				gotoxy(40,16);
					printf("GSM :  %s",reservation.gsm);
     				gotoxy(4,18);
					printf("e-mail :  %s",reservation.e_mail);
					gotoxy(4,19);
					printf("%c",procedure);
					if(procedure=='A')
					{
						vert;
						gotoxy(4,21);
						printf("EST CE LA BONNE FICHE (o/n) ? : ");
						scanf("%c",&rep);
						fflush(stdin);
						
					}
					if(procedure=='M')
					{
						vert;
						gotoxy(4,21);
						f_appel='M';
						printf("EST CE LE BON CLIENT A MODIFIER (o/n) ? : ");
						scanf("%c",&rep);
						fflush(stdin);
					}
					if(rep=='o')
					{
						if(procedure=='A')
						{
							ok=1;
							cmp1=strcmp(reservation.type_prestation,type_prestation[0]);  /*ALLEE*/
							cmp2=strcmp(reservation.type_prestation,type_prestation[1]);  /*RETOUR*/	
							cmp3=strcmp(reservation.type_prestation,type_prestation[2]);  /*ALLEE/RETOUR*/
							if(cmp1==0 || cmp3==0)
							{
								affiche_allee(reservation,num_cl_entre);
							}
			
							if(cmp2==0 || cmp3==0)
							{
								affiche_retour(reservation,num_cl_entre);
							}
						/*	gotoxy(4,21);
							vert;
							printf("Prix total a payer : ");
							blanc;
							printf("%.2f",reservation.prix_total);  */
						}
						else
						{
							ok=1;
						}
					}
					else
					{
						if(ok2==0)
						{
							ok2=1;
							vert;
							gotoxy(4,21);
							clreol();
							gotoxy(79,21);
							textcolor(14);
							cprintf("%c",179);
							Sleep(200);
							vert;
							gotoxy(4,21);
							printf("VOULEZ-VOUS VOIR LES AUTRES FICHES (o/n) ? : ");
							scanf("%c",&rep2);
								fflush(stdin);
							if(rep2=='o')
							{
								ok=0;
							
								rewind(ptr);
								i=1;
								//pos=0;
								fread(&reservation,sizeof(reservation),1,ptr);
							}
							else
							{
								i=-1;
								ok=-1;
							}
						}
						else
						{
							fread(&reservation,sizeof(reservation),1,ptr);
							ok=0;
							i++;
						}
					}
			}//Fin while
	}
else{
			gotoxy(18,10);
    		textcolor(14);
			cadre_affichage(f_appel,1,1,79,24);
			printf("Probleme de connexion a la base de donnees ");
			typ_affiche='f';
			retour_menu(f_appel,typ_affiche);
	}
	fclose(ptr);
		if(procedure=='M')
		{
			if(ok==1 && i==0)
			{
				modif(pos,type_prest);//APPEL DE LA FONCTION POUR MODIF 
			}
			else if(ok==1 && i!=0)
			{
				modif(i,type_prest);//APPEL DE LA FONCTION POUR MODIF 
			}
			else if(ok==-1)
			{
				typ_affiche='f';
				
				retour_menu(f_appel,typ_affiche);	
			}
		}
}


// Saisie par l'utilisateur du numéro du client dont on désire afficher les données 
int saisie_num()
{
	int num_cl_entre;
		vert;
		gotoxy(10,10);
		printf ("Entrez le numero de client : ");
		blanc;
		scanf("%d",&num_cl_entre);
		fflush(stdin);
return num_cl_entre;
}

int verif_num_client(struct fiche reservation)
{		
	char f_appel='M',typ_affiche;
	int num_cl_entre=0,pos;
	num_cl_entre=saisie_num();
	pos= recherche(num_cl_entre,reservation);
				if(pos==-1)
				{
					clrscr();
					cadre_affichage(f_appel,1,1,79,24);
					gotoxy(5,10);
					vert;
					printf("Ce numero de client n'existe pas");	
					Sleep(200);
					typ_affiche='f';
					retour_menu(f_appel,typ_affiche);
				}
	return pos;	
}


int recherche(int num_cli, struct fiche reservation)
{
	int i,ok;
	FILE *ptr;
	ptr=fopen("reservation_clients.dat","rb");	
	if(ptr!=NULL)
	{
     	ok=0;
     	i=0;
     	fread(&reservation,sizeof(reservation),1,ptr);
    	while(!feof(ptr) && !ok)
        {
          	if(reservation.num_client==num_cli)
            {
               ok=1; 
            }
          	else
            {
               ok=0;
			   fread(&reservation,sizeof(reservation),1,ptr);
               i++;
            }
        }// fin while
     }// fin ptr
	fclose(ptr);
	if(ok==1)
    	 return i;
	else
     	return -1;
}



/* Constitution de l'index */
int creation_index(struct recherche* index, struct fiche reservation)
{
char f_appel='M';
FILE *ptr;
int i;
i= -1;
	ptr=fopen("reservation_clients.dat","rb+");	
	if(ptr!=NULL)
	{
    	fread(&reservation,sizeof(reservation),1,ptr);
    while(!feof(ptr))
        {
        i++;
        index[i].numero=reservation.num_client;
        strcpy(index[i].nom,reservation.nom_complet);
		index[i].position=i;
        fread(&reservation,sizeof(reservation),1,ptr);
        }// fin while
    }// fin if ptr
else
    {
    cadre_affichage(f_appel,1,1,79,24);
	textcolor(14);
	gotoxy(5,8);
	printf("\nProblème de lecture du fichier");
    }
fclose(ptr);
return i;
}

// Tri (sélection) de l'index, par ordre croissant 
void tri(struct recherche *index,int N)
{
int i,j;
int num,pos;
char n[40];

for(i=0;i<=N-1;i++)
    {
    for(j=i+1;j<=N;j++)
        {
        if(index[i].numero>index[j].numero)
            {
             num=index[i].numero;
             index[i].numero=index[j].numero;
             index[j].numero=num;
             strcpy(n,index[i].nom);
             strcpy(index[i].nom,index[j].nom);
             strcpy(index[j].nom,n);
             pos=index[i].position;
             index[i].position=index[j].position;
             index[j].position=pos;
             }// fin if strcmp
        }// fin for j
    }// fin for i
}

// Affichage de l'index trié 
char affiche_index(struct recherche* index,int N)
{
int i;
int pos_y;
char rep,typ_affiche;
char f_appel='M';
	gotoxy(5,6);
	vert;
	printf("VOICI LA LISTE DE CLIENT PRESENTS DANS LE FICHIER");
	gotoxy(5,7);
	printf("__________________________________________________");
	blanc;
	i=0;rep='n',pos_y=10;
	do
	{
	//for(i=0;i<N+1;i++)
    	
    	gotoxy(5,pos_y);
		blanc;
		printf("%d                 %s",index[i].numero, index[i].nom);
		if(i!=0 && i%9==0)
			{
				pos_y=9;
				gotoxy(5,20);
		  		vert;
		  		printf("Avez-vous trouve le client que vous recherchez (o/n)? :");
		  		scanf("%c",&rep);
		  		fflush(stdin);
		  		if (rep=='n')
		  			{
		  				clrscr();
		  				cadre_affichage(f_appel,1,1,79,24);
		  				typ_affiche='f';
						retour_menu(f_appel,typ_affiche);
    				}
			}  
    	i++; pos_y++;	
    }while(i<N+1 && rep!='o');
    
    gotoxy(5,20);
	vert;
	printf("Avez-vous trouve le client que vous recherchez (o/n)? :");
	scanf("%c",&rep);
	fflush(stdin);  
	typ_affiche='f';
	retour_menu(f_appel,typ_affiche);
	return rep;
    
}




//FONCTION POUR MODIFIER LES RESERVATIONS
void modification_reservation(struct fiche* reservation)
{
	
	struct recherche index[100];
	int num_cl_entre=0,pos,nbre_elements;
	char f_appel='M',rep,rep1;
	char typ_affiche='m';
	char f_appel2='M';
	cadre_affichage(f_appel,1,1,79,24);
	textcolor(10);
	gotoxy(10,8);
	cprintf("CONNAISEZ VOUS LE NUMERO DE CLIENT A MODIFIER (o/n)? : ");
	scanf("%c",&rep1);
	fflush(stdin);
	if(rep1=='o')
	{
		pos=verif_num_client(*(reservation));
				if(pos!=-1)  //position trouvée
				{
				 	affiche_par_numclient(*(reservation),num_cl_entre,pos,f_appel2);
				}
	}
	else
	{
				nbre_elements=creation_index(index,(*(reservation)));
				if(nbre_elements!=-1)
    			{
    				tri(index,nbre_elements);
    			}
				clrscr();
				cadre_affichage(f_appel,1,1,79,24);
				rep=affiche_index(index,nbre_elements);
					
				if(rep=='o')
				{
					clrscr();
					cadre_affichage(f_appel,1,1,79,24);
				    pos=verif_num_client(*(reservation));
					/*typ_affiche='m';
					retour_menu(f_appel,typ_affiche);*/
			
					if(pos!=-1)
					{
						clrscr();
						cadre_affichage(f_appel,1,1,79,24);
						gotoxy(20,5);blanc
						affiche_par_numclient(*(reservation),num_cl_entre,pos,f_appel2);
						//APPELER LA FONCTION QUI VA MODIFIER LA RESERVATION
					}
				}
				else
				{
					/*gotoxy(5,6);
					vert;
					printf("Avez-vous trouvé le client que vous recherchez (o/n)? :");
					scanf("%c",&rep);
					fflush(stdin);
					if (rep=='n')
					{*/
						clrscr();
						cadre_affichage(f_appel,1,1,79,24);
						vert;
						gotoxy(5,10);
						printf("SI VOUS SOUHAITEZ RECOMMENCER LA RECHERCHE ");
						
						typ_affiche='f';
						retour_menu(f_appel,typ_affiche);
					//}
				}
	}
	retour_menu(f_appel,typ_affiche);
}


void modif(int pos,char *type_prest)
{ 
	
struct fiche reservation;
char rep,type;
int champ;
char c_postal[5];
char date_complete[11];
char lieux[4][30]={"Bruxelles National","Aeroport de Charleroi","Lille Lesquin","Autre"};
int choix_lieu;
char heure_complete[6];
int heure_ok=0;

FILE *ptr;

	ptr=fopen("reservation_clients.dat","rb+");	
	do
	{
		champ=define_champ_modifier(pos,type_prest);
/*	gotoxy(1,1);vert;
	printf("          %d",champ);*/

	if(ptr!=NULL)
	{		
		
			fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
			fread(&reservation,sizeof(reservation),1,ptr);

		switch (champ)
        	{
				case 1: clrscr();
                    	gotoxy(5,5);vert;
						printf("Entrez le nouveau nom :  ");
						blanc;
						gotoxy(30,5);
						scanf("%[^\n]",reservation.nom_complet);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 2: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez la nouvelle adresse :  ");
						gotoxy(5,7);
						printf("Entrez le code postal : ");
						gotoxy(5,9);
						printf("Entrez la localité : ");
						blanc;
						gotoxy(37,5);
						scanf("%[^\n]",reservation.adresse);
					    fflush(stdin);
						gotoxy(37,7);
						control_saisie(c_postal,4);
      					strcpy(reservation.cod_pos,c_postal);
      					fflush(stdin);
						gotoxy(37,9);
						scanf("%[^\n]",reservation.localite);
						fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 3: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez le nouveau telephone :  ");
						blanc;
						gotoxy(37,5);
						scanf("%s",reservation.telephone);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
                    	break;
            	case 4: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez le nouveau numero de GSM :  ");
						blanc;
						gotoxy(41,5);
						scanf("%s",reservation.gsm);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 5:  clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez la nouvelle adresse mail :  ");
						blanc;
						gotoxy(41,5);
						scanf("%s",reservation.e_mail);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 6: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez le nombre d'adultes à l'allee :  ");
						blanc;
						gotoxy(46,5);
						scanf("%d",reservation.qte_adultes_allee);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
                    	break;
            	case 7: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez le nombre d'enfants à l'allee :  ");
						blanc;
						gotoxy(46,5);
						scanf("%d",reservation.qte_enfants_allee);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 8: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez la nouvelle date de depart :  ");
						blanc;
						//gotoxy(43,5);
						type='A';
						verification_date(&reservation,date_complete,type,43,58,15);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
                    	break;
            	case 9: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez le nouveau lieu de depose :  ");
						blanc;
						choix_lieu= menu_choix(&lieux[0][0],30,4,42,5);
				  	  	gotoxy(42,5);
						clreol();
						gotoxy(79,5);
						textcolor(14);
						cprintf("%c",179);
						gotoxy(42,6);
						clreol();
						gotoxy(79,6);
						textcolor(14);
						cprintf("%c",179);
						gotoxy(42,7);
						clreol();
						gotoxy(79,7);
						textcolor(14);
						cprintf("%c",179);
						gotoxy(42,8);
						clreol();
						gotoxy(79,8);
						textcolor(14);
						cprintf("%c",179);
			  			if(choix_lieu==3) //si choix = 3 c-à-d "autre" on recupere la chaine entrée au clavier
			  			{
			  				gotoxy(42,5); 
					    	textcolor(15);
							scanf("%[^\n]",reservation.lieu_depose);
					    	fflush(stdin);
		      			}
			  			else 
			  			{
				  			gotoxy(42,5);
					    	textcolor(15);
							strcpy(reservation.lieu_depose,lieux[choix_lieu]);
				  			cprintf("%s",reservation.lieu_depose);
			  			}
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 10:  clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez la nouvelle heure de prise en charge :  ");
						 do
					  	 {
					       		heure_ok=saisie_heure(heure_complete,53,5);
					  
					  	 }while(heure_ok==1);
					  
					  	 strcpy(reservation.heure_prise_en_charge,heure_complete);
					   	fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 11: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez le nouveau numero du vol au depart :  ");
						blanc;
						gotoxy(48,5);
						scanf("%[^\n]",reservation.allee_numero_vol );
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
                    	break;
            	case 12: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez la nouvelle heure de decollage :  ");
						blanc;
						 do
					  	 {
					      	heure_ok=saisie_heure(heure_complete,47,5);
					  
					  	 }while(heure_ok==1);
					  
					     strcpy(reservation.heure_decollage,heure_complete);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						
						break;
            	case 13: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez la destination du vol :  ");
						blanc;
						gotoxy(39,5);
						scanf("%[^\n]",reservation.destination_vol);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
                    	break;
            	case 14: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez le nombre d'adules au retour :  ");
						blanc;
						gotoxy(45,5);
						scanf("%d",reservation.qte_adultes_retour);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 15:  clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez le nombre d'enfants au retour :  ");
						blanc;
						gotoxy(45,5);
						scanf("%d",reservation.qte_enfants_retour);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 16: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez la nouvelle date de retour :  ");
						blanc;
						type='R';
						verification_date(&reservation,date_complete,type,44,59,5);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
                    	break;
            	case 17: clrscr();
						gotoxy(5,5);vert;
							choix_lieu= menu_choix(&lieux[0][0],30,4,54,15);
					  	  	gotoxy(54,15);
							clreol();
							gotoxy(79,15);
							textcolor(14);
							cprintf("%c",179);
							gotoxy(54,16);
							clreol();
						    gotoxy(79,16);
							textcolor(14);
							cprintf("%c",179);
							gotoxy(54,17);
							clreol();
							gotoxy(79,17);
							textcolor(14);
							cprintf("%c",179);			
							gotoxy(54,18);
							clreol();
							gotoxy(79,18);
							textcolor(14);
							cprintf("%c",179);
					  	if(choix_lieu==3) //si choix = 3 c-à-d "autre" on recupere la chaine entrée au clavier
					  	{
					  		
							gotoxy(54,15); 
						    textcolor(15);
							scanf("%[^\n]",reservation.lieu_retour);
						    fflush(stdin);
				     	 }
					  	 else 
					  	 {
					  		strcpy(reservation.lieu_retour,lieux[choix_lieu]);
					  		gotoxy(54,15);
					  		textcolor(15);
							cprintf("%s",reservation.lieu_retour);
					  	 }
		
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 18: clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez le nouveau nom :  ");
						blanc;
						gotoxy(30,5);
						scanf("%[^\n]",reservation.nom_complet);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						
                    	break;
            	case 19: clrscr();
						gotoxy(5,5);vert;
						printf("Entrez le nouveau nom :  ");
						blanc;
						gotoxy(30,5);
						scanf("%[^\n]",reservation.nom_complet);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            	case 20:  clrscr();
            			gotoxy(5,5);vert;
						printf("Entrez le nouveau nom :  ");
						blanc;
						gotoxy(30,5);
						scanf("%[^\n]",reservation.nom_complet);
					    fflush(stdin);
						fseek(ptr,sizeof(reservation)*pos,SEEK_SET);
     					fwrite(&reservation,sizeof(reservation),1,ptr);
						break;
            }
		gotoxy(5,8);vert;
		printf("Souhaitez vous apporter d'autres modifications (o/n ? : ");
		scanf("%c",&rep);
		fflush(stdin);
	}
	else
	{
	gotoxy(5,5);
	printf("erreur d'ouverture");
	rep='n';
	}
}while(rep=='o');
fclose(ptr);

//num_cl_entre=" ";
//affiche_par_numclient(reservation,num_cl_entre,pos,f_appel2);

}


int define_champ_modifier(int pos,char *type_prest)
{
	char tab1[26];
	char type_prestation[3][15]={"ALLEE","RETOUR","ALLEE / RETOUR"};
	int cmp1,cmp2,cmp3,choix,i,k,j,touche;
	
	cmp1=strcmp(type_prest,type_prestation[0]);  /*ALLEE*/
	cmp2=strcmp(type_prest,type_prestation[1]);  /*RETOUR*/	
	cmp3=strcmp(type_prest,type_prestation[2]);  /*ALLEE/RETOUR*/
	
	if(cmp1==0)
	{
	
	char tab[2][9][26]={{"DONNEES CLIENT","Nom complet","Adresse","Telephone","GSM","e-mail"},
	  				   {"DONNEES PRESTATION ALLEE","Nombre d'adultes allee","Nombre d'enfants allee","date de depart",
						"lieu de depose","heure prise en charge","Numero de vol depart",
						"Heure de decollage","Destination du vol"}};
	
    int nbchoix[2]={5,8},max=2; 
	//int pos,i,touche,,j,k;
    clrscr();
     pos=0;i=0;
   	do
    {	for(k=0;k<max;k++)
        {
          	gotoxy(12+k*30,10);
            printf("%s",tab[k][0]);
      	}
         	gotoxy(12+i*30,10); vert;
         	cprintf("%s",tab[i][0]);blanc;
        	for(j=1;j<=nbchoix[i];j++)
         	{
             	if(j==pos)
            	{vert;gotoxy(12+i*30,10+j);cprintf("%s",tab[i][j]);
                  blanc;
				}
            	else
                {	gotoxy(12+i*30,10+j);
                	cprintf("%s",tab[i][j]);
                }
            }
         	gotoxy(12+i*30,10);
        	 touche=getch();
         	if (touche==224)
         	{touche=getch();
             	if(touche==KEY_DOWN)
             	{
                 	if(pos<nbchoix[i])
                 	 	pos++;
        			else
                    	 pos=1;
           	 	}
             	if(touche==KEY_UP)
             	{
                 	if(pos>1)
                     	pos--;
                 	else
                    	 pos=nbchoix[i];
             	}
             	if (touche==KEY_RIGHT)
             	{
                 	pos=1;
                 	if(i==max-1)
                 	{i=0;clrscr();
                 	}
                 	else
             		 {++i;clrscr();
             	 	 }
        	 	}
             	if(touche==KEY_LEFT)
             	{
             		pos=1;
             		if(i==0)
             		{ i=max-1;clrscr();}
             		else
             		 	--i;clrscr();
                	
             	}
      		}
 	}while(touche!=13);
 	gotoxy(12,20);cprintf("vous avez choisi de modifier : %s     %d       %d",tab[i][pos],i,pos);//i = donnees - allee - retour
  	strcpy(tab1,tab[i][pos]);
 	getch();																					//pos=  choix dans chaque colonne
	}
	else if(cmp2==0)
	{
	 char tab[2][8][27]={{"DONNEES CLIENT","Nom complet","Adresse","Telephone","GSM","e-mail"}, 
						{"DONNEES PRESTATION RETOUR","Nombre d'adultes retour","Nombre d'enfants retour","Date de retour",
						 "Lieu de retour","Heure d'arrivee","Numero de vol au retour","Provenance du vol"}}; 
	int nbchoix[2]={5,7},max=2; 	 
	//int pos,i,touche,,j,k;
    clrscr();
     pos=0;i=0;
   	do
    {	for(k=0;k<max;k++)
        {
          	gotoxy(12+k*30,10);
            printf("%s",tab[k][0]);
      	}
         	gotoxy(12+i*30,10); vert;
         	cprintf("%s",tab[i][0]);blanc;
        	for(j=1;j<=nbchoix[i];j++)
         	{
             	if(j==pos)
            	{vert;gotoxy(12+i*30,10+j);cprintf("%s",tab[i][j]);
                 blanc;
				}
            	else
                {	gotoxy(12+i*30,10+j);
                	cprintf("%s",tab[i][j]);
                }
            }
         	gotoxy(12+i*30,10);
        	 touche=getch();
         	if (touche==224)
         	{touche=getch();
             	if(touche==KEY_DOWN)
             	{
                 	if(pos<nbchoix[i])
                 	 	pos++;
        			else
                    	 pos=1;
           	 	}
             	if(touche==KEY_UP)
             	{
                 	if(pos>1)
                     	pos--;
                 	else
                    	 pos=nbchoix[i];
             	}
             	if (touche==KEY_RIGHT)
             	{
                 	pos=1;
                 	if(i==max-1)
                 	{i=0;clrscr();
                 	}
                 	else
             		 {++i;clrscr();
             	 	 }
        	 	}
             	if(touche==KEY_LEFT)
             	{
             		pos=1;
             		if(i==0)
             			{ i=max-1;clrscr();}
             		else
             		 	--i;clrscr();
                }
      		}
 	}while(touche!=13);
	gotoxy(12,20);cprintf("vous avez choisi : %s",tab[i][pos]);
	strcpy(tab1,tab[i][pos]);
	getch();
}
else if(cmp3==0)
{
	
	char tab [3][9][25]={{"DONNEES CLIENT","Nom complet","Adresse","Telephone","GSM","e-mail"},
		 				{"DONNEES ALLEE","Nombre d'adultes allee","Nombre d'enfants allee","date de depart",
						 "lieu de depose","heure prise en charge","Numero de vol depart",
						 "Heure de decollage","Destination du vol"},				
						{"DONNEES RETOUR","Nombre d'adultes retour","Nombre d'enfants retour","Date de retour",
						 "Lieu de retour","Heure d'arrivee","Numero de vol au retour","Provenance du vol"}};
	int nbchoix[3]={5,8,7},max=3;//A / R
	//int pos,i,touche,,j,k;
	clrscr();
	pos=0;i=0;
	   	do
	    {	for(k=0;k<max;k++)
	        {
	          	gotoxy(5+k*24,10);
	            printf("%s",tab[k][0]);
	      	}
	         	gotoxy(5+i*24,10); vert;
	         	cprintf("%s",tab[i][0]);blanc;
	        	for(j=1;j<=nbchoix[i];j++)
	         	{
	             	if(j==pos)
	            	{textcolor(10);gotoxy(5+i*24,10+j);cprintf("%s",tab[i][j]);
	                  blanc;
					}
	            	else
	                {	gotoxy(5+i*24,10+j);
	                	cprintf("%s",tab[i][j]);
	                }
	            }
	         	gotoxy(5+i*24,10);
	        	 touche=getch();
	         	if (touche==224)
	         	{touche=getch();
	             	if(touche==KEY_DOWN)
	             	{
	                 	if(pos<nbchoix[i])
	                 	 	pos++;
	        			else
	                    	 pos=1;
	           	 	}
	             	if(touche==KEY_UP)
	             	{
	                 	if(pos>1)
	                     	pos--;
	                 	else
	                    	 pos=nbchoix[i];
	             	}
	             	if (touche==KEY_RIGHT)
	             	{
	                 	pos=1;
	                 	if(i==max-1)
	                 	{i=0;clrscr();
	                 	}
	                 	else
	             		{++i;clrscr();
	             	 	}
	        	 	}
	             	if(touche==KEY_LEFT)
	             	{
	             		pos=1;
	             		if(i==0)
	             		   { i=max-1;clrscr();}
	             		else
	             		 	--i;clrscr();
	                }
	      		}
	 	}while(touche!=13);
	 	gotoxy(12,20);cprintf("vous avez choisi : %s",tab[i][pos]);
	 	strcpy(tab1,tab[i][pos]);
	 	getch();
	}
	
	if(strcmp(tab1,"Nom complet")==0) choix=1;
	if(strcmp(tab1,"Adresse")==0) choix=2;
	if(strcmp(tab1,"Telephone")==0) choix=3;
	if(strcmp(tab1,"GSM")==0) choix=4;
	if(strcmp(tab1,"e-mail")==0) choix=5;
	if(strcmp(tab1,"Nombre d'adultes allee")==0) choix=6;
	if(strcmp(tab1,"Nombre d'enfants allee")==0) choix=7;
	if(strcmp(tab1,"date de depart")==0) choix=8;
	if(strcmp(tab1,"lieu de depose")==0) choix=9;
	if(strcmp(tab1,"heure prise en charge")==0) choix=10;
	if(strcmp(tab1,"Numero de vol depart")==0) choix=11;
	if(strcmp(tab1,"Heure de decollage")==0) choix=12;
	if(strcmp(tab1,"Destination du vol")==0) choix=13;
	if(strcmp(tab1,"Nombre d'adultes retour")==0) choix=14;
	if(strcmp(tab1,"Nombre d'enfants retour")==0) choix=15;
	if(strcmp(tab1,"Date de retour")==0) choix=16;
	if(strcmp(tab1,"Lieu de retour")==0) choix=17;
	if(strcmp(tab1,"Heure d'arrivee")==0) choix=18;
	if(strcmp(tab1,"Numero de vol au retour")==0) choix=19;
	if(strcmp(tab1,"Provenance du vol")==0) choix=20;

return choix;
}


void suppression_reservation(struct fiche*)
{
	char f_appel='R';
	char typ_affiche='m';
	
	cadre_affichage(f_appel,1,1,79,24);

	retour_menu(f_appel,typ_affiche);
}

void consult_supprimees(struct fiche)
{
	char f_appel='C';
	char typ_affiche='m';

	cadre_affichage(f_appel,1,1,79,24);

	retour_menu(f_appel,typ_affiche);
}
void consult_executees(struct fiche)
{
	char f_appel='C';
	char typ_affiche='m';
	cadre_affichage(f_appel,1,1,79,24);
	//printf("CONSULTATION EXECUTEES");
	retour_menu(f_appel,typ_affiche);
}


//FONCTION POUR CHOISIR TYPE CLIENT, DESTINATION, ETC
int menu_choix(char *tab,int col,int max,int pos_x,int pos_y)
{
//posx= position x de gotoxy pour situer le menu déroulant ou l'on veut
int ancpos,anci,i,j,touche;

    for(i=0;i<max;i++)
    {
        gotoxy(pos_x,pos_y+i);
        printf("%s\n",(tab+i*col));
    }
    i=0;

    do
    {
        gotoxy(pos_x,pos_y+i);highvideo();
        cprintf("%s",(tab+i*col)); normvideo();

        touche=getch();
        if(touche==224)
        {
            touche=getch();
            anci=i;
            if(touche==KEY_DOWN)i=++i%max;
            if(touche==KEY_UP)i=(--i+max)%max;
            gotoxy(pos_x,pos_y+anci);
            cprintf("%s",(tab+anci*col));
        }
     }while(touche != 13);
     fflush(stdin);
    return i;
}


void affiche_choix_menu(char *tab,int col,int max,int choix,int pos_x,int pos_y)
{
     int j=0;
	      do
	      { gotoxy(79,pos_y);
		     textcolor(14);
		     cprintf("%c",179);
	      	 
			   gotoxy(pos_x,pos_y+j);
		     clreol();
		     gotoxy(79,pos_y+j);
		     textcolor(14);
		     cprintf("%c",179);
		     j++;
	      }while(j<max);
	 textcolor(15);
	 gotoxy(pos_x,pos_y);
	 cprintf("%s",(tab+choix*col));
}

 void cadre_affichage(char f_appel,int pos_x,int pos_y,int nbr_col,int nbr_lig)
{

int i,j;
    textcolor(14);
    gotoxy(pos_y,pos_x);
    printf("%c",218);

    for(i=0;i<nbr_col-2;i++) {
        printf("%c",196);
    }
    printf("%c",191);
    
    for(i=0;i<nbr_lig-2;i++) {
        gotoxy(pos_y,++pos_x);
        printf("%c",179);
        for(j=0;j<nbr_col-2;j++) {
                printf(" ");
        }
        printf("%c",179);
    }
    gotoxy(pos_y,pos_x+1);
    printf("%c",192);
    for(i=0;i<nbr_col-2;i++) {
        printf("%c",196);
    }
    printf("%c",217);
    gotoxy(28,2);
	textcolor(14);
	if(f_appel=='M')
	{
		gotoxy(24,2);
		cprintf("MODIFICATION D'UNE RESERVATION");
	}
	else if(f_appel=='R')
		cprintf("ENCODAGE RESERVATIONS");
		
	else if(f_appel=='D')
		{
			gotoxy(36,2);
			cprintf("DEVIS");
		}
	else if(f_appel=='C')
			cprintf("CONSULTATION RESERVATIONS");
}

//RETOUR AU MENU PRINCIPAL
 void retour_menu(char f_appel,char typ_affiche)
{
	
 char rep;

 	textcolor(14);
 	if(f_appel=='T')
 		gotoxy(25,24);
	else
 		gotoxy(5,23);

 	cprintf("RETOUR MENU ACCUEIL <ESCAPE>");
 
	if(typ_affiche!='f')
	{
		gotoxy(58,23);
 		cprintf("CONTINUER <ENTREE>");
	}
 	rep=getch();
 	fflush(stdin);
   	if (rep==27)
   	{
        Sleep(400);
		clrscr();
        main(); 
  	}
}

void en_tete(struct fiche reservation,int num_cl)	
{
	gotoxy(4,5);
	textcolor(10);
	if(num_cl)
	printf("DONNEES DU CLIENT NUMERO :  %d        %s",num_cl,reservation.nom_complet);
	else
	printf("DONNEES DU CLIENT NUMERO :  %d        %s",reservation.num_client,reservation.nom_complet);
}




//AFFICHAGE DU TABLEAU SI CHOIX = TARIFS
void affichage_tarifs(char tab1[][20],int nbr1,char tab2[][5],int nbr2,char tab3[][30],float tab4[][3])
{
 
   int h,i,j,axe_y;
   char rep;
   axe_y=4;
   char typ_affiche;
   char f_appel='T';

	textcolor(15);
	gotoxy(2,axe_y-2);
   for (h=0;h<nbr1;h++)
   {
       if(h==3){gotoxy(47,2);}
       else if(h==4){gotoxy(61,2);}
       printf("%s\t",tab1[h]);  
   }   
   for (i=0;i<nbr2;i++)
   {  
       gotoxy(5,axe_y);
       printf("%s\t",tab2[i]);
       printf("%s\t\t",tab3[i]);
           for (j=0;j<3;j++)
           {
                if (j==0)
                {
                    gotoxy(35,axe_y);
                }
                printf("%.2f\t\t",tab4[i][j]);
           }
             
           axe_y++;
 
   }
   typ_affiche='f';
	retour_menu(f_appel,typ_affiche);

}
