---
layout: default
title: "Generative Design and Applications"
subtitle: Generative design applied to an electric skateboard truck
description: "Exploring generative design and powder bed fusion through the design of an electric skateboard truck."
date: 2025-11-20
featured: true
---

# Generative Design and Applications

Generative design is a process that allows you to lightweight geometries and consolidate assemblies into a singular, more efficient component by establishing preserved areas, obstacles, and predicted forces on the component. This has been combined with powder bed fusion in aerospace and automotive industries. An example of this is General Motors using generative design software to work on the part that secures the seat belt to the floor of the car. They worked to combine eight parts into two, both to optimize functionality and decrease supply chain costs from having eight individual pieces. General Motors states that “generative design paired with additive manufacturing can be completely disruptive to our industry.”

---

## Generative Design Skateboard

In this project, generative design was applied to design a truck for an electric skateboard to hold the front wheels and the motor. The first step in this was establishing the preserve and obstacle geometries.

<p align="center">
  <img src="{{ '/docs/assets/PreserveGeometry.png' | relative_url }}" width="65%">
</p>

<p align="center">
  <img src="{{ '/docs/assets/ObstacleGeometry.png' | relative_url }}" width="65%">
</p>


---

## Applying Forces

After setting up the areas of the design where material must be generated and where the part cannot be generated, the next step is applying expected forces so that the generative model can withstand its application. In the case of the skateboard truck, there were eight key forces.

<p align="center">
  <img src="{{ '/docs/assets/Forces.png' | relative_url }}" width="65%">
</p>


### 1. Motor Weight  
An 8.5 N remote force was applied downward at the motor’s center of mass and connected to the four motor mounting screw locations. This value was calculated from the motor mass (0.86 kg) using F = mg. The remote force accounts for the offset between the motor center of mass and the motor mounting plate.

### 2. Belt Tension  
A 560 N remote force was applied at the center of the motor pulley, following the angle of the belt line toward the wheel pulley. This force was calculated from the motor’s maximum torque (8 N·m) divided by the motor pulley pitch radius.

### 3. Motor Torque  
An 8 N·m moment was applied on the motor shaft axis at the motor mounting interface. This represents the torque of the motor attempting to rotate within the mount during maximum torque output.

### 4. Left Wheel Vertical Load  
A 500 N upward force was applied at the left wheel contact region. This force represents the upward ground reaction from rider weight during riding and was calculated by distributing the rider and board weight across all four wheels and applying a 2.5× dynamic safety factor.

### 5. Right Wheel Vertical Load  
A 500 N upward force was applied at the right wheel contact region using the same assumptions and safety factor as the left wheel.

### 6. Left Wheel Turning (Shear) Force  
A 400 N horizontal force was applied at the left wheel contact region, pointing backwards. This force represents friction between the wheel and ground during turning.

### 7. Right Wheel Turning (Shear) Force  
A 400 N horizontal force was applied at the right wheel contact region, pointing forward. This creates a shear couple in the hanger consistent with turning behavior.

### 8. Pivot Cup Compression  
A 500 N force was applied along the pivot axis, directed from the baseplate into the hanger’s pivot nose. This represents the compressive load transmitted through the pivot cup during rider loading and turning.

The structural constraint was placed on the kingpin seat region because it is fixed relative to the baseplate and deck. Constraining this region represents how the truck is supported during riding. The kingpin seat was chosen over the pivot cup because it is more rigid, while the pivot cup allows for some rotation during turning.

---

## Process

To verify that the generated model fit correctly, the part was first filament printed before carbon printing. The first print did not leave enough space to fit over the bearings during assembly, so the obstacle geometry was expanded to allow for proper clearance.

<p align="center">
  <img src="{{ '/docs/assets/3DPrint.jpeg' | relative_url }}" width="65%">
</p>


The final carbon print acounted for this.
<p align="center">
  <img src="{{ '/docs/assets/MotorMount.jpeg' | relative_url }}" width="65%">
</p>

<p align="center">
  <img src="{{ '/docs/assets/AxleFit.jpeg' | relative_url }}" width="65%">
</p>

 <p align="center">
  <img src="{{ '/docs/assets/FinalDesign.jpeg' | relative_url }}" width="65%">
</p>

<p align="center">
  <img src="{{ '/docs/assets/FinalFit.jpeg' | relative_url }}" width="65%">
</p>


---

## Comparison Between Materials

The aluminum outcomes required less material due to the higher stiffness and yield strength of the material. As a result, the nylon design had thicker sections and more material to reach the same safety factor. The aluminum solution was able to generate a more open geometry with thinner structural members.

<p align="center">
  <img src="{{ '/docs/assets/NylonOutcome.png' | relative_url }}" width="65%">
</p>

<p align="center">
  <img src="{{ '/docs/assets/AluminumResult.png' | relative_url }}" width="65%">
</p>

---

## Generative Design: Pros and Cons

Generative design is useful for identifying efficient structures and reducing unnecessary material, but it requires highly constrained and performance-driven parts to be most successful. The process is also extremely sensitive to small errors and can be very time-consuming. In this project, it was challenging to define obstacle geometry that both prevented interference and still allowed enough clearance to physically assemble the motor, belt, and wheels. Because of this, generative design is most effective as an early-stage tool that helps guide geometry rather than producing a fully fabrication-ready solution.

---

## CAD Models
Generative Design Setup
<div style="text-align:center">
  <iframe
    src="https://a360.co/3YmEB7J"
    width="90%"
    height="540"
    frameborder="0"
    allowfullscreen>
  </iframe>
</div>

Aluminum Result
<div style="text-align:center">
  <iframe
    src="https://a360.co/4oSlMnR"
    width="90%"
    height="540"
    frameborder="0"
    allowfullscreen>
  </iframe>
</div>

Nylon Result
<div style="text-align:center">
  <iframe
    src="https://a360.co/3YoODFn"
    width="90%"
    height="540"
    frameborder="0"
    allowfullscreen>
  </iframe>
</div>


