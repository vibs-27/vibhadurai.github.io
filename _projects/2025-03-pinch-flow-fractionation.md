---
layout: default
title: Pinch Flow Fractionation Microfluidic Device
subtitle: Resin-printed PFF device for size-based particle sorting
teaser: Symmetric pinch flow fractionation device designed & fabricated using SLA printing.
description: Exploring particle separation in a symmetric microfluidic geometry with resin-printed molds and PDMS casting.
date: 2025-03-05
thumbnail: docs/assets/MicrofluidicDeviceRendering.png
featured: false
---

# Pinch Flow Fractionation Microfluidic Device

## Purpose & Key Features
This project investigates **pinch flow fractionation (PFF)** — a microfluidic method that separates particles by diameter based on laminar flow focusing near a channel wall. The focus is a **fully symmetric design**, eliminating geometric bias and emphasizing pure hydrodynamic separation.

**Key features**
- Symmetric channel geometry → equal outlet hydraulic resistance
- Designed in Fusion 360 based on PFF theoretical displacement
- SLA resin-printed mold for PDMS casting
- Ports sized for standard tubing (2.2 mm posts)

---

## Design Decisions

### Symmetric geometry
A symmetric approach was used to simplify pressure-balancing across outlets.  
This ensures separation performance reflects inherent PFF physics instead of geometric skew.

### Outlet placement driven by PFF theory
Outlet positions were selected using the **PFF equilibrium position equation**, which predicts particle heights after the expansion region.

With:
- **Pinched width:** 1 mm  
- **Broad width:** 40 mm  

Expected streamlines:
- **Small particles:** near the top wall  
- **Large particles:** ~6–7 mm below  
- **Buffer fluid:** below both streams

### Addressing unequal outlet flows
The buffer stream carries **more fluid** than small/large particle streams → higher flow → backflow risk into particle outlets.

To equalize pressure losses:
> **Flow resistance was increased for the small/large outlets** using longer outlet channels.

This produced **more uniform backpressures** and stabilized sorting.

---

## What I Would Improve in a Future Iteration
- Increase vertical spacing between outlets to reduce crosstalk  
- Taper particle outlets slightly to help maintain streamline isolation  
- Add a **fourth bypass outlet** to bleed excess buffer volume  
- Include **computational flow simulation** (e.g., COMSOL) to verify backpressure balancing upfront  

---

## Fabrication Process (Resin Printing)

| Step | Description |
|---:|---|
| 1 | **Model design** in Fusion 360 as the negative mold |
| 2 | **SLA resin print** on Form 3+/4 with flat base surface |
| 3 | **IPA wash** — 5 min + 5 min |
| 4 | **Dry upside-down** for 30 minutes to prevent pooling |
| 5 | **Air blast** to clear channels |
| 6 | **Short cure** (1 min) to minimize warping before removing supports |

> After mold prep, PDMS can be cast, cured, plasma bonded, and tubed.

---

## Final Device Image
![Final PFF mold]({{ docs/assets/microfluidicDevicePrint.png }})

---

## Operation Summary
1. Introduce particle suspension + buffer into inlet  
2. Flow enters pinched region and focuses particles along wall  
3. Expansion region enables separation by size  
4. Particles exit through dedicated small/large outlets  
5. Buffer diverted through center outlet

---

## Files & Links
- CAD Model *(upload to GitHub or Autodesk viewer link)*


