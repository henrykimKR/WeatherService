# WeatherService
Description
=
As a program written in C language, it is a project that shows regional precipitation information in Ontario using file input/output.  
A total of three people participated as the final project of Seneca College C programming course for the first semester.  
[Seonghoon Kim(Me), Tsun Lung Lo, Kin Shing Herman Yiu.]  

Modular programming was implemented according to the functions.  
The main functions that implement the program are included in the 'weather_service' file, and the helpful functions are included in the 'core' file.

Sample Output
=
```
=======================================================
         Ontario Weather Analysis Service
                  Year: 2021
=======================================================
1. View all data
2. View by region (sorted DESCENDING by precip.)
3. View by month (sorted ASCENDING by precip.)
4. View by location name (sorted DESCENDING by precip.)
-------------------------------------------------------
0. Exit
-------------------------------------------------------
Selection: 1

Year Month Precip.Amt Unit Region Name
---- ----- ---------- ---- ------ ---------------
2021    12       45.2    c     30 Ottawa
2021    03      743.0    m     40 Halton
2021    04       32.9    c     30 Ottawa
2021    07        8.2    c     20 Thunder Bay
2021    12      133.0    m     20 Kenora
2021    06      106.0    m     30 Renfrew
2021    01      646.0    m     40 Simcoe
2021    11       72.2    c     10 Chatham-Kent
2021    10      257.0    m     20 Thunder Bay
2021    12       54.8    c     10 Chatham-Kent
2021    11       61.5    c     40 Simcoe
2021    02       18.8    c     10 Chatham-Kent
2021    11       47.6    c     20 Kenora
2021    12       57.5    c     20 Thunder Bay
2021    09       28.1    c     20 Thunder Bay

< Press [ENTER] key to continue >

2021    05      326.0    m     30 Ottawa
2021    07      376.0    m     40 Simcoe
2021    10      515.0    m     40 Halton
2021    08       76.9    c     10 Chatham-Kent
2021    12      635.0    m     40 Simcoe
2021    07      350.0    m     10 Chatham-Kent
2021    09       48.9    c     30 Ottawa
2021    11       13.5    c     20 Thunder Bay
2021    06      143.0    m     20 Kenora
2021    04      614.0    m     20 Kenora
2021    03      299.0    m     20 Thunder Bay
2021    09      672.0    m     40 Halton
2021    07       71.7    c     40 Halton
2021    08       34.8    c     40 Halton
2021    01       13.4    c     30 Ottawa

< Press [ENTER] key to continue >

2021    09      342.0    m     20 Kenora
2021    01       51.7    c     20 Kenora
2021    06      632.0    m     40 Halton
2021    05       78.1    c     20 Kenora
2021    12       76.2    c     10 Essex
2021    08      470.0    m     30 Ottawa
2021    07      693.0    m     30 Renfrew
2021    01       28.3    c     30 Renfrew
2021    08      799.0    m     40 Simcoe
2021    11      636.0    m     30 Ottawa
2021    12      504.0    m     40 Halton
2021    08       46.6    c     30 Renfrew
2021    09      584.0    m     30 Renfrew
2021    06       23.0    m     40 Simcoe
2021    06       40.9    c     20 Thunder Bay

< Press [ENTER] key to continue >

2021    02      487.0    m     30 Renfrew
2021    03       58.8    c     20 Kenora
2021    02       65.6    c     20 Kenora
2021    06       53.3    c     10 Essex
2021    10       57.6    c     10 Chatham-Kent
2021    09       50.0    c     10 Essex
2021    04      193.0    m     10 Essex
2021    01      740.0    m     40 Halton
2021    03       64.5    c     30 Ottawa
2021    07      162.0    m     10 Essex
2021    08       18.3    c     20 Kenora
2021    01       35.4    c     20 Thunder Bay
2021    02       94.0    c     10 Essex
2021    07       64.3    c     20 Kenora
2021    10        9.0    c     40 Simcoe

< Press [ENTER] key to continue >

2021    10       43.8    c     30 Ottawa
2021    08        4.1    c     10 Essex
2021    09      618.0    m     40 Simcoe
2021    09       74.6    c     10 Chatham-Kent
2021    10      428.0    m     10 Essex
2021    05      739.0    m     30 Renfrew
2021    02       22.9    c     40 Simcoe
2021    04      739.0    m     40 Halton
2021    01       25.9    c     10 Essex
2021    05       55.5    c     20 Thunder Bay
2021    10       65.3    c     30 Renfrew
2021    03      207.0    m     10 Essex
2021    12       74.7    c     30 Renfrew
2021    05       69.1    c     10 Essex
2021    08       16.8    c     20 Thunder Bay

< Press [ENTER] key to continue >

2021    04      297.0    m     20 Thunder Bay
2021    06       76.8    c     10 Chatham-Kent
2021    03       43.0    c     40 Simcoe
2021    05       33.0    c     40 Halton
2021    02      482.0    m     20 Thunder Bay
2021    11      163.0    m     10 Essex
2021    11        6.3    c     30 Renfrew
2021    07       21.8    c     30 Ottawa
2021    05       29.0    c     40 Simcoe
2021    05       77.7    c     10 Chatham-Kent
2021    04       65.6    c     10 Chatham-Kent
2021    02      146.0    m     30 Ottawa
2021    04      149.0    m     40 Simcoe
2021    06       15.9    c     30 Ottawa
2021    10       33.8    c     20 Kenora

< Press [ENTER] key to continue >

2021    02      542.0    m     40 Halton
2021    01      759.0    m     10 Chatham-Kent
2021    03      760.0    m     10 Chatham-Kent
2021    04      602.0    m     30 Renfrew
2021    11      745.0    m     40 Halton
2021    03       20.9    c     30 Renfrew

=======================================================
         Ontario Weather Analysis Service
                  Year: 2021
=======================================================
1. View all data
2. View by region (sorted DESCENDING by precip.)
3. View by month (sorted ASCENDING by precip.)
4. View by location name (sorted DESCENDING by precip.)
-------------------------------------------------------
0. Exit
-------------------------------------------------------
Selection: 2

Region Name     Precip(mm)
------ -------- ----------
    10 Western       12498
    40 Central       12127
    30 Eastern       10074
    20 Northern       9308
------ -------- ----------
         Total:      44007
       Average:   11001.75

=======================================================
         Ontario Weather Analysis Service
                  Year: 2021
=======================================================
1. View all data
2. View by region (sorted DESCENDING by precip.)
3. View by month (sorted ASCENDING by precip.)
4. View by location name (sorted DESCENDING by precip.)
-------------------------------------------------------
0. Exit
-------------------------------------------------------
Selection: 3

Month     Precip(mm)
--------- ----------
June            2773
July            3241
August          3244
October         3295
November        3555
April           3579
February        3670
January         3692
March           3881
September       4232
December        4356
May             4489
--------- ----------
   Total:      44007
 Average:    3667.25

=======================================================
         Ontario Weather Analysis Service
                  Year: 2021
=======================================================
1. View all data
2. View by region (sorted DESCENDING by precip.)
3. View by month (sorted ASCENDING by precip.)
4. View by location name (sorted DESCENDING by precip.)
-------------------------------------------------------
0. Exit
-------------------------------------------------------
Selection: 4

Location        Precip(mm)
--------------- ----------
   Chatham-Kent       7619
         Halton       7227
        Renfrew       5632
         Kenora       5414
         Simcoe       4900
          Essex       4879
         Ottawa       4442
    Thunder Bay       3894
--------------- ----------
         Total:      44007
       Average:    5500.88

=======================================================
         Ontario Weather Analysis Service
                  Year: 2021
=======================================================
1. View all data
2. View by region (sorted DESCENDING by precip.)
3. View by month (sorted ASCENDING by precip.)
4. View by location name (sorted DESCENDING by precip.)
-------------------------------------------------------
0. Exit
-------------------------------------------------------
Selection: 0

Application Terminated!
```
