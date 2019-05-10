#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP
#include <Gamebuino-Meta.h>

/*
 * ====================
 * GRAFIKEN & ANIMATION
 * ====================
 * Hier befinden sich alle Daten für die Grafiken im Spiel.
 * Alle Grafiken sind im "Index-Color-Mode" angelegt (Details in der Doku unten).
 * Jede Grafik besteht aus zwei Teilen. Den META-Daten (Festlegung der Pixel, Höhe, Breite, Loop etc.)
 * und dem eigentlichen Bild, was sich dann per Aufruf auf dem Display zeichnen lassen kann.
 * Zum zeichnen einer Grafik diese Datei includen und zum eigentlichen Ausgeben
 * Ein Image mit " Image SPRITENAMEN(SPRITENAMEN_DATA); " erstellen und mit
 * " gb.display.drawImage(XKOORDINATE, YKOORDINATE, SPRITENAMEN); " verwenden.
 *
 * ---------------------
 * ALLE SPRITES:
 *
 * DataName:  playerSpriteData
 * Funktion:  Grafik für den Spieler
 * Breite:    7
 * Höhe:      9
 *
 * DataName:  enemySpriteData
 * Funktion:  Grafik für den Gegner
 * Breite:    12
 * Höhe:      15
 *
 * DataName:  hullSpriteData
 * Funktion:  Icon für Rüstung
 * Breite:    5
 * Höhe:      6
 *
 * DataName:  ammuSpriteData
 * Funktion:  Icon für Munition
 * Breite:    3
 * Höhe:      6
 *
 * DataName:  projectileImgData
 * Funktion:  Icon für Projektile
 * Breite:    2
 * Höhe:      1
 * ---------------------
 * Documentation zum Nachlesen: https://gamebuino.com/academy/standalone/add-images-to-your-games
*/

/* === v === ROHDATEN === v === */

const uint8_t playerSpriteData[] = {
  7, 9, // width, heigth
  1, 0, // frames
  0, // frame loop
  0x02, // transparent color
  1, // color mode

  0x22, 0x22, 0xB2, 0x22,
  0x22, 0x2B, 0xB2, 0x22,
  0x22, 0x23, 0xB2, 0x22,
  0xB2, 0x23, 0xBB, 0x22,
  0x3B, 0xCB, 0xBB, 0x72,
  0xB2, 0x23, 0xBB, 0x22,
  0x22, 0x23, 0xB2, 0x22,
  0x22, 0x2B, 0xB2, 0x22,
  0x22, 0x22, 0xB2, 0x22,
};

const uint8_t enemySpriteData[] = {
  12, 15, // width, heigth
  1, 0, // frames
  0, // frame loop
  0x02, // transparent color
  1, // color mode

  0x22, 0x22, 0x62, 0x22, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x22, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x22, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x52, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x82, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x52, 0x22, 0x26,
  0x26, 0x66, 0x66, 0x66, 0x66, 0x66,
  0x67, 0x66, 0x66, 0x66, 0x66, 0x65,
  0x26, 0x66, 0x66, 0x66, 0x66, 0x66,
  0x22, 0x22, 0x66, 0x52, 0x22, 0x26,
  0x22, 0x22, 0x66, 0x82, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x52, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x22, 0x22, 0x22,
  0x22, 0x22, 0x66, 0x22, 0x22, 0x22,
  0x22, 0x22, 0x62, 0x22, 0x22, 0x22,
};

const uint8_t hullSpriteData[] = {
  5, 5, // width, heigth
  1, 0, // frames
  0, // frame loop
  0x02, // transparent color
  1, // color mode

  0x99, 0xAA, 0xA2,
  0x9A, 0xAA, 0xA2,
  0xAA, 0xAA, 0xA2,
  0x2A, 0xAA, 0x22,
  0x22, 0xA2, 0x22,
};

const uint8_t ammuSpriteData[] = {
  3, 5, // width, heigth
  1, 0, // frames
  0, // frame loop
  0x02, // transparent color
  1, // color mode

  0x28, 0x22,
  0x88, 0x82,
  0x88, 0x82,
  0x88, 0x82,
  0x88, 0x82,
};

const uint8_t projectileImgData[] = {
  2, 1, // width, heigth
  1, 0, // frames
  0, // frame loop
  0x02, // transparent color
  1, // color mode

  0xAA,
};
#endif
