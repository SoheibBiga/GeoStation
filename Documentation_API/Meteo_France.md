#Meteo France API

This documentation present the API of Meteo France, how to use it and what you can find in it.

##Presentation

You have to go on [OpenDataSoft](https://public.opendatasoft.com/explore/?sort=modified), there are several data set, you can use the filter to make a search.

##Weather Data Set

For the weather, there is two interesting data set, "Vigilance Meteorologique France" and "Prevision Meteo France", for each you have also the historique for example "Observation métérologique historiques France".

On [Prévision Météo France](https://public.opendatasoft.com/explore/dataset/arome-0025-sp1_sp2/table) you have the temperature, the humidity and the raining until H+36h.

On [Vigilance Météorologique](https://public.opendatasoft.com/explore/dataset/vigilance-meteorologique/table/) you have a color which indicate the state of the department and if there is a risk it inform you the kind.

On [](https://public.opendatasoft.com/explore/dataset/vigilance-meteorologique/table/) you have a color which indicate the state of the department and if there is a risk it inform you the kind.

To know what kind of data there is, you have to go on the tab [Informations](https://public.opendatasoft.com/explore/dataset/arome-0025-sp1_sp2/information)

You have to go on the last tab [API](https://public.opendatasoft.com/explore/dataset/arome-0025-sp1_sp2/api/), and there make your request, you can find all the documentation about the request on [doc](https://help.opendatasoft.com/apis/ods-search-v1/#record-search-api).

####Request :

The field "geofilter.distance" limit the result set to a geographical area defined by a circle, you have to put latitude, longitude and the radius (in meter).
If there is zero results from your research you have to put a bigger number for the radius (500 meters) which not that bad for the weather.

####Get the data set :

Once you did you request you can take a look on the result in the tab "Tableau", to download you have just go to the tab "Export" and choose the format (.json in preference).
