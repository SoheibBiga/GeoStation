#Event API
This documentation describes how to use event API.
The purpose of its API is to list all public events happening around a circle of a given distance. It concerns either current events in the present either upcoming ones in the future.


## Functional presentation
Event API calls a webservice which requests a network server in order to gather expected events. 

### Type of events
Event API enables to search different type of events:
 - concerts
 - sport events
  - drama 
  - lectures
  ....

###Place of event
The place of the event is calculated through a geo-location provided by the user who sets up:
 - longitude position
 - lattitude position
 - radius: scope of distance based on a number of meters
These 3 parameters (latitude, longitude, distance) define a geographical area.


## Technical presentation
### Network server (URL)
Network server is fed by OpenData's government which broadcasts all event data through dedicated APIs: satellites, museums, trains...
Main address is available through this specific URL: 
 https://public.opendatasoft.com/api/records/1.0/search/?dataset=evenements-publics 

## JSON
API communicates data between a network browser and a server in text format using JSON syntax.
JSON stands for **J**ava**S**cript **O**bject **N**otation.
It s a lightweight data-interchange format in text only.
Text is read and used as a data format by C++ (programming language).
### INPUT

Network request:
https://public.opendatasoft.com/api/records/1.0/search/?dataset=evenements-publics-cibul&rows=20&sort=date_start&facet=tags&facet=placename&facet=department&facet=region&facet=city&facet=date_start&facet=date_end&facet=pricing_info&facet=updated_at&facet=city_district&refine.date_start="+QString(dateAffichee)+"&geofilter.distance="+QString::number(latitude)+"%2C+"+QString::number(longitude)+"%2C+"+QString::number(radius))
    

### OUTPUT
nhits	312
parameters	{…}
records	
0	
datasetid	"evenements-publics-cibul"
recordid	"0c8c269582336c100e8b899a395b8718e859ad44"
fields	
latlon	
0	48.871801
1	2.343854
lang	"fr"
dist	"164"
uid	"84823653"
title	"Nuit de la lecture 2019 rap et littérature !"
pricing_info	"entrée libre sur inscription"
date_end	"2019-01-20"
date_start	"2019-01-20"
updated_at	"2018-12-19T10:57:52+00:00"
space_time_info	"le dimanche 20 janvier 2019 à Librairie ICI"
department	"Paris"
city	"Paris"
link	"http://openagenda.com/event/nuit-de-la-lecture-2019-rap-et-litterature"
free_text	"Une nuit consacrée au rap et à la littérature !\n\nRencontrez Abd al Malik, rappeur, auteur-compositeur-interprète, écrivain et réalisateur français qui échangera autour du rap et de la littéraire et lira ses textes préférés. D'autres rappeurs invités à découvrir dans les prochaines semaines."
address	"25 boulevard Poissonnière Paris"
timetable	"2019-01-20T16:30:00 2019-01-20T17:30:00;2019-01-20T20:00:00 2019-01-20T21:00:00;2019-01-20T21:00:00 2019-01-20T22:00:00;2019-01-20T22:30:00 2019-01-20T23:30:00;2019-01-20T23:30:00 2019-01-20T00:30:00"
placename	"Librairie ICI"
region	"Île-de-France"
tags	"rap,littérature,rap,abd al malik"
description	"Rencontres de rappeurs autour de leurs influences littéraires"
geometry	
type	"Point"
coordinates	
0	2.343854
1	48.871801
record_timestamp	"2018-12-19T10:57:52+00:00"





















