##Satellite API
***
This documentation purpose is to give an overview of the API used to to build satellite tracking or prediction applications.



###Important information
***
This API is based on a **RE**prensational **S**tate **T**ransfert  web service.
This REST API is free but is limited to **1000 transactions/hour**.
If API used in improper ways, user will be limited or blocked.

Each request takes approximately 8 seconds on Raspberry Pi 3.



####Login
***
Each transaction must be identified and authorized with a license key.

Please, [register](https://www.n2yo.com/login/register/)  to obtain your API key. This key is unique. Then scroll down to the bottom page and generate the API Key. 
Result: "Your License Key is **6 digits - 6 digits - 6 digits - 4 digits**

The new API key will be accessible in the profile and cannot be changed.
If a new key is needed, please contact support [here](https://www.n2yo.com/about/?a=feedback).
The keys issued for the SOAP Web Services API are not valid for REST API.



####Usage
***
Satellites are identified by their NORAD catalog number which is an integer ranging from 1 to 43235 and counting. The numbers are assigned by United States Space Command (USSPACECOM) to all Earth orbiting satellites in order of identification.
If you are looking to find the id of your favorite satellite, browse categories or search the n2yo.com database until you arrive at the satellite details page, and extract the NORAD ID for your application. For instance, Space Station (ISS) is NORAD ID 25544.

For all request, method used is GET.
Each request must be composed of:
 
-	Base URL: https://www.n2yo.com/rest/v1/satellite/

-	API key: The API key (apiKey) must be appended at the end of the URL as &apiKey={your API key} 

####Search for Satellite ID
***
Before doing any request, go [here](https://www.n2yo.com/database/)   to find a satellite NORAD catalog number.
 
####Functions
***
There are five types of function available for request:

-	**Get TLE usage {tle}**

Description : Retrieve the Two Line Elements (TLE) for a satellite identified by NORAD id.

		
-	**Get satellite positions usage {position}**

Description: Retrieve the future positions of any satellite as footprints (latitude, longitude) to display orbits on maps.
 Also return the satellite's azimuth and elevation with respect to the observer location. 
 Each element in the response array is one second of calculation. 
 First element is calculated for current UTC time.

-	**Get visual passes usage {visualpasses}**

Get predicted visual passes for any satellite relative to a location on Earth.
A "visual pass" is a pass that should be optically visible on the entire (or partial) duration of crossing the sky. 
For that to happen, the satellite must be above the horizon, illumintaed by Sun (not in Earth shadow), and the sky dark enough to allow visual satellite observation. 

-	**Get radio passes usage {radiopasses}**

The "radio passes" are similar to "visual passes", the only difference being the requirement for the objects to be optically visible for observers. 
This function is useful mainly for predicting satellite passes to be used for radio communications. 
The quality of the pass depends essentially on the highest elevation value during the pass, which is one of the input parameters. 

-	**Get Above {above}**

The "above" function will return all objects within a given search radius above observer's location. The radius (θ), expressed in degrees, is measured relative to the point in the sky directly above an observer (azimuth). See image below:

![](https://www.n2yo.com/img/above.png) 

The search radius range is 0 to 90 degrees, nearly 0 meaning to show only satellites passing exactly above the observer location, while 90 degrees to return all satellites above the horizon.


####Parameters
***
- 	**TLE** 

For request :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Required</th><th>Comments</th>
</tr>
<tr>
<td>id</td><td>integer</td><td>Yes</td><td>NORAD id</td>
</tr>
</table>

At response :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Comments</th>
</tr>
<tr>
<td>satid</td><td>integer</td><td>NORAD id used in input</td>
</tr>
<tr>
<td>satname</td><td>string</td><td>Satellite name</td>
</tr>
<tr>
<td>transactionscount</td><td>integer</td><td>Count of transactions performed with this API key in last 60 minutes</td>
</tr>
<tr>
<td>tle</td><td>string</td><td>TLE on single line string. Split the line in two by \r\n to get original two lines</td>
</tr>
</table>

-	**Satellite position**

For request :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Required</th><th>Comments</th>
</tr>
<tr>
<td>id</td><td>integer</td><td>Yes</td><td>NORAD id</td>
</tr>
<tr>
<td>observer_lat</td><td>float</td><td>Yes</td><td>Observer's latitide (decimal degrees format)</td>
</tr>
<tr>
<td>observer_lng</td><td>float</td><td>Yes</td><td>Observer's longitude (decimal degrees format)</td>
</tr>
<tr>
<td>observer_alt</td><td>float</td><td>Yes</td><td>Observer's altitude above sea level in meters</td>
</tr>
<tr>
<td>seconds</td><td>integer</td><td>Yes</td><td>Number of future positions to return. Each second is a position. Limit 300 seconds</td>
</tr>
</table>

At response : 

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Comments</th>
</tr>
<tr>
<td>satid</td><td>integer</td><td>NORAD id used in input</td>
</tr>
<tr>
<td>satname</td><td>string</td><td>Satellite name</td>
</tr>
<tr>
<td>transactionscount</td><td>integer</td><td>Count of transactions performed with this API key in last 60 minutes</td>
</tr>
<tr>
<td>satlatitude</td><td>float</td><td>Satellite footprint latitude (decimal degrees format)</td>
</tr>
<tr>
<td>satlongitude</td><td>float</td><td>Satellite footprint longitude (decimal degrees format)</td>
</tr>
<tr>
<td>sataltitude</td><td>float</td><td>Satellite footprint altitude (kilometers format)</td>
</tr>
<tr>
<td>azimuth</td><td>float</td><td>Satellite azimuth with respect to observer's location (degrees)</td>
</tr>
<tr>
<td>elevation</td><td>float</td><td>Satellite elevation with respect to observer's location (degrees)</td>
</tr>
<tr>
<td>ra</td><td>float</td><td>Satellite right angle (degrees)</td>
</tr>
<tr>
<td>dec</td><td>float</td><td>Satellite declination (degrees)</td>
</tr>
<tr>
<td>timestamp</td><td>integer</td><td>Unix time for this position (seconds). You should convert this UTC value to observer's time zone</td>
</tr>
</table>

-	**Visual passes**

For request : 

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Required</th><th>Comments</th>
</tr>
<tr>
<td>id</td><td>integer</td><td>Yes</td><td>NORAD id</td>
</tr>
<tr>
<td>observer_lat</td><td>float</td><td>Yes</td><td>Observer's latitide (decimal degrees format)</td>
</tr>
<tr>
<td>observer_lng</td><td>float</td><td>Yes</td><td>Observer's longitude (decimal degrees format)</td>
</tr>
<tr>
<td>observer_alt</td><td>float</td><td>Yes</td><td>Observer's altitude above sea level in meters</td>
</tr>
<tr>
<td>days</td><td>integer</td><td>Yes</td><td>Number of days of prediction (max 10)</td>
</tr>
<tr>
<td>min_visibility</td><td>integer</td><td>Yes</td><td>Minimum number of seconds the satellite should be considered optically visible during the pass to be returned as result</td>
</tr>
</table>

At response :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Comments</th>
</tr>
<tr>
<td>satid</td><td>integer</td><td>NORAD id used in input</td>
</tr>
<tr>
<td>satname</td><td>string</td><td>Satellite name</td>
</tr>
<tr>
<td>transactionscount</td><td>integer</td><td>Count of transactions performed with this API key in last 60 minutes</td>
</tr>
<tr>
<td>passescount</td><td>integer</td><td>Count of passes returned</td>
</tr>
<tr>
<td>startAz</td><td>float</td><td>Satellite azimuth for the start of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>startAzCompass</td><td>string</td><td>Satellite azimuth for the start of this pass (relative to the observer). Possible values: N, NE, E, SE, S, SW, W, NW</td>
</tr>
<tr>
<td>startEl</td><td>float</td><td>Satellite elevation for the start of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>startUTC</td><td>integer</td><td>Unix time for the start of this pass. You should convert this UTC value to observer's time zone</td>
</tr>
<tr>
<td>maxAz</td><td>float</td><td>Satellite azimuth for the max elevation of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>maxAzCompass</td><td>string</td><td>Satellite azimuth for the max elevation of this pass (relative to the observer). Possible values: N, NE, E, SE, S, SW, W, NW</td>
</tr>
<tr>
<td>maxEl</td><td>float</td><td>Satellite max elevation for this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>maxUTC</td><td>integer</td><td>Unix time for the max elevation of this pass. You should convert this UTC value to observer's time zone</td>
</tr>
<tr>
<td>endAz</td><td>float</td><td>Satellite azimuth for the end of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>endAzCompass</td><td>string</td><td>Satellite azimuth for the end of this pass (relative to the observer). Possible values: N, NE, E, SE, S, SW, W, NW</td>
</tr>
<tr>
<td>endEl</td><td>float</td><td>Satellite elevation for the end of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>endUTC</td><td>integer</td><td>Unix time for the end of this pass. You should convert this UTC value to observer's time zone</td>
</tr>
<tr>
<td>mag</td><td>float</td><td>Max visual magnitude of the pass, same scale as star brightness. If magnitude cannot be determined, the value is 100000</td>
</tr>
<tr>
<td>duration</td><td>integer</td><td>Total visible duration of this pass (in seconds)</td>
</tr>
</table>

-	**Radio passes**

For request : 

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Required</th><th>Comments</th>
</tr>
<tr>
<td>id</td><td>integer</td><td>Yes</td><td>NORAD id</td>
</tr>
<tr>
<td>observer_lat</td><td>float</td><td>Yes</td><td>Observer's latitide (decimal degrees format)</td>
</tr>
<tr>
<td>observer_lng</td><td>float</td><td>Yes</td><td>Observer's longitude (decimal degrees format)</td>
</tr>
<tr>
<td>observer_alt</td><td>float</td><td>Yes</td><td>Observer's altitude above sea level in meters</td>
</tr>
<tr>
<td>days</td><td>integer</td><td>Yes</td><td>Number of days of prediction (max 10)</td>
</tr>
<tr>
<td>min_elevation</td><td>integer</td><td>Yes</td><td>The minimum elevation acceptable for the highest altitude point of the pass (degrees)</td>
</tr>
</table>

At response  :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Comments</th>
</tr>
<tr>
<td>satid</td><td>integer</td><td>NORAD id used in input</td>
</tr>
<tr>
<td>satname</td><td>string</td><td>Satellite name</td>
</tr>
<tr>
<td>transactionscount</td><td>integer</td><td>Count of transactions performed with this API key in last 60 minutes</td>
</tr>
<tr>
<td>passescount</td><td>integer</td><td>Count of passes returned</td>
</tr>
<tr>
<td>startAz</td><td>float</td><td>Satellite azimuth for the start of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>startAzCompass</td><td>string</td><td>Satellite azimuth for the start of this pass (relative to the observer). Possible values: N, NE, E, SE, S, SW, W, NW</td>
</tr>
<tr>
<td>startUTC</td><td>integer</td><td>Unix time for the start of this pass. You should convert this UTC value to observer's time zone</td>
</tr>
<tr>
<td>maxAz</td><td>float</td><td>Satellite azimuth for the max elevation of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>maxAzCompass</td><td>string</td><td>Satellite azimuth for the max elevation of this pass (relative to the observer). Possible values: N, NE, E, SE, S, SW, W, NW</td>
</tr>
<tr>
<td>maxEl</td><td>float</td><td>Satellite max elevation for this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>maxUTC</td><td>integer</td><td>Unix time for the max elevation of this pass. You should convert this UTC value to observer's time zone</td>
</tr>
<tr>
<td>endAz</td><td>float</td><td>Satellite azimuth for the end of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>endAzCompass</td><td>string</td><td>Satellite azimuth for the end of this pass (relative to the observer). Possible values: N, NE, E, SE, S, SW, W, NW</td>
</tr>
<tr>
<td>endUTC</td><td>integer</td><td>Unix time for the end of this pass. You should convert this UTC value to observer's time zone</td>
</tr>
</table>

-	**Above**

Since there are many satellites and debris in the sky at any point in time, the result could be filtered by satellite category (integer). The following categories are currently available at n2yo.com: 

<table>
<tr>
<td valign="top">
	<table class="gridtable">
	<tr><th>Catgory</th><th>id</th></tr>
	<tr><td>Amateur radio</td><td>18</td></tr>
	<tr><td>Beidou Navigation System</td><td>35</td></tr>
	<tr><td>Brightest</td><td>1</td></tr>
	<tr><td>Celestis</td><td>45</td></tr>
	<tr><td>CubeSats</td><td>32</td></tr>
	<tr><td>Disaster monitoring</td><td>8</td></tr>
	<tr><td>Earth resources</td><td>6</td></tr>
	<tr><td>Education</td><td>29</td></tr>
	<tr><td>Engineering</td><td>28</td></tr>
	<tr><td>Experimental</td><td>19</td></tr>
	<tr><td>Flock</td><td>48</td></tr>
	<tr><td>Galileo</td><td>22</td></tr>
	<tr><td>Geodetic</td><td>27</td></tr>
	<tr><td>Geostationary</td><td>10</td></tr>
	<tr><td>Global Positioning System (GPS) Constellation</td><td>50</td></tr>
	<tr><td>Global Positioning System (GPS) Operational</td><td>20</td></tr>
	<tr><td>Globalstar</td><td>17</td></tr>
	<tr><td>Glonass Operational</td><td>21</td></tr>
	<tr><td>GOES</td><td>5</td></tr>
	<tr><td>Gonets</td><td>40</td></tr>
	<tr><td>Gorizont</td><td>12</td></tr>
	<tr><td>Intelsat</td><td>11</td></tr>
	<tr><td>Iridium</td><td>15</td></tr>
	<tr><td>IRNSS</td><td>46</td></tr>
	<tr><td>ISS</td><td>2</td></tr>
	</table>
</td>
<td valign="top">
	<table class="gridtable">
	<tr><th>Catgory</th><th>id</th></tr>
	<tr><td>Lemur</td><td>49</td></tr>
	<tr><td>Military</td><td>30</td></tr>
	<tr><td>Molniya</td><td>14</td></tr>
	<tr><td>Navy Navigation Satellite System</td><td>24</td></tr>
	<tr><td>NOAA</td><td>4</td></tr>
	<tr><td>O3B Networks</td><td>43</td></tr>
	<tr><td>Orbcomm</td><td>16</td></tr>
	<tr><td>Parus</td><td>38</td></tr>
	<tr><td>QZSS</td><td>47</td></tr>
	<tr><td>Radar Calibration</td><td>31</td></tr>
	<tr><td>Raduga</td><td>13</td></tr>
	<tr><td>Russian LEO Navigation</td><td>25</td></tr>
	<tr><td>Satellite-Based Augmentation System</td><td>23</td></tr>
	<tr><td>Search & rescue</td><td>7</td></tr>
	<tr><td>Space & Earth Science</td><td>26</td></tr>
	<tr><td>Strela</td><td>39</td></tr>
	<tr><td>Tracking and Data Relay Satellite System</td><td>9</td></tr>
	<tr><td>Tselina</td><td>44</td></tr>
	<tr><td>Tsikada</td><td>42</td></tr>
	<tr><td>Tsiklon</td><td>41</td></tr>
	<tr><td>TV</td><td>34</td></tr>
	<tr><td>Weather</td><td>3</td></tr>
	<tr><td>Westford Needles</td><td>37</td></tr>
	<tr><td>XM and Sirius</td><td>33</td></tr>
	<tr><td>Yaogan</td><td>36</td></tr>
	</table>
</td>
</tr>
</table>

For request :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Required</th><th>Comments</th>
</tr>
<tr>
<td>observer_lat</td><td>float</td><td>Yes</td><td>Observer's latitide (decimal degrees format)</td>
</tr>
<tr>
<td>observer_lng</td><td>float</td><td>Yes</td><td>Observer's longitude (decimal degrees format)</td>
</tr>
<tr>
<td>observer_alt</td><td>float</td><td>Yes</td><td>Observer's altitude above sea level in meters</td>
</tr>
<tr>
<td>search_radius</td><td>integer</td><td>Yes</td><td>Search radius (0-90)</td>
</tr>
<tr>
<td>category_id</td><td>integer</td><td>Yes</td><td>Category id (see table). Use 0 for all categories</td>
</tr>
</table>

At response :

<table class="gridtable">
<tr>
<th>Parameter</th><th>Type</th><th>Comments</th>
</tr>
<tr>
<td>category</td><td>string</td><td>Category name (ANY if category id requested was 0)</td>
</tr>
<tr>
<td>transactionscount</td><td>integer</td><td>Count of transactions performed with this API key in last 60 minutes</td>
</tr>
<tr>
<td>satcount</td><td>integer</td><td>Count of satellites returned</td>
</tr>
<tr>
<td>startAz</td><td>float</td><td>Satellite azimuth for the start of this pass (relative to the observer, in degrees)</td>
</tr>
<tr>
<td>satid</td><td>integer</td><td>Satellite NORAD id</td>
</tr>
<tr>
<td>intDesignator</td><td>string</td><td>Satellite international designator</td>
</tr>
<tr>
<td>satname</td><td>string</td><td>Satellite name</td>
</tr>
<tr>
<td>launchDate</td><td>string</td><td>Satellite launch date (YYYY-MM-DD)</td>
</tr>
<tr>
<td>satlat</td><td>float</td><td>Satellite footprint latitude (decimal degrees format)</td>
</tr>
<tr>
<td>satlat</td><td>float</td><td>Satellite footprint longitude (decimal degrees format)</td>
</tr>
<tr>
<td>satlat</td><td>float</td><td>Satellite altitude (km)</td>
</tr>
</table>

####Command usage
***
 
Each request is construct this way:  

{Base URL}/{Function}/{NORAD_ID}/{parameters}&apiKey={your API key} 

-	TLE:
{Base URL}/**tle**/{NORAD_ID}/{parameters}&apiKey={your API key} 



####Example
***
 
-	**TLE:**

<table class="gridtable">
<tr>
<th>Base URL</th><th>Function</th><th>NORAD_ID</th><th>Parameters</th><th>apiKey</th>
</tr>
<tr>
<td>https://www.n2yo.com/rest/v1/satellite/</td><td>tle/</td></p><td>25544/</td><td>id</td><td>&apiKey=589P8Q-SDRYX8-L842ZD-5Z9 </td>   
</table>

-	**Satellite position:**

{Base URL}/**position**/{NORAD_ID}/{**id**}/{**observer\_lat**}/{**observer\_lng**}/{**observer\_alt**}/{**seconds**}&apiKey={your API key} 






	
 


 
 
 
 


