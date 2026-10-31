# Fusion Board

## 1. Project Overview

### What is Fusion Board ?

Fusion Board is an FPGA (Field Programmable Gate Array) built from scratch based on AMD Zynq Ultrascale + architecture.
This board features 4GB DDR4 RAM, 32GB Memory, E Ink Display and much more.
(*Note : Checkout Repo guide for repo navigation*)

### Goals and Objectives.

I designed this board to explore a new domain after making projects like [Flight controller](https://github.com/damnitzhemanth-oss/Flight_Controller/tree/main)
, [Calculator](https://github.com/damnitzhemanth-oss/Custom-Scientific-Calc).

### Key Features.


Zynq UltraScale+ XCZU4E,900-pin FBVB900 SoC with 4 GB DDR4 (4× MT40A512M16LY), 256 Mb QSPI, 32 GB eMMC, and microSD.
With High Speed connectivity Peripherals like SFP+ cage, PCIE, superspeed USB.

(*Note : There are many more amazing features, checkout [Features for Nerds](https://github.com/damnitzhemanth-oss/FusionBoard/blob/main/Guides/DetailsForNerds.md)
for detailed specs list.*)

## 2. Requirements

### Hardware Requirements 
(*Rough estimated prices according to LCSC*)

| # | Reference | Qty | Value | LCSC Part | Subtotal (USD) |
|---:|:---|--:|:---|:---|--:|
| 1 | BT1 | 1 | Battery_Cell |  | 0.42 |
| 2 | C1,C3,C8 | 3 | 1uF |  | 0.02 |
| 3 | C2,C9,C15 | 3 | 100uF 35V |  | 0.33 |
| 4 | C4 | 1 | 100nF |  | 0.00 |
| 5 | C5,C10 | 2 | 1uF 25V |  | 0.01 |
| 6 | C6 | 1 | 2.2uF |  | 0.01 |
| 7 | C7,C26,C31,C412...C500 | 37 | 100nF |  | 0.10 |
| 8 | C11 | 1 | 0.1uF 50V X7R |  | 0.00 |
| 9 | C12,C13,C20 | 3 | 10nF 25V |  | 0.01 |
| 10 | C14,C81,C85,C111,C_shield1 | 5 | 4.7nF 50V |  | 0.01 |
| 11 | C16 | 1 | 2.2nF 25V |  | 0.00 |
| 12 | C17,C18,C66,C68,C70,C72,C74,C94,C105,C119 | 10 | 0.1uF 25V |  | 0.03 |
| 13 | C19,C21 | 2 | 0.1uF 50V |  | 0.01 |
| 14 | C22 | 1 | 47nF |  | 0.00 |
| 15 | C23,C24,C28,C29,C30,C50,C52,C60,C61,C64,C65 | 11 | 22uF |  | 0.31 |
| 16 | C25,C45,C48,C62,C101...C498 | 35 | 1uF |  | 0.10 |
| 17 | C27 | 1 | 4.7uF |  | 0.01 |
| 18 | C32,C33,C37 | 3 | 1uF |  | 0.02 |
| 19 | C34 | 1 | 0.47uF |  | 0.00 |
| 20 | C35,C39 | 2 | 10nF |  | 0.01 |
| 21 | C36,C58,C59,C63...C507 | 26 | 10uF |  | 0.29 |
| 22 | C38 | 1 | 0.1uF |  | 0.01 |
| 23 | C40 | 1 | 22uF, 6.3V |  | 0.03 |
| 24 | C41,C49 | 2 | 0.1uF, 25V |  | 0.01 |
| 25 | C42,C43,C82,C86,C103,C112,C477,C478,C495,C496 | 10 | 100pF |  | 0.03 |
| 26 | C44 | 1 | 10nF, 10V |  | 0.00 |
| 27 | C46,C79,C83,C109 | 4 | 10nF |  | 0.01 |
| 28 | C47 | 1 | 3.3nF |  | 0.00 |
| 29 | C51 | 1 | 2.2nF |  | 0.00 |
| 30 | C53,C54,C55,C56 | 4 | 47uF,4V |  | 0.22 |
| 31 | C57,C97,C99,C107,C113 | 5 | 47uF |  | 0.28 |
| 32 | C76,C78,C104 | 3 | 0.1uF 25v |  | 0.01 |
| 33 | C77,C121...C523 | 300 | 0.1uF |  | 0.83 |
| 34 | C80,C84,C91,C96,C110,C118 | 6 | 22uf 25v |  | 0.21 |
| 35 | C87,C88,C114,C481,C482 | 5 | 22pF |  | 0.01 |
| 36 | C89,C90,C92,C93,C115,C116 | 6 | 47uF 6.3V |  | 0.33 |
| 37 | C154,C174 | 2 | 47uF |  | 0.17 |
| 38 | C368,C369,C370,C380,C381,C382,C383,C392,C422 | 9 | 1nF |  | 0.03 |
| 39 | C372,C373,C408,C409 | 4 | 33pF |  | 0.01 |
| 40 | C375,C385 | 2 | 22uF |  | 0.03 |
| 41 | C424,C429,C431 | 3 | 10uF |  | 0.06 |
| 42 | C473 | 1 | 0.56 nF |  | 0.00 |
| 43 | C474 | 1 | 330 nF |  | 0.00 |
| 44 | C475 | 1 | 3.3 nF |  | 0.00 |
| 45 | C499 | 1 | 0.1 uF |  | 0.00 |
| 46 | C518 | 1 | 22F 5.5V |  | 1.11 |
| 47 | Card1 | 1 | TF-01A | C91145 | 0.17 |
| 48 | CN1 | 1 | 1-2199230-6 | C4710843 | 1.39 |
| 49 | D1 | 1 | SMBJ20A |  | 0.08 |
| 50 | D2 | 1 | 15V |  | 0.08 |
| 51 | D3 | 1 | TP7.OSMD24CA-XC |  | 0.11 |
| 52 | D4 | 1 | LSMB24CAH |  | 0.11 |
| 53 | D5 | 1 | Red |  | 0.01 |
| 54 | D6,D9 | 2 | Green |  | 0.03 |
| 55 | D7,D8 | 2 | D_Schottky |  | 0.14 |
| 56 | D10,D11,D12 | 3 | RB521S30 |  | 0.08 |
| 57 | DC1 | 1 | PJ-102AH_C3096093 | C3096093 | 0.60 |
| 58 | FB1,FB2,FB3,FB4,FB5,FB6,FB7,FB8,FB10 | 9 | 120Ω@100MHz |  | 0.06 |
| 59 | FB9 | 1 | BLM18 |  | 0.01 |
| 60 | J1 | 1 | HR911105A_C12074 | C12074 | 1.35 |
| 61 | J2 | 1 | Conn_01x03_Pin |  | 0.14 |
| 62 | J3 | 1 | USB3_B |  | 1.11 |
| 63 | J4,J5 | 2 | Conn_01x02_Pin |  | 0.22 |
| 64 | J6 | 1 | 3.3V_I2C |  | 0.11 |
| 65 | J7,J14,J15,J16 | 4 | Conn_01x10 |  | 0.83 |
| 66 | J8 | 1 | Conn_01x09_Pin |  | 0.19 |
| 67 | J9 | 1 | Conn_Coaxial |  | 1.39 |
| 68 | J10 | 1 | Conn_02x07_Odd_Even |  | 0.28 |
| 69 | J11 | 1 | Conn_01x04_Pin |  | 0.14 |
| 70 | J12 | 1 | SFP+ |  | 2.08 |
| 71 | J13 | 1 | Conn_01x22 |  | 1.11 |
| 72 | L1,L2 | 2 | 2.2uH,5A |  | 0.42 |
| 73 | L3 | 1 | 1/2.2uH |  | 0.21 |
| 74 | L4 | 1 | 0.47uH 15A |  | 0.28 |
| 75 | L5 | 1 | 10uH 12A |  | 0.28 |
| 76 | L6,L7 | 2 | 2.2uH |  | 0.42 |
| 77 | L8,L9,L10 | 3 | 1uH |  | 0.42 |
| 78 | L11 | 1 | DLW21HN900SQ2L-CUTTAPE | C80529 | 0.14 |
| 79 | L12,L13,L14 | 3 | 220 nH |  | 0.13 |
| 80 | Q1,Q2 | 2 | IPB180P04P4L-02 | C21547650 | 2.22 |
| 81 | R1,R3,R135,R138,R163,R164 | 6 | 5.1kΩ |  | 0.01 |
| 82 | R2,R13,R41,R49,R50,R52,R54,R56,R59,R153,R155,R165,R166 | 13 | 100kΩ |  | 0.02 |
| 83 | R4,R7,R20,R21,R22,R23,R24,R29,R75 | 9 | 10k |  | 0.01 |
| 84 | R5 | 1 | 100Ω |  | 0.00 |
| 85 | R6,R8,R177,R178,R181 | 5 | 4.7kΩ |  | 0.01 |
| 86 | R9,R25 | 2 | 124k |  | 0.00 |
| 87 | R10,R27,R34...R212 | 54 | 10kΩ |  | 0.08 |
| 88 | R11,R12,R60,R65,R70,R73,R74,R76,R78,R90,R101 | 11 | 100k |  | 0.02 |
| 89 | R14 | 1 | 549Ω |  | 0.00 |
| 90 | R15,R26 | 2 | 750Ω |  | 0.00 |
| 91 | R16,R17 | 2 | 470R |  | 0.00 |
| 92 | R18 | 1 | 29.8k |  | 0.00 |
| 93 | R19,R92 | 2 | 120k |  | 0.00 |
| 94 | R28 | 1 | 5.9kΩ |  | 0.00 |
| 95 | R30 | 1 | 442k |  | 0.00 |
| 96 | R31 | 1 | 210k |  | 0.00 |
| 97 | R32 | 1 | 20.5k |  | 0.00 |
| 98 | R33 | 1 | 10mΩ |  | 0.69 |
| 99 | R37,R48,R104,R105,R140,R145 | 6 | 1kΩ |  | 0.01 |
| 100 | R38 | 1 | 1k |  | 0.00 |
| 101 | R39 | 1 | 100 |  | 0.00 |
| 102 | R40 | 1 | 180Ω |  | 0.00 |
| 103 | R42 | 1 | 30.1kΩ |  | 0.00 |
| 104 | R45 | 1 | 5.23kΩ |  | 0.00 |
| 105 | R55 | 1 | 31.6K |  | 0.00 |
| 106 | R58 | 1 | 60.4k |  | 0.00 |
| 107 | R63 | 1 | 49.9k |  | 0.00 |
| 108 | R64 | 1 | 24.3kΩ |  | 0.00 |
| 109 | R67,R183,R187 | 3 | 10Ω |  | 0.00 |
| 110 | R69 | 1 | 73.2kΩ |  | 0.00 |
| 111 | R71 | 1 | 249kΩ |  | 0.00 |
| 112 | R72 | 1 | 309k |  | 0.00 |
| 113 | R77 | 1 | 200k |  | 0.00 |
| 114 | R81,R82 | 2 | 49.9kΩ |  | 0.00 |
| 115 | R85,R87,R99 | 3 | 20k |  | 0.00 |
| 116 | R86,R89,R100 | 3 | 50K |  | 0.00 |
| 117 | R88 | 1 | 182kΩ |  | 0.00 |
| 118 | R91,R93,R102 | 3 | 249k |  | 0.00 |
| 119 | R94 | 1 | 3.24kΩ |  | 0.00 |
| 120 | R95 | 1 | 14.7kΩ |  | 0.00 |
| 121 | R103 | 1 | 220Ω |  | 0.00 |
| 122 | R106,R107,R108,R109 | 4 | 240Ω |  | 0.01 |
| 123 | R110,R112,R122,R125...R139 | 11 | 22Ω |  | 0.02 |
| 124 | R124 | 1 | 11kΩ |  | 0.00 |
| 125 | R129,R132 | 2 | 470Ω |  | 0.00 |
| 126 | R137 | 1 | 8.06kΩ |  | 0.00 |
| 127 | R142,R144 | 2 | 2.49kΩ |  | 0.00 |
| 128 | R146 | 1 | 47.5kΩ |  | 0.00 |
| 129 | R147 | 1 | 22.1kΩ |  | 0.00 |
| 130 | R148,R167,R176,R209,R210 | 5 | 1MΩ |  | 0.01 |
| 131 | R149,R150,R152,R156,R157,R159,R160,R199,R200 | 9 | 2.2kΩ |  | 0.01 |
| 132 | R154 | 1 | 200kΩ |  | 0.00 |
| 133 | R161 | 1 | 12kΩ |  | 0.00 |
| 134 | R168,R175,R186,R192,R193,R195 | 6 | 50Ω |  | 0.01 |
| 135 | R169,R171 | 2 | 33Ω |  | 0.00 |
| 136 | R182,R184,R185 | 3 | 27Ω |  | 0.00 |
| 137 | R191 | 1 | 1.92kΩ |  | 0.00 |
| 138 | R196,R197,R201,R202,R203,R204,R205,R206 | 8 | 5kΩ |  | 0.01 |
| 139 | R208 | 1 | 4.02MΩ |  | 0.00 |
| 140 | R211 | 1 | 3MΩ |  | 0.00 |
| 141 | RT1 | 1 | 10k NTC |  | 0.04 |
| 142 | R_shield1 | 1 | 1 M |  | 0.00 |
| 143 | SW1 | 1 | SW_Push |  | 0.21 |
| 144 | SW2 | 1 | SW_SPDT |  | 0.28 |
| 145 | TP1,TP2 | 2 | TestPoint |  | 0.14 |
| 146 | U1 | 1 | TPD6S300ARUKR | C2876380 | 0.51 |
| 147 | U2 | 1 | STUSB4500QTR |  | 2.08 |
| 148 | U3 | 1 | TVS2201DRBR | C1849889 | 0.21 |
| 149 | U4,U6 | 2 | TPS259470ARPWR | C3662799 | 10.34 |
| 150 | U5 | 1 | TPS2121RUXR | C485916 | 0.53 |
| 151 | U7 | 1 | XT60 | C98733 | 0.28 |
| 152 | U8 | 1 | DW06 | C917080 | 0.07 |
| 153 | U9 | 1 | BQ25895RTWR | C80200 | 2.17 |
| 154 | U10 | 1 | BQ27441DRZR-G1A | C473397 | 1.41 |
| 155 | U11 | 1 | LM66100DCK |  | 0.42 |
| 156 | U12 | 1 | TPS61088RHLR | C87357 | 0.67 |
| 157 | U13 | 1 | TPS548A20RVER | C468255 | 1.08 |
| 158 | U14 | 1 | TPS62130RGTR | C43590 | 0.92 |
| 159 | U15,U20,U21,U25 | 4 | TPS54824RNVR | C2070614 | 4.32 |
| 160 | U16 | 1 | TPS62823DLCR | C2693497 | 0.32 |
| 161 | U17 | 1 | TPS62822DLCR | C473385 | 0.20 |
| 162 | U18,U22,U23,U26 | 4 | TPS7A4700RGWR | C114839 | 9.32 |
| 163 | U19 | 1 | TPS3700DSET | C2869244 | 0.56 |
| 164 | U24 | 1 | RS3112-1.25XSF3 | C19269195 | 0.11 |
| 165 | U27 | 1 | xczu4evfbvb900pkg |  | 3000.00 |
| 166 | U28 | 1 | TXS02612RTWR | C140276 | 1.52 |
| 167 | U29 | 1 | MT25QU256ABA8ESF-0SIT TR | C2061781 | 20.23 |
| 168 | U30 | 1 | FEMDNN032G-A3A55 | C5117593 | 37.90 |
| 169 | U31 | 1 | DP83867IRRGZR | C2678038 | 2.09 |
| 170 | U32 | 1 | CP2102N-A02-GQFN24 |  | 1.39 |
| 171 | U33 | 1 | USB3320C-EZK-TR | C132156 | 1.49 |
| 172 | U34,U39 | 2 | TPD4E05U06DQA |  | 0.83 |
| 173 | U35,U53 | 2 | TCA9548APWR |  | 2.78 |
| 174 | U36 | 1 | TXB0108PW |  | 1.11 |
| 175 | U37 | 1 | PCA9306 |  | 0.42 |
| 176 | U38 | 1 | USB2514B_Bi |  | 2.08 |
| 177 | U40 | 1 | TXS0102DQE |  | 0.42 |
| 178 | U41 | 1 | SI5341A-D12636-GM | C3609093 | 20.28 |
| 179 | U42 | 1 | REF5025AD |  | 3.47 |
| 180 | U43 | 1 | LMX2594RHAR | C2862572 | 68.58 |
| 181 | U44 | 1 | ADS131M08IPBS | C2685451 | 6.76 |
| 182 | U45 | 1 | ADS4245IRGCT | C2670075 | 59.37 |
| 183 | U46 | 1 | AD9744ARUZRL7 | C461519 | 11.48 |
| 184 | U47 | 1 | THS4509RGTT | C2057531 | 6.27 |
| 185 | U48 | 1 | ADL8100ACPZN |  | 11.11 |
| 186 | U49 | 1 | BPF-A355 |  | 20.83 |
| 187 | U50 | 1 | TMP117DRVR |  | 2.08 |
| 188 | U51 | 1 | ICM-42688-P |  | 2.78 |
| 189 | U52 | 1 | MMC5983MA | C404329 | 3.43 |
| 190 | U54 | 1 | BMP581 | C5362283 | 1.67 |
| 191 | U55 | 1 | MAX-M10S-00B | C4153167 | 10.42 |
| 192 | U56 | 1 | ATECC608B-MAHDA |  | 1.11 |
| 193 | U57 | 1 | OPTIGA TPM SLB 9673 FW26 |  | 3.47 |
| 194 | U58 | 1 | BQ25570 |  | 3.47 |
| 195 | U59 | 1 | STM32G0B1RBT6 |  | 2.08 |
| 196 | USB1,USB2,USB3 | 3 | TYPE-C-24P-SMD | C53207146 | 0.50 |
| 197 | USB4 | 1 | 472720001 | C587824 | 1.25 |
| 198 | U_RAM1,U_RAM2,U_RAM3,U_RAM4 | 4 | MT40A512M16LY-075:E | C598779 | 13.89 |
| 199 | Y1,Y2,Y7 | 3 | 25 MHz |  | 0.63 |
| 200 | Y3 | 1 | 26 MHz |  | 0.21 |
| 201 | Y4 | 1 | SiT9365AI-4B2-33E100.0000000 |  | 4.17 |
| 202 | Y5 | 1 | ECS_480-8-37-A-D-P-TR |  | 0.28 |
| 203 | Y6 | 1 | SiT5356AI-FP-25VT-16.367667 |  | 6.94 |
|  | **TOTAL** |  |  |  | **≈ 3,747.37** |

### Software and Tools.

To flash this board you would need tools like Vivado and vitis. STSW-STUSB002 for PD Control. 

### Constraints and Challenges.

This is not a simple hobbyist project. This is an 16 layer board with numerous constraints. As a 14 year old with not much experience this board might not be stable. And I cannot manufacture it, as total cost is more than 3000$.

## Development Logs.

### Key Decisions and Changes.

Key Change : First thoughts was to make a breakout board based on ESP32 S3, but it turned into a FPGA Board.
Key Decision : Using multiple sheets.

### Daily Logs.

Check [Journal](https://github.com/damnitzhemanth-oss/FusionBoard/blob/main/Guides/journal.md) for day to day feats, challenges and much more.

## PCB 



