---
layout: default
title: Pinch Flow Fractionation Microfluidic Device
subtitle: Resin-printed PFF device for size-based particle sorting
teaser: Symmetric pinch flow fractionation device designed & fabricated using SLA printing.
description: Exploring particle separation in a symmetric microfluidic geometry with resin-printed molds and PDMS casting.
date: 2025-03-05
thumbnail: docs/assets/MicrofluidicDeviceRendering.png
featured: true
---

# Microfluidic Device

## Introduction

Pinch flow fractionation is a method for separating particles by size using laminar flow, which is how fluids travel in smooth, parallel layers without mixing. This stands in contrast to turbulent flow, which is swirlier and more chaotic. Pinch flow fractionation takes advantage of this by squeezing a stream of particles through a pinch segment that spreads into different paths en route to separate outlets. This relatively simple concept has a wide and helpful range of applications, and this microfluidic sorter could be used to separate different-sized particles for things like biomedical testing or environmental sampling. For example, a paper from the National Library of Medicine explains how a spiral microfluidic device was used to separate bacterial cells from large debris in the field of food safety. In this study, the spiral device achieved an average bacterial recovery efficiency of around 80% for swab samples and 70% for ground-meat suspensions (National Library of Medicine).

---

## Design

![Sketch Placeholder](/docs/assets/MicrofluidicDeviceRendering.png)
A symmetric approach was taken to simplify the logic behind balancing the flow, as the paths have identical outlet resistance. This puts emphasis on particle separation from the PFF, without support or skewing from geometric asymmetry.

The outlet boundaries for small and large particles and buffer flow were based on the PFF equation, which calculates the expected vertical position after the expansion zone based on the particle diameter. Based on a pinched width of 1 mm and broad width of 40 mm, the small particles were expected to hit the top, with the large particles around the 6 mm to 7 mm range. The buffer outlets were then placed below this to collect the excess flow with no particles.

A problem proposed by this is that the buffer layer of fluid that carries no particles is much thicker than the stream of both small and large particles. Because of this, there is an unequal backpressure between the outlets, and the backflow from the buffer layer to the large and small particle outlets disturbs the sorting. This was accounted for by increasing the resistance of the path to the particle outlets to create more equal resistances between the three paths.

![Sketch Placeholder](/docs/assets/SketchDimensions.png)

The final design consisted of a pinched segment with a width of 1.0 mm to accommodate particles up to 500 µm while maintaining laminar focusing. The broad channel expands to 40 mm over a 20 mm length, allowing clear spatial separation of small (125–150 µm) and large (425–500 µm) particles before reaching the outlets. Three 2.2 mm diameter outlet ports were positioned along the right edge of the device. The buffer channel was an 11 mm taper from 27.25 mm to 2.2 mm. The small and large particle outlets were placed at heights according to the calculated output positions, 37 mm and 30 mm from the base wall respectively. The channel length for the small and large particles was increased to 30 mm to increase resistance. The channels were extruded 1.5 mm tall in the mold.

![Final Device Placeholder](/docs/assets/microfluidicDevicePrint.png)

In testing, the device did not function as expected because the flow was not purely laminar. The fluids experienced pressure differences in the broad section due to the siphoning effect. If the design were iterated, the abrupt jump from the 1 mm pinched section to the 40 mm broad section would be replaced with a longer, smooth taper to help control turbulent behavior.

---

## Instructions

**Designing the model** – The mold was first designed in Autodesk Fusion with 50 mm × 75 mm base dimensions and 2.2 mm posts for the inlet and outlet ports. The model is designed as an inverse of the desired microfluidic device.

**Printing** – The mold was resin printed on a Form 3+/4 SLA printer. The key at this stage was ensuring that the bottom of the mold was perfectly flat and parallel to the resin vat.

**Post-printing** – The device was washed for 5 minutes in one machine and another 5 minutes in the second. The device then had to dry leaning upside down for 30 minutes before curing to prevent pooling of resin. Compressed air was then used to blow off any additional debris. The mold was finally cured for 1 minute to prevent warping from excess curing before removing the support material.

**Mold to device** – To turn the mold into a functional device, PDMS was mixed at a 10:1 ratio, poured over the mold, and heat-cured overnight at ~55°C to avoid cracking or distortion from higher temperatures. After peeling the cured PDMS, the device and glass slide were plasma-treated and bonded together. Then, tubing was added and the device was primed under pressure to remove bubbles before running polyethylene (PE) beads through the system.

---

## Discussion

A benefit of PFF over traditional techniques like filtering in this example includes clog-free operation, in that there is no filter to trap particles. Furthermore, PFF allows for easy scaling to account for a wide range of sizes, from micron-level bacteria to cell clusters and beyond. The design can be scaled up or modified to handle a wider range of particle sizes by changing the width of the pinched section. The lower particle-size limit is set by when diffusion tolerances stop allowing for effective laminar flow.

---

## Files & Links

🔗 **Fusion 360 CAD Model**
{% raw %}
<div style="aspect-ratio:16/9; border:1px solid #eee; border-radius:10px; overflow:hidden; margin: 8px 0 16px;">
  <iframe 
    src="https://a360.co/47zjFP7"
    width="100%" height="100%" allowfullscreen loading="lazy">
  </iframe>
</div>
{% endraw %}
**References**
- **Spiral microfluidic device for bacterial separation in food safety applications.**  
  *National Library of Medicine.*  
  🔗 https://pmc.ncbi.nlm.nih.gov/articles/PMC10415021/



