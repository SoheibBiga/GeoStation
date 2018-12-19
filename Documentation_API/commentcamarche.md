##Etape 1 :

####Objectif de l'etape: Lancer les requêtes URL

Créer une classe héritant de AbstractApi nommée MaclasseApi.
Vous devez utiliser le constructeur suivant :

	explicit AbstractApi(int myId, ordonnanceur *ord_, QObject *parent = 0,QString longitude_ = "2.346051", QString latitude_ = "48.871517", QString radius_ = "500");
	

La liste d'initialisation du constructeur de votre classe fille sera de la forme :

	SncfApi::SncfApi(ordonnanceur *ord_, QObject *parent): AbstractApi(IdWidget(Sncf), ord_, parent)

Vous devez obligatoirement donner un objet de type ordonnanceur* dans votre constructeur.
Par ailleurs, lors de l'appel du constructeur du parent, il faut indiquer l'Id correspondant à votre API.

Vous remarquerez la présence d'un QEventLoop et d'une fonction finish dans AbstractApi, vous devez simplement utiliser la fonction finish (avec en argument un bool pour le code de retour). 
Lors des requêtes de votre API, lancer finish lorsque l'ensemble des requêtes sont terminées ou lorsqu'il y a une erreur durant le processus.

##Etape 2 :

####Objectif  de l'étape : Faire le design pour votre API

Ajouter une nouvelle classe MaClasseWiget de type Qt : Classe d'interface graphique Qt, cela crée trois fichiers, .cpp, .h et .ui.

Faites hériter votre classe de AWidget.
Vous devez utiliser le constructeur suivant :
	
	explicit AWidget(QWidget* parent = 0);
	
Dans votre classe fille MaClasseWidget, il faut rajouter la déclaration du signal suivant :
	
	signals:
    	void send_info(QMap<QString,QString>);
    	
 
 Il faut aussi rajouter un slot :
 
 	private slots:
    	void receive_info(QMap<QString,QString>);

Ce slot permet de gérer les informations reçus, pour l'instant on a seulement un objet de type [QMap(QString,QString)], mais cela va très problablement changer.
Vous devez donc implémenter ce slot afin qu'il interragisse avec le ui de MaClasseWidget.

Exemple : SncfWidget

Dans l'ui SncfWidget j'ai ajouté un QTableWidget que j'ai promu en TableauWidget.
Ainsi l'implementation du slot receive_info s'effectue comme suit :

	void sncfwidget::receive_info(QMap<QString, QString> map_formulaire)
	{
    	ui->tableWidget->refresh(map_formulaire);
	}
	
	
Widgets disponibles:

- TableauWidget

~~~cpp 
Entrées : QMap <QString,QString>
~~~
Permet de présenter sous forme de tableau key/value.
Cf : Ghania

- GraphWidget
~~~cpp 
Entrées : QMap <QDateTime,int>
~~~
Permet de présenter sous forme d'un graphique rectiligne les données.
Cf : Charles

NB : Les classes mères AbstractApi et AWidget contiennent des fonctions virtuelles pures, veillez bien à les implémenter dans les classes filles correspondantes.