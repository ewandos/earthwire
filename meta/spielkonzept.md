# Operation Earthwire

Operation Blitzableiter - Angelehnt an den Namen „The Blitz“ den die englische Bevölkerung den deutschen Luftangriffe gab, welche gegen Großbritannien geflogen wurden.

*Das Setting* ist dem entsprechend zwischen 1940 - 1941 in Großbritannien. Der Spieler schlüpft in die Rolle eines englischen Elite-Piloten, welcher den Blitzangriff der deutschen Wehrmacht stoppen bzw. „ableiten“ soll.

Das Spiel bedient sich dabei dem *Shoot them Up* Genre. Man steuert ein Spitfire-Flugzeug und muss den herannahenden deutschen Flugzeugen entgegentreten. *Ressourcen* sind dabei Ammunition (Munition), um die Gegner zu zerstören und Hull (Rüstung) was unseren Lebenspunkten entspricht. Die Gegner werden zufällig erzeugt und geben beim erfolgreichen Abschuss Punkte. Ziel ist es so lange wie möglich durchzuhalten und Punkte zu erhalten. Die Punkte werden am Ende in ein *Scoreboard* abgespeichert.

---

## System & Spielmechanik
Benutzt wird das gesamte *Steuerkreuz* für die Navigation. Der *A&B-Knopf* wird zum schießen und nachladen benutzt. Der *META-Knopf* bleibt zum pausieren des Spiels. Das Aussehen des Spiels wird auf farbige Pixelgrafik reduziert, die durch die Engine des Gamebuino eingefügt werden können. Bei Schüssen und Treffern sollen Soundeffekte gespielt werden. Beim Abschuss eines Gegners soll ein rot-gelber Lichteffekt an der Rückseite der Konsole erscheinen. Beim eigenen Abschuss werden eine Aneinanderreihung von Lichteffekten geben. Musik ist zurzeit nicht geplant. Kann aber nachgeliefert werden.
Mit dem *A-Knopf* feuert die Spitfire nach vorne. Schüsse die Gegner treffen, fügen diesen Schaden zu und reduzieren deren Lebenspunkte. Wenn diese auf null fallen, wird der Gegner zerstört. Das selbe kann mit dem Spieler geschehen. Die Rüstung ist eine nicht-regenerative Ressource und kann vorerst nicht wiedererlangt werden. Sie dienen als Lebenspunkte des Spielers. Wenn diese auf null fallen stürzt der Spieler ab und hat verloren. Munition ist ein regenerative Ressource. Mit dem *B-Knopf* kann nachgeladen werden, was einem für eine geringe Dauer das Schießen verbietet. 

## Featurelist
Der **Spieler** kann
* sich mit dem Steuerkreuz bewegen
* mit schießen
* Gegner zerstören
* nachladen
* pausieren

Die **Gegner**
* spawnen und fliegen auf den Spieler zu
* können sich nicht bewegen
* können zufällig schießen
* können den Spieler abschießen

Das **Spiel**
* berücksichtigt die Munition des Spielers
* reagiert auf die Lebenspunkte des Spielers
* kann pausiert werden
* zählt und speichert die Punkte in einem Scoreboard

Die **Konsole**
* blinkt bei Ereignissen wie einem erfolreichen Abschuss
* spielt Sounds ab bei z.B. Schüssen oder Explosionen

## Potenzielle Features
* In Zukunft könnten sammelbare Items generiert werden, welche die Rüstung und/oder Munition wieder erhöht.
* Verschiedene Gegnertypen
* Spielbare Level mit Schwierigkeitgraden

 
