---
title: "ESP32 PC Remote Starter"
github: "https://github.com/pdpo/esp32-pc-remote-starter"
description: "A small enclosure connected to your PCs front panel headers to turn on and reset your PC using: physical buttons on the case (duh) WiFi, Bluetooth, 433MHz RF Remote, and an optional extra button.\n\nI am building this because I often stream games from my PC using Moonlight, but leaving my PC always running wastes alot of energy. This remote starter allows me to turn on my PC remotely so it doesn't matter if your in a different country, planet (one that has wifi), or just in across your house you will always be able to start your PC remotely!"
created_at: "2026-10-03"
total_time: "12h"
---

# October 3, 2026: Planning the project & safety
<!-- fabricate:entry 91 -->

I researched and planned the hardware for the remote starter:

- Safety: Connecting an ESP32 directly to the motherboard power pins can cause voltage spikes. To avoid that from happening I added an 5v relay module with an optocoupler that isolates the PC from the ESP32.
- Components: I chose the ESP32-C3 Supermini for its WiFi and Bluetooth support in a tiny form factor. I added a basic 433MHz receiver for RF support, a simple 2 button 433MHz remote, an extra button, and also an LED diode (with 220ohm resistors) to show its ready to be used.
- Soldering: Since some soldering will be used with wires n stuff I will be using a heat shrink set to protect the wires.
- Sourcing: Sourced components trough Otronic.nl to keep total price low and get it locally.

![](https://fabricate.hackclub-assets.com/847de494c426bfe692a01c6ee8c08684c3c7304c0c35a27ee88c9b62b7663d49/brave_4g1bAB3uZe.png)

**Total time spent: 1h 30m**

# October 3, 2026 (entry 2): Wiring Diagram & Optimizing Costs
<!-- fabricate:entry 92 -->

I started wiring everything up. I made the diagram using Canva and found the pinouts of the boards online to help me. The diagram isn't really pretty but does show where everything is supposed to go.

## What was changed?
I decided to swap out the 5V Relay with Optocoupler with a simpler 2-Channel Optocoupler. Why? A relay was way too overkill for this project, used more space, cost more, and I would need 2 of them to also be able to use the Reset SW. While an optocoupler does the exact same job for this project for a lower price.

![](https://fabricate.hackclub-assets.com/6ed10b4d7741c44448e43a07a23fda788efef725715ee5e958a82625b0c22976/diagram.png)

**Total time spent: 2h**

# October 3, 2026 (entry 3): Designing the enclosure
<!-- fabricate:entry 107 -->

I designed the enclosure to fit every component like the ESP32, RF Receiver, and the Optocoupler. Since im not that good in CAD I still tried my best. The RF receiver gets slid into the side wall, the optocoupler goes trough these cilinders snug to stay seated, and the esp32 gets pushed into a little hole. Next time I will write the firmware.

![](https://fabricate.hackclub-assets.com/2fb6d5a3a404a893c5b897ff338036c495770f3f9f89c3ac174662404a2298f5/brave_yYzOaGOmz7.png)

**Total time spent: 2h 30m**

# October 4, 2026: 3D Printing Enclosure & Problem
<!-- fabricate:entry 121 -->

I've printed the enclosure on my Bambu Lab P2S using PLA and surprisingly it wasn't even that bad! However we have 2 small problems: first the usb-c hole is a little small so the size of that has to get increased. Second, theres no lid so everythings just exposed, I will be adding a sliding lid for easy access and simple designing. What is nice tho is that the 6 wires fit that have to come out the enclosure. It took only 20g of cheap PLA and 22 minutes to print on Sport (altough theres no lid which would probably add only a few grams extra).

![](https://fabricate.hackclub-assets.com/d28c48ec154fe02eaa17955bc4d80b4e9719034a2013d8c55f9b821dd51b7152/IMG_20261004_125832.jpg)
![](https://fabricate.hackclub-assets.com/6c0a05cbd3e6776b2d056e66dce7b260542fbae94626c3971171020619408eb2/IMG_20261004_125814.jpg)
![](https://fabricate.hackclub-assets.com/d1eaa946cba7c16819b6dd95e023dc0bf2fb453f4268e3165d146bbf4d972eaf/IMG_20261004_130748.jpg)
![](https://fabricate.hackclub-assets.com/c8e737d0f1e955ee0a042b63600e19cad876bd3b6123161a8cdff936a2af3cbb/IMG_20261004_131226.jpg)

**Total time spent: 1h**

# October 4, 2026 (entry 2): Redesigned Enclosure & Coding
<!-- fabricate:entry 127 -->

## Enclosure
I have completely redesigned the enclosure in Autodesk Fusion (I first used Tinkercad as a quick prototype) and made it significantly better. The usb-c port is bigger, added texts to show where modules go, and added a cool looking lid with the logo and model name.

## Coding
Also I started coding the firmware, adding the Wi-Fi, RF and External button. The code is untested but it is a proof of concept.

![](https://fabricate.hackclub-assets.com/2c9e94bc150eefdd3564dae9959695c20ca8a8defb75f0cd78826c00da91c6c3/Fusion360_mWeJ7LPSDj.png)
![](https://fabricate.hackclub-assets.com/3b3704b14b227925680864e3614c8c844bccde28d730a05f736589afaa8a56f2/Fusion360_Ia8nqv9sJi.png)
![](https://fabricate.hackclub-assets.com/37a2b6e745d20f90d0fb015be771dfd1318ca957a24ce5b240073168ad6a1625/Arduino_IDE_ISS4q7VEeF.png)

**Total time spent: 3h**

# October 6, 2026: Finalizing Everything
<!-- fabricate:entry 159 -->

I made the README complete with images and even a logo! Organized everything in folders and exported my files. Now I will submit my project and hope it gets accepted, I cant wait to build it!

**Update:** whoops I completely forgot to update the wiring diagram to change the relay to the optocoupler. i'll re edit that now.

![](https://fabricate.hackclub-assets.com/dff8ef109fe38c2165a692dca9208200aba4065fd1d2bbc2948f3a3f477f332d/explorer_an4TEQHL6Z.png)

**Total time spent: 2h**
