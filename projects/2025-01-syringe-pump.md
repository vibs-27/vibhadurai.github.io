---
layout: default
title: Syringe Pump
subtitle: Compact, parametric syringe pump designed & fabricated with Fusion 360 + Arduino control
teaser: Compact parametric syringe pump with Fusion 360 + Arduino control.
description: Goals, design features, BOMs, printed parts, firmware link, interactive model, and operation notes.
date: 2025-01-20
thumbnail: /docs/assets/pump/pump_thumb.jpg   # ← put a 1200×800-ish image here
featured: true
---

# Syringe Pump

## Purpose & Key Features
The goal of this build is a compact, low-cost syringe pump for repeatable, computer-controlled flow.  
**Highlights**
- **Parametric CAD** for easy resizing to different syringe diameters and stroke lengths  
- **Timing-belt drive** with simple belt clamp and adjustable tension  
- **Modular motor mount** for NEMA 17 steppers  
- **Printable carriage** with quick-swap syringe cradle  
- **Arduino control** (direction, steps, microstepping) with serial/knob input

---

## Final Design (Photo/Render)
![Final render of the assembled pump](/docs/assets/pump/pump_render.jpg)

> Put your photo or rendering at `/docs/assets/pump/pump_render.jpg`.  
> (You can also drop in build photos below this image.)

---

## Off-the-Shelf Parts (BOM)

| Item | Qty | Notes | Example Link |
|---|---:|---|---|
| NEMA 17 stepper motor (1.5–2A) | 1 | 200 steps/rev, typical 42 mm body | *(add vendor link)* |
| Stepper driver (A4988/DRV8825/TMC2208) | 1 | With heatsink; set current limit | *(add vendor link)* |
| GT2 timing belt | 1 | Length per design (~400–500 mm loop) | *(add vendor link)* |
| GT2 pulley 20T (5 mm bore) | 2 | One on motor; one idler or both driven | *(add vendor link)* |
| 8 mm smooth rods (or 2020 extrusion) | 2 | Linear guides, cut to length | *(add vendor link)* |
| LM8UU bearings (if using 8 mm rods) | 4 | Carriage guidance | *(add vendor link)* |
| M3/M4 screws + nuts + washers | — | Assembly hardware | *(add vendor link)* |
| 10 mL (or chosen) syringe | 1 | Match carriage cradle size | *(add vendor link)* |
| 12 V DC power supply (2–3 A) | 1 | For stepper + electronics | *(add vendor link)* |
| Arduino (Uno/Nano) + USB cable | 1 | Controller | *(add vendor link)* |
| Optional: limit switch | 1–2 | Homing/endstop | *(add vendor link)* |

> Adjust to your actual build—these are common choices for a belt-driven syringe pump.

---

## 3D-Printed Parts

| Part | Qty | Material | Infill | Notes |
|---|---:|---|---|---|
| Base frame (L/R halves) | 2 | PLA or PETG | 30% | Bolt to each other or to plate |
| Carriage body | 1 | PETG recommended | 40% | Houses two LM8UU (or sliders) |
| Syringe cradle & clamp | 1+1 | PLA/PETG | 40% | Parametric to syringe OD |
| Motor mount | 1 | PETG | 40% | NEMA 17 hole pattern |
| Idler block (or pulley post) | 1 | PLA/PETG | 35% | Belt routing |
| Belt clamp | 1 | PLA | 40% | Captures belt ends |
| End caps / feet (optional) | 2–4 | PLA | 20% | Clean finish |

> Print orientation: lay flat surfaces down for strength; add 3–4 perimeters for the carriage and clamp.

---

## Arduino Code
Firmware lives in this repository here:  
**➡ [Open the Arduino sketch](/code/syringe_pump/syringe_pump.ino)**

> Put your `.ino` at `code/syringe_pump/syringe_pump.ino` (or change the link above to match where you upload it).

---

## Interactive Fusion 360 Model
Embed your assembly viewer share link here (Fusion 360 → Share → “Public Link” → **Embed**). Replace the `src` with your URL or URN.

<div style="aspect-ratio:16/9; border:1px solid #eee; border-radius:10px; overflow:hidden; margin: 8px 0 16px;">
  <iframe 
    src="https://viewer.autodesk.com/id/dummy-embed-url-replace-me"
    width="100%" height="100%" allowfullscreen loading="lazy">
  </iframe>
</div>

> If your course uses a specific viewer/URN, paste that instead.

---

## Operation (How to Use)
1. **Mount the syringe**: seat the barrel in the cradle; clamp the plunger into the carriage clamp.  
2. **Power on**: connect 12 V supply; Arduino powers via USB or buck converter.  
3. **Set microstepping** on the driver (e.g., 1/16) and current limit per motor specs.  
4. **Calibrate steps/mm**:  
   - Command a known move (e.g., 100 mm), measure plunger travel.  
   - Adjust steps/mm until commanded travel ≈ measured travel.  
5. **Run a test**: send serial commands (or press buttons/turn knob if UI is added) to advance/retract.  
6. **Record flow rate**: time a dispense of a known volume to build a simple flow vs. speed table.  
7. **Safety**: keep fingers clear; don’t stall the motor; verify endstops (if installed).

---

## Build Notes / Lessons Learned
- Belt tension matters: too loose → backlash; too tight → bearing wear.  
- Carriage smoothness dominates repeatability—deburr printed parts around bearing bores.  
- PETG for heat-resistance on motor-adjacent parts; PLA is fine for non-hot components.

---

## Files & Links
- CAD (Fusion 360): *(insert share link to the CAD file or repo folder)*  
- Firmware: **[syringe_pump.ino](/code/syringe_pump/syringe_pump.ino)**  
- Photos: *(add a gallery section if you like)*
