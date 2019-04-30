/* 
 * ====================
 * GRAFIKEN & ANIMATION
 * ====================
 * Hier befinden sich alle Daten für die Grafiken im Spiel.
 * Alle Grafiken sind im "Index-Color-Mode" angelegt (Details in der Doku unten).
 * Jede Grafik besteht aus zwei Teilen. Den META-Daten (Festlegung der Pixel, Höhe, Breite, Loop etc.)
 * und dem eigentlichen Bild, was sich dann per Aufruf auf dem Display zeichnen lassen kann.
 * Zum zeichnen einer Grafik diese Datei includen und zum eigentlichen Ausgeben
 * " gb.display.drawImage(XKOORDINATE, YKOORDINATE, SPRITENAMEN); " verwenden.
 * 
 * ---------------------
 * ALLE SPRITES:
 * 
 * Name:      playerSprite
 * Funktion:  Grafik für den Spieler
 * Breite:    8
 * Höhe:      9
 * 
 * ---------------------
 * Documentation zum Nachlesen: https://gamebuino.com/academy/standalone/add-images-to-your-games
*/



/* === v === ROHDATEN === v === */

const uint8_t playerSpriteData[] = {
  8, 9, // width, heigth
  1, 0, // frames
  0, // frame loop
  0x02, // transparent color
  1, // color mode

  0x22, 0x22, 0x2B, 0x22,
  0x22, 0x22, 0xBB, 0x22,
  0x22, 0x22, 0x3B, 0x22,
  0x2B, 0x22, 0x3B, 0xB2,
  0x23, 0xBC, 0xBB, 0xB7,
  0x2B, 0x22, 0x3B, 0xB2,
  0x22, 0x22, 0x3B, 0x22,
  0x22, 0x22, 0xBB, 0x22,
  0x22, 0x22, 0x2B, 0x22,
};

Image playerSprite(playerSpriteData);
