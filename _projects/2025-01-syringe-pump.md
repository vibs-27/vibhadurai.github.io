---
layout: default
title: Syringe Pump
subtitle: 3D Printed
teaser: 3D printed syringe pump with Fusion 360 + Arduino control.
date: 2025-01-20
thumbnail: /docs/assets/pump/pump_thumb.jpg
featured: true
---

# Syringe Pump

## Purpose & Key Features
Syringe pumps are motorized devices that mechanically insert a plunger to control the dispensation of fluid from a syringe. Even basic syringe pumps can cost $500, while programmable pumps can easily cost $3000. Given their typical price and ultimately simple design, syringe pumps are the ideal project for an efficient do-it-yourself alternative, especially with some knowledge of 3D printing and electrical prototyping. 

The design is driven by a stepper motor rotating a lead screw. It can accommodate both a 10 mL and a 20 mL syringe pump.  

The flow rate of the pump is easily adjustable, and an LED turns green to indicate the pump is running, yellow when pauses, and red when fully plunged.   

For ease of adjusting the elctrical components, the electrical box is easy to open and close.  

Function: When the black button is pressed, the motion of the pump starts automatically at 5 mL/min for a 20 mL syringe and stops automatically when the syringe is empty.    

---

## Final Design (Photo/Render)
![Final render of the assembled pump](/docs/assets/pump/pump_render.jpg)

> Put your photo or rendering at `/docs/assets/pump/pump_render.jpg`.  
> (You can also drop in build photos below this image.)

---

## Off-the-Shelf Parts

| Item | Qty | Notes |
|---|---:|---|
| Arduino Uno (ATmega-based) | 1 | Main controller driving stepper + UI |
| ESP32 dev boards | 2 | One transmitter + one receiver for remote start/pause |
| Stepper motor (NEMA-17 class) | 1 | Drives the pump via step/dir control and microstepping |
| Stepper driver (A4988/DRV8825/TMC-type) | 1 | Microstep pins tied for 1/16 step (≈3200 steps/rev) |
| Lead screw + matching nut | 1 set | Converts motor rotation to linear motion |
| 12 V DC power supply | 1 | Feeds Arduino + stepper (logic rails also derived from 5 V) |
| 5 V rail / regulator (buck or equivalent) | 1 | Powers ESP32s and driver logic from 5 V |
| Limit (latch) switch | 1 | End-of-travel detection and stop |
| Momentary push buttons | 5 | Forward, reverse, start/pause, syringe size select, flow-rate-source |
| Potentiometer (panel-mount) | 1 | Sets flow rate in “knob” mode |
| RGB or bi-color LED + resistors | 1 set | Green = running, yellow = paused (mix), red = end |
| I²C LCD module | 1 | Status messages (LiquidCrystal_I2C in code) |
| Breadboard / perfboard + jumper wires | 1 | For wiring the UI + logic |
| Micro-USB cable | 1 | Powers the transmitter remote during prototyping |
| Assorted M-fasteners/washers | — | General assembly |
| Syringes (10 mL and 20 mL) | 1 each | Two supported sizes |


---

## 3D-Printed Parts

| Part | Qty | Recommended Material | Notes |
|---|---:|---|---|
| Stationary support panel (with latch pocket) | 1 | PLA/PETG | Holds syringe body; integrates the end-stop latch |
| Moving carriage (plunger holder) | 1 | PETG | Travels on lead-screw nut; carries plunger |
| Syringe holder inserts — 10 mL / 20 mL | 1 + 1 | PLA/PETG | Dual positions to swap sizes without tools |
| Motor mounting plate | 1 | ABS (heat-tolerant) | Sits near stepper; spec calls for higher-temp material |
| Base/side rails or frame members | 2+ | PLA/PETG | Main chassis pieces |
| Belt/lead-screw nut capture & small brackets | as needed | PLA/PETG | Hardware capture, alignment |
| Electronics enclosure (main) | 1 | PLA | Protects breadboard/electronics; tight passthroughs |
| Remote controller box (transmitter) | 1 | PLA | Printed handheld housing for switch/ESP32 |
| Top/bottom lids, covers, feet | as needed | PLA | Finish parts / service access |

---

## Arduino Code
Firmware lives in this repository here:  
**➡ [Open the Arduino sketch](/code/syringe_pump/syringe_pump.ino)**

> Put your `.ino` at `code/syringe_pump/syringe_pump.ino` (or change the link above to match where you upload it).

---

## Interactive Fusion 360 Model

<div style="aspect-ratio:16/9; border:1px solid #eee; border-radius:10px; overflow:hidden; margin: 8px 0 16px;">
  <iframe 
    src="https://a360.co/4hypyPY"
    width="100%" height="100%" allowfullscreen loading="lazy">
  </iframe>
</div>

---

## Instructions for Pump Usage
1. Place 10 mL or 20 mL in corresponding holes. The 10 mL holes are on the front side of
the pump, and 20 mL holes are towards the back side.
2. Press the black button, third from the left, to start the motion of the pump at 5 mL/min for
a 20 mL syringe. To pause, press this button again. Motion will automatically stop when
the syringe is empty.
3. To adjust the motion for a 10 mL syringe, press the red button directly to the right of the
black button (the fourth button from the left).
4. Press and hold the first button to manually move forward. Press and hold the second
button to manually move backward.
5. To set the speed using the knob, press the rightmost red button (5th from the left) and
rotate the knob right to increase speed and left to decrease speed.
6. For remote use, due to limitations in prototyping, the remote must be powered using a
micro usb cable connected to a laptop or similar device. For future iterations, the remote
will have a stand alone powersource. To turn on the syringe, flip the switch the on
position, to pause the syringe flip the syringe to the off position.

---

## Files & Links
- CAD (Fusion 360): https://a360.co/4hypyPY   
- Firmware: **[syringe_pump.ino](/code/syringe_pump/syringe_pump.ino)**  
