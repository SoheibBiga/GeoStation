Je fais appel à deux APIs

Le premier offre une liste d'avions en vol, dans une zone que l'on peut parametrer.
On souhaite completer les informations sur chaque avion, offert par la première API, en faisant appel à une deuxième.


La première API est issue de opensky-network.org/

La deuxième est issue aviation-edge.com/

## 			Opensky-network.org
#

API URL

https://opensky-network.org/api/states/all?lamin=45&lomin=5&lamax=48&lomax=10

This API, offered by opensky-network.org, offers live information on planes currently in flight. 

As soon as an ADS-B message of an airplane arrives at their servers, opensky-network.org creates a record for the aircraft. Such a message will only be emitted and received by servers when a plane is in flight.

ADS-B is when a plane determines its position via satellite navigation and emits the created message to Ground station receivers.

The API we use allows us to define an area by specifying minimum and maximum latitudes and longitudes.

In the above example, minimum latitude is lamin = 45, maximum longitude is lomax = 10, and so forth.

All planes with records inside this defined area will be stated in the received information.

Amongst information stated for each plane, the ICAO24 code will be of particular interest to us. Any given plane is assigned a ICAO24-bit aircraft address. We use it to call a second API to obtain further information on the plane that we would wish to work on.

https://opensky-network.org/apidoc/rest.html#all-state-vectors

JSON setout :
-----------------
```	
time	1545238020
states	
0	
0	"400e12"
1	"EZY631D "
2	"United Kingdom"
3	1545238019
4	1545238019
5	5.0864
6	45.7818
7	487.68
8	false
9	65.07
10	175.01
11	-4.23
12	null
13	518.16
14	"1000"
15	false
16	0
1	
0	"4074b7"
1	"EZY37GF "
2	"United Kingdom"
3	1545238017
4	1545238017
5	5.0866
6	45.7368
7	null
8	true
9	5.92
10	104
11	null
12	null
13	null
14	"4030"
15	false
16	0
2	
0	"3c09e4"
1	"GMI74BF "
2	"Germany"
3	1545238019
4	1545238020
5	5.3479
6	45.5769
7	11567.16
8	false
9	253.01
10	52.85
11	0
12	null
13	11330.94
14	"2302"
15	false
16	0

```


##			aviation-edge.com

API URL

http://aviation-edge.com/v2/public/flights?key=58f4c4-bf6820&limit=30000&aircraftIcao24=3c6750

'aircraftIcao24= ' allows us to specify the airplane for which we wish to retrieve information on. Addtional parameters, listed below, may also be added to the URL.

&depIata=	Departure airport IATAcode
&depIcao=	Departure airport ICAO code
&arrIata=	Arrival airport IATA code
&arrIcao=	Arrival airport ICAO code
&aircraftIcao=	Aircraft ICAO code
&regNum=	Aircraft registration number
&airlineIata=	Airline IATA code
&airlineIcao=	Airline ICAO code
&flightIata=	Flight IATA code
&flightIcao=	Flight ICAO code
&flightNum=	Flight number
&status=	Status of the flight (en-route, landed)
&limit=	Limit value for output
















JSON setout
-----------------
```
[ 
{ "geography": { "latitude": 50.3659, "longitude": 6.4578, "altitude": 5791.2, "direction": 107 }, 
"speed": { "horizontal": 751.912, "isGround": 0, "vertical": 0 }, 
"departure": { "iataCode": "BRU", "icaoCode": "EBBR" }, 
"arrival": { "iataCode": "FRA", "icaoCode": "EDDF" }, 
"aircraft": { "regNumber": "DAIZP", "icaoCode": "A320", "icao24": "3C6750", "iataCode": "A320" }, 
"airline": { "iataCode": "LH", "icaoCode": "GEC" }, 
"flight": { "iataNumber": "LH1005", "icaoNumber": "GEC1005", "number": "1005" }, 
"system": { "updated": "1545208612", "squawk": "1000" }, 
"status": "en-route" } 
]



```
