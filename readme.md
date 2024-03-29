
Takze, zadanie sa nachádza tu dole. Template sa nachadza v apps-thread-demo. Podla zadania som vytvoril insert sort funkciu, ktoru mam v zlozke search_max a potrebujem to aplikovat podla zadania a template.


Tasks

Implementujte třídění pole čísel s pomocí vláken.

Využijte jeden ze tří algoritmů dle následujícího klíče: login_uživatele % 3, tedy např. oli10 -> 10 % 3 = 1 a algoritmy jsou 3 v poli [ přímý_výběr, přímé vkládání, bubble_sort ]. Pro oli10 tedy přímé vkládání.
// ja mam priamy vyber

Dále sudý login bude mít čísla long a třídění vzestupně a lichý login int a třídění sestupně.

1. Napište si program, ve kterém si ověříte, že třídící algoritmus funguje správně a hlavně třídí správně jen zadanou část pole!

2. Upravte program tak, aby se při spuštění jako parametry musela zadat délka pole a počet vláken pro třídění.

3. V programu se nejprve vygenerují náhodná čísla v rozsahu <-109 - 109 > a vytvoří se kopie pole.

4. Provede se setřídění prvního pole v jednom vlákně a změří se čas třídění.

5. Druhé pole se rozdělí na požadovaný počet dílů a každý díl se bude následně třídit ve vlastním vlákně (paralelně s ostatními vlákny). Změří se čas třídění.

6. Jednotlivé setříděné části se spojí v jeden výsledek (např. 1, 2). Spojování ideálně vždy jen po dvojicích, nemá smysl spojovat 3, 4 a více částí současně. Spojování má složitost O(N) a čas spojování je zanedbatelný ve srovnání s časem třídění. Čas spojování se změří.

7. Porovnání prvního a druhého výsledku třídění, zda jsou výsledky shodné.

8. Finální měření času proveďte na počítači na učebně pro 2-3-4-5-6 vláken. Stačí se k počítači připojit vzdáleně. Délku pole nastavte tak, aby třídění bez vláken trvalo alespoň 30s. Naměřené hodnoty z jednotlivých měření uložte do souboru a ten přiložte do Kelvina ke zdrojovému kódu. Seznam počítačů učebny je na stránce předmětu a pro třídění bude vyhrazen ten poslední uvedený počítač (IP končí 85).

