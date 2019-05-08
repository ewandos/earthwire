# MS1 | Spielerinteraktion
## 1.1 Rahmen (15 Stunden)
- 1.1.1 Es gibt zwei Klassen von Objekten: *Flugzeug* und *Projektil*.
- 1.1.2 Aus *Fugzeug* erben sowohl das Spieler-Flugzeug und die KI ihre Objekte.
- 1.1.3 Betreffende Attribute (Koordinaten, Lebenspunkte, Stats, ...) sollten provisorisch hinzugefügt werden.
- 1.1.4 Ein Loop überprüft bei *Flugzeug* ob die Lebenspunkte auf 0 gefallen sind.

## 1.2 Navigation (5 Stunden)
- 1.2.1 Der Spieler kann sich mit dem Steuerkreuz in den Himmelsrichtungen und auch diagonal bewegen bewegen.
- 1.2.2 Der Spieler sieht immer in Richtung Osten.
- 1.2.3 Kollision mit Bildschirm, verhindert dass der Spieler aus dem Spielbereich gerät. 
- 1.2.4 Die Größe des Spielers ist variable (für Grafiken).
- 1.2.5 Die Bewegung ist statisch und hängt nicht nach, sobald man das Steuerkreut loskreuzt.

## 1.3 Schießen (10 Stunden)
- 1.3.1 Der Spieler kann mit dem *A-Knopf* ein *Projektil* abfeuern, der Richtung Osten fliegt.
- 1.3.2 Die Vertikale Bewegung hat keinen Einfluss auf die vertikale Bewegung des *Projektils*.
- 1.3.3 Das *Projektil* wird beim Verlassen des Bildschirm zerstört.
- 1.3.4 Die Größe des *Projektils* ist variable (für Grafiken).
- 1.3.5 Beim Abschuss des *Projektils* wird ein Sound abgespielt (Platzhaltersounds reichen vorerst).

# MS2 | Gegner
## 2.1 Kollision (5 Stunden)
- 2.1.1 Der Spieler kann mit statischen Gegner kollidieren.
- 2.1.2 Bei Kollision werden beide Flugzeuge zerstört, in dem ihre Lebenspunkte auf 0 fallen.
- 2.1.3 Die Animation soll austauschbar sein.

## 2.2 Schießen (8 Stunden)
- 2.2.1 Die Gegner sind in der Lage in einem zufälligen Zeitraum *Projektile* abzufeuern, welche Richtung Westen fliegen.
- 2.2.2 Diese haben alle Verhaltensweisen wie die *Projektile* des Spielers.
- 2.2.3 Wenn ein *Projektil* ein Objekt *Flugzeug* trifft reduziert es die Lebenspunkte um einen provisorischen Wert.
- 2.2.4 Bei Kollision mit einem Objekt *Flugzeug* wird das Projektil zerstört.

## 2.3 Zerstörung (8 Stunden)
- 2.3.1 Bei Abschuss eines *Projektils* speichert das Projektil ob es der Spieler oder der Computer abgefeuert hat.
- 2.3.2 Bei Zerstörung (Lebenspunkte auf 0) eines Gegners durch den Spieler wird ein gelb-roter Lichteffekt abgespielt.
- 2.3.3 Bei der Zerstörung eines Flugzeugs soll eine provisorische Animation abgespielt werden.
- 2.3.4 Sobald der Spieler zerstört wird, startet das Spiel von neuem.
- 2.3.5 Beim Zerstören eines Flugzeugs (egal ob Spieler oder Computer) wird ein Sound abgespielt.

## 2.4 Bewegung (10 Stunden)
- 2.4.1 Die Gegner bewegen sich automatisch in Richtung Osten.
- 2.4.2 Sie sollen sich nicht vertikal bewegen, da sonst die Gefahr besteht, dass sie sich gegenseitig treffen.
- 2.4.3 Wenn die Gegner den Bildschirm verlassen werden sie zerstört.

# MS3 | Stats & Ressources
## 3.1 Statistiken (5 Stunden)
- 3.1.1 Beim Zerstören eines Gegner durch ein *Projektil* des Spielers wird eine Variable *Punkte* erhöht.
- 3.1.2 Die Punkte werden als Zahl angezeigt.
- 3.1.3 Die *Rüstung* des Spielers werden in Form eines Schild-Icons und einem Balken angezeigt.
- 3.1.4 Eine neue Variable *Munition* wird in Form eines Patronen-Icons und einem Balken angezeigt.

## 3.2 Munitions-Mechanik (10 Stunden)
- 3.2.1 Mit jedem Schuss sinkt die Munition.
- 3.2.2 Ist die Munition auf 0 kann nicht mehr geschossen werden.
- 3.2.3 Will der Spieler bei 0 Munition schießen, ertönt ein Sound.
- 3.2.4 Mit dem *B-Knopf* lädt sich über eine provisorische Zeit der Balken der Munition wieder auf.
- 3.2.5 Nach dem Aufladen ist das Schießen wieder möglich.

# MS4 | Fortschritt
## 4.1 Gegnerspawn (10 Stunden)
- 4.1.1 Zufällig werden Gegner am rechten Bildschirmrand erscheinen.
- 4.1.2 Über den Verlauf der Zeit erscheinen mehr Gegner, die öfter schießen.

## 4.2 Scoreboard (5 Stunden)
- 4.2.1 Sobald der Spieler stirbt, werden die Punkte in ein Array abgespeichert.
- 4.2.2 Das Array wird dann nach Größe sortiert.

## 4.3 GameLoop abschließen (5 Stunden)
- 4.3.1 Sobald der Spieler stirbt wird das aktuelle Scoreboard angezeigt.
- 4.3.2 Mit dem Druck auf den *A-Knopf* wird ein neues Spiel gestartet.

## 4.4 Pause (10 Stunden)
- 4.4.1 Beim betätigen des *META-Knopfs* pausiert das Spiel.
- 4.4.2 Ein Titel "Pausiert" erscheint.
- 4.4.3 Der Spieler bewegt sich nicht mehr und kann auch nicht mehr schießen.
- 4.4.4 Die Gegner bewegen sich nicht mehr und schießen nicht.
- 4.4.5 Beim betätigen des *A-Knopfs* wird das Spiel fortgesetzt.

# MS5 | Finalisierung
## 5.1 Grafik (15 Stunden)
- 5.1.1 Grafiken werden erstellt
- 5.1.2 Die Platzhaltergrafiken werden ausgetauscht.
- 5.1.3 Die Kollision funktioniert weiterhin.

## 5.2 Polishing (10 Stunden)
- 5.2.1  Sounds & Grafiken werden verfeinert
- 5.2.2 Bug Fixes

## 5.3 Hintergrundgrafik (optional)
- 5.3.1 Eine Hintergrundgrafik wird erstellt.
- 5.3.2 Die Hintergrundgrafik scrollt *gekachelt* mit dem Spieler langsam mit (Parallax Effekt).

## 5.4 Musik (optional)
- 5.4.1 Eine Hintergrundmusik wird erstellt.
- 5.4.2 Eine andere Hintergrundmusik für das Scoreboard.
