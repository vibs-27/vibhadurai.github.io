---
layout: default
title: Syringe Pump
subtitle: 3D Printing
teaser: 3D printed syringe pump.
date: 2024-10-01
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

## Final Design (Render/Photo)

![Final render of the assembled pump]({{ '/docs/assets/pump/pump_render.jpg' | relative_url }})
![Final image of the assembled pump]({{ '/docs/assets/pump/pump_thumb.jpg' | relative_url }})

---

## Off-the-Shelf Parts

| Item                                | Qty   |
|-------------------------------------|------:|
| Arduino Uno                         |     1 |
| ESP32 dev boards                    |     2 |
| Stepper motor                       |     1 |
| Stepper driver                      |     1 |
| Lead screw + matching nut           | 1 set |
| 12 V DC power supply                |     1 |
| 5 V rail                            |     1 |
| Limit switch                        |     1 |
| Momentary push buttons              |     5 |
| Potentiometer                       |     1 |
| RGB LED + resistors                 | 1 set |
| I²C LCD module                      |     1 |
| Breadboard + jumper wires           |     1 |
| Micro-USB cable                     |     1 |
| M-fasteners/washers                 |     — |
| Syringes (10 mL and 20 mL)          | 1 each |


---

## 3D-Printed Parts

| Part                     | Qty | Recommended Material |
|--------------------------|----:|----------------------|
| Stationary Support Panel |   1 | ABS                  |
| Moving Carriage          |   1 | ABS                  |
| Motor Mounting Plate     |   1 | ABS                  |
| Electronics Enclosure    |   1 | PLA                  |
| Remote Controller Box    |   1 | PLA                  |

---

## Arduino Code

- [Main Syringe Pump Code](https://github.com/vibs-27/vibhadurai.github.io/blob/main/syringe_pump.ino)
- [ESP32 Receiver](https://github.com/vibs-27/vibhadurai.github.io/blob/main/esp32_receiver.ino)
- [ESP32 Transmitter](https://github.com/vibs-27/vibhadurai.github.io/blob/main/esp32_transmitter.ino)

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

