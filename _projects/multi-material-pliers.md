---
layout: default
title: "Multi-Material Pliers"
subtitle: In-place multi-material print-in-place pliers using TPU and PLA
teaser: 
description: "Design and fabrication of multi-material print-in-place pliers using TPU and PLA."
date: 2025-11-12
thumbnail: docs/assets/PlierWriteUp/Final Plier Image.jpeg
featured: true
---

# Print in Place Parts

Print-in-place parts are designed in such a way that the moving parts are printed already assembled with no manual assembly needed. This has been utilized in both fun and functional ways, including chain mail and gear mechanisms. For example, expandable grabber arms can be built off of a series of hinges. Another approach is to print rigid sections in one material and flexible sections in another. For example, using a stiff PLA together with a rubbery TPU helps create hinges or joints that move freely without sticking. 

---

## CAD Iteration 1

I started the process by taking inspiration from two mechanisms of 3D printed pliers: squeeze pliers and pull pliers. I felt that the squeeze pliers would be the most effective at picking up the small resistors, especially when sized down to a suitable scale. For my first model, I mostly attempted to replicate the big-picture shapes of the squeeze pliers and understand dovetail snaps. This model was presented in class for feedback. 

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FirstCADCheckModel.png' | relative_url }}" width="65%">
</p>

### What I Learned from CAD Model 1

I did not have to actually build the grid in CAD. The Superslicer’s features can be taken advantage of to achieve the same result by removing the top and bottom layers and using a rectilinear pattern. Decreasing or increasing the infill modifies the number of boxes/dimensions of the grid. 

Instead of mirroring the dovetails on the sketch layer, mirroring in 3D allows for easier modification. This is more easily done when the spring is set up diagonally, so the handles and grabbers are symmetric across the x-axis.  

---

## Printing the Spring + Dovetails

### Print 1

I started the printing process by printing just a spring and a sample bar of the corresponding hard component to understand the spring behavior and configure the dovetails.  

I decided to set the male end of the dovetails on the spring component so that they could be essentially shoved into the female component for a tighter fit. I started with a 0.1 mm oversize on the male component to see how this would snap together. 

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FirstSpringPrintSketch.png' | relative_url }}" width="65%">
</p>

For the spring, I started with a 4-wall perimeter and 1.2 mm wall thickness with an 8% rectilinear pattern. I found these walls to be a bit too flimsy and increased it to 1.4 mm in the next print. I also realized that this would be unnecessarily large for the size of a resistor. For the dovetails, the oversize was too much for the fit, and I decreased to an exact fit in the next print.

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/ImageFirstSpring.jpeg' | relative_url }}" width="65%">
</p>

### Print 2

I decreased the size of the spring to a 30 mm x 30 mm square and increased the wall thickness to 6. I found this to inhibit the movement of the square too much.

### Print 3

My final square was a 30 mm square with 1.6 mm walls and a 4-wall perimeter. I found this to be the best midpoint of stability and flexibility.

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FinalSpringSketch.png' | relative_url }}" width="65%">
</p>

---

## Printing the Handles and the Mouth

### Fit

There were some fit issues in the first handle and mouth print. I decreased from a 0.1 mm overset to an exact fit but found this to be a hair too loose. I found a good midpoint at a 0.5 mm overset.

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FitIssues.jpeg' | relative_url }}" width="65%">
</p>

### Handle and Mouth Design

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/GrabberSketchZoomOut.png' | relative_url }}" width="65%">
</p>

The jaw length is 43 mm, which yields a jaw capacity of 10 mm. I added a slanted offset at the top of the mouth for an easier grip on the resistors.

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/HandleSketch.png' | relative_url }}" width="65%">
</p>

---

## The Final Design

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/LargeGif - Made with Clipchamp.gif' | relative_url }}" 
       alt="Multi-Material Pliers animation" 
       width="70%">
</p>

The final design was 130 mm end-to-end pliers and 10 mm in height, with a jaw capacity of 10 mm. The spring was a 30 mm TPU square with a 4x4 grid of 1.6 mm walls. The hard components (the grabbers and handles) were printed in PLA. There were four separate pieces in total, attached using dovetail snap fits. 

<p align="center">
  <img src="{{ '/docs/assets/PlierWriteUp/FinalCADHandlesGrabbers.png' | relative_url }}" width="65%">
</p>

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
