# AntrasDarbas

# [v0.1](https://github.com/EmilisDolgov/OOP-AntrasDarbas/releases/tag/0.1)
 * Realizuota programa (develop branch'e) pagal aprašymą, bei palyginta abi programos: naudojančios struct iš ankstesniojo darbos ir naudojančios class tipo Studentus iš dabartinės realizacijos spartą (veikimo laiką) priklausomai nuo failo dydžio.
 * Papildytas README.md
 * Atlikita eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3 ir papildytas README.md failas gautais rezultatais su optimizavimo flag'ais. 
 * Galutinę versiją įlieta (merge) į master branch'ą ir push'inta į GitHub'ą abu branchus: master ir develop.
 
 Vector(su struct)

 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.000939094s|0.00482475s|0.0650637s|0.926928s|9.74813s|
 |Antra strategija|0.00104192s|0.00402304s|0.0530833s|0.712356s|8.87912s|
 
 Vector(su class)

 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.000921602s|0.00896215s|0.153571s|2.01213s|25.9205s|
 |Antra strategija|0.000776534s|0.00821804s|0.162556s|2.16818s|25.5222s|
  
 Vector(O1 flagas)
 
 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.00099072s|0.00938668s|0.16706s|2.04862s|24.2209s|
 |Antra strategija|0.00104491s|0.00948226s|0.163876s|2.04326s|23.6399s|
 
 Vector(O2 flagas)
 
 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.000942935s|0.00899073s|0.159535s|1.96377s|24.2768s|
 |Antra strategija|0.000861868s|0.00814935s|0.186626s|1.92462s|23.7902s|
 
 Vector(O3 flagas)
 
 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.00102656s|0.0112768s|0.1598s|2.05783s|24.7511s|
 |Antra strategija|0.000905388s|0.00865196s|0.143649s|1.9597s|23.9378s|
 
 Vector(Ofast flagas)
 
 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.000972375s|0.00908503s|0.194644s|2.03342s|23.946s|
 |Antra strategija|0.00104192s|0.001264234s|0.146146s|1.93426s|23.2079s|

# [v0.2](https://github.com/EmilisDolgov/OOP-AntrasDarbas/releases/tag/0.2)
 * Realizuoti operatoriai
 * Sukurta Doxygen dokumentacija
 * Panaudotas std::partition/std::stable_partition
 
# [v1.0](https://github.com/EmilisDolgov/OOP-AntrasDarbas/releases/tag/1.0)
 * Sutvarkytas Git'as
 
