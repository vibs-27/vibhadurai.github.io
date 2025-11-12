---
layout: project
title: "Multi-Material Pliers (Print-in-Place + TPU/PLA)"
date: 2025-11-11
tags: [digital fabrication, 3d printing, print-in-place, tpu, pla, cad]
cover_image: "{{ '/docs/assets/multi-material-pliers/PickingUpPlier.jpg' | relative_url }}"
description: "Designing print-in-place, multi-material pliers that combine a flexible TPU spring with rigid PLA jaws—covering CAD, dovetail tuning, and slicer setup."
---

# Print in Place Parts

Print-in-place (PiP) parts are designed to **come off the printer already assembled**—no screws, glue, or post-assembly. Clearances, bridging, and compliant features are baked into the geometry so moving elements (hinges, sliders, gears, living springs) separate as the print completes.

**Where PiP shines:** no-assembly hinges, compliant grippers, iris mechanisms, captive chains/bearings, gearboxes, snap-fit boxes/latches, and deployable mechanisms. In education and rapid prototyping, PiP is ideal for demonstrating **mechanisms, tolerances, and material behavior** without extra hardware. In product contexts, it reduces part count and manual labor while enabling **sealed or captive features** that can’t be assembled otherwise.

**Material combos that tend to work well:**
- **Rigid + Flexible:** PLA or PETG for structure, **TPU** for springs, pads, or soft-contact features.  
- **All-rigid PiP:** PLA or PETG with designed clearances (≈0.2–0.4 mm typical for FDM, tuned to printer).  
- **Higher performance:** Nylon (PA) or PA-CF for structure + TPU for flex, when you need better fatigue and heat resistance.

This project pairs a **TPU spring “spine”** with **PLA handles/jaws** using **dovetail joints** so the soft spring presses in for a tight interference fit.

---

# CAD Iteration 1

I started by looking at two printed-plier archetypes: **squeeze pliers** (scissor-like action) and **pull pliers** (linear slider). For grabbing small resistors, **squeeze pliers** felt better at a reduced scale. My first CAD mainly replicated the macro geometry to study **dovetail snaps** and confirm the spring path.

**What I learned from CAD Model 1**
- I didn’t need to model a grid manually. In **SuperSlicer**, removing top/bottom layers and choosing a **rectilinear infill** gives a clean, open-cell “grid” spring—faster to iterate. Varying **infill %** changes grid density and stiffness.
- **Mirror in 3D, not in sketch.** With the spring placed **diagonally**, handles/jaws remain symmetric across X, and it’s easier to tweak after mirroring bodies or features.

<div style="display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:10px;">
  <img src="{{ '/docs/assets/multi-material-pliers/FirstCAD.png' | relative_url }}" alt="First CAD" />
  <img src="{{ '/docs/assets/multi-material-pliers/FirstCADCheckModel.png' | relative_url }}" alt="Mesh Check" />
  <img src="{{ '/docs/assets/multi-material-pliers/FinalCADHandlesGrabbers.png' | relative_url }}" alt="Final CAD Handles & Grabbers" />
</div>

---

# Printing the Spring + Dovetails

### Print 1
To characterize the spring and joint fit, I printed **only the TPU spring** plus a **PLA sample bar** with the matching dovetail.

- **Dovetails:** I put the **male** end on the **TPU spring** so it can **press-fit** into the PLA female. I began with **+0.10 mm oversize** on the TPU male to test a tight snap.  
- **TPU spring settings (initial):** 4 perimeters, ~1.2 mm wall, **8% rectilinear** infill, no top/bottom layers.  
- Early takeaway: TPU compresses under press-fit—**start small** on oversize and creep up in **0.05–0.10 mm** steps until it’s firm but printable.

<img src="{{ '/docs/assets/multi-material-pliers/FirstSpringPrintSketch.png' | relative_url }}" alt="Spring print sketch" />

### Print 2
Iterated dovetail **clearance/oversize sweep** (+0.00 / +0.05 / +0.10 / +0.15 mm on the TPU male) and tested hand-assembly and retention force. Landed on a **+0.10–0.12 mm** sweet spot for my printer and materials (tight snap, still serviceable).

<img src="{{ '/docs/assets/multi-material-pliers/SpringConfigurePrint.png' | relative_url }}" alt="Spring configure print" />
<img src="{{ '/docs/assets/multi-material-pliers/SpringComponentsPrintSettings.png' | relative_url }}" alt="Spring print settings" />

---

# Printing the Handles and the Mouth

### Print 1
Baseline PLA handles + jaws with **0.2 mm layer**, 3–4 perimeters, 20–30% infill. Verified ergonomics and jaw reach.  

### Print 2
Added **edge chamfers/fillets** on the jaw bite and tuned **nozzle-side clearance** so the jaws don’t fuse in PiP regions. Increased perimeters near the pivot to stiffen the squeeze path.

### Print 3
Finalized geometry for the **TPU-to-PLA dovetail seats** and added a slight **lead-in bevel** to help the TPU male snap home without shaving.

<div style="display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:10px;">
  <img src="{{ '/docs/assets/multi-material-pliers/HandleSketch.png' | relative_url }}" alt="Handle sketch" />
  <img src="{{ '/docs/assets/multi-material-pliers/GrabberSketchZoomOut.png' | relative_url }}" alt="Jaw sketch zoom out" />
  <img src="{{ '/docs/assets/multi-material-pliers/GrabberEdgeZoomInSketch.png' | relative_url }}" alt="Jaw edge detail" />
</div>

<img src="{{ '/docs/assets/multi-material-pliers/HardComponentsPrintSettings.png' | relative_url }}" alt="Hard component print settings" />

---

# The Final Design

A **print-in-place, multi-material plier** where a **TPU compliant spring** provides return force and grip comfort, and **PLA** forms stiff handles and precise jaws. The **dovetail press-fits** lock the spring without screws or glue; the living structure prints as one and assembles by hand in seconds.

<img src="{{ '/docs/assets/multi-material-pliers/PickingUpPlier.jpg' | relative_url }}" alt="Picking up component with pliers" />

---

# CAD Model

*(Embed your model viewer here if you have a public link.)*

```html
<!-- Example Fusion 360 Embed (replace `src` with your shared link) -->
<iframe src="YOUR_FUSION_EMBED_URL"
        width="100%" height="520" frameborder="0" allowfullscreen>
</iframe>

