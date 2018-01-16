# Bomberman Demo

This is a demonstration project that aims to recreate part of the gameplay of
Super bomberman (SNES) on the battle stage 1 using Unreal Engine.

## General gameplay

**Objective**: Defeat your opponent with bombs explosions within 2 minutes
*Win condition*: Your opponent has been caught in a bomb explosion.
*Loose condition*: You got caught in a bomb explosion. Timer has expired.

Every player impersonates characters that are located on a map that is fully
visible on the screen. The map is divided in several cells that can contains
blocks. Characters can walk on empty cells but they can not walk on a cell that
contains a block.

Players can dispose bombs at their character current position. There is no limit
of bombs that a player can use but there can only have one active bomb per
player and only one bomb per cell. Character can not walk on a cell that contains
an active bomb.

Bombs automatically detonates after a certain amount of time. The explosion
covers the cell on which the bomb has been disposed and the top, left,
bottom and right adjacent cells. Bombs totally deplete player life when they
are caught in its explosion. Bombs explodes destructible blocks that are caught
in the explosion.

## Power ups

Power can appears after exploding a destructible block. The following power
ups are available:

* Bomb power up: increase the amount of active bombs that a player can dispose.
* Radius power up: increase by 1 the number of adjacent cell that a bomb
  explosion covers.

## Stage

The stage is an an assemblage of borders, indestructible blocks, empty cells
and randomly generated destructible blocks. Randomly generated blocks may
contains power ups.

**Size**: 15x13 including borders
**Visibility**: Map must be fully visible without scrolling

### Map plan

**Legend:**

```
+--+                            +--+                    +--+
|XX| = Map                      |P1| = Player 1 start   |P2| = Player 2 start
+--+                            +--+                    +--+

+--+                            +--+                    +--+
|II| = Indestructible block     |OO| = Empty block      |  | = Randomly generated block
+--+                            +--+                    +--+
```

```
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |P1| |OO| |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |OO| |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |  | |II| |OO| |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |  | |OO| |P2| |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
|XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX| |XX|
+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+
```

## Game modes

The game can be played agains an artificial intelligence or another player
located on the same network

### VS AI

The AI behavior is as follows:

* Without active bomb, search for an accessible destructible block.
* After finding a destructible walk towards it.
* Near a targetted destructible block, dispose a bombs near it.
* After disposing a bomb, find and walk to a safe spot
* If there is a power up created by the bomb explosion, retrieve power up.
* Prepare next action (wait) or walk
