332CC Achtar Mohamad 


Am facut mai multe functie unde am vazut 
ca trebuie sa scriu mai multe lin de code .

my_itoa:
e o functie care ma ajuta sa transfor 
string in int si e legata de functia 
printInt , la functia asta ma picat tot timpu un test
si trebuia sa folosesc o variabila de tip long long, 
am luat in considerare si cand numaru e minus , pentru asta 
am lasat un if special  .


UnitTrans:
o functie care transforma unsigend int 
in string si e legata de functia 
UnitPrint , e acelasi functia de la hexadecemal dar ,
e modificata putin , sa fie bun pentru unsigend int.


hexadecemal:
o functie care transforma  int 
in hexadecemal si e legata de functia 
printHexa , aici am folosit metoda celebra de transforma din int in hexadecemal
, si o sa las cu un link de unde m-am inspirat pentru asta .

printInt:
e functie care depinde de my_itoua , aloca memorie dinamica pentru 
sa salvezi rezultatu din my_itoua , salvezi si rezultatu de la
strlen in length a fisezi cu functia write_stdout , si returnezi length .

printUint:
e functie care depinde de UnitTrans, aloca memorie dinamica pentru 
sa salvezi rezultatu din UnitTrans: , salvezi si rezultatu de la
strlen in length a fisezi cu functia write_stdout , si returnezi length .


printHexa:
e functie care depinde de hexadecemal, aloca memorie dinamica pentru 
sa salvezi rezultatu din hexadecemal, salvezi si rezultatu de la
strlen in length a fisezi cu functia write_stdout si returnezi length .



iocla_printf:
Am folosit  va_list args si  va_start cum a fost explicat in enunti ,
aloc memorie dinmaica pentru buffer care sa fie suficienta pentru a nu 
da overflow , verific cu if si elfesle fie care caz ,
afisezi bufferul cu write_stdout si eliberezi mermoria,returnezi lenMax la sfercit.



