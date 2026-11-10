---
title: "Custom ESP32-S3 hub with MAGSAFE!"
github: "https://github.com/MinoMark/MAGSAFE-ESP-32S3-HUB"
description: "I'm using an ESP32-S3-WROOM-1U-N16R8 with MAGSAFE to create a hub to control varius things around the house, or just a basic desk accessory, this project will have 1 speaker with an adapter from my custom pcb encasing to hold the amplifier and the speakers using simple Interfaces for the audio amplifier!\n\nA battery will be included as well, so there will be a 5v to 3.3v reduction circuirt (MAGSAFE causes this)."
created_at: "2026-11-05"
total_time: "12h 42m"
---

# November 5, 2026: Design the first schematic
<!-- fabricate:entry 2192 -->

I'm on the first stage of making my project! So far I've worked on designing the schematic of the PCB. There were many difficult challenges I had to overcome, such as learning about power management for wireless. Because the wireless module I've looked into has a 5V output, and my microcontroller can only take 3.3V, I had to make a 3.3V regulator from scratch. I've learnt how to manage power usage in my project today; hopefully, I can use it for future projects or maybe later on!

I've made a parts list of what I may use when I make this. I've chosen things that can help with my design because of their size and shape, so it fits easily. I have learnt that you will need a ferrite sheet to block the magnetic fields from the wireless charger to avoid damaging or changing how your PCB works. As we all know, copper is a conductor, and it can distort and even possibly induce new current into the circuit.

[EDIT: I changed the GPIO pin of the Audio Amplifier from GPIO 1015 to 1017, did not see the crystal there!]

![](https://fabricate.hackclub-assets.com/9fd863c530be8123294163bfc11d50a8ae513a8a5defb6b0a655088057835c5e/image-png/Screenshot%202026-11-05%20215135.png)
![](https://fabricate.hackclub-assets.com/2abe7baf71a2d90b24b2cf840e0cd7429001473f4caf26faa81762e5c2e73b3a/image-png/Screenshot%202026-11-05%20215142.png)
![](https://fabricate.hackclub-assets.com/d63eee66d4f52e5aadd01582b7168eb5e1422a3d29c26abba3f3205910e4f4ef/image-png/Screenshot%202026-11-05%20220425.png)

**Total time spent: 4h**

# November 5, 2026 (entry 2): Fixing power and MAGSAFE compatibility
<!-- fabricate:entry 2253 -->

Day 2 went well. I've worked on fixing some power compatibility issues with MagSafe. Let me explain the issues I had.

Because my circuit is going to be powered by MagSafe and/or USB-C, I needed my circuit to accept power from both and not go back into the circuit when idle. I've used two diodes which both block the flow of electricity if it were to move in the opposite direction. Further down I added a solder pad, so I can add a jumper cable to a separate battery management board. With the output of that board, it will connect to another solder pad connected to the 5V to 3V3 step-down circuit which will output a clean 3V3 for the rest of the circuit to be powered.

As well as that, I've added new footprints too my ESP, USB-C and Pins. There was a small weird error involving the headers to be a diffrent comonent, luckly I found out it was just a footprint missmatch.

I'll add some models for 3 of the components later.

![](https://fabricate.hackclub-assets.com/fecb9c3173decc4dc18e847c34bdbedf17ef44511f23aec5d3c690c7f3501f68/image-png/Screenshot%202026-11-06%20185651.png)
![](https://fabricate.hackclub-assets.com/d000a7819f388dcc03164e2ebfd81b7562e2461225b05e08566d4923c82bf36c/image-png/Screenshot%202026-11-06%20185906.png)
![](https://fabricate.hackclub-assets.com/9040f6572b3bb1cf3ade2f4814570c5e1123cad55f6c2bd6ae3a886a71ddcf0a/image-png/Screenshot%202026-11-06%20190014.png)
![](https://fabricate.hackclub-assets.com/efedb13792515d00ffda86d71f843a166dfc435fa2511f74437a9339179bd83e/image-png/Screenshot%202026-11-06%20190028.png)

**Total time spent: 3h 30m**

# November 6, 2026: Adding my traces to the PCB
<!-- fabricate:entry 2296 -->

Today I did so much progress!

I've added my traces to my PCB, fixed so many (over 260 ERC errors), and learned something new about how ICs cool themselves. When making my PCB, I first had to measure a component I already had (a 2.8" TFT screen). I used that measurement's length and width to ensure that the PCB is not too long nor short. Later on, I intend to have the enclosure of the PCB fit around this (will, of course, include the MagSafe and charger module, etc.). This is expected to be very thick, but there is nothing I can do. I've tried looking for thinner components, but it's not a big deal.

Ok, now for my schematic. If you look at it, on the ESP IC, you see text along the pins (not the ones in a box). By mistake, I was labeling the pins I want to use with this instead of the global labels, so in my PCB editor, none of the pins were being used. Luckily, after testing a new label (global label), it worked very well. My PCB has 6 layers (one of which I won't be using). Layer one is the thick 5V traces from the USB-C they are 5mm. The layer below is a ground plane. This is important because I won't need traces for the ground plane, I just need a via and it will connect to the ground net plane. The next layer is a 3V3+ power plane. It covers the whole board for every part that needs it. The next layer is just data traces, and so is everything else below it.

I also had one major issue. So, in one of the photos I sent here, there is like a red square. I learned that this is for cooling, and I also set a constraint that shows errors for any via that's less than 0.3mm in diameter.

That's all for today!

![](https://fabricate.hackclub-assets.com/d37c19ec3f95593ff883c402d6c5d714af258c046ac769d5a5a72c8ca276a09a/image-png/Screenshot%202026-11-07%20160842.png)
![](https://fabricate.hackclub-assets.com/fa9205f20e07801dfd2e061457baa49563108fba4a17b6632ff5aea8ac7cbdca/image-png/Screenshot%202026-11-07%20161232.png)
![](https://fabricate.hackclub-assets.com/433f2366ea1e97a4d0b4486853495a7614d2e42fffaa73a42cbf2716a465c6fe/image-png/Screenshot%202026-11-07%20161254.png)
![](https://fabricate.hackclub-assets.com/7d80a308b6cc5b01ded96ead5f266ce1cdc9057539aa7b5d1215660f7f0994a6/image-png/Screenshot%202026-11-07%20161311.png)
![](https://fabricate.hackclub-assets.com/b0e70d745f2d8c57c022e3c39bcd7fdb99c546395e4d795ada05eb97c25740aa/image-png/Screenshot%202026-11-07%20182727.png)

**Total time spent: 2h 30m**

# November 7, 2026: Making BOM and final changes to PCB
<!-- fabricate:entry 2381 -->

I have made the BOM so far, with all the AliExpress modules I need for my project. Also, when calculating a price for the manufactured PCB, because my PCB was 6 layers, it cost almost 200% more than a standard 4-layer PCB.

So my biggest challenge was first figuring out how to make it so that it has fewer layers, then filling in the traces of the others. Luckily, I was able to fix this in KiCad. I first set the PCB layers from 6 to 4, which deleted all the other traces that were in those layers. Then, I used a ground plane and a 3V3+ plane, adding traces and pressing 'b' regularly to recalculate the planes.

This allowed me to save almost 500 dollars in production (yes, 6-layer PCBs do cost that much).

![](https://fabricate.hackclub-assets.com/795f7ad772da6f0c620dcb00a3bb0f8bd52263b96f90c48c5f6dbd1d7828b1cd/image-png/Screenshot%202026-11-08%20172354.png)
![](https://fabricate.hackclub-assets.com/68e3216d7c9f753042dee56f34971ab496061e97368aa4407f59ca363c48c7ee/image-png/Screenshot%202026-11-08%20172400.png)
![](https://fabricate.hackclub-assets.com/20957fa523b9752b33477b66f3be4f04266968f48778c7c2e80d1139d5f602ee/image-png/Screenshot%202026-11-08%20173457.png)

**Total time spent: 1h 30m**

# November 8, 2026: Money issues and small issues with PCB FIXED
<!-- fabricate:entry 2389 -->

After I made the change from a 6-layer PCB to a 4-layer PCB, I went back to JLCPCB and looked into the pricing and I found that it was way cheaper.

As well as that, when I was looking at the order page, I got notified that there was a piece that was not in stock. It was an LDO part from the 5V to 3V3 step-down, the one directly under the USB-C connector in the schematic editor. I removed and replaced the part that was out of stock and replaced it with an AP2112K-3.3 instead.

This allowed me to save time and money waiting for it to get back in stock or finding more expensive alternatives. Along with this, I had to delete a resistor (R18) that accompanied this old chip. I have also sourced some models for the ESP, pin headers, and the USB-C connector.

![](https://fabricate.hackclub-assets.com/7f47f509149857056eddff86da112dea3d4d9be8eaea692c67ef461db8c6897f/image-png/Screenshot%202026-11-08%20232824.png)
![](https://fabricate.hackclub-assets.com/565903b5c245e57dd6b44cba672b66f6cea5f5cc1a6db1509d25708f4e658ab8/image-png/Screenshot%202026-11-08%20232850.png)
![](https://fabricate.hackclub-assets.com/b5f247866a949e6b733b24ed66531ba8839a1704cb97bf59edbdd25119f60a51/image-png/Screenshot%202026-11-08%20202810.png)
![](https://fabricate.hackclub-assets.com/09318462ed5b3bb90eee9554612aeb8a73fd9b0e51c5007a1ee1e994ee4115d4/image-png/Screenshot%202026-11-08%20202822.png)

**Total time spent: 42m**

# November 9, 2026: Created and finished my REPO
<!-- fabricate:entry 2536 -->

Today I created and finished my repository. I was struggling a lot with how to add files into my repository so I searched online and used forums to try to figure it out. I ended up installing Git and running commands to commit and push an update to my repository.

This allowed me to finally update and regularly add new content into my repository while giving me the ability to add files whenever I want.

![](https://fabricate.hackclub-assets.com/f8afa1353c59282fded6546521d9f0aeaca4c1496fd12c0aadb4503e81a3d01e/image-png/Screenshot%202026-11-10%20162832.png)
![](https://fabricate.hackclub-assets.com/363b2ac1f36615fe5bfb2b6bd316cbfdeb32a892b3119fea63c650e525adbfa2/image-png/Screenshot%202026-11-10%20162837.png)

**Total time spent: 30m**
