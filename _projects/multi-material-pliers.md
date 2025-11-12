---
layout: project
title: "Multi-Material Pliers"
date: 2025-11-12
cover_image: "{{ '/docs/assets/multi-material-pliers/PickingUpPlier.jpg' | relative_url }}"
description: "Design and fabrication of multi-material print-in-place pliers using TPU and PLA."
---

# Print in Place Parts

Description of the project with a blurb about print-in-place parts. Perform external research to determine other applications print-in-place has been used. What combination of materials work well for print-in-place? 

---

## CAD Iteration 1

I started the process by taking inspiration from two mechanisms of 3D printed pliers: squeeze pliers and pull pliers. I felt that the squeeze pliers would be the most effective at picking up the small resistors, especially when sized down to a suitable scale. For my first model, I mostly attempted to replicate the big picture shapes of the squeeze pliers and understand dovetail snaps. This model was presented in class for feedback. 

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FirstCADCheckModel.png' | relative_url }}" width="65%">
</p>

### What I learned from CAD Model 1

I did not have to actually build the grid in CAD. The superslicer’s features can be taken advantage of to achieve the same result by removing the top and bottom layer and using a rectilinear pattern. Decreasing or increasing the infill modifies the number of boxes/dimensions of the grid. 

Instead of mirroring the dovetails on the sketch layer, mirroring in 3D allows for easier modification. This is more easily done when the spring is set up diagonally, so the handles and grabbers are symmetric across the x axis.  

---

## Printing the Spring + Dovetails

### Print 1

I started the printing process by printing just a spring and a sample bar of the corresponding hard component to understand the spring behavior and configure the dovetails.  

I decided to set the male end of the dovetails on the spring component so that they could be essentially shoved into the male component for a tighter fit. I started with a 0.1 mm oversize on the male component to see how this would snap together. 

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FirstSpringPrintSketch.png' | relative_url }}" width="65%">
</p>

For the spring, I started with a 4 wall perimeter and 1.2 mm wall thickness with a 8% rectilinear pattern. 

### Print 2

### Print 3


<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FinalSpringSketch.png' | relative_url }}" width="65%">
</p>


---

## Printing the Handles and the Mouth

### Print 1

### Print 2

### Print 3

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/GrabberSketchZoomOut.png' | relative_url }}" width="65%">
</p>

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/HandleSketch.png' | relative_url }}" width="65%">
</p>

---

## The Final Design

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FinalCADHandlesGrabbers.png' | relative_url }}" width="65%">
</p>

Final project description. 

---

## CAD Model

<div style="text-align:center">
  <iframe
    src="https://a360.co/4qSfk2e"
    width="90%"
    height="540"
    frameborder="0"
    allowfullscreen>
  </iframe>
  <p><em>Interactive Fusion 360 model of the Multi-Material Pliers</em></p>
</div>


