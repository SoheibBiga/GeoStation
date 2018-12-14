

# Vigicrues API

This documentation briefly introduces OpenDataSoft's government API "Vigicrues - Hauteurs et débits des cours d’eau".

# Presentation

##

The Vigicrues network continuously collects water levels and stream flows observed in real time on nearly 1700 teletransmitted measuring points in France, as well as their evolutions during the last days and hours.

##

These measurements can be viewed on the Vigicrues site: the flow presented here, to encourage the re-use of data, corresponds to the raw data of these water levels and stream flows.

##

The published data is the most recent in our possession, transmission delays being necessary. They correspond to raw data produced by automatic measuring stations.

#

##

The main address of the API is located here https://public.opendatasoft.com/explore/dataset/vigicrues/api/.
The governmental site is here https://www.data.gouv.fr/fr/datasets/hauteurs-deau-et-debits-des-cours-deau-observes-en-temps-reel-aux-stations-du-reseau-vigicrues/.

# Licence

The dataset is under license : Open License v2.0 (Etalab).
Each user can access the public space and view data set without opening an account.
For larger uses, the conditions of OpenDataSoft may change.


# Request

A more general presentation is available here https://help.opendatasoft.com/apis/ods-search-v1/#search-api-v1.

A request looks like [data.opendatasoft.com/api/records...](https://public.opendatasoft.com/api/records/1.0/search/?dataset=vigicrues&q=timestamp+%3E%3D+2018-12-14T06%3A00%3A00%2B00%3A00+AND+station_id+%3D+F704000101&rows=1000&sort=timestamp&facet=station_id&facet=lbstationhydro&facet=cdcommune&facet=timestamp&facet=cdzonehydro&geofilter.distance=48.862725%2C+2.287592%2C+5000 "Md comment")

The most important parameters are in the following list.

- dataset : vigicrues, Identifier of the dataset. This parameter is mandatory
- q : Full-text query performed on the result set
- lang : 2 letter language code
- format : Format of the response output. Can be json (default) or jsonp

#

- rows : Number of results to return in a single call. By default, 10 results are returned.
- start : Index of the first result to return (starting at 0). Use in conjunction with rows to implement paging
- sort : Sorts results by the specified field. By default, the sort is descending
- facet : Activate faceting on the specified field (see list of fields in the Query Language section)
- refine : Limit the result set to records where FACET has the specified value
- exclude : Exclude records where FACET has the specified value from the result set
- geofilter.distance : Limit the result set to a geographical area defined by a circle center (WGS84) and radius (in meters): latitude, longitude, distance
- geofilter.polygon : Limit the result set to a geographical area defined by a polygon (points expressed in WGS84): ((lat1, lon1), (lat2, lon2), (lat3, lon3))

# JSON

The API return a JSON which have several fields.
Most important are :

- nhits, Number of records
- station_id
- lbstationhydro
- cdcommune
- timestamp, measurement date
- hauteur, measured height
- debit, m3/s
- cdzonehydro
- ...

# 

Example of JSON :

{

    "nhits":1,
    "parameters":{
        "dataset":[
            "vigicrues"
        ]
        ,
        "timezone":"UTC",
        "q":"timestamp >= 2018-12-13T11:00:00+00:00 AND station_id = F704000101",
        "rows":10,
        "format":"json",
        "geofilter.distance":[
            "48.862725, 2.287592, 5000"
        ]
        ,
        "facet":[
            "station_id",
            "lbstationhydro",
            "cdcommune",
            "timestamp",
            "cdzonehydro"
        ]
    }
    ,
    "records":[
        {
            "datasetid":"vigicrues",
            "recordid":"0090442a4e4843fd84d980a37ec14ebaa2c72725",
            "fields":{
                "dist":"4132",
                "lbstationhydro":"La Seine à Suresnes - Barrage (amont)",
                "cdcommune":"92073",
                "timestamp":"2018-12-13T11:00:00+00:00",
                "coordonneeswgs84":[
                    48.8701786417,
                    2.23219714413
                ]
                ,
                "station_id":"F704000101",
                "cdzonehydro":"F704",
                "hauteur":5.314
            }
            ,
            "geometry":{
                "type":"Point",
                "coordinates":[
                    2.23219714413,
                    48.8701786417
                ]
            }
            ,
            "record_timestamp":"2018-12-13T11:21:00+00:00"
        }
    ]
    ,
    "facet_groups":[
        {
            "name":"station_id",
            "facets":[
                {
                    "name":"F704000101",
                    "path":"F704000101",
                    "count":1,
                    "state":"displayed"
                }
            ]
        }
        ,
        {
            "name":"lbstationhydro",
            "facets":[
                {
                    "name":"La Seine à Suresnes - Barrage (amont)",
                    "path":"La Seine à Suresnes - Barrage (amont)",
                    "count":1,
                    "state":"displayed"
                }
            ]
        }
        ,
        {
            "name":"cdcommune",
            "facets":[
                {
                    "name":"92073",
                    "path":"92073",
                    "count":1,
                    "state":"displayed"
                }
            ]
        }
        ,
        {
            "name":"timestamp",
            "facets":[
                {
                    "name":"2018",
                    "path":"2018",
                    "count":1,
                    "state":"displayed"
                }
            ]
        }
        ,
        {
            "name":"cdzonehydro",
            "facets":[
                {
                    "name":"F704",
                    "path":"F704",
                    "count":1,
                    "state":"displayed"
                }
            ]
        }
    ]

}


# Field recovery in QT

You can retrieve fields in QT as follows :
QNetworkReply *reply;
jsonrep=QJsonDocument::fromJson(reply->readAll());
jsonobj=jsonrep.object();
QJsonArray MonJSonArray = jsonobj.value(QString("records")).toArray();

Puis :

- MonJSonArray[i].toObject().value(QString("fields" )).toObject().value(QString("dist")).toString();
- MonJSonArray[i].toObject().value(QString("fields" )).toObject().value(QString("lbstationhydro")).toString();
- MonJSonArray[i].toObject().value(QString("fields" )).toObject().value(QString("hauteur")).toDouble();

# Treatment performance

The request http until the reception of the answer takes 3 to 4 tenths of a second with a Raspberry Pi 3.
Processing and accessing json data can take a few tenths of a second.



