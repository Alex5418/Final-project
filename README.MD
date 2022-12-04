# Final Project For Team4321
**Contributed by Sirui Zhang, Muye Yuan, Yiduo Wang, Zonghan Wu** 
## Introduction
This project is done by team4321 in 2022 fall semester cs 225 class. The datasets come from Openflights, and this project can help you find the shortest routes between two airports, and give you a list of the 10 most important airports in the world. Although all the datasets come from 2014, but we can still get important ideas from the history. We hope this project can help people to learn data structure and use it to find the shortest route. Hope you enjoy our project.
- Main algorithms: BFS, Dijkstra, and PageRank
- How these algorithms work:
  - BFS: Used to find all routes between two airports
  - Dijkstra: Used to find the shortest route
  - PageRank: Used to find the most important airports
## Documents
### /data
  -Contain airports.txt, Routes.txt which are two datasets we used in this project. Besides these two, we have airports_test which used in testcase, and tmp.txt for BFS since it will run a very long time for BFS to go through all routes. [Link]https://github.com/Alex5418/Final-project/tree/main/data
### /entry
  -Contain main.cpp, which we used to run all algorithms, and read files. This part is vital for us to show how this code can work. You can use code from this part to seeoutputs. [Link]https://github.com/Alex5418/Final-project/blob/main/entry/main.cpp
### /lib
 - Help to build environment [link]https://github.com/Alex5418/Final-project/tree/main/lib
### /src
  - This is the folder we have all algorithms, and readfile in. Airport.cpp and Airport.h are for after reading files, we can use fuctions inside to assign data into mean variable including airport_id, name, city, country, IATA, ICAO, latitude, longtitude, altitude. Similarly, routes.cpp and routes.h are used to assign routes after reading file. [link]https://github.com/Alex5418/Final-project/blob/main/src/Airport.cpp, [link]https://github.com/Alex5418/Final-project/blob/main/src/route.cpp
  - filereading.h and filereading.cpp help us to read data into correct forms. For example, we need to get substring by GetSubstrs from txt file, and some strings have quotation mark we want to use remove_quote to remove them. Then we give data meanings by readairport and readairroute. In this file, we also have distance to find the distance in km between two airports. [link]https://github.com/Alex5418/Final-project/blob/main/src/filereading.cpp
  - 
