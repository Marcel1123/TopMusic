

void MyManual(){
	if(strcmp(msg,"manual\n")==0){

		strcat(msgrasp,"Sunteti in manual\n" );
		strcat(msgrasp,"Puteti accesa urmatoarele comenzi:  \n" );
		strcat(msgrasp,"\"login\" -> Pentru a va loga la un cont existent.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.login\"\n" );

		strcat(msgrasp,"\"register\" -> Pentru a va inregistra un cont nou.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.register\"\n" );

		strcat(msgrasp,"\"add\" -> Pentru a adauga o noua melodie.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.add\"\n" );

		strcat(msgrasp,"\"vote\" -> Pentru a vota o melodie.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.vote\"\n" );

		strcat(msgrasp,"\"list\" -> Pentru a lista un top de melodii.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.list\"\n" );

		strcat(msgrasp,"\"remove\" -> Pentru a sterge o melodie.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.remove\"\n" );

		strcat(msgrasp,"\"blockvote\" -> Pentru a sterge dreptul de vot al unui user.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.blockvote\"\n" );

		strcat(msgrasp,"\"unblockvote\" -> Pentru a reda dreptul de vot al unui user.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.unblockvote\"\n" );

		strcat(msgrasp,"\"bann\" -> Pentru a bloca contul unui user.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.bann\"\n" );

		strcat(msgrasp,"\"unbann\" -> Pentru a debloca contul unui user.\n");
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.unbann\"\n" );

		strcat(msgrasp,"\"comment\" -> Pentru a adauga un comentariu la o melodie.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.comment\"\n" );

		strcat(msgrasp,"\"istoric\" -> Pentru a afisa istoricul comenzilor sale.\n" );
		strcat(msgrasp,"\tPentru mai multe informatii utilizati comanda \"manual.istoric\"\n" );

		strcat(msgrasp,"\"logout\" -> Pentru a delogare.\n" );
		strcat(msgrasp,"\"quit\" Pentru a inchide un client.\n");
		strcat(msgrasp,"\"report\" -> Pentru a raprta un cont.\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if (strcmp(msg,"manual.register\n")==0){

		strcat(msgrasp,"\n\t\tManual register\n");
		strcat(msgrasp,"\nAceasta comanda este folosita pentru a va crea un nou cont.\n");
		strcat(msgrasp,"\nDupa ce tastati comanda trebuie sa introduceti urmatoarele date: ");
		strcat(msgrasp,"\n\tUsername: (ATENTIE Maxim 15 caractere)\nExemplu: \n");
		strcat(msgrasp,"\tIntruduceti username: contul_meu\n\n");
		strcat(msgrasp,"\tParola: (ATENTIE Maxim 15 caractere)\nExemplu: \n");
		strcat(msgrasp,"\tIntruduceti Parola: parola_mea\n");
		strcat(msgrasp,"Tipul de utilizator: user sau admin\n\n");
		strcat(msgrasp,"user-ul poate vota si adauga o melodie sau un comentariu la o melodie\n");
		strcat(msgrasp,"admin-ul poate vota,adauga o melodie sau un comentariu, sterge o melodie,\n");
		strcat(msgrasp,"bloca dreptul de vot al unui user sau blocarea contului acestuia\n");
		strcat(msgrasp,"Daca inregistrarea s-a realizat cu succes trebuie sa primiti urmatorul mesaj:\n");
		strcat(msgrasp,"\t\"Contul a fost creat cu succes.\"\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	}else if(strcmp(msg,"manual.login\n")==0){

		strcat(msgrasp,"\n\t\tManual login\n");
		strcat(msgrasp,"\nAceasta comanda este folosita pentru a va loga cu un cont existent.\n");
		strcat(msgrasp,"\nDupa ce introduceti comanda trebuie sa introduceti un username si o parola valide.");
		strcat(msgrasp,"\nExemplu: \n");
		strcat(msgrasp,"\tIntruduceti username: contul_meu \n");
		strcat(msgrasp,"\tIntruduceti parola: parola_mea \n");
		strcat(msgrasp,"Daca logarea sa realizat cu succes trebuie sa primiti urmatorul mesaj: \n");
		strcat(msgrasp,"\t\"Ati fost logat cu succes. \"\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.add\n")==0){

		strcat(msgrasp,"\n\t\tManual add\n");
		strcat(msgrasp,"\nCu aceasta comanda puteti adauga o noua melodie.\n");
		strcat(msgrasp,"\nDupa ce tastati comanda trebuie sa introduceti urmatoarele date: \n");
		strcat(msgrasp,"\tNume melodie: (ATENTIE Maxim 30 caractere)\nExemplu: \n");
		strcat(msgrasp,"\tIntruduceti numele melodiei: La multi ani!\n");
		strcat(msgrasp,"\tDescriere: (ATENTIE Maxim  100 caractere)\nExemplu: \n");
		strcat(msgrasp,"\tIntruduceti o descriere: Aceasta melodie este una speciala! :))\n");
		strcat(msgrasp,"\tGen: (ATENTIE Maxim 20 caractere)\nExemplu: \n");
		strcat(msgrasp,"\tIntruduceti genul: Petrecere\n");
		strcat(msgrasp,"\tURL: (ATENTIE Maxim 50 caractere)\nExemplu: \n");
		strcat(msgrasp,"\thttps://www.youtube.com/watch?v=qwe!aAD\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.vote\n")==0) {

		strcat(msgrasp,"\n\t\tManual vote\n");
		strcat(msgrasp,"\nCu aceasta comanda puteti vota o melodie dintr-un top.\n");
		strcat(msgrasp,"\nComanda are urmatoarea structura: \n");
		strcat(msgrasp,"\tvote \"Nume melodie\":\"Top\"\n");
		strcat(msgrasp,"\nAceasta comanda se intoduce in felul urmator: \n");
		strcat(msgrasp,"\tvote La multi ani!:Petrecere\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.list\n")==0) {

		strcat(msgrasp,"\n\t\tManual list\n");
		strcat(msgrasp,"\nAceasta comanda listeaza un top sau toate melodiile.\n");
		strcat(msgrasp,"\nComanda are urmatoarea structura: \n");
		strcat(msgrasp,"\tlist \"Top\" sau list all\n");
		strcat(msgrasp,"list all -> afiseaza toate melodiile din baza de date ordonate dupa voturi.\n");
		strcat(msgrasp,"\tExemplu: \n");
		strcat(msgrasp,"\tlist Rock\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.remove\n")==0) {

		strcat(msgrasp,"\n\t\tManual remove\n");
		strcat(msgrasp,"\t!!!ACEASTA COMANDA ESTE DOAR PENTRU ADMINISTRATORI!!!\n");
		strcat(msgrasp,"\nAceasta comanda sterge o melodie dintr-un top specificat.\n");
		strcat(msgrasp,"\nComanda are urmatoarea structura: \n");
		strcat(msgrasp,"\tremove \"APASATI ENTER\"\n");
		strcat(msgrasp,"\tIntruduceti numele: \n");
		strcat(msgrasp,"\tIntruduceti genul: \n");
		strcat(msgrasp,"\n\tExemplu: \n");
		strcat(msgrasp,"Introduceti numele: Melodie 1\n");
		strcat(msgrasp,"Introduceti genul: Pop\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.blockvote\n")==0) {

		strcat(msgrasp,"\n\t\tManual blockvote.\n");
		strcat(msgrasp,"\t!!!ACEASTA COMANDA ESTE DOAR PENTRU ADMINISTRATORI!!!\n");
		strcat(msgrasp,"\nAceasta comanda este folosita de un administrator pentru a sterge drepul de vot al unui user.\n");
		strcat(msgrasp,"Comanda are urmatoarea structura: \n");
		strcat(msgrasp,"\t blockvote \"Username\"\n");
		strcat(msgrasp,"\tExemplu: \n");
		strcat(msgrasp,"\t blockvote marcel\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.unblockvote\n")==0) {

		strcat(msgrasp,"\n\t\tManual unblockvote.\n");
		strcat(msgrasp,"\t!!!ACEASTA COMANDA ESTE DOAR PENTRU ADMINISTRATORI!!!\n");
		strcat(msgrasp,"\nAceasta comanda este folosita de un administrator pentru a reda drepul de vot al unui user.\n");
		strcat(msgrasp,"Comanda are urmatoarea structura: \n");
		strcat(msgrasp,"\t unblockvote \"Username\"\n");
		strcat(msgrasp,"\tExemplu: \n");
		strcat(msgrasp,"\t unblockvote marcel\n"); 
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");
		
	} else if(strcmp(msg,"manual.bann\n")==0) {

		strcat(msgrasp,"\n\t\tManual bann.\n");
		strcat(msgrasp,"\t!!!ACEASTA COMANDA ESTE DOAR PENTRU ADMINISTRATORI!!!\n");
		strcat(msgrasp,"\nAceasta comanda este folosita de un administrator pentru a bloca contul unui user.\n");
		strcat(msgrasp,"Comanda are urmatoarea structura: \n");
		strcat(msgrasp,"\t bann \"Username\"\n");
		strcat(msgrasp,"\tExemplu: \n");
		strcat(msgrasp,"\t bann marcel\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.unbann\n")==0) {

		strcat(msgrasp,"\n\t\tManual unbann.\n");
		strcat(msgrasp,"\t!!!ACEASTA COMANDA ESTE DOAR PENTRU ADMINISTRATORI!!!\n");
		strcat(msgrasp,"\nAceasta comanda este folosita de un administrator pentru a debloca contul unui user.\n");
		strcat(msgrasp,"Comanda are urmatoarea structura: \n");
		strcat(msgrasp,"\t unbann \"Username\"\n");
		strcat(msgrasp,"\tExemplu: \n");
		strcat(msgrasp,"\t unbann marcel\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else if(strcmp(msg,"manual.comment\n")==0) {

		strcat(msgrasp,"\n\t\tManual comment.\n");
		strcat(msgrasp,"\tDupa ce tastati comanda intoduceti nmele melodiei, genul melodiei si comentariul.\n");
		strcat(msgrasp,"\n\n\t<---------OK--------->\n");

	} else {

		strcat(msgrasp,"Comanda introdusa este incorecta. \n");

	}
}
