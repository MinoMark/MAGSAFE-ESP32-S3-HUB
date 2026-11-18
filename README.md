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

| Part | Type | Quantity | Unit price (USD) | Line total (USD) | Link | Vendor | Funding | Notes | Reference | Footprint | Datasheet | MPN | LCSC |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Conn_01x01_Pin | Part | 6 | 0.00 | 0.00 | N/A |  | Grant | N/A | J7,J8,J9 | Connector_Wire:SolderWirePad_1x01_SMD_1.5x3mm | ~ | N/A | N/A |
| 0402,1k | Part | 2 | 0.0013 | 0.0026 | [LCSC](https://www.lcsc.com/datasheet/C11702.pdf) |  | Grant |  | R7 | Resistor_SMD:R_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C11702.pdf) | 0402WGF1001TCE | C11702 |
| 0402,22 | Part | 4 | 0.001 | 0.004 | [LCSC](https://www.lcsc.com/datasheet/C25092.pdf) |  | Grant |  | R13,R14 | Resistor_SMD:R_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C25092.pdf) | 0402WGF220JTCE | C25092 |
| 0 | Part | 4 | 0.0012 | 0.0048 | [LCSC](https://www.lcsc.com/datasheet/C17168.pdf) |  | Grant |  | R10,R15 | Resistor_SMD:R_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C17168.pdf) | 0402WGF0000TCE | C17168 |
| 0402,5.1k | Part | 4 | 0.0014 | 0.0056 | [LCSC](https://www.lcsc.com/datasheet/C25905.pdf) |  | Grant |  | R5,R6 | Resistor_SMD:R_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C25905.pdf) | 0402WGF5101TCE | C25905 |
| 0402,10k | Part | 4 | 0.0016 | 0.0064 | [LCSC](https://www.lcsc.com/datasheet/C2765610.pdf) |  | Grant |  | R11,R12 | Resistor_SMD:R_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C2765610.pdf) | CQ02WGF1002TCE | C2765610 |
| 22 | Part | 4 | 0.0017 | 0.0068 | [LCSC](https://www.lcsc.com/datasheet/C25152.pdf) |  | Grant |  | R8,R9 | Resistor_SMD:R_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C25152.pdf) | 0402WGJ0220TCE | C25152 |
| LED | Part | 2 | 0.0036 | 0.0072 | [LCSC](https://www.lcsc.com/datasheet/C965799.pdf) |  | Grant |  | D2 | LED_SMD:LED_0603_1608Metric | [LCSC](https://www.lcsc.com/datasheet/C965799.pdf) | XL-1608SURC-06 | C965799 |
| 6.8pF | Part | 4 | 0.0023 | 0.0092 | [LCSC](https://www.lcsc.com/datasheet/C1576.pdf) |  | Grant |  | C19,C20 | Capacitor_SMD:C_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C1576.pdf) | 0402CG6R8C500NT | C1576 |
| 100nF,16V,X7R | Part | 10 | 0.0024 | 0.024 | [LCSC](https://www.lcsc.com/datasheet/C1525.pdf) |  | Grant |  | C1,C6,C7,C13,C16 | Capacitor_SMD:C_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C1525.pdf) | CL05B104KO5NNNC | C1525 |
| 1uF | Part | 6 | 0.0057 | 0.0342 | [LCSC](https://www.lcsc.com/datasheet/C52923.pdf) |  | Grant |  | C9,C12,C18 | Capacitor_SMD:C_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C52923.pdf) | CL05A105KA5NQNC | C52923 |
| Conn_01x02_Pin | Part | 2 | 0.0184 | 0.0368 | [LCSC](https://www.lcsc.com/datasheet/C492401.pdf) |  | Grant |  | J1 | Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical | [LCSC](https://www.lcsc.com/datasheet/C492401.pdf) | PZ254V-11-02P | C492401 |
| ESD5Z3.3T1G | Part | 2 | 0.038 | 0.076 | [LCSC](https://www.lcsc.com/datasheet/C61148.pdf) |  | Grant |  | D9 | Diode_SMD:D_SOD-523 | [LCSC](https://www.lcsc.com/datasheet/C61148.pdf) | ESD5Z3.3T1G | C61148 |
| Conn_01x07_Pin | Part | 2 | 0.0444 | 0.0888 | [LCSC](https://www.lcsc.com/datasheet/C492406.pdf) |  | Grant |  | J3 | Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical | [LCSC](https://www.lcsc.com/datasheet/C492406.pdf) | PZ254V-11-07P | C492406 |
| UMH3N | Part | 2 | 0.0502 | 0.1004 | [LCSC](https://www.lcsc.com/datasheet/C62892.pdf) |  | Grant |  | Q1 | Package_TO_SOT_SMD:SOT-363_SC-70-6 | [LCSC](https://www.lcsc.com/datasheet/C62892.pdf) | UMH3N | C62892 |
| SW_Push | Part | 4 | 0.0461 | 0.1844 | [LCSC](https://www.lcsc.com/datasheet/C255802.pdf) |  | Grant |  | SW1,SW2 | Button_Switch_SMD:SW_SPST_CK_RS282G05A3 | [LCSC](https://www.lcsc.com/datasheet/C255802.pdf) | 1TS002E-2500-2501-CT | C255802 |
| Conn_01x14_Pin | Part | 2 | 0.0927 | 0.1854 | [LCSC](https://www.lcsc.com/datasheet/C22465874.pdf) |  | Grant |  | J4 | Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical | [LCSC](https://www.lcsc.com/datasheet/C22465874.pdf) | PZ254V-11-14P | C22465874 |
| SS34 | Part | 6 | 0.0354 | 0.2124 | [LCSC](https://www.lcsc.com/datasheet/C8678.pdf) |  | Grant |  | D1,D3,D4 | Diode_SMD:D_SMA | [LCSC](https://www.lcsc.com/datasheet/C8678.pdf) | SS34 | C8678 |
| 0805,22uF,25V,X5R | Part | 2 | 0.1093 | 0.2186 | [LCSC](https://www.lcsc.com/datasheet/C45783.pdf) |  | Grant |  | C17 | Capacitor_SMD:C_0805_2012Metric | [LCSC](https://www.lcsc.com/datasheet/C45783.pdf) | CL21A226MAQNNNE | C45783 |
| USBLC6-2P6 | Part | 2 | 0.1572 | 0.3144 | [LCSC](https://www.lcsc.com/datasheet/C2827693.pdf) |  | Grant |  | U2 | Package_TO_SOT_SMD:SOT-666 | [LCSC](https://www.lcsc.com/datasheet/C2827693.pdf) | USBLC6-2P6 | C2827693 |
| 10uF | Part | 6 | 0.0561 | 0.3366 | [LCSC](https://www.lcsc.com/datasheet/C2846677.pdf) |  | Grant |  | C5,C8,C10 | Capacitor_SMD:C_0402_1005Metric | [LCSC](https://www.lcsc.com/datasheet/C2846677.pdf) | 0402X106M100NT | C2846677 |
| USB_C_Receptacle_USB2.0 | Part | 2 | 0.1888 | 0.3776 | [LCSC](https://www.lcsc.com/datasheet/C165948.pdf) |  | Grant |  | E2 | Connector_USB:USB_C_Receptacle_HRO_TYPE-C-31-M-12 | [LCSC](https://www.lcsc.com/datasheet/C165948.pdf) | TYPE-C-31-M-12 | C165948 |
| AP2112K-3.3 | Part | 4 | 0.1683 | 0.6732 | [LCSC](https://www.lcsc.com/datasheet/C51118.pdf) |  | Grant |  | U1,U3 | Package_TO_SOT_SMD:SOT-23-5 | [LCSC](https://www.lcsc.com/datasheet/C51118.pdf) | AP2112K-3.3TRG1 | C51118 |
| 32.768kHz | Part | 2 | 0.6128 | 1.2256 | [LCSC](https://www.lcsc.com/datasheet/C1985240.pdf) |  | Grant |  | Y2 | Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm | [LCSC](https://www.lcsc.com/datasheet/C1985240.pdf) | ABS07-120-32.768KHZ-T | C1985240 |
| ESP32-S3-WROOM-1-N16R8 | Part | 2 | 5.3999 | 10.7998 | [LCSC](https://www.lcsc.com/datasheet/C2913202.pdf) |  | Grant |  | U4 | RF_Module:ESP32-S3-WROOM-1 | [LCSC](https://www.lcsc.com/datasheet/C2913202.pdf) | ESP32-S3-WROOM-1-N16R8 | C2913202 |
| Shipping (JLCONE) | Shipping | 1 | 2.22 | 2.22 | [JLCPCB](https://jlcpcb.com/?from=VGS&utm_source=google&utm_medium=cpc&utm_campaign=14177189905&gad_source=1&gad_campaignid=14177189905&gbraid=0AAAAABS1QqkgPoFOHUy_26J4N5kBx4Aa3&gclid=Cj0KCQiAwdDXBhDuARIsAFdLukmN-B7r3FdQKI8Ma6WjcPEJgnZSJuI_80tu4TU9jCkDFhZ-cYRUD3oaAn0kEALw_wcB) |  | Grant |  | N/A | N/A | N/A | N/A | N/A |
| Shipping (AliExpress) | Shipping | 1 | 2.03 | 2.03 | N/A |  | Grant |  | N/A | N/A | N/A | N/A | N/A |
| Tax (AliExpress) | Tax or fee | 1 | 1.74 | 1.74 | N/A |  | Grant |  | N/A | N/A | N/A | N/A | N/A |
| MAX98357A audio amplifier | Part | 1 | 2.07 | 2.07 | [AliExpress](https://www.aliexpress.com/item/1005007003802663.html?spm=a2g0o.productlist.main.4.2bd23ce0doG6x8&aem_p4p_detail=202611050133081315319932123740002772996&algo_pvid=0ad6be40-46e3-4f00-9430-e9820924795f&algo_exp_id=0ad6be40-46e3-4f00-9430-e9820924795f-3&pdp_ext_f=%7B%22order%22%3A%223834%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21AUD%212.99%212.84%21%21%2113.80%2113.11%21%402101ca9517938711880116699e0d41%2112000052658790894%21sea%21AU%212961347876%21X%211%210%21n_tag%3A-29919%3Bd%3A20f6a0d2%3Bm03_new_user%3A-29895%3BpisId%3A5000000220905999&curPageLogUid=gHNWoxg3Cup0&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007003802663%7C_p_origin_prod%3A&search_p4p_id=202611050133081315319932123740002772996_1) |  | Grant |  | MAX98357A | N/A | N/A | N/A | N/A |
| Wireless charger receiver | Part | 1 | 2.92 | 2.92 | [AliExpress](https://www.aliexpress.com/item/1005006917890401.html?spm=a2g0o.productlist.main.21.5befc5e30wHdxF&algo_pvid=c3f727d4-7764-4de2-9cfe-4073aea75173&algo_exp_id=c3f727d4-7764-4de2-9cfe-4073aea75173-18&pdp_ext_f=%7B%22order%22%3A%22260%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21AUD%213.98%213.49%21%21%212.75%212.41%21%402101d2e717938715347906588e0f1b%2112000038722150536%21sea%21AU%212961347876%21X%211%210%21n_tag%3A-29919%3Bd%3A20f6a0d2%3Bm03_new_user%3A-29895%3BpisId%3A5000000220770329&curPageLogUid=ptJgFovmIGzU&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006917890401%7C_p_origin_prod%3A) |  | Grant |  | 5W | N/A | N/A | N/A | N/A |
| Battery management board | Part | 1 | 0.80 | 0.80 | [AliExpress](https://www.aliexpress.com/item/1005013472412754.html?spm=a2g0o.productlist.main.9.7fb4e999hY7Rre&algo_pvid=98fe2f10-0cd6-416a-bbd2-9b577de21ebe&algo_exp_id=98fe2f10-0cd6-416a-bbd2-9b577de21ebe-8&pdp_ext_f=%7B%22order%22%3A%225%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21AUD%212.45%210.97%21%21%2111.31%214.51%21%402101d33417938729376868658e0dc7%2112000061234386246%21sea%21AU%212961347876%21X%211%210%21n_tag%3A-29919%3Bd%3A20f6a0d2%3Bm03_new_user%3A-29895%3BpisId%3A5000000220868114&curPageLogUid=SZ1nXcZwQJOj&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005013472412754%7C_p_origin_prod%3A) |  | Grant |  | 1X-Type C | N/A | N/A | N/A | N/A |
| 5000mAh 955565 Lipo Lithium Battery | Part | 1 | 8.55 | 8.55 | [AliExpress](https://www.aliexpress.com/item/1005012710344008.html?spm=a2g0o.detail.0.0.4f13zLNrzLNrYC&mp=1&pdp_npi=6%40dis%21AUD%21AUD+44.89%21AUD+12.70%21%21AUD+12.70%21%21%21%402101c69517948801902018396e0e59%2112000059134254104%21ct%21AU%212961347876%21%211%210%21) |  | Grant |  | 3.7 V | N/A | N/A | N/A | N/A |
| 2W Speaker | Part | 1 | 2.60 | 2.60 | [AliExpress](https://www.aliexpress.com/item/1005007640238935.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.4.6cacshuCshuCnA&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=b61e8163-83fe-4c95-9dc5-7b9f26661546&_t=gps-id%3ApcDetailTopMoreOtherSeller%2Cscm-url%3A1007.40050.354490.0%2Cpvid%3Ab61e8163-83fe-4c95-9dc5-7b9f26661546%2Ctpp_buckets%3A668%232846%238110%231995&pdp_ext_f=%7B%22order%22%3A%222631%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21AUD%214.06%213.69%21%21%2118.49%2116.82%21%402103117b17940474651706506e0d0b%2112000041608234950%21rec%21AU%212961347876%21XZ%211%210%21n_tag%3A-29919%3Bd%3A20f6a0d2%3Bm03_new_user%3A-29895%3BpisId%3A5000000220905999&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005007640238935%7C_p_origin_prod%3A) |  | Grant |  | 2535 4 ohm 3W | N/A | N/A | N/A | N/A |
| 2.8" TFT Screen | Part | 1 | 7.60 | 7.60 | [AliExpress](https://www.aliexpress.com/item/1005008568072063.html?spm=a2g0o.productlist.main.11.1c26482dWSHE9j&algo_pvid=15dab31f-5e3b-4a75-826a-e8b2a567e931&algo_exp_id=15dab31f-5e3b-4a75-826a-e8b2a567e931-10&pdp_ext_f=%7B%22order%22%3A%22174%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21AUD%2115.38%216.34%21%21%2168.37%2128.16%21%402101c69517948838882406752e0f63%2112000045752604980%21sea%21AU%212961347876%21X%211%210%21n_tag%3A-29919%3Bd%3A20f6a0d2%3Bm03_new_user%3A-29895%3BpisId%3A5000000221713830&curPageLogUid=v0UEPRpnLVGD&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008568072063%7C_p_origin_prod%3A) |  | Already own |  | 2.8 Inch Display | N/A | N/A | N/A | N/A |
| PCBA | Tax or fee | 2 | 44.455 | 88.91 | [JLCPCB](https://jlcpcb.com/?from=VGS&utm_source=google&utm_medium=cpc&utm_campaign=14177189905&gad_source=1&gad_campaignid=14177189905&gbraid=0AAAAABS1QqkgPoFOHUy_26J4N5kBx4Aa3&gclid=Cj0KCQiAwdDXBhDuARIsAFdLukmN-B7r3FdQKI8Ma6WjcPEJgnZSJuI_80tu4TU9jCkDFhZ-cYRUD3oaAn0kEALw_wcB) |  | Grant |  | N/A | N/A | N/A | N/A | N/A |
| PCB | Part | 5 | 0.592 | 2.96 | N/A |  | Grant |  | N/A | N/A | N/A | N/A | N/A |
| Total |  |  |  | 137.3348 |  |  |  |  |  |  |  |  |  |
| Grant total |  |  |  | 129.7348 |  |  |  |  |  |  |  |  |  |

# IMPORTANT READ BELOW

**Just to let you know:**

The total for the PCB is $150 AUD, plus $25 AUD for the AliExpress modules, bringing the actual total to $175 AUD.
You might notice the Bill of Materials (BOM) shows a total of around $200 AUD. This looks high because the BOM lists the individual prices of every single component. However, the PCB and PCBA prices already include the cost of these parts and their assembly.

I included the individual parts in the list just to show the breakdown, but you do not need to buy them separately. Since they are already covered in the PCBA price, they will not be added to the final cost.