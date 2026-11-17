# MAGSAFE ESP32-S3 HUB
**Don't get up, just use this...**

(Read bottom before reading BOM)

## About My Project

What is my project? My project is one of a kind! I am using an ESP32-S3 microcontroller chip to power a smart 2.8" TFT touchscreen. As mentioned in the title, it is listed as being MagSafe compatible, which is ingenious, right? Who does not want to have it charging 24/7? Or maybe not? Well, that has been solved too! I have added a 3.7V 5000mAh LiPo battery that can last well over 24 hours. But that is not all! I have also included an audio amplifier with a super loud and crisp speaker so you can hear those alerts and alarms from meters away.

I’ve made this project because I am tired of opening my laptop just to have a look at the time, set a timer, turn on smart lights, or do almost anything else. With my design, I’ll be able to control these all in one. You can have it play soothing music or play annoying alarms whenever.

**How to use:**

Plug it into the dedicated USB-C port at the bottom side with a USB-C cable or any compatible iPhone MagSafe charger. Let it charge for 10 minutes to an hour to fully charge. For MagSafe, let it charge for 30 minutes to an hour and 15 minutes.

## Schematics
The schematics of my final design, what I'll be using to make the main PCB.

N/A

## PCB
The fully routed PCB, with fun easter egg and smart eletrical wiring choices that save money and change the path of electricity more efficiently.

N/A

## CAD
A full design of the parts (except some models impossible to source)

N/A

## BOM

| Part | Type | Quantity | Unit price (USD) | Line total (USD) | Link | Funding | Reference | Footprint | Datasheet | MPN | LCSC |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Conn_01x01_Pin | Part | 6 | 0.00 | 0.00 | N/A | Grant | J7, J8, J9 | Connector_Wire:SolderWirePad_1x01_SMD_1.5x3mm | ~ | N/A | N/A |
| 0402, 1k | Part | 2 | 0.0013 | 0.0026 | [Link](https://lcsc.com) | Grant | R7 | Resistor_SMD:R_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402WGF1001TCE | C11702 |
| 0402, 22 | Part | 4 | 0.001 | 0.004 | [Link](https://lcsc.com) | Grant | R13, R14 | Resistor_SMD:R_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402WGF220JTCE | C25092 |
| 0 | Part | 4 | 0.0012 | 0.0048 | [Link](https://lcsc.com) | Grant | R10, R15 | Resistor_SMD:R_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402WGF0000TCE | C17168 |
| 0402, 5.1k | Part | 4 | 0.0014 | 0.0056 | [Link](https://lcsc.com) | Grant | R5, R6 | Resistor_SMD:R_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402WGF5101TCE | C25905 |
| 0402, 10k | Part | 4 | 0.0016 | 0.0064 | [Link](https://lcsc.com) | Grant | R11, R12 | Resistor_SMD:R_0402_1005Metric | [Datasheet](https://lcsc.com) | CQ02WGF1002TCE | C2765610 |
| 22 | Part | 4 | 0.0017 | 0.0068 | [Link](https://lcsc.com) | Grant | R8, R9 | Resistor_SMD:R_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402WGJ0220TCE | C25152 |
| LED | Part | 2 | 0.0036 | 0.0072 | [Link](https://lcsc.com) | Grant | D2 | LED_SMD:LED_0603_1608Metric | [Datasheet](https://lcsc.com) | XL-1608SURC-06 | C965799 |
| 6.8pF | Part | 4 | 0.0023 | 0.0092 | [Link](https://lcsc.com) | Grant | C19, C20 | Capacitor_SMD:C_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402CG6R8C500NT | C1576 |
| 100nF, 16V, X7R | Part | 10 | 0.0024 | 0.024 | [Link](https://lcsc.com) | Grant | C1, C6, C7, C13, C16 | Capacitor_SMD:C_0402_1005Metric | [Datasheet](https://lcsc.com) | CL05B104KO5NNNC | C1525 |
| 1uF | Part | 6 | 0.0057 | 0.0342 | [Link](https://lcsc.com) | Grant | C9, C12, C18 | Capacitor_SMD:C_0402_1005Metric | [Datasheet](https://lcsc.com) | CL05A105KA5NQNC | C52923 |
| Conn_01x02_Pin | Part | 2 | 0.0184 | 0.0368 | [Link](https://lcsc.com) | Grant | J1 | Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical | [Datasheet](https://lcsc.com) | PZ254V-11-02P | C492401 |
| ESD5Z3.3T1G | Part | 2 | 0.038 | 0.076 | [Link](https://lcsc.com) | Grant | D9 | Diode_SMD:D_SOD-523 | [Datasheet](https://lcsc.com) | ESD5Z3.3T1G | C61148 |
| Conn_01x07_Pin | Part | 2 | 0.0444 | 0.0888 | [Link](https://lcsc.com) | Grant | J3 | Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical | [Datasheet](https://lcsc.com) | PZ254V-11-07P | C492406 |
| UMH3N | Part | 2 | 0.0502 | 0.1004 | [Link](https://lcsc.com) | Grant | Q1 | Package_TO_SOT_SMD:SOT-363_SC-70-6 | [Datasheet](https://lcsc.com) | UMH3N | C62892 |
| SW_Push | Part | 4 | 0.0461 | 0.1844 | [Link](https://lcsc.com) | Grant | SW1, SW2 | Button_Switch_SMD:SW_SPST_CK_RS282G05A3 | [Datasheet](https://lcsc.com) | 1TS002E-2500-2501-CT | C255802 |
| Conn_01x14_Pin | Part | 2 | 0.0927 | 0.1854 | [Link](https://lcsc.com) | Grant | J4 | Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical | [Datasheet](https://lcsc.com) | PZ254V-11-14P | C22465874 |
| SS34 | Part | 6 | 0.0354 | 0.2124 | [Link](https://lcsc.com) | Grant | D1, D3, D4 | Diode_SMD:D_SMA | [Datasheet](https://lcsc.com) | SS34 | C8678 |
| 0805, 22uF, 25V, X5R | Part | 2 | 0.1093 | 0.2186 | [Link](https://lcsc.com) | Grant | C17 | Capacitor_SMD:C_0805_2012Metric | [Datasheet](https://lcsc.com) | CL21A226MAQNNNE | C45783 |
| USBLC6-2P6 | Part | 2 | 0.1572 | 0.3144 | [Link](https://lcsc.com) | Grant | U2 | Package_TO_SOT_SMD:SOT-666 | [Datasheet](https://lcsc.com) | USBLC6-2P6 | C2827693 |
| 10uF | Part | 6 | 0.0561 | 0.3366 | [Link](https://lcsc.com) | Grant | C5, C8, C10 | Capacitor_SMD:C_0402_1005Metric | [Datasheet](https://lcsc.com) | 0402X106M100NT | C2846677 |
| USB_C_Receptacle_USB2.0 | Part | 2 | 0.1888 | 0.3776 | [Link](https://lcsc.com) | Grant | E2 | Connector_USB:USB_C_Receptacle_HRO_TYPE-C-31-M-12 | [Datasheet](https://lcsc.com) | TYPE-C-31-M-12 | C165948 |
| AP2112K-3.3 | Part | 4 | 0.1683 | 0.6732 | [Link](https://lcsc.com) | Grant | U1, U3 | Package_TO_SOT_SMD:SOT-23-5 | [Datasheet](https://lcsc.com) | AP2112K-3.3TRG1 | C51118 |
| 32.768kHz | Part | 2 | 0.6128 | 1.2256 | [Link](https://lcsc.com) | Grant | Y2 | Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm | [Datasheet](https://lcsc.com) | ABS07-120-32.768KHZ-T | C1985240 |
| ESP32-S3-WROOM-1-N16R8 | Part | 2 | 5.3999 | 10.7998 | [Link](https://lcsc.com) | Grant | U4 | RF_Module:ESP32-S3-WROOM-1 | [Datasheet](https://lcsc.com) | ESP32-S3-WROOM-1-N16R8 | C2913202 |
| Shipping (JLCONE) | Shipping | 1 | 2.22 | 2.22 | [Link](https://jlcpcb.com) | Grant | N/A | N/A | N/A | N/A | N/A |
| Shipping (AliExpress) | Shipping | 1 | 2.03 | 2.03 | N/A | Grant | N/A | N/A | N/A | N/A | N/A |
| Tax (AliExpress) | Tax or fee | 1 | 1.74 | 1.74 | N/A | Grant | N/A | N/A | N/A | N/A | N/A |
| MAX98357A audio amplifier | Part | 1 | 2.07 | 2.07 | [Link](https://aliexpress.com) | Grant | MAX98357A | N/A | N/A | N/A | N/A |
| Wireless charger receiver | Part | 1 | 2.92 | 2.92 | [Link](https://aliexpress.com) | Grant | 5W | N/A | N/A | N/A | N/A |
| Battery management board | Part | 1 | 0.80 | 0.80 | [Link](https://aliexpress.com) | Grant | 1X-Type C | N/A | N/A | N/A | N/A |
| 5000mAh 955565 Lipo Lithium Battery | Part | 1 | 8.55 | 8.55 | [Link](https://aliexpress.com) | Grant | 3.7 V | N/A | N/A | N/A | N/A |
| 2W Speaker | Part | 1 | 2.60 | 2.60 | [Link](https://aliexpress.com) | Grant | 2535 4 ohm 3W | N/A | N/A | N/A | N/A |
| 2.8 TFT Screen | Part | 1 | 7.60 | 7.60 | [Link](https://aliexpress.com) | Already own | 2.8 Inch Display | N/A | N/A | N/A | N/A |
| PCBA | Tax or fee | 2 | 44.455 | 88.91 | [Link](https://jlcpcb.com) | Grant | N/A | N/A | N/A | N/A | N/A |
| PCB | Part | 5 | 0.592 | 2.96 | N/A | Grant | N/A | N/A | N/A | N/A | N/A |
| **Total** | | | | **137.3348** | | | | | | | |
| **Grant total** | | | | **129.7348** | | | | | | | |

# IMPORTANT READ BELOW

**Just to let you know:**

The total for the PCB is $150 AUD, plus $25 AUD for the AliExpress modules, bringing the actual total to $175 AUD.
You might notice the Bill of Materials (BOM) shows a total of around $200 AUD. This looks high because the BOM lists the individual prices of every single component. However, the PCB and PCBA prices already include the cost of these parts and their assembly.

I included the individual parts in the list just to show the breakdown, but you do not need to buy them separately. Since they are already covered in the PCBA price, they will not be added to the final cost.