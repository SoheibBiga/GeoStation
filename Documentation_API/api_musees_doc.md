Musées de France
=======



[url de l'API (sur data.culture.gouv.fr)](https://data.culture.gouv.fr/explore/dataset/liste-et-localisation-des-musees-de-france/api/)
    
    
      
Description de la structure d'un enregistrement :
-----------------------------

| Champ | Description |
| ------ | ----------- |
|   datasetid | il y a toujours "liste-et-localisation-des-musees-de-france" dans ce champ |
| recordid | un identifiant plein de chiffres et de minuscules |
| periode_ouverture    | écrit en français en toutes lettres (pas formaté)|
| fax    | numéro de fax|
| new_regions    | nom de la région en majuscules|
| adr   | adresse|
| ville    | nom de la ville en majuscules|
|    coordonnees_finales | latitude et longitude du musée|
|    coordonnees_ban | latitude et longitude de l'adresse (Base Adressse Nationale)|
| sitweb    | url|
| ref_musee    | référence du musée (numéro)|
| telephone1   | |
| fermeture_annuelle    | écrit en français en toutes lettres (pas formaté)|
|    coordonnees_cp | latitude et longitude relatives au code postal|
| cp    | code postal|
| date_appellation    | format JJ/MM/AAAA |
| nom_du_musee   | |
| nomdep    | département|
|   type  | il y a toujours "Point" dans ce champ|
|    coordinates | longitude et latitude du musée|
| record_timestamp    | timestamp de l'enregistrement|



Forme du JSON :
-----------------
```
{

    "nhits":1253,
    "parameters":{
        "dataset":[
            "liste-et-localisation-des-musees-de-france"
        ]
        ,
        "timezone":"UTC",
        "rows":10,
        "format":"json",
        "facet":[
            "new_regions",
            "nomdep"
        ]
    }
    ,
    "records":[
        {
            "datasetid":"liste-et-localisation-des-musees-de-france",
            "recordid":"2e1eb1cd8fcae7f10f5b0cdd32fcf6bb7c93df93",
            "fields":{
                "periode_ouverture":"Ouvert d'avril à octobre. En avril, mai et octobre du lundi au vendredi de 10h à 12h et de 14h à 18h, en juin et septembre du lundi au vendredi de 10h à 12h et de 14h à 18h et le dimanche de 14h à 18h, en juillet-août du lundi au vendredi de 10h à 18h30,",
                "fax":"0297369822",
                "new_regions":"BRETAGNE",
                "adr":"Mail François Giovannelli",
                "ville":"INZINZAC-LOCHRIST",
                "coordonnees_finales":[
                    47.824797,
                    -3.252319
                ]
                ,
                "coordonnees_ban":[
                    47.824797,
                    -3.252319
                ]
                ,
                "sitweb":"www.inzinzac-lochrist.fr/Ecomusee-des-Forges.6681.0.html",
                "ref_musee":"5609001",
                "telephone1":"0297369821",
                "fermeture_annuelle":"Janvier, février",
                "coordonnees_cp":[
                    47.8561611073,
                    -3.25190412648
                ]
                ,
                "cp":"56650",
                "date_appellation":"01/02/2003",
                "nom_du_musee":"Ecomusée Industriel des Forges",
                "nomdep":"MORBIHAN"
            }
            ,
            "geometry":{
                "type":"Point",
                "coordinates":[
                    -3.252319,
                    47.824797
                ]
            }
            ,
            "record_timestamp":"2018-06-22T10:33:40+00:00"
        }
        , 
        ...
    ]
    ,
    "facet_groups":[
        {
            "name":"new_regions",
            "facets":[
                {
                    "name":"BRETAGNE",
                    "path":"BRETAGNE",
                    "count":40,
                    "state":"displayed"
                }
                ,
                ...
            ]
        }
        ,
        {
            "name":"nomdep",
            "facets":[
            (too many elements to preview)]
        }
    ]

}
```