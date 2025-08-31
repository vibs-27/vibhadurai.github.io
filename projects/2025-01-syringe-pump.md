---
layout: default
title: Syringe Pump (DF-2100)
subtitle: Compact, parametric syringe pump designed & fabricated with Fusion 360 + Arduino control
description: Documentation of goals, design, BOM, printed parts, firmware link, interactive model, and operation notes.
date: 2025-01-20
thumbnail: /docs/assets/pump_render.jpg
---

# Syringe Pump

## Purpose & Features
- Purpose: Controlled fluid delivery for lab demos and small-scale experiments.  
- Features: Parametric body, modular motor mount, easy belt tensioning, printable hardware.

![Final render](/docs/assets/pump_render.jpg)

## Bill of Materials — Off-the-Shelf
| Item | Qty | Notes | Link |
|---|---:|---|---|
| NEMA 17 stepper motor | 1 | Standard 200-step/rev | *(add link)* |
| GT2 timing belt | 1 | Length per design | *(add link)* |
| GT2 pulleys (20T) | 2 | Bore to match motor | *(add link)* |
| M3/M4 screws & nuts | as needed | Assembly hardware | *(add link)* |
| Syringe (e.g., 10 mL) | 1 | Fits carriage | *(add link)* |

## Bill of Materials — 3D Printed
| Part | Qty | Material | Infill | Notes |
|---|---:|---|---|---|
| Frame halves | 2 | PLA/PETG | 30% | |
| Carriage | 1 | PLA/PETG | 40% | |
| Motor mount | 1 | PETG | 40% | |
| End caps | 2 | PLA | 20% | |
| Belt clamp | 1 | PLA | 40% | |

## Firmware / Code
- Arduino code: **[View on GitHub](/path/to/your/arduino/code/folder/)**  
  *(Place the `.ino` in your repo and link to it here.)*

## Interactive Fusion 360 Model
Paste the **public share** or **Autodesk Viewer** embed link here (Fusion 360 → Share → Public Link → “Embed”). Example:

<div style="aspect-ratio:16/9;">
<iframe 
  src="https://viewer.autodesk.com/embedded.html?urn=YOUR_MODEL_URN" 
  width="100%" height="100%" allowfullscreen>
</iframe>
</div>

## Operation (How to Use)
1. Secure the syringe in the carriage and set the plunger in the clamp.  
2. Power the controller and set the step/mm (or microstepping) as calibrated.  
3. Use the control knob/serial commands to advance/retract; verify smooth motion.  
4. Record flow-rate vs. steps to build a simple calibration curve.

## Gallery
<img src="/docs/assets/gallery/img1.jpg" width="49%"> <img src="/docs/assets/gallery/img2.jpg" width="49%">
