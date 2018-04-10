# PirmasDarbas

## Vertinimas

**Pastabos:**

- [x] Reiktu i gitignore prideti kai kuriuos nereikalingus failus
- [x] Releasai turetu buti issamesni
- [x] Truksta eksperimentu ataskaitos README faile

**Privalumai:**

- Tvarginkas stilius ir kodas


Pirmoji programa
# [v0.1](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v0.1)
* Pradėta programa
 * Įvedus vardą, pavardę, pažymius ir egzamino balą programa apskaičiuoja galutinį balą
# [v0.2](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v0.2)
* Programa papildyta galimybe duomenis ne tik įvesti, bet ir skaityti iš failo
# [v0.3](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v0.3)
* Refactoringas
# [v0.4](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v0.4)
* Programa sugeneruoja norimo dydžio tekstinį failą su duomenimis
* Išmatuojamas tikslus programos veikimo laikas
# [v0.5](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v0.5)
* Trys konteinerių tipai (vector,list,deque)
* Exception handling'as
* Studentų skirstymas į prileistus prie egzamino ir neprileistus
# [v1.0](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v1.0)
* Pridėtas README.md failas
# [v1.1](https://github.com/EmilisDolgov/PirmasDarbas/releases/tag/v1.1)
* Programa optimizuota
* Ištrintas rankinis output'as
* Pridėta daugiau algoritmų, veikia daug greičiau.

## Ataskaita
Failo generavimas

 |10|100|1000|10000|100000|
 |---|---|---|---|---|
 |0.00316715s|0.00542763s|0.0585664s|0.509385s|4.9661s|

Vector

 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.000939094s|0.00482475s|0.0650637s|0.926928s|9.74813s|
 |Antra strategija|0.00104192s|0.00402304s|0.0530833s|0.712356s|8.87912s|
 
List

 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.00108885s|0.00481579s|0.0599045s|0.713983s|7.17883s|
 |Antra strategija|0.00105344s|0.00404736s|0.0408282s|0.683421s|6.89246s|

Deque

 |Konteinerio dydis|10|100|1000|10000|100000|
 |---|---|---|---|---|---|
 |Pirma strategija|0.00109227s|0.00428288s|0.0749376s|0.821196s|9.73092s|
 |Antra strategija|0.000796161s|0.00476544s|0.0551847s|0.724776s|9.07986s|
