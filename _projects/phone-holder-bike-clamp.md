---
layout: default
title: "Phone Holder Bike Clamp"
subtitle: A rotating detent-based bike phone mount
description: "Design and fabrication of a top-down modeled bike phone holder with a spinning detent mechanism."
date: 2025-11-20
thumbnail: docs/assets/phone-holder-bike-clamp/thumbnail.jpg
featured: true
---

# Phone Holder Bike Clamp

I approached the bike holder project by breaking it into more manageable chunks: the detent spinning mechanism, the bike clamp, and the phone holder. The detent spinning mechanism was printed in PLA for rigidity. The half of the clamp with the detent base was printed in PETG for print clarity and stability, and the other half was printed in PLA for strength. The phone holder was printed in TPU for flexibility and grip around the phone. All components were printed using the filament printer, as the parts were designed to be attached using screws and did not require carbon printing to account for awkward supports.

---

## Top Down Modeling

Top-down modeling works by creating reference geometry at the base level and projecting these features through all the components. This was taken advantage of in this project to keep all the alignment points, screw holes, and axles consistent across all the parts. This made it really easy to update a dimension in one place and have those changes ripple through the entire design.

---

## The Bike Clamp

The bike clamp is made of two components: a back and a front holding the detent page. The two halves are connected with a hole on each side for an M5 screw and nut. This allows the clamp to be securely tightened in place wherever necessary. A 3.1 mm hole also runs through the top half of the clamp with the detent base to serve as the axle connecting the spinning component of the detent and the base.

### Issues

**Supports**  
The first print was done with supports along the bottom, but these were extremely difficult to remove.

<p align="center">
  <img src="{{ '/docs/assets/Phone Holder Images/ClampBase.png' | relative_url }}" width="65%">
</p>


The next print was done without supports and had no issues.

**Nut Hole**  
A larger hole was indented from the base of the clamp to make space for a nut to hold the M3 screw serving as the axle.

---

## The Detent

A detent is a simple mechanism that switches between specific positions when a force is applied. The spinning detent controls the horizontal-to-vertical rotation of the phone holder and consists of two components:  
1. the base (which holds the spring and ball bearing), and  
2. the spinning circle (with inlets for the ball to click between).

This setup worked well because it’s compact, reliable, and easy to iterate on. The first version had two inlets—one vertical and one horizontal.

### Issues

**Decreasing the Detent Depth**  
The ball faced too much resistance between positions, so the inlet depth had to be decreased.

<p align="center">
  <img src="{{ '/docs/assets/phone-holder-bike-clamp/detent-problem.jpg' | relative_url }}" width="65%">
</p>

**Increasing Space for the Spring**  
Both the height and width of the spring inlet had to be increased. The spring technically fit but would get stuck in the compressed position.

**Increasing Inlet Number**  
With only two inlets, the ball would sometimes overshoot. Increasing to eight evenly spaced inlets made switching positions more consistent.

**Closing Off the Spring**  
The spring and ball had a tendency to fly off when rotating the detent. To solve this, I enclosed the spring in a hole instead of an open channel and added a 0.2 mm inlet behind it.

**Connecting the Detent and Phone Holder**  
Four additional screw holes were added to attach the phone holder to the spinning detent piece.

<p align="center">
  <img src="{{ '/docs/assets/phone-holder-bike-clamp/final-detent.jpg' | relative_url }}" width="65%">
</p>

---

## Phone Holder

Instead of making a full phone case, I went with a T-structure for stability without unnecessary bulk. The T-structure was modeled around the exact dimensions of my phone (with the case on).

### Issues

The first version didn’t account for the camera bump. Rather than redesigning the overall structure, I added a cutout for the camera. A 3 mm wall thickness gave the right balance of flexibility and support.

Four screw holes were added to attach the phone holder to the detent, including inlets so the screw heads would sit flush with the surface.

<p align="center">
  <img src="{{ '/docs/assets/phone-holder-bike-clamp/final-phone-holder.jpg' | relative_url }}" width="65%">
</p>

---

## Instructions

1. Place the spring and ball bearing into the hole in the detent base.  
2. Attach the phone holder to the spinning detent part using 4× M3×5 screws.  
3. Run an M3×16 screw through the detent assembly and secure it with a nut on the back.  
4. Attach the two clamp halves around the bike handle using 2× M5×8 screws with nuts.  
5. Insert the phone into the holder and rotate it in 45° increments using the detent mechanism.

---

## CAD Model

<div style="text-align:center">
  <iframe
    src="https://a360.co/3KwFMhG"
    width="90%"
    height="540"
    frameborder="0"
    allowfullscreen>
  </iframe>
  <p><em>Interactive Fusion 360 model of the Bike Phone Holder</em></p>
</div>
